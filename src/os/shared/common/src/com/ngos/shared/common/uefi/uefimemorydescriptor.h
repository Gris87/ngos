#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H



#include <common/src/com/ngos/shared/common/uefi/types.h>
#include <common/src/com/ngos/shared/common/uefi/uefimemorytype.h>



struct UefiMemoryDescriptor
{
    UefiMemoryType type;
    u32            __pad;
    u64            physicalStart;
    u64            virtualStart;
    u64            numberOfPages;
    u64            attribute;
};



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H
