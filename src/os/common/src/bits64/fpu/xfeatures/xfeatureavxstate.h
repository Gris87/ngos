#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREAVXSTATE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREAVXSTATE_H



#include <src/bits64/other/fpu/xfeatures/extendedregisters.h>



// There are 16 * 256-bit AVX registers named YMM0-YMM15.
// The low 128 bits are aliased to the 16 SSE registers (XMM0-XMM15)
// and are stored in FXSaveState::xmm in the "legacy" area.
//
// The high 128 bits are stored here.
struct XFeatureAvxState
{
    Register128Bit hiYmm[16];
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XFEATURES_XFEATUREAVXSTATE_H
