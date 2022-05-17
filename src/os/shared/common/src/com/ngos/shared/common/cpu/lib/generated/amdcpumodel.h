// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_AMDCPUMODEL_H
#define COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_AMDCPUMODEL_H



#include <com/ngos/shared/common/cpu/lib/cpufamily.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Taken from https://en.wikichip.org/wiki/amd/cpuid
enum class AmdCpuModel: good_U8 // Ignore CppEnumVerifier
{
    NONE                       = 0,
    FAMILY_23_NAPLES           = 1,
    FAMILY_23_SNOWY_OWL        = 1,
    FAMILY_23_SUMMIT_RIDGE     = 1,
    FAMILY_23_WHITEHAVEN       = 1,
    FAMILY_23_COLFAX           = 8,
    FAMILY_23_PINNACLE_RIDGE   = 8,
    FAMILY_23_GREAT_HORNED_OWL = 17,
    FAMILY_23_RAVEN_RIDGE      = 17,
    FAMILY_23_BANDED_KESTREL   = 24,
    FAMILY_23_PICASSO          = 24,
    FAMILY_23_DALI             = 32,
    FAMILY_23_CASTLE_PEAK      = 49,
    FAMILY_23_ROME             = 49,
    FAMILY_23_XBOX_SERIES_X    = 71,
    FAMILY_23_GREY_HAWK        = 96,
    FAMILY_23_RENOIR           = 96,
    FAMILY_23_LUCIENNE         = 104,
    FAMILY_23_MATISSE          = 113,
    FAMILY_23_VAN_GOGH         = 144,
    FAMILY_24_DHYANA           = 0,
    FAMILY_25_MILAN            = 1,
    FAMILY_25_CHAGALL          = 8,
    FAMILY_25_VERMEER          = 33,
    FAMILY_25_REMBRANT         = 64,
    FAMILY_25_CEZANNE          = 80
};



inline const good_Char8* enumToString(CpuFamily family, AmdCpuModel model) // TEST: NO
{
    // COMMON_LT((" | family = %u, model = %u", family, model)); // Commented to avoid bad looking logs



    if (model == AmdCpuModel::NONE)
    {
        return "NONE";
    }



    switch (family)
    {
        case CpuFamily::AMD_FAMILY_23:
        {
            switch (model)
            {
                case AmdCpuModel::FAMILY_23_NAPLES:           return "FAMILY_23_NAPLES";
                case AmdCpuModel::FAMILY_23_COLFAX:           return "FAMILY_23_COLFAX";
                case AmdCpuModel::FAMILY_23_GREAT_HORNED_OWL: return "FAMILY_23_GREAT_HORNED_OWL";
                case AmdCpuModel::FAMILY_23_BANDED_KESTREL:   return "FAMILY_23_BANDED_KESTREL";
                case AmdCpuModel::FAMILY_23_DALI:             return "FAMILY_23_DALI";
                case AmdCpuModel::FAMILY_23_CASTLE_PEAK:      return "FAMILY_23_CASTLE_PEAK";
                case AmdCpuModel::FAMILY_23_XBOX_SERIES_X:    return "FAMILY_23_XBOX_SERIES_X";
                case AmdCpuModel::FAMILY_23_GREY_HAWK:        return "FAMILY_23_GREY_HAWK";
                case AmdCpuModel::FAMILY_23_LUCIENNE:         return "FAMILY_23_LUCIENNE";
                case AmdCpuModel::FAMILY_23_MATISSE:          return "FAMILY_23_MATISSE";
                case AmdCpuModel::FAMILY_23_VAN_GOGH:         return "FAMILY_23_VAN_GOGH";

                default: return "UNKNOWN";
            }
        }
        break;

        case CpuFamily::AMD_FAMILY_24:
        {
            switch (model)
            {
                case AmdCpuModel::FAMILY_24_DHYANA:           return "FAMILY_24_DHYANA";

                default: return "UNKNOWN";
            }
        }
        break;

        case CpuFamily::AMD_FAMILY_25:
        {
            switch (model)
            {
                case AmdCpuModel::FAMILY_25_MILAN:            return "FAMILY_25_MILAN";
                case AmdCpuModel::FAMILY_25_CHAGALL:          return "FAMILY_25_CHAGALL";
                case AmdCpuModel::FAMILY_25_VERMEER:          return "FAMILY_25_VERMEER";
                case AmdCpuModel::FAMILY_25_REMBRANT:         return "FAMILY_25_REMBRANT";
                case AmdCpuModel::FAMILY_25_CEZANNE:          return "FAMILY_25_CEZANNE";

                default: return "UNKNOWN";
            }
        }
        break;

        default: return "UNKNOWN";
    }
}



inline const good_Char8* enumToFullString(CpuFamily family, AmdCpuModel model) // TEST: NO
{
    // COMMON_LT((" | family = %u, model = %u", family, model)); // Commented to avoid bad looking logs



    static good_Char8 res[33];

    sprintf(res, "0x%02X (%s)", static_cast<good_U8>(model), enumToString(family, model));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_CPU_LIB_GENERATED_AMDCPUMODEL_H
