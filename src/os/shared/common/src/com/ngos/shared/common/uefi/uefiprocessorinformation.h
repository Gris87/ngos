#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPROCESSORINFORMATION_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPROCESSORINFORMATION_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/ueficpuphysicallocation.h>
#include <com/ngos/shared/common/uefi/uefiprocessorinformationstatusflags.h>



struct UefiProcessorInformation
{
    u64                                 processorId;
    UefiProcessorInformationStatusFlags status;
    UefiCpuPhysicalLocation             location;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIPROCESSORINFORMATION_H
