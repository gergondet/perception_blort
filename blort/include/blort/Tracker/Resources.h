
#ifndef __RESOURCES_H__
#define __RESOURCES_H__

#include <blort/Tracker/headers.h>
#include <blort/Tracker/Singleton.h>
#include <blort/Tracker/ImageProcessor.h>
#include <blort/Tracker/TrackerModel.h>
#include <blort/Tracker/ModelLoader.h>
#include <blort/Tracker/Texture.h>
#include <blort/Tracker/Shader.h>

#ifndef FN_LEN
#define FN_LEN 256
#endif

#define g_Resources Tracking::Resources::GetInstance()

namespace Tracking{

typedef std::vector<Shader*> ShaderList;
typedef std::vector<char*> NameList;


class Resources : public Singleton <Resources>
{
friend class Singleton <Resources>;
private:
	Resources();
	
	// Singleton Resources (one instance in programm)
	CvCapture* 			m_capture;
	IplImage* 			m_image;
	ImageProcessor* 	m_ip;
	
	// Resources lists
	ShaderList		m_shaderList;
	
	// Name lists
	NameList		m_shaderNameList;
	
	char			m_shaderPath[FN_LEN];
	
	bool			m_showlog;
	
	int				SearchName(NameList* list, const char* filename);

public:
	BLORT_API ~Resources();
	BLORT_API static Resources* GetInstance(){
		return Singleton <Resources>::GetInstance ();
	}
	
	// Initialisation
	BLORT_API IplImage*				InitCapture(const char* file);
	BLORT_API IplImage* 				InitCapture(float width=640.0, float height=480.0, int camID = CV_CAP_ANY);
	BLORT_API ImageProcessor*			InitImageProcessor(int width, int height);

    // Release-functions
	BLORT_API void ReleaseCapture();
	BLORT_API void ReleaseImageProcessor();
    
    // Set-function
	BLORT_API void 	SetShaderPath(const char* path){ sprintf(m_shaderPath, "%s", path); }
	BLORT_API void	ShowLog(bool b){ m_showlog = b; }

	// Get-functions
	BLORT_API IplImage* 			GetNewImage();
	BLORT_API IplImage* 			GetImage();
	BLORT_API ImageProcessor* 	GetImageProcessor();
	
	BLORT_API Shader*					GetShader(int id);
	
	// Add-functions
	BLORT_API int		AddShader(	const char* shadername,
						const char* vertex_file = NULL,
						const char* fragment_file = NULL,
						const char* header = NULL);
	
	// Release-functions
	BLORT_API void ReleaseShader();
	BLORT_API void ReleaseShader(int id);
	
	// Search-functions
	BLORT_API int	SearchShaderName(const char* filename);
};

} // namespace Tracking

#endif
