#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/uefi/uefiacpidescriptor.h>
#include <com/ngos/shared/common/uefi/uefiacpiresourcetype.h>



struct UefiAcpiAddressSpaceDescriptor
{
    UefiAcpiDescriptor   descriptor;
    bad_uint16                  length;
    UefiAcpiResourceType resourceType;
    bad_uint8                   genFlag;
    bad_uint8                   specificFlag;
    bad_uint64                  addressSpaceGranularity;
    bad_uint64                  addressRangeMinimum;
    bad_uint64                  addressRangeMaximum;
    bad_uint64                  addressTranslationOffset;
    bad_uint64                  addressLength;
} __attribute__((packed));



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H
