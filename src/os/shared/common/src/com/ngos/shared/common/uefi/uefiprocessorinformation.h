#ifndef UEFI_UEFIPROCESSORINFORMATION_H
#define UEFI_UEFIPROCESSORINFORMATION_H



#include <common/src/com/ngos/shared/common/ngos/types.h>
#include <common/src/com/ngos/shared/common/uefi/ueficpuphysicallocation.h>
#include <common/src/com/ngos/shared/common/uefi/uefiprocessorinformationstatusflags.h>



struct UefiProcessorInformation
{
    u64                                 processorId;
    UefiProcessorInformationStatusFlags status;
    UefiCpuPhysicalLocation             location;
};



#endif // UEFI_UEFIPROCESSORINFORMATION_H
