#ifndef BOOTPARAMS_MEMORYMAPENTRYTYPE_H
#define BOOTPARAMS_MEMORYMAPENTRYTYPE_H



#include <ngos/types.h>



enum class MemoryMapEntryType: u8
{
    RAM,
    ACPI,
    NVS,
    PERSISTENT_MEMORY,
    UNUSABLE,
    RESERVED,
    RESERVED_BY_KERNEL
};



inline const char* memoryMapEntryTypeToString(MemoryMapEntryType type) // TEST: NO
{
    switch (type)
    {
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
