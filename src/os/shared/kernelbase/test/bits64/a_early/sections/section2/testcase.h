#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_TESTCASE_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_TESTCASE_H



#include <buildconfig.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/brk/brk.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/cpu/cpumask.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/dmi/dmi.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/e820/e820.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/hypervisor/kvm/kvm.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/ioremap/ioremap.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/ioremap/utils.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/memorymanager/memoryblockregion.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/memorymanager/memorymanager.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/pagetable/addressconversion.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/pagetable/dynamicpagetable.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/other/task/utils.h>
#include <kernelbase/test/bits64/a_early/sections/section2/bits64/types.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection2()
{
    EARLY_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section2, bits64_other_brk_brk);
    CALL_TEST_CASES(section2, bits64_other_cpu_cpumask);
    CALL_TEST_CASES(section2, bits64_other_dmi_dmi);
    CALL_TEST_CASES(section2, bits64_other_e820_e820);
    CALL_TEST_CASES(section2, bits64_other_hypervisor_kvm_kvm);
    CALL_TEST_CASES(section2, bits64_other_ioremap_ioremap);
    CALL_TEST_CASES(section2, bits64_other_ioremap_utils);
    CALL_TEST_CASES(section2, bits64_other_memorymanager_memoryblockregion);
    CALL_TEST_CASES(section2, bits64_other_memorymanager_memorymanager);
    CALL_TEST_CASES(section2, bits64_other_pagetable_addressconversion);
    CALL_TEST_CASES(section2, bits64_other_pagetable_dynamicpagetable);
    CALL_TEST_CASES(section2, bits64_other_task_utils);
    CALL_TEST_CASES(section2, bits64_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_TESTCASE_H
