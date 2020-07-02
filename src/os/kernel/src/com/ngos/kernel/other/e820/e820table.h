#ifndef OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_E820_E820TABLE_H
#define OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_E820_E820TABLE_H



#include <bootparams/memorymapentry.h>
#include <ngos/types.h>



#define E820_TABLE_SIZE 128



struct E820Table
{
    u64            count;
    MemoryMapEntry entries[E820_TABLE_SIZE];
};



#endif // OS_SHARED_KERNELBASE_SRC_BITS64_OTHER_E820_E820TABLE_H
