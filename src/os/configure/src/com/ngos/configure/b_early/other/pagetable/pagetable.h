#ifndef CONFIGURE_SRC_BITS64_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H
#define CONFIGURE_SRC_BITS64_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H



#include <ngos/status.h>
#include <ngos/types.h>



NgosStatus initializeIdentityMaps(u8 *pageTable); // TEST: NO
NgosStatus addIdentityMap(u64 start, u64 end); // TEST: NO
NgosStatus finalizeIdentityMaps(); // TEST: NO



#endif // CONFIGURE_SRC_BITS64_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H
