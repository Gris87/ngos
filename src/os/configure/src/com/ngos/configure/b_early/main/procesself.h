#ifndef COM_NGOS_CONFIGURE_B_EARLY_MAIN_PROCESSELF_H
#define COM_NGOS_CONFIGURE_B_EARLY_MAIN_PROCESSELF_H



#include <com/ngos/shared/common/elf/header.h>
#include <com/ngos/shared/common/ngos/status.h>



u64 getElfMemorySize(ElfHeader *header); // TEST: NO
NgosStatus loadElfToAddress(ElfHeader *header, u64 address); // TEST: NO
NgosStatus handleRelocations(ElfHeader *header, u64 physicalAddress, u64 virtualAddress); // TEST: NO



#endif // COM_NGOS_CONFIGURE_B_EARLY_MAIN_PROCESSELF_H
