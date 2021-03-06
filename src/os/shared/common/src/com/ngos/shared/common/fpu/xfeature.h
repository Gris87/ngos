#ifndef COM_NGOS_SHARED_COMMON_FPU_XFEATURE_H
#define COM_NGOS_SHARED_COMMON_FPU_XFEATURE_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class XFeature: u8
{
    FPU,
    SSE,
    AVX,
    MPX_BOUND_REGISTERS,
    MPX_BOUND_CONFIG_AND_STATUS_REGISTERS,
    AVX512_OPMASK,
    AVX512_ZMM_FROM_0_TO_15,
    AVX512_ZMM_FROM_16_TO_31,
    PT,
    PKRU,
    MAXIMUM
};



inline const char8* enumToString(XFeature feature) // TEST: NO
{
    // COMMON_LT((" | feature = %u", feature)); // Commented to avoid bad looking logs



    switch (feature)
    {
        case XFeature::FPU:                                   return "FPU";
        case XFeature::SSE:                                   return "SSE";
        case XFeature::AVX:                                   return "AVX";
        case XFeature::MPX_BOUND_REGISTERS:                   return "MPX_BOUND_REGISTERS";
        case XFeature::MPX_BOUND_CONFIG_AND_STATUS_REGISTERS: return "MPX_BOUND_CONFIG_AND_STATUS_REGISTERS";
        case XFeature::AVX512_OPMASK:                         return "AVX512_OPMASK";
        case XFeature::AVX512_ZMM_FROM_0_TO_15:               return "AVX512_ZMM_FROM_0_TO_15";
        case XFeature::AVX512_ZMM_FROM_16_TO_31:              return "AVX512_ZMM_FROM_16_TO_31";
        case XFeature::PT:                                    return "PT";
        case XFeature::PKRU:                                  return "PKRU";
        case XFeature::MAXIMUM:                               return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(XFeature feature) // TEST: NO
{
    // COMMON_LT((" | feature = %u", feature)); // Commented to avoid bad looking logs



    static char8 res[45];

    sprintf(res, "0x%02X (%s)", (u8)feature, enumToString(feature));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_FPU_XFEATURE_H
