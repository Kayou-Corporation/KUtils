#pragma once

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
#define KUNKNOW_PLATFORM
#define KPLATFORM_NAME "Unknown"
#endif