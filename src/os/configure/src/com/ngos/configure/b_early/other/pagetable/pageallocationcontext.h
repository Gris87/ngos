#ifndef COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGEALLOCATIONCONTEXT_H
#define COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGEALLOCATIONCONTEXT_H



#include <com/ngos/shared/common/ngos/types.h>



struct PageAllocationContext
{
    bad_uint8  *buffer;
    bad_uint64  size;
    bad_uint64  position;
};



#endif // COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGEALLOCATIONCONTEXT_H
