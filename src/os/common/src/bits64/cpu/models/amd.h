#ifndef OS_COMMON_SRC_BITS64_CPU_MODELS_AMD_H
#define OS_COMMON_SRC_BITS64_CPU_MODELS_AMD_H



#include <ngos/types.h>



#define AMD_FAMILY_23 23



enum class AmdCpuModel: u8
{
    NAPLES         = 1,
    WHITEHAVEN     = 1,
    SUMMIT_RIDGE   = 1,
    SNOWY_OWL      = 1,
    PINNACLE_RIDGE = 8,
    RAVEN_RIDGE    = 17,
    ROME           = 32
};



#endif // OS_COMMON_SRC_BITS64_CPU_MODELS_AMD_H
