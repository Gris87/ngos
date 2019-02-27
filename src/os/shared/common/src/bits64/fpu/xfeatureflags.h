#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATUREFLAGS_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATUREFLAGS_H



#include <ngos/types.h>



typedef u32 x_feature_flags;

enum class XFeatureFlag: x_feature_flags
{
    SUPERVISOR = (1ULL << 0),
    ALIGNED    = (1ULL << 1)
};



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATUREFLAGS_H
