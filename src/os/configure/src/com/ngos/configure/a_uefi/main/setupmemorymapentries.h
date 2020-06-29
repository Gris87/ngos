#ifndef CONFIGURE_SRC_BITS64_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H
#define CONFIGURE_SRC_BITS64_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H



#include <bootparams/bootparams.h>
#include <ngos/status.h>
#include <uefibase/src/bits64/other/uefibootmemorymap.h>



NgosStatus setupMemoryMapEntries(BootParams *params, UefiBootMemoryMap *bootMemoryMap, MemoryMapEntry *memoryMapEntries); // TEST: NO



#endif // CONFIGURE_SRC_BITS64_A_UEFI_MAIN_SETUPMEMORYMAPENTRIES_H
