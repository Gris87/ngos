#ifndef UEFI_UEFIALLOCATETYPE_H
#define UEFI_UEFIALLOCATETYPE_H



#include <ngos/types.h>



enum class UefiAllocateType: u32
{
    ALLOCATE_ANY_PAGES,
    ALLOCATE_MAX_ADDRESS,
    ALLOCATE_ADDRESS,
    MAXIMUM
};



#endif // UEFI_UEFIALLOCATETYPE_H
