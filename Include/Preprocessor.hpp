#pragma once

#include "Debug.hpp"
#include "Platform.hpp"


// Inline
#if defined(KCOMPILER_CLANG) || defined(KCOMPILER_GCC)
    #define KINLINE inline __attribute__((always_inline))
#elif defined(KCOMPILER_MSVC)
    #define KINLINE __forceinline
#else
    #define KINLINE inline
#endif

/// NoInline : Compiler-specific utilities
#if defined(KCOMPILER_CLANG) || defined(KCOMPILER_GCC)
    #define KNO_INLINE __attribute__((noinline))
#elif defined(KCOMPILER_MSVC)
    #define KNO_INLINE __declspec(noinline)
#else
    #define KNO_INLINE
#endif

/// NoDiscard
#if defined(__has_cpp_attribute)
    #if __has_cpp_attribute(nodiscard)
        #define KNO_DISCARD [[nodiscard]]
    #else
        #define KNO_DISCARD
    #endif
#else
    #define KNO_DISCARD
#endif

/// RESTRICT
/// Pointer aliasing hints that tell the compiler this pointer is unique.
/// Enables better vectorization and memory optimization.
#if defined(KCOMPILER_CLANG) || defined(KCOMPILER_GCC)
    #define KRESTRICT __restrict__
#elif defined(KCOMPILER_MSVC)
    #define KRESTRICT __restrict
#else
    #define KRESTRICT
#endif

/// UNREACHABLE
/// Marks code as unreachable.
/// Helps the compiler optimize control flow and may catch logic errors in debug builds.
#if defined(KCOMPILER_CLANG) || defined(KCOMPILER_GCC)
    #define KUNREACHABLE() __builtin_unreachable()
#elif defined(KCOMPILER_MSVC)
    #define KUNREACHABLE() __assume(0)
#else
    #define KUNREACHABLE()
#endif

#define KCACHE_ALIGN alignas(64)
#define KCACHE_ALIGN_AS(x) alignas(x)

#define KSTRINGIFY(x) #x
#define KTOSTRING(x) KSTRINGIFY(x)

#define KCONCAT(a, b) a##b
#define KCONCAT_EXPAND(a, b) KCONCAT(a, b)


/// Likely / Unlikely : Branch prediction hints (C++20)
#if defined(__has_cpp_attribute)
    #if __has_cpp_attribute(likely)
        #define KLIKELY [[likely]]
        #define KUNLIKELY [[unlikely]]
    #else
        #define KLIKELY
        #define KUNLIKELY
    #endif
#else
    #define KLIKELY
    #define KUNLIKELY
#endif