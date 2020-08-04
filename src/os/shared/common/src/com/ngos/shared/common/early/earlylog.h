#ifndef COM_NGOS_SHARED_COMMON_EARLY_EARLYLOG_H
#define COM_NGOS_SHARED_COMMON_EARLY_EARLYLOG_H



#include <buildconfig.h>
#include <com/ngos/shared/common/console/console.h>
#include <com/ngos/shared/common/console/graphicalconsole.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/serial/serial.h>



// Ignore CppAlignmentVerifier [BEGIN]
// Ignore CppIndentVerifier [BEGIN]
#define __EARLY_PRINT_LOG(level, message) \
    if (GraphicalConsole::canPrint()) \
    { \
        GraphicalConsole::init(); \
        \
        Serial::print(level); \
        GraphicalConsole::print(level); \
        \
        Serial::printf message; \
        GraphicalConsole::println(printfBuffer); \
    } \
    else \
    if (Console::canPrint()) \
    { \
        Serial::print(level); \
        Console::print(level); \
        \
        Serial::printf message; \
        Console::println(printfBuffer); \
    } \
    else \
    { \
        Serial::print(level); \
        Serial::printf message; \
    }



#define __EARLY_PRINT_LT(message) \
    if (GraphicalConsole::canPrint()) \
    { \
        GraphicalConsole::init(); \
        \
        Serial::print("TRACE:     "); \
        GraphicalConsole::print("TRACE:     "); \
        \
        Serial::print(__PRETTY_FUNCTION__); \
        GraphicalConsole::print(__PRETTY_FUNCTION__); \
        \
        Serial::printf message; \
        GraphicalConsole::println(printfBuffer); \
    } \
    else \
    if (Console::canPrint()) \
    { \
        Serial::print("TRACE:     "); \
        Console::print("TRACE:     "); \
        \
        Serial::print(__PRETTY_FUNCTION__); \
        Console::print(__PRETTY_FUNCTION__); \
        \
        Serial::printf message; \
        Console::println(printfBuffer); \
    } \
    else \
    { \
        Serial::print("TRACE:     "); \
        Serial::print(__PRETTY_FUNCTION__); \
        Serial::printf message; \
    }



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL
#define EARLY_LF(message) \
    __EARLY_PRINT_LOG("FATAL:     ", message);
#else
#define EARLY_LF(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL
#define EARLY_LC(message) \
    __EARLY_PRINT_LOG("CRITICAL:  ", message);
#else
#define EARLY_LC(message)
#endif



#if NGOS_BUILD_EARLY_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR || NGOS_BUILD_EARLY_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR
#define EARLY_LE(message) \
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



#endif // COM_NGOS_SHARED_COMMON_EARLY_EARLYLOG_H
