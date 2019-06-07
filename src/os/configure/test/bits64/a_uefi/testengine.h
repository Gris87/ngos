#ifndef CONFIGURE_TEST_BITS64_A_UEFI_TESTENGINE_H
#define CONFIGURE_TEST_BITS64_A_UEFI_TESTENGINE_H



#include <buildconfig.h>
#include <ngos/utils.h>

#include "src/bits64/a_uefi/uefi/uefilog.h"
#include "test/bits64/a_uefi/testresults.h"



#if NGOS_BUILD_TEST_MODE == OPTION_YES



#define TEST_CASES(section, name) \
        void __testcases__##section##__##name(TestResults *__results) \
        { \
            UEFI_LT((" | __results = 0x%p", __results));

#define TEST_CASES_END() \
        }



// Ignore CppAlignmentVerifier [BEGIN]
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE
#define TEST_CASE(name) \
        do \
        { \
            if (Console::canPrint()) \
            { \
                Serial::print("TRACE:     TEST_CASE(\""); \
                Serial::print(name); \
                Serial::println("\")"); \
                \
                Console::print("TRACE:     TEST_CASE(\""); \
                Console::print(name); \
                Console::println("\")"); \
            } \
            else \
            if (UEFI::canPrint()) \
            { \
                UEFI::print("TRACE:     TEST_CASE(\""); \
                UEFI::print(name); \
                UEFI::println("\")"); \
            } \
            else \
            { \
                Serial::print("TRACE:     TEST_CASE(\""); \
                Serial::print(name); \
                Serial::println("\")"); \
            }
#else
#define TEST_CASE(name) \
        do \
        {
#endif

#define TEST_CASE_END() \
            __results->testPassed(); \
            \
            break; \
        } while(true);



#define INIT_TEST_SECTION() \
    TestResults *__results; \
    \
    asm volatile( \
        "pushq   %%rbp"                 "\n\t" \
        "movq    %%rsp, %%rbp"          "\n\t" \
        "andq    $-0x40, %%rsp"         "\n\t" \
        "pushq   %%rbp"                 "\n\t" \
        "subq    $0x28, %%rsp"          "\n\t" \
        "movq    %%rsp, %0"             "\n\t" \
        "movq    %0, %%rdi"             "\n\t" \
        "call    _ZN11TestResultsC1Ev"  "\n\t" \
            : \
                "=r" (__results) \
    );



#define CALL_TEST_CASES(section, name) __testcases__##section##__##name(__results);



#define SUMMARY_TEST_SECTION() \
    NgosStatus __res = __results->summary(); \
    \
    asm volatile( \
        "movq    %0, %%rdx"     "\n\t" \
        "addq    $0x28, %%rsp"  "\n\t" \
        "popq    %%rbp"         "\n\t" \
        "movq    %%rbp, %%rsp"  "\n\t" \
        "popq    %%rbp"         "\n\t" \
        "movq    %%rdx, %0"     "\n\t" \
            :   \
            : "r" (__results) \
    ); \
    \
    return __res;
// Ignore CppAlignmentVerifier [END]



#define __TEST_OVERRIDE_MACRO2(_1, _2, NAME, ...)     NAME
#define __TEST_OVERRIDE_MACRO3(_1, _2, _3, NAME, ...) NAME



#define TEST_FAILED(description) \
        __results->testFailed(__FILE__, __LINE__, description); \
        break;



#define __TEST_ASSERT1(condition) \
        if (!(condition)) \
        { \
            TEST_FAILED("Condition \"" #condition "\" failed"); \
        }

#define __TEST_ASSERT2(condition, description) \
        if (!(condition)) \
        { \
            TEST_FAILED(description); \
        }

#define TEST_ASSERT(...) __TEST_OVERRIDE_MACRO2(__VA_ARGS__, __TEST_ASSERT2, __TEST_ASSERT1)(__VA_ARGS__)



#define __TEST_ASSERT_EQUALS2(value1, value2)              TEST_ASSERT((value1) == (value2));
#define __TEST_ASSERT_EQUALS3(value1, value2, description) TEST_ASSERT((value1) == (value2), description);

#define TEST_ASSERT_EQUALS(...) __TEST_OVERRIDE_MACRO3(__VA_ARGS__, __TEST_ASSERT_EQUALS3, __TEST_ASSERT_EQUALS2)(__VA_ARGS__)



#define __TEST_ASSERT_NOT_EQUALS2(value1, value2)              TEST_ASSERT((value1) != (value2));
#define __TEST_ASSERT_NOT_EQUALS3(value1, value2, description) TEST_ASSERT((value1) != (value2), description);

#define TEST_ASSERT_NOT_EQUALS(...) __TEST_OVERRIDE_MACRO3(__VA_ARGS__, __TEST_ASSERT_NOT_EQUALS3, __TEST_ASSERT_NOT_EQUALS2)(__VA_ARGS__)



#define __TEST_ASSERT_FLOAT_EQUALS2(value1, value2)              TEST_ASSERT(ABS((value1) - (value2)) < 0.001);
#define __TEST_ASSERT_FLOAT_EQUALS3(value1, value2, description) TEST_ASSERT(ABS((value1) - (value2)) < 0.001, description);

#define TEST_ASSERT_FLOAT_EQUALS(...) __TEST_OVERRIDE_MACRO3(__VA_ARGS__, __TEST_ASSERT_FLOAT_EQUALS3, __TEST_ASSERT_FLOAT_EQUALS2)(__VA_ARGS__)



#define __TEST_ASSERT_FLOAT_NOT_EQUALS2(value1, value2)              TEST_ASSERT(ABS((value1) - (value2)) >= 0.001);
#define __TEST_ASSERT_FLOAT_NOT_EQUALS3(value1, value2, description) TEST_ASSERT(ABS((value1) - (value2)) >= 0.001, description);

#define TEST_ASSERT_FLOAT_NOT_EQUALS(...) __TEST_OVERRIDE_MACRO3(__VA_ARGS__, __TEST_ASSERT_FLOAT_NOT_EQUALS3, __TEST_ASSERT_FLOAT_NOT_EQUALS2)(__VA_ARGS__)



#endif



#endif // CONFIGURE_TEST_BITS64_A_UEFI_TESTENGINE_H
