#ifndef COM_NGOS_SHARED_COMMON_FPU_FPUSTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_FPUSTATE_H



#include <com/ngos/shared/common/fpu/fsavestate.h>
#include <com/ngos/shared/common/fpu/fxsavestate.h>
#include <com/ngos/shared/common/fpu/xsavestate.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pagetable/macros.h>



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



#endif // COM_NGOS_SHARED_COMMON_FPU_FPUSTATE_H
