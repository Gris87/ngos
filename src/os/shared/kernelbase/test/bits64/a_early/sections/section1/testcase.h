#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_TESTCASE_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_TESTCASE_H



#include <buildconfig.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/cpu/cpumask.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/e820/e820.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/ioremap/ioremap.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/ioremap/utils.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/memorymanager/memoryblockregion.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/memorymanager/memorymanager.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/pagetable/addressconversion.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/pagetable/dynamicpagetable.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/task/utils.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/other/uefi/uefi.h>
#include <kernelbase/test/bits64/a_early/sections/section1/bits64/types.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection1()
{
    EARLY_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section1, bits64_other_cpu_cpumask);
    CALL_TEST_CASES(section1, bits64_other_e820_e820);
    CALL_TEST_CASES(section1, bits64_other_ioremap_ioremap);
    CALL_TEST_CASES(section1, bits64_other_ioremap_utils);
    CALL_TEST_CASES(section1, bits64_other_memorymanager_memoryblockregion);
    CALL_TEST_CASES(section1, bits64_other_memorymanager_memorymanager);
    CALL_TEST_CASES(section1, bits64_other_pagetable_addressconversion);
    CALL_TEST_CASES(section1, bits64_other_pagetable_dynamicpagetable);
    CALL_TEST_CASES(section1, bits64_other_task_utils);
    CALL_TEST_CASES(section1, bits64_other_uefi_uefi);
    CALL_TEST_CASES(section1, bits64_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION1_TESTCASE_H
