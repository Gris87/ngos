#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_FPUSTATE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_FPUSTATE_H



#include <common/src/com/ngos/shared/common/fpu/fsavestate.h>
#include <common/src/com/ngos/shared/common/fpu/fxsavestate.h>
#include <common/src/com/ngos/shared/common/fpu/xsavestate.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/pagetable/macros.h>



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_FPUSTATE_H
