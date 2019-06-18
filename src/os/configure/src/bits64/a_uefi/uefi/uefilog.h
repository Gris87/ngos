#ifndef CONFIGURE_SRC_BITS64_A_UEFI_UEFI_UEFILOG_H
#define CONFIGURE_SRC_BITS64_A_UEFI_UEFI_UEFILOG_H



#include <buildconfig.h>
#include <common/src/bits64/console/console.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/serial/serial.h>

#include "src/bits64/a_uefi/uefi/uefi.h"



// Ignore CppAlignmentVerifier [BEGIN]
// Ignore CppIndentVerifier [BEGIN]
#define __UEFI_PRINT_LOG(level, message) \
    if (Console::canPrint()) \
    { \
        Serial::print(level); \
        Console::print(level); \
        \
        Serial::printf message; \
        \
        /* HACK: Temporary fix for PIE. Try to find another solution */ \
        /* Console::println(printfBuffer); */ \
        char *__temp; \
        \
        asm volatile( \
            "leaq    printfBuffer(%%rip), %0" /* leaq    printfBuffer(%rip), %rdi   # Get address of printfBuffer variable to RDI. %RDI == __temp*/ \
                :                             /* Output parameters*/ \
                    "=D" (__temp)             /* 'D' - RDI, '=' - write only */ \
        ); \
        \
        Console::println(__temp); \
    } \
    else \
    if (UEFI::canPrint()) \
    { \
        UEFI::print(level); \
        UEFI::printf message; \
    } \
    else \
    { \
        Serial::print(level); \
        Serial::printf message; \
    }



#define __UEFI_PRINT_LT(message) \
    if (Console::canPrint()) \
    { \
        Serial::print("TRACE:     "); \
        Console::print("TRACE:     "); \
        \
        Serial::print(__PRETTY_FUNCTION__); \
        Console::print(__PRETTY_FUNCTION__); \
        \
        Serial::printf message; \
        \
        /* HACK: Temporary fix for PIE. Try to find another solution */ \
        /* Console::println(printfBuffer); */ \
        char *__temp; \
        \
        asm volatile( \
            "leaq    printfBuffer(%%rip), %0" /* leaq    printfBuffer(%rip), %rdi   # Get address of printfBuffer variable to RDI. %RDI == __temp*/ \
                :                             /* Output parameters*/ \
                    "=D" (__temp)             /* 'D' - RDI, '=' - write only */ \
        ); \
        \
        Console::println(__temp); \
    } \
    else \
    if (UEFI::canPrint()) \
    { \
        UEFI::print("TRACE:     "); \
        UEFI::print(__PRETTY_FUNCTION__); \
        UEFI::printf message; \
    } \
    else \
    { \
        Serial::print("TRACE:     "); \
        Serial::print(__PRETTY_FUNCTION__); \
        Serial::printf message; \
    }



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL
#define UEFI_LF(message) \
    __UEFI_PRINT_LOG("FATAL:     ", message);
#else
#define UEFI_LF(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL
#define UEFI_LC(message)  \
    __UEFI_PRINT_LOG("CRITICAL:  ", message);
#else
#define UEFI_LC(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR
#define UEFI_LE(message)  \
    __UEFI_PRINT_LOG("ERROR:     ", message);
#else
#define UEFI_LE(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_WARNING || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_WARNING
#define UEFI_LW(message) \
    __UEFI_PRINT_LOG("WARNING:   ", message);
#else
#define UEFI_LW(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_INFO || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_INFO
#define UEFI_LI(message) \
    __UEFI_PRINT_LOG("INFO:      ", message);
#else
#define UEFI_LI(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_DEBUG || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_DEBUG
#define UEFI_LD(message) \
    __UEFI_PRINT_LOG("DEBUG:     ", message);
#else
#define UEFI_LD(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE
#define UEFI_LV(message) \
    __UEFI_PRINT_LOG("VERBOSE:   ", message);
#else
#define UEFI_LV(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE
#define UEFI_LVV(message) \
    __UEFI_PRINT_LOG("VVERBOSE:  ", message);
#else
#define UEFI_LVV(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
#define UEFI_LVVV(message) \
    __UEFI_PRINT_LOG("VVVERBOSE: ", message);
#else
#define UEFI_LVVV(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE
#define UEFI_LT(message) __UEFI_PRINT_LT(message) // TEST: NO
#else
#define UEFI_LT(message)
#endif
// Ignore CppIndentVerifier [END]
// Ignore CppAlignmentVerifier [END]



#endif // CONFIGURE_SRC_BITS64_A_UEFI_UEFI_UEFILOG_H
