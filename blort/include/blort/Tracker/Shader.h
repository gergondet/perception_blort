/* Shader
 *
 * Copyright (C) 2005, Maurizio Monge <maurizio.monge@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __SHADER_H__
#define __SHADER_H__



#include <blort/Tracker/headers.h>
#include <blort/TomGine/tgMathlib.h>

namespace Tracking{

/**
@author Maurizio Monge
*/
class Shader{
private:
    GLhandleARB fragment;
    GLhandleARB vertex;
    GLhandleARB program;
public:
    BLORT_API Shader(	const char *vertex_file = NULL,
    		const char *fragment_file = NULL,
    		const char *header = NULL);
    BLORT_API ~Shader();

    BLORT_API void bind();
    BLORT_API void unbind();
    BLORT_API void dumpVars();
    BLORT_API void printInfoLog(GLhandleARB obj, const char *msg, ...);
    BLORT_API bool getStatus();

    BLORT_API GLuint getAttribLoc(const char*);
    BLORT_API GLint  getUniformLoc(const char*);
    BLORT_API void setUniform(const char*,int);
    BLORT_API void setUniform(const char*,unsigned);
    BLORT_API void setUniform(const char*,int,const int*);
    BLORT_API void setUniform(const char*,float);
    BLORT_API void setUniform(const char*,int,const float*);
    BLORT_API void setUniform(const char*,vec2);
    BLORT_API void setUniform(const char* var,int n,vec2* f);
    BLORT_API void setUniform(const char*,vec3);
    BLORT_API void setUniform(const char* var,int n,vec3* f);
    BLORT_API void setUniform(const char*,vec4);
    BLORT_API void setUniform(const char* var,int n,vec4* f);
    BLORT_API void setUniform(const char*,mat3,bool transpose=false);
    BLORT_API void setUniform(const char* var,int n,mat3* f,bool transpose);
    BLORT_API void setUniform(const char*,mat4,bool transpose=false);
    BLORT_API void setUniform(const char* var,int n,mat4* f,bool transpose);


};

} //namespace Tracking

#endif //__SHADER_H__
