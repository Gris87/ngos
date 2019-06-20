#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_PAGETABLE_DYNAMICPAGETABLE_H



#include <buildconfig.h>
#include <common/src/bits64/memory/memory.h>
#include <kernelbase/src/bits64/other/kerneldefines.h>
#include <kernelbase/src/bits64/other/pagetable/dynamicpagetable.h>
#include <kernelbase/test/bits64/a_early/testengine.h>
#include <pagetable/utils.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



extern PMD dynamic_pagetable_pages[EARLY_DYNAMIC_PAGE_TABLES][PTRS_PER_PMD];    // dynamic_pagetable_pages declared in main.S file



TEST_CASES(section1, bits64_other_pagetable_dynamicpagetable);
{
    TEST_CASE("addDynamicIdentityMap()");
    {
        TEST_ASSERT_EQUALS(memempty(dynamic_pagetable_pages, sizeof(dynamic_pagetable_pages)), true);
        TEST_ASSERT_EQUALS(addDynamicIdentityMap(3000000, 30000000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(memempty(dynamic_pagetable_pages, sizeof(dynamic_pagetable_pages)), false);
    }
    TEST_CASE_END();



    TEST_CASE("clearDynamicIdentityMap()");
    {
        TEST_ASSERT_EQUALS(memempty(dynamic_pagetable_pages, sizeof(dynamic_pagetable_pages)), false);
        TEST_ASSERT_EQUALS(clearDynamicIdentityMap(3000000, 30000000), NgosStatus::OK);
        TEST_ASSERT_EQUALS(memempty(dynamic_pagetable_pages, sizeof(dynamic_pagetable_pages)), true);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
