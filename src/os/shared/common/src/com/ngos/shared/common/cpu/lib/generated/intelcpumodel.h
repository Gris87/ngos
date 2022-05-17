// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_INTELCPUMODEL_H
#define COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_INTELCPUMODEL_H



#include <com/ngos/shared/common/cpu/lib/cpufamily.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Taken from https://en.wikichip.org/wiki/intel/cpuid
enum class IntelCpuModel: good_U8 // Ignore CppEnumVerifier
{
    NONE                            = 0,
    FAMILY_6_KATMAI                 = 7,
    FAMILY_6_COPPERMINE             = 8,
    FAMILY_6_COPPERMINE_T           = 8,
    FAMILY_6_BANIAS                 = 9,
    FAMILY_6_P6                     = 10,
    FAMILY_6_TUALATIN               = 11,
    FAMILY_6_DOTHAN                 = 13,
    FAMILY_6_YONAH                  = 14,
    FAMILY_6_MEROM                  = 15,
    FAMILY_6_TOLAPAI                = 21,
    FAMILY_6_MEROM_L                = 22,
    FAMILY_6_HARPERTOWN             = 23,
    FAMILY_6_PENRYN                 = 23,
    FAMILY_6_PENRYN_SERVER_QC       = 23,
    FAMILY_6_WOLFDALE               = 23,
    FAMILY_6_YORKFIELD              = 23,
    FAMILY_6_BLOOMFIELD             = 26,
    FAMILY_6_NEHALEM_SERVER_EP      = 26,
    FAMILY_6_NEHALEM_SERVER_WS      = 26,
    FAMILY_6_DIAMONDVILLE           = 28,
    FAMILY_6_PINEVIEW               = 28,
    FAMILY_6_SILVERTHORNE           = 28,
    FAMILY_6_DUNNINGTON             = 29,
    FAMILY_6_CLARKSFIELD            = 30,
    FAMILY_6_LYNNFIELD              = 30,
    FAMILY_6_AUBURNDALE             = 31,
    FAMILY_6_HAVENDALE              = 31,
    FAMILY_6_ARRANDALE              = 37,
    FAMILY_6_CLARKDALE              = 37,
    FAMILY_6_LINCROFT               = 38,
    FAMILY_6_PENWELL                = 39,
    FAMILY_6_CELERON                = 42,
    FAMILY_6_SANDY_BRIDGE_CLIENT_H  = 42,
    FAMILY_6_SANDY_BRIDGE_CLIENT_M  = 42,
    FAMILY_6_GULFTOWN               = 44,
    FAMILY_6_WESTMERE_SERVER_EP     = 44,
    FAMILY_6_SANDY_BRIDGE_SERVER_E  = 45,
    FAMILY_6_SANDY_BRIDGE_SERVER_EN = 45,
    FAMILY_6_SANDY_BRIDGE_SERVER_EP = 45,
    FAMILY_6_NEHALEM_SERVER_EX      = 46,
    FAMILY_6_WESTMERE_SERVER_EX     = 47,
    FAMILY_6_CLOVERVIEW             = 53,
    FAMILY_6_CEDARVIEW              = 54,
    FAMILY_6_BAY_TRAIL              = 55,
    FAMILY_6_GLADDEN                = 58,
    FAMILY_6_IVY_BRIDGE_CLIENT_H    = 58,
    FAMILY_6_IVY_BRIDGE_CLIENT_M    = 58,
    FAMILY_6_HASWELL_CLIENT_S       = 60,
    FAMILY_6_BROADWELL_CLIENT_S     = 61,
    FAMILY_6_BROADWELL_CLIENT_U     = 61,
    FAMILY_6_BROADWELL_CLIENT_Y     = 61,
    FAMILY_6_IVY_BRIDGE_SERVER_E    = 62,
    FAMILY_6_IVY_BRIDGE_SERVER_EN   = 62,
    FAMILY_6_IVY_BRIDGE_SERVER_EP   = 62,
    FAMILY_6_IVY_BRIDGE_SERVER_EX   = 62,
    FAMILY_6_HASWELL_SERVER_E       = 63,
    FAMILY_6_HASWELL_SERVER_EP      = 63,
    FAMILY_6_HASWELL_SERVER_EX      = 63,
    FAMILY_6_HASWELL_CLIENT_ULT     = 69,
    FAMILY_6_HASWELL_CLIENT_GT3E    = 70,
    FAMILY_6_BROADWELL_CLIENT_C     = 71,
    FAMILY_6_BROADWELL_CLIENT_H     = 71,
    FAMILY_6_BROADWELL_CLIENT_W     = 71,
    FAMILY_6_TANGIER                = 74,
    FAMILY_6_BRASWELL               = 76,
    FAMILY_6_CHERRY_TRAIL           = 76,
    FAMILY_6_AVOTON                 = 77,
    FAMILY_6_RANGELEY               = 77,
    FAMILY_6_SKYLAKE_CLIENT_U       = 78,
    FAMILY_6_SKYLAKE_CLIENT_Y       = 78,
    FAMILY_6_BROADWELL_SERVER_E     = 79,
    FAMILY_6_BROADWELL_SERVER_EP    = 79,
    FAMILY_6_BROADWELL_SERVER_EX    = 79,
    FAMILY_6_CASCADE_LAKE_SP        = 85,
    FAMILY_6_CASCADE_LAKE_W         = 85,
    FAMILY_6_CASCADE_LAKE_X         = 85,
    FAMILY_6_COOPER_LAKE            = 85,
    FAMILY_6_SKYLAKE_SERVER_DE      = 85,
    FAMILY_6_SKYLAKE_SERVER_SP      = 85,
    FAMILY_6_SKYLAKE_SERVER_W       = 85,
    FAMILY_6_SKYLAKE_SERVER_X       = 85,
    FAMILY_6_BROADWELL_SERVER_DE    = 86,
    FAMILY_6_HEWITT_LAKE            = 86,
    FAMILY_6_KNIGHTS_LANDING        = 87,
    FAMILY_6_ANNIEDALE              = 90,
    FAMILY_6_APOLLO_LAKE            = 92,
    FAMILY_6_BROXTON                = 92,
    FAMILY_6_SOFIA                  = 93,
    FAMILY_6_SKYLAKE_CLIENT_DT      = 94,
    FAMILY_6_SKYLAKE_CLIENT_H       = 94,
    FAMILY_6_SKYLAKE_CLIENT_S       = 94,
    FAMILY_6_DENVERTON              = 95,
    FAMILY_6_CANNON_LAKE_U          = 102,
    FAMILY_6_ICE_LAKE_SERVER_SP     = 106,
    FAMILY_6_ICE_LAKE_SERVER_DE     = 108,
    FAMILY_6_GEMINI_LAKE            = 122,
    FAMILY_6_ICE_LAKE_CLIENT_Y      = 125,
    FAMILY_6_ICE_LAKE_CLIENT_U      = 126,
    FAMILY_6_KNIGHTS_MILL           = 133,
    FAMILY_6_LAKEFIELD              = 138,
    FAMILY_6_TIGER_LAKE_U           = 140,
    FAMILY_6_TIGER_LAKE_H           = 141,
    FAMILY_6_AMBER_LAKE_Y           = 142,
    FAMILY_6_COFFEE_LAKE_U          = 142,
    FAMILY_6_COMET_LAKE_U           = 142,
    FAMILY_6_KABY_LAKE_U            = 142,
    FAMILY_6_KABY_LAKE_Y            = 142,
    FAMILY_6_WHISKEY_LAKE_U         = 142,
    FAMILY_6_SAPPHIRE_RAPIDS        = 143,
    FAMILY_6_ELKHART_LAKE           = 150,
    FAMILY_6_ALDER_LAKE_S           = 151,
    FAMILY_6_ALDER_LAKE_P           = 154,
    FAMILY_6_JASPER_LAKE            = 156,
    FAMILY_6_COFFEE_LAKE_E          = 158,
    FAMILY_6_COFFEE_LAKE_H          = 158,
    FAMILY_6_COFFEE_LAKE_S          = 158,
    FAMILY_6_KABY_LAKE_DT           = 158,
    FAMILY_6_KABY_LAKE_H            = 158,
    FAMILY_6_KABY_LAKE_S            = 158,
    FAMILY_6_KABY_LAKE_X            = 158,
    FAMILY_6_COMET_LAKE_H           = 165,
    FAMILY_6_COMET_LAKE_S           = 165,
    FAMILY_6_ROCKET_LAKE_S          = 167
};



inline const good_Char8* enumToString(CpuFamily family, IntelCpuModel model) // TEST: NO
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
                case IntelCpuModel::FAMILY_6_KATMAI:                 return "FAMILY_6_KATMAI";
                case IntelCpuModel::FAMILY_6_COPPERMINE:             return "FAMILY_6_COPPERMINE";
                case IntelCpuModel::FAMILY_6_BANIAS:                 return "FAMILY_6_BANIAS";
                case IntelCpuModel::FAMILY_6_P6:                     return "FAMILY_6_P6";
                case IntelCpuModel::FAMILY_6_TUALATIN:               return "FAMILY_6_TUALATIN";
                case IntelCpuModel::FAMILY_6_DOTHAN:                 return "FAMILY_6_DOTHAN";
                case IntelCpuModel::FAMILY_6_YONAH:                  return "FAMILY_6_YONAH";
                case IntelCpuModel::FAMILY_6_MEROM:                  return "FAMILY_6_MEROM";
                case IntelCpuModel::FAMILY_6_TOLAPAI:                return "FAMILY_6_TOLAPAI";
                case IntelCpuModel::FAMILY_6_MEROM_L:                return "FAMILY_6_MEROM_L";
                case IntelCpuModel::FAMILY_6_HARPERTOWN:             return "FAMILY_6_HARPERTOWN";
                case IntelCpuModel::FAMILY_6_BLOOMFIELD:             return "FAMILY_6_BLOOMFIELD";
                case IntelCpuModel::FAMILY_6_DIAMONDVILLE:           return "FAMILY_6_DIAMONDVILLE";
                case IntelCpuModel::FAMILY_6_DUNNINGTON:             return "FAMILY_6_DUNNINGTON";
                case IntelCpuModel::FAMILY_6_CLARKSFIELD:            return "FAMILY_6_CLARKSFIELD";
                case IntelCpuModel::FAMILY_6_AUBURNDALE:             return "FAMILY_6_AUBURNDALE";
                case IntelCpuModel::FAMILY_6_ARRANDALE:              return "FAMILY_6_ARRANDALE";
                case IntelCpuModel::FAMILY_6_LINCROFT:               return "FAMILY_6_LINCROFT";
                case IntelCpuModel::FAMILY_6_PENWELL:                return "FAMILY_6_PENWELL";
                case IntelCpuModel::FAMILY_6_CELERON:                return "FAMILY_6_CELERON";
                case IntelCpuModel::FAMILY_6_GULFTOWN:               return "FAMILY_6_GULFTOWN";
                case IntelCpuModel::FAMILY_6_SANDY_BRIDGE_SERVER_E:  return "FAMILY_6_SANDY_BRIDGE_SERVER_E";
                case IntelCpuModel::FAMILY_6_NEHALEM_SERVER_EX:      return "FAMILY_6_NEHALEM_SERVER_EX";
                case IntelCpuModel::FAMILY_6_WESTMERE_SERVER_EX:     return "FAMILY_6_WESTMERE_SERVER_EX";
                case IntelCpuModel::FAMILY_6_CLOVERVIEW:             return "FAMILY_6_CLOVERVIEW";
                case IntelCpuModel::FAMILY_6_CEDARVIEW:              return "FAMILY_6_CEDARVIEW";
                case IntelCpuModel::FAMILY_6_BAY_TRAIL:              return "FAMILY_6_BAY_TRAIL";
                case IntelCpuModel::FAMILY_6_GLADDEN:                return "FAMILY_6_GLADDEN";
                case IntelCpuModel::FAMILY_6_HASWELL_CLIENT_S:       return "FAMILY_6_HASWELL_CLIENT_S";
                case IntelCpuModel::FAMILY_6_BROADWELL_CLIENT_S:     return "FAMILY_6_BROADWELL_CLIENT_S";
                case IntelCpuModel::FAMILY_6_IVY_BRIDGE_SERVER_E:    return "FAMILY_6_IVY_BRIDGE_SERVER_E";
                case IntelCpuModel::FAMILY_6_HASWELL_SERVER_E:       return "FAMILY_6_HASWELL_SERVER_E";
                case IntelCpuModel::FAMILY_6_HASWELL_CLIENT_ULT:     return "FAMILY_6_HASWELL_CLIENT_ULT";
                case IntelCpuModel::FAMILY_6_HASWELL_CLIENT_GT3E:    return "FAMILY_6_HASWELL_CLIENT_GT3E";
                case IntelCpuModel::FAMILY_6_BROADWELL_CLIENT_C:     return "FAMILY_6_BROADWELL_CLIENT_C";
                case IntelCpuModel::FAMILY_6_TANGIER:                return "FAMILY_6_TANGIER";
                case IntelCpuModel::FAMILY_6_BRASWELL:               return "FAMILY_6_BRASWELL";
                case IntelCpuModel::FAMILY_6_AVOTON:                 return "FAMILY_6_AVOTON";
                case IntelCpuModel::FAMILY_6_SKYLAKE_CLIENT_U:       return "FAMILY_6_SKYLAKE_CLIENT_U";
                case IntelCpuModel::FAMILY_6_BROADWELL_SERVER_E:     return "FAMILY_6_BROADWELL_SERVER_E";
                case IntelCpuModel::FAMILY_6_CASCADE_LAKE_SP:        return "FAMILY_6_CASCADE_LAKE_SP";
                case IntelCpuModel::FAMILY_6_BROADWELL_SERVER_DE:    return "FAMILY_6_BROADWELL_SERVER_DE";
                case IntelCpuModel::FAMILY_6_KNIGHTS_LANDING:        return "FAMILY_6_KNIGHTS_LANDING";
                case IntelCpuModel::FAMILY_6_ANNIEDALE:              return "FAMILY_6_ANNIEDALE";
                case IntelCpuModel::FAMILY_6_APOLLO_LAKE:            return "FAMILY_6_APOLLO_LAKE";
                case IntelCpuModel::FAMILY_6_SOFIA:                  return "FAMILY_6_SOFIA";
                case IntelCpuModel::FAMILY_6_SKYLAKE_CLIENT_DT:      return "FAMILY_6_SKYLAKE_CLIENT_DT";
                case IntelCpuModel::FAMILY_6_DENVERTON:              return "FAMILY_6_DENVERTON";
                case IntelCpuModel::FAMILY_6_CANNON_LAKE_U:          return "FAMILY_6_CANNON_LAKE_U";
                case IntelCpuModel::FAMILY_6_ICE_LAKE_SERVER_SP:     return "FAMILY_6_ICE_LAKE_SERVER_SP";
                case IntelCpuModel::FAMILY_6_ICE_LAKE_SERVER_DE:     return "FAMILY_6_ICE_LAKE_SERVER_DE";
                case IntelCpuModel::FAMILY_6_GEMINI_LAKE:            return "FAMILY_6_GEMINI_LAKE";
                case IntelCpuModel::FAMILY_6_ICE_LAKE_CLIENT_Y:      return "FAMILY_6_ICE_LAKE_CLIENT_Y";
                case IntelCpuModel::FAMILY_6_ICE_LAKE_CLIENT_U:      return "FAMILY_6_ICE_LAKE_CLIENT_U";
                case IntelCpuModel::FAMILY_6_KNIGHTS_MILL:           return "FAMILY_6_KNIGHTS_MILL";
                case IntelCpuModel::FAMILY_6_LAKEFIELD:              return "FAMILY_6_LAKEFIELD";
                case IntelCpuModel::FAMILY_6_TIGER_LAKE_U:           return "FAMILY_6_TIGER_LAKE_U";
                case IntelCpuModel::FAMILY_6_TIGER_LAKE_H:           return "FAMILY_6_TIGER_LAKE_H";
                case IntelCpuModel::FAMILY_6_AMBER_LAKE_Y:           return "FAMILY_6_AMBER_LAKE_Y";
                case IntelCpuModel::FAMILY_6_SAPPHIRE_RAPIDS:        return "FAMILY_6_SAPPHIRE_RAPIDS";
                case IntelCpuModel::FAMILY_6_ELKHART_LAKE:           return "FAMILY_6_ELKHART_LAKE";
                case IntelCpuModel::FAMILY_6_ALDER_LAKE_S:           return "FAMILY_6_ALDER_LAKE_S";
                case IntelCpuModel::FAMILY_6_ALDER_LAKE_P:           return "FAMILY_6_ALDER_LAKE_P";
                case IntelCpuModel::FAMILY_6_JASPER_LAKE:            return "FAMILY_6_JASPER_LAKE";
                case IntelCpuModel::FAMILY_6_COFFEE_LAKE_E:          return "FAMILY_6_COFFEE_LAKE_E";
                case IntelCpuModel::FAMILY_6_COMET_LAKE_H:           return "FAMILY_6_COMET_LAKE_H";
                case IntelCpuModel::FAMILY_6_ROCKET_LAKE_S:          return "FAMILY_6_ROCKET_LAKE_S";

                default: return "UNKNOWN";
            }
        }
        break;

        default: return "UNKNOWN";
    }
}



inline const good_Char8* enumToFullString(CpuFamily family, IntelCpuModel model) // TEST: NO
{
    // COMMON_LT((" | family = %u, model = %u", family, model)); // Commented to avoid bad looking logs



    static good_Char8 res[37];

    sprintf(res, "0x%02X (%s)", static_cast<good_U8>(model), enumToString(family, model));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_INTELCPUMODEL_H
