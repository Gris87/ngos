#ifndef OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H
#define OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H



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



#endif // OS_SHARED_COMMON_SRC_COM_NGOS_SHARED_COMMON_BOOTPARAMS_MEMORYMAPENTRY_H
