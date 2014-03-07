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



#include <blort/TomGine/headers.h>
#include <blort/TomGine/tgMathlib.h>

namespace TomGine{

/**
@author Maurizio Monge
*/
class tgShader{
private:
    GLhandleARB fragment;
    GLhandleARB vertex;
    GLhandleARB program;
public:
    BLORT_API tgShader(	const char *vertex_file = NULL,
    		const char *fragment_file = NULL,
    		const char *header = NULL);
    BLORT_API ~tgShader();

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


/* allocate (and free) aligned memory, align must be power of 2 */
BLORT_API void *malloc_align(size_t size, int align);
BLORT_API void free_align(void *ptr);

/* read entierely a file, returning a 0 terminated string */
BLORT_API char *read_text_file(const char* file);

/* offset of a membet in a structure */
#undef OFFSETOF
#define OFFSETOF(TYPE, MEMBER) (((size_t)&((TYPE *)1)->MEMBER) - 1)

/* some templates */
template<typename T>
T Max(T a,T b)
{
    return a>b?a:b;
}

template<typename T>
T Min(T a,T b)
{
    return a<b?a:b;
}

template<typename T>
T Abs(T a)
{
    return a>0?a:-a;
}

template<typename T>
T Square(T a)
{
    return a*a;
}

template<typename T>
T Sign(T a)
{
    return a==0?0:a>0?1:-1;
}

} //namespace TomGine

#endif //__SHADER_H__
