#ifndef OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_HYPERVISOR_KVM_H
#define OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_HYPERVISOR_KVM_H



#include <buildconfig.h>
#include <kernelbase/src/bits64/other/hypervisor/kvm/kvm.h>
#include <kernelbase/test/bits64/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, bits64_other_hypervisor_kvm_kvm);
{
    TEST_CASE("hasFeature()");
    {
        TEST_ASSERT_EQUALS(KVM::sFeatures, 0);

        KVM::sFeatures = 0x01000A93;

        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE),            true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::NOP_IO_DELAY),           true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::MMU_OP),                 false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE2),           false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::ASYNC_PF),               true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::STEAL_TIME),             false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::PV_EOI),                 false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::PV_UNHALT),              true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::PV_TLB_FLUSH),           true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::ASYNC_PF_VMEXIT),        false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::PV_SEND_IPI),            true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE_STABLE_BIT), true);

        KVM::sFeatures = 0;
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // OS_SHARED_KERNELBASE_TEST_BITS64_A_EARLY_SECTIONS_SECTION2_BITS64_OTHER_HYPERVISOR_KVM_H
