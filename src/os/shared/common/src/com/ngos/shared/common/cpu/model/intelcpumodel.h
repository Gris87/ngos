#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_INTELCPUMODEL_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_INTELCPUMODEL_H



#include <common/src/com/ngos/shared/common/cpu/cpufamily.h>
#include <common/src/com/ngos/shared/common/log/assert.h>
#include <common/src/com/ngos/shared/common/log/log.h>
#include <common/src/com/ngos/shared/common/printf/printf.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



// Taken from https://en.wikichip.org/wiki/intel/cpuid
enum class IntelCpuModel: u8 // Ignore CppEnumVerifier
{
    NONE                              = 0,
    FAMILY_6_HASWELL_S                = 60,
    FAMILY_6_BROADWELL_U_Y_S          = 61,
    FAMILY_6_IVY_BRIDGE_SERVER        = 62,
    FAMILY_6_HASWELL_SERVER           = 63,
    FAMILY_6_HASWELL_ULT              = 69,
    FAMILY_6_HASWELL_GT3E             = 70,
    FAMILY_6_BROADWELL_H_C_W          = 71,
    FAMILY_6_TANGIER                  = 74,
    FAMILY_6_CHERRY_TRAIL             = 76,
    FAMILY_6_BRASWELL                 = 76,
    FAMILY_6_AVOTON                   = 77,
    FAMILY_6_RANGELEY                 = 77,
    FAMILY_6_SKYLAKE_Y_U              = 78,
    FAMILY_6_BROADWELL_SERVER_E_EP_EX = 79,
    FAMILY_6_SKYLAKE_SERVER           = 85,
    FAMILY_6_CASCADE_LAKE             = 85,
    FAMILY_6_COOPER_LAKE              = 85,
    FAMILY_6_BROADWELL_SERVER_DE      = 86,
    FAMILY_6_KNIGHTS_LANDING          = 87,
    FAMILY_6_ANNIEDALE                = 90,
    FAMILY_6_AIRMONT_MID              = 90,
    FAMILY_6_APOLLO_LAKE              = 92,
    FAMILY_6_SOFIA                    = 93,
    FAMILY_6_SKYLAKE_DT_H_S           = 94,
    FAMILY_6_DENVERTON                = 95,
    FAMILY_6_CANNON_LAKE              = 102,
    FAMILY_6_ICE_LAKE_SERVER_DE       = 106,
    FAMILY_6_ICE_LAKE_SERVER_SP       = 108,
    FAMILY_6_GEMINI_LAKE              = 122,
    FAMILY_6_ICE_LAKE_Y               = 125,
    FAMILY_6_ICE_LAKE_U               = 126,
    FAMILY_6_KNIGHTS_MILL             = 133,
    FAMILY_6_ELKHART_LAKE             = 134,
    FAMILY_6_KABY_LAKE_Y_U            = 142,
    FAMILY_6_COFFEE_LAKE_U            = 142,
    FAMILY_6_WHISKEY_LAKE             = 142,
    FAMILY_6_AMBER_LAKE               = 142,
    FAMILY_6_COMET_LAKE               = 142,
    FAMILY_6_KABY_LAKE_DT_H_S_X       = 158,
    FAMILY_6_COFFEE_LAKE_S_H_E        = 158
};



inline const char8* enumToString(CpuFamily family, IntelCpuModel model) // TEST: NO
{
    // COMMON_LT((" | family = %u, model = %u", family, model)); // Commented to avoid bad looking logs



    if (model == IntelCpuModel::NONE)
    {
        return "NONE";
    }



    switch (family)
    {
        case CpuFamily::INTEL_FAMILY_6:
        {
            switch (model)
            {
                case IntelCpuModel::FAMILY_6_HASWELL_S:                return "FAMILY_6_HASWELL_S";
                case IntelCpuModel::FAMILY_6_BROADWELL_U_Y_S:          return "FAMILY_6_BROADWELL_U_Y_S";
                case IntelCpuModel::FAMILY_6_IVY_BRIDGE_SERVER:        return "FAMILY_6_IVY_BRIDGE_SERVER";
                case IntelCpuModel::FAMILY_6_HASWELL_SERVER:           return "FAMILY_6_HASWELL_SERVER";
                case IntelCpuModel::FAMILY_6_HASWELL_ULT:              return "FAMILY_6_HASWELL_ULT";
                case IntelCpuModel::FAMILY_6_HASWELL_GT3E:             return "FAMILY_6_HASWELL_GT3E";
                case IntelCpuModel::FAMILY_6_BROADWELL_H_C_W:          return "FAMILY_6_BROADWELL_H_C_W";
                case IntelCpuModel::FAMILY_6_TANGIER:                  return "FAMILY_6_TANGIER";
                case IntelCpuModel::FAMILY_6_CHERRY_TRAIL:             return "FAMILY_6_CHERRY_TRAIL";
                case IntelCpuModel::FAMILY_6_AVOTON:                   return "FAMILY_6_AVOTON";
                case IntelCpuModel::FAMILY_6_SKYLAKE_Y_U:              return "FAMILY_6_SKYLAKE_Y_U";
                case IntelCpuModel::FAMILY_6_BROADWELL_SERVER_E_EP_EX: return "FAMILY_6_BROADWELL_SERVER_E_EP_EX";
                case IntelCpuModel::FAMILY_6_COOPER_LAKE:              return "FAMILY_6_COOPER_LAKE";
                case IntelCpuModel::FAMILY_6_BROADWELL_SERVER_DE:      return "FAMILY_6_BROADWELL_SERVER_DE";
                case IntelCpuModel::FAMILY_6_KNIGHTS_LANDING:          return "FAMILY_6_KNIGHTS_LANDING";
                case IntelCpuModel::FAMILY_6_ANNIEDALE:                return "FAMILY_6_ANNIEDALE";
                case IntelCpuModel::FAMILY_6_APOLLO_LAKE:              return "FAMILY_6_APOLLO_LAKE";
                case IntelCpuModel::FAMILY_6_SOFIA:                    return "FAMILY_6_SOFIA";
                case IntelCpuModel::FAMILY_6_SKYLAKE_DT_H_S:           return "FAMILY_6_SKYLAKE_DT_H_S";
                case IntelCpuModel::FAMILY_6_DENVERTON:                return "FAMILY_6_DENVERTON";
                case IntelCpuModel::FAMILY_6_CANNON_LAKE:              return "FAMILY_6_CANNON_LAKE";
                case IntelCpuModel::FAMILY_6_ICE_LAKE_SERVER_DE:       return "FAMILY_6_ICE_LAKE_SERVER_DE";
                case IntelCpuModel::FAMILY_6_ICE_LAKE_SERVER_SP:       return "FAMILY_6_ICE_LAKE_SERVER_SP";
                case IntelCpuModel::FAMILY_6_GEMINI_LAKE:              return "FAMILY_6_GEMINI_LAKE";
                case IntelCpuModel::FAMILY_6_ICE_LAKE_Y:               return "FAMILY_6_ICE_LAKE_Y";
                case IntelCpuModel::FAMILY_6_ICE_LAKE_U:               return "FAMILY_6_ICE_LAKE_U";
                case IntelCpuModel::FAMILY_6_KNIGHTS_MILL:             return "FAMILY_6_KNIGHTS_MILL";
                case IntelCpuModel::FAMILY_6_ELKHART_LAKE:             return "FAMILY_6_ELKHART_LAKE";
                case IntelCpuModel::FAMILY_6_COMET_LAKE:               return "FAMILY_6_COMET_LAKE";
                case IntelCpuModel::FAMILY_6_COFFEE_LAKE_S_H_E:        return "FAMILY_6_COFFEE_LAKE_S_H_E";

                default: return "UNKNOWN";
            }
        }
        break;

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(CpuFamily family, IntelCpuModel model) // TEST: NO
{
    // COMMON_LT((" | family = %u, model = %u", family, model)); // Commented to avoid bad looking logs



    static char8 res[41];

    sprintf(res, "0x%02X (%s)", model, enumToString(family, model));

    return res;
}



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_INTELCPUMODEL_H
