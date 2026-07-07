#pragma once

#if defined(__x86_64__) || defined(_M_X64)
#define KARCH_X64
#define KARCH_NAME "x86_64"
#elif defined(__i386__) || defined(_M_IX86)
#define KARCH_X86
#define KARCH_NAME "x86"
#elif defined(__aarch64__) || defined(_M_ARM64)
#define KARCH_ARM_X64
#define KARCH_NAME "ARM64"
#elif defined(__arm__) || defined(_M_ARM)
#define KARCH_ARM
#define KARCH_NAME "ARM"
#else
#define KARCH_UNKNOW
#define KARCH_NAME "Unknown"
#endif