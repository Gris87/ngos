#ifndef OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
#define OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H



#include <buildconfig.h>
#include <src/bits64/other/memorymanager/memoryblockregion.h>
#include <test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_other_memorymanager_memoryblockregion);
{
    TEST_CASE("end()");
    {
        MemoryBlockRegion temp;

        temp.start = 1000;
        temp.size  = 2000;

        TEST_ASSERT_EQUALS(temp.end(), 3000);

        temp.size  = 3000;

        TEST_ASSERT_EQUALS(temp.end(), 4000);

        temp.start  = 4000;

        TEST_ASSERT_EQUALS(temp.end(), 7000);

        temp.size  = 1000;

        TEST_ASSERT_EQUALS(temp.end(), 5000);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
