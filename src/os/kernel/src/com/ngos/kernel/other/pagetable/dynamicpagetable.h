#ifndef COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
#define COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



NgosStatus addDynamicIdentityMap(u64 start, u64 end);
NgosStatus clearDynamicIdentityMap(u64 start, u64 end);



#endif // COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
