#ifndef OS_SHARED_UEFIBASE_TEST_BITS64_TESTENGINE_H
#define OS_SHARED_UEFIBASE_TEST_BITS64_TESTENGINE_H



#include <buildconfig.h>
#include <macro/utils.h>
#include <ngos/utils.h>
#include <uefibase/src/bits64/uefi/uefilog.h>
#include <uefibase/test/bits64/testresults.h>



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
            if (GraphicalConsole::canPrint()) \
            { \
                GraphicalConsole::init(); \
                \
                Serial::print("TRACE:     TEST_CASE(\""); \
                GraphicalConsole::print("TRACE:     TEST_CASE(\""); \
                \
                Serial::print(name); \
                GraphicalConsole::print(name); \
                \
                Serial::println("\")"); \
                GraphicalConsole::println("\")"); \
            } \
            else \
            if (Console::canPrint()) \
            { \
                Serial::print("TRACE:     TEST_CASE(\""); \
                Console::print("TRACE:     TEST_CASE(\""); \
                \
                Serial::print(name); \
                Console::print(name); \
                \
                Serial::println("\")"); \
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
        "pushq   %%rbp"                 "\n\t"  /* pushq   %rbp                     # Store RBP to stack                                               */ \
        "movq    %%rsp, %%rbp"          "\n\t"  /* movq    %rsp, %rbp               # Store RSP value in RBP                                           */ \
        "andq    $-0x40, %%rsp"         "\n\t"  /* andq    $-0x40, %rsp             # Make RSP aligned                                                 */ \
        "pushq   %%rbp"                 "\n\t"  /* pushq   %rbp                     # Store RBP to stack                                               */ \
        "subq    $0x28, %%rsp"          "\n\t"  /* subq    $0x28, %rsp              # Allocate space on stack. The value selected to keep RSP aligned  */ \
        "movq    %%rsp, %0"             "\n\t"  /* movq    %rsp, %rbp               # Make __results variable to point on RSP. %RBP == __results       */ \
        "movq    %0, %%rdi"             "\n\t"  /* movq    %rbp, %rdi               # Provide __results variable as RDI register                       */ \
        "call    _ZN11TestResultsC1Ev"  "\n\t"  /* call    _ZN11TestResultsC1Ev     # Call TestResults::TestResults() to initialize __results variable */ \
            :                                   /* Output parameters */ \
                "=r" (__results)                /* 'r' - any general register, '=' - write only */ \
    );



#define CALL_TEST_CASES(section, name) __testcases__##section##__##name(__results);



#define SUMMARY_TEST_SECTION() \
    NgosStatus __res = __results->summary(); \
    \
    asm volatile( \
        "addq    $0x28, %rsp"   "\n\t"  /* subq    $0x28, %rsp  # Release space on stack. The value selected to keep RSP aligned */ \
        "popq    %rbp"          "\n\t"  /* popq    %rbp         # Restore RBP from stack                                         */ \
        "movq    %rbp, %rsp"    "\n\t"  /* movq    %rbp, %rsp   # Restore RSP from RBP                                           */ \
        "popq    %rbp"          "\n\t"  /* popq    %rbp         # Restore RBP from stack                                         */ \
    ); \
    \
    return __res;
// Ignore CppAlignmentVerifier [END]



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

#define TEST_ASSERT(...) __OVERRIDE_MACRO2(__VA_ARGS__, __TEST_ASSERT2, __TEST_ASSERT1)(__VA_ARGS__)



#define __TEST_ASSERT_EQUALS2(value1, value2)              TEST_ASSERT((value1) == (value2));
#define __TEST_ASSERT_EQUALS3(value1, value2, description) TEST_ASSERT((value1) == (value2), description);

#define TEST_ASSERT_EQUALS(...) __OVERRIDE_MACRO3(__VA_ARGS__, __TEST_ASSERT_EQUALS3, __TEST_ASSERT_EQUALS2)(__VA_ARGS__)



#define __TEST_ASSERT_NOT_EQUALS2(value1, value2)              TEST_ASSERT((value1) != (value2));
#define __TEST_ASSERT_NOT_EQUALS3(value1, value2, description) TEST_ASSERT((value1) != (value2), description);

#define TEST_ASSERT_NOT_EQUALS(...) __OVERRIDE_MACRO3(__VA_ARGS__, __TEST_ASSERT_NOT_EQUALS3, __TEST_ASSERT_NOT_EQUALS2)(__VA_ARGS__)



#define __TEST_ASSERT_FLOAT_EQUALS2(value1, value2)              TEST_ASSERT(ABS((value1) - (value2)) < 0.001);
#define __TEST_ASSERT_FLOAT_EQUALS3(value1, value2, description) TEST_ASSERT(ABS((value1) - (value2)) < 0.001, description);

#define TEST_ASSERT_FLOAT_EQUALS(...) __OVERRIDE_MACRO3(__VA_ARGS__, __TEST_ASSERT_FLOAT_EQUALS3, __TEST_ASSERT_FLOAT_EQUALS2)(__VA_ARGS__)



#define __TEST_ASSERT_FLOAT_NOT_EQUALS2(value1, value2)              TEST_ASSERT(ABS((value1) - (value2)) >= 0.001);
#define __TEST_ASSERT_FLOAT_NOT_EQUALS3(value1, value2, description) TEST_ASSERT(ABS((value1) - (value2)) >= 0.001, description);

#define TEST_ASSERT_FLOAT_NOT_EQUALS(...) __OVERRIDE_MACRO3(__VA_ARGS__, __TEST_ASSERT_FLOAT_NOT_EQUALS3, __TEST_ASSERT_FLOAT_NOT_EQUALS2)(__VA_ARGS__)



#endif



#endif // OS_SHARED_UEFIBASE_TEST_BITS64_TESTENGINE_H
