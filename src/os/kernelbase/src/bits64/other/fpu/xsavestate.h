#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XSAVESTATE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XSAVESTATE_H



#include <ngos/types.h>

#include "src/bits64/other/fpu/fxsavestate.h"
#include "src/bits64/other/fpu/xstateheader.h"



struct XSaveState
{
    FXSaveState  fxsave;
    XStateHeader header;
    u8           extendedStateArea[0];
} __attribute__((packed, aligned(64)));



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_XSAVESTATE_H
