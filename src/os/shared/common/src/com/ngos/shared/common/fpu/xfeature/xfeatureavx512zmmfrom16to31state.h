#ifndef COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREAVX512ZMMFROM16TO31STATE_H
#define COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREAVX512ZMMFROM16TO31STATE_H



#include <com/ngos/shared/common/fpu/xfeature/extendedregisters.h>



// There are 32 * 512-bit AVX-512 registers named ZMM0-ZMM31.
// The low 256 bits of ZMM0-ZMM15 are stored in FXSaveState::xmm and in XFeatureAvxState::hiYmm.
// The high 256 bits of ZMM0-ZMM15 are stored in XFeatureAvx512ZmmFrom0To15State::hiZmm.
//
// The remaining ZMM16-ZMM31 are stored here.
struct XFeatureAvx512ZmmFrom16To31State
{
    Register512Bit zmm[16];
};



#endif // COM_NGOS_SHARED_COMMON_FPU_XFEATURE_XFEATUREAVX512ZMMFROM16TO31STATE_H
