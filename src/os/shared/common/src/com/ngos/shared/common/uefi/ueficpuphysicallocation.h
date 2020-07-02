#ifndef UEFI_UEFICPUPHYSICALLOCATION_H
#define UEFI_UEFICPUPHYSICALLOCATION_H



#include <ngos/types.h>



struct UefiCpuPhysicalLocation
{
    u32 package;
    u32 core;
    u32 thread;
};



#endif // UEFI_UEFICPUPHYSICALLOCATION_H
