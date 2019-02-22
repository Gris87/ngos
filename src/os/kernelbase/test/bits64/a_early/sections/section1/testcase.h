#ifndef OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_TESTCASE_H
#define OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <test/bits64/a_early/sections/section1/bits64/other/cpu/cpumask.h>
#include <test/bits64/a_early/sections/section1/bits64/other/ioremap/utils.h>
#include <test/bits64/a_early/sections/section1/bits64/other/memorymanager/memoryblockregion.h>
#include <test/bits64/a_early/sections/section1/bits64/other/memorymanager/memorymanager.h>
#include <test/bits64/a_early/sections/section1/bits64/other/pagetable/addressconversion.h>
#include <test/bits64/a_early/sections/section1/bits64/other/pagetable/dynamicpagetable.h>
#include <test/bits64/a_early/sections/section1/bits64/other/tasks/utils.h>
#include <test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    EARLY_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, bits64_other_cpu_cpumask);
    CALL_TEST_CASES(section1, bits64_other_ioremap_utils);
    CALL_TEST_CASES(section1, bits64_other_memorymanager_memoryblockregion);
    CALL_TEST_CASES(section1, bits64_other_memorymanager_memorymanager);
    CALL_TEST_CASES(section1, bits64_other_pagetable_addressconversion);
    CALL_TEST_CASES(section1, bits64_other_pagetable_dynamicpagetable);
    CALL_TEST_CASES(section1, bits64_other_tasks_utils);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // OS_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_TESTCASE_H
