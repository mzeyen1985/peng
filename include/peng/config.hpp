#pragma once

#include <string>
#include <unordered_map>




// operating system detection
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
    #define PENG_WINDOWS
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #ifndef NOMINMAX
        #define NOMINMAX
    #endif
#elif defined(linux) || defined(__linux)
    #define PENG_LINUX
#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)
    #define PENG_APPLE
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    #define PENG_FREEBSD
#else
    #error Unsupported operating system!
#endif

// compiler detection
#if defined(__clang__)
    #define PENG_CLANG
#elif defined(__GNUG__)
    #define PENG_GCC
#elif defined(_MSC_VER)
    #define PENG_MSVC
#endif

// plugin file extension detection
#ifdef PENG_WINDOWS
    #define PENG_PLUGIN_EXTENSION ".dll"
#elif defined(PENG_APPLE)
    #define PENG_PLUGIN_EXTENSION ".dylib"
#elif defined(PENG_LINUX) || defined(PENG_FREEBSD)
    #define PENG_PLUGIN_EXTENSION ".so"
#else
    #error Unsupported operating system!
#endif

// import/export macros
#ifdef PENG_WINDOWS
    #ifdef PENG_STATIC_DEFINE
        #define PENG_EXPORT
        #define PENG_NO_EXPORT
    #else
        #ifndef PENG_EXPORT
            #ifdef PENG_EXPORTS
                #define PENG_EXPORT __declspec(dllexport)
            #else
                #define PENG_EXPORT __declspec(dllimport)
            #endif
        #endif
        #ifndef PENG_NO_EXPORT
            #define PENG_NO_EXPORT
        #endif
    #endif
#else
    #ifndef PENG_EXPORT
        #define PENG_EXPORT __attribute__ ((visibility ("default"))
    #endif
    #ifndef PENG_NO_EXPORT
        #define PENG_NO_EXPORT __attribute__ ((visibility ("hidden"))
    #endif
#endif

// constructor parameters container
using config_t = std::unordered_map<std::string, std::string>