#ifndef CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_PROCESSELF_H
#define CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_PROCESSELF_H



#include <common/src/com/ngos/shared/common/elf/header.h>
#include <common/src/com/ngos/shared/common/ngos/status.h>



u64 getElfMemorySize(ElfHeader *header); // TEST: NO
NgosStatus loadElfToAddress(ElfHeader *header, u64 address); // TEST: NO
NgosStatus handleRelocations(ElfHeader *header, u64 physicalAddress, u64 virtualAddress); // TEST: NO



#endif // CONFIGURE_SRC_COM_NGOS_CONFIGURE_B_EARLY_MAIN_PROCESSELF_H
