#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_A_EARLY_EARLY_EARLYLOG_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_A_EARLY_EARLY_EARLYLOG_H



#include <buildconfig.h>
#include <common/src/bits64/console/console.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/serial/serial.h>



// Ignore CppAlignmentVerifier [BEGIN]
// Ignore CppIndentVerifier [BEGIN]
#define __EARLY_PRINT_LOG(level, message) \
    Serial::print(level); \
    Serial::printf message; \
    \
    if (Console::canPrint()) \
    { \
        Console::print(level); \
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
    }



#define __EARLY_PRINT_LT(message) \
    Serial::print("TRACE:     "); \
    Serial::print(__PRETTY_FUNCTION__); \
    Serial::printf message; \
    \
    if (Console::canPrint()) \
    { \
        Console::print("TRACE:     "); \
        Console::print(__PRETTY_FUNCTION__); \
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
    }



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL
#define EARLY_LF(message) \
    __EARLY_PRINT_LOG("FATAL:     ", message);
#else
#define EARLY_LF(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL
#define EARLY_LC(message)  \
    __EARLY_PRINT_LOG("CRITICAL:  ", message);
#else
#define EARLY_LC(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR
#define EARLY_LE(message)  \
    __EARLY_PRINT_LOG("ERROR:     ", message);
#else
#define EARLY_LE(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_WARNING || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_WARNING
#define EARLY_LW(message) \
    __EARLY_PRINT_LOG("WARNING:   ", message);
#else
#define EARLY_LW(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_INFO || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_INFO
#define EARLY_LI(message) \
    __EARLY_PRINT_LOG("INFO:      ", message);
#else
#define EARLY_LI(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_DEBUG || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_DEBUG
#define EARLY_LD(message) \
    __EARLY_PRINT_LOG("DEBUG:     ", message);
#else
#define EARLY_LD(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERBOSE
#define EARLY_LV(message) \
    __EARLY_PRINT_LOG("VERBOSE:   ", message);
#else
#define EARLY_LV(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERBOSE
#define EARLY_LVV(message) \
    __EARLY_PRINT_LOG("VVERBOSE:  ", message);
#else
#define EARLY_LVV(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
#define EARLY_LVVV(message) \
    __EARLY_PRINT_LOG("VVVERBOSE: ", message);
#else
#define EARLY_LVVV(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE
#define EARLY_LT(message) __EARLY_PRINT_LT(message) // TEST: NO
#else
#define EARLY_LT(message)
#endif
// Ignore CppIndentVerifier [END]
// Ignore CppAlignmentVerifier [END]



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_A_EARLY_EARLY_EARLYLOG_H
