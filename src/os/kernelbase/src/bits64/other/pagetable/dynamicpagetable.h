#ifndef OS_KERNELBASE_SRC_BITS64_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
#define OS_KERNELBASE_SRC_BITS64_OTHER_PAGETABLE_DYNAMICPAGETABLE_H



#include <ngos/status.h>
#include <ngos/types.h>



NgosStatus addDynamicIdentityMap(u64 start, u64 end);
NgosStatus clearDynamicIdentityMap(u64 start, u64 end);



#endif // OS_KERNELBASE_SRC_BITS64_OTHER_PAGETABLE_DYNAMICPAGETABLE_H
