
#ifndef _IMAGE_PROCESSOR_H_
#define _IMAGE_PROCESSOR_H_

namespace Tracking{
	class ImageProcessor;
}
#include <blort/Tracker/headers.h>

#include <blort/Tracker/Shader.h>
#include <blort/Tracker/Texture.h>
#include <blort/TomGine/tgCamera.h>
#include <blort/Tracker/Resources.h>

enum LensMode{
	NONE,		// No rectification
	BARREL,		// Rectification using Barrel equation
};

namespace Tracking{

/** @brief class ImageProcessor */
class ImageProcessor{
private:
    unsigned m_width;        // Image width in pixels
    unsigned m_height;       // Image height in pixels
    int m_dlRect;       	// Display list for rectification (distorted TexCoords)
    int m_dlImage;      	// Display List for normal images (less geometry)
    int m_dlUpsideDown; 	// Display List for flipping image upside down
    LensMode m_lensMode;	// Enumeration for lens rectification algorithm (NONE, BARREL)
    
    Shader* m_shadeGauss;		// Fragment shader for blurring image using gaussian filter
    Shader* m_shadeSobel;       // Fragment shader for edge detection with sobel algorithm
    Shader* m_shadeThinning;    // Fragment shader for thinning edges
    Shader* m_shadeSpreading;   // Fragment shader for spreading edges
    
    TomGine::tgCamera m_cam_ortho, m_cam_ortho_fbo;
	
	GLuint fbo;
	GLuint fbo_tex;
	GLuint fbo_tex_depth;
	int fbo_res;
	int fbo_stage;
	bool m_sum_init;
    
    bool initShader();
    bool dlImage();
    bool dlImage(float x, float y, float w, float h);
    bool dlFlipUpsideDown();
    bool dlRectification();
    bool transform(float i, float j, float *ix, float *iy);

public:
    
	BLORT_API ImageProcessor();
	BLORT_API ~ImageProcessor();

	// Set functions
	BLORT_API void setCamOrtho();
	BLORT_API int getWidth(){ return m_width; }
	BLORT_API int getHeight(){ return m_height; }
    
	// Image Processing functions
	BLORT_API void flipUpsideDown(Texture* source, Texture* result);
	BLORT_API void copy(Texture* source, Texture* result);
	BLORT_API void rectification(Texture* source, Texture* result);
	BLORT_API void gauss(Texture* source, Texture* result);
	BLORT_API void sobel(Texture* source, Texture* result, float threshold=0.01, bool normalise=false, bool binary=false);
	BLORT_API void sobel(Texture* source, Texture* result, Texture* mask, float threshold=0.01, bool normalize=false, bool binary=false);
	BLORT_API void thinning(Texture* source, Texture* result);
	BLORT_API void thinning(Texture* source, Texture* result, Texture* mask);
	BLORT_API void spreading(Texture* source, Texture* result);
	BLORT_API void render(Texture* tex);
	BLORT_API void render(Texture*tex, int x, int y, unsigned w, unsigned h);
	
	// summation
	BLORT_API GLenum avgInit(int res);
	BLORT_API void avgActivate();
	BLORT_API void avgGet(float *avg, int lvl=0);
	BLORT_API void avgDeactivate();
	inline int avgGetResolution(){ return fbo_res; }
	
	// Main functions
	BLORT_API bool init(unsigned w, unsigned h);
};

} // namespace Tracking

#endif
