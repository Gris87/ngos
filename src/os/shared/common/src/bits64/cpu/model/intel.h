#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_INTEL_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_INTEL_H



#include <ngos/types.h>



enum class IntelCpuModel: u8 // Ignore CppEnumVerifier
{
    FAMILY_6_SKYLAKE_SERVER     = 85,
    FAMILY_6_CASCADE_LAKE       = 85,
    FAMILY_6_COOPER_LAKE        = 85,
    FAMILY_6_BROADWELL          = 86,
    FAMILY_6_KNIGHTS_LANDING    = 87,
    FAMILY_6_ANNIEDALE          = 90,
    FAMILY_6_AIRMONT_MID        = 90,
    FAMILY_6_APOLLO_LAKE        = 92,
    FAMILY_6_SOFIA              = 93,
    FAMILY_6_SKYLAKE_DESKTOP    = 94,
    FAMILY_6_DENVERTON          = 95,
    FAMILY_6_CANNON_LAKE        = 102,
    FAMILY_6_ICE_LAKE_DE        = 106,
    FAMILY_6_ICE_LAKE_SP        = 108,
    FAMILY_6_GEMINI_LAKE        = 122,
    FAMILY_6_ICE_LAKE_Y         = 125,
    FAMILY_6_ICE_LAKE_U         = 126,
    FAMILY_6_KNIGHTS_MILL       = 133,
    FAMILY_6_ELKHART_LAKE       = 134,
    FAMILY_6_KABY_LAKE_MOBILE   = 142,
    FAMILY_6_COFFEE_LAKE_U      = 142,
    FAMILY_6_WHISKEY_LAKE_U     = 142,
    FAMILY_6_AMBER_LAKE_U       = 142,
    FAMILY_6_COMET_LAKE_U       = 142,
    FAMILY_6_KABY_LAKE_DESKTOP  = 158,
    FAMILY_6_COFFEE_LAKE_S_H_E  = 158
};



inline const char* intelCpuModelToString(IntelCpuModel model) // TEST: NO
{
    // COMMON_LT((" | model = %u", model)); // Commented to avoid bad looking logs



    switch (model)
    {
        case IntelCpuModel::FAMILY_6_COOPER_LAKE:       return "FAMILY_6_COOPER_LAKE";
        case IntelCpuModel::FAMILY_6_BROADWELL:         return "FAMILY_6_BROADWELL";
        case IntelCpuModel::FAMILY_6_KNIGHTS_LANDING:   return "FAMILY_6_KNIGHTS_LANDING";
        case IntelCpuModel::FAMILY_6_ANNIEDALE:         return "FAMILY_6_ANNIEDALE";
        case IntelCpuModel::FAMILY_6_APOLLO_LAKE:       return "FAMILY_6_APOLLO_LAKE";
        case IntelCpuModel::FAMILY_6_SOFIA:             return "FAMILY_6_SOFIA";
        case IntelCpuModel::FAMILY_6_SKYLAKE_DESKTOP:   return "FAMILY_6_SKYLAKE_DESKTOP";
        case IntelCpuModel::FAMILY_6_DENVERTON:         return "FAMILY_6_DENVERTON";
        case IntelCpuModel::FAMILY_6_CANNON_LAKE:       return "FAMILY_6_CANNON_LAKE";
        case IntelCpuModel::FAMILY_6_ICE_LAKE_DE:       return "FAMILY_6_ICE_LAKE_DE";
        case IntelCpuModel::FAMILY_6_ICE_LAKE_SP:       return "FAMILY_6_ICE_LAKE_SP";
        case IntelCpuModel::FAMILY_6_GEMINI_LAKE:       return "FAMILY_6_GEMINI_LAKE";
        case IntelCpuModel::FAMILY_6_ICE_LAKE_Y:        return "FAMILY_6_ICE_LAKE_Y";
        case IntelCpuModel::FAMILY_6_ICE_LAKE_U:        return "FAMILY_6_ICE_LAKE_U";
        case IntelCpuModel::FAMILY_6_KNIGHTS_MILL:      return "FAMILY_6_KNIGHTS_MILL";
        case IntelCpuModel::FAMILY_6_ELKHART_LAKE:      return "FAMILY_6_ELKHART_LAKE";
        case IntelCpuModel::FAMILY_6_COMET_LAKE_U:      return "FAMILY_6_COMET_LAKE_U";
        case IntelCpuModel::FAMILY_6_COFFEE_LAKE_S_H_E: return "FAMILY_6_COFFEE_LAKE_S_H_E";

        default: return "UNKNOWN";
    }
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_INTEL_H
