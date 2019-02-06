#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREMPXBOUNDREGISTERSSTATE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREMPXBOUNDREGISTERSSTATE_H



#include <ngos/types.h>



struct MpxBoundRegister
{
    u64 lowerBound;
    u64 upperBound;
};



// XFeatureMpxBoundRegistersState is used for 4 MpxBoundRegisters
struct XFeatureMpxBoundRegistersState
{
    MpxBoundRegister boundRegisters[4];
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREMPXBOUNDREGISTERSSTATE_H
