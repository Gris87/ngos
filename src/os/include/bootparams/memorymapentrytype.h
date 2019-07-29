#ifndef BOOTPARAMS_MEMORYMAPENTRYTYPE_H
#define BOOTPARAMS_MEMORYMAPENTRYTYPE_H



#include <ngos/types.h>



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



inline const char8* memoryMapEntryTypeToString(MemoryMapEntryType type) // TEST: NO
{
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



#endif // BOOTPARAMS_MEMORYMAPENTRYTYPE_H
