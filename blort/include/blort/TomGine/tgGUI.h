/**
* @file TomtgGUI.h
* @author Thomas Mörwald
* @date September 2010
* @version 0.1
* @brief OpenGL tgGUI
* @namespace TomtgGUI
*/

#ifndef TOMGINE_TGGUI
#define TOMGINE_TGGUI


#include <blort/GLWindow/GLWindow.h>

#include <vector>

namespace TomGine{

class tgGUI
{
private:
	unsigned m_width, m_height;
	
	blortGLWindow::GLWindow* m_window;
	
	bool InputControl(blortGLWindow::Event &event);


public:
	BLORT_API tgGUI(unsigned width, unsigned height);
	BLORT_API ~tgGUI();
	
	BLORT_API bool Update();
	
	BLORT_API void Activate(){ m_window->Activate(); }
	
	
	BLORT_API void GetPlot2D(int x, int y, unsigned w, unsigned h);

	BLORT_API void Screenshot(const char* filename) const;

};

}


#endif
