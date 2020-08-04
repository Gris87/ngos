#ifndef COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H
#define COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H



#include <com/ngos/shared/common/bootparams/memorymapentrytype.h>
#include <com/ngos/shared/common/ngos/types.h>



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



#endif // COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H
