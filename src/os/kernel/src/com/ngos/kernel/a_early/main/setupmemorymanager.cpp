#include "setupmemorymanager.h"

#include <com/ngos/kernel/other/memorymanager/memorymanager.h>
#include <com/ngos/kernel/other/pagetable/addressconversion.h>
#include <com/ngos/shared/common/early/earlyassert.h>
#include <com/ngos/shared/common/early/earlylog.h>
#include <com/ngos/shared/common/page/macros.h>



extern void *_start; // _start declared in main.S file // Ignore CppEqualAlignmentVerifier
extern void *_end;   // _end declared in linker.ld file // Ignore CppEqualAlignmentVerifier



NgosStatus setupMemoryManager()
{
    EARLY_LT((""));



    EARLY_ASSERT_EXECUTION(MemoryManager::init(),                                                                               NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(MemoryManager::reserve(0, PAGE_SIZE),                                                                NgosStatus::ASSERTION);
    EARLY_ASSERT_EXECUTION(MemoryManager::reserve(AddressConversion::physicalAddress((bad_uint64)&_start), (bad_uint64)&_end - (bad_uint64)&_start), NgosStatus::ASSERTION);



    // Validation
    {
#if NGOS_BUILD_TEST_MODE == OPTION_YES
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.count     = %u",        MemoryManager::sMemoryBlock.reserved.count));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.max       = %u",        MemoryManager::sMemoryBlock.reserved.max));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.totalSize = 0x%016llX", MemoryManager::sMemoryBlock.reserved.totalSize));

        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.regions:"));
        EARLY_LVVV(("-------------------------------------"));

        for (bad_int64 i = 0; i < (bad_int64)MemoryManager::sMemoryBlock.reserved.count; ++i)
        {
            EARLY_LVVV(("#%-3d: 0x%p-0x%p | %s | 0x%04X", i, MemoryManager::sMemoryBlock.reserved.regions[i].start, MemoryManager::sMemoryBlock.reserved.regions[i].end(), flagsToFullString(MemoryManager::sMemoryBlock.reserved.regions[i].flags), MemoryManager::sMemoryBlock.reserved.regions[i].nodeId));
        }

        EARLY_LVVV(("-------------------------------------"));
#endif



        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.count             == 2,                                                NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.max               == INIT_MEMORYBLOCK_REGIONS,                         NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.totalSize         == PAGE_SIZE + (bad_uint64)&_end - (bad_uint64)&_start,            NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].start  == 0,                                                NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].size   == PAGE_SIZE,                                        NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].flags  == 0,                                                NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].nodeId == MAX_NUMNODES,                                     NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].start  == AddressConversion::physicalAddress((bad_uint64)&_start), NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].size   == (bad_uint64)&_end - (bad_uint64)&_start,                        NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].flags  == 0,                                                NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].nodeId == MAX_NUMNODES,                                     NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}
