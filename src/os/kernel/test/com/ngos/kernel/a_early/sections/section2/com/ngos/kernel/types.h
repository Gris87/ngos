#ifndef KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_TYPES_H
#define KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_TYPES_H



#include <buildconfig.h>
#include <com/ngos/kernel/a_early/testengine.h>
#include <com/ngos/kernel/other/brk/brk.h>
#include <com/ngos/kernel/other/cpu/cpumask.h>
#include <com/ngos/kernel/other/cpu/hotplug/cpuhotplug.h>
#include <com/ngos/kernel/other/cpu/hotplug/cpuhotplugstate.h>
#include <com/ngos/kernel/other/cpu/hotplug/cpuhotplugstep.h>
#include <com/ngos/kernel/other/cpu/percpu.h>
#include <com/ngos/kernel/other/e820/e820.h>
#include <com/ngos/kernel/other/e820/e820table.h>
#include <com/ngos/kernel/other/hypervisor/hypervisor.h>
#include <com/ngos/kernel/other/hypervisor/hypervisortype.h>
#include <com/ngos/kernel/other/hypervisor/kvm/clock/kvmclock.h>
#include <com/ngos/kernel/other/hypervisor/kvm/kvm.h>
#include <com/ngos/kernel/other/hypervisor/kvm/kvmfeature.h>
#include <com/ngos/kernel/other/hypervisor/kvm/kvmfeaturetypeflags.h>
#include <com/ngos/kernel/other/ioremap/fixmap.h>
#include <com/ngos/kernel/other/ioremap/ioremap.h>
#include <com/ngos/kernel/other/irq/irqstack.h>
#include <com/ngos/kernel/other/memorymanager/memoryblock.h>
#include <com/ngos/kernel/other/memorymanager/memoryblockregion.h>
#include <com/ngos/kernel/other/memorymanager/memoryblocktype.h>
#include <com/ngos/kernel/other/memorymanager/memorymanager.h>
#include <com/ngos/kernel/other/pagetable/addressconversion.h>
#include <com/ngos/kernel/other/task/task.h>
#include <com/ngos/kernel/other/task/threadinfo.h>
#include <com/ngos/kernel/other/uefi/uefi.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, com_ngos_kernel_types);
{
    TEST_CASE("Size of structures");
    {
        TEST_ASSERT_EQUALS(sizeof(AddressConversion),     1);
        TEST_ASSERT_EQUALS(sizeof(BRK),                   1);
        TEST_ASSERT_EQUALS(sizeof(CpuHotplug),            1);
        TEST_ASSERT_EQUALS(sizeof(CpuHotplugState),       1);
        TEST_ASSERT_EQUALS(sizeof(CpuHotplugStep),        32);
        TEST_ASSERT_EQUALS(sizeof(CpuMask),               8192);
        TEST_ASSERT_EQUALS(sizeof(E820),                  1);
        TEST_ASSERT_EQUALS(sizeof(E820Table),             3080);
        TEST_ASSERT_EQUALS(sizeof(FixMap),                1);
        TEST_ASSERT_EQUALS(sizeof(Hypervisor),            1);
        TEST_ASSERT_EQUALS(sizeof(HypervisorType),        1);
        TEST_ASSERT_EQUALS(sizeof(IORemap),               1);
        TEST_ASSERT_EQUALS(sizeof(IrqStack),              16384);
        TEST_ASSERT_EQUALS(sizeof(KVM),                   1);
        TEST_ASSERT_EQUALS(sizeof(KvmClock),              1);
        TEST_ASSERT_EQUALS(sizeof(KvmFeature),            1);
        TEST_ASSERT_EQUALS(sizeof(KvmFeatureTypeFlag),    4);
        TEST_ASSERT_EQUALS(sizeof(MemoryBlock),           64);
        TEST_ASSERT_EQUALS(sizeof(MemoryBlockRegion),     24);
        TEST_ASSERT_EQUALS(sizeof(MemoryBlockRegionFlag), 1);
        TEST_ASSERT_EQUALS(sizeof(MemoryBlockType),       32);
        TEST_ASSERT_EQUALS(sizeof(MemoryManager),         1);
        TEST_ASSERT_EQUALS(sizeof(PERCPU),                1);
        TEST_ASSERT_EQUALS(sizeof(Task),                  24);
        TEST_ASSERT_EQUALS(sizeof(TaskState),             1);
        TEST_ASSERT_EQUALS(sizeof(ThreadInfo),            4);
        TEST_ASSERT_EQUALS(sizeof(ThreadInfoFlag),        4);
        TEST_ASSERT_EQUALS(sizeof(UEFI),                  1);
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_TYPES_H
