#ifndef UEFI_UEFIMEMORYDESCRIPTOR_H
#define UEFI_UEFIMEMORYDESCRIPTOR_H



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



#endif // UEFI_UEFIMEMORYDESCRIPTOR_H
