#ifndef GLXHIDINGWINDOW_H
#define GLXHIDINGWINDOW_H

#include <blort/api.h>
#include <blort/GLWindow/GLWindow.h>

namespace pal_blort
{
    class GLXHidingWindow : public ::blortGLWindow::GLWindow
    {
    public:
        BLORT_API GLXHidingWindow();
        BLORT_API GLXHidingWindow(unsigned int width, unsigned int height);
        BLORT_API GLXHidingWindow(unsigned int width, unsigned int height, const char* name);
  };
}
#endif // GLXHIDINGWINDOW_H
