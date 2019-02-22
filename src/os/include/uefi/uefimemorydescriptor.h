#ifndef UEFI_UEFIMEMORYDESCRIPTOR_H
#define UEFI_UEFIMEMORYDESCRIPTOR_H



#include <uefi/types.h>



struct UefiMemoryDescriptor
{
    u32 type;
    u32 __pad;
    u64 physicalStart;
    u64 virtualStart;
    u64 numberOfPages;
    u64 attribute;
};



#endif // UEFI_UEFIMEMORYDESCRIPTOR_H
