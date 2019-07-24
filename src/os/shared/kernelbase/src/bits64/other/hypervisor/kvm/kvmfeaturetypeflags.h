#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURETYPEFLAGS_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURETYPEFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <kernelbase/src/bits64/other/hypervisor/kvm/kvmfeature.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



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



inline const char* kvmFeatureTypeFlagToString(KvmFeatureTypeFlag flag) // TEST: NO
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



inline const char* kvmFeatureTypeFlagsToString(kvm_feature_type_flags flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char res[179];

    FLAGS_TO_STRING(res, flags, kvmFeatureTypeFlagToString, KvmFeatureTypeFlag);

    return res;
}



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_HYPERVISOR_KVM_KVMFEATURETYPEFLAGS_H
