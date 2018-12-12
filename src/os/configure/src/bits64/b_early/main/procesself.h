#ifndef CONFIGURE_SRC_BITS64_B_EARLY_MAIN_PROCESSELF_H
#define CONFIGURE_SRC_BITS64_B_EARLY_MAIN_PROCESSELF_H



#include <elf/header.h>
#include <ngos/status.h>



u64 getElfMemorySize(ElfHeader *header); // TEST: NO
NgosStatus loadElfToAddress(ElfHeader *header, u64 address); // TEST: NO
NgosStatus handleRelocations(ElfHeader *header, u64 physicalAddress, u64 virtualAddress); // TEST: NO



#endif // CONFIGURE_SRC_BITS64_B_EARLY_MAIN_PROCESSELF_H
