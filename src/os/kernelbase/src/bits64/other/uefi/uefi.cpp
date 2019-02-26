#include "uefi.h"

#include <src/bits64/log/assert.h>
#include <src/bits64/log/log.h>
#include <src/bits64/memory/memory.h>
#include <src/bits64/other/bootparams/bootparams.h>
#include <src/bits64/other/ioremap/ioremap.h>



#define UEFI_MEMORY_MAP_DESCRIPTOR(i) ((UefiMemoryDescriptor *)((u64)UEFI::sMemoryMap.map + (i * UEFI::sMemoryMap.descriptorSize))) // TEST: NO



UefiMemoryMapInfo UEFI::sMemoryMap;



NgosStatus UEFI::initMemoryMap()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)bootParams.uefi.memoryMap.map, bootParams.uefi.memoryMap.size, (void **)&sMemoryMap.map), NgosStatus::ASSERTION);

    sMemoryMap.size              = bootParams.uefi.memoryMap.size;
    sMemoryMap.descriptorSize    = bootParams.uefi.memoryMap.descriptorSize;
    sMemoryMap.descriptorVersion = bootParams.uefi.memoryMap.descriptorVersion;



    // -----------------------------------------------------------------------------------------------
    // Check IORemap
    // -----------------------------------------------------------------------------------------------



#if NGOS_BUILD_TEST_MODE == OPTION_YES
    COMMON_LVVV(("IORemap::sLastUsedSlot     = %u", IORemap::sLastUsedSlot));
    COMMON_LVVV(("IORemap::sLastReleasedSlot = %u", IORemap::sLastReleasedSlot));
    COMMON_LVVV(("IORemap::sSlotsAvailable   = %u", IORemap::sSlotsAvailable));

    for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
    {
        COMMON_LVVV(("IORemap::sSlotsAddresses[%d] = 0x%p", i, IORemap::sSlotsAddresses[i]));
    }

    for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
    {
        COMMON_LVVV(("IORemap::sSlotsSizes[%d] = %u", i, IORemap::sSlotsSizes[i]));
    }

    for (i64 i = 0; i < FIX_BITMAP_SLOTS; ++i)
    {
        COMMON_LVVV(("IORemap::sPoolOfSlots[%d] = %u", i, IORemap::sPoolOfSlots[i]));
    }

    for (i64 i = 0; i < PTRS_PER_PTE; ++i)
    {
        if (IORemap::sFixmapPage[i].pte)
        {
            COMMON_LVVV(("IORemap::sFixmapPage[%d].pte = 0x%016lX", i, IORemap::sFixmapPage[i].pte));
        }
    }
#endif



    COMMON_TEST_ASSERT(IORemap::sLastUsedSlot                      == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sLastReleasedSlot                  == 7,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAvailable                    == 7,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[0]                 == 0xFFFFFFFFFF200018, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[1]                 == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[2]                 == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[3]                 == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[4]                 == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[5]                 == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[6]                 == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[7]                 == 0x0000000000000000, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsSizes[0]                     == 2160,               NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsSizes[1]                     == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsSizes[2]                     == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsSizes[3]                     == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsSizes[4]                     == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsSizes[5]                     == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsSizes[6]                     == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sSlotsSizes[7]                     == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[0]                    == 0,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[1]                    == 1,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[2]                    == 2,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[3]                    == 3,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[4]                    == 4,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[5]                    == 5,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[6]                    == 6,                  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[7]                    == 7,                  NgosStatus::ASSERTION);
    // COMMON_TEST_ASSERT(IORemap::sFixmapPage[0].pte              == 0x800000003E356163, NgosStatus::ASSERTION); // Commented due to value variation
    COMMON_TEST_ASSERT(memempty(&IORemap::sFixmapPage[1], 511 * 8) == true,               NgosStatus::ASSERTION); // Ignore CppShiftVerifier



    // -----------------------------------------------------------------------------------------------
    // Check UEFI memory map
    // -----------------------------------------------------------------------------------------------



    i64 count = sMemoryMap.size / sMemoryMap.descriptorSize;
    AVOID_UNUSED(count);



    COMMON_LVVV(("sMemoryMap.map               = 0x%p", sMemoryMap.map));
    COMMON_LVVV(("sMemoryMap.size              = %u",   sMemoryMap.size));
    COMMON_LVVV(("sMemoryMap.descriptorSize    = %u",   sMemoryMap.descriptorSize));
    COMMON_LVVV(("sMemoryMap.descriptorVersion = %u",   sMemoryMap.descriptorVersion));
    COMMON_LVVV(("count                        = %d",   count));

#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
    {
        COMMON_LVVV(("UEFI Memory Map entries:"));
        COMMON_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < count; ++i)
        {
            UefiMemoryDescriptor *memoryDescriptor = UEFI_MEMORY_MAP_DESCRIPTOR(i);
            COMMON_TEST_ASSERT(memoryDescriptor, NgosStatus::ASSERTION);

            COMMON_LVVV(("#%d: type = %u | 0x%p-0x%p | 0x%016lX", i, memoryDescriptor->type, memoryDescriptor->physicalStart, memoryDescriptor->physicalStart + memoryDescriptor->numberOfPages * PAGE_SIZE, memoryDescriptor->attribute));
        }

        COMMON_LVVV(("-------------------------------------"));
    }
#endif



    COMMON_TEST_ASSERT((u64)sMemoryMap.map                              == 0xFFFFFFFFFF200018,                    NgosStatus::ASSERTION);
    // COMMON_TEST_ASSERT(sMemoryMap.size                               == 2160,                                  NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(sMemoryMap.descriptorSize                     == 48,                                    NgosStatus::ASSERTION); // Commented due to value variation
    COMMON_TEST_ASSERT(sMemoryMap.descriptorVersion                     == 1,                                     NgosStatus::ASSERTION);
    // COMMON_TEST_ASSERT(count                                         == 45,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(0)->type           == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(0)->physicalStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(0)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(0)->numberOfPages  == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(0)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(1)->type           == UefiMemoryType::LOADER_DATA,           NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(1)->physicalStart  == 0x0000000000001000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(1)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(1)->numberOfPages  == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(1)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(2)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(2)->physicalStart  == 0x0000000000002000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(2)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(2)->numberOfPages  == 158,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(2)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(3)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(3)->physicalStart  == 0x0000000000100000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(3)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(3)->numberOfPages  == 256,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(3)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(4)->type           == UefiMemoryType::LOADER_DATA,           NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(4)->physicalStart  == 0x0000000000200000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(4)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(4)->numberOfPages  == 1300,                                  NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(4)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(5)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(5)->physicalStart  == 0x0000000000714000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(5)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(5)->numberOfPages  == 242,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(5)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(6)->type           == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(6)->physicalStart  == 0x0000000000806000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(6)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(6)->numberOfPages  == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(6)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(7)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(7)->physicalStart  == 0x0000000000807000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(7)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(7)->numberOfPages  == 25,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(7)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(8)->type           == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(8)->physicalStart  == 0x0000000000820000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(8)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(8)->numberOfPages  == 3040,                                  NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(8)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(9)->type           == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(9)->physicalStart  == 0x0000000001400000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(9)->virtualStart   == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(9)->numberOfPages  == 240574,                                NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(9)->attribute      == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(10)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(10)->physicalStart == 0x000000003BFBE000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(10)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(10)->numberOfPages == 32,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(10)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(11)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(11)->physicalStart == 0x000000003BFDE000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(11)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(11)->numberOfPages == 9062,                                  NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(11)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(12)->type          == UefiMemoryType::LOADER_DATA,           NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(12)->physicalStart == 0x000000003E344000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(12)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(12)->numberOfPages == 72,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(12)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(13)->type          == UefiMemoryType::LOADER_CODE,           NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(13)->physicalStart == 0x000000003E38C000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(13)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(13)->numberOfPages == 209,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(13)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(14)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(14)->physicalStart == 0x000000003E45D000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(14)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(14)->numberOfPages == 1153,                                  NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(14)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(15)->type          == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(15)->physicalStart == 0x000000003E8DE000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(15)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(15)->numberOfPages == 504,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(15)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(16)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(16)->physicalStart == 0x000000003EAD6000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(16)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(16)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(16)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(17)->type          == UefiMemoryType::RUNTIME_SERVICES_CODE, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(17)->physicalStart == 0x000000003EADB000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(17)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(17)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(17)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(18)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(18)->physicalStart == 0x000000003EAE0000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(18)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(18)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(18)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(19)->type          == UefiMemoryType::RUNTIME_SERVICES_CODE, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(19)->physicalStart == 0x000000003EAE5000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(19)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(19)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(19)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(20)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(20)->physicalStart == 0x000000003EAEA000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(20)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(20)->numberOfPages == 5,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(20)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(21)->type          == UefiMemoryType::RUNTIME_SERVICES_CODE, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(21)->physicalStart == 0x000000003EAEF000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(21)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(21)->numberOfPages == 7,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(21)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(22)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(22)->physicalStart == 0x000000003EAF6000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(22)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(22)->numberOfPages == 37,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(22)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(23)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(23)->physicalStart == 0x000000003EB1B000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(23)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(23)->numberOfPages == 786,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(23)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(24)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(24)->physicalStart == 0x000000003EE2D000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(24)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(24)->numberOfPages == 261,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(24)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(25)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(25)->physicalStart == 0x000000003EF32000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(25)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(25)->numberOfPages == 4,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(25)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(26)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(26)->physicalStart == 0x000000003EF36000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(26)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(26)->numberOfPages == 2,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(26)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(27)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(27)->physicalStart == 0x000000003EF38000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(27)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(27)->numberOfPages == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(27)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(28)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(28)->physicalStart == 0x000000003EF39000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(28)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(28)->numberOfPages == 121,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(28)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(29)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(29)->physicalStart == 0x000000003EFB2000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(29)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(29)->numberOfPages == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(29)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(30)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(30)->physicalStart == 0x000000003EFB3000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(30)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(30)->numberOfPages == 2664,                                  NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(30)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(31)->type          == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(31)->physicalStart == 0x000000003FA1B000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(31)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(31)->numberOfPages == 384,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(31)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(32)->type          == UefiMemoryType::RUNTIME_SERVICES_CODE, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(32)->physicalStart == 0x000000003FB9B000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(32)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(32)->numberOfPages == 48,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(32)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(33)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(33)->physicalStart == 0x000000003FBCB000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(33)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(33)->numberOfPages == 36,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(33)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(34)->type          == UefiMemoryType::RESERVED_MEMORY,       NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(34)->physicalStart == 0x000000003FBEF000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(34)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(34)->numberOfPages == 4,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(34)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(35)->type          == UefiMemoryType::ACPI_RECLAIM_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(35)->physicalStart == 0x000000003FBF3000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(35)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(35)->numberOfPages == 8,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(35)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(36)->type          == UefiMemoryType::ACPI_MEMORY_NVS,       NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(36)->physicalStart == 0x000000003FBFB000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(36)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(36)->numberOfPages == 4,                                     NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(36)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(37)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(37)->physicalStart == 0x000000003FBFF000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(37)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(37)->numberOfPages == 513,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(37)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(38)->type          == UefiMemoryType::CONVENTIONAL_MEMORY,   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(38)->physicalStart == 0x000000003FE00000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(38)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(38)->numberOfPages == 347,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(38)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(39)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(39)->physicalStart == 0x000000003FF5B000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(39)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(39)->numberOfPages == 32,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(39)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(40)->type          == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(40)->physicalStart == 0x000000003FF7B000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(40)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(40)->numberOfPages == 37,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(40)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(41)->type          == UefiMemoryType::BOOT_SERVICES_DATA,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(41)->physicalStart == 0x000000003FFA0000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(41)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(41)->numberOfPages == 33,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(41)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(42)->type          == UefiMemoryType::BOOT_SERVICES_CODE,    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(42)->physicalStart == 0x000000003FFC1000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(42)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(42)->numberOfPages == 31,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(42)->attribute     == 0x000000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(43)->type          == UefiMemoryType::RUNTIME_SERVICES_DATA, NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(43)->physicalStart == 0x000000003FFE0000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(43)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(43)->numberOfPages == 32,                                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(43)->attribute     == 0x800000000000000F,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(44)->type          == UefiMemoryType::MEMORY_MAPPED_IO,      NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(44)->physicalStart == 0x00000000FFE00000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(44)->virtualStart  == 0x0000000000000000,                    NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(44)->numberOfPages == 512,                                   NgosStatus::ASSERTION); // Commented due to value variation
    // COMMON_TEST_ASSERT(UEFI_MEMORY_MAP_DESCRIPTOR(44)->attribute     == 0x8000000000000001,                    NgosStatus::ASSERTION); // Commented due to value variation



    return NgosStatus::OK;
}
