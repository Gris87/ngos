#ifndef COM_NGOS_SHARED_COMMON_FPU_FXSAVESTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_FXSAVESTATE_H



#include <com/ngos/shared/common/ngos/types.h>



// The legacy fx SSE/MMX FPU state format, as saved by FXSAVE and restored by the FXRSTOR instructions.
// It's similar to the FSaveState format, but differs in some areas
struct FXSaveState
{
    bad_uint16         cwd;        // Control Word
    bad_uint16         swd;        // Status Word
    bad_uint16         twd;        // Tag Word
    bad_uint16         fop;        // Last Instruction Opcode

    union
    {
        struct
        {
            bad_uint64 rip;        // Instruction Pointer
            bad_uint64 rdp;        // Data Pointer
        };

        struct
        {
            bad_uint32 fip;        // FPU IP Offset
            bad_uint32 fcs;        // FPU IP Selector
            bad_uint32 foo;        // FPU Operand Offset
            bad_uint32 fos;        // FPU Operand Selector
        };
    };

    bad_uint32         mxcsr;      // MXCSR Register State
    bad_uint32         mxcsrMask;  // MXCSR Mask

    // 16 * 8 bytes for each FPU register = 128 bytes
    //
    bad_uint64         stack[16];

    // 16 * 16 bytes for each XMM register = 256 bytes
    //
    bad_uint64         xmm[16][2];

    bad_uint32         __reserved[12];
    bad_uint32         __pad[12];
} __attribute__((aligned(16)));



#endif // COM_NGOS_SHARED_COMMON_FPU_FXSAVESTATE_H
