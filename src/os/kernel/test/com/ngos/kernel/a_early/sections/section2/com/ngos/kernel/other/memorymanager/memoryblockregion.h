#ifndef COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
#define COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H



#include <buildconfig.h>
#include <com/ngos/kernel/a_early/testengine.h>
#include <com/ngos/kernel/other/memorymanager/memoryblockregion.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, com_ngos_kernel_other_memorymanager_memoryblockregion);
{
    TEST_CASE("end()");
    {
        MemoryBlockRegion temp;

        temp.start = 1000;
        temp.size  = 2000;

        TEST_ASSERT_EQUALS(temp.end(), 3000);

        temp.size = 3000;

        TEST_ASSERT_EQUALS(temp.end(), 4000);

        temp.start = 4000;

        TEST_ASSERT_EQUALS(temp.end(), 7000);

        temp.size = 1000;

        TEST_ASSERT_EQUALS(temp.end(), 5000);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
