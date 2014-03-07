 /**
 * @file tgMatrix3.h
 * @author Thomas Mörwald
 * @date October 2009
 * @version 0.1
 * @brief Defining a 3x3 matrix.
 */
 
#ifndef TG_MATRIX3
#define TG_MATRIX3

#ifndef PI
#define PI 3.14159265358979323846f
#endif

#include <math.h>

#include <blort/TomGine/tgVector3.h>

namespace TomGine{

/**
* @brief Class tgMatrix3
*/
class tgMatrix3
{
private:
	
public:
	float m[9];
		
	BLORT_API tgMatrix3();
	BLORT_API tgMatrix3(const tgMatrix3 &m);
	BLORT_API tgMatrix3(tgVector3 x, tgVector3 y, tgVector3 z);
	BLORT_API tgMatrix3(float m0, float m1, float m2,
						float m3, float m4, float m5,
						float m6, float m7, float m8);

	BLORT_API tgMatrix3 operator+(tgMatrix3 v);
	BLORT_API tgMatrix3 operator-(tgMatrix3 v);
	BLORT_API tgMatrix3 operator*(tgMatrix3 v);
	BLORT_API tgMatrix3 operator*(float m);
	BLORT_API tgVector3 operator*(tgVector3 v);
	
	BLORT_API void transpose();
};

} // namespace TomGine


#endif
