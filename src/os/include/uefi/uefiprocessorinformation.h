#ifndef UEFI_UEFIPROCESSORINFORMATION_H
#define UEFI_UEFIPROCESSORINFORMATION_H



#include <ngos/types.h>
#include <uefi/ueficpuphysicallocation.h>
#include <uefi/uefiprocessorinformationstatusflags.h>



struct UefiProcessorInformation
{
    u64                                     processorId;
    uefi_processor_information_status_flags status;
    UefiCpuPhysicalLocation                 location;
};



#endif // UEFI_UEFIPROCESSORINFORMATION_H
