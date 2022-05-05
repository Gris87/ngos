#ifndef COM_NGOS_SHARED_COMMON_CPU_MODEL_AMDCPUMODEL_H                                                                                                                                                   // Colorize: green
#define COM_NGOS_SHARED_COMMON_CPU_MODEL_AMDCPUMODEL_H                                                                                                                                                   // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#include <com/ngos/shared/common/cpu/lib/cpufamily.h>                                                                                                                                                    // Colorize: green
#include <com/ngos/shared/common/log/assert.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/log/log.h>                                                                                                                                                              // Colorize: green
#include <com/ngos/shared/common/ngos/types.h>                                                                                                                                                           // Colorize: green
#include <com/ngos/shared/common/printf/printf.h>                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
// Taken from https://en.wikichip.org/wiki/amd/cpuid                                                                                                                                                     // Colorize: green
enum class AmdCpuModel: good_U8 // Ignore CppEnumVerifier // TODO: Generate it                                                                                                                           // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    NONE                       = 0,                                                                                                                                                                      // Colorize: green
    FAMILY_23_NAPLES           = 1,                                                                                                                                                                      // Colorize: green
    FAMILY_23_WHITEHAVEN       = 1,                                                                                                                                                                      // Colorize: green
    FAMILY_23_SUMMIT_RIDGE     = 1,                                                                                                                                                                      // Colorize: green
    FAMILY_23_SNOWY_OWL        = 1,                                                                                                                                                                      // Colorize: green
    FAMILY_23_COLFAX           = 8,                                                                                                                                                                      // Colorize: green
    FAMILY_23_PINNACLE_RIDGE   = 8,                                                                                                                                                                      // Colorize: green
    FAMILY_23_RAVEN_RIDGE      = 17,                                                                                                                                                                     // Colorize: green
    FAMILY_23_GREAT_HORNED_OWL = 17,                                                                                                                                                                     // Colorize: green
    FAMILY_23_PICASSO          = 24,                                                                                                                                                                     // Colorize: green
    FAMILY_23_BANDED_KESTREL   = 24,                                                                                                                                                                     // Colorize: green
    FAMILY_23_DALI             = 32,                                                                                                                                                                     // Colorize: green
    FAMILY_23_ROME             = 49,                                                                                                                                                                     // Colorize: green
    FAMILY_23_CASTLE_PEAK      = 49,                                                                                                                                                                     // Colorize: green
    FAMILY_23_XBOX_SERIES_X    = 71,                                                                                                                                                                     // Colorize: green
    FAMILY_23_RENOIR           = 96,                                                                                                                                                                     // Colorize: green
    FAMILY_23_GREY_HAWK        = 96,                                                                                                                                                                     // Colorize: green
    FAMILY_23_LUCIENNE         = 104,                                                                                                                                                                    // Colorize: green
    FAMILY_23_MATISSE          = 113,                                                                                                                                                                    // Colorize: green
    FAMILY_23_VAN_GOGH         = 144                                                                                                                                                                     // Colorize: green
};                                                                                                                                                                                                       // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const good_Char8* enumToString(CpuFamily family, AmdCpuModel model) // TEST: NO                                                                                                                   // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | family = %u, model = %u", family, model)); // Commented to avoid bad looking logs                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    if (model == AmdCpuModel::NONE)                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        return "NONE";                                                                                                                                                                                   // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    switch (family)                                                                                                                                                                                      // Colorize: green
    {                                                                                                                                                                                                    // Colorize: green
        case CpuFamily::AMD_FAMILY_23:                                                                                                                                                                   // Colorize: green
        {                                                                                                                                                                                                // Colorize: green
            switch (model)                                                                                                                                                                               // Colorize: green
            {                                                                                                                                                                                            // Colorize: green
                case AmdCpuModel::FAMILY_23_NAPLES:        return "FAMILY_23_NAPLES";                                                                                                                    // Colorize: green
                case AmdCpuModel::FAMILY_23_COLFAX:        return "FAMILY_23_COLFAX";                                                                                                                    // Colorize: green
                case AmdCpuModel::FAMILY_23_RAVEN_RIDGE:   return "FAMILY_23_RAVEN_RIDGE";                                                                                                               // Colorize: green
                case AmdCpuModel::FAMILY_23_PICASSO:       return "FAMILY_23_PICASSO";                                                                                                                   // Colorize: green
                case AmdCpuModel::FAMILY_23_DALI:          return "FAMILY_23_DALI";                                                                                                                      // Colorize: green
                case AmdCpuModel::FAMILY_23_ROME:          return "FAMILY_23_ROME";                                                                                                                      // Colorize: green
                case AmdCpuModel::FAMILY_23_XBOX_SERIES_X: return "FAMILY_23_XBOX_SERIES_X";                                                                                                             // Colorize: green
                case AmdCpuModel::FAMILY_23_RENOIR:        return "FAMILY_23_RENOIR";                                                                                                                    // Colorize: green
                case AmdCpuModel::FAMILY_23_LUCIENNE:      return "FAMILY_23_LUCIENNE";                                                                                                                  // Colorize: green
                case AmdCpuModel::FAMILY_23_MATISSE:       return "FAMILY_23_MATISSE";                                                                                                                   // Colorize: green
                case AmdCpuModel::FAMILY_23_VAN_GOGH:      return "FAMILY_23_VAN_GOGH";                                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                default: return "UNKNOWN";                                                                                                                                                               // Colorize: green
            }                                                                                                                                                                                            // Colorize: green
        }                                                                                                                                                                                                // Colorize: green
        break;                                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
        default: return "UNKNOWN";                                                                                                                                                                       // Colorize: green
    }                                                                                                                                                                                                    // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
inline const good_Char8* enumToFullString(CpuFamily family, AmdCpuModel model) // TEST: NO                                                                                                               // Colorize: green
{                                                                                                                                                                                                        // Colorize: green
    // COMMON_LT((" | family = %u, model = %u", family, model)); // Commented to avoid bad looking logs                                                                                                  // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    static good_Char8 res[34];                                                                                                                                                                           // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    sprintf(res, "0x%02X (%s)", static_cast<good_U8>(model), enumToString(family, model)); // TODO: Remove cast like this everywhere                                                                     // Colorize: green
                                                                                                                                                                                                         // Colorize: green
    return res;                                                                                                                                                                                          // Colorize: green
}                                                                                                                                                                                                        // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
                                                                                                                                                                                                         // Colorize: green
#endif // COM_NGOS_SHARED_COMMON_CPU_MODEL_AMDCPUMODEL_H                                                                                                                                                 // Colorize: green