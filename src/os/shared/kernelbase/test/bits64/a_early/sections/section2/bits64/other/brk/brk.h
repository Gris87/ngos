#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_BRK_BRK_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_BRK_BRK_H



#include <buildconfig.h>
#include <kernelbase/src/bits64/other/brk/brk.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



extern void *_brk_begin; // _brk_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier



TEST_CASES(section2, bits64_other_brk_brk);
{
    TEST_CASE("init()");
    {
        TEST_ASSERT_EQUALS(BRK::init(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(BRK::sBegin, (u64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sEnd,   (u64)&_brk_begin);
    }
    TEST_CASE_END();



    TEST_CASE("allocate()");
    {
        u8 *temp;

        TEST_ASSERT_EQUALS(BRK::allocate(1, 1, &temp), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)temp,                  (u64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sBegin,                (u64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sEnd,                  (u64)&_brk_begin + 1);

        TEST_ASSERT_EQUALS(BRK::allocate(100, 1, &temp), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)temp,                    (u64)&_brk_begin + 1);
        TEST_ASSERT_EQUALS(BRK::sBegin,                  (u64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sEnd,                    (u64)&_brk_begin + 101);

        TEST_ASSERT_EQUALS(BRK::allocate(50, 64, &temp), NgosStatus::OK);
        TEST_ASSERT_EQUALS((u64)temp,                    ROUND_UP((u64)&_brk_begin + 101, 64));
        TEST_ASSERT_EQUALS(BRK::sBegin,                  (u64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sEnd,                    ROUND_UP((u64)&_brk_begin + 101, 64) + 50);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_BRK_BRK_H
