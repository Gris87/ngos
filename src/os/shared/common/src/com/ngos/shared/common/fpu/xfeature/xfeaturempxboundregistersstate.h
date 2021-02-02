#ifndef COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDREGISTERSSTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDREGISTERSSTATE_H



#include <com/ngos/shared/common/ngos/types.h>



struct MpxBoundRegister
{
    bad_uint64 lowerBound;
    bad_uint64 upperBound;
};



// XFeatureMpxBoundRegistersState is used for 4 MpxBoundRegisters
struct XFeatureMpxBoundRegistersState
{
    MpxBoundRegister boundRegisters[4];
};



#endif // COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREMPXBOUNDREGISTERSSTATE_H
