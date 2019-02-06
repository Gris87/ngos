#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPUSTATE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPUSTATE_H



#include <ngos/types.h>
#include <pagetable/macros.h>
#include <src/bits64/other/fpu/fsavestate.h>
#include <src/bits64/other/fpu/fxsavestate.h>
#include <src/bits64/other/fpu/xsavestate.h>



union FpuState
{
    FSaveState  fsave;
    FXSaveState fxsave;
    XSaveState  xsave;
    u8          __pad[PAGE_SIZE];
};



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_FPU_FPUSTATE_H
