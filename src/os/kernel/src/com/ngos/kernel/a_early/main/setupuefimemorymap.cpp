#include "setupuefimemorymap.h"

#include <com/ngos/kernel/other/bootparams/bootparams.h>
#include <com/ngos/kernel/other/ioremap/ioremap.h>
#include <com/ngos/kernel/other/memorymanager/memorymanager.h>
#include <com/ngos/kernel/other/pagetable/addressconversion.h>
#include <com/ngos/kernel/other/uefi/uefi.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>



extern void *_start; // _start declared in main.S file // Ignore CppEqualAlignmentVerifier
extern void *_end;   // _end declared in linker.ld file // Ignore CppEqualAlignmentVerifier



NgosStatus setupUefiMemoryMap()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(UEFI::initMemoryMap(),                                                                      NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(MemoryManager::reserve((u64)bootParams.uefi.memoryMap.map, bootParams.uefi.memoryMap.size), NgosStatus::ASSERTION);



    // Validation
    {
#if NGOS_BUILD_TEST_MODE == OPTION_YES
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.count     = %u",        MemoryManager::sMemoryBlock.reserved.count));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.max       = %u",        MemoryManager::sMemoryBlock.reserved.max));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.totalSize = 0x%016llX", MemoryManager::sMemoryBlock.reserved.totalSize));

        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.regions:"));
        EARLY_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)MemoryManager::sMemoryBlock.reserved.count; ++i)
        {
            EARLY_LVVV(("#%-3d: 0x%p-0x%p | %s | 0x%04X", i, MemoryManager::sMemoryBlock.reserved.regions[i].start, MemoryManager::sMemoryBlock.reserved.regions[i].end(), flagsToFullString(MemoryManager::sMemoryBlock.reserved.regions[i].flags), MemoryManager::sMemoryBlock.reserved.regions[i].nodeId));
        }

        EARLY_LVVV(("-------------------------------------"));
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
    }



    return NgosStatus::OK;
}
