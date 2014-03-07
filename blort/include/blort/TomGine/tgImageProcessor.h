
#ifndef _TG_IMAGE_PROCESSOR_H_
#define _TG_IMAGE_PROCESSOR_H_

#include <blort/TomGine/headers.h>

#include <blort/TomGine/tgShader.h>
#include <blort/TomGine/tgTexture.h>
#include <blort/TomGine/tgCamera.h>

namespace TomGine{

/** @brief class tgImageProcessor */
class tgImageProcessor{
private:
	unsigned m_width;        // Image width in pixels
	unsigned m_height;       // Image height in pixels

	tgShader* m_shadeGauss;		// Fragment shader for blurring image using gaussian filter
	tgShader* m_shadeSobel;       // Fragment shader for edge detection with sobel algorithm
	tgShader* m_shadeThinning;    // Fragment shader for thinning edges
	tgShader* m_shadeSpreading;   // Fragment shader for spreading edges

	TomGine::tgCamera m_cam_ortho, m_cam_ortho_fbo;

	GLuint fbo;
	GLuint fbo_tex;
	GLuint fbo_tex_depth;
	int fbo_res;
	int fbo_stage;
	bool m_avg_init;
	
	void drawQuadUpsideDown(float w, float h);
	void drawQuad(float w, float h);
	bool transform(float i, float j, float *ix, float *iy);
	
	void init(unsigned width, unsigned height);
	
	void initFBO(int res);

public:
	BLORT_API tgImageProcessor(	const char *gauss_frag_file,
						const char *sobel_frag_file,
						const char *thinning_frag_file,
						const char *spreading_frag_file,
						unsigned img_width, unsigned img_height,
						int avg_resolution);
	BLORT_API ~tgImageProcessor();
	
	BLORT_API void initShader(float width, float height);

	// Set functions
	BLORT_API void setCamOrtho();
	BLORT_API int getWidth(){ return m_width; }
	BLORT_API int getHeight(){ return m_height; }

	// Image Processing functions
	BLORT_API void flipUpsideDown(const tgTexture& source, tgTexture& result);
	BLORT_API void copy(const tgTexture& source, tgTexture& result);
	BLORT_API void gauss(const tgTexture& source, tgTexture& result);
	BLORT_API void sobel(const tgTexture& source, tgTexture& result, float threshold=0.01, bool normalise=false, bool binary=false);
	BLORT_API void sobel(const tgTexture& source, tgTexture& result, tgTexture& mask, float threshold=0.01, bool normalize=false, bool binary=false);
	BLORT_API void thinning(const tgTexture& source, tgTexture& result);
	BLORT_API void thinning(const tgTexture& source, tgTexture& result, tgTexture& mask);
	BLORT_API void spreading(const tgTexture& source, tgTexture& result);
	BLORT_API void render(const tgTexture& tex);
	
	// average computations
	BLORT_API void avgActivate();
	BLORT_API void avgGet(float *avg, int lvl=0);
	BLORT_API void avgDeactivate();
	inline int avgGetResolution(){ return fbo_res; }
};

} // namespace TomGine

#endif
