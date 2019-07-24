#include "reservepciromimages.h"

#include <common/src/bits64/early/earlyassert.h>
#include <common/src/bits64/early/earlylog.h>
#include <common/src/bits64/memory/memory.h>
#include <kernelbase/src/bits64/other/bootparams/bootparams.h>
#include <kernelbase/src/bits64/other/e820/e820.h>
#include <kernelbase/src/bits64/other/ioremap/ioremap.h>
#include <kernelbase/src/bits64/other/memorymanager/memorymanager.h>
#include <pagetable/utils.h>



NgosStatus reservePciRomImages()
{
    EARLY_LT((""));



    PciRomImageWithInfo *currentPci = bootParams.pciRomImages;

    while (currentPci)
    {
        PciRomImageWithInfo *currentPciMapped;

        EARLY_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)currentPci, sizeof(PciRomImageWithInfo), (void **)&currentPciMapped), NgosStatus::ASSERTION);



        EARLY_LVV(("ROM Image with info 0x%p mapped to 0x%p", currentPci, currentPciMapped));

        EARLY_LVVV(("currentPciMapped->next           = 0x%p",   currentPciMapped->next));
        EARLY_LVVV(("currentPciMapped->vendorId       = 0x%04X", currentPciMapped->vendorId));
        EARLY_LVVV(("currentPciMapped->deviceId       = 0x%04X", currentPciMapped->deviceId));
        EARLY_LVVV(("currentPciMapped->segmentNumber  = %u",     currentPciMapped->segmentNumber));
        EARLY_LVVV(("currentPciMapped->busNumber      = %u",     currentPciMapped->busNumber));
        EARLY_LVVV(("currentPciMapped->deviceNumber   = %u",     currentPciMapped->deviceNumber));
        EARLY_LVVV(("currentPciMapped->functionNumber = %u",     currentPciMapped->functionNumber));
        EARLY_LVVV(("currentPciMapped->romSize        = %u",     currentPciMapped->romSize));



        u64 size = sizeof(PciRomImageWithInfo) + currentPciMapped->romSize;

        EARLY_ASSERT_EXECUTION(MemoryManager::reserve((u64)currentPci, size), NgosStatus::ASSERTION);

        EARLY_ASSERT_EXECUTION(E820::updateRange((u64)currentPci,      size, MemoryMapEntryType::RAM, MemoryMapEntryType::RESERVED_BY_KERNEL), NgosStatus::ASSERTION);
        EARLY_ASSERT_EXECUTION(E820::updateRangeKExec((u64)currentPci, size, MemoryMapEntryType::RAM, MemoryMapEntryType::RESERVED_BY_KERNEL), NgosStatus::ASSERTION);



        currentPci = currentPciMapped->next;

        EARLY_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)currentPciMapped, sizeof(PciRomImageWithInfo)), NgosStatus::ASSERTION);
    }



    // Validation
    {
        // -----------------------------------------------------------------------------------------------
        // Check IORemap
        // -----------------------------------------------------------------------------------------------



#if NGOS_BUILD_TEST_MODE == OPTION_YES
        EARLY_LVVV(("IORemap::sLastUsedSlot     = %u", IORemap::sLastUsedSlot));
        EARLY_LVVV(("IORemap::sLastReleasedSlot = %u", IORemap::sLastReleasedSlot));
        EARLY_LVVV(("IORemap::sSlotsAvailable   = %u", IORemap::sSlotsAvailable));

        for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
        {
            EARLY_LVVV(("IORemap::sSlotsAddresses[%d] = 0x%p", i, IORemap::sSlotsAddresses[i]));
        }

        for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
        {
            EARLY_LVVV(("IORemap::sSlotsSizes[%d] = %u", i, IORemap::sSlotsSizes[i]));
        }

        for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
        {
            EARLY_LVVV(("IORemap::sPoolOfSlots[%d] = %u", i, IORemap::sPoolOfSlots[i]));
        }

        for (i64 i = 0; i < PTRS_PER_PTE; ++i)
        {
            if (pteValue(IORemap::sFixmapPage[i]))
            {
                EARLY_LVVV(("pteValue(IORemap::sFixmapPage[%d]) = 0x%016lX", i, pteValue(IORemap::sFixmapPage[i])));
            }
        }
#endif



        EARLY_TEST_ASSERT(IORemap::sLastUsedSlot                      == 2,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sLastReleasedSlot                  == 1,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAvailable                    == 7,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAddresses[0]                 == 0xFFFFFFFFFF200018, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAddresses[1]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAddresses[2]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAddresses[3]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAddresses[4]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAddresses[5]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAddresses[6]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsAddresses[7]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        // EARLY_TEST_ASSERT(IORemap::sSlotsSizes[0]                  == 2160,               NgosStatus::ASSERTION); // Commented due to value variation
        EARLY_TEST_ASSERT(IORemap::sSlotsSizes[1]                     == 0,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsSizes[2]                     == 0,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsSizes[3]                     == 0,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsSizes[4]                     == 0,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsSizes[5]                     == 0,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsSizes[6]                     == 0,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sSlotsSizes[7]                     == 0,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sPoolOfSlots[0]                    == 1,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sPoolOfSlots[1]                    == 2,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sPoolOfSlots[2]                    == 2,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sPoolOfSlots[3]                    == 3,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sPoolOfSlots[4]                    == 4,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sPoolOfSlots[5]                    == 5,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sPoolOfSlots[6]                    == 6,                  NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(IORemap::sPoolOfSlots[7]                    == 7,                  NgosStatus::ASSERTION);
        // EARLY_TEST_ASSERT(pteValue(IORemap::sFixmapPage[0])        == 0x800000003E357163, NgosStatus::ASSERTION); // Commented due to value variation
        EARLY_TEST_ASSERT(memempty(&IORemap::sFixmapPage[1], 511 * 8) == true,               NgosStatus::ASSERTION);



        // -----------------------------------------------------------------------------------------------
        // Check MemoryManager
        // -----------------------------------------------------------------------------------------------



#if NGOS_BUILD_TEST_MODE == OPTION_YES
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.count     = %u",       MemoryManager::sMemoryBlock.reserved.count));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.max       = %u",       MemoryManager::sMemoryBlock.reserved.max));
        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.totalSize = 0x%016lX", MemoryManager::sMemoryBlock.reserved.totalSize));

        EARLY_LVVV(("MemoryManager::sMemoryBlock.reserved.regions:"));
        EARLY_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)MemoryManager::sMemoryBlock.reserved.count; ++i)
        {
            EARLY_LVVV(("#%-3d: 0x%p-0x%p | 0x%02X (%s) | 0x%04X", i, MemoryManager::sMemoryBlock.reserved.regions[i].start, MemoryManager::sMemoryBlock.reserved.regions[i].end(), MemoryManager::sMemoryBlock.reserved.regions[i].flags, memoryBlockRegionFlagsToString(MemoryManager::sMemoryBlock.reserved.regions[i].flags), MemoryManager::sMemoryBlock.reserved.regions[i].nodeId));
        }

        EARLY_LVVV(("-------------------------------------"));
#endif



        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.count             == 5,                        NgosStatus::ASSERTION); // Commented due to value variation
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.max                  == INIT_MEMORYBLOCK_REGIONS, NgosStatus::ASSERTION);
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.totalSize         == 0x00000000000B4B88,       NgosStatus::ASSERTION); // Commented due to value variation
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].start     == 0,                        NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].size      == PAGE_SIZE,                NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].flags     == 0,                        NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].nodeId    == MAX_NUMNODES,             NgosStatus::ASSERTION);
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].start  == 0x0000000010000000,       NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].size   == 0x000000000006F0A8,       NgosStatus::ASSERTION); // Commented due to value variation
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].flags     == 0,                        NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].nodeId    == MAX_NUMNODES,             NgosStatus::ASSERTION);
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].start  == 0x000000003E357018,       NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].size   == 0x0000000000000870,       NgosStatus::ASSERTION); // Commented due to value variation
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].flags     == 0,                        NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].nodeId    == MAX_NUMNODES,             NgosStatus::ASSERTION);
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[3].start  == 0x000000003E359018,       NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[3].size   == 0x000000000003AA38,       NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[3].flags  == 0,                        NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[3].nodeId == MAX_NUMNODES,             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[4].start  == 0x000000003E394018,       NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[4].size   == 0x0000000000009838,       NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[4].flags  == 0,                        NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[4].nodeId == MAX_NUMNODES,             NgosStatus::ASSERTION); // Commented due to value variation



        // -----------------------------------------------------------------------------------------------
        // Check E820
        // -----------------------------------------------------------------------------------------------



#if NGOS_BUILD_TEST_MODE == OPTION_YES
        EARLY_LVVV(("E820::sTable.count         = %u", E820::sTable.count));
        EARLY_LVVV(("E820::sTableKExec.count    = %u", E820::sTableKExec.count));
        EARLY_LVVV(("E820::sTableFirmware.count = %u", E820::sTableFirmware.count));

        EARLY_LVVV(("E820::sTable.entries:"));
        EARLY_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)E820::sTable.count; ++i)
        {
            EARLY_LVVV(("#%-3d: type = %20s | 0x%p-0x%p", i, memoryMapEntryTypeToString(E820::sTable.entries[i].type), E820::sTable.entries[i].start, E820::sTable.entries[i].end()));
        }

        EARLY_LVVV(("-------------------------------------"));



        EARLY_LVVV(("sTableKExec.entries:"));
        EARLY_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)E820::sTableKExec.count; ++i)
        {
            EARLY_LVVV(("#%-3d: type = %20s | 0x%p-0x%p", i, memoryMapEntryTypeToString(E820::sTableKExec.entries[i].type), E820::sTableKExec.entries[i].start, E820::sTableKExec.entries[i].end()));
        }

        EARLY_LVVV(("-------------------------------------"));



        EARLY_LVVV(("sTableFirmware.entries:"));
        EARLY_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)E820::sTableFirmware.count; ++i)
        {
            EARLY_LVVV(("#%-3d: type = %20s | 0x%p-0x%p", i, memoryMapEntryTypeToString(E820::sTableFirmware.entries[i].type), E820::sTableFirmware.entries[i].start, E820::sTableFirmware.entries[i].end()));
        }

        EARLY_LVVV(("-------------------------------------"));
#endif



        EARLY_TEST_ASSERT(E820::sTable.count         <= E820_TABLE_SIZE, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(E820::sTableKExec.count    <= E820_TABLE_SIZE, NgosStatus::ASSERTION);
        EARLY_TEST_ASSERT(E820::sTableFirmware.count <= E820_TABLE_SIZE, NgosStatus::ASSERTION);

        // EARLY_TEST_ASSERT(E820::sTable.count             == 14,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[0].start  == 0x00000000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[0].size   == 0x000A0000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[0].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[1].start  == 0x00100000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[1].size   == 0x3E252018,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[1].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[2].start  == 0x3E352018,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[2].size   == 0x0003AA38,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[2].type   == MemoryMapEntryType::RESERVED_BY_KERNEL, NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[3].start  == 0x3E38CA50,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[3].size   == 0x000005C8,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[3].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[4].start  == 0x3E38D018,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[4].size   == 0x00009838,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[4].type   == MemoryMapEntryType::RESERVED_BY_KERNEL, NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[5].start  == 0x3E396850,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[5].size   == 0x0073F7B0,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[5].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[6].start  == 0x3EAD6000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[6].size   == 0x00045000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[6].type   == MemoryMapEntryType::RESERVED,           NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[7].start  == 0x3EB1B000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[7].size   == 0x01080000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[7].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[8].start  == 0x3FB9B000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[8].size   == 0x00058000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[8].type   == MemoryMapEntryType::RESERVED,           NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[9].start  == 0x3FBF3000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[9].size   == 0x00008000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[9].type   == MemoryMapEntryType::ACPI,               NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[10].start == 0x3FBFB000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[10].size  == 0x00004000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[10].type  == MemoryMapEntryType::NVS,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[11].start == 0x3FBFF000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[11].size  == 0x003E1000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[11].type  == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[12].start == 0x3FFE0000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[12].size  == 0x00020000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[12].type  == MemoryMapEntryType::RESERVED,           NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[13].start == 0xFFE00000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[13].size  == 0x00200000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTable.entries[13].type  == MemoryMapEntryType::RESERVED,           NgosStatus::ASSERTION); // Commented due to value variation

        // EARLY_TEST_ASSERT(E820::sTableKExec.count             == 14,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[0].start  == 0x00000000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[0].size   == 0x000A0000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[0].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[1].start  == 0x00100000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[1].size   == 0x3E252018,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[1].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[2].start  == 0x3E352018,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[2].size   == 0x0003AA38,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[2].type   == MemoryMapEntryType::RESERVED_BY_KERNEL, NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[3].start  == 0x3E38CA50,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[3].size   == 0x000005C8,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[3].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[4].start  == 0x3E38D018,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[4].size   == 0x00009838,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[4].type   == MemoryMapEntryType::RESERVED_BY_KERNEL, NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[5].start  == 0x3E396850,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[5].size   == 0x0073F7B0,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[5].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[6].start  == 0x3EAD6000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[6].size   == 0x00045000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[6].type   == MemoryMapEntryType::RESERVED,           NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[7].start  == 0x3EB1B000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[7].size   == 0x01080000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[7].type   == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[8].start  == 0x3FB9B000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[8].size   == 0x00058000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[8].type   == MemoryMapEntryType::RESERVED,           NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[9].start  == 0x3FBF3000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[9].size   == 0x00008000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[9].type   == MemoryMapEntryType::ACPI,               NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[10].start == 0x3FBFB000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[10].size  == 0x00004000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[10].type  == MemoryMapEntryType::NVS,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[11].start == 0x3FBFF000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[11].size  == 0x003E1000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[11].type  == MemoryMapEntryType::RAM,                NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[12].start == 0x3FFE0000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[12].size  == 0x00020000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[12].type  == MemoryMapEntryType::RESERVED,           NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[13].start == 0xFFE00000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[13].size  == 0x00200000,                             NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableKExec.entries[13].type  == MemoryMapEntryType::RESERVED,           NgosStatus::ASSERTION); // Commented due to value variation

        // EARLY_TEST_ASSERT(E820::sTableFirmware.count            == 10,                           NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[0].start == 0x00000000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[0].size  == 0x000A0000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[0].type  == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[1].start == 0x00100000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[1].size  == 0x3E9D6000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[1].type  == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[2].start == 0x3EAD6000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[2].size  == 0x00045000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[2].type  == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[3].start == 0x3EB1B000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[3].size  == 0x01080000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[3].type  == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[4].start == 0x3FB9B000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[4].size  == 0x00058000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[4].type  == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[5].start == 0x3FBF3000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[5].size  == 0x00008000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[5].type  == MemoryMapEntryType::ACPI,     NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[6].start == 0x3FBFB000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[6].size  == 0x00004000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[6].type  == MemoryMapEntryType::NVS,      NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[7].start == 0x3FBFF000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[7].size  == 0x003E1000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[7].type  == MemoryMapEntryType::RAM,      NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[8].start == 0x3FFE0000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[8].size  == 0x00020000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[8].type  == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[9].start == 0xFFE00000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[9].size  == 0x00200000,                   NgosStatus::ASSERTION); // Commented due to value variation
        // EARLY_TEST_ASSERT(E820::sTableFirmware.entries[9].type  == MemoryMapEntryType::RESERVED, NgosStatus::ASSERTION); // Commented due to value variation
    }



    return NgosStatus::OK;
}
