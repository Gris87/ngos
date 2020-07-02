#ifndef KERNEL_SRC_COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
#define KERNEL_SRC_COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H



#include <ngos/status.h>
#include <ngos/types.h>



NgosStatus addDynamicIdentityMap(u64 start, u64 end);
NgosStatus clearDynamicIdentityMap(u64 start, u64 end);



#endif // KERNEL_SRC_COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
