#ifndef COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H
#define COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H



#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



NgosStatus initializeIdentityMaps(bad_uint8 *pageTable); // TEST: NO
NgosStatus addIdentityMap(bad_uint64 start, bad_uint64 end); // TEST: NO
NgosStatus finalizeIdentityMaps(); // TEST: NO



#endif // COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H
