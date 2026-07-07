#pragma once

#include "Platform.hpp"

#ifdef EXPORTS
    #if defined KCOMPILER_MSVC && not defined(KCOMPILER_CLANG)
        #define KAPI __declspec(dllexport)
    #else
        #define KAPI __attribute__((visibility("default")))
    #endif
#else
    #if defined KCOMPILER_MSVC && not defined(KCOMPILER_CLANG)
        #define KAPI __declspec(dllimport)
    #else
        #define KAPI
    #endif
#endif