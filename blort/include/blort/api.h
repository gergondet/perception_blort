#ifndef BLORT_API
    #ifndef WIN32
    #define BLORT_API
    #else
    #define BLORT_API __declspec(dllexport)
    #endif
#endif