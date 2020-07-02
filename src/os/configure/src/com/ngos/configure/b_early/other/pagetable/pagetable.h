#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H



#include <common/src/com/ngos/shared/common/ngos/status.h>
#include <common/src/com/ngos/shared/common/ngos/types.h>



NgosStatus initializeIdentityMaps(u8 *pageTable); // TEST: NO
NgosStatus addIdentityMap(u64 start, u64 end); // TEST: NO
NgosStatus finalizeIdentityMaps(); // TEST: NO



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_OTHER_PAGETABLE_PAGETABLE_H
