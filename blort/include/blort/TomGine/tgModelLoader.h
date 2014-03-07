 /**
 * @file tgModelLoader.h
 * @author Thomas Mörwald
 * @date October 2009
 * @version 0.1
 * @brief Loading geometrical models from file
 * @namespace Tracking
 */
 
#ifndef TG_MODELLOADER
#define TG_MODELLOADER

#include <stdlib.h>
#include <stddef.h>
#include <string>

#include <blort/TomGine/ply.h>
#include <blort/TomGine/PlyStructure.h>
#include <blort/TomGine/tgModel.h>
#include <blort/TomGine/tgRenderModel.h>


namespace TomGine{

/** @brief Loading geometrical models from file */
class tgModelLoader
{
private:

	bool propertyIsInList(PlyProperty* prop, PlyProperty* list, int n, int* index);

public:
	BLORT_API tgModelLoader();
	BLORT_API ~tgModelLoader();
	
	/** @brief Loads PLY (Polygon File Format, Stanford Triangle Format) 
	*		@param Model Storage for model
	*		@param filename path and filename of file to load
	*		@return true on success, false on failure
	*/
	BLORT_API bool LoadPly(tgModel &model, const char* filename);
	
	BLORT_API bool SavePly(tgModel &model, const char* filename);
	   
};

} // namespace TomGine

#endif
