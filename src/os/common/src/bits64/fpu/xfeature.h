#ifndef OS_COMMON_SRC_BITS64_FPU_XFEATURE_H
#define OS_COMMON_SRC_BITS64_FPU_XFEATURE_H



#include <ngos/types.h>



#define XFEATURE_FPU                                   0
#define XFEATURE_SSE                                   1
#define XFEATURE_AVX                                   2
#define XFEATURE_MPX_BOUND_REGISTERS                   3
#define XFEATURE_MPX_BOUND_CONFIG_AND_STATUS_REGISTERS 4
#define XFEATURE_AVX512_OPMASK                         5
#define XFEATURE_AVX512_ZMM_FROM_0_TO_15               6
#define XFEATURE_AVX512_ZMM_FROM_16_TO_31              7
#define XFEATURE_PT                                    8
#define XFEATURE_PKRU                                  9
#define XFEATURE_MAX                                   10

#define XFEATURE_MASK_FPU_SSE    ((x_features)XFeature::FPU | (x_features)XFeature::SSE)
#define XFEATURE_MASK_SUPERVISOR ((x_features)XFeature::PT)



typedef u64 x_features;

enum class XFeature: x_features
{
    FPU                                   = (1ULL << XFEATURE_FPU),
    SSE                                   = (1ULL << XFEATURE_SSE),
    AVX                                   = (1ULL << XFEATURE_AVX),
    MPX_BOUND_REGISTERS                   = (1ULL << XFEATURE_MPX_BOUND_REGISTERS),
    MPX_BOUND_CONFIG_AND_STATUS_REGISTERS = (1ULL << XFEATURE_MPX_BOUND_CONFIG_AND_STATUS_REGISTERS),
    AVX512_OPMASK                         = (1ULL << XFEATURE_AVX512_OPMASK),
    AVX512_ZMM_FROM_0_TO_15               = (1ULL << XFEATURE_AVX512_ZMM_FROM_0_TO_15),
    AVX512_ZMM_FROM_16_TO_31              = (1ULL << XFEATURE_AVX512_ZMM_FROM_16_TO_31),
    PT                                    = (1ULL << XFEATURE_PT),
    PKRU                                  = (1ULL << XFEATURE_PKRU)
};



#endif // OS_COMMON_SRC_BITS64_FPU_XFEATURE_H
