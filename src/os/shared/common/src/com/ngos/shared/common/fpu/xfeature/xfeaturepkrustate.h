#ifndef COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREPKRUSTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREPKRUSTATE_H



#include <com/ngos/shared/common/ngos/types.h>



// XFeaturePkruState is used for 32-bit PKRU register
struct XFeaturePkruState
{
    u32 pkru;
    u32 __pad;
};



#endif // COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREPKRUSTATE_H
