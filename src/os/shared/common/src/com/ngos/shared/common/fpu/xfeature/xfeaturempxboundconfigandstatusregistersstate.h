#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H



#include <com/ngos/shared/common/ngos/types.h>



// XFeatureMpxBoundConfigAndStatusRegistersState is used for the 64-bit
// user-mode MPX config register and the 64-bit MPX status register
struct XFeatureMpxBoundConfigAndStatusRegistersState
{
    u64 configRegister;
    u64 statusRegister;
    u8  __pad[48];
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDCONFIGANDSTATUSREGISTERSSTATE_H
