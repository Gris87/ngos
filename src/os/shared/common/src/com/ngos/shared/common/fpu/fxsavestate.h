#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_FXSAVESTATE_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_FXSAVESTATE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



// The legacy fx SSE/MMX FPU state format, as saved by FXSAVE and restored by the FXRSTOR instructions.
// It's similar to the FSaveState format, but differs in some areas
struct FXSaveState
{
    u16         cwd;        // Control Word
    u16         swd;        // Status Word
    u16         twd;        // Tag Word
    u16         fop;        // Last Instruction Opcode

    union
    {
        struct
        {
            u64 rip;        // Instruction Pointer
            u64 rdp;        // Data Pointer
        };

        struct
        {
            u32 fip;        // FPU IP Offset
            u32 fcs;        // FPU IP Selector
            u32 foo;        // FPU Operand Offset
            u32 fos;        // FPU Operand Selector
        };
    };

    u32         mxcsr;      // MXCSR Register State
    u32         mxcsrMask;  // MXCSR Mask

    // 16 * 8 bytes for each FPU register = 128 bytes
    //
    u64         stack[16];

    // 16 * 16 bytes for each XMM register = 256 bytes
    //
    u64         xmm[16][2];

    u32         __reserved[12];
    u32         __pad[12];
} __attribute__((aligned(16)));



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_FXSAVESTATE_H
