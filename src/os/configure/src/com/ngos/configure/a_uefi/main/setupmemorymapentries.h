#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H



#include <common/src/com/ngos/shared/common/bootparams/bootparams.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>
#include <uefibase/src/com/ngos/shared/uefibase/other/uefibootmemorymap.h>



NgosStatus setupMemoryMapEntries(BootParams *params, UefiBootMemoryMap *bootMemoryMap, MemoryMapEntry *memoryMapEntries); // TEST: NO



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H
