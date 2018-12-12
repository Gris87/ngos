#ifndef OS_COMMON_SRC_BITS64_LOG_LOG_H
#define OS_COMMON_SRC_BITS64_LOG_LOG_H



#include <buildconfig.h>
#include <src/bits64/serial/serial.h>



#define __COMMON_PRINT_LOG(level, message) \
    Serial::print(level); \
    Serial::printf message;



// Ignore CppAlignmentVerifier [BEGIN]
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL
#define COMMON_LF(message) \
    __COMMON_PRINT_LOG("FATAL:     ", message);
#else
#define COMMON_LF(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL
#define COMMON_LC(message)  \
    __COMMON_PRINT_LOG("CRITICAL:  ", message);
#else
#define COMMON_LC(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR
#define COMMON_LE(message)  \
    __COMMON_PRINT_LOG("ERROR:     ", message);
#else
#define COMMON_LE(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_WARNING || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_WARNING
#define COMMON_LW(message) \
    __COMMON_PRINT_LOG("WARNING:   ", message);
#else
#define COMMON_LW(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_INFO || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_INFO
#define COMMON_LI(message) \
    __COMMON_PRINT_LOG("INFO:      ", message);
#else
#define COMMON_LI(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_DEBUG || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_DEBUG
#define COMMON_LD(message) \
    __COMMON_PRINT_LOG("DEBUG:     ", message);
#else
#define COMMON_LD(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE
#define COMMON_LV(message) \
    __COMMON_PRINT_LOG("VERBOSE:   ", message);
#else
#define COMMON_LV(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE
#define COMMON_LVV(message) \
    __COMMON_PRINT_LOG("VVERBOSE:  ", message);
#else
#define COMMON_LVV(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
#define COMMON_LVVV(message) \
    __COMMON_PRINT_LOG("VVVERBOSE: ", message);
#else
#define COMMON_LVVV(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE
#define COMMON_LT(message) \
    Serial::print("TRACE:     "); \
    Serial::print(__PRETTY_FUNCTION__); \
    Serial::printf message;
#else
#define COMMON_LT(message)
#endif
// Ignore CppAlignmentVerifier [END]



#endif // OS_COMMON_SRC_BITS64_LOG_LOG_H
