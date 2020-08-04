#ifndef COM_NGOS_KERNEL_OTHER_E820_E820TABLE_H
#define COM_NGOS_KERNEL_OTHER_E820_E820TABLE_H



#include <com/ngos/shared/common/bootparams/memorymapentry.h>
#include <com/ngos/shared/common/ngos/types.h>



#define E820_TABLE_SIZE 128



struct E820Table
{
    u64            count;
    MemoryMapEntry entries[E820_TABLE_SIZE];
};



#endif // COM_NGOS_KERNEL_OTHER_E820_E820TABLE_H
