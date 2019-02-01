#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREPKRUSTATE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREPKRUSTATE_H



#include <ngos/types.h>



// XFeaturePkruState is used for 32-bit PKRU register
struct XFeaturePkruState
{
    u32 pkru;
    u32 __pad;
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREPKRUSTATE_H
