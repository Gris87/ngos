#ifndef OS_COMMON_SRC_BITS64_FPU_FPUSTATE_H
#define OS_COMMON_SRC_BITS64_FPU_FPUSTATE_H



#include <ngos/types.h>
#include <pagetable/macros.h>
#include <src/bits64/fpu/fsavestate.h>
#include <src/bits64/fpu/fxsavestate.h>
#include <src/bits64/fpu/xsavestate.h>



union FpuState
{
    FSaveState  fsave;
    FXSaveState fxsave;
    XSaveState  xsave;
    u8          __pad[PAGE_SIZE];
};



#endif // OS_COMMON_SRC_BITS64_FPU_FPUSTATE_H
