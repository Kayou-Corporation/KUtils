#pragma once

#if (defined(_DEBUG) || defined(DEBUG) || defined(__DEBUG__) || defined(__DEBUG)) || not defined(NDEBUG)
    #define KDEBUG
#else
    #define KRELEASE
#endif