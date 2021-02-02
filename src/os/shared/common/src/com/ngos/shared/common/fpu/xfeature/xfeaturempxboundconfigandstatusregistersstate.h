#ifndef COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H



#include <com/ngos/shared/common/ngos/types.h>



// XFeatureMpxBoundConfigAndStatusRegistersState is used for the 64-bit
// user-mode MPX config register and the 64-bit MPX status register
struct XFeatureMpxBoundConfigAndStatusRegistersState
{
    bad_uint64 configRegister;
    bad_uint64 statusRegister;
    bad_uint8  __pad[48];
};



#endif // COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H
