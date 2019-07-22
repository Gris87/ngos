#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURE_H



#include <ngos/types.h>



enum class KvmFeature: u8
{
    CLOCKSOURCE            = 0,
    NOP_IO_DELAY           = 1,
    MMU_OP                 = 2,
    CLOCKSOURCE2           = 3,
    ASYNC_PF               = 4,
    STEAL_TIME             = 5,
    PV_EOI                 = 6,
    PV_UNHALT              = 7,
    PV_TLB_FLUSH           = 9,
    ASYNC_PF_VMEXIT        = 10,
    PV_SEND_IPI            = 11,
    CLOCKSOURCE_STABLE_BIT = 24
};



inline const char* kvmFeatureToString(KvmFeature feature) // TEST: NO
{
    // COMMON_LT((" | feature = %u", feature)); // Commented to avoid bad looking logs



    switch (feature)
    {
        case KvmFeature::CLOCKSOURCE:            return "CLOCKSOURCE";
        case KvmFeature::NOP_IO_DELAY:           return "NOP_IO_DELAY";
        case KvmFeature::MMU_OP:                 return "MMU_OP";
        case KvmFeature::CLOCKSOURCE2:           return "CLOCKSOURCE2";
        case KvmFeature::ASYNC_PF:               return "ASYNC_PF";
        case KvmFeature::STEAL_TIME:             return "STEAL_TIME";
        case KvmFeature::PV_EOI:                 return "PV_EOI";
        case KvmFeature::PV_UNHALT:              return "PV_UNHALT";
        case KvmFeature::PV_TLB_FLUSH:           return "PV_TLB_FLUSH";
        case KvmFeature::ASYNC_PF_VMEXIT:        return "ASYNC_PF_VMEXIT";
        case KvmFeature::PV_SEND_IPI:            return "PV_SEND_IPI";
        case KvmFeature::CLOCKSOURCE_STABLE_BIT: return "CLOCKSOURCE_STABLE_BIT";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURE_H
