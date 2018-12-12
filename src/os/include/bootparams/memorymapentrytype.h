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
    RESERVED
};



#endif // BOOTPARAMS_MEMORYMAPENTRYTYPE_H
