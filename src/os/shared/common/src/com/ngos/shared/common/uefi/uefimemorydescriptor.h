#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H



#include <com/ngos/shared/common/uefi/types.h>
#include <com/ngos/shared/common/uefi/uefimemorytype.h>



struct UefiMemoryDescriptor
{
    UefiMemoryType type;
    u32            __pad;
    u64            physicalStart;
    u64            virtualStart;
    u64            numberOfPages;
    u64            attribute;
};



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIMEMORYDESCRIPTOR_H
