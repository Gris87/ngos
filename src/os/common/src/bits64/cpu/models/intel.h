#ifndef OS_COMMON_SRC_BITS64_CPU_MODELS_INTEL_H
#define OS_COMMON_SRC_BITS64_CPU_MODELS_INTEL_H



#include <ngos/types.h>



#define INTEL_FAMILY_6 6



enum class IntelCpuModel: u8
{
    FAMILY_6_SKYLAKE_X          = 85,
    FAMILY_6_CASCADE_LAKE       = 85,
    FAMILY_6_BROADWELL_XEON_D   = 86,
    FAMILY_6_KNIGHTS_LANDING    = 87,
    FAMILY_6_ANNIEDALE          = 90,
    FAMILY_6_AIRMONT_MID        = 90,
    FAMILY_6_APOLLO_LAKE        = 92,
    FAMILY_6_SOFIA              = 93,
    FAMILY_6_SKYLAKE_DESKTOP    = 94,
    FAMILY_6_DENVERTON          = 95,
    FAMILY_6_CANNON_LAKE        = 102,
    FAMILY_6_GEMINI_LAKE        = 122,
    FAMILY_6_ICE_LAKE           = 126,
    FAMILY_6_KNIGHTS_MILL       = 133,
    FAMILY_6_ELKHART_LAKE       = 134,
    FAMILY_6_KABY_LAKE_MOBILE   = 142,
    FAMILY_6_COFFEE_LAKE_U      = 142,
    FAMILY_6_KABY_LAKE_DESKTOP  = 158,
    FAMILY_6_COFFEE_LAKE_S_H_E  = 158
};



#endif // OS_COMMON_SRC_BITS64_CPU_MODELS_INTEL_H
