#ifndef COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H
#define COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H



#include <com/ngos/shared/common/bootparams/memorymapentrytype.h>
#include <com/ngos/shared/common/ngos/types.h>



struct MemoryMapEntry
{
    i64                start;
    i64                size;
    MemoryMapEntryType type;



    inline i64 end()
    {
        return start + size;
    }
};



#endif // COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H
