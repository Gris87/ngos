#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_RANDOMIZATION_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_RANDOMIZATION_H



#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/common/ngos/types.h>



NgosStatus getRandomLocation(BootParams *params, bad_uint8 *pageTable, bad_uint64 imageSize, bad_uint64 *physicalAddress, bad_uint64 *virtualAddress); // TEST: NO



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_RANDOMIZATION_H
