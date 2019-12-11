#ifndef UEFI_UEFIPROCESSORINFORMATION_H
#define UEFI_UEFIPROCESSORINFORMATION_H



#include <ngos/types.h>
#include <uefi/ueficpuphysicallocation.h>
#include <uefi/uefiprocessorinformationstatusflags.h>



struct UefiProcessorInformation
{
    u64                                 processorId;
    UefiProcessorInformationStatusFlags status;
    UefiCpuPhysicalLocation             location;
};



#endif // UEFI_UEFIPROCESSORINFORMATION_H
