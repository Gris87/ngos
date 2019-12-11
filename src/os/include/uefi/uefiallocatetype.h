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



inline const char8* enumToString(UefiAllocateType type) // TEST: NO
{
    switch (type)
    {
        case UefiAllocateType::ALLOCATE_ANY_PAGES:   return "ALLOCATE_ANY_PAGES";
        case UefiAllocateType::ALLOCATE_MAX_ADDRESS: return "ALLOCATE_MAX_ADDRESS";
        case UefiAllocateType::ALLOCATE_ADDRESS:     return "ALLOCATE_ADDRESS";
        case UefiAllocateType::MAXIMUM:              return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(UefiAllocateType type) // TEST: NO
{
    switch (type)
    {
        case UefiAllocateType::ALLOCATE_ANY_PAGES:   return "ALLOCATE_ANY_PAGES";
        case UefiAllocateType::ALLOCATE_MAX_ADDRESS: return "ALLOCATE_MAX_ADDRESS";
        case UefiAllocateType::ALLOCATE_ADDRESS:     return "ALLOCATE_ADDRESS";
        case UefiAllocateType::MAXIMUM:              return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#endif // UEFI_UEFIALLOCATETYPE_H
