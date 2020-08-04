#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_RANDOMIZATION_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_RANDOMIZATION_H



#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



NgosStatus getRandomLocation(BootParams *params, u8 *pageTable, u64 imageSize, u64 *physicalAddress, u64 *virtualAddress); // TEST: NO



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_RANDOMIZATION_H
