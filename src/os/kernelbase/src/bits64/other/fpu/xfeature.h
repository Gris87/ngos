#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURE_H



#include <ngos/types.h>



#define XFEATURE_MASK_FPU_SSE    ((x_features)XFeature::FPU | (x_features)XFeature::SSE)
#define XFEATURE_MASK_SUPERVISOR ((x_features)XFeature::PT)



typedef u64 x_features;

enum class XFeature: x_features
{
    FPU                 = (1ULL << 0),
    SSE                 = (1ULL << 1),
    AVX                 = (1ULL << 2),
    MPX_BNDREGS         = (1ULL << 3),
    MPX_BNDCSR          = (1ULL << 4),
    AVX512_OPMASK       = (1ULL << 5),
    AVX512_ZMM_HI_256   = (1ULL << 6),
    AVX512_HI_16_ZMM    = (1ULL << 7),
    PT                  = (1ULL << 8),
    PKRU                = (1ULL << 9)
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURE_H
