#ifndef COM_NGOS_SHARED_COMMON_LOG_ASSERT_H
#define COM_NGOS_SHARED_COMMON_LOG_ASSERT_H



#if defined(UEFI_APPLICATION)                                                   // Defined in pro file
#include <com/ngos/shared/uefibase/uefi/uefiassert.h>
#elif defined(BUILD_TARGET_KERNEL)                                              // Defined in pro file
#include <com/ngos/shared/common/early/earlyassert.h>
#else
#include <buildconfig.h>
#include <com/ngos/shared/common/serial/serial.h>
#include <com/ngos/shared/common/macro/utils.h>
#include <com/ngos/shared/common/ngos/status.h>
#endif



// Ignore CppAlignmentVerifier [BEGIN]
#if NGOS_BUILD_RELEASE == OPTION_NO // Ignore CppReleaseUsageVerifier
#if defined(UEFI_APPLICATION)                                           // Defined in pro file
#define __COMMON_PRINT_ASSERT(message) __UEFI_PRINT_ASSERT(message)     // TEST: NO
#elif defined(BUILD_TARGET_KERNEL)                                      // Defined in pro file
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
            __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code %s", __FILE__, __LINE__, #command, enumToFullString(__exec_result))); \
            return; \
        } \
    }

#define __COMMON_ASSERT_EXECUTION_2(command, returnValue) \
    { \
        NgosStatus __exec_result = command; \
        \
        if (__exec_result != NgosStatus::OK) \
        { \
            __COMMON_PRINT_ASSERT(("ASSERT:    %s:%u | Execution \"%s\" failed with error code %s", __FILE__, __LINE__, #command, enumToFullString(__exec_result))); \
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



#endif // COM_NGOS_SHARED_COMMON_LOG_ASSERT_H
