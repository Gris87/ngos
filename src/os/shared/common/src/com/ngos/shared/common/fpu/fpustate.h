#ifndef OS_SHARED_COMMON_SRC_BITS64_FPU_FPUSTATE_H
#define OS_SHARED_COMMON_SRC_BITS64_FPU_FPUSTATE_H



#include <common/src/bits64/fpu/fsavestate.h>
#include <common/src/bits64/fpu/fxsavestate.h>
#include <common/src/bits64/fpu/xsavestate.h>
#include <ngos/types.h>
#include <pagetable/macros.h>



union FpuState
{
    FpuState()
        : __pad()
    {
        // Nothing
    }

    FSaveState  fsave;
    FXSaveState fxsave;
    XSaveState  xsave;
    u8          __pad[PAGE_SIZE];
};



#endif // OS_SHARED_COMMON_SRC_BITS64_FPU_FPUSTATE_H
