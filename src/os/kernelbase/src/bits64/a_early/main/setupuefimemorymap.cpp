#include "setupuefimemorymap.h"

#include <src/bits64/a_early/early/earlyassert.h>
#include <src/bits64/a_early/early/earlylog.h>
#include <src/bits64/other/bootparams/bootparams.h>
#include <src/bits64/other/ioremap/ioremap.h>
#include <src/bits64/other/memorymanager/memorymanager.h>
#include <src/bits64/other/pagetable/addressconversion.h>
#include <src/bits64/other/uefi/uefi.h>



extern void *_start; // _start declared in main.S file // Ignore CppEqualAlignmentVerifier
extern void *_end;   // _end declared in linker.ld file // Ignore CppEqualAlignmentVerifier



NgosStatus setupUefiMemoryMap()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(UEFI::initMemoryMap(),                                                                      NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(MemoryManager::reserve((u64)bootParams.uefi.memoryMap.map, bootParams.uefi.memoryMap.size), NgosStatus::ASSERTION);



#if NGOS_BUILD_TEST_MODE == OPTION_YES
    EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.count     = %u",       MemoryManager::sMemoryBlock.reserved.count));
    EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.max       = %u",       MemoryManager::sMemoryBlock.reserved.max));
    EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.totalSize = 0x%016lX", MemoryManager::sMemoryBlock.reserved.totalSize));

    for (i64 i = 0; i < (i64)MemoryManager::sMemoryBlock.reserved.count; ++i)
    {
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.regions[%d].start  = 0x%016lX", i, MemoryManager::sMemoryBlock.reserved.regions[i].start));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.regions[%d].size   = 0x%016lX", i, MemoryManager::sMemoryBlock.reserved.regions[i].size));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.regions[%d].flags  = 0x%02X",   i, MemoryManager::sMemoryBlock.reserved.regions[i].flags));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.regions[%d].nodeId = 0x%04X",   i, MemoryManager::sMemoryBlock.reserved.regions[i].nodeId));
    }
#endif

    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.count             == 3,                                                                      NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.max               == INIT_MEMORYBLOCK_REGIONS,                                               NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.totalSize         == PAGE_SIZE + (u64)&_end - (u64)&_start + bootParams.uefi.memoryMap.size, NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].start  == 0,                                                                      NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].size   == PAGE_SIZE,                                                              NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].flags  == 0,                                                                      NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].nodeId == MAX_NUMNODES,                                                           NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].start  == AddressConversion::physicalAddress((u64)&_start),                       NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].size   == (u64)&_end - (u64)&_start,                                              NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].flags  == 0,                                                                      NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].nodeId == MAX_NUMNODES,                                                           NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].start  == (u64)bootParams.uefi.memoryMap.map,                                     NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].size   == bootParams.uefi.memoryMap.size,                                         NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].flags  == 0,                                                                      NgosStatus::ASSERTION);
    EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].nodeId == MAX_NUMNODES,                                                           NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
