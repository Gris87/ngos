#ifndef KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVM_H
#define KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVM_H



#include <buildconfig.h>

#include <com/ngos/kernel/other/hypervisor/kvm/kvm.h>
#include <com/ngos/kernel/a_early/testengine.h>



#if NGOS_BUILD_TEST_MODE == OPTION_YES



TEST_CASES(section2, com_ngos_kernel_other_hypervisor_kvm_kvm);
{
    TEST_CASE("setFeature()/clearFeature()/hasFeature()");
    {
        TEST_ASSERT_EQUALS(KVM::sFeatures, 0);

        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE),  false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE2), false);

        TEST_ASSERT_EQUALS(KVM::setFeature(KvmFeature::CLOCKSOURCE),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE),  true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE2), false);
        TEST_ASSERT_EQUALS(KVM::sFeatures,                            0x00000001);

        TEST_ASSERT_EQUALS(KVM::setFeature(KvmFeature::CLOCKSOURCE2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE),  true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE2), true);
        TEST_ASSERT_EQUALS(KVM::sFeatures,                            0x00000009);

        TEST_ASSERT_EQUALS(KVM::clearFeature(KvmFeature::CLOCKSOURCE), NgosStatus::OK);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE),   false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE2),  true);
        TEST_ASSERT_EQUALS(KVM::sFeatures,                             0x00000008);

        TEST_ASSERT_EQUALS(KVM::clearFeature(KvmFeature::CLOCKSOURCE2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE),    false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE2),   false);
        TEST_ASSERT_EQUALS(KVM::sFeatures,                              0);



        KVM::sFeatures = 0x01000A93;

        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE),        true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::NOP_IO_DELAY),       true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::MMU_OP),             false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE2),       false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::ASYNC_PF),           true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::STEAL_TIME),         false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::PV_EOI),             false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::PV_UNHALT),          true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::PV_TLB_FLUSH),       true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::ASYNC_PF_VMEXIT),    false);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::PV_SEND_IPI),        true);
        TEST_ASSERT_EQUALS(KVM::hasFeature(KvmFeature::CLOCKSOURCE_STABLE), true);

        KVM::sFeatures = 0;
    }
    TEST_CASE_END();



    TEST_CASE("setFlag()/clearFlag()/hasFlag()");
    {
        TEST_ASSERT_EQUALS(KVM::sFeatures, 0);

        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE),  false);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE2), false);

        TEST_ASSERT_EQUALS(KVM::setFlag(KvmFeatureTypeFlag::CLOCKSOURCE),  NgosStatus::OK);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE),  true);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE2), false);
        TEST_ASSERT_EQUALS(KVM::sFeatures,                                 0x00000001);

        TEST_ASSERT_EQUALS(KVM::setFlag(KvmFeatureTypeFlag::CLOCKSOURCE2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE),  true);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE2), true);
        TEST_ASSERT_EQUALS(KVM::sFeatures,                                 0x00000009);

        TEST_ASSERT_EQUALS(KVM::clearFlag(KvmFeatureTypeFlag::CLOCKSOURCE), NgosStatus::OK);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE),   false);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE2),  true);
        TEST_ASSERT_EQUALS(KVM::sFeatures,                                  0x00000008);

        TEST_ASSERT_EQUALS(KVM::clearFlag(KvmFeatureTypeFlag::CLOCKSOURCE2), NgosStatus::OK);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE),    false);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE2),   false);
        TEST_ASSERT_EQUALS(KVM::sFeatures,                                   0);



        KVM::sFeatures = 0x01000A93;

        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE),        true);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::NOP_IO_DELAY),       true);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::MMU_OP),             false);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE2),       false);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::ASYNC_PF),           true);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::STEAL_TIME),         false);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::PV_EOI),             false);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::PV_UNHALT),          true);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::PV_TLB_FLUSH),       true);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::ASYNC_PF_VMEXIT),    false);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::PV_SEND_IPI),        true);
        TEST_ASSERT_EQUALS(KVM::hasFlag(KvmFeatureTypeFlag::CLOCKSOURCE_STABLE), true);

        KVM::sFeatures = 0;
    }
    TEST_CASE_END();
}
TEST_CASES_END();



#endif



#endif // KERNEL_TEST_COM_NGOS_KERNEL_A_EARLY_SECTIONS_SECTION2_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVM_H
