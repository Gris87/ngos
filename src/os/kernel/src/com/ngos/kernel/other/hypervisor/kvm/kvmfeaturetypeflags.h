#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVMFEATURETYPEFLAGS_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVMFEATURETYPEFLAGS_H



#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/printf/printf.h>
#include <com/ngos/shared/common/string/string.h>
#include <com/ngos/shared/common/ngos/flags.h>
#include <com/ngos/shared/common/ngos/linkage.h>
#include <com/ngos/shared/common/ngos/types.h>

#include <com/ngos/kernel/other/hypervisor/kvm/kvmfeature.h>



typedef u32 kvm_feature_type_flags;

enum class KvmFeatureTypeFlag: kvm_feature_type_flags
{
    NONE               = 0,
    CLOCKSOURCE        = (1ULL << (u64)KvmFeature::CLOCKSOURCE),
    NOP_IO_DELAY       = (1ULL << (u64)KvmFeature::NOP_IO_DELAY),
    MMU_OP             = (1ULL << (u64)KvmFeature::MMU_OP),
    CLOCKSOURCE2       = (1ULL << (u64)KvmFeature::CLOCKSOURCE2),
    ASYNC_PF           = (1ULL << (u64)KvmFeature::ASYNC_PF),
    STEAL_TIME         = (1ULL << (u64)KvmFeature::STEAL_TIME),
    PV_EOI             = (1ULL << (u64)KvmFeature::PV_EOI),
    PV_UNHALT          = (1ULL << (u64)KvmFeature::PV_UNHALT),
    PV_TLB_FLUSH       = (1ULL << (u64)KvmFeature::PV_TLB_FLUSH),
    ASYNC_PF_VMEXIT    = (1ULL << (u64)KvmFeature::ASYNC_PF_VMEXIT),
    PV_SEND_IPI        = (1ULL << (u64)KvmFeature::PV_SEND_IPI),
    CLOCKSOURCE_STABLE = (1ULL << (u64)KvmFeature::CLOCKSOURCE_STABLE)
};

DEFINE_FLAGS(KvmFeatureTypeFlags, kvm_feature_type_flags); // TEST: NO



inline const char8* flagToString(KvmFeatureTypeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case KvmFeatureTypeFlag::NONE:               return "NONE";
        case KvmFeatureTypeFlag::CLOCKSOURCE:        return "CLOCKSOURCE";
        case KvmFeatureTypeFlag::NOP_IO_DELAY:       return "NOP_IO_DELAY";
        case KvmFeatureTypeFlag::MMU_OP:             return "MMU_OP";
        case KvmFeatureTypeFlag::CLOCKSOURCE2:       return "CLOCKSOURCE2";
        case KvmFeatureTypeFlag::ASYNC_PF:           return "ASYNC_PF";
        case KvmFeatureTypeFlag::STEAL_TIME:         return "STEAL_TIME";
        case KvmFeatureTypeFlag::PV_EOI:             return "PV_EOI";
        case KvmFeatureTypeFlag::PV_UNHALT:          return "PV_UNHALT";
        case KvmFeatureTypeFlag::PV_TLB_FLUSH:       return "PV_TLB_FLUSH";
        case KvmFeatureTypeFlag::ASYNC_PF_VMEXIT:    return "ASYNC_PF_VMEXIT";
        case KvmFeatureTypeFlag::PV_SEND_IPI:        return "PV_SEND_IPI";
        case KvmFeatureTypeFlag::CLOCKSOURCE_STABLE: return "CLOCKSOURCE_STABLE";

        default: return "UNKNOWN";
    }
}



inline const char8* flagToFullString(KvmFeatureTypeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", flag, flagToString(flag));

    return res;
}



inline const char8* flagsToString(const KvmFeatureTypeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[179];

    FLAGS_TO_STRING(res, flags.flags, KvmFeatureTypeFlag);

    return res;
}



inline const char8* flagsToFullString(const KvmFeatureTypeFlags &flags) // TEST: NO
{
    // COMMON_LT((" | flags = ...")); // Commented to avoid bad looking logs



    static char8 res[192];

    FLAGS_TO_FULL_STRING(res, flags.flags, KvmFeatureTypeFlag, "0x%08X");

    return res;
}



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_HYPERVISOR_KVM_KVMFEATURETYPEFLAGS_H
