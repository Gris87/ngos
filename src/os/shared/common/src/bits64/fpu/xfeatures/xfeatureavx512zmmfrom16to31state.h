#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREAVX512ZMMFROM16TO31STATE_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREAVX512ZMMFROM16TO31STATE_H



#include <common/src/bits64/fpu/xfeatures/extendedregisters.h>



// There are 32 * 512-bit AVX-512 registers named ZMM0-ZMM31.
// The low 256 bits of ZMM0-ZMM15 are stored in FXSaveState::xmm and in XFeatureAvxState::hiYmm.
// The high 256 bits of ZMM0-ZMM15 are stored in XFeatureAvx512ZmmFrom0To15State::hiZmm.
//
// The remaining ZMM16-ZMM31 are stored here.
struct XFeatureAvx512ZmmFrom16To31State
{
    Register512Bit zmm[16];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_XFEATURES_XFEATUREAVX512ZMMFROM16TO31STATE_H
