#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRYTYPE_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRYTYPE_H



#include <com/ngos/shared/common/ngos/types.h>

#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile
#include <com/ngos/shared/common/printf/printf.h>
#endif



enum class MemoryMapEntryType: u8
{
    NONE               = 0,
    RAM                = 1,
    ACPI               = 2,
    NVS                = 3,
    PERSISTENT_MEMORY  = 4,
    UNUSABLE           = 5,
    RESERVED           = 6,
    RESERVED_BY_KERNEL = 7
};



inline const char8* enumToString(MemoryMapEntryType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    switch (type)
    {
        case MemoryMapEntryType::NONE:               return "NONE";
        case MemoryMapEntryType::RAM:                return "RAM";
        case MemoryMapEntryType::ACPI:               return "ACPI";
        case MemoryMapEntryType::NVS:                return "NVS";
        case MemoryMapEntryType::PERSISTENT_MEMORY:  return "PERSISTENT_MEMORY";
        case MemoryMapEntryType::UNUSABLE:           return "UNUSABLE";
        case MemoryMapEntryType::RESERVED:           return "RESERVED";
        case MemoryMapEntryType::RESERVED_BY_KERNEL: return "RESERVED_BY_KERNEL";

        default: return "UNKNOWN";
    }
}



#if defined(UEFI_APPLICATION) || defined(BUILD_TARGET_KERNEL) // Defined in Makefile



inline const char8* enumToFullString(MemoryMapEntryType type) // TEST: NO
{
    // COMMON_LT((" | type = %u", type)); // Commented to avoid bad looking logs



    static char8 res[26];

    sprintf(res, "0x%02X (%s)", type, enumToString(type));

    return res;
}



#endif



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRYTYPE_H
