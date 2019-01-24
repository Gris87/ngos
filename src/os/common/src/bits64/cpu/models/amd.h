#ifndef OS_COMMON_SRC_BITS64_CPU_MODELS_AMD_H
#define OS_COMMON_SRC_BITS64_CPU_MODELS_AMD_H



#include <ngos/types.h>



#define AMD_FAMILY_23 23



enum class AmdCpuModel: u8
{
    FAMILY_23_NAPLES         = 1,
    FAMILY_23_WHITEHAVEN     = 1,
    FAMILY_23_SUMMIT_RIDGE   = 1,
    FAMILY_23_SNOWY_OWL      = 1,
    FAMILY_23_PINNACLE_RIDGE = 8,
    FAMILY_23_RAVEN_RIDGE    = 17,
    FAMILY_23_ROME           = 32
};



#endif // OS_COMMON_SRC_BITS64_CPU_MODELS_AMD_H
