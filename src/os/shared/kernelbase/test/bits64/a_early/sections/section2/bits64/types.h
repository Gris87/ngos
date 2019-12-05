#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_TYPES_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_TYPES_H



#include <buildconfig.h>
#include <kernelbase/src/bits64/other/brk/brk.h>
#include <kernelbase/src/bits64/other/cpu/cpumask.h>
#include <kernelbase/src/bits64/other/cpu/hotplug/cpuhotplug.h>
#include <kernelbase/src/bits64/other/cpu/hotplug/cpuhotplugstate.h>
#include <kernelbase/src/bits64/other/cpu/hotplug/cpuhotplugstep.h>
#include <kernelbase/src/bits64/other/cpu/percpu.h>
#include <kernelbase/src/bits64/other/e820/e820.h>
#include <kernelbase/src/bits64/other/e820/e820table.h>
#include <kernelbase/src/bits64/other/hypervisor/hypervisor.h>
#include <kernelbase/src/bits64/other/hypervisor/hypervisortype.h>
#include <kernelbase/src/bits64/other/hypervisor/kvm/clock/kvmclock.h>
#include <kernelbase/src/bits64/other/hypervisor/kvm/kvm.h>
#include <kernelbase/src/bits64/other/hypervisor/kvm/kvmfeature.h>
#include <kernelbase/src/bits64/other/hypervisor/kvm/kvmfeaturetypeflags.h>
#include <kernelbase/src/bits64/other/ioremap/fixmap.h>
#include <kernelbase/src/bits64/other/ioremap/ioremap.h>
#include <kernelbase/src/bits64/other/irq/irqstack.h>
#include <kernelbase/src/bits64/other/memorymanager/memoryblock.h>
#include <kernelbase/src/bits64/other/memorymanager/memoryblockregion.h>
#include <kernelbase/src/bits64/other/memorymanager/memoryblocktype.h>
#include <kernelbase/src/bits64/other/memorymanager/memorymanager.h>
#include <kernelbase/src/bits64/other/pagetable/addressconversion.h>
#include <kernelbase/src/bits64/other/task/task.h>
#include <kernelbase/src/bits64/other/task/threadinfo.h>
#include <kernelbase/src/bits64/other/uefi/uefi.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, bits64_types);
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



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_TYPES_H
