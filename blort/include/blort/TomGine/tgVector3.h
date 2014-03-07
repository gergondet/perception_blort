 /**
 * @file tgVector.h
 * @author Thomas Mörwald
 * @date October 2009
 * @version 0.1
 * @brief Defining a 3D vector. For comfortable camera movement.
 */
 
#ifndef TG_VECTOR3
#define TG_VECTOR3

#ifndef PI
#define PI 3.14159265358979323846f
#endif

#include <math.h>
#include <blort/api.h>

namespace TomGine{

/**
* @brief Class tgVector3
*/
class tgVector3
{
public:
	float x, y, z;
	
	BLORT_API tgVector3();
	//tgVector3(const tgVector3 &v);
	BLORT_API tgVector3(float all);
	BLORT_API tgVector3(float x, float y, float z);

	BLORT_API tgVector3 operator=(tgVector3 v);
	BLORT_API tgVector3 operator+(tgVector3 v);
	BLORT_API tgVector3 operator-(tgVector3 v);
	BLORT_API tgVector3 operator*(tgVector3 v);
	BLORT_API tgVector3 operator*(float m);
	BLORT_API tgVector3 operator/(float m);
	
	BLORT_API tgVector3 cross(tgVector3 v);
	BLORT_API static tgVector3 cross(tgVector3 v1, tgVector3 v2);
	BLORT_API float dot(tgVector3 v);
	BLORT_API void normalize();
	BLORT_API float length();
	BLORT_API void setLength(float l);

	BLORT_API void rotateX(float fAngle);
	BLORT_API void rotateY(float fAngle);
	BLORT_API void rotateZ(float fAngle);

	BLORT_API void rotate(float fAngle, tgVector3 vAxis);

	//void GetRotYZ(float &fAngleY, float &fAngleZ);

};

// tgVector3 funktions
BLORT_API float Angle(tgVector3 a, tgVector3 b);

} // namespace TomGine

#endif
