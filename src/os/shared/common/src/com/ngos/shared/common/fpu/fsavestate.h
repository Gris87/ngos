#ifndef COM_NGOS_SHARED_COMMON_FPU_FSAVESTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_FSAVESTATE_H



#include <com/ngos/shared/common/ngos/types.h>



// The legacy x87 FPU state format, as saved by FSAVE and restored by the FRSTOR instructions
struct FSaveState
{
    bad_uint32 cwd;    // FPU Control Word
    bad_uint32 swd;    // FPU Status Word
    bad_uint32 twd;    // FPU Tag Word
    bad_uint32 fip;    // FPU IP Offset
    bad_uint32 fcs;    // FPU IP Selector
    bad_uint32 foo;    // FPU Operand Pointer Offset
    bad_uint32 fos;    // FPU Operand Pointer Selector

    // 10 * 8 bytes for each FPU register = 80 bytes
    bad_uint64 stack[10];
};



#endif // COM_NGOS_SHARED_COMMON_FPU_FSAVESTATE_H
