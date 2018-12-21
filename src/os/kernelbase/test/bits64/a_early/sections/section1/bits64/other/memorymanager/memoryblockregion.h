#ifndef OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
#define OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H



#include <buildconfig.h>
#include <src/bits64/other/memorymanager/memoryblockregion.h>
#include <test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section1, bits64_other_memorymanager_memoryblockregion);
{
    TEST_CASE("aaaa()");
    {

    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_BITS64_OTHER_MEMORYMANAGER_MEMORYBLOCKREGION_H
