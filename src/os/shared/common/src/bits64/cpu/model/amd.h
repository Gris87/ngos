#ifndef OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_AMD_H
#define OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_AMD_H



#include <ngos/types.h>



enum class AmdCpuModel: u8 // Ignore CppEnumVerifier
{
    FAMILY_23_NAPLES         = 1,
    FAMILY_23_WHITEHAVEN     = 1,
    FAMILY_23_SUMMIT_RIDGE   = 1,
    FAMILY_23_SNOWY_OWL      = 1,
    FAMILY_23_PINNACLE_RIDGE = 8,
    FAMILY_23_RAVEN_RIDGE    = 17,
    FAMILY_23_ROME           = 32,
    FAMILY_23_MATISSE        = 113
};



inline const char* amdCpuModelToString(AmdCpuModel model) // TEST: NO
{
    // COMMON_LT((" | model = %u", model)); // Commented to avoid bad looking logs



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



#endif // OS_SHARED_COMMON_SRC_BITS64_CPU_MODEL_AMD_H
