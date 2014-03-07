 /**
 * @file tgQuaternion.h
 * @author Thomas Mörwald
 * @date September 2009
 * @version 0.1
 * @brief tgQuaternion representing rotations (avoiding singularity locks)
 */
 
#ifndef TG_QUATERNION
#define TG_QUATERNION

#include <math.h>

#include <blort/TomGine/tgMathlib.h>

namespace TomGine{

const float ftol = 0.0001f;

/** @brief Class tgQuaternion */
class tgQuaternion
{
private:
	
	
public:
	float x,y,z,w;
	BLORT_API tgQuaternion();
	BLORT_API tgQuaternion(float x, float y, float z, float w);
	
	BLORT_API void normalise();
	BLORT_API tgQuaternion getConjugate() const;
	BLORT_API tgQuaternion operator+ (const tgQuaternion &q2) const;
	BLORT_API tgQuaternion operator- (const tgQuaternion &q2) const;
	BLORT_API tgQuaternion operator* (const tgQuaternion &rq);
	BLORT_API tgQuaternion operator* (const float f);
	
	BLORT_API vec3 operator* (const vec3 &vec);
	
	BLORT_API void fromAxis(const vec3 &v, float angle);
	BLORT_API void fromEuler(float pitch, float yaw, float roll);
	BLORT_API void fromMatrix(mat3 m);
	BLORT_API void fromMatrix(mat4 m);
	BLORT_API mat4 getMatrix4() const;
	BLORT_API mat3 getMatrix3() const;
	BLORT_API void getAxisAngle(vec3& axis, float& angle) const;
	
	BLORT_API void print() const;

};

} // namespace TomGine

#endif
