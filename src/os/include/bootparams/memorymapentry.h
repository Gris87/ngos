#ifndef BOOTPARAMS_MEMORYMAPENTRY_H
#define BOOTPARAMS_MEMORYMAPENTRY_H



#include <bootparams/memorymapentrytype.h>
#include <ngos/types.h>



struct MemoryMapEntry
{
    u64                address;
    u64                size;
    MemoryMapEntryType type;
};



#endif // BOOTPARAMS_MEMORYMAPENTRY_H
