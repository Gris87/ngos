#ifndef COM_NGOS_SHARED_COMMON_UEFI_UEFIALLOCATETYPE_H
#define COM_NGOS_SHARED_COMMON_UEFI_UEFIALLOCATETYPE_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
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
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case UefiAllocateType::ALLOCATE_ANY_PAGES:   return "ALLOCATE_ANY_PAGES";
        case UefiAllocateType::ALLOCATE_MAX_ADDRESS: return "ALLOCATE_MAX_ADDRESS";
        case UefiAllocateType::ALLOCATE_ADDRESS:     return "ALLOCATE_ADDRESS";
        case UefiAllocateType::MAXIMUM:              return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiAllocateType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[34];

    sprintf(res, "0x%08X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // COM_NGOS_SHARED_COMMON_UEFI_UEFIALLOCATETYPE_H
