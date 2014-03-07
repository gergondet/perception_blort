 /**
 * @file tgCamera.h
 * @author Thomas Mörwald & Bence Magyar
 * @date April 2012
 * @version 0.2
 * @brief OpenGL Camera for moving around in 3D space (including internal and external camera parameters). \a
 *        Improved with a Parameter constructor which can handle a ROS camera_info message.
 */
 
#ifndef TG_CAMERA
#define TG_CAMERA

#include <blort/TomGine/headers.h>

#include <blort/TomGine/tgVector3.h>
#include <blort/TomGine/tgFrustum.h>
#include <blort/TomGine/tgMathlib.h>
#include <blort/TomGine/tgPose.h>
#ifndef WIN32
#include <sensor_msgs/CameraInfo.h>
#endif

#define GL_ORTHO 0
#define GL_PERSPECTIVE 1

namespace TomGine{

/**
* @brief Class tgCamera
*/
class tgCamera
{
private:
	// tgCamera definition
	tgVector3 m_vPos;			// Position of tgCamera (absolute)
	tgVector3 m_vView;		// Viewpoint of tgCamera (absolute)
	tgVector3 m_vUp;			// The tgCameras upside (relative)
	
	tgVector3 f;		// Vector of camera pointing forward 
	tgVector3 s;		// Vector of camera pointing sidewards (right)
	tgVector3 u;		// Vector of camera pointing up
	
	unsigned m_width, m_height;
	float m_fovy;
	float m_zNear, m_zFar;
	unsigned short m_projection;	
	mat4 m_extrinsic;
	mat4 m_intrinsic;
	
	tgFrustum m_frustum;
	
public:
	BLORT_API tgCamera();
	
	struct Parameter{
		BLORT_API Parameter();
#ifndef WIN32
                Parameter(const sensor_msgs::CameraInfo& cam_info);
#endif
                BLORT_API void setPose(const TomGine::tgPose& camPose);
		// image dimension
		unsigned width;
		unsigned height;
		// Instrinsic parameters:
		// entries of the camera matrix
		float fx;
		float fy;
		float cx;
		float cy;
		// radial distortion parameters
		float k1;
		float k2;
		float k3;
		// tangential distortion parameters
		float p1;
		float p2;
		// extrinsic parameters: 3D pose of camera w.r.t. world
		mat3 rot;
		vec3 pos;
		// Clipping planes of virtual camera
		float zNear;
		float zFar;
		
		BLORT_API void print(){
			printf("width = %u height = %u\n", width, height);
			printf("fx = %f fy = %f\n", fx, fy);
			printf("cx = %f cy = %f\n", cx, cy);
			printf("k1 = %f k2 = %f k3 = %f\n", k1, k2, k3);
			printf("p1 = %f p2 = %f\n", p1, p2);
			printf("rot\n %f %f %f\n", rot.mat[0], rot.mat[1], rot.mat[2]);
			printf(" %f %f %f\n", rot.mat[3], rot.mat[4], rot.mat[5]);
			printf(" %f %f %f\n", rot.mat[6], rot.mat[7], rot.mat[8]);
			printf("pos\n %f %f %f\n", pos.x, pos.y, pos.z);
			printf("zNear = %f zFar = %f\n", zNear, zFar);
		}
	};
	
	BLORT_API void Load(tgCamera::Parameter camPar);
	
	// Define tgCamera
	BLORT_API void Set(	float posx,  float posy,  float posz,
				float viewx, float viewy, float viewz,
				float upx,   float upy,   float upz,
				float fovy=45.0f, unsigned width=800, unsigned height=600,
				float zNear=0.1f, float zFar=100.0f,
				unsigned short projection=GL_PERSPECTIVE );
	BLORT_API void SetExtrinsic(float* M);
	BLORT_API void SetIntrinsic(float* M);
	BLORT_API void SetIntrinsic(float fovy, unsigned width, unsigned height, float zNear, float zFar, unsigned short projection);
	BLORT_API void SetViewport(unsigned w, unsigned h);
	BLORT_API void SetZRange(float near, float far);
	BLORT_API void SetPerspective(){m_projection=GL_PERSPECTIVE;}
	BLORT_API void SetOrtho(){m_projection=GL_ORTHO;}
	BLORT_API void SetPos(float x, float y, float z){ m_vPos.x=x; m_vPos.y=y; m_vPos.z=z; }
	
	BLORT_API vec2 ToImageSpace(const vec3 &world_space);
	
	BLORT_API void Activate();
	BLORT_API void Print();
	
	BLORT_API void pvu2fsu();
	BLORT_API void fsu2pvu();
	BLORT_API void fsu2extrinsic();
	BLORT_API void extrinsic2fsu();
	BLORT_API void fwh2intrinsic();
	
	// Gets
	BLORT_API TomGine::tgPose GetPose();

	BLORT_API tgVector3 GetF(){return f;}
	BLORT_API tgVector3 GetS(){return s;}
	BLORT_API tgVector3 GetU(){return u;}
	
	BLORT_API tgVector3 GetPos(){return m_vPos;}
	BLORT_API tgVector3 GetView(){return m_vView;}
	BLORT_API tgVector3 GetUp(){return m_vUp;}
	
	BLORT_API float GetZNear(){ return m_zNear; }
	BLORT_API float GetZFar(){ return m_zFar; }
	BLORT_API unsigned GetWidth(){ return m_width; }
	BLORT_API unsigned GetHeight(){return m_height; }
	
	BLORT_API float GetFOVY(){ return m_fovy; }
	BLORT_API unsigned short GetProjection(){ return m_projection; }
	BLORT_API mat4 GetIntrinsic(){ return m_intrinsic; }
	BLORT_API mat4 GetExtrinsic(){ return m_extrinsic; }
	
	BLORT_API tgFrustum* GetFrustum(){ return &m_frustum; }

	// Translations
	BLORT_API void Translate(tgVector3 v);
	BLORT_API void Translate(float x, float y, float z, float fWay);
	BLORT_API void TranslateF(float fWay);
	BLORT_API void TranslateS(float fWay);
	BLORT_API void TranslateU(float fWay);
	
	// Rotations
	BLORT_API void Rotate(float x, float y, float z, float fAngle);
	BLORT_API void RotateF(float fAngle);
	BLORT_API void RotateS(float fAngle);
	BLORT_API void RotateU(float fAngle);
	
	BLORT_API void RotateX(float fAngle);
	BLORT_API void RotateY(float fAngle);
	BLORT_API void RotateZ(float fAngle);
	
	BLORT_API void Orbit(tgVector3 vPoint, tgVector3 vAxis, float fAngle);
	
	// Movement
	BLORT_API void ApplyTransform();
	
	BLORT_API void DrawFrustum(){ m_frustum.DrawFrustum(); }

};

} // namespace TomGine

#endif
