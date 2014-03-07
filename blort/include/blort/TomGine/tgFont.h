 /**
 * @file tgFont.h
 * @author Thomas Mörwald
 * @date October 2009
 * @version 0.1
 * @link file:///usr/share/doc/libftgl-dev/html/index.html FTGL User Guide
 * @brief Main file of rendering engine 'TomGine'.
 * @namespace TomGine
 */
 
#ifndef _TG_FONT_H_
#define _TG_FONT_H_
 
#ifdef USE_FTGL_FONT
#include <FTGL/ftgl.h>
#endif

#include <blort/api.h>

namespace TomGine{

class tgFont
{
private:
#ifdef USE_FTGL_FONT
	FTFont* m_font;
#endif
public:
	BLORT_API tgFont();
	BLORT_API ~tgFont();
	
	BLORT_API void Print(const char* text, int size, int pos_x, int pos_y) const;
	BLORT_API void Print(const char* text, int size, int pos_x, int pos_y, float x, float y, float z, float a=1) const;

};

}

#endif
