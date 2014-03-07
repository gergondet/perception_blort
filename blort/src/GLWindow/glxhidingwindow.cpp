#include <blort/GLWindow/glxhidingwindow.h>

#include <stdio.h>
#include <stdexcept>

pal_blort::GLXHidingWindow::GLXHidingWindow()
        : ::blortGLWindow::GLWindow(1, 1, "tracker", false)
{
#ifndef WIN32
    XIconifyWindow(dpy, glWin, 0);
#endif
}

pal_blort::GLXHidingWindow::GLXHidingWindow(unsigned int width, unsigned int height)
    : ::blortGLWindow::GLWindow(width, height, "tracker", false)
{
#ifndef WIN32
    XIconifyWindow(dpy, glWin, 0);
#endif
}

pal_blort::GLXHidingWindow::GLXHidingWindow(unsigned int width, unsigned int height, const char* name)
    : ::blortGLWindow::GLWindow(width, height, name, false)
{
#ifndef WIN32
  //XIconifyWindow(dpy, glWin, 0);
  XUnmapWindow(dpy, glWin);
#endif
}
