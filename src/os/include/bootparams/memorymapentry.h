#ifndef BOOTPARAMS_MEMORYMAPENTRY_H
#define BOOTPARAMS_MEMORYMAPENTRY_H



#include <bootparams/memorymapentrytype.h>
#include <ngos/types.h>



struct MemoryMapEntry
{
    u64                start;
    u64                size;
    MemoryMapEntryType type;



    inline u64 end()
    {
        return start + size;
    }
};



#endif // BOOTPARAMS_MEMORYMAPENTRY_H
