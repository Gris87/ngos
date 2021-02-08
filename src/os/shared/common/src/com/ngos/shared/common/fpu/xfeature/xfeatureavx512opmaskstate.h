#ifndef COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREAVX512OPMASKSTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREAVX512OPMASKSTATE_H



#include <com/ngos/shared/common/ngos/types.h>



// XFeatureAvx512OpmaskState is used for the 8 * 64-bit opmask registers (k0-k7)
struct XFeatureAvx512OpmaskState
{
    u64 opmaskRegisters[8];
};



#endif // COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREAVX512OPMASKSTATE_H
