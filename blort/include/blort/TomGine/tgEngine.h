/**
* @file tgEngine.h
* @author Thomas Mörwald
* @date October 2009
* @version 0.1
* @brief Main file of rendering engine 'TomGine'.
* @namespace TomGine
*/

#ifndef TG_ENGINE
#define TG_ENGINE

#include <blort/TomGine/headers.h>

#include <blort/GLWindow/GLWindow.h>
#include <blort/TomGine/tgCamera.h>
#include <blort/TomGine/tgLighting.h>
#include <blort/TomGine/tgRenderModel.h>
#include <blort/TomGine/tgPose.h>
#include <blort/TomGine/tgTimer.h>
#include <blort/TomGine/tgVector3.h>
#include <blort/TomGine/tgMathlib.h>

namespace TomGine{

/** @brief Class tgEngine */
class tgEngine
{
private:
	unsigned m_width;
	unsigned m_height;
	float m_far;
	float m_near;
	
	float m_input_rotation_speed;
	float m_input_translation_speed;
	float m_input_zoom_speed;
	
	blortGLWindow::GLWindow* m_window;
	tgTexture* m_background_image;
	
	tgCamera 		m_cam[6];
	tgCamera		m_camera;
	tgCamera		m_cam_ortho;

	tgLighting 		m_lighting;
	tgLight			m_light0;
	tgTimer 		m_timer;
	tgVector3		m_cor;			///< Center of Rotation
	
	int m_mouse_pos[2];
	bool p_pressed;
	
	float m_frametime;
	bool m_bfc;
	bool m_button_left, m_button_middle, m_button_right;
	bool m_wireframe;
	bool m_smoothshading;
	bool m_show_background_image;
	bool m_flip_background_image;
	
// 	FTTextureFont* m_font_tf;
	tgFont m_font;
	
	void DrawBackgroundImage();
	
public:
	/** @brief Initialising render engine
	* @param width Width of rendering window in pixels
	* @param height Height of rendering window in pixels
	* @param depth Depth of object to render (Distance between camera and object to render in meter)
	* @param name Caption of Window
	* @param bfc Enable / Disable back face culling (render back face of polygons or not)
	* @return Success of initialisation */
	BLORT_API tgEngine(	unsigned width=640,
				unsigned height=480,
				float far=10.0f,
				float near=0.01f,
				const char* name="TomGine",
				bool bfc=false);
				
	BLORT_API ~tgEngine();
	
	/** @brief Welcome message */
	BLORT_API void Welcome();
	
	/** @brief Draws content to  frame screen
	* @param time Time in seconds since last Update() call 
	* @param event GLX event */
	BLORT_API bool Update();
	BLORT_API bool Update(float &fTime);
	BLORT_API bool Update(std::vector<blortGLWindow::Event> &eventlist);
	BLORT_API bool Update(float &fTime, std::vector<blortGLWindow::Event> &eventlist);
	
	
	/** @brief Handles keyboard and mouse input applied to this window */
	BLORT_API bool InputControl(blortGLWindow::Event &event);
	
	/**	@brief Draws a simple coordinate frame */
	BLORT_API void DrawCoordinates();
	
	/** @brief Sets Camera of rendering engine (including internal and external camera parameters) */
	BLORT_API void SetCamera(tgCamera cam);
	BLORT_API void UpdateCameraViews(tgCamera cam);
	
	/**	@brief Sets center of rotation */
	BLORT_API void SetCenterOfRotation(float x, float y, float z);
	
	/** @brief Activates 3D rendering mode; standard after Update() */
	BLORT_API void Activate3D();

	/** @brief Activates 2D rendering moder */
	BLORT_API void Activate2D();
	
	/** @brief Swaps frame buffer to screen (called by Update() aswell)*/
	BLORT_API void Swap();
	
	BLORT_API void LoadBackgroundImage(unsigned char* image_data, int width, int height, GLenum format=GL_RGB, bool flip=false);
	BLORT_API void UnloadBackgroundImage();
	
	/**	@brief Returns the actual position of the camera with respect to the coordinate frame */
	BLORT_API vec3 GetCameraPosition(){ tgVector3 tgv = m_camera.GetPos(); return vec3(tgv.x, tgv.y, tgv.z); }

	/** @brief get a copy of the current camera of the engine */
	BLORT_API void GetCamera0(tgCamera &cam){ cam = m_camera; }
	
	/** @brief get state of wireframe drawing mode (wireframe mode on/off) */
	BLORT_API bool GetWireframeMode(){ return m_wireframe; }
	
	BLORT_API void PrintText3D(std::string text, vec3 pos, int size=16);
	BLORT_API void PrintText2D(std::string text, vec2 pos, int size=16);
	
	/** Set input speed for mouse control (rotating, zooming and translating)*/
	BLORT_API void SetInputRotationSpeed(float v){ m_input_rotation_speed = v; }
	BLORT_API void SetInputTranslationSpeed(float v){ m_input_translation_speed = v; }
	BLORT_API void SetInputZoomSpeed(float v){ m_input_zoom_speed = v; }
	BLORT_API void SetSpeeds(float rotation, float translation, float zoom){ 
		m_input_rotation_speed  = rotation;
		m_input_translation_speed = translation;
		m_input_zoom_speed = zoom;
	}
		
	BLORT_API tgVector3 Get3DPointFrom2D(int x, int y);
	BLORT_API bool GetNewPoint(vec3& v);

};

} // namespace TomGine

#endif
