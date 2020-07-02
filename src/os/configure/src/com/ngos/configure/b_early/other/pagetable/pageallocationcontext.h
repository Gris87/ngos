#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGEALLOCATIONCONTEXT_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGEALLOCATIONCONTEXT_H



#include <common/src/com/ngos/shared/common/ngos/types.h>



struct PageAllocationContext
{
    u8  *buffer;
    u64  size;
    u64  position;
};



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGEALLOCATIONCONTEXT_H
