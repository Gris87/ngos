#ifndef OS_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREAVX512OPMASKSTATE_H
#define OS_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREAVX512OPMASKSTATE_H



#include <ngos/types.h>



// XFeatureAvx512OpmaskState is used for the 8 * 64-bit opmask registers (k0-k7)
struct XFeatureAvx512OpmaskState
{
    u64 opmaskRegisters[8];
};



#endif // OS_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREAVX512OPMASKSTATE_H