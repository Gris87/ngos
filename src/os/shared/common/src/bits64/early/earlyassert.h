#ifndef OS_SHARED_COMMON_SRC_BITS64_EARLY_EARLYASSERT_H
#define OS_SHARED_COMMON_SRC_BITS64_EARLY_EARLYASSERT_H



#include <buildconfig.h>
#include <common/src/bits64/console/console.h>
#include <common/src/bits64/console/graphicalconsole.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/serial/serial.h>
#include <macro/utils.h>
#include <ngos/status.h>



// Ignore CppAlignmentVerifier [BEGIN]
// Ignore CppIndentVerifier [BEGIN]
#if NGOS_BUILD_RELEASE == OPTION_NO
#define __EARLY_PRINT_ASSERT(message) \
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
    { \
        Serial::printf message; \
    }



#define __EARLY_ASSERT_2(condition, message) \
    if (!(condition)) \
    { \
        __EARLY_PRINT_ASSERT(("ASSERT:    %s:%u | %s", __FILE__, __LINE__, message)); \
        return; \
    }

#define __EARLY_ASSERT_3(condition, message, returnValue) \
    if (!(condition)) \
    { \
        __EARLY_PRINT_ASSERT(("ASSERT:    %s:%u | %s", __FILE__, __LINE__, message)); \
        return returnValue; \
    }
#else
#define __EARLY_ASSERT_2(condition, message)
#define __EARLY_ASSERT_3(condition, message, returnValue)
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES
#define __EARLY_TEST_ASSERT_1(condition) \
    if (!(condition)) \
    { \
        __EARLY_PRINT_ASSERT(("ASSERT:    %s:%u | Condition \"%s\" failed", __FILE__, __LINE__, #condition)); \
        return; \
    }

#define __EARLY_TEST_ASSERT_2(condition, returnValue) \
    if (!(condition)) \
    { \
        __EARLY_PRINT_ASSERT(("ASSERT:    %s:%u | Condition \"%s\" failed", __FILE__, __LINE__, #condition)); \
        return returnValue; \
    }
#else
#define __EARLY_TEST_ASSERT_1(condition)
#define __EARLY_TEST_ASSERT_2(condition, returnValue)
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES
#define __EARLY_ASSERT_EXECUTION_1(command) \
    { \
        NgosStatus __exec_result = command; \
        \
        if (__exec_result != NgosStatus::OK) \
        { \
            __EARLY_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code %s", __FILE__, __LINE__, #command, enumToFullString(__exec_result))); \
            return; \
        } \
    }

#define __EARLY_ASSERT_EXECUTION_2(command, returnValue) \
    { \
        NgosStatus __exec_result = command; \
        \
        if (__exec_result != NgosStatus::OK) \
        { \
            __EARLY_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code %s", __FILE__, __LINE__, #command, enumToFullString(__exec_result))); \
            return returnValue; \
        } \
    }

#define __EARLY_ASSERT_EXECUTION_3(command, resultType, expectedValue) \
    { \
        resultType __exec_result = command; \
        \
        if (__exec_result != expectedValue) \
        { \
            __EARLY_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed", __FILE__, __LINE__, #command)); \
            return; \
        } \
    }

#define __EARLY_ASSERT_EXECUTION_4(command, resultType, expectedValue, returnValue) \
    { \
        resultType __exec_result = command; \
        \
        if (__exec_result != expectedValue) \
        { \
            __EARLY_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed", __FILE__, __LINE__, #command)); \
            return returnValue; \
        } \
    }
#else
#define __EARLY_ASSERT_EXECUTION_1(command)                                         command;
#define __EARLY_ASSERT_EXECUTION_2(command, returnValue)                            command;
#define __EARLY_ASSERT_EXECUTION_3(command, resultType, expectedValue)              command;
#define __EARLY_ASSERT_EXECUTION_4(command, resultType, expectedValue, returnValue) command;
#endif
// Ignore CppIndentVerifier [END]
// Ignore CppAlignmentVerifier [END]



#define EARLY_ASSERT(...)           __OVERRIDE_MACRO3(__VA_ARGS__, __EARLY_ASSERT_3, __EARLY_ASSERT_2)(__VA_ARGS__)
#define EARLY_TEST_ASSERT(...)      __OVERRIDE_MACRO2(__VA_ARGS__, __EARLY_TEST_ASSERT_2, __EARLY_TEST_ASSERT_1)(__VA_ARGS__)
#define EARLY_ASSERT_EXECUTION(...) __OVERRIDE_MACRO4(__VA_ARGS__, __EARLY_ASSERT_EXECUTION_4, __EARLY_ASSERT_EXECUTION_3, __EARLY_ASSERT_EXECUTION_2, __EARLY_ASSERT_EXECUTION_1)(__VA_ARGS__)



#endif // OS_SHARED_COMMON_SRC_BITS64_EARLY_EARLYASSERT_H
