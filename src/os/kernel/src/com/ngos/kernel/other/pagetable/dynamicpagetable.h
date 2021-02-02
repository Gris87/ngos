#ifndef COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
#define COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



NgosStatus addDynamicIdentityMap(bad_uint64 start, bad_uint64 end);
NgosStatus clearDynamicIdentityMap(bad_uint64 start, bad_uint64 end);



#endif // COM_NGOS_KERNEL_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
