 /**
 * @file tgTexture.h
 * @author Thomas Mörwald
 * @date October 2009
 * @version 0.1
 * @brief Class for managing textures (load from file, bind, copy, ...).
 */
 
#ifndef TG_TEXTURE
#define TG_TEXTURE

#include <blort/TomGine/headers.h>

namespace TomGine{

/**
* @brief Class tgTexture
*/
class tgTexture
{
private:
	GLuint m_texture_id;
	int m_width;
	int m_height;

public:
	BLORT_API tgTexture();
	BLORT_API ~tgTexture();
	
	BLORT_API bool Load(void* image_data, int width, int height, GLenum format=GL_RGB, GLenum internal=GL_UNSIGNED_BYTE);
	BLORT_API bool Load(const char* filename);
	BLORT_API bool Save(const char* filename, bool overwrite=true);
	BLORT_API bool GetImageData(unsigned char* image_data);
	
	BLORT_API void Bind(int stage=0) const;

	BLORT_API void CopyTexImage2D(int width, int height);
	BLORT_API void CopyTexImage2D(int x, int y, int width, int height);
	
	BLORT_API inline GLuint GetTextureID(){ return m_texture_id; }
	BLORT_API inline int GetWidth() const{ return m_width; }
	BLORT_API inline int GetHeight() const{ return m_height; }
	
};

} // namespace TomGine

#endif
