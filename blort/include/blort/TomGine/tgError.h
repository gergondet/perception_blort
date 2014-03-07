
#ifndef _TG_ERROR_H
#define _TG_ERROR_H

#include <blort/TomGine/headers.h>
#include <string>

BLORT_API GLenum tgCheckError(std::string pre_msg);

BLORT_API GLenum tgCheckFBError(GLenum target, std::string pre_msg);

#endif
