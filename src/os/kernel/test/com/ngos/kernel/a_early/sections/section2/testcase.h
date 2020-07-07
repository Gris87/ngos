#ifndef KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_TESTCASE_H
#define KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_TESTCASE_H



#include <buildconfig.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/brk/brk.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/cpu/cpumask.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/e820/e820.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/hypervisor/kvm/kvm.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/ioremap/ioremap.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/ioremap/utils.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/memorymanager/memoryblockregion.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/memorymanager/memorymanager.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/pagetable/addressconversion.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/pagetable/dynamicpagetable.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/other/task/utils.h>
#include <com/ngos/kernel/a_early/sections/section2/com/ngos/kernel/types.h>
#include <com/ngos/kernel/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



NgosStatus startTestSection2()
{
    EARLY_LT((""));



    INIT_TEST_SECTION();

    CALL_TEST_CASES(section2, com_ngos_kernel_other_brk_brk);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_cpu_cpumask);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_e820_e820);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_hypervisor_kvm_kvm);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_ioremap_ioremap);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_ioremap_utils);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_memorymanager_memoryblockregion);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_memorymanager_memorymanager);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_pagetable_addressconversion);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_pagetable_dynamicpagetable);
    CALL_TEST_CASES(section2, com_ngos_kernel_other_task_utils);
    CALL_TEST_CASES(section2, com_ngos_kernel_types);

    SUMMARY_TEST_SECTION();
}



#endif



#endif // KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_TESTCASE_H
