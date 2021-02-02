#ifndef COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_BRK_BRK_H
#define COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_BRK_BRK_H



#include <buildconfig.h>
#include <com/ngos/kernel/a_early/testengine.h>
#include <com/ngos/kernel/other/brk/brk.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



extern void *_brk_begin; // _brk_begin declared in linker.ld file // Ignore CppEqualAlignmentVerifier



TEST_CASES(section2, com_ngos_kernel_other_brk_brk);
{
    TEST_CASE("init()");
    {
        TEST_ASSERT_EQUALS(BRK::init(), NgosStatus::OK);
        TEST_ASSERT_EQUALS(BRK::sBegin, (bad_uint64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sEnd,   (bad_uint64)&_brk_begin);
    }
    TEST_CASE_END();



    TEST_CASE("allocate()");
    {
        bad_uint8 *temp;

        TEST_ASSERT_EQUALS(BRK::allocate(1, 1, &temp), NgosStatus::OK);
        TEST_ASSERT_EQUALS((bad_uint64)temp,                  (bad_uint64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sBegin,                (bad_uint64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sEnd,                  (bad_uint64)&_brk_begin + 1);

        TEST_ASSERT_EQUALS(BRK::allocate(100, 1, &temp), NgosStatus::OK);
        TEST_ASSERT_EQUALS((bad_uint64)temp,                    (bad_uint64)&_brk_begin + 1);
        TEST_ASSERT_EQUALS(BRK::sBegin,                  (bad_uint64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sEnd,                    (bad_uint64)&_brk_begin + 101);

        TEST_ASSERT_EQUALS(BRK::allocate(50, 64, &temp), NgosStatus::OK);
        TEST_ASSERT_EQUALS((bad_uint64)temp,                    ROUND_UP((bad_uint64)&_brk_begin + 101, 64));
        TEST_ASSERT_EQUALS(BRK::sBegin,                  (bad_uint64)&_brk_begin);
        TEST_ASSERT_EQUALS(BRK::sEnd,                    ROUND_UP((bad_uint64)&_brk_begin + 101, 64) + 50);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_BRK_BRK_H
