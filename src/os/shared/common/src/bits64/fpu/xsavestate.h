#ifndef OS_COMMON_SRC_BITS64_FPU_XSAVESTATE_H
#define OS_COMMON_SRC_BITS64_FPU_XSAVESTATE_H



#include <ngos/types.h>
#include <src/bits64/fpu/fxsavestate.h>
#include <src/bits64/fpu/xstateheader.h>



struct XSaveState
{
    FXSaveState  fxsave;
    XStateHeader header;
    u8           extendedStateArea[0];
} __attribute__((packed, aligned(64)));



#endif // OS_COMMON_SRC_BITS64_FPU_XSAVESTATE_H
