#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_E820_E820TABLE_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_E820_E820TABLE_H



#include <common/src/com/ngos/shared/common/bootparams/memorymapentry.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



#define E820_TABLE_SIZE 128



struct E820Table
{
    u64            count;
    MemoryMapEntry entries[E820_TABLE_SIZE];
};



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_E820_E820TABLE_H
