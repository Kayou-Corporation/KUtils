#pragma once

#include "BuildMode.hpp"
#include "Platform.hpp"

#ifdef KDEBUG
#if defined KCOMPILER_MSVC && not defined(KCOMPILER_CLANG)
#define BREAKPOINT() __debugbreak()
#else
#define BREAKPOINT() __builtin_trap()
#endif

#ifdef KDEBUG
#define ASSERT(condition, message) \
					do { \
						if (!(condition)) { \
							std::cerr << "Assertion failed: " << (message) << " in file " << (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__) << " at line " << __LINE__ << '\n'; \
							BREAKPOINT(); \
						} \
					} while(0)
#else
#define ASSERT(condition, message) \
					do { \
						if (!(condition)) { \
							std::cerr << "Assertion failed: " << (message) << " in file " << (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__) << " at line " << __LINE__ << '\n'; \
							abort(); \
						} \
					} while(0)
#endif

#define KSTATIC_ASSERT(cond, msg) static_assert(cond, msg)