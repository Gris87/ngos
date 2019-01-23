#ifndef OS_COMMON_SRC_BITS64_CPU_MODELS_INTEL_H
#define OS_COMMON_SRC_BITS64_CPU_MODELS_INTEL_H



#include <ngos/types.h>



#define INTEL_FAMILY_6 6



enum class IntelCpuModel: u8
{
    SKYLAKE_X          = 85,
    CASCADE_LAKE       = 85,
    BROADWELL_XEON_D   = 86,
    KNIGHTS_LANDING    = 87,
    ANNIEDALE          = 90,
    AIRMONT_MID        = 90,
    APOLLO_LAKE        = 92,
    SOFIA              = 93,
    SKYLAKE_DESKTOP    = 94,
    DENVERTON          = 95,
    CANNON_LAKE        = 102,
    GEMINI_LAKE        = 122,
    ICE_LAKE           = 126,
    KNIGHTS_MILL       = 133,
    ELKHART_LAKE       = 134,
    KABY_LAKE_MOBILE   = 142,
    COFFEE_LAKE_U      = 142,
    KABY_LAKE_DESKTOP  = 158,
    COFFEE_LAKE_S_H_E  = 158
};



#endif // OS_COMMON_SRC_BITS64_CPU_MODELS_INTEL_H
