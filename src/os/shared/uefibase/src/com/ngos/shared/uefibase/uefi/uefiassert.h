#ifndef OS_SHARED_UEFIBASE_SRC_COM_NGOS_SHARED_UEFIBASE_UEFI_UEFIASSERT_H
#define OS_SHARED_UEFIBASE_SRC_COM_NGOS_SHARED_UEFIBASE_UEFI_UEFIASSERT_H



#include <buildconfig.h>
#include <com/ngos/shared/common/console/console.h>
#include <com/ngos/shared/common/console/graphicalconsole.h>
#include <com/ngos/shared/common/macro/utils.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/serial/serial.h>
#include <com/ngos/shared/uefibase/uefi/uefi.h>
#include <com/ngos/shared/uefibase/uefi/uefilogfile.h>



// Ignore CppAlignmentVerifier [BEGIN]
// Ignore CppIndentVerifier [BEGIN]
#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES
#define __UEFI_LOG_FILE_PRINT_ASSERT_1(message) \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::init(); \
    }

#define __UEFI_LOG_FILE_PRINT_ASSERT_2(message) \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::println(printfBuffer); \
    }
#else
#define __UEFI_LOG_FILE_PRINT_ASSERT_1(message)
#define __UEFI_LOG_FILE_PRINT_ASSERT_2(message)
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO
#define __UEFI_PRINT_ASSERT(message) \
    __UEFI_LOG_FILE_PRINT_ASSERT_1(message); \
    \
    if (GraphicalConsole::canPrint()) \
    { \
        GraphicalConsole::init(); \
        \
        Serial::printf message; \
        GraphicalConsole::println(printfBuffer); \
    } \
    else \
    if (Console::canPrint()) \
    { \
        Serial::printf message; \
        Console::println(printfBuffer); \
    } \
    else \
    if (UEFI::canPrint()) \
    { \
        UEFI::printf message; \
    } \
    else \
    { \
        Serial::printf message; \
    } \
    \
    __UEFI_LOG_FILE_PRINT_ASSERT_2(message);



#define __UEFI_ASSERT_2(condition, message) \
    if (!(condition)) \
    { \
        __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | %s", __FILE__, __LINE__, message)); \
        return; \
    }

#define __UEFI_ASSERT_3(condition, message, returnValue) \
    if (!(condition)) \
    { \
        __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | %s", __FILE__, __LINE__, message)); \
        return returnValue; \
    }
#else
#define __UEFI_ASSERT_2(condition, message)
#define __UEFI_ASSERT_3(condition, message, returnValue)
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES
#define __UEFI_TEST_ASSERT_1(condition) \
    if (!(condition)) \
    { \
        __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | Condition \"%s\" failed", __FILE__, __LINE__, #condition)); \
        return; \
    }

#define __UEFI_TEST_ASSERT_2(condition, returnValue) \
    if (!(condition)) \
    { \
        __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | Condition \"%s\" failed", __FILE__, __LINE__, #condition)); \
        return returnValue; \
    }
#else
#define __UEFI_TEST_ASSERT_1(condition)
#define __UEFI_TEST_ASSERT_2(condition, returnValue)
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES
#define __UEFI_ASSERT_EXECUTION_1(command) \
    { \
        NgosStatus __exec_result = command; \
        \
        if (__exec_result != NgosStatus::OK) \
        { \
            __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code %s", __FILE__, __LINE__, #command, enumToFullString(__exec_result))); \
            return; \
        } \
    }

#define __UEFI_ASSERT_EXECUTION_2(command, returnValue) \
    { \
        NgosStatus __exec_result = command; \
        \
        if (__exec_result != NgosStatus::OK) \
        { \
            __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code %s", __FILE__, __LINE__, #command, enumToFullString(__exec_result))); \
            return returnValue; \
        } \
    }

#define __UEFI_ASSERT_EXECUTION_3(command, resultType, expectedValue) \
    { \
        resultType __exec_result = command; \
        \
        if (__exec_result != expectedValue) \
        { \
            __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed", __FILE__, __LINE__, #command)); \
            return; \
        } \
    }

#define __UEFI_ASSERT_EXECUTION_4(command, resultType, expectedValue, returnValue) \
    { \
        resultType __exec_result = command; \
        \
        if (__exec_result != expectedValue) \
        { \
            __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed", __FILE__, __LINE__, #command)); \
            return returnValue; \
        } \
    }
#else
#define __UEFI_ASSERT_EXECUTION_1(command)                                         command;
#define __UEFI_ASSERT_EXECUTION_2(command, returnValue)                            command;
#define __UEFI_ASSERT_EXECUTION_3(command, resultType, expectedValue)              command;
#define __UEFI_ASSERT_EXECUTION_4(command, resultType, expectedValue, returnValue) command;
#endif
// Ignore CppIndentVerifier [END]
// Ignore CppAlignmentVerifier [END]



#define UEFI_ASSERT(...)           __OVERRIDE_MACRO3(__VA_ARGS__, __UEFI_ASSERT_3, __UEFI_ASSERT_2)(__VA_ARGS__)
#define UEFI_TEST_ASSERT(...)      __OVERRIDE_MACRO2(__VA_ARGS__, __UEFI_TEST_ASSERT_2, __UEFI_TEST_ASSERT_1)(__VA_ARGS__)
#define UEFI_ASSERT_EXECUTION(...) __OVERRIDE_MACRO4(__VA_ARGS__, __UEFI_ASSERT_EXECUTION_4, __UEFI_ASSERT_EXECUTION_3, __UEFI_ASSERT_EXECUTION_2, __UEFI_ASSERT_EXECUTION_1)(__VA_ARGS__)



#endif // OS_SHARED_UEFIBASE_SRC_COM_NGOS_SHARED_UEFIBASE_UEFI_UEFIASSERT_H