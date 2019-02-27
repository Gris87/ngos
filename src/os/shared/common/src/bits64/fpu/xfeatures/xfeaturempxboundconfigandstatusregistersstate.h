#ifndef OS_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H
#define OS_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H



#include <ngos/types.h>



// XFeatureMpxBoundConfigAndStatusRegistersState is used for the 64-bit
// user-mode MPX config register and the 64-bit MPX status register
struct XFeatureMpxBoundConfigAndStatusRegistersState
{
    u64 configRegister;
    u64 statusRegister;
    u8  __pad[48];
};



#endif // OS_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H
