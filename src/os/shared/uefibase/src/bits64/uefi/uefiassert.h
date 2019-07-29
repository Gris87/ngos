#ifndef OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFIASSERT_H
#define OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFIASSERT_H



#include <buildconfig.h>
#include <common/src/bits64/console/console.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/serial/serial.h>
#include <ngos/status.h>
#include <uefibase/src/bits64/uefi/uefi.h>



// Ignore CppAlignmentVerifier [BEGIN]
// Ignore CppIndentVerifier [BEGIN]
#if NGOS_BUILD_RELEASE == OPTION_NO
#define __UEFI_PRINT_ASSERT(message) \
    if (Console::canPrint()) \
    { \
        Serial::printf message; \
        \
        /* HACK: Temporary fix for PIE. Try to find another solution */ \
        /* Console::println(printfBuffer); */ \
        char8 *__temp; \
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
        UEFI::printf message; \
    } \
    else \
    { \
        Serial::printf message; \
    }



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
            __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code 0x%016lX (%s)", __FILE__, __LINE__, #command, __exec_result, ngosStatusToString(__exec_result))); \
            return; \
        } \
    }

#define __UEFI_ASSERT_EXECUTION_2(command, returnValue) \
    { \
        NgosStatus __exec_result = command; \
        \
        if (__exec_result != NgosStatus::OK) \
        { \
            __UEFI_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code 0x%016lX (%s)", __FILE__, __LINE__, #command, __exec_result, ngosStatusToString(__exec_result))); \
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



#define __OVERRIDE_MACRO2(_1, _2,         NAME, ...) NAME
#define __OVERRIDE_MACRO3(_1, _2, _3,     NAME, ...) NAME
#define __OVERRIDE_MACRO4(_1, _2, _3, _4, NAME, ...) NAME



#define UEFI_ASSERT(...)           __OVERRIDE_MACRO3(__VA_ARGS__, __UEFI_ASSERT_3, __UEFI_ASSERT_2)(__VA_ARGS__)
#define UEFI_TEST_ASSERT(...)      __OVERRIDE_MACRO2(__VA_ARGS__, __UEFI_TEST_ASSERT_2, __UEFI_TEST_ASSERT_1)(__VA_ARGS__)
#define UEFI_ASSERT_EXECUTION(...) __OVERRIDE_MACRO4(__VA_ARGS__, __UEFI_ASSERT_EXECUTION_4, __UEFI_ASSERT_EXECUTION_3, __UEFI_ASSERT_EXECUTION_2, __UEFI_ASSERT_EXECUTION_1)(__VA_ARGS__)



#endif // OS_SHARED_UEFIBASE_SRC_BITS64_UEFI_UEFIASSERT_H
