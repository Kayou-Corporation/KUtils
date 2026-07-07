#pragma once

// platform
#if defined(_WIN32) || defined(_WIN64)
    #define KWINDOWS
    #define KPLATFORM_NAME "Windows"
#elif defined(__linux__)
    #define KLINUX
    #define KPLATFORM_NAME "Linux"
#elif defined(__APPLE__) && defined(__MACH__)
    #include <TargetConditionals.h>

#if TARGET_OS_IPHONE
    #define KIOS 1
    #define KPLATFORM_NAME "iOS"
#else
    #define KMACOS
    #define KPLATFORM_NAME "macOS"
#endif
#else
    #define KUNKNOWN_PLATFORM
    #define KPLATFORM_NAME "Unknown"
#endif

// Compiler
#if defined(__clang__)
    #define KCOMPILER_CLANG
    #define KCOMPILER_NAME "Clang"
    #define KCOMPILER_VERSION (__clang_major__ * 100 + __clang_minor__)
#elif defined(__GNUC__)
    #define KCOMPILER_GCC
    #define KCOMPILER_NAME "GCC"
    #define KCOMPILER_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
#elif defined(_MSC_VER)
    #define KCOMPILER_MSVC
    #define KCOMPILER_NAME "MSVC"
    #define KCOMPILER_VERSION _MSC_VER
#else
    #define KCOMPILER_UNKNOWN
    #define KCOMPILER_NAME "Unknown"
#endif