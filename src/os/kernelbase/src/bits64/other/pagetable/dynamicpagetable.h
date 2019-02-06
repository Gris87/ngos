#ifndef OS_COMMON_SRC_BITS64_PAGETABLE_DYNAMICPAGETABLE_H
#define OS_COMMON_SRC_BITS64_PAGETABLE_DYNAMICPAGETABLE_H



#include <ngos/status.h>
#include <ngos/types.h>



NgosStatus addDynamicIdentityMap(u64 start, u64 end);
NgosStatus clearDynamicIdentityMap(u64 start, u64 end);



#endif // OS_COMMON_SRC_BITS64_PAGETABLE_DYNAMICPAGETABLE_H
