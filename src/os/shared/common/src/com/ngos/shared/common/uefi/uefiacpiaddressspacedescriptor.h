#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefiacpidescriptor.h>
#include <com/ngos/shared/common/uefi/uefiacpiresourcetype.h>



struct UefiAcpiAddressSpaceDescriptor
{
    UefiAcpiDescriptor   descriptor;
    u16                  length;
    UefiAcpiResourceType resourceType;
    u8                   genFlag;
    u8                   specificFlag;
    u64                  addressSpaceGranularity;
    u64                  addressRangeMinimum;
    u64                  addressRangeMaximum;
    u64                  addressTranslationOffset;
    u64                  addressLength;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H
