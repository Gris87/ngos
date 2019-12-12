#ifndef UEFI_UEFIALLOCATETYPE_H
#define UEFI_UEFIALLOCATETYPE_H



#include <ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile
#include <common/src/bits64/printf/printf.h>
#endif



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



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) || defined(BUILD_TARGET_INSTALLER) // Defined in Makefile



inline const char8* enumToFullString(UefiAllocateType type) // TEST: NO
{
    static char8 res[34];

    sprintf(res, "0x%08X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // UEFI_UEFIALLOCATETYPE_H
