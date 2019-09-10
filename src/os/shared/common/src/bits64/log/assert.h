#ifndef OS_SHARED_COMMON_SRC_BITS64_LOG_ASSERT_H
#define OS_SHARED_COMMON_SRC_BITS64_LOG_ASSERT_H



#if defined(UEFI_APPLICATION)                                                   // Defined in Makefile
#include <uefibase/src/bits64/uefi/uefiassert.h>
#elif defined(BUILD_TARGET_INSTALLER)                                           // Defined in Makefile
#include <common/src/bits64/early/earlyassert.h>
#elif defined(BUILD_TARGET_KERNEL)                                              // Defined in Makefile
#include <common/src/bits64/early/earlyassert.h>
#else
#include <buildconfig.h>
#include <common/src/bits64/serial/serial.h>
#include <macro/utils.h>
#include <ngos/status.h>
#endif



// Ignore CppAlignmentVerifier [BEGIN]
#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
#if defined(UEFI_APPLICATION)                                                   // Defined in Makefile
#define __COMMON_PRINT_ASSERT(message) __UEFI_PRINT_ASSERT(message)     // TEST: NO
#elif defined(BUILD_TARGET_INSTALLER)                                           // Defined in Makefile
#define __COMMON_PRINT_ASSERT(message) __EARLY_PRINT_ASSERT(message)    // TEST: NO
#elif defined(BUILD_TARGET_KERNEL)                                              // Defined in Makefile
#define __COMMON_PRINT_ASSERT(message) __EARLY_PRINT_ASSERT(message)    // TEST: NO
#else
#define __COMMON_PRINT_ASSERT(message) \
    Serial::printf message;
#endif



#define __COMMON_ASSERT_2(condition, message) \
    if (!(condition)) \
    { \
        __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | %s", __FILE__, __LINE__, message)); \
        return; \
    }

#define __COMMON_ASSERT_3(condition, message, returnValue) \
    if (!(condition)) \
    { \
        __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | %s", __FILE__, __LINE__, message)); \
        return returnValue; \
    }
#else
#define __COMMON_ASSERT_2(condition, message)
#define __COMMON_ASSERT_3(condition, message, returnValue)
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES
#define __COMMON_TEST_ASSERT_1(condition) \
    if (!(condition)) \
    { \
        __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | Condition \"%s\" failed", __FILE__, __LINE__, #condition)); \
        return; \
    }

#define __COMMON_TEST_ASSERT_2(condition, returnValue) \
    if (!(condition)) \
    { \
        __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | Condition \"%s\" failed", __FILE__, __LINE__, #condition)); \
        return returnValue; \
    }
#else
#define __COMMON_TEST_ASSERT_1(condition)
#define __COMMON_TEST_ASSERT_2(condition, returnValue)
#endif



#if NGOS_BUILD_RELEASE == OPTION_NO && NGOS_BUILD_TEST_MODE == OPTION_YES
#define __COMMON_ASSERT_EXECUTION_1(command) \
    { \
        NgosStatus __exec_result = command; \
        \
        if (__exec_result != NgosStatus::OK) \
        { \
            __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code 0x%016lX (%s)", __FILE__, __LINE__, #command, __exec_result, ngosStatusToString(__exec_result))); \
            return; \
        } \
    }

#define __COMMON_ASSERT_EXECUTION_2(command, returnValue) \
    { \
        NgosStatus __exec_result = command; \
        \
        if (__exec_result != NgosStatus::OK) \
        { \
            __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code 0x%016lX (%s)", __FILE__, __LINE__, #command, __exec_result, ngosStatusToString(__exec_result))); \
            return returnValue; \
        } \
    }

#define __COMMON_ASSERT_EXECUTION_3(command, resultType, expectedValue) \
    { \
        resultType __exec_result = command; \
        \
        if (__exec_result != expectedValue) \
        { \
            __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed", __FILE__, __LINE__, #command)); \
            return; \
        } \
    }

#define __COMMON_ASSERT_EXECUTION_4(command, resultType, expectedValue, returnValue) \
    { \
        resultType __exec_result = command; \
        \
        if (__exec_result != expectedValue) \
        { \
            __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed", __FILE__, __LINE__, #command)); \
            return returnValue; \
        } \
    }
#else
#define __COMMON_ASSERT_EXECUTION_1(command)                                         command;
#define __COMMON_ASSERT_EXECUTION_2(command, returnValue)                            command;
#define __COMMON_ASSERT_EXECUTION_3(command, resultType, expectedValue)              command;
#define __COMMON_ASSERT_EXECUTION_4(command, resultType, expectedValue, returnValue) command;
#endif
// Ignore CppAlignmentVerifier [END]



#define COMMON_ASSERT(...)           __OVERRIDE_MACRO3(__VA_ARGS__, __COMMON_ASSERT_3, __COMMON_ASSERT_2)(__VA_ARGS__)
#define COMMON_TEST_ASSERT(...)      __OVERRIDE_MACRO2(__VA_ARGS__, __COMMON_TEST_ASSERT_2, __COMMON_TEST_ASSERT_1)(__VA_ARGS__)
#define COMMON_ASSERT_EXECUTION(...) __OVERRIDE_MACRO4(__VA_ARGS__, __COMMON_ASSERT_EXECUTION_4, __COMMON_ASSERT_EXECUTION_3, __COMMON_ASSERT_EXECUTION_2, __COMMON_ASSERT_EXECUTION_1)(__VA_ARGS__)



#endif // OS_SHARED_COMMON_SRC_BITS64_LOG_ASSERT_H
