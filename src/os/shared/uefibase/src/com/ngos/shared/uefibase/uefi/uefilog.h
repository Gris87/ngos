#ifndef COM_NGOS_SHARED_UEFIBASE_UEFI_UEFILOG_H
#define COM_NGOS_SHARED_UEFIBASE_UEFI_UEFILOG_H



#include <buildconfig.h>
#include <com/ngos/shared/common/console/console.h>
#include <com/ngos/shared/common/console/graphicalconsole.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/serial/serial.h>
#include <com/ngos/shared/uefibase/uefi/uefi.h>
#include <com/ngos/shared/uefibase/uefi/uefilogfile.h>



// Ignore CppAlignmentVerifier [BEGIN]
// Ignore CppIndentVerifier [BEGIN]
#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES
#define __UEFI_LOG_FILE_PRINT_LOG_1() \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::init(); \
    }

#define __UEFI_LOG_FILE_PRINT_LOG_2(level) \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::print(level); \
        UefiLogFile::println(message); \
    }

#define __UEFI_LOG_FILE_PRINT_LOG_3(level) \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::print(timestampBuffer); \
        UefiLogFile::print("| "); \
        UefiLogFile::print(level); \
        UefiLogFile::println(printfBuffer); \
    }
#else
#define __UEFI_LOG_FILE_PRINT_LOG_1()
#define __UEFI_LOG_FILE_PRINT_LOG_2(level)
#define __UEFI_LOG_FILE_PRINT_LOG_3(level)
#endif



#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES
#define __UEFI_LOG_FILE_PRINT_LT_1() \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::init(); \
    }

#define __UEFI_LOG_FILE_PRINT_LT_2() \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::print("TRACE:     "); \
        UefiLogFile::print(__PRETTY_FUNCTION__); \
        UefiLogFile::println(printfBuffer); \
    }

#define __UEFI_LOG_FILE_PRINT_LT_3() \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::print(timestampBuffer); \
        UefiLogFile::print("| TRACE:     "); \
        UefiLogFile::print(__PRETTY_FUNCTION__); \
        UefiLogFile::println(printfBuffer); \
    }
#else
#define __UEFI_LOG_FILE_PRINT_LT_1()
#define __UEFI_LOG_FILE_PRINT_LT_2()
#define __UEFI_LOG_FILE_PRINT_LT_3()
#endif



#if NGOS_BUILD_LOG_TO_SCREEN == OPTION_YES && NGOS_BUILD_LOG_WITH_TIMESTAMP == OPTION_YES
#define __UEFI_PRINT_LOG(level, message) \
    UEFI::currentTimestampToString(timestampBuffer); \
    \
    __UEFI_LOG_FILE_PRINT_LOG_1(); \
    \
    if (GraphicalConsole::canPrint()) \
    { \
        GraphicalConsole::init(); \
        \
        Serial::print(timestampBuffer); \
        GraphicalConsole::print(timestampBuffer); \
        \
        Serial::print("| "); \
        GraphicalConsole::print("| "); \
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
        Serial::print(timestampBuffer); \
        Console::print(timestampBuffer); \
        \
        Serial::print("| "); \
        Console::print("| "); \
        \
        Serial::print(level); \
        Console::print(level); \
        \
        Serial::printf message; \
        Console::println(printfBuffer); \
    } \
    else \
    if (UEFI::canPrint()) \
    { \
        UEFI::print(timestampBuffer); \
        UEFI::print("| "); \
        UEFI::print(level); \
        UEFI::printf message; \
    } \
    else \
    { \
        Serial::print(timestampBuffer); \
        Serial::print("| "); \
        Serial::print(level); \
        Serial::printf message; \
    } \
    \
    __UEFI_LOG_FILE_PRINT_LOG_3(level);



#define __UEFI_PRINT_LT(message) \
    UEFI::currentTimestampToString(timestampBuffer); \
    \
    __UEFI_LOG_FILE_PRINT_LT_1(); \
    \
    if (GraphicalConsole::canPrint()) \
    { \
        GraphicalConsole::init(); \
        \
        Serial::print(timestampBuffer); \
        GraphicalConsole::print(timestampBuffer); \
        \
        Serial::print("| TRACE:     "); \
        GraphicalConsole::print("| TRACE:     "); \
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
        Serial::print(timestampBuffer); \
        Console::print(timestampBuffer); \
        \
        Serial::print("| TRACE:     "); \
        Console::print("| TRACE:     "); \
        \
        Serial::print(__PRETTY_FUNCTION__); \
        Console::print(__PRETTY_FUNCTION__); \
        \
        Serial::printf message; \
        Console::println(printfBuffer); \
    } \
    else \
    if (UEFI::canPrint()) \
    { \
        UEFI::print(timestampBuffer); \
        UEFI::print("| TRACE:     "); \
        UEFI::print(__PRETTY_FUNCTION__); \
        UEFI::printf message; \
    } \
    else \
    { \
        Serial::print(timestampBuffer); \
        Serial::print("| TRACE:     "); \
        Serial::print(__PRETTY_FUNCTION__); \
        Serial::printf message; \
    } \
    \
    __UEFI_LOG_FILE_PRINT_LT_3();
#elif NGOS_BUILD_LOG_TO_SCREEN == OPTION_YES && NGOS_BUILD_LOG_WITH_TIMESTAMP == OPTION_NO
#define __UEFI_PRINT_LOG(level, message) \
    __UEFI_LOG_FILE_PRINT_LOG_1(); \
    \
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
    if (UEFI::canPrint()) \
    { \
        UEFI::print(level); \
        UEFI::printf message; \
    } \
    else \
    { \
        Serial::print(level); \
        Serial::printf message; \
    } \
    \
    __UEFI_LOG_FILE_PRINT_LOG_2(level);



#define __UEFI_PRINT_LT(message) \
    __UEFI_LOG_FILE_PRINT_LT_1(); \
    \
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
    } \
    \
    __UEFI_LOG_FILE_PRINT_LT_2();
#elif NGOS_BUILD_LOG_TO_SCREEN == OPTION_NO && NGOS_BUILD_LOG_WITH_TIMESTAMP == OPTION_YES
#define __UEFI_PRINT_LOG(level, message) \
    UEFI::currentTimestampToString(timestampBuffer); \
    \
    __UEFI_LOG_FILE_PRINT_LOG_1(); \
    \
    Serial::print(timestampBuffer); \
    Serial::print("| "); \
    Serial::print(level); \
    Serial::printf message; \
    \
    __UEFI_LOG_FILE_PRINT_LOG_3(level);



#define __UEFI_PRINT_LT(message) \
    UEFI::currentTimestampToString(timestampBuffer); \
    \
    __UEFI_LOG_FILE_PRINT_LT_1(); \
    \
    Serial::print(timestampBuffer); \
    Serial::print("| TRACE:     "); \
    Serial::print(__PRETTY_FUNCTION__); \
    Serial::printf message; \
    \
    __UEFI_LOG_FILE_PRINT_LT_3();
#elif NGOS_BUILD_LOG_TO_SCREEN == OPTION_NO && NGOS_BUILD_LOG_WITH_TIMESTAMP == OPTION_NO
#define __UEFI_PRINT_LOG(level, message) \
    __UEFI_LOG_FILE_PRINT_LOG_1(); \
    \
    Serial::print(level); \
    Serial::printf message; \
    \
    __UEFI_LOG_FILE_PRINT_LOG_2(level);



#define __UEFI_PRINT_LT(message) \
    __UEFI_LOG_FILE_PRINT_LT_1(); \
    \
    Serial::print("TRACE:     "); \
    Serial::print(__PRETTY_FUNCTION__); \
    Serial::printf message; \
    \
    __UEFI_LOG_FILE_PRINT_LT_2();
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_FATAL
#define UEFI_LF(message) \
    __UEFI_PRINT_LOG("FATAL:     ", message);
#else
#define UEFI_LF(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_CRITICAL
#define UEFI_LC(message) \
    __UEFI_PRINT_LOG("CRITICAL:  ", message);
#else
#define UEFI_LC(message)
#endif



#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_ERROR
#define UEFI_LE(message) \
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
#define UEFI_LT(message) \
    __UEFI_PRINT_LT(message);
#else
#define UEFI_LT(message)
#endif
// Ignore CppIndentVerifier [END]
// Ignore CppAlignmentVerifier [END]



#endif // COM_NGOS_SHARED_UEFIBASE_UEFI_UEFILOG_H
