#ifndef COM_NGOS_SHARED_COMMON_FPU_FSAVESTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_FSAVESTATE_H



#include <com/ngos/shared/common/ngos/types.h>



// The legacy x87 FPU state format, as saved by FSAVE and restored by the FRSTOR instructions
struct FSaveState
{
    u32 cwd;    // FPU Control Word
    u32 swd;    // FPU Status Word
    u32 twd;    // FPU Tag Word
    u32 fip;    // FPU IP Offset
    u32 fcs;    // FPU IP Selector
    u32 foo;    // FPU Operand Pointer Offset
    u32 fos;    // FPU Operand Pointer Selector

    // 10 * 8 bytes for each FPU register = 80 bytes
    u64 stack[10];
};



#endif // COM_NGOS_SHARED_COMMON_FPU_FSAVESTATE_H
