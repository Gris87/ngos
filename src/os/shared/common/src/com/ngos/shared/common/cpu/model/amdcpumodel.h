#ifndef COM_NGOS_SHARED_COMMON_CPU_MODEL_AMDCPUMODEL_H
#define COM_NGOS_SHARED_COMMON_CPU_MODEL_AMDCPUMODEL_H



#include <com/ngos/shared/common/cpu/cpufamily.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



// Taken from https://en.wikichip.org/wiki/amd/cpuid
enum class AmdCpuModel: bad_uint8 // Ignore CppEnumVerifier
{
    NONE                     = 0,
    FAMILY_23_NAPLES         = 1,
    FAMILY_23_WHITEHAVEN     = 1,
    FAMILY_23_SUMMIT_RIDGE   = 1,
    FAMILY_23_SNOWY_OWL      = 1,
    FAMILY_23_PINNACLE_RIDGE = 8,
    FAMILY_23_RAVEN_RIDGE    = 17,
    FAMILY_23_ROME           = 32,
    FAMILY_23_MATISSE        = 113
};



inline const char8* enumToString(CpuFamily family, AmdCpuModel model) // TEST: NO
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
                case AmdCpuModel::FAMILY_23_NAPLES:         return "FAMILY_23_NAPLES";
                case AmdCpuModel::FAMILY_23_PINNACLE_RIDGE: return "FAMILY_23_PINNACLE_RIDGE";
                case AmdCpuModel::FAMILY_23_RAVEN_RIDGE:    return "FAMILY_23_RAVEN_RIDGE";
                case AmdCpuModel::FAMILY_23_ROME:           return "FAMILY_23_ROME";
                case AmdCpuModel::FAMILY_23_MATISSE:        return "FAMILY_23_MATISSE";

                default: return "UNKNOWN";
            }
        }
        break;

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(CpuFamily family, AmdCpuModel model) // TEST: NO
{
    // COMMON_LT((" | family = %u, model = %u", family, model)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%02X (%s)", (bad_uint8)model, enumToString(family, model));

    return res;
}



#endif // COM_NGOS_SHARED_COMMON_CPU_MODEL_AMDCPUMODEL_H
