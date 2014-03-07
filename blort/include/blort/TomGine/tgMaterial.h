 /**
 * @file tgMaterial.h
 * @author Thomas Mörwald
 * @date January 2010
 * @version 0.1
 * @brief Defining material for a model (color, lighting behaviour).
 */

#ifndef TG_MATERIAL_MODEL
#define TG_MATERIAL_MODEL

#include <blort/TomGine/tgMathlib.h>

namespace TomGine{

/**
* @brief Class tgMaterial
*/
class tgMaterial
{
public:
	vec4 ambient;
	vec4 diffuse;
	vec4 specular;
	vec4 color;
	float shininess;

	BLORT_API tgMaterial();
	BLORT_API void Apply();
	BLORT_API void Color(float r, float g, float b, float a=1.0f);
	BLORT_API void Random();
};


} // namespace TomGine

#endif
