
#ifndef __TRACKER_MODEL_H__
#define __TRACKER_MODEL_H__

namespace Tracking{
	class TrackerModel;
}
#include <blort/Tracker/headers.h>
#include <blort/TomGine/tgModel.h>
#include <blort/Tracker/Texture.h>
#include <blort/Tracker/Shader.h>
#include <blort/TomGine/tgMathlib.h>
#include <blort/TomGine/tgPose.h>
#include <blort/TomGine/tgCamera.h>
#include <boost/utility.hpp>

#ifndef FN_LEN
#define FN_LEN 256
#endif

namespace Tracking{


/** @brief 3D Model with special methods for tracking and texturing */
class TrackerModel : public TomGine::tgModel
{
private:
	TrackerModel(const TrackerModel& m);
	
	TrackerModel& operator=(const TomGine::tgModel& m);		// no implementation (should not be used)

public:
	BLORT_API TrackerModel();
	BLORT_API TrackerModel(const TomGine::tgModel& m);
	BLORT_API ~TrackerModel();
	
	BLORT_API TrackerModel& operator=(const TrackerModel& m);
	
	BLORT_API void releasePassList();
	
	struct Pass : public boost::noncopyable {												// Renderpass
		std::vector<unsigned> f;								// Faces to draw with this pass
		mat4 modelviewprojection;					// Modelview and projection matrix for texCoords
		float x,y,w,h;										// Bounding box of SubTexture
		Texture* texture;									// Texture to use
		BLORT_API Pass(){ texture = new(Texture); glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); }
		BLORT_API ~Pass(){ delete(texture);}
	};
	
	typedef std::vector<Pass*>	PassList;
	
	// Variables
	PassList				m_passlist;
	std::vector<int>		m_facepixellist;
	
	Texture* m_tex_original;		// original texture of model (not modified by tracker)
	Texture*	m_texture;				// texture of model modified by tracker (edge-texture)
	bool m_textured;
	
	// computes, updates
	BLORT_API void computeEdges();
	BLORT_API void computeBoundingSphere();
	BLORT_API void Update();
	
	// draws
	BLORT_API virtual void Print() const;
	BLORT_API virtual void drawNormals();
	BLORT_API virtual void drawFaces(bool colorful=false);
	BLORT_API void drawFace(int i);
	BLORT_API void drawEdges();
	BLORT_API void drawTexturedFaces();
	BLORT_API void drawUntexturedFaces();
	BLORT_API void drawPass(bool colorful=false);
	BLORT_API void drawCoordinates();
	
	
	BLORT_API std::vector<unsigned> getFaceUpdateList(TomGine::tgPose& p_max, vec3 view, float minTexGrabAngle=3.0*PI/4.0, bool use_num_pixels=true);
	
	BLORT_API void getBoundingBox2D( int width, int height, TomGine::tgPose& p_max, TomGine::tgCamera* m_cam,
							int &minX, int &maxX, int &minY, int &maxY );
	
	/** @brief capture texture from image */
	BLORT_API void textureFromImage(	Texture* image,
							int width, int height,
							TomGine::tgPose& p_max,
							vec3 view,
							float minTexGrabAngle,
							std::vector<unsigned> faceUpdateList,
							std::vector<TomGine::tgVertex> &vertices,
							TomGine::tgCamera* m_cam);
	
	BLORT_API void useTexCoords(bool useTC);
	BLORT_API void unwarpTexturesBox_hacky(const char* name);

		// gets
	BLORT_API bool 			getTextured(){ return m_textured; }
	BLORT_API Texture* 	getTexture(){ return m_texture; }
	BLORT_API Texture* 	getOriginalTexture(){ return m_tex_original; }
	BLORT_API float			getBoundingSphereRadius(){ return m_boundingSphereRadius; }
	
	// sets
	BLORT_API void setBFC(bool bfc){ m_bfc = bfc; }
	BLORT_API void setTexture(Texture* tex){ m_texture = tex; }
	BLORT_API void setOriginalTexture(Texture* tex){ m_tex_original = tex; }
	BLORT_API void restoreTexture(){ m_texture=m_tex_original; }
	
		// generate display lists
	BLORT_API void genListTexturedFaces();
	BLORT_API void genListUntexturedFaces();
	BLORT_API void genListPass(bool colorful=false);
	BLORT_API void genListFaces(bool colorful=false);
	BLORT_API void genListEdges();
	BLORT_API void genListNormals(float normal_length);
	
protected:
	GLint m_dlTexturedFaces;
	GLint m_dlUntexturedFaces;
	GLint m_dlPass;
	GLint m_dlFaces;
	GLint m_dlEdges;
	GLint m_dlNormals;
	
	Shader* m_shadeTexturing;
	int m_shadeTexturingID;
	bool m_bfc;
	float m_boundingSphereRadius;

	// Functions
	BLORT_API bool isRedundant(TomGine::tgLine* e1);
	BLORT_API void UpdateDisplayLists();
};

} // namespace Tracking

#endif
