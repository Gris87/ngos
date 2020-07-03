#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XSAVESTATE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XSAVESTATE_H



#include <com/ngos/shared/common/fpu/fxsavestate.h>
#include <com/ngos/shared/common/fpu/xstateheader.h>
#include <com/ngos/shared/common/ngos/types.h>



struct XSaveState
{
    FXSaveState  fxsave;
    XStateHeader header;
    u8           extendedStateArea[0];
} __attribute__((packed, aligned(64)));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_FPU_XSAVESTATE_H
