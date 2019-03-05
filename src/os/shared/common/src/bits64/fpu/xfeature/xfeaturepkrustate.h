#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREPKRUSTATE_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREPKRUSTATE_H



#include <ngos/types.h>



// XFeaturePkruState is used for 32-bit PKRU register
struct XFeaturePkruState
{
    u32 pkru;
    u32 __pad;
};



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREPKRUSTATE_H
