#ifndef BOOTPARAMS_MEMORYMAPENTRY_H
#define BOOTPARAMS_MEMORYMAPENTRY_H



#include <common/src/com/ngos/shared/common/bootparams/memorymapentrytype.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



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
