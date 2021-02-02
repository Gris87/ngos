#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFICPUPHYSICALLOCATION_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFICPUPHYSICALLOCATION_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiCpuPhysicalLocation
{
    bad_uint32 package;
    bad_uint32 core;
    bad_uint32 thread;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFICPUPHYSICALLOCATION_H
