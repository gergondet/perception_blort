 /**
 * @file GLWindow.h
 * @author Thomas Moerwald (Vienna University of Technology)
 * @date June 2010
 * @version 0.1
 * @brief Device Context for handling OpenGL windows in MS GLWindows.
 */
 
#ifndef _GL_WINDOW_
#define _GL_WINDOW_

#include <blort/api.h>
#include <blort/GLWindow/GLEvent.h>

/** @brief BLORT namespace for GLWindow */
namespace blortGLWindow{

#ifdef WIN32
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
#endif

struct GLWindowImpl;

/** @brief Class GLWindow */
class GLWindow{

public:
	/** @brief Construction of an OpenGL Window (Rendering Context)
	*   @param width Window and OpenGL viewport width in pixel
	*   @param height Window and OpenGL viewport height in pixel
  *   @param name Caption of the window in the titel bar
  *   @param visible if false the window will not be mapped to the display */
  BLORT_API GLWindow();
  BLORT_API GLWindow(unsigned int width, unsigned int height);
  BLORT_API GLWindow(unsigned int width, unsigned int height, const char* name, bool visible = true);
  BLORT_API ~GLWindow();

  /** @brief Activate window for usage (set focus) */
  BLORT_API void Activate();

  /** @brief Update OpenGL GLWindow (Swap Buffers) */
  BLORT_API void Update();

  /** @brief Query input event 
  *   @return true if there are events in the event que 
  *		@param Event defined in TMGLEvent.h */
  BLORT_API bool GetEvent(Event &event);

#ifdef WIN32
  HWND gethWnd() const {return hWnd;}
#endif

protected:
  GLWindowImpl * impl;

  BLORT_API void init(unsigned int width, unsigned int height, const char* name, bool visible = true);
  BLORT_API void quit();
  
};

} /* namespace */

#endif /* _GL_WINDOW_ */
