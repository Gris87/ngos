#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATUREFLAGS_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATUREFLAGS_H



#include <ngos/types.h>



typedef u32 x_feature_flags;

enum class XFeatureFlag: x_feature_flags
{
    SUPERVISOR = (1ULL << 0),
    ALIGNED    = (1ULL << 1)
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATUREFLAGS_H
