#ifndef COM_NGOS_SHARED_COMMON_FPU_XSAVESTATE_H
#define COM_NGOS_SHARED_COMMON_FPU_XSAVESTATE_H



#include <com/ngos/shared/common/fpu/fxsavestate.h>
#include <com/ngos/shared/common/fpu/xstateheader.h>
#include <com/ngos/shared/common/ngos/types.h>



struct XSaveState
{
    FXSaveState  fxsave;
    XStateHeader header;
    u8           extendedStateArea[0];
} __attribute__((packed, aligned(64)));



#endif // COM_NGOS_SHARED_COMMON_FPU_XSAVESTATE_H
