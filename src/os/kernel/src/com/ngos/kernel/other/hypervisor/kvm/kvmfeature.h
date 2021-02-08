#ifndef COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVMFEATURE_H
#define COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVMFEATURE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class KvmFeature: u8
{
    CLOCKSOURCE        = 0,
    NOP_IO_DELAY       = 1,
    MMU_OP             = 2,
    CLOCKSOURCE2       = 3,
    ASYNC_PF           = 4,
    STEAL_TIME         = 5,
    PV_EOI             = 6,
    PV_UNHALT          = 7,
    PV_TLB_FLUSH       = 9,
    ASYNC_PF_VMEXIT    = 10,
    PV_SEND_IPI        = 11,
    CLOCKSOURCE_STABLE = 24
};



inline const char8* enumToString(KvmFeature feature) // TEST: NO
{
    // COMMON_LT((" | feature = %u", feature)); // Commented to avoid bad looking logs



    switch (feature)
    {
        case KvmFeature::CLOCKSOURCE:        return "CLOCKSOURCE";
        case KvmFeature::NOP_IO_DELAY:       return "NOP_IO_DELAY";
        case KvmFeature::MMU_OP:             return "MMU_OP";
        case KvmFeature::CLOCKSOURCE2:       return "CLOCKSOURCE2";
        case KvmFeature::ASYNC_PF:           return "ASYNC_PF";
        case KvmFeature::STEAL_TIME:         return "STEAL_TIME";
        case KvmFeature::PV_EOI:             return "PV_EOI";
        case KvmFeature::PV_UNHALT:          return "PV_UNHALT";
        case KvmFeature::PV_TLB_FLUSH:       return "PV_TLB_FLUSH";
        case KvmFeature::ASYNC_PF_VMEXIT:    return "ASYNC_PF_VMEXIT";
        case KvmFeature::PV_SEND_IPI:        return "PV_SEND_IPI";
        case KvmFeature::CLOCKSOURCE_STABLE: return "CLOCKSOURCE_STABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(KvmFeature feature) // TEST: NO
{
    // COMMON_LT((" | feature = %u", feature)); // Commented to avoid bad looking logs



    static char8 res[26];

    sprintf(res, "0x%02X (%s)", (u8)feature, enumToString(feature));

    return res;
}



#endif // COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVMFEATURE_H
