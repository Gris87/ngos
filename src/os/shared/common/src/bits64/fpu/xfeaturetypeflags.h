#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURETYPEFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURETYPEFLAGS_H



#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/fpu/xfeature.h>
#include <common/src/bits64/printf/printf.h>
#include <common/src/bits64/string/string.h>
#include <ngos/linkage.h>
#include <ngos/types.h>



#define XFEATURE_MASK_FPU_SSE    FLAGS(XFeatureTypeFlag::FPU, XFeatureTypeFlag::SSE)
#define XFEATURE_MASK_SUPERVISOR FLAG(XFeatureTypeFlag::PT)



typedef u64 x_feature_type_flags;

enum class XFeatureTypeFlag: x_feature_type_flags
{
    NONE                                  = 0,
    FPU                                   = (1ULL << (u64)XFeature::FPU),
    SSE                                   = (1ULL << (u64)XFeature::SSE),
    AVX                                   = (1ULL << (u64)XFeature::AVX),
    MPX_BOUND_REGISTERS                   = (1ULL << (u64)XFeature::MPX_BOUND_REGISTERS),
    MPX_BOUND_CONFIG_AND_STATUS_REGISTERS = (1ULL << (u64)XFeature::MPX_BOUND_CONFIG_AND_STATUS_REGISTERS),
    AVX512_OPMASK                         = (1ULL << (u64)XFeature::AVX512_OPMASK),
    AVX512_ZMM_FROM_0_TO_15               = (1ULL << (u64)XFeature::AVX512_ZMM_FROM_0_TO_15),
    AVX512_ZMM_FROM_16_TO_31              = (1ULL << (u64)XFeature::AVX512_ZMM_FROM_16_TO_31),
    PT                                    = (1ULL << (u64)XFeature::PT),
    PKRU                                  = (1ULL << (u64)XFeature::PKRU)
};



inline const char8* xFeatureTypeFlagToString(XFeatureTypeFlag flag) // TEST: NO
{
    // COMMON_LT((" | flag = %u", flag)); // Commented to avoid bad looking logs



    switch (flag)
    {
        case XFeatureTypeFlag::NONE:                                  return "NONE";
        case XFeatureTypeFlag::FPU:                                   return "FPU";
        case XFeatureTypeFlag::SSE:                                   return "SSE";
        case XFeatureTypeFlag::AVX:                                   return "AVX";
        case XFeatureTypeFlag::MPX_BOUND_REGISTERS:                   return "MPX_BOUND_REGISTERS";
        case XFeatureTypeFlag::MPX_BOUND_CONFIG_AND_STATUS_REGISTERS: return "MPX_BOUND_CONFIG_AND_STATUS_REGISTERS";
        case XFeatureTypeFlag::AVX512_OPMASK:                         return "AVX512_OPMASK";
        case XFeatureTypeFlag::AVX512_ZMM_FROM_0_TO_15:               return "AVX512_ZMM_FROM_0_TO_15";
        case XFeatureTypeFlag::AVX512_ZMM_FROM_16_TO_31:              return "AVX512_ZMM_FROM_16_TO_31";
        case XFeatureTypeFlag::PT:                                    return "PT";
        case XFeatureTypeFlag::PKRU:                                  return "PKRU";

        default: return "UNKNOWN";
    }
}



inline const char8* xFeatureTypeFlagsToString(x_feature_type_flags flags) // TEST: NO
{
    // COMMON_LT((" | flags = %u", flags)); // Commented to avoid bad looking logs



    if (!flags)
    {
        return "NONE";
    }



    static char8 res[174];

    FLAGS_TO_STRING(res, flags, xFeatureTypeFlagToString, XFeatureTypeFlag);

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURETYPEFLAGS_H
