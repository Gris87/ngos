#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURE_XFEATUREAVX512OPMASKSTATE_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURE_XFEATUREAVX512OPMASKSTATE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



// XFeatureAvx512OpmaskState is used for the 8 * 64-bit opmask registers (k0-k7)
struct XFeatureAvx512OpmaskState
{
    u64 opmaskRegisters[8];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURE_XFEATUREAVX512OPMASKSTATE_H
