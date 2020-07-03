#include "uefi.h"

#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/guid/utils.h>
#include <com/ngos/shared/common/pagetable/utils.h>

#include <com/ngos/kernel/other/bootparams/bootparams.h>
#include <com/ngos/kernel/other/ioremap/ioremap.h>
#include <com/ngos/kernel/other/memorymanager/memorymanager.h>



#define UEFI_MEMORY_MAP_DESCRIPTOR(i) (UefiMemoryDescriptor *)((u64)UEFI::sMemoryMap.map + (i) * UEFI::sMemoryMap.descriptorSize)



UefiMemoryMapInfo                             UEFI::sMemoryMap;
UefiSystemTable                               UEFI::sSystemTable;
UefiAcpi20ConfigurationTable                 *UEFI::sAcpi20Config;
UefiAcpiConfigurationTable                   *UEFI::sAcpiConfig;
UefiDebugInfoConfigurationTable              *UEFI::sDebugInfoConfig;
UefiDxeServicesConfigurationTable            *UEFI::sDxeServicesConfig;
UefiHcdpConfigurationTable                   *UEFI::sHcdpConfig;
UefiHobListConfigurationTable                *UEFI::sHobListConfig;
UefiLzmaDecompressConfigurationTable         *UEFI::sLzmaDecompressConfig;
UefiMemoryAttributesConfigurationTable       *UEFI::sMemoryAttributesConfig;
UefiMemoryStatusCodeRecordConfigurationTable *UEFI::sMemoryStatusCodeRecordConfig;
UefiMemoryTypeInformationConfigurationTable  *UEFI::sMemoryTypeInformationConfig;
UefiMpsConfigurationTable                    *UEFI::sMpsConfig;
UefiPropertiesConfigurationTable             *UEFI::sPropertiesConfig;
UefiSalSystemConfigurationTable              *UEFI::sSalSystemConfig;
UefiSmbios3ConfigurationTable                *UEFI::sSmbios3Config;
UefiSmbiosConfigurationTable                 *UEFI::sSmbiosConfig;
UefiSystemResourceConfigurationTable         *UEFI::sSystemResourceConfig;
UefiUgaIoConfigurationTable                  *UEFI::sUgaIoConfig;



NgosStatus UEFI::initMemoryMap()
{
    COMMON_LT((""));



    COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)bootParams.uefi.memoryMap.map, bootParams.uefi.memoryMap.size, (void **)&sMemoryMap.map), NgosStatus::ASSERTION);

    sMemoryMap.size              = bootParams.uefi.memoryMap.size;
    sMemoryMap.descriptorSize    = bootParams.uefi.memoryMap.descriptorSize;
    sMemoryMap.descriptorVersion = bootParams.uefi.memoryMap.descriptorVersion;



    // Validation
    {
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
            if (pteValue(IORemap::sFixmapPage[i]))
            {
                COMMON_LVVV(("pteValue(IORemap::sFixmapPage[%d]) = 0x%016lX", i, pteValue(IORemap::sFixmapPage[i])));
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
        // COMMON_TEST_ASSERT(IORemap::sSlotsSizes[0]                  == 2160,               NgosStatus::ASSERTION); // Commented due to value variation
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
        // COMMON_TEST_ASSERT(pteValue(IORemap::sFixmapPage[0])        == 0x800000003E357163, NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(memempty(&IORemap::sFixmapPage[1], 511 * 8) == true,               NgosStatus::ASSERTION);



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

                COMMON_LVVV(("#%-3d: type = %-27s | 0x%p-0x%p | 0x%016lX", i, enumToFullString(memoryDescriptor->type), memoryDescriptor->physicalStart, memoryDescriptor->physicalStart + memoryDescriptor->numberOfPages * PAGE_SIZE, memoryDescriptor->attribute));
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
    }



    return NgosStatus::OK;
}

NgosStatus UEFI::initSystemTable()
{
    COMMON_LT((""));



    // Copy system table from BootParams
    {
        UefiSystemTable *systemTable;



        COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)bootParams.uefi.systemTable, sizeof(UefiSystemTable), (void **)&systemTable), NgosStatus::ASSERTION);

        memcpy(&sSystemTable, systemTable, sizeof(UefiSystemTable));

        COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)systemTable, sizeof(UefiSystemTable)), NgosStatus::ASSERTION);
    }



    COMMON_ASSERT_EXECUTION(initConfigurationTables(), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(initMemoryAttributes(),    NgosStatus::ASSERTION);



    // Validation
    {
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
            if (pteValue(IORemap::sFixmapPage[i]))
            {
                COMMON_LVVV(("pteValue(IORemap::sFixmapPage[%d]) = 0x%016lX", i, pteValue(IORemap::sFixmapPage[i])));
            }
        }
#endif



        COMMON_TEST_ASSERT(IORemap::sLastUsedSlot                      == 6,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sLastReleasedSlot                  == 5,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAvailable                    == 7,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[0]                 == 0xFFFFFFFFFF200018, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[1]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[2]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[3]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[4]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[5]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[6]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsAddresses[7]                 == 0x0000000000000000, NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(IORemap::sSlotsSizes[0]                  == 2160,               NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(IORemap::sSlotsSizes[1]                     == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsSizes[2]                     == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsSizes[3]                     == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsSizes[4]                     == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsSizes[5]                     == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsSizes[6]                     == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sSlotsSizes[7]                     == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[0]                    == 1,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[1]                    == 2,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[2]                    == 3,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[3]                    == 4,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[4]                    == 5,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[5]                    == 6,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[6]                    == 6,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(IORemap::sPoolOfSlots[7]                    == 7,                  NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(pteValue(IORemap::sFixmapPage[0])        == 0x800000003E357163, NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(memempty(&IORemap::sFixmapPage[1], 511 * 8) == true,               NgosStatus::ASSERTION);



        // -----------------------------------------------------------------------------------------------
        // Check MemoryManager
        // -----------------------------------------------------------------------------------------------



#if NGOS_BUILD_TEST_MODE == OPTION_YES
        COMMON_LVVV(("MemoryManager::sMemoryBlock.reserved.count     = %u",       MemoryManager::sMemoryBlock.reserved.count));
        COMMON_LVVV(("MemoryManager::sMemoryBlock.reserved.max       = %u",       MemoryManager::sMemoryBlock.reserved.max));
        COMMON_LVVV(("MemoryManager::sMemoryBlock.reserved.totalSize = 0x%016lX", MemoryManager::sMemoryBlock.reserved.totalSize));

        COMMON_LVVV(("MemoryManager::sMemoryBlock.reserved.regions:"));
        COMMON_LVVV(("-------------------------------------"));

        for (i64 i = 0; i < (i64)MemoryManager::sMemoryBlock.reserved.count; ++i)
        {
            COMMON_LVVV(("#%-3d: 0x%p-0x%p | %s | 0x%04X", i, MemoryManager::sMemoryBlock.reserved.regions[i].start, MemoryManager::sMemoryBlock.reserved.regions[i].end(), flagsToFullString(MemoryManager::sMemoryBlock.reserved.regions[i].flags), MemoryManager::sMemoryBlock.reserved.regions[i].nodeId));
        }

        COMMON_LVVV(("-------------------------------------"));
#endif



        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.count             == 6,                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.max                  == INIT_MEMORYBLOCK_REGIONS, NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.totalSize         == 0x00000000000B4B88,       NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].start     == 0,                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].size      == PAGE_SIZE,                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].flags     == 0,                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[0].nodeId    == MAX_NUMNODES,             NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].start  == 0x0000000010000000,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].size   == 0x000000000006F0A8,       NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].flags     == 0,                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[1].nodeId    == MAX_NUMNODES,             NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].start  == 0x000000003E357018,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].size   == 0x0000000000000870,       NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].flags     == 0,                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[2].nodeId    == MAX_NUMNODES,             NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[3].start  == 0x000000003E359018,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[3].size   == 0x000000000003AA38,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[3].flags  == 0,                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[3].nodeId == MAX_NUMNODES,             NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[4].start  == 0x000000003E394018,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[4].size   == 0x0000000000009838,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[4].flags  == 0,                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[4].nodeId == MAX_NUMNODES,             NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[5].start  == 0x000000003EF41018,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[5].size   == 0x0000000000000550,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[5].flags  == 0,                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(MemoryManager::sMemoryBlock.reserved.regions[5].nodeId == MAX_NUMNODES,             NgosStatus::ASSERTION); // Commented due to value variation



        // -----------------------------------------------------------------------------------------------
        // Check system table
        // -----------------------------------------------------------------------------------------------



        COMMON_LVVV(("sSystemTable.header.signature            = 0x%016lX", sSystemTable.header.signature));
        COMMON_LVVV(("sSystemTable.header.revision             = 0x%08X",   sSystemTable.header.revision));
        COMMON_LVVV(("sSystemTable.header.headerSize           = %u",       sSystemTable.header.headerSize));
        COMMON_LVVV(("sSystemTable.header.crc32                = 0x%08X",   sSystemTable.header.crc32));
        COMMON_LVVV(("sSystemTable.firmwareVendor              = 0x%p",     sSystemTable.firmwareVendor));
        COMMON_LVVV(("sSystemTable.firmwareRevision            = 0x%08X",   sSystemTable.firmwareRevision));
        COMMON_LVVV(("sSystemTable.stdinHandle                 = 0x%p",     sSystemTable.stdinHandle));
        COMMON_LVVV(("sSystemTable.stdin                       = 0x%p",     sSystemTable.stdin));
        COMMON_LVVV(("sSystemTable.stdoutHandle                = 0x%p",     sSystemTable.stdoutHandle));
        COMMON_LVVV(("sSystemTable.stdout                      = 0x%p",     sSystemTable.stdout));
        COMMON_LVVV(("sSystemTable.stderrHandle                = 0x%p",     sSystemTable.stderrHandle));
        COMMON_LVVV(("sSystemTable.stderr                      = 0x%p",     sSystemTable.stderr));
        COMMON_LVVV(("sSystemTable.runtimeServices             = 0x%p",     sSystemTable.runtimeServices));
        COMMON_LVVV(("sSystemTable.bootServices                = 0x%p",     sSystemTable.bootServices));
        COMMON_LVVV(("sSystemTable.numberOfConfigurationTables = %u",       sSystemTable.numberOfConfigurationTables));
        COMMON_LVVV(("sSystemTable.configurationTables         = 0x%p",     sSystemTable.configurationTables));
        COMMON_LVVV(("sAcpi20Config                            = 0x%p",     sAcpi20Config));
        COMMON_LVVV(("sAcpiConfig                              = 0x%p",     sAcpiConfig));
        COMMON_LVVV(("sDebugInfoConfig                         = 0x%p",     sDebugInfoConfig));
        COMMON_LVVV(("sDxeServicesConfig                       = 0x%p",     sDxeServicesConfig));
        COMMON_LVVV(("sHcdpConfig                              = 0x%p",     sHcdpConfig));
        COMMON_LVVV(("sHobListConfig                           = 0x%p",     sHobListConfig));
        COMMON_LVVV(("sLzmaDecompressConfig                    = 0x%p",     sLzmaDecompressConfig));
        COMMON_LVVV(("sMemoryAttributesConfig                  = 0x%p",     sMemoryAttributesConfig));
        COMMON_LVVV(("sMemoryStatusCodeRecordConfig            = 0x%p",     sMemoryStatusCodeRecordConfig));
        COMMON_LVVV(("sMemoryTypeInformationConfig             = 0x%p",     sMemoryTypeInformationConfig));
        COMMON_LVVV(("sMpsConfig                               = 0x%p",     sMpsConfig));
        COMMON_LVVV(("sPropertiesConfig                        = 0x%p",     sPropertiesConfig));
        COMMON_LVVV(("sSalSystemConfig                         = 0x%p",     sSalSystemConfig));
        COMMON_LVVV(("sSmbios3Config                           = 0x%p",     sSmbios3Config));
        COMMON_LVVV(("sSmbiosConfig                            = 0x%p",     sSmbiosConfig));
        COMMON_LVVV(("sSystemResourceConfig                    = 0x%p",     sSystemResourceConfig));
        COMMON_LVVV(("sUgaIoConfig                             = 0x%p",     sUgaIoConfig));



        COMMON_TEST_ASSERT(sSystemTable.header.signature            == UEFI_SYSTEM_TABLE_SIGNATURE, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.header.revision             == 0x00020046,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.header.headerSize           == 120,                         NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.header.crc32                == 0x938F9502,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.firmwareVendor              != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.firmwareRevision            == 0x00010000,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.stdinHandle                 == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.stdin                       == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.stdoutHandle                == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.stdout                      == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.stderrHandle                == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.stderr                      == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.runtimeServices             != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.bootServices                == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.numberOfConfigurationTables == 10,                          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemTable.configurationTables         != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sAcpi20Config                            != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sAcpiConfig                              != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sDebugInfoConfig                         != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sDxeServicesConfig                       != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sHcdpConfig                              == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sHobListConfig                           != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sLzmaDecompressConfig                    != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sMemoryAttributesConfig                  != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sMemoryStatusCodeRecordConfig            != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sMemoryTypeInformationConfig             != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sMpsConfig                               == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sPropertiesConfig                        == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSalSystemConfig                         == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSmbios3Config                           == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSmbiosConfig                            != 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sSystemResourceConfig                    == 0,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sUgaIoConfig                             == 0,                           NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

UefiSmbios3ConfigurationTable* UEFI::getSmbios3Config()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sSmbios3Config;
}

UefiSmbiosConfigurationTable* UEFI::getSmbiosConfig()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sSmbiosConfig;
}

NgosStatus UEFI::initConfigurationTables()
{
    COMMON_LT((""));



    UefiConfigurationTable *configurationTables;



    COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)sSystemTable.configurationTables, sSystemTable.numberOfConfigurationTables * sizeof(UefiConfigurationTable), (void **)&configurationTables), NgosStatus::ASSERTION);

    for (i64 i = 0; i < (i64)sSystemTable.numberOfConfigurationTables; ++i)
    {
        COMMON_LVV(("Processing configuration table #%d %s at address 0x%p", i, guidToString(configurationTables[i].vendorGuid), configurationTables[i].vendorTable));



        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_ACPI_20_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("ACPI 2.0 configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sAcpi20Config = (UefiAcpi20ConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_ACPI_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("ACPI configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sAcpiConfig = (UefiAcpiConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_DEBUG_INFO_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("Debug info configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sDebugInfoConfig = (UefiDebugInfoConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_DXE_SERVICES_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("DXE services configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sDxeServicesConfig = (UefiDxeServicesConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_HCDP_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("HCDP configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sHcdpConfig = (UefiHcdpConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_HOB_LIST_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("HOB list configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sHobListConfig = (UefiHobListConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_LZMA_DECOMPRESS_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("LZMA decompress configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sLzmaDecompressConfig = (UefiLzmaDecompressConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_MEMORY_STATUS_CODE_RECORD_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("Memory status code record configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sMemoryStatusCodeRecordConfig = (UefiMemoryStatusCodeRecordConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_MEMORY_ATTRIBUTES_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("Memory attributes configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sMemoryAttributesConfig = (UefiMemoryAttributesConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_MEMORY_TYPE_INFORMATION_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("Memory type information configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sMemoryTypeInformationConfig = (UefiMemoryTypeInformationConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_MPS_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("MPS configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sMpsConfig = (UefiMpsConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_PROPERTIES_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("Properties configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sPropertiesConfig = (UefiPropertiesConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_SAL_SYSTEM_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("SAL system configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sSalSystemConfig = (UefiSalSystemConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_SMBIOS_3_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("SMBIOS 3 configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sSmbios3Config = (UefiSmbios3ConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_SMBIOS_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("SMBIOS configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sSmbiosConfig = (UefiSmbiosConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_SYSTEM_RESOURCE_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("System resource configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sSystemResourceConfig = (UefiSystemResourceConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        if (isGuidEquals(configurationTables[i].vendorGuid, UEFI_UGA_IO_CONFIGURATION_TABLE_GUID))
        {
            COMMON_LV(("UGA IO configuration table found at address 0x%p", configurationTables[i].vendorTable));

            sUgaIoConfig = (UefiUgaIoConfigurationTable *)configurationTables[i].vendorTable;
        }
        else
        {
            COMMON_LW(("Unknown configuration table %s", guidToString(configurationTables[i].vendorGuid)));
        }
    }

    COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)configurationTables, sSystemTable.numberOfConfigurationTables * sizeof(UefiConfigurationTable)), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus UEFI::initMemoryAttributes()
{
    COMMON_LT((""));



    if (!sMemoryAttributesConfig)
    {
        COMMON_LVV(("sMemoryAttributesConfig is null"));

        return NgosStatus::OK;
    }



    UefiMemoryAttributesConfigurationTable *memoryAttrs;



    COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)sMemoryAttributesConfig, sizeof(UefiMemoryAttributesConfigurationTable), (void **)&memoryAttrs), NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("memoryAttrs->version         = %u", memoryAttrs->version));
        COMMON_LVVV(("memoryAttrs->numberOfEntries = %u", memoryAttrs->numberOfEntries));
        COMMON_LVVV(("memoryAttrs->descriptorSize  = %u", memoryAttrs->descriptorSize));



        COMMON_TEST_ASSERT(memoryAttrs->version            == 1,  NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(memoryAttrs->numberOfEntries == 28, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(memoryAttrs->descriptorSize  == 48, NgosStatus::ASSERTION); // Commented due to value variation
    }



    u64 memoryAttrsSize = sizeof(UefiMemoryAttributesConfigurationTable) + memoryAttrs->numberOfEntries * memoryAttrs->descriptorSize;
    COMMON_ASSERT_EXECUTION(MemoryManager::reserve((u64)sMemoryAttributesConfig, memoryAttrsSize), NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)memoryAttrs, sizeof(UefiMemoryAttributesConfigurationTable)), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}
