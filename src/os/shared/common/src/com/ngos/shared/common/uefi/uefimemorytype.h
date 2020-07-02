#ifndef UEFI_UEFIMEMORYTYPE_H
#define UEFI_UEFIMEMORYTYPE_H



#include <common/src/com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <common/src/com/ngos/shared/common/printf/printf.h>
#endif



enum class UefiMemoryType: u32
{
    RESERVED_MEMORY,
    LOADER_CODE,
    LOADER_DATA,
    BOOT_SERVICES_CODE,
    BOOT_SERVICES_DATA,
    RUNTIME_SERVICES_CODE,
    RUNTIME_SERVICES_DATA,
    CONVENTIONAL_MEMORY,
    UNUSABLE_MEMORY,
    ACPI_RECLAIM_MEMORY,
    ACPI_MEMORY_NVS,
    MEMORY_MAPPED_IO,
    MEMORY_MAPPED_IO_PORT_SPACE,
    PAL_CODE,
    PERSISTENT_MEMORY,
    MAXIMUM
};



inline const char8* enumToString(UefiMemoryType type) // TEST: NO
{
    switch (type)
    {
        case UefiMemoryType::RESERVED_MEMORY:             return "RESERVED_MEMORY";
        case UefiMemoryType::LOADER_CODE:                 return "LOADER_CODE";
        case UefiMemoryType::LOADER_DATA:                 return "LOADER_DATA";
        case UefiMemoryType::BOOT_SERVICES_CODE:          return "BOOT_SERVICES_CODE";
        case UefiMemoryType::BOOT_SERVICES_DATA:          return "BOOT_SERVICES_DATA";
        case UefiMemoryType::RUNTIME_SERVICES_CODE:       return "RUNTIME_SERVICES_CODE";
        case UefiMemoryType::RUNTIME_SERVICES_DATA:       return "RUNTIME_SERVICES_DATA";
        case UefiMemoryType::CONVENTIONAL_MEMORY:         return "CONVENTIONAL_MEMORY";
        case UefiMemoryType::UNUSABLE_MEMORY:             return "UNUSABLE_MEMORY";
        case UefiMemoryType::ACPI_RECLAIM_MEMORY:         return "ACPI_RECLAIM_MEMORY";
        case UefiMemoryType::ACPI_MEMORY_NVS:             return "ACPI_MEMORY_NVS";
        case UefiMemoryType::MEMORY_MAPPED_IO:            return "MEMORY_MAPPED_IO";
        case UefiMemoryType::MEMORY_MAPPED_IO_PORT_SPACE: return "MEMORY_MAPPED_IO_PORT_SPACE";
        case UefiMemoryType::PAL_CODE:                    return "PAL_CODE";
        case UefiMemoryType::PERSISTENT_MEMORY:           return "PERSISTENT_MEMORY";
        case UefiMemoryType::MAXIMUM:                     return "MAXIMUM";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(UefiMemoryType type) // TEST: NO
{
    static char8 res[41];

    sprintf(res, "0x%08X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // UEFI_UEFIMEMORYTYPE_H
