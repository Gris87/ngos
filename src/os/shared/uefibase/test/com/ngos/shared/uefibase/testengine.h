#ifndef COM_NGOS_SHARED_UEFIBASE_TESTENGINE_H
#define COM_NGOS_SHARED_UEFIBASE_TESTENGINE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/macro/utils.h>
#include <com/ngos/shared/common/ngos/utils.h>
#include <com/ngos/shared/uefibase/testresults.h>
#include <com/ngos/shared/uefibase/uefi/uefilog.h>
#include <com/ngos/shared/uefibase/uefi/uefilogfile.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



#define TEST_CASES(section, name) \
        void __testcases__##section##__##name(TestResults &__results) \
        { \
            UEFI_LT((" | __results = ..."));

#define TEST_CASES_END() \
        }



// Ignore CppAlignmentVerifier [BEGIN]
#if NGOS_BUILD_UEFI_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE || NGOS_BUILD_UEFI_LOG_LEVEL >= OPTION_LOG_LEVEL_TRACE
#if NGOS_BUILD_LOG_TO_UEFI_FILE == OPTION_YES
#define __UEFI_LOG_FILE_TEST_TRACE(name) \
    if (UefiLogFile::canPrint()) \
    { \
        UefiLogFile::init(); \
        \
        UefiLogFile::print("TRACE:     TEST_CASE(\""); \
        UefiLogFile::print(name); \
        UefiLogFile::println("\")"); \
    }
#else
#define __UEFI_LOG_FILE_TEST_TRACE(name)
#endif



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
            } \
            \
            __UEFI_LOG_FILE_TEST_TRACE(name);
#else
#define TEST_CASE(name) \
        do \
        {
#endif

#define TEST_CASE_END() \
            __results.testPassed(); \
            \
            break; \
        } while(true);
// Ignore CppAlignmentVerifier [END]



#define INIT_TEST_SECTION()            TestResults __results;
#define CALL_TEST_CASES(section, name) __testcases__##section##__##name(__results);
#define SUMMARY_TEST_SECTION()         return __results.summary();



#define TEST_FAILED(description) \
        __results.testFailed(__FILE__, __LINE__, description); \
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



#endif // COM_NGOS_SHARED_UEFIBASE_TESTENGINE_H
