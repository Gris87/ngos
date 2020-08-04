#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFICPUPHYSICALLOCATION_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFICPUPHYSICALLOCATION_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiCpuPhysicalLocation
{
    u32 package;
    u32 core;
    u32 thread;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFICPUPHYSICALLOCATION_H
