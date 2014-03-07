 /**
 * @file tgPose.h
 * @author Thomas Mörwald
 * @date October 2009
 * @version 0.1
 * @brief Defining the position and orientation of an object in 3D.
 */
 
#ifndef TG_POSE
#define TG_POSE

#include <blort/TomGine/tgMathlib.h>
#include <blort/TomGine/tgQuaternion.h>

namespace TomGine{

/**
* @brief Class tgPose
*/
class tgPose{
public:
	vec3 t;
	tgQuaternion q;
	
	BLORT_API tgPose operator*(const tgPose& p) const;
	BLORT_API vec3 operator*(const vec3& t) const;
	BLORT_API tgPose operator+(const tgPose &p) const;
	BLORT_API tgPose operator-(const tgPose &p) const;
	BLORT_API tgPose Transpose() const;
	
	BLORT_API void PrintHeader() const;
	BLORT_API void Print() const;

	BLORT_API void Activate() const;	
	BLORT_API void Deactivate() const;
	
	BLORT_API void SetPose(mat3 r, vec3 p);	
	BLORT_API void GetPose(mat3 &r, vec3 &p) const;
	
	BLORT_API void Rotate(float x, float y, float z);	
	BLORT_API void Rotate(vec3 r);
	BLORT_API void RotateAxis(vec3 rot);
	BLORT_API void RotateEuler(vec3 rot);
	BLORT_API void Translate(float x, float y, float z);	
	BLORT_API void Translate(vec3 t);	
};

} // namespace TomGine

#endif
