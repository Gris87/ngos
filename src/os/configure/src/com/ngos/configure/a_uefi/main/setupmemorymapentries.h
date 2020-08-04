#ifndef COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H
#define COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H



#include <com/ngos/shared/common/bootparams/bootparams.h>
#include <com/ngos/shared/common/ngos/status.h>
#include <com/ngos/shared/uefibase/other/uefibootmemorymap.h>



NgosStatus setupMemoryMapEntries(BootParams *params, UefiBootMemoryMap *bootMemoryMap, MemoryMapEntry *memoryMapEntries); // TEST: NO



#endif // COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H
