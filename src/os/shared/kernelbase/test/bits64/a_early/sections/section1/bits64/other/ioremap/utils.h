#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_UTILS_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_UTILS_H



#include <buildconfig.h>
#include <kernelbase/src/bits64/other/ioremap/utils.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_other_ioremap_utils);
{
    TEST_CASE("FIX_ADDRESS_TO_VIRTUAL()");
    {
        TEST_ASSERT_EQUALS(FIX_ADDRESS_TO_VIRTUAL(0),                0xFFFFFFFFFF3FF000);
        TEST_ASSERT_EQUALS(FIX_ADDRESS_TO_VIRTUAL(1),                0xFFFFFFFFFF3FE000);
        TEST_ASSERT_EQUALS(FIX_ADDRESS_TO_VIRTUAL(2),                0xFFFFFFFFFF3FD000);
        TEST_ASSERT_EQUALS(FIX_ADDRESS_TO_VIRTUAL(3),                0xFFFFFFFFFF3FC000);
        TEST_ASSERT_EQUALS(FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN), FIX_ADDRESS_BOTTOM);
        TEST_ASSERT_EQUALS(FIX_ADDRESS_TO_VIRTUAL(FIX_BITMAP_BEGIN), 0xFFFFFFFFFF200000);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_IOREMAP_UTILS_H
