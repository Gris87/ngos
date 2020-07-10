#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H



#include <com/ngos/shared/common/ngos/types.h>



struct UefiAcpiAddressSpaceDescriptor
{
    u8  desc;
    u16 len;
    u8  resType;
    u8  genFlag;
    u8  specificFlag;
    u64 addrSpaceGranularity;
    u64 addrRangeMin;
    u64 addrRangeMax;
    u64 addrTranslationOffset;
    u64 addrLen;
} __attribute__((packed));



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIACPIADDRESSSPACEDESCRIPTOR_H
