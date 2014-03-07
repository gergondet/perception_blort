 /**
 * @file tgRenderModel.h
 * @author Thomas Mörwald
 * @date January 2010
 * @version 0.1
 * @brief Defining a model for rendering.
 */

#ifndef TG_RENDER_MODEL
#define TG_RENDER_MODEL

#include <stdio.h>
#include <vector>

#include <blort/TomGine/tgMathlib.h>
#include <blort/TomGine/tgPose.h>
#include <blort/TomGine/tgModel.h>
#include <blort/TomGine/tgLabel.h>
#include <blort/TomGine/tgMaterial.h>

namespace TomGine{



/** @brief Class tgRenderModel */
class tgRenderModel : public tgModel
{	
public:
	tgPose			m_pose;
	tgMaterial 		m_material;
	tgModel*		m_bsmodel;	// bounding sphere
	
	BLORT_API tgRenderModel();
	BLORT_API tgRenderModel(const tgModel& model);
	BLORT_API ~tgRenderModel();
	
	BLORT_API void ApplyMaterial();
	BLORT_API void ApplyColor();
	
	BLORT_API virtual void DrawFaces();
	BLORT_API void DrawFaces(bool lighting);
// 	virtual void DrawPolygons();
	BLORT_API virtual void DrawNormals(float normal_length);
	
	/** @brief draws bounding sphere of model */
	BLORT_API virtual void DrawBoundingSphere();
};

} // namespace TomGine

#endif
