 /**
 * @file Texture.h
 * @author Thomas Mörwald
 * @date October 2009
 * @version 0.1
 * @brief Class for managing textures (load from file, bind, copy, ...).
 */
 
#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <blort/Tracker/headers.h>
#include <blort/api.h>
#include <opencv2/core/core.hpp>

namespace Tracking{

/**
* @brief Class Texture
*/
class Texture
{
private:
	GLuint m_texture_id;
	unsigned m_width;
	unsigned m_height;
	int m_res_id;
	
public:
	BLORT_API Texture();
	BLORT_API ~Texture();
	
	BLORT_API bool load(unsigned char* image_data, unsigned width, unsigned height, GLenum format=GL_BGR);
	BLORT_API bool load(const char* filename);
	BLORT_API bool save(const char* filename);
	BLORT_API bool getImageData(unsigned char* image_data);
	
	BLORT_API void bind(int stage=0);
	BLORT_API void copyTexImage2D(unsigned width, unsigned height);		// copy frame buffer pixels to texture
	BLORT_API void copyTexImage2D(int x, int y, unsigned width, unsigned height);
	BLORT_API void copyFromTexture(Texture* tex);
	BLORT_API void copyFromTexture(Texture* tex, int x, int y, unsigned w, unsigned h);
	
	inline GLuint getTextureID(){ return m_texture_id; }
	inline unsigned getWidth(){ return m_width; }
	inline unsigned getHeight(){ return m_height; }
	inline int getResID(){ return m_res_id; }
	inline void setResID(int id){ m_res_id = id; }
    BLORT_API cv::Mat toCvMat();
	
	
};

} // namespace Tracking

#endif
