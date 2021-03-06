#ifndef COM_NGOS_SHARED_COMMON_LOG_LOG_H
#define COM_NGOS_SHARED_COMMON_LOG_LOG_H



#if defined(UEFI_APPLICATION)                                                   // Defined in pro file
#include <com/ngos/shared/uefibase/uefi/uefilog.h>
#elif defined(BUILD_TARGET_KERNEL)                                              // Defined in pro file
#include <com/ngos/shared/common/early/earlylog.h>
#else
#include <buildconfig.h>
#include <com/ngos/shared/common/serial/serial.h>
#endif



// Ignore CppAlignmentVerifier [BEGIN]
#if defined(UEFI_APPLICATION)                                                // Defined in pro file
#define __COMMON_PRINT_LOG(level, message) __UEFI_PRINT_LOG(level, message)  // TEST: NO
#define __COMMON_PRINT_LT(message)         __UEFI_PRINT_LT(message)          // TEST: NO
#elif defined(BUILD_TARGET_KERNEL)                                           // Defined in pro file
#define __COMMON_PRINT_LOG(level, message) __EARLY_PRINT_LOG(level, message) // TEST: NO
#define __COMMON_PRINT_LT(message)         __EARLY_PRINT_LT(message)         // TEST: NO
#else
#define __COMMON_PRINT_LOG(level, message) \
    Serial::print(level); \
    Serial::printf message;

#define __COMMON_PRINT_LT(message) \
    Serial::print("TRACE:     "); \
    Serial::print(__PRETTY_FUNCTION__); \
    Serial::printf message;
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL
#define COMMON_LF(message) \
    __COMMON_PRINT_LOG("FATAL:     ", message);
#else
#define COMMON_LF(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL
#define COMMON_LC(message) \
    __COMMON_PRINT_LOG("CRITICAL:  ", message);
#else
#define COMMON_LC(message)
#endif



#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR
#define COMMON_LE(message) \
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
#define COMMON_LT(message) __COMMON_PRINT_LT(message) // TEST: NO
#else
#define COMMON_LT(message)
#endif
// Ignore CppAlignmentVerifier [END]



#endif // COM_NGOS_SHARED_COMMON_LOG_LOG_H
