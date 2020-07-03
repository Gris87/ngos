#ifndef KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
#define KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H



#include <buildconfig.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/pagetable/utils.h>

#include <com/ngos/kernel/other/kerneldefines.h>
#include <com/ngos/kernel/other/pagetable/dynamicpagetable.h>
#include <com/ngos/kernel/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



extern PMD dynamic_pagetable_pages[EARLY_DYNAMIC_PAGE_TABLES][PTRS_PER_PMD];    // dynamic_pagetable_pages declared in main.S file



TEST_CASES(section2, com_ngos_kernel_other_pagetable_dynamicpagetable);
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



#endif // KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
