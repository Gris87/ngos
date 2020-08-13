#include "dmi.h"

#include <com/ngos/shared/common/dmi/entry/dmimemorydeviceentry.h>
#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/memory/memory.h>
#include <com/ngos/shared/common/string/utils.h>
#include <com/ngos/shared/common/uuid/utils.h>

#ifdef UEFI_APPLICATION // Defined in pro file
#include <com/ngos/shared/uefibase/uefi/uefi.h>
#else
#include <com/ngos/kernel/other/brk/brk.h>
#include <com/ngos/kernel/other/ioremap/ioremap.h>
#include <com/ngos/kernel/other/uefi/uefi.h>
#endif



u32                                            DMI::sVersion;
u16                                            DMI::sNumberOfSmbiosStructures;
u64                                            DMI::sStructureTableAddress;
u32                                            DMI::sStructureTableLength;
u16                                            DMI::sSystemPhysicalMemoryArrayHandle;
u64                                            DMI::sSystemPhysicalMemoryArrayCapacity;
u64                                            DMI::sTotalAmountOfMemory;
u64                                            DMI::sNumberOfInstalledMemoryDevices;
ArrayList<DmiMemoryDeviceEntry *>              DMI::sMemoryDeviceEntries;
ArrayList<DmiMemoryDeviceMappedAddressEntry *> DMI::sMemoryDeviceMappedAddressEntries;
ArrayList<DmiMemoryDevice>                     DMI::sMemoryDevices;
const char8*                                   DMI::sIdentities[(u64)DmiIdentity::MAXIMUM];
Uuid*                                          DMI::sUuids[(u64)DmiStoredUuid::MAXIMUM];



NgosStatus DMI::init()
{
    COMMON_LT((""));



    UefiSmbios3ConfigurationTable *smbios3 = UEFI::getSmbios3Config();

    if (smbios3)
    {
#ifdef UEFI_APPLICATION // Defined in pro file
        COMMON_ASSERT_EXECUTION(initFromSmbios3(smbios3), NgosStatus::ASSERTION);
#else
        UefiSmbios3ConfigurationTable *smbios3Mapped;

        COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)smbios3, sizeof(UefiSmbios3ConfigurationTable), (void **)&smbios3Mapped), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(initFromSmbios3(smbios3Mapped),                                                                         NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)smbios3Mapped, sizeof(UefiSmbios3ConfigurationTable)),                 NgosStatus::ASSERTION);
#endif
    }
    else
    {
        UefiSmbiosConfigurationTable *smbios = UEFI::getSmbiosConfig();

        if (smbios)
        {
#ifdef UEFI_APPLICATION // Defined in pro file
            COMMON_ASSERT_EXECUTION(initFromSmbios(smbios), NgosStatus::ASSERTION);
#else
            UefiSmbiosConfigurationTable *smbiosMapped;

            COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)smbios, sizeof(UefiSmbiosConfigurationTable), (void **)&smbiosMapped), NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(initFromSmbios(smbiosMapped),                                                                        NgosStatus::ASSERTION);
            COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)smbiosMapped, sizeof(UefiSmbiosConfigurationTable)),                NgosStatus::ASSERTION);
#endif
        }
        else
        {
            COMMON_LF(("DMI not present"));

            return NgosStatus::NOT_FOUND;
        }
    }



#ifdef UEFI_APPLICATION // Defined in pro file
    COMMON_ASSERT_EXECUTION(iterateDmiEntries((u8 *)sStructureTableAddress, decodeDmiEntry), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(storeDmiMemoryDevices(),                                         NgosStatus::ASSERTION);
#else
    u8 *buf;

    COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping(sStructureTableAddress, sStructureTableLength, (void **)&buf), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, decodeDmiEntry),                                                 NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(storeDmiMemoryDevices(),                                                                NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)buf, sStructureTableLength),                           NgosStatus::ASSERTION);
#endif



    COMMON_LV(("SMBIOS version is %u.%u", sVersion >> 16, (sVersion >> 8) & 0xFF));
    COMMON_LV(("DMI: %s %s, BIOS %s %s %s", sIdentities[(u64)DmiIdentity::SYSTEM_MANUFACTURER], sIdentities[(u64)DmiIdentity::SYSTEM_PRODUCT_NAME], sIdentities[(u64)DmiIdentity::BIOS_VENDOR], sIdentities[(u64)DmiIdentity::BIOS_VERSION], sIdentities[(u64)DmiIdentity::BIOS_RELEASE_DATE]));



    // Validation
    {
        COMMON_LVVV(("sVersion                           = 0x%08X", sVersion));
        COMMON_LVVV(("sNumberOfSmbiosStructures          = %u",     sNumberOfSmbiosStructures));
        COMMON_LVVV(("sStructureTableAddress             = 0x%p",   sStructureTableAddress));
        COMMON_LVVV(("sStructureTableLength              = %u",     sStructureTableLength));
        COMMON_LVVV(("sSystemPhysicalMemoryArrayHandle   = 0x%04X", sSystemPhysicalMemoryArrayHandle));
        COMMON_LVVV(("sSystemPhysicalMemoryArrayCapacity = %s",     bytesToString(sSystemPhysicalMemoryArrayCapacity)));
        COMMON_LVVV(("sTotalAmountOfMemory               = %s",     bytesToString(sTotalAmountOfMemory)));
        COMMON_LVVV(("sNumberOfInstalledMemoryDevices    = %u",     sNumberOfInstalledMemoryDevices));



        // sMemoryDeviceEntries:
        {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            COMMON_LVVV(("sMemoryDeviceEntries:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)sMemoryDeviceEntries.getSize(); ++i)
            {
                DmiMemoryDeviceEntry *device = sMemoryDeviceEntries.at(i);

                COMMON_LVVV(("#%-3d: 0x%p | 0x%04X | 0x%04X", i, device, device->header.handle, device->memoryArrayHandle));
            }

            COMMON_LVVV(("-------------------------------------"));
#endif
        }



        // sMemoryDeviceMappedAddressEntries:
        {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            COMMON_LVVV(("sMemoryDeviceMappedAddressEntries:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)sMemoryDeviceMappedAddressEntries.getSize(); ++i)
            {
                DmiMemoryDeviceMappedAddressEntry *device = sMemoryDeviceMappedAddressEntries.at(i);

                COMMON_LVVV(("#%-3d: 0x%p | 0x%04X | 0x%04X", i, device, device->header.handle, device->memoryDeviceHandle));
            }

            COMMON_LVVV(("-------------------------------------"));
#endif
        }



        // sMemoryDevices:
        {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            COMMON_LVVV(("sMemoryDevices:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)sMemoryDevices.getSize(); ++i)
            {
                const DmiMemoryDevice &device = sMemoryDevices.at(i);



                char8 startBuffer[11];
                char8 endBuffer[11];

                COMMON_ASSERT_EXECUTION(bytesToString(device.start, startBuffer, sizeof(startBuffer)), NgosStatus::ASSERTION);
                COMMON_ASSERT_EXECUTION(bytesToString(device.end,   endBuffer,   sizeof(endBuffer)),   NgosStatus::ASSERTION);



                COMMON_LVVV(("#%-3d: %s | %u MHz | %-5s | %5s - %-5s | %s | %s | %s | %s", i, enumToFullString(device.memoryType), device.speed, bytesToString(device.size), startBuffer, endBuffer, stringToString(device.deviceLocator), stringToString(device.manufacturer), stringToString(device.serialNumber), stringToString(device.partNumber)));
            }

            COMMON_LVVV(("-------------------------------------"));
#endif
        }



        // sIdentities:
        {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            COMMON_LVVV(("sIdentities:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)DmiIdentity::MAXIMUM; ++i)
            {
                if (sIdentities[i])
                {
                    COMMON_LVVV(("%-36s: 0x%p | %s", enumToFullString((DmiIdentity)i), sIdentities[i], sIdentities[i]));
                }
                else
                {
                    COMMON_LVVV(("%-36s: 0x%p", enumToFullString((DmiIdentity)i), sIdentities[i]));
                }
            }

            COMMON_LVVV(("-------------------------------------"));
#endif
        }



        // sUuids:
        {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            COMMON_LVVV(("sUuids:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)DmiStoredUuid::MAXIMUM; ++i)
            {
                COMMON_LVVV(("%-11s: %s", enumToFullString((DmiStoredUuid)i), uuidToString(sUuids[i])));
            }

            COMMON_LVVV(("-------------------------------------"));
#endif
        }



        // COMMON_TEST_ASSERT(sVersion                                    == 0x00020800, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sNumberOfSmbiosStructures                   == 9,          NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sStructureTableAddress                         != 0,          NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sStructureTableLength                       == 395,        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sSystemPhysicalMemoryArrayHandle            == 0x1000,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sSystemPhysicalMemoryArrayCapacity          == GB,         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sTotalAmountOfMemory                        == GB,         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sNumberOfInstalledMemoryDevices             == 1,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDeviceEntries.getSize()              == 1,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDeviceEntries.at(0)                  != nullptr,    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDeviceMappedAddressEntries.getSize() == 0,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices.getSize()                    == 1,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices.at(0).size                   == GB,         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices.at(0).deviceLocator          != nullptr,    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices.at(0).manufacturer           != nullptr,    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices.at(0).serialNumber           != nullptr,    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices.at(0).partNumber             != nullptr,    NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((u64)DmiIdentity::MAXIMUM                      == 7,          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[0]                                 != nullptr,    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[1]                                 != nullptr,    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[2]                                 != nullptr,    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[3]                                 != nullptr,    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[4]                                 != nullptr,    NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sIdentities[5]                              != nullptr,    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[6]                              != nullptr,    NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((u64)DmiStoredUuid::MAXIMUM                    == 1,          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sUuids[0]                                      != nullptr,    NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sUuids[0]->data1                            == 0x9FAE0773, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data2                            == 0xF53F,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data3                            == 0x4A15,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data4                            == 0x8A,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data5                            == 0x11,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[0]                         == 0xED,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[1]                         == 0x76,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[2]                         == 0xA1,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[3]                         == 0x0F,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[4]                         == 0x4E,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[5]                         == 0x5B,       NgosStatus::ASSERTION); // Commented due to value variation
    }



    return NgosStatus::OK;
}

NgosStatus DMI::iterateDmiEntries(u8 *buf, process_dmi_entry processDmiEntry)
{
    COMMON_LT((" | buf = 0x%p, processDmiEntry = 0x%p", buf, processDmiEntry));

    COMMON_ASSERT(buf,             "buf is null",             NgosStatus::ASSERTION);
    COMMON_ASSERT(processDmiEntry, "processDmiEntry is null", NgosStatus::ASSERTION);



    i64  i   = 0;
    u8  *cur = buf;

    while (
           sNumberOfSmbiosStructures == 0
           ||
           i < sNumberOfSmbiosStructures
          )
    {
        DmiEntryHeader *dmiEntryHeader = (DmiEntryHeader *)cur;



        COMMON_LVV(("Processing DMI header at address 0x%p", dmiEntryHeader));

        COMMON_LVVV(("dmiEntryHeader->type   = %s",     enumToFullString(dmiEntryHeader->type)));
        COMMON_LVVV(("dmiEntryHeader->length = %u",     dmiEntryHeader->length));
        COMMON_LVVV(("dmiEntryHeader->handle = 0x%04X", dmiEntryHeader->handle));



        cur += dmiEntryHeader->length;

        // We are getting total DMI entry size until we met 2 zeros in buffer that let us avoid issues on decoding
        do
        {
            if (
                cur[0] == 0
                &&
                cur[1] == 0
               )
            {
                break;
            }

            ++cur;
        } while(true);

        cur += 2;
        ++i;



        if (dmiEntryHeader->type == DmiEntryType::END_OF_TABLE)
        {
            break;
        }



        COMMON_ASSERT_EXECUTION(processDmiEntry(dmiEntryHeader), NgosStatus::ASSERTION);
    }

    COMMON_TEST_ASSERT(sNumberOfSmbiosStructures == 0 || cur == buf + sStructureTableLength, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sNumberOfSmbiosStructures == 0 || i   == sNumberOfSmbiosStructures,   NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

u32 DMI::getVersion()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sVersion;
}

u64 DMI::getStructureTableAddress()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sStructureTableAddress;
}

u64 DMI::getSystemPhysicalMemoryArrayCapacity()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sSystemPhysicalMemoryArrayCapacity;
}

u64 DMI::getTotalAmountOfMemory()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sTotalAmountOfMemory;
}

u64 DMI::getNumberOfInstalledMemoryDevices()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sNumberOfInstalledMemoryDevices;
}

const ArrayList<DmiMemoryDevice>& DMI::getMemoryDevices()
{
    // COMMON_LT(("")); // Commented to avoid too frequent logs



    return sMemoryDevices;
}

const char8* DMI::getIdentity(DmiIdentity id)
{
    // COMMON_LT((" | id = %u", id)); // Commented to avoid too frequent logs



    return sIdentities[(u64)id];
}

Uuid* DMI::getUuid(DmiStoredUuid id)
{
    // COMMON_LT((" | id = %u", id)); // Commented to avoid too frequent logs



    return sUuids[(u64)id];
}

NgosStatus DMI::initFromSmbios3(UefiSmbios3ConfigurationTable *smbios3)
{
    COMMON_LT((" | smbios3 = 0x%p", smbios3));

    COMMON_ASSERT(smbios3, "smbios3 is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("smbios3->anchor                      = %.5s", smbios3->anchor));
        COMMON_LVVV(("smbios3->entryPointStructureChecksum = %u",   smbios3->entryPointStructureChecksum));
        COMMON_LVVV(("smbios3->entryPointLength            = %u",   smbios3->entryPointLength));
        COMMON_LVVV(("smbios3->majorVersion                = %u",   smbios3->majorVersion));
        COMMON_LVVV(("smbios3->minorVersion                = %u",   smbios3->minorVersion));
        COMMON_LVVV(("smbios3->docRevision                 = %u",   smbios3->docRevision));
        COMMON_LVVV(("smbios3->entryPointRevision          = %u",   smbios3->entryPointRevision));
        COMMON_LVVV(("smbios3->structureTableMaximumSize   = %u",   smbios3->structureTableMaximumSize));
        COMMON_LVVV(("smbios3->structureTableAddress       = 0x%p", smbios3->structureTableAddress));



        COMMON_TEST_ASSERT((*(u64 *)smbios3->anchor & 0x000000FFFFFFFFFF) == SMBIOS_3_ANCHOR,                                                                          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->entryPointStructureChecksum           == checksum((u8 *)smbios3, smbios3->entryPointLength, smbios3->entryPointStructureChecksum), NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->entryPointLength                      == 24,                                                                                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->majorVersion                          == 3,                                                                                        NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios3->minorVersion                       == 3,                                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(smbios3->docRevision                        == 0,                                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios3->entryPointRevision                    == 1,                                                                                        NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios3->structureTableMaximumSize          == 4070,                                                                                     NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios3->structureTableAddress                 != 0,                                                                                        NgosStatus::ASSERTION);
    }



    sVersion               = DMI_VERSION_3(smbios3->majorVersion, smbios3->minorVersion, smbios3->docRevision);
    sStructureTableAddress = smbios3->structureTableAddress;
    sStructureTableLength  = smbios3->structureTableMaximumSize;



    return NgosStatus::OK;
}

NgosStatus DMI::initFromSmbios(UefiSmbiosConfigurationTable *smbios)
{
    COMMON_LT((" | smbios = 0x%p", smbios));

    COMMON_ASSERT(smbios, "smbios is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("smbios->anchor                      = %.4s",   &smbios->anchor));
        COMMON_LVVV(("smbios->entryPointStructureChecksum = %u",      smbios->entryPointStructureChecksum));
        COMMON_LVVV(("smbios->entryPointLength            = %u",      smbios->entryPointLength));
        COMMON_LVVV(("smbios->majorVersion                = %u",      smbios->majorVersion));
        COMMON_LVVV(("smbios->minorVersion                = %u",      smbios->minorVersion));
        COMMON_LVVV(("smbios->maximumStructureSize        = %u",      smbios->maximumStructureSize));
        COMMON_LVVV(("smbios->entryPointRevision          = %u",      smbios->entryPointRevision));
        COMMON_LVVV(("smbios->formattedArea[0]            = %u",      smbios->formattedArea[0]));
        COMMON_LVVV(("smbios->formattedArea[1]            = %u",      smbios->formattedArea[1]));
        COMMON_LVVV(("smbios->formattedArea[2]            = %u",      smbios->formattedArea[2]));
        COMMON_LVVV(("smbios->formattedArea[3]            = %u",      smbios->formattedArea[3]));
        COMMON_LVVV(("smbios->formattedArea[4]            = %u",      smbios->formattedArea[4]));
        COMMON_LVVV(("smbios->intermediateAnchor          = %.5s",    smbios->intermediateAnchor));
        COMMON_LVVV(("smbios->intermediateChecksum        = %u",      smbios->intermediateChecksum));
        COMMON_LVVV(("smbios->structureTableLength        = %u",      smbios->structureTableLength));
        COMMON_LVVV(("smbios->structureTableAddress       = 0x%p",    smbios->structureTableAddress));
        COMMON_LVVV(("smbios->numberOfSmbiosStructures    = %u",      smbios->numberOfSmbiosStructures));
        COMMON_LVVV(("smbios->bcdRevision                 = 0x%02X",  smbios->bcdRevision));



        COMMON_TEST_ASSERT(smbios->anchor                                            == SMBIOS_ANCHOR,                                                                         NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->entryPointStructureChecksum                       == checksum((u8 *)smbios, smbios->entryPointLength, smbios->entryPointStructureChecksum), NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->entryPointLength                                  == 31,                                                                                    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->majorVersion                                      == 2,                                                                                     NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios->minorVersion                                   == 8,                                                                                     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(smbios->maximumStructureSize                           == 81,                                                                                    NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios->entryPointRevision                                == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[0]                                  == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[1]                                  == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[2]                                  == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[3]                                  == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[4]                                  == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT((*(u64 *)smbios->intermediateAnchor & 0x000000FFFFFFFFFF) == SMBIOS_INTERMEDIATE_ANCHOR,                                                            NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->intermediateChecksum                              == checksum((u8 *)&smbios->intermediateAnchor, 15, smbios->intermediateChecksum),         NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios->structureTableLength                           == 395,                                                                                   NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios->structureTableAddress                             != 0,                                                                                     NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios->numberOfSmbiosStructures                       == 9,                                                                                     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(smbios->bcdRevision                                    == 0x28,                                                                                  NgosStatus::ASSERTION); // Commented due to value variation
    }



    sVersion                  = DMI_VERSION(smbios->majorVersion, smbios->minorVersion);
    sNumberOfSmbiosStructures = smbios->numberOfSmbiosStructures;
    sStructureTableAddress    = smbios->structureTableAddress;
    sStructureTableLength     = smbios->structureTableLength;



    return NgosStatus::OK;
}

NgosStatus DMI::decodeDmiEntry(DmiEntryHeader *header)
{
    COMMON_LT((" | header = 0x%p", header));

    COMMON_ASSERT(header, "header is null", NgosStatus::ASSERTION);



    switch (header->type)
    {
        case DmiEntryType::BIOS:                             COMMON_ASSERT_EXECUTION(saveDmiBiosEntry((DmiBiosEntry *)header),                                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM:                           COMMON_ASSERT_EXECUTION(saveDmiSystemEntry((DmiSystemEntry *)header),                                               NgosStatus::ASSERTION); break;
        case DmiEntryType::BASEBOARD:                        COMMON_ASSERT_EXECUTION(saveDmiBaseboardEntry((DmiBaseboardEntry *)header),                                         NgosStatus::ASSERTION); break;
        case DmiEntryType::CHASSIS:                          COMMON_ASSERT_EXECUTION(saveDmiChassisEntry((DmiChassisEntry *)header),                                             NgosStatus::ASSERTION); break;
        case DmiEntryType::PROCESSOR:                        COMMON_ASSERT_EXECUTION(saveDmiProcessorEntry((DmiProcessorEntry *)header),                                         NgosStatus::ASSERTION); break;
        case DmiEntryType::CACHE:                            COMMON_ASSERT_EXECUTION(saveDmiCacheEntry((DmiCacheEntry *)header),                                                 NgosStatus::ASSERTION); break;
        case DmiEntryType::PORT_CONNECTOR:                   COMMON_ASSERT_EXECUTION(saveDmiPortConnectorEntry((DmiPortConnectorEntry *)header),                                 NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_SLOTS:                     COMMON_ASSERT_EXECUTION(saveDmiSystemSlotsEntry((DmiSystemSlotsEntry *)header),                                     NgosStatus::ASSERTION); break;
        case DmiEntryType::ONBOARD_DEVICES:                  COMMON_ASSERT_EXECUTION(saveDmiOnboardDevicesEntry((DmiOnboardDevicesEntry *)header),                               NgosStatus::ASSERTION); break;
        case DmiEntryType::OEM_STRINGS:                      COMMON_ASSERT_EXECUTION(saveDmiOemStringsEntry((DmiOemStringsEntry *)header),                                       NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_CONFIGURATION:             COMMON_ASSERT_EXECUTION(saveDmiSystemConfigurationEntry((DmiSystemConfigurationEntry *)header),                     NgosStatus::ASSERTION); break;
        case DmiEntryType::BIOS_LANGUAGE:                    COMMON_ASSERT_EXECUTION(saveDmiBiosLanguageEntry((DmiBiosLanguageEntry *)header),                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::GROUP_ASSOCIATIONS:               COMMON_ASSERT_EXECUTION(saveDmiGroupAssociationsEntry((DmiGroupAssociationsEntry *)header),                         NgosStatus::ASSERTION); break;
        case DmiEntryType::PHYSICAL_MEMORY_ARRAY:            COMMON_ASSERT_EXECUTION(saveDmiPhysicalMemoryArrayEntry((DmiPhysicalMemoryArrayEntry *)header),                     NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_DEVICE:                    COMMON_ASSERT_EXECUTION(saveDmiMemoryDeviceEntry((DmiMemoryDeviceEntry *)header),                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::BITS32_MEMORY_ERROR:              COMMON_ASSERT_EXECUTION(saveDmiBits32MemoryErrorInformationEntry((DmiBits32MemoryErrorInformationEntry *)header),   NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS:      COMMON_ASSERT_EXECUTION(saveDmiMemoryArrayMappedAddressEntry((DmiMemoryArrayMappedAddressEntry *)header),           NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_DEVICE_MAPPED_ADDRESS:     COMMON_ASSERT_EXECUTION(saveDmiMemoryDeviceMappedAddressEntry((DmiMemoryDeviceMappedAddressEntry *)header),         NgosStatus::ASSERTION); break;
        case DmiEntryType::PORTABLE_BATTERY:                 COMMON_ASSERT_EXECUTION(saveDmiPortableBatteryEntry((DmiPortableBatteryEntry *)header),                             NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_RESET:                     COMMON_ASSERT_EXECUTION(saveDmiSystemResetEntry((DmiSystemResetEntry *)header),                                     NgosStatus::ASSERTION); break;
        case DmiEntryType::HARDWARE_SECURITY:                COMMON_ASSERT_EXECUTION(saveDmiHardwareSecurityEntry((DmiHardwareSecurityEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::VOLTAGE_PROBE:                    COMMON_ASSERT_EXECUTION(saveDmiVoltageProbeEntry((DmiVoltageProbeEntry *)header),                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::COOLING_DEVICE:                   COMMON_ASSERT_EXECUTION(saveDmiCoolingDeviceEntry((DmiCoolingDeviceEntry *)header),                                 NgosStatus::ASSERTION); break;
        case DmiEntryType::TEMPERATURE_PROBE:                COMMON_ASSERT_EXECUTION(saveDmiTemperatureProbeEntry((DmiTemperatureProbeEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::ELECTRICAL_CURRENT_PROBE:         COMMON_ASSERT_EXECUTION(saveDmiElectricalCurrentProbeEntry((DmiElectricalCurrentProbeEntry *)header),               NgosStatus::ASSERTION); break;
        case DmiEntryType::OUT_OF_BAND_REMOTE_ACCESS:        COMMON_ASSERT_EXECUTION(saveDmiOutOfBandRemoteAccessEntry((DmiOutOfBandRemoteAccessEntry *)header),                 NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_BOOT:                      COMMON_ASSERT_EXECUTION(saveDmiSystemBootEntry((DmiSystemBootEntry *)header),                                       NgosStatus::ASSERTION); break;
        case DmiEntryType::BITS64_MEMORY_ERROR:              COMMON_ASSERT_EXECUTION(saveDmiBits64MemoryErrorInformationEntry((DmiBits64MemoryErrorInformationEntry *)header),   NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE:                COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceEntry((DmiManagementDeviceEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE_COMPONENT:      COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceComponentEntry((DmiManagementDeviceComponentEntry *)header),         NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE_THRESHOLD_DATA: COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceThresholdDataEntry((DmiManagementDeviceThresholdDataEntry *)header), NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_POWER_SUPPLY:              COMMON_ASSERT_EXECUTION(saveDmiSystemPowerSupplyEntry((DmiSystemPowerSupplyEntry *)header),                         NgosStatus::ASSERTION); break;
        case DmiEntryType::ADDITIONAL:                       COMMON_ASSERT_EXECUTION(saveDmiAdditionalInformationEntry((DmiAdditionalInformationEntry *)header),                 NgosStatus::ASSERTION); break;
        case DmiEntryType::ONBOARD_DEVICES_EXTENDED:         COMMON_ASSERT_EXECUTION(saveDmiOnboardDevicesExtendedEntry((DmiOnboardDevicesExtendedEntry *)header),               NgosStatus::ASSERTION); break;
        case DmiEntryType::INACTIVE:                         COMMON_ASSERT_EXECUTION(saveDmiInactiveEntry((DmiInactiveEntry *)header),                                           NgosStatus::ASSERTION); break;

        default:
        {
            COMMON_LVV(("Ignoring DMI entry at address 0x%p with type %s", header, enumToFullString(header->type)));
        }
        break;
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiBiosEntry(DmiBiosEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiBiosEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiBiosEntryV21) ? (DmiBiosEntryV21 *)entry : nullptr;
    DmiBiosEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiBiosEntryV23) ? (DmiBiosEntryV23 *)entry : nullptr;
    DmiBiosEntryV24 *entryV24 = DMI::getVersion() >= DMI_VERSION(2, 4) && entry->header.length >= sizeof(DmiBiosEntryV24) ? (DmiBiosEntryV24 *)entry : nullptr;
    DmiBiosEntryV31 *entryV31 = DMI::getVersion() >= DMI_VERSION(3, 1) && entry->header.length >= sizeof(DmiBiosEntryV31) ? (DmiBiosEntryV31 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->vendor.id                  = %u",     entry->vendor.id));
            COMMON_LVVV(("entry->biosVersion.id             = %u",     entry->biosVersion.id));
            COMMON_LVVV(("entry->biosStartingAddressSegment = 0x%04X", entry->biosStartingAddressSegment));
            COMMON_LVVV(("entry->biosReleaseDate.id         = %u",     entry->biosReleaseDate.id));
            COMMON_LVVV(("entry->biosRomSize.value          = 0x%02X", entry->biosRomSize.value));
            COMMON_LVVV(("entry->biosRomSize                = %s",     bytesToString(entry->biosRomSize.size())));
            COMMON_LVVV(("entry->biosCharacteristics        = %s",     flagsToFullString(entry->biosCharacteristics)));

            if (entryV21)
            {
                COMMON_LVVV(("entryV21->biosCharacteristicsExtensionBiosReserved = %s", flagsToFullString(entryV21->biosCharacteristicsExtensionBiosReserved)));

                if (entryV23)
                {
                    COMMON_LVVV(("entryV23->biosCharacteristicsExtensionSystemReserved = %s", flagsToFullString(entryV23->biosCharacteristicsExtensionSystemReserved)));

                    if (entryV24)
                    {
                        COMMON_LVVV(("entryV24->systemBiosMajorRelease                 = %u", entryV24->systemBiosMajorRelease));
                        COMMON_LVVV(("entryV24->systemBiosMinorRelease                 = %u", entryV24->systemBiosMinorRelease));
                        COMMON_LVVV(("entryV24->embeddedControllerFirmwareMajorRelease = %u", entryV24->embeddedControllerFirmwareMajorRelease));
                        COMMON_LVVV(("entryV24->embeddedControllerFirmwareMinorRelease = %u", entryV24->embeddedControllerFirmwareMinorRelease));

                        if (entryV31)
                        {
                            COMMON_LVVV(("entryV31->extendedBiosRomSize.value   = %u",     entryV31->extendedBiosRomSize.value));
                            COMMON_LVVV(("entryV31->extendedBiosRomSize.unit    = %s",     enumToFullString((DmiBiosExtendedRomSizeUnit)entryV31->extendedBiosRomSize.unit)));
                            COMMON_LVVV(("entryV31->extendedBiosRomSize.value16 = 0x%04X", entryV31->extendedBiosRomSize.value16));
                            COMMON_LVVV(("entryV31->extendedBiosRomSize         = %s",     bytesToString(entryV31->extendedBiosRomSize.size())));
                        }
                    }
                }
            }
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(entry->vendor.id                     == 1,                                                                     NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->biosVersion.id                == 2,                                                                     NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->biosStartingAddressSegment == 0xE800,                                                                NgosStatus::ASSERTION); // Commented due to value variation
            COMMON_TEST_ASSERT(entry->biosReleaseDate.id            == 3,                                                                     NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->biosRomSize.value          == 0xFF,                                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->biosCharacteristics        == FLAGS(DmiBiosCharacteristicsFlag::BIOS_CHARACTERISTICS_NOT_SUPPORTED), NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV21)
            {
                // COMMON_TEST_ASSERT(entryV21->biosCharacteristicsExtensionBiosReserved == FLAG(DmiBiosCharacteristicsBiosReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV23)
                {
                    // COMMON_TEST_ASSERT(entryV23->biosCharacteristicsExtensionSystemReserved == FLAG(DmiBiosCharacteristicsSystemReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

                    if (entryV24)
                    {
                        // COMMON_TEST_ASSERT(entryV24->systemBiosMajorRelease                 == 15,  NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entryV24->systemBiosMinorRelease                 == 103, NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entryV24->embeddedControllerFirmwareMajorRelease == 151, NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entryV24->embeddedControllerFirmwareMinorRelease == 78,  NgosStatus::ASSERTION); // Commented due to value variation

                        if (entryV31)
                        {
                            // COMMON_TEST_ASSERT(entryV31->extendedBiosRomSize.value   == 0,                                     NgosStatus::ASSERTION); // Commented due to value variation
                            // COMMON_TEST_ASSERT(entryV31->extendedBiosRomSize.unit    == DmiBiosExtendedRomSizeUnit::MEGABYTES, NgosStatus::ASSERTION); // Commented due to value variation
                            // COMMON_TEST_ASSERT(entryV31->extendedBiosRomSize.value16 == 0x0000,                                NgosStatus::ASSERTION); // Commented due to value variation

                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV31), NgosStatus::ASSERTION);
                        }
                        else
                        {
                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV24), NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV23), NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        if (
            entry->vendor.id
            ||
            entry->biosVersion.id
            ||
            entry->biosReleaseDate.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->vendor)
                    {
                        COMMON_LVVV(("vendor = %s", begin));
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BIOS_VENDOR, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == entry->biosVersion)
                    {
                        COMMON_LVVV(("biosVersion = %s", begin));
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BIOS_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == entry->biosReleaseDate)
                    {
                        COMMON_LVVV(("biosReleaseDate = %s", begin));
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BIOS_RELEASE_DATE, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemEntry(DmiSystemEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiSystemEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiSystemEntryV21) ? (DmiSystemEntryV21 *)entry : nullptr;
    DmiSystemEntryV24 *entryV24 = DMI::getVersion() >= DMI_VERSION(2, 4) && entry->header.length >= sizeof(DmiSystemEntryV24) ? (DmiSystemEntryV24 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->manufacturer.id = %u", entry->manufacturer.id));
            COMMON_LVVV(("entry->productName.id  = %u", entry->productName.id));
            COMMON_LVVV(("entry->version.id      = %u", entry->version.id));
            COMMON_LVVV(("entry->serialNumber.id = %u", entry->serialNumber.id));

            if (entryV21)
            {
                COMMON_LVVV(("entryV21->uuid       = %s", uuidToString(entryV21->uuid)));
                COMMON_LVVV(("entryV21->wakeUpType = %s", enumToFullString(entryV21->wakeUpType)));

                if (entryV24)
                {
                    COMMON_LVVV(("entryV24->skuNumber.id = %u", entryV24->skuNumber.id));
                    COMMON_LVVV(("entryV24->family.id    = %u", entryV24->family.id));
                }
            }
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(entry->manufacturer.id    == 1, NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->productName.id  == 2, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->version.id      == 3, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->serialNumber.id == 4, NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV21)
            {
                // COMMON_TEST_ASSERT(entryV21->uuid.data1    == 0x9FAE0773,                        NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data2    == 0xF53F,                            NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data3    == 0x4A15,                            NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data4    == 0x8A,                              NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data5    == 0x11,                              NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[0] == 0xED,                              NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[1] == 0x76,                              NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[2] == 0xA1,                              NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[3] == 0x0F,                              NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[4] == 0x4E,                              NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->uuid.data6[5] == 0x5B,                              NgosStatus::ASSERTION); // Commented due to value variation
                COMMON_TEST_ASSERT(entryV21->wakeUpType       == DmiSystemWakeUpType::POWER_SWITCH, NgosStatus::ASSERTION);

                if (entryV24)
                {
                    // COMMON_TEST_ASSERT(entryV24->skuNumber.id == 5, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV24->family.id    == 6, NgosStatus::ASSERTION); // Commented due to value variation

                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntryV24), NgosStatus::ASSERTION);
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId skuNumberStringId;
        DmiStringId familyStringId;

        if (entryV24)
        {
            skuNumberStringId = entryV24->skuNumber;
            familyStringId    = entryV24->family;
        }



        if (
            entry->manufacturer.id
            ||
            entry->productName.id
            ||
            entry->version.id
            ||
            entry->serialNumber.id
            ||
            skuNumberStringId.id
            ||
            familyStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->manufacturer)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::SYSTEM_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == entry->productName)
                    {
                        COMMON_LVVV(("productName = %s", begin));
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::SYSTEM_PRODUCT_NAME, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == entry->version)
                    {
                        COMMON_LVVV(("version = %s", begin));
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == skuNumberStringId)
                    {
                        COMMON_LVVV(("skuNumber = %s", begin));
                    }
                    else
                    if (stringId == familyStringId)
                    {
                        COMMON_LVVV(("family = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    if (entryV21)
    {
        COMMON_ASSERT_EXECUTION(storeUuid(DmiStoredUuid::SYSTEM_UUID, &entryV21->uuid), NgosStatus::ASSERTION);
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiBaseboardEntry(DmiBaseboardEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->manufacturer.id                = %u",     entry->manufacturer.id));
            COMMON_LVVV(("entry->product.id                     = %u",     entry->product.id));
            COMMON_LVVV(("entry->version.id                     = %u",     entry->version.id));
            COMMON_LVVV(("entry->serialNumber.id                = %u",     entry->serialNumber.id));
            COMMON_LVVV(("entry->assetTag.id                    = %u",     entry->assetTag.id));
            COMMON_LVVV(("entry->featureFlags                   = %s",     flagsToFullString(entry->featureFlags)));
            COMMON_LVVV(("entry->locationInChassis.id           = %u",     entry->locationInChassis.id));
            COMMON_LVVV(("entry->chassisHandle                  = 0x%04X", entry->chassisHandle));
            COMMON_LVVV(("entry->boardType                      = %s",     enumToFullString(entry->boardType)));
            COMMON_LVVV(("entry->numberOfContainedObjectHandles = %u",     entry->numberOfContainedObjectHandles));



            // entry->containedObjectHandles:
            {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                COMMON_LVVV(("entry->containedObjectHandles:"));
                COMMON_LVVV(("-------------------------------------"));

                for (i64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)
                {
                    COMMON_LVVV(("#%-3d: 0x%04X", i, entry->containedObjectHandles[i]));
                }

                COMMON_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(entry->manufacturer.id                == 1,                                           NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->product.id                     == 2,                                           NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->version.id                     == 3,                                           NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->serialNumber.id             == 4,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->assetTag.id                 == 5,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->featureFlags                == FLAGS(DmiBaseboardFeatureFlag::MOTHERBOARD), NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->locationInChassis.id        == 6,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->chassisHandle               == 0x0300,                                      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->boardType                   == DmiBaseboardType::MOTHERBOARD,               NgosStatus::ASSERTION); // Commented due to value variation
            COMMON_TEST_ASSERT(entry->numberOfContainedObjectHandles == 0,                                           NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->containedObjectHandles[0]   == 0,                                           NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBaseboardEntry) + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            entry->manufacturer.id
            ||
            entry->product.id
            ||
            entry->version.id
            ||
            entry->serialNumber.id
            ||
            entry->assetTag.id
            ||
            entry->locationInChassis.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->manufacturer)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BASEBOARD_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == entry->product)
                    {
                        COMMON_LVVV(("product = %s", begin));
                        COMMON_ASSERT_EXECUTION(storeIdentity(DmiIdentity::BASEBOARD_PRODUCT, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == entry->version)
                    {
                        COMMON_LVVV(("version = %s", begin));
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->assetTag)
                    {
                        COMMON_LVVV(("assetTag = %s", begin));
                    }
                    else
                    if (stringId == entry->locationInChassis)
                    {
                        COMMON_LVVV(("locationInChassis = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiChassisEntry(DmiChassisEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiChassisEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1)                        && entry->header.length >= sizeof(DmiChassisEntryV21)                                                                                                         ? (DmiChassisEntryV21 *)entry                                                                    : nullptr;
    DmiChassisEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3)                        && entry->header.length >= sizeof(DmiChassisEntryV23)                                                                                                         ? (DmiChassisEntryV23 *)entry                                                                    : nullptr;
    DmiChassisEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entryV23 != nullptr && entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength + sizeof(DmiChassisEntryV27) ? (DmiChassisEntryV27 *)DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, entryV23->containedElementCount) : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->manufacturer.id = %u",     entry->manufacturer.id));
            COMMON_LVVV(("entry->type            = %s",     enumToFullString((DmiChassisType)entry->type)));
            COMMON_LVVV(("entry->locked          = %u",     entry->locked));
            COMMON_LVVV(("entry->typeAndLocked   = 0x%02X", entry->typeAndLocked));
            COMMON_LVVV(("entry->version.id      = %u",     entry->version.id));
            COMMON_LVVV(("entry->serialNumber.id = %u",     entry->serialNumber.id));
            COMMON_LVVV(("entry->assetTag.id     = %u",     entry->assetTag.id));

            if (entryV21)
            {
                COMMON_LVVV(("entryV21->bootUpState      = %s", enumToFullString(entryV21->bootUpState)));
                COMMON_LVVV(("entryV21->powerSupplyState = %s", enumToFullString(entryV21->powerSupplyState)));
                COMMON_LVVV(("entryV21->thermalState     = %s", enumToFullString(entryV21->thermalState)));
                COMMON_LVVV(("entryV21->securityStatus   = %s", enumToFullString(entryV21->securityStatus)));

                if (entryV23)
                {
                    COMMON_LVVV(("entryV23->oemDefined                   = 0x%08X", entryV23->oemDefined));
                    COMMON_LVVV(("entryV23->height                       = %u",     entryV23->height));
                    COMMON_LVVV(("entryV23->numberOfPowerCords           = %u",     entryV23->numberOfPowerCords));
                    COMMON_LVVV(("entryV23->containedElementCount        = %u",     entryV23->containedElementCount));
                    COMMON_LVVV(("entryV23->containedElementRecordLength = %u",     entryV23->containedElementRecordLength));



                    // entryV23->containedElements:
                    {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                        COMMON_LVVV(("entryV23->containedElements:"));
                        COMMON_LVVV(("-------------------------------------"));

                        for (i64 i = 0; i < entryV23->containedElementCount; ++i)
                        {
                            DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, i);

                            COMMON_LVVV(("containedElement[%-3d]->type.typeSelect = %s", i, enumToFullString((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect)));

                            switch ((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect)
                            {
                                case DmiChassisContainedElementTypeSelect::BASEBOARD_TYPE: COMMON_LVVV(("containedElement[%-3d]->type.baseboardType = %s", i, enumToFullString((DmiBaseboardType)containedElement->type.baseboardType))); break;
                                case DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE: COMMON_LVVV(("containedElement[%-3d]->type.dmiEntryType  = %s", i, enumToFullString((DmiEntryType)containedElement->type.dmiEntryType)));      break;

                                default:
                                {
                                    COMMON_LF(("Unknown DMI chassis contained element type select %s, %s:%u", enumToFullString((DmiChassisContainedElementTypeSelect)containedElement->type.typeSelect), __FILE__, __LINE__));

                                    return NgosStatus::UNEXPECTED_BEHAVIOUR;
                                }
                                break;
                            }

                            COMMON_LVVV(("containedElement[%-3d]->type.value8 = 0x%02X", i, containedElement->type.value8));
                            COMMON_LVVV(("containedElement[%-3d]->minimum     = %u",     i, containedElement->minimum));
                            COMMON_LVVV(("containedElement[%-3d]->maximum     = %u",     i, containedElement->maximum));
                        }

                        COMMON_LVVV(("-------------------------------------"));
#endif
                    }



                    if (entryV27)
                    {
                        COMMON_LVVV(("entryV27->skuNumber.id = %u", entryV27->skuNumber.id));
                    }
                }
            }
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(entry->manufacturer.id    == 1,                       NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->type            == DmiChassisType::DESKTOP, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->locked          == 0,                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->typeAndLocked   == 0x03,                    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->version.id      == 2,                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->serialNumber.id == 3,                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->assetTag.id     == 4,                       NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV21)
            {
                COMMON_TEST_ASSERT(entryV21->bootUpState       == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entryV21->powerSupplyState  == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entryV21->thermalState   == DmiChassisState::SAFE,             NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->securityStatus == DmiChassisSecurityStatus::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV23)
                {
                    COMMON_TEST_ASSERT(entryV23->oemDefined                                             == 0x00000000,                                           NgosStatus::ASSERTION);
                    // COMMON_TEST_ASSERT(entryV23->height                                              == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV23->numberOfPowerCords                                  == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV23->containedElementCount                               == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV23->containedElementRecordLength                        == 3,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->type.typeSelect   == DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->type.dmiEntryType == DmiEntryType::SYSTEM_POWER_SUPPLY,                    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->type.value8       == 0xA7,                                                 NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->minimum           == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entryV23, 0)->maximum           == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation

                    if (entryV27)
                    {
                        // COMMON_TEST_ASSERT(entryV27->skuNumber.id == 5, NgosStatus::ASSERTION); // Commented due to value variation

                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength + sizeof(DmiChassisEntryV27), NgosStatus::ASSERTION);
                    }
                    else
                    {
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV23) + entryV23->containedElementCount * entryV23->containedElementRecordLength, NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId skuNumberStringId;

        if (entryV27)
        {
            skuNumberStringId = entryV27->skuNumber;
        }



        if (
            entry->manufacturer.id
            ||
            entry->version.id
            ||
            entry->serialNumber.id
            ||
            entry->assetTag.id
            ||
            skuNumberStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->manufacturer)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                    }
                    else
                    if (stringId == entry->version)
                    {
                        COMMON_LVVV(("version = %s", begin));
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->assetTag)
                    {
                        COMMON_LVVV(("assetTag = %s", begin));
                    }
                    else
                    if (stringId == skuNumberStringId)
                    {
                        COMMON_LVVV(("skuNumber = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiProcessorEntry(DmiProcessorEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiProcessorEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiProcessorEntryV21) ? (DmiProcessorEntryV21 *)entry : nullptr;
    DmiProcessorEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiProcessorEntryV23) ? (DmiProcessorEntryV23 *)entry : nullptr;
    DmiProcessorEntryV25 *entryV25 = DMI::getVersion() >= DMI_VERSION(2, 5) && entry->header.length >= sizeof(DmiProcessorEntryV25) ? (DmiProcessorEntryV25 *)entry : nullptr;
    DmiProcessorEntryV26 *entryV26 = DMI::getVersion() >= DMI_VERSION(2, 6) && entry->header.length >= sizeof(DmiProcessorEntryV26) ? (DmiProcessorEntryV26 *)entry : nullptr;
    DmiProcessorEntryV30 *entryV30 = DMI::getVersion() >= DMI_VERSION(3, 0) && entry->header.length >= sizeof(DmiProcessorEntryV30) ? (DmiProcessorEntryV30 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->socketDesignation.id                 = %u",     entry->socketDesignation.id));
            COMMON_LVVV(("entry->processorType                        = %s",     enumToFullString(entry->processorType)));
            COMMON_LVVV(("entry->processorFamily                      = %s",     enumToFullString(entry->processorFamily)));
            COMMON_LVVV(("entry->processorManufacturer.id             = %u",     entry->processorManufacturer.id));
            COMMON_LVVV(("entry->processorId.signature.stepping       = %u",     entry->processorId.signature.stepping));
            COMMON_LVVV(("entry->processorId.signature.model          = %u",     entry->processorId.signature.model));
            COMMON_LVVV(("entry->processorId.signature.family         = %u",     entry->processorId.signature.family));
            COMMON_LVVV(("entry->processorId.signature.type           = %u",     entry->processorId.signature.type));
            COMMON_LVVV(("entry->processorId.signature.extendedModel  = %u",     entry->processorId.signature.extendedModel));
            COMMON_LVVV(("entry->processorId.signature.extendedFamily = %u",     entry->processorId.signature.extendedFamily));
            COMMON_LVVV(("entry->processorId.signature.value32        = 0x%08X", entry->processorId.signature.value32));
            COMMON_LVVV(("entry->processorId.featureFlags             = %s",     flagsToFullString(entry->processorId.featureFlags)));
            COMMON_LVVV(("entry->processorVersion.id                  = %u",     entry->processorVersion.id));
            COMMON_LVVV(("entry->voltage.modeType                     = %s",     enumToFullString((DmiProcessorVoltageModeType)entry->voltage.modeType)));

            // entry->voltage
            {
                switch ((DmiProcessorVoltageModeType)entry->voltage.modeType)
                {
                    case DmiProcessorVoltageModeType::LEGACY_MODE:          COMMON_LVVV(("entry->voltage.flags = %s", flagsToFullString((DmiProcessorVoltageFlags)entry->voltage.flags))); break;
                    case DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE: COMMON_LVVV(("entry->voltage.value = %u", entry->voltage.value));                                              break;

                    default:
                    {
                        COMMON_LF(("Unknown DMI processor voltage mode type %s, %s:%u", enumToFullString((DmiProcessorVoltageModeType)entry->voltage.modeType), __FILE__, __LINE__));

                        return NgosStatus::UNEXPECTED_BEHAVIOUR;
                    }
                    break;
                }
            }

            COMMON_LVVV(("entry->voltage.value8   = 0x%02X", entry->voltage.value8));
            COMMON_LVVV(("entry->externalClock    = %u",     entry->externalClock));
            COMMON_LVVV(("entry->maxSpeed         = %u",     entry->maxSpeed));
            COMMON_LVVV(("entry->currentSpeed     = %u",     entry->currentSpeed));
            COMMON_LVVV(("entry->status           = %s",     enumToFullString((DmiProcessorStatus)entry->status)));
            COMMON_LVVV(("entry->socketPopulated  = %u",     entry->socketPopulated));
            COMMON_LVVV(("entry->processorStatus  = 0x%02X", entry->processorStatus));
            COMMON_LVVV(("entry->processorUpgrade = %s",     enumToFullString(entry->processorUpgrade)));

            if (entryV21)
            {
                COMMON_LVVV(("entryV21->l1CacheHandle = 0x%04X", entryV21->l1CacheHandle));
                COMMON_LVVV(("entryV21->l2CacheHandle = 0x%04X", entryV21->l2CacheHandle));
                COMMON_LVVV(("entryV21->l3CacheHandle = 0x%04X", entryV21->l3CacheHandle));

                if (entryV23)
                {
                    COMMON_LVVV(("entryV23->serialNumber.id = %u", entryV23->serialNumber.id));
                    COMMON_LVVV(("entryV23->assetTag.id     = %u", entryV23->assetTag.id));
                    COMMON_LVVV(("entryV23->partNumber.id   = %u", entryV23->partNumber.id));

                    if (entryV25)
                    {
                        COMMON_LVVV(("entryV25->coreCount                = 0x%02X", entryV25->coreCount));
                        COMMON_LVVV(("entryV25->enabledCoreCount         = 0x%02X", entryV25->enabledCoreCount));
                        COMMON_LVVV(("entryV25->threadCount              = 0x%02X", entryV25->threadCount));
                        COMMON_LVVV(("entryV25->processorCharacteristics = %s",     flagsToFullString(entryV25->processorCharacteristics)));

                        if (entryV26)
                        {
                            COMMON_LVVV(("entryV26->processorFamily2 = %s", enumToFullString(entryV26->processorFamily2)));

                            if (entryV30)
                            {
                                COMMON_LVVV(("entryV30->coreCount2        = 0x%04X", entryV30->coreCount2));
                                COMMON_LVVV(("entryV30->enabledCoreCount2 = 0x%04X", entryV30->enabledCoreCount2));
                                COMMON_LVVV(("entryV30->threadCount2      = 0x%04X", entryV30->threadCount2));
                            }
                        }
                    }
                }
            }
        }



        // Check variables
        {
            // Ignore CppAlignmentVerifier [BEGIN]
            // COMMON_TEST_ASSERT(entry->socketDesignation.id                 == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            COMMON_TEST_ASSERT(entry->processorType                           == DmiProcessorType::CENTRAL_PROCESSOR,               NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->processorFamily                      == DmiProcessorFamily::OTHER,                         NgosStatus::ASSERTION); // Commented due to value variation
            COMMON_TEST_ASSERT(entry->processorManufacturer.id                == 2,                                                 NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->processorId.signature.stepping       == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorId.signature.model          == 12,                                                NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorId.signature.family         == 6,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            COMMON_TEST_ASSERT(entry->processorId.signature.type              == 0,                                                 NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->processorId.signature.extendedModel  == 3,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorId.signature.extendedFamily == 0,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorId.signature.value32        == 0x00000000,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorId.featureFlags             == FLAGS(DmiProcessorFeatureFlag::FPU                                         // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::VME                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::DE                                        // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::PSE                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::TSC                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::MSR                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::PAE                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::MCE                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::CX8                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::APIC                                      // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::SEP                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::MTRR                                      // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::PGE                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::MCA                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::CMOV                                      // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::PAT                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::PSE36                                     // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::CLFSH                                     // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::MMX                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::FXSR                                      // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::SSE                                       // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::SSE2                                      // Commented due to value variation
            //                                                                         , DmiProcessorFeatureFlag::SS),              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorVersion.id                  == 3,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->voltage.modeType                     == DmiProcessorVoltageModeType::CURRENT_VOLTAGE_MODE, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->voltage.value                        == 18,                                                NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->voltage.value8                       == 0x92,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->externalClock                        == 100,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maxSpeed                             == 2000,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->currentSpeed                         == 2000,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->status                               == DmiProcessorStatus::ENABLED,                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->socketPopulated                      == 1,                                                 NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorStatus                      == 0x41,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorUpgrade                     == DmiProcessorUpgrade::OTHER,                        NgosStatus::ASSERTION); // Commented due to value variation
            // Ignore CppAlignmentVerifier [END]

            if (entryV21)
            {
                // COMMON_TEST_ASSERT(entryV21->l1CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->l2CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->l3CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV23)
                {
                    // COMMON_TEST_ASSERT(entryV23->serialNumber.id == 4, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV23->assetTag.id     == 5, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV23->partNumber.id   == 6, NgosStatus::ASSERTION); // Commented due to value variation

                    if (entryV25)
                    {
                        // COMMON_TEST_ASSERT(entryV25->coreCount                == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entryV25->enabledCoreCount         == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entryV25->threadCount              == 0x02,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entryV25->processorCharacteristics == FLAGS(DmiProcessorCharacteristicsFlag::SUPPORT_64_BIT), NgosStatus::ASSERTION); // Commented due to value variation

                        if (entryV26)
                        {
                            // COMMON_TEST_ASSERT(entryV26->processorFamily2 == DmiProcessorFamily2::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

                            if (entryV30)
                            {
                                // COMMON_TEST_ASSERT(entryV30->coreCount2        == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation
                                // COMMON_TEST_ASSERT(entryV30->enabledCoreCount2 == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation
                                // COMMON_TEST_ASSERT(entryV30->threadCount2      == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation

                                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV30), NgosStatus::ASSERTION);
                            }
                            else
                            {
                                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV26), NgosStatus::ASSERTION);
                            }
                        }
                        else
                        {
                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV25), NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV23), NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId serialNumberStringId;
        DmiStringId assetTagStringId;
        DmiStringId partNumberStringId;

        if (entryV23)
        {
            serialNumberStringId = entryV23->serialNumber;
            assetTagStringId     = entryV23->assetTag;
            partNumberStringId   = entryV23->partNumber;
        }



        if (
            entry->socketDesignation.id
            ||
            entry->processorManufacturer.id
            ||
            entry->processorVersion.id
            ||
            serialNumberStringId.id
            ||
            assetTagStringId.id
            ||
            partNumberStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->socketDesignation)
                    {
                        COMMON_LVVV(("socketDesignation = %s", begin));
                    }
                    else
                    if (stringId == entry->processorManufacturer)
                    {
                        COMMON_LVVV(("processorManufacturer = %s", begin));
                    }
                    else
                    if (stringId == entry->processorVersion)
                    {
                        COMMON_LVVV(("processorVersion = %s", begin));
                    }
                    else
                    if (stringId == serialNumberStringId)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == assetTagStringId)
                    {
                        COMMON_LVVV(("assetTag = %s", begin));
                    }
                    else
                    if (stringId == partNumberStringId)
                    {
                        COMMON_LVVV(("partNumber = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiCacheEntry(DmiCacheEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiCacheEntryV21 *entryV21 = DMI::getVersion() >= DMI_VERSION(2, 1) && entry->header.length >= sizeof(DmiCacheEntryV21) ? (DmiCacheEntryV21 *)entry : nullptr;
    DmiCacheEntryV31 *entryV31 = DMI::getVersion() >= DMI_VERSION(3, 1) && entry->header.length >= sizeof(DmiCacheEntryV31) ? (DmiCacheEntryV31 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->socketDesignation.id               = %u",     entry->socketDesignation.id));
            COMMON_LVVV(("entry->cacheConfiguration.level           = %u",     entry->cacheConfiguration.level));
            COMMON_LVVV(("entry->cacheConfiguration.socketed        = %u",     entry->cacheConfiguration.socketed));
            COMMON_LVVV(("entry->cacheConfiguration.location        = %s",     enumToFullString((DmiCacheLocation)entry->cacheConfiguration.location)));
            COMMON_LVVV(("entry->cacheConfiguration.enabled         = %u",     entry->cacheConfiguration.enabled));
            COMMON_LVVV(("entry->cacheConfiguration.operationalMode = %s",     enumToFullString((DmiCacheOperationalMode)entry->cacheConfiguration.operationalMode)));
            COMMON_LVVV(("entry->cacheConfiguration.value16         = 0x%04X", entry->cacheConfiguration.value16));
            COMMON_LVVV(("entry->maximumCacheSize.value             = %u",     entry->maximumCacheSize.value));
            COMMON_LVVV(("entry->maximumCacheSize.granularity       = %s",     enumToFullString((DmiCacheSizeGranularity)entry->maximumCacheSize.granularity)));
            COMMON_LVVV(("entry->maximumCacheSize.value16           = 0x%04X", entry->maximumCacheSize.value16));
            COMMON_LVVV(("entry->maximumCacheSize                   = %s",     bytesToString(entry->maximumCacheSize.size())));
            COMMON_LVVV(("entry->installedSize.value                = %u",     entry->installedSize.value));
            COMMON_LVVV(("entry->installedSize.granularity          = %s",     enumToFullString((DmiCacheSizeGranularity)entry->installedSize.granularity)));
            COMMON_LVVV(("entry->installedSize.value16              = 0x%04X", entry->installedSize.value16));
            COMMON_LVVV(("entry->installedSize                      = %s",     bytesToString(entry->installedSize.size())));
            COMMON_LVVV(("entry->supportedSramType                  = %s",     flagsToFullString(entry->supportedSramType)));
            COMMON_LVVV(("entry->currentSramType                    = %s",     flagsToFullString(entry->currentSramType)));

            if (entryV21)
            {
                COMMON_LVVV(("entryV21->cacheSpeed          = %u", entryV21->cacheSpeed));
                COMMON_LVVV(("entryV21->errorCorrectionType = %s", enumToFullString(entryV21->errorCorrectionType)));
                COMMON_LVVV(("entryV21->systemCacheType     = %s", enumToFullString(entryV21->systemCacheType)));
                COMMON_LVVV(("entryV21->associativity       = %s", enumToFullString(entryV21->associativity)));

                if (entryV31)
                {
                    COMMON_LVVV(("entryV31->maximumCacheSize2.value       = %u",     entryV31->maximumCacheSize2.value));
                    COMMON_LVVV(("entryV31->maximumCacheSize2.granularity = %s",     enumToFullString((DmiCacheSizeGranularity)entryV31->maximumCacheSize2.granularity)));
                    COMMON_LVVV(("entryV31->maximumCacheSize2.value32     = 0x%08X", entryV31->maximumCacheSize2.value32));
                    COMMON_LVVV(("entryV31->maximumCacheSize2             = %s",     bytesToString(entryV31->maximumCacheSize2.size())));
                    COMMON_LVVV(("entryV31->installedSize2.value          = %u",     entryV31->installedSize2.value));
                    COMMON_LVVV(("entryV31->installedSize2.granularity    = %s",     enumToFullString((DmiCacheSizeGranularity)entryV31->installedSize2.granularity)));
                    COMMON_LVVV(("entryV31->installedSize2.value32        = 0x%08X", entryV31->installedSize2.value32));
                    COMMON_LVVV(("entryV31->installedSize2                = %s",     bytesToString(entryV31->installedSize2.size())));
                }
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->socketDesignation.id               == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->cacheConfiguration.level           == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->cacheConfiguration.socketed        == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->cacheConfiguration.location        == DmiCacheLocation::UNKNOWN,                      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->cacheConfiguration.enabled         == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->cacheConfiguration.operationalMode == DmiCacheOperationalMode::UNKNOWN,               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->cacheConfiguration.value16         == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maximumCacheSize.value             == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maximumCacheSize.granularity       == DmiCacheSizeGranularity::_1_KILOBYTE,           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maximumCacheSize.value16           == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->installedSize.value                == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->installedSize.granularity          == DmiCacheSizeGranularity::_1_KILOBYTE,           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->installedSize.value16              == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->supportedSramType                  == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->currentSramType                    == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV21)
            {
                // COMMON_TEST_ASSERT(entryV21->cacheSpeed          == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->errorCorrectionType == DmiCacheErrorCorrectionType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->systemCacheType     == DmiCacheType::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV21->associativity       == DmiCacheAssociativity::OTHER,       NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV31)
                {
                    // COMMON_TEST_ASSERT(entryV31->maximumCacheSize2.value       == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV31->maximumCacheSize2.granularity == DmiCacheSizeGranularity::_1_KILOBYTE, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV31->maximumCacheSize2.value32     == 0x00000000,                           NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV31->installedSize2.value          == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV31->installedSize2.granularity    == DmiCacheSizeGranularity::_1_KILOBYTE, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV31->installedSize2.value32        == 0x00000000,                           NgosStatus::ASSERTION); // Commented due to value variation

                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntryV31), NgosStatus::ASSERTION);
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntryV21), NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        if (entry->socketDesignation.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->socketDesignation)
                    {
                        COMMON_LVVV(("socketDesignation = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiPortConnectorEntry(DmiPortConnectorEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->internalReferenceDesignator.id = %u", entry->internalReferenceDesignator.id));
            COMMON_LVVV(("entry->internalConnectorType          = %s", enumToFullString(entry->internalConnectorType)));
            COMMON_LVVV(("entry->externalReferenceDesignator.id = %u", entry->externalReferenceDesignator.id));
            COMMON_LVVV(("entry->externalConnectorType          = %s", enumToFullString(entry->externalConnectorType)));
            COMMON_LVVV(("entry->portType                       = %s", enumToFullString(entry->portType)));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->internalReferenceDesignator.id == 1,                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->internalConnectorType          == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->externalReferenceDesignator.id == 2,                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->externalConnectorType          == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->portType                       == DmiPortConnectorPortType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPortConnectorEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            entry->internalReferenceDesignator.id
            ||
            entry->externalReferenceDesignator.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->internalReferenceDesignator)
                    {
                        COMMON_LVVV(("internalReferenceDesignator = %s", begin));
                    }
                    else
                    if (stringId == entry->externalReferenceDesignator)
                    {
                        COMMON_LVVV(("externalReferenceDesignator = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemSlotsEntry(DmiSystemSlotsEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiSystemSlotsEntryV26 *entryV26 = DMI::getVersion() >= DMI_VERSION(2, 6) && entry->header.length >= sizeof(DmiSystemSlotsEntryV26) ? (DmiSystemSlotsEntryV26 *)entry : nullptr;
    DmiSystemSlotsEntryV32 *entryV32 = DMI::getVersion() >= DMI_VERSION(3, 2) && entry->header.length >= sizeof(DmiSystemSlotsEntryV32) ? (DmiSystemSlotsEntryV32 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->slotDesignation.id  = %u",     entry->slotDesignation.id));
            COMMON_LVVV(("entry->slotType            = %s",     enumToFullString(entry->slotType)));
            COMMON_LVVV(("entry->slotDataBusWidth    = %s",     enumToFullString(entry->slotDataBusWidth)));
            COMMON_LVVV(("entry->currentUsage        = %s",     enumToFullString(entry->currentUsage)));
            COMMON_LVVV(("entry->slotLength          = %s",     enumToFullString(entry->slotLength)));
            COMMON_LVVV(("entry->slotID              = 0x%04X", entry->slotID));
            COMMON_LVVV(("entry->slotCharacteristics = %s",     flagsToFullString(entry->slotCharacteristics)));

            if (entryV26)
            {
                COMMON_LVVV(("entryV26->segmentGroupNumber            = %u",     entryV26->segmentGroupNumber));
                COMMON_LVVV(("entryV26->busNumber                     = %u",     entryV26->busNumber));
                COMMON_LVVV(("entryV26->functionNumber                = %u",     entryV26->functionNumber));
                COMMON_LVVV(("entryV26->deviceNumber                  = %u",     entryV26->deviceNumber));
                COMMON_LVVV(("entryV26->functionNumberAndDeviceNumber = 0x%02X", entryV26->functionNumberAndDeviceNumber));

                if (entryV32)
                {
                    COMMON_LVVV(("entryV32->dataBusWidth      = %u", entryV32->dataBusWidth));
                    COMMON_LVVV(("entryV32->peerGroupingCount = %u", entryV32->peerGroupingCount));



                    // entryV32->peerGroups:
                    {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                        COMMON_LVVV(("entryV32->peerGroups:"));
                        COMMON_LVVV(("-------------------------------------"));

                        for (i64 i = 0; i < entryV32->peerGroupingCount; ++i)
                        {
                            COMMON_LVVV(("entryV32->peerGroups[%d].segmentGroupNumber            = %u",     i, entryV32->peerGroups[i].segmentGroupNumber));
                            COMMON_LVVV(("entryV32->peerGroups[%d].busNumber                     = %u",     i, entryV32->peerGroups[i].busNumber));
                            COMMON_LVVV(("entryV32->peerGroups[%d].functionNumber                = %u",     i, entryV32->peerGroups[i].functionNumber));
                            COMMON_LVVV(("entryV32->peerGroups[%d].deviceNumber                  = %u",     i, entryV32->peerGroups[i].deviceNumber));
                            COMMON_LVVV(("entryV32->peerGroups[%d].functionNumberAndDeviceNumber = 0x%02X", i, entryV32->peerGroups[i].functionNumberAndDeviceNumber));
                            COMMON_LVVV(("entryV32->peerGroups[%d].dataBusWidth                  = %u",     i, entryV32->peerGroups[i].dataBusWidth));
                        }

                        COMMON_LVVV(("-------------------------------------"));
#endif
                    }
                }
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->slotDesignation.id  == 1,                                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->slotType            == DmiSystemSlotsType::UNKNOWN,                    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->slotDataBusWidth    == DmiSystemSlotsDataBusWidth::UNKNOWN,            NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->currentUsage        == DmiSystemSlotsUsage::AVAILABLE,                 NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->slotLength          == DmiSystemSlotsLength::UNKNOWN,                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->slotID              == 0x0001,                                         NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->slotCharacteristics == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV26)
            {
                // COMMON_TEST_ASSERT(entryV26->segmentGroupNumber            == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV26->busNumber                     == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV26->functionNumber                == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV26->deviceNumber                  == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV26->functionNumberAndDeviceNumber == 0x00, NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV32)
                {
                    // COMMON_TEST_ASSERT(entryV32->dataBusWidth                                == 0,    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV32->peerGroupingCount                           == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV32->peerGroups[0].segmentGroupNumber            == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV32->peerGroups[0].busNumber                     == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV32->peerGroups[0].functionNumber                == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV32->peerGroups[0].deviceNumber                  == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV32->peerGroups[0].functionNumberAndDeviceNumber == 0x00, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV32->peerGroups[0].dataBusWidth                  == 0,    NgosStatus::ASSERTION); // Commented due to value variation

                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntryV32) + entryV32->peerGroupingCount * sizeof(DmiSystemSlotsPeerGroup), NgosStatus::ASSERTION);
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntryV26), NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        if (entry->slotDesignation.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->slotDesignation)
                    {
                        COMMON_LVVV(("slotDesignation = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiOnboardDevicesEntry(DmiOnboardDevicesEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    u8 count = (entry->header.length - sizeof(entry->header)) / sizeof(entry->devices[0]);

    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("count = %u", count));

            // entry->devices:
            {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                COMMON_LVVV(("entry->devices:"));
                COMMON_LVVV(("-------------------------------------"));

                for (i64 i = 0; i < count; ++i)
                {
                    COMMON_LVVV(("entry->devices[%d].deviceType           = %s",     i, enumToFullString((DmiOnboardDevicesDeviceType)entry->devices[i].deviceType)));
                    COMMON_LVVV(("entry->devices[%d].enabled              = %u",     i, entry->devices[i].enabled));
                    COMMON_LVVV(("entry->devices[%d].deviceTypeAndEnabled = 0x%02X", i, entry->devices[i].deviceTypeAndEnabled));
                    COMMON_LVVV(("entry->devices[%d].description.id       = %u",     i, entry->devices[i].description.id));
                }

                COMMON_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(count                                                        >  0,                                    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT((DmiOnboardDevicesDeviceType)entry->devices[0].deviceType == DmiOnboardDevicesDeviceType::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->devices[0].enabled                                 == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->devices[0].deviceTypeAndEnabled                    == 0x00,                                 NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->devices[0].description.id                          == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesEntry) + sizeof(DmiOnboardDevicesDevice), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            count > 0
            &&
            entry->devices[0].description.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiOemStringsEntry(DmiOemStringsEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->stringCount = %u", entry->stringCount));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOemStringsEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->stringCount > 0)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);



            COMMON_TEST_ASSERT(stringId.id == entry->stringCount, NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemConfigurationEntry(DmiSystemConfigurationEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->stringCount = %u", entry->stringCount));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemConfigurationEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->stringCount > 0)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);



            COMMON_TEST_ASSERT(stringId.id == entry->stringCount, NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiBiosLanguageEntry(DmiBiosLanguageEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->installableLanguages = %u", entry->installableLanguages));
            COMMON_LVVV(("entry->flags                = %s", flagsToFullString(entry->flags)));
            COMMON_LVVV(("entry->currentLanguage.id   = %u", entry->currentLanguage.id));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->installableLanguages == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->flags                == FLAGS(DmiBiosLanguageFlags::NONE), NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->currentLanguage.id   == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosLanguageEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            entry->installableLanguages
            ||
            entry->currentLanguage.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiGroupAssociationsEntry(DmiGroupAssociationsEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    u8 count = (entry->header.length - sizeof(entry->header) - sizeof(entry->groupName)) / sizeof(entry->items[0]);

    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->groupName.id = %u", entry->groupName.id));
            COMMON_LVVV(("count               = %u", count));

            // entry->items:
            {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                COMMON_LVVV(("entry->items:"));
                COMMON_LVVV(("-------------------------------------"));

                for (i64 i = 0; i < count; ++i)
                {
                    COMMON_LVVV(("entry->items[%d].type   = %s",     i, enumToFullString(entry->items[i].type)));
                    COMMON_LVVV(("entry->items[%d].handle = 0x%04X", i, entry->items[i].handle));
                }

                COMMON_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->groupName.id    == 1,                  NgosStatus::ASSERTION); // Commented due to value variation
            COMMON_TEST_ASSERT(count                     >  0,                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->items[0].type   == DmiEntryType::BIOS, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->items[0].handle == 0x0000,             NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiGroupAssociationsEntry) + sizeof(DmiGroupAssociationsItem), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->groupName.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->groupName)
                    {
                        COMMON_LVVV(("groupName = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiPhysicalMemoryArrayEntry(DmiPhysicalMemoryArrayEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiPhysicalMemoryArrayEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntryV27) ? (DmiPhysicalMemoryArrayEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->location                     = %s",     enumToFullString(entry->location)));
            COMMON_LVVV(("entry->use                          = %s",     enumToFullString(entry->use)));
            COMMON_LVVV(("entry->memoryErrorCorrection        = %s",     enumToFullString(entry->memoryErrorCorrection)));
            COMMON_LVVV(("entry->maximumCapacity.value        = 0x%08X", entry->maximumCapacity.value));
            COMMON_LVVV(("entry->maximumCapacity              = %s",     bytesToString(entry->maximumCapacity.size())));
            COMMON_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
            COMMON_LVVV(("entry->numberOfMemoryDevices        = %u",     entry->numberOfMemoryDevices));

            if (entryV27)
            {
                COMMON_LVVV(("entryV27->extendedMaximumCapacity = 0x%016llX", entryV27->extendedMaximumCapacity));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->location                     == DmiPhysicalMemoryArrayLocation::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->use                          == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY,             NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryErrorCorrection        == DmiPhysicalMemoryArrayErrorCorrection::MULTI_BIT_ECC, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maximumCapacity.value        == 0x00100000,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->numberOfMemoryDevices        == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV27)
            {
                // COMMON_TEST_ASSERT(entryV27->extendedMaximumCapacity == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntry), NgosStatus::ASSERTION);
            }
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    if (entry->use == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY)
    {
        // Set sSystemPhysicalMemoryArrayHandle
        {
            if (sSystemPhysicalMemoryArrayHandle != 0)
            {
                COMMON_LW(("Found 2 or more PHYSICAL_MEMORY_ARRAY entries with SYSTEM_MEMORY use"));
            }

            sSystemPhysicalMemoryArrayHandle = entry->header.handle;
        }



        // Set sSystemPhysicalMemoryArrayCapacity
        {
            if (
                entry->maximumCapacity.value == DMI_PHYSICAL_MEMORY_ARRAY_MAXIMUM_CAPACITY_NEED_TO_EXTEND
                &&
                entryV27
               )
            {
                sSystemPhysicalMemoryArrayCapacity = entryV27->extendedMaximumCapacity;
            }
            else
            {
                sSystemPhysicalMemoryArrayCapacity = entry->maximumCapacity.size();
            }
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiMemoryDeviceEntry(DmiMemoryDeviceEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiMemoryDeviceEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV23) ? (DmiMemoryDeviceEntryV23 *)entry : nullptr;
    DmiMemoryDeviceEntryV26 *entryV26 = DMI::getVersion() >= DMI_VERSION(2, 6) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV26) ? (DmiMemoryDeviceEntryV26 *)entry : nullptr;
    DmiMemoryDeviceEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV27) ? (DmiMemoryDeviceEntryV27 *)entry : nullptr;
    DmiMemoryDeviceEntryV28 *entryV28 = DMI::getVersion() >= DMI_VERSION(2, 8) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV28) ? (DmiMemoryDeviceEntryV28 *)entry : nullptr;
    DmiMemoryDeviceEntryV32 *entryV32 = DMI::getVersion() >= DMI_VERSION(3, 2) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV32) ? (DmiMemoryDeviceEntryV32 *)entry : nullptr;
    DmiMemoryDeviceEntryV33 *entryV33 = DMI::getVersion() >= DMI_VERSION(3, 3) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV33) ? (DmiMemoryDeviceEntryV33 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->memoryArrayHandle            = 0x%04X", entry->memoryArrayHandle));
            COMMON_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
            COMMON_LVVV(("entry->totalWidth                   = %u",     entry->totalWidth));
            COMMON_LVVV(("entry->dataWidth                    = %u",     entry->dataWidth));
            COMMON_LVVV(("entry->size.value                   = %u",     entry->size.value));
            COMMON_LVVV(("entry->size.granularity             = %s",     enumToFullString((DmiMemoryDeviceSizeGranularity)entry->size.granularity)));
            COMMON_LVVV(("entry->size.value16                 = 0x%04X", entry->size.value16));
            COMMON_LVVV(("entry->size                         = %s",     bytesToString(entry->size.size())));
            COMMON_LVVV(("entry->formFactor                   = %s",     enumToFullString(entry->formFactor)));
            COMMON_LVVV(("entry->deviceSet                    = %u",     entry->deviceSet));
            COMMON_LVVV(("entry->deviceLocator.id             = %u",     entry->deviceLocator.id));
            COMMON_LVVV(("entry->bankLocator.id               = %u",     entry->bankLocator.id));
            COMMON_LVVV(("entry->memoryType                   = %s",     enumToFullString(entry->memoryType)));
            COMMON_LVVV(("entry->typeDetail                   = %s",     flagsToFullString(entry->typeDetail)));

            if (entryV23)
            {
                COMMON_LVVV(("entryV23->speed           = %u", entryV23->speed));
                COMMON_LVVV(("entryV23->manufacturer.id = %u", entryV23->manufacturer.id));
                COMMON_LVVV(("entryV23->serialNumber.id = %u", entryV23->serialNumber.id));
                COMMON_LVVV(("entryV23->assetTag.id     = %u", entryV23->assetTag.id));
                COMMON_LVVV(("entryV23->partNumber.id   = %u", entryV23->partNumber.id));

                if (entryV26)
                {
                    COMMON_LVVV(("entryV26->attributes.rank   = %u",     entryV26->attributes.rank));
                    COMMON_LVVV(("entryV26->attributes.value8 = 0x%02X", entryV26->attributes.value8));

                    if (entryV27)
                    {
                        COMMON_LVVV(("entryV27->extendedSize.value    = %u",     entryV27->extendedSize.value));
                        COMMON_LVVV(("entryV27->extendedSize.value32  = 0x%08X", entryV27->extendedSize.value32));
                        COMMON_LVVV(("entryV27->extendedSize          = %s",     bytesToString(entryV27->extendedSize.size())));
                        COMMON_LVVV(("entryV27->configuredMemorySpeed = %u",     entryV27->configuredMemorySpeed));

                        if (entryV28)
                        {
                            COMMON_LVVV(("entryV28->minimumVoltage    = %u", entryV28->minimumVoltage));
                            COMMON_LVVV(("entryV28->maximumVoltage    = %u", entryV28->maximumVoltage));
                            COMMON_LVVV(("entryV28->configuredVoltage = %u", entryV28->configuredVoltage));

                            if (entryV32)
                            {
                                COMMON_LVVV(("entryV32->memoryTechnology                        = %s", enumToFullString(entryV32->memoryTechnology)));
                                COMMON_LVVV(("entryV32->memoryOperatingModeCapability           = %s", flagsToFullString(entryV32->memoryOperatingModeCapability)));
                                COMMON_LVVV(("entryV32->firmwareVersion.id                      = %u", entryV32->firmwareVersion.id));
                                COMMON_LVVV(("entryV32->moduleManufacturerID                    = %u", entryV32->moduleManufacturerID));
                                COMMON_LVVV(("entryV32->moduleProductID                         = %u", entryV32->moduleProductID));
                                COMMON_LVVV(("entryV32->memorySubsystemControllerManufacturerID = %u", entryV32->memorySubsystemControllerManufacturerID));
                                COMMON_LVVV(("entryV32->memorySubsystemControllerProductID      = %u", entryV32->memorySubsystemControllerProductID));
                                COMMON_LVVV(("entryV32->nonVolatileSize                         = %u", entryV32->nonVolatileSize));
                                COMMON_LVVV(("entryV32->volatileSize                            = %u", entryV32->volatileSize));
                                COMMON_LVVV(("entryV32->cacheSize                               = %u", entryV32->cacheSize));
                                COMMON_LVVV(("entryV32->logicalSize                             = %u", entryV32->logicalSize));

                                if (entryV33)
                                {
                                    COMMON_LVVV(("entryV33->extendedSpeed                 = %u", entryV33->extendedSpeed));
                                    COMMON_LVVV(("entryV33->extendedConfiguredMemorySpeed = %u", entryV33->extendedConfiguredMemorySpeed));
                                }
                            }
                        }
                    }
                }
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->memoryArrayHandle            == 0x1000,                                      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->totalWidth                   == 64,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->dataWidth                    == 64,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->size.value                   == 1024,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->size.granularity             == DmiMemoryDeviceSizeGranularity::_1_MEGABYTE, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->size.value16                 == 0x0400,                                      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->formFactor                   == DmiMemoryDeviceFormFactor::DIMM,             NgosStatus::ASSERTION); // Commented due to value variation
            COMMON_TEST_ASSERT(entry->deviceSet                       == 0,                                           NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->deviceLocator.id             == 1,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->bankLocator.id               == 2,                                           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryType                   == DmiMemoryDeviceType::RAM,                    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->typeDetail                   == FLAGS(DmiMemoryDeviceTypeDetailFlag::OTHER), NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV23)
            {
                // COMMON_TEST_ASSERT(entryV23->speed           == 2133, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV23->manufacturer.id == 3,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV23->serialNumber.id == 4,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV23->assetTag.id     == 5,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV23->partNumber.id   == 6,    NgosStatus::ASSERTION); // Commented due to value variation

                if (entryV26)
                {
                    // COMMON_TEST_ASSERT(entryV26->attributes.rank   == 2,    NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entryV26->attributes.value8 == 0x02, NgosStatus::ASSERTION); // Commented due to value variation

                    if (entryV27)
                    {
                        // COMMON_TEST_ASSERT(entryV27->extendedSize.value    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entryV27->extendedSize.value32  == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entryV27->configuredMemorySpeed == 2133,       NgosStatus::ASSERTION); // Commented due to value variation

                        if (entryV28)
                        {
                            // COMMON_TEST_ASSERT(entryV28->minimumVoltage    == 1200, NgosStatus::ASSERTION); // Commented due to value variation
                            // COMMON_TEST_ASSERT(entryV28->maximumVoltage    == 1200, NgosStatus::ASSERTION); // Commented due to value variation
                            // COMMON_TEST_ASSERT(entryV28->configuredVoltage == 1200, NgosStatus::ASSERTION); // Commented due to value variation

                            if (entryV32)
                            {
                                COMMON_TEST_ASSERT(entryV32->memoryTechnology                        == DmiMemoryDeviceTechnology::NONE,                         NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->memoryOperatingModeCapability           == FLAGS(DmiMemoryDeviceOperatingModeCapabilityFlag::NONE), NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->firmwareVersion.id                      == 7,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->moduleManufacturerID                    == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->moduleProductID                         == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->memorySubsystemControllerManufacturerID == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->memorySubsystemControllerProductID      == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->nonVolatileSize                         == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->volatileSize                            == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->cacheSize                               == 0,                                                       NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entryV32->logicalSize                             == 0,                                                       NgosStatus::ASSERTION);

                                if (entryV33)
                                {
                                    // COMMON_TEST_ASSERT(entryV33->extendedSpeed                 == 0, NgosStatus::ASSERTION); // Commented due to value variation
                                    // COMMON_TEST_ASSERT(entryV33->extendedConfiguredMemorySpeed == 0, NgosStatus::ASSERTION); // Commented due to value variation

                                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV33), NgosStatus::ASSERTION);
                                }
                                else
                                {
                                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV32), NgosStatus::ASSERTION);
                                }
                            }
                            else
                            {
                                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV28), NgosStatus::ASSERTION);
                            }
                        }
                        else
                        {
                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV27), NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV26), NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntryV23), NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId manufacturerStringId;
        DmiStringId serialNumberStringId;
        DmiStringId assetTagStringId;
        DmiStringId partNumberStringId;
        DmiStringId firmwareVersionStringId;

        if (entryV23)
        {
            manufacturerStringId = entryV23->manufacturer;
            serialNumberStringId = entryV23->serialNumber;
            assetTagStringId     = entryV23->assetTag;
            partNumberStringId   = entryV23->partNumber;

            if (entryV32)
            {
                firmwareVersionStringId = entryV32->firmwareVersion;
            }
        }



        if (
            entry->deviceLocator.id
            ||
            entry->bankLocator.id
            ||
            manufacturerStringId.id
            ||
            serialNumberStringId.id
            ||
            assetTagStringId.id
            ||
            partNumberStringId.id
            ||
            firmwareVersionStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->deviceLocator)
                    {
                        COMMON_LVVV(("deviceLocator = %s", begin));
                    }
                    else
                    if (stringId == entry->bankLocator)
                    {
                        COMMON_LVVV(("bankLocator = %s", begin));
                    }
                    else
                    if (stringId == manufacturerStringId)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                    }
                    else
                    if (stringId == serialNumberStringId)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == assetTagStringId)
                    {
                        COMMON_LVVV(("assetTag = %s", begin));
                    }
                    else
                    if (stringId == partNumberStringId)
                    {
                        COMMON_LVVV(("partNumber = %s", begin));
                    }
                    else
                    if (stringId == firmwareVersionStringId)
                    {
                        COMMON_LVVV(("firmwareVersion = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    COMMON_ASSERT_EXECUTION(sMemoryDeviceEntries.append(entry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiBits32MemoryErrorInformationEntry(DmiBits32MemoryErrorInformationEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->errorType               = %s",     enumToFullString(entry->errorType)));
            COMMON_LVVV(("entry->errorGranularity        = %s",     enumToFullString(entry->errorGranularity)));
            COMMON_LVVV(("entry->errorOperation          = %s",     enumToFullString(entry->errorOperation)));
            COMMON_LVVV(("entry->vendorSyndrome          = 0x%08X", entry->vendorSyndrome));
            COMMON_LVVV(("entry->memoryArrayErrorAddress = 0x%08X", entry->memoryArrayErrorAddress));
            COMMON_LVVV(("entry->deviceErrorAddress      = 0x%08X", entry->deviceErrorAddress));
            COMMON_LVVV(("entry->errorResolution         = 0x%08X", entry->errorResolution));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->errorType               == DmiBits32MemoryErrorInformationErrorType::OK,             NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->errorGranularity        == DmiBits32MemoryErrorInformationErrorGranularity::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->errorOperation          == DmiBits32MemoryErrorInformationErrorOperation::UNKNOWN,   NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->vendorSyndrome          == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryArrayErrorAddress == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceErrorAddress      == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->errorResolution         == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBits32MemoryErrorInformationEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiMemoryArrayMappedAddressEntry(DmiMemoryArrayMappedAddressEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiMemoryArrayMappedAddressEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntryV27) ? (DmiMemoryArrayMappedAddressEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->startingAddress.value = 0x%08X", entry->startingAddress.value));
            COMMON_LVVV(("entry->startingAddress       = %s",     bytesToString(entry->startingAddress.address())));
            COMMON_LVVV(("entry->endingAddress.value   = 0x%08X", entry->endingAddress.value));
            COMMON_LVVV(("entry->endingAddress         = %s",     bytesToString(entry->endingAddress.address())));
            COMMON_LVVV(("entry->memoryArrayHandle     = 0x%04X", entry->memoryArrayHandle));
            COMMON_LVVV(("entry->partitionWidth        = %u",     entry->partitionWidth));

            if (entryV27)
            {
                COMMON_LVVV(("entryV27->extendedStartingAddress = 0x%016llX", entryV27->extendedStartingAddress));
                COMMON_LVVV(("entryV27->extendedEndingAddress   = 0x%016llX", entryV27->extendedEndingAddress));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->startingAddress.value == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->endingAddress.value   == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryArrayHandle     == 0x1000,     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->partitionWidth        == 1,          NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV27)
            {
                // COMMON_TEST_ASSERT(entryV27->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV27->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntry), NgosStatus::ASSERTION);
            }
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiMemoryDeviceMappedAddressEntry(DmiMemoryDeviceMappedAddressEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiMemoryDeviceMappedAddressEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntryV27) ? (DmiMemoryDeviceMappedAddressEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->startingAddress.value          = 0x%08X", entry->startingAddress.value));
            COMMON_LVVV(("entry->startingAddress                = %s",     bytesToString(entry->startingAddress.address())));
            COMMON_LVVV(("entry->endingAddress.value            = 0x%08X", entry->endingAddress.value));
            COMMON_LVVV(("entry->endingAddress                  = %s",     bytesToString(entry->endingAddress.address())));
            COMMON_LVVV(("entry->memoryDeviceHandle             = 0x%04X", entry->memoryDeviceHandle));
            COMMON_LVVV(("entry->memoryArrayMappedAddressHandle = 0x%04X", entry->memoryArrayMappedAddressHandle));
            COMMON_LVVV(("entry->partitionRowPosition           = %u",     entry->partitionRowPosition));
            COMMON_LVVV(("entry->interleavePosition             = %u",     entry->interleavePosition));
            COMMON_LVVV(("entry->interleavedDataDepth           = %u",     entry->interleavedDataDepth));

            if (entryV27)
            {
                COMMON_LVVV(("entryV27->extendedStartingAddress = 0x%016llX", entryV27->extendedStartingAddress));
                COMMON_LVVV(("entryV27->extendedEndingAddress   = 0x%016llX", entryV27->extendedEndingAddress));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->startingAddress.value          == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->endingAddress.value            == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryDeviceHandle             == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryArrayMappedAddressHandle == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->partitionRowPosition           == 1,          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->interleavePosition             == 1,          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->interleavedDataDepth           == 1,          NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV27)
            {
                // COMMON_TEST_ASSERT(entryV27->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV27->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntry), NgosStatus::ASSERTION);
            }
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(sMemoryDeviceMappedAddressEntries.append(entry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiPortableBatteryEntry(DmiPortableBatteryEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiPortableBatteryEntryV22 *entryV22 = DMI::getVersion() >= DMI_VERSION(2, 2) && entry->header.length >= sizeof(DmiPortableBatteryEntryV22) ? (DmiPortableBatteryEntryV22 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->location.id               = %u", entry->location.id));
            COMMON_LVVV(("entry->manufacturer.id           = %u", entry->manufacturer.id));
            COMMON_LVVV(("entry->manufactureDate.id        = %u", entry->manufactureDate.id));
            COMMON_LVVV(("entry->serialNumber.id           = %u", entry->serialNumber.id));
            COMMON_LVVV(("entry->deviceName.id             = %u", entry->deviceName.id));
            COMMON_LVVV(("entry->deviceChemistry           = %s", enumToFullString(entry->deviceChemistry)));
            COMMON_LVVV(("entry->designCapacity            = %u", entry->designCapacity));
            COMMON_LVVV(("entry->designVoltage             = %u", entry->designVoltage));
            COMMON_LVVV(("entry->sbdsVersionNumber.id      = %u", entry->sbdsVersionNumber.id));
            COMMON_LVVV(("entry->maximumErrorInBatteryData = %u", entry->maximumErrorInBatteryData));

            if (entryV22)
            {
                COMMON_LVVV(("entryV22->sbdsSerialNumber            = %u",             entryV22->sbdsSerialNumber));
                COMMON_LVVV(("entryV22->sbdsManufactureDate.date    = %u",             entryV22->sbdsManufactureDate.date));
                COMMON_LVVV(("entryV22->sbdsManufactureDate.month   = %u",             entryV22->sbdsManufactureDate.month));
                COMMON_LVVV(("entryV22->sbdsManufactureDate.year    = %u",             entryV22->sbdsManufactureDate.year));
                COMMON_LVVV(("entryV22->sbdsManufactureDate.value16 = 0x%04X",         entryV22->sbdsManufactureDate.value16));
                COMMON_LVVV(("entryV22->sbdsManufactureDate         = %04u-%02u-%02u", entryV22->sbdsManufactureDate.yearReal(), entryV22->sbdsManufactureDate.month, entryV22->sbdsManufactureDate.date));
                COMMON_LVVV(("entryV22->sbdsDeviceChemistry.id      = %u",             entryV22->sbdsDeviceChemistry.id));
                COMMON_LVVV(("entryV22->designCapacityMultiplier    = %u",             entryV22->designCapacityMultiplier));
                COMMON_LVVV(("entryV22->oemSpecific                 = 0x%08X",         entryV22->oemSpecific));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->location.id               == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->manufacturer.id           == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->manufactureDate.id        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->serialNumber.id           == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceName.id             == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceChemistry           == DmiPortableBatteryDeviceChemistry::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->designCapacity            == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->designVoltage             == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->sbdsVersionNumber.id      == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maximumErrorInBatteryData == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV22)
            {
                // COMMON_TEST_ASSERT(entryV22->sbdsSerialNumber            == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV22->sbdsManufactureDate.date    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV22->sbdsManufactureDate.month   == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV22->sbdsManufactureDate.year    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV22->sbdsManufactureDate.value16 == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV22->sbdsDeviceChemistry.id      == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV22->designCapacityMultiplier    == 0,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entryV22->oemSpecific                 == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntryV22), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId sbdsDeviceChemistryStringId;

        if (entryV22)
        {
            sbdsDeviceChemistryStringId = entryV22->sbdsDeviceChemistry;
        }



        if (
            entry->location.id
            ||
            entry->manufacturer.id
            ||
            entry->manufactureDate.id
            ||
            entry->serialNumber.id
            ||
            entry->deviceName.id
            ||
            entry->sbdsVersionNumber.id
            ||
            sbdsDeviceChemistryStringId.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->location)
                    {
                        COMMON_LVVV(("location = %s", begin));
                    }
                    else
                    if (stringId == entry->manufacturer)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                    }
                    else
                    if (stringId == entry->manufactureDate)
                    {
                        COMMON_LVVV(("manufactureDate = %s", begin));
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->deviceName)
                    {
                        COMMON_LVVV(("deviceName = %s", begin));
                    }
                    else
                    if (stringId == entry->sbdsVersionNumber)
                    {
                        COMMON_LVVV(("sbdsVersionNumber = %s", begin));
                    }
                    else
                    if (stringId == sbdsDeviceChemistryStringId)
                    {
                        COMMON_LVVV(("sbdsDeviceChemistry = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemResetEntry(DmiSystemResetEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->capabilities.enabled           = %s",     boolToString(entry->capabilities.enabled)));
            COMMON_LVVV(("entry->capabilities.bootOption        = %s",     enumToFullString((DmiSystemResetBootOption)entry->capabilities.bootOption)));
            COMMON_LVVV(("entry->capabilities.bootOptionOnLimit = %s",     enumToFullString((DmiSystemResetBootOption)entry->capabilities.bootOptionOnLimit)));
            COMMON_LVVV(("entry->capabilities.watchdogEnabled   = %s",     boolToString(entry->capabilities.watchdogEnabled)));
            COMMON_LVVV(("entry->capabilities.value8            = 0x%02X", entry->capabilities.value8));
            COMMON_LVVV(("entry->resetCount                     = %u",     entry->resetCount));
            COMMON_LVVV(("entry->resetLimit                     = %u",     entry->resetLimit));
            COMMON_LVVV(("entry->timerInterval                  = %u",     entry->timerInterval));
            COMMON_LVVV(("entry->timeout                        = %u",     entry->timeout));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->capabilities.enabled           == 1,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->capabilities.bootOption        == DmiSystemResetBootOption::DO_NOT_REBOOT, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->capabilities.bootOptionOnLimit == DmiSystemResetBootOption::DO_NOT_REBOOT, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->capabilities.watchdogEnabled   == 1,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->capabilities.value8            == 0x3F,                                    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->resetCount                     == 0xFFFF,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->resetLimit                     == 0xFFFF,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->timerInterval                  == 0xFFFF,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->timeout                        == 0xFFFF,                                  NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemResetEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiHardwareSecurityEntry(DmiHardwareSecurityEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->settings.frontPanelResetStatus       = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.frontPanelResetStatus)));
            COMMON_LVVV(("entry->settings.administratorPasswordStatus = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.administratorPasswordStatus)));
            COMMON_LVVV(("entry->settings.keyboardPasswordStatus      = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.keyboardPasswordStatus)));
            COMMON_LVVV(("entry->settings.powerOnPasswordStatus       = %s",     enumToFullString((DmiHardwareSecurityStatus)entry->settings.powerOnPasswordStatus)));
            COMMON_LVVV(("entry->settings.value8                      = 0x%02X", entry->settings.value8));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->settings.frontPanelResetStatus       == DmiHardwareSecurityStatus::UNKNOWN,  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->settings.administratorPasswordStatus == DmiHardwareSecurityStatus::ENABLED,  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->settings.keyboardPasswordStatus      == DmiHardwareSecurityStatus::UNKNOWN,  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->settings.powerOnPasswordStatus       == DmiHardwareSecurityStatus::DISABLED, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->settings.value8                      == 0x37,                                NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiHardwareSecurityEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiVoltageProbeEntry(DmiVoltageProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id    = %u",     entry->description.id));
            COMMON_LVVV(("entry->location          = %s",     enumToFullString((DmiVoltageProbeLocation)entry->location)));
            COMMON_LVVV(("entry->status            = %s",     enumToFullString((DmiVoltageProbeStatus)entry->status)));
            COMMON_LVVV(("entry->locationAndStatus = 0x%02X", entry->locationAndStatus));
            COMMON_LVVV(("entry->maximumValue      = %u",     entry->maximumValue));
            COMMON_LVVV(("entry->minimumValue      = %u",     entry->minimumValue));
            COMMON_LVVV(("entry->resolution        = %u",     entry->resolution));
            COMMON_LVVV(("entry->tolerance         = %u",     entry->tolerance));
            COMMON_LVVV(("entry->accuracy          = %u",     entry->accuracy));
            COMMON_LVVV(("entry->oemDefined        = 0x%08X", entry->oemDefined));
            COMMON_LVVV(("entry->nominalValue      = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id    == 1,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->location          == DmiVoltageProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->status            == DmiVoltageProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->locationAndStatus == 0x00,                           NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maximumValue      == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->minimumValue      == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->resolution        == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->tolerance         == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->accuracy          == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->oemDefined        == 0x00000000,                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->nominalValue      == 0,                              NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiVoltageProbeEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiCoolingDeviceEntry(DmiCoolingDeviceEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    DmiCoolingDeviceEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiCoolingDeviceEntryV27) ? (DmiCoolingDeviceEntryV27 *)entry : nullptr;



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->temperatureProbeHandle = 0x%04X", entry->temperatureProbeHandle));
            COMMON_LVVV(("entry->deviceType             = %s",     enumToFullString((DmiCoolingDeviceType)entry->deviceType)));
            COMMON_LVVV(("entry->status                 = %s",     enumToFullString((DmiCoolingDeviceStatus)entry->status)));
            COMMON_LVVV(("entry->deviceTypeAndStatus    = 0x%02X", entry->deviceTypeAndStatus));
            COMMON_LVVV(("entry->coolingUnitGroup       = %u",     entry->coolingUnitGroup));
            COMMON_LVVV(("entry->oemDefined             = 0x%08X", entry->oemDefined));
            COMMON_LVVV(("entry->nominalSpeed           = %u",     entry->nominalSpeed));

            if (entryV27)
            {
                COMMON_LVVV(("entryV27->description.id = %u", entryV27->description.id));
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->temperatureProbeHandle == 0x0000,                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceType             == DmiCoolingDeviceType::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->status                 == DmiCoolingDeviceStatus::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceTypeAndStatus    == 0x00,                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->coolingUnitGroup       == 0,                             NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->oemDefined             == 0x00000000,                    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->nominalSpeed           == 0,                             NgosStatus::ASSERTION); // Commented due to value variation

            if (entryV27)
            {
                // COMMON_TEST_ASSERT(entryV27->description.id == 1, NgosStatus::ASSERTION); // Commented due to value variation

                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntryV27), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry), NgosStatus::ASSERTION);
            }
        }
    }



    // Get strings
    {
        DmiStringId descriptionStringId;

        if (entryV27)
        {
            descriptionStringId = entryV27->description;
        }



        if (descriptionStringId.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == descriptionStringId)
                    {
                        COMMON_LVVV(("description = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiTemperatureProbeEntry(DmiTemperatureProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id    = %u",     entry->description.id));
            COMMON_LVVV(("entry->location          = %s",     enumToFullString((DmiTemperatureProbeLocation)entry->location)));
            COMMON_LVVV(("entry->status            = %s",     enumToFullString((DmiTemperatureProbeStatus)entry->status)));
            COMMON_LVVV(("entry->locationAndStatus = 0x%02X", entry->locationAndStatus));
            COMMON_LVVV(("entry->maximumValue      = %u",     entry->maximumValue));
            COMMON_LVVV(("entry->minimumValue      = %u",     entry->minimumValue));
            COMMON_LVVV(("entry->resolution        = %u",     entry->resolution));
            COMMON_LVVV(("entry->tolerance         = %u",     entry->tolerance));
            COMMON_LVVV(("entry->accuracy          = %u",     entry->accuracy));
            COMMON_LVVV(("entry->oemDefined        = 0x%08X", entry->oemDefined));
            COMMON_LVVV(("entry->nominalValue      = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id    == 1,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->location          == DmiTemperatureProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->status            == DmiTemperatureProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->locationAndStatus == 0x00,                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maximumValue      == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->minimumValue      == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->resolution        == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->tolerance         == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->accuracy          == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->oemDefined        == 0x00000000,                         NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->nominalValue      == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiTemperatureProbeEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiElectricalCurrentProbeEntry(DmiElectricalCurrentProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id    = %u",     entry->description.id));
            COMMON_LVVV(("entry->location          = %s",     enumToFullString((DmiElectricalCurrentProbeLocation)entry->location)));
            COMMON_LVVV(("entry->status            = %s",     enumToFullString((DmiElectricalCurrentProbeStatus)entry->status)));
            COMMON_LVVV(("entry->locationAndStatus = 0x%02X", entry->locationAndStatus));
            COMMON_LVVV(("entry->maximumValue      = %u",     entry->maximumValue));
            COMMON_LVVV(("entry->minimumValue      = %u",     entry->minimumValue));
            COMMON_LVVV(("entry->resolution        = %u",     entry->resolution));
            COMMON_LVVV(("entry->tolerance         = %u",     entry->tolerance));
            COMMON_LVVV(("entry->accuracy          = %u",     entry->accuracy));
            COMMON_LVVV(("entry->oemDefined        = 0x%08X", entry->oemDefined));
            COMMON_LVVV(("entry->nominalValue      = %u",     entry->nominalValue));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id    == 1,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->location          == DmiElectricalCurrentProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->status            == DmiElectricalCurrentProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->locationAndStatus == 0x00,                                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maximumValue      == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->minimumValue      == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->resolution        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->tolerance         == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->accuracy          == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->oemDefined        == 0x00000000,                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->nominalValue      == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiElectricalCurrentProbeEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiOutOfBandRemoteAccessEntry(DmiOutOfBandRemoteAccessEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->manufacturerName.id = %u", entry->manufacturerName.id));
            COMMON_LVVV(("entry->connections         = %s", flagsToFullString(entry->connections)));
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(entry->manufacturerName.id == 1,                                                      NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->connections         == FLAGS(DmiOutOfBandRemoteAccessConnectionFlag::INBOUND), NgosStatus::ASSERTION);

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOutOfBandRemoteAccessEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->manufacturerName.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->manufacturerName)
                    {
                        COMMON_LVVV(("manufacturerName = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemBootEntry(DmiSystemBootEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->bootStatus = %s", enumToFullString(entry->bootStatus)));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->bootStatus == DmiSystemBootStatus::NO_ERROR, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemBootEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiBits64MemoryErrorInformationEntry(DmiBits64MemoryErrorInformationEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->errorType               = %s",        enumToFullString(entry->errorType)));
            COMMON_LVVV(("entry->errorGranularity        = %s",        enumToFullString(entry->errorGranularity)));
            COMMON_LVVV(("entry->errorOperation          = %s",        enumToFullString(entry->errorOperation)));
            COMMON_LVVV(("entry->vendorSyndrome          = 0x%08X",    entry->vendorSyndrome));
            COMMON_LVVV(("entry->memoryArrayErrorAddress = 0x%016llX", entry->memoryArrayErrorAddress));
            COMMON_LVVV(("entry->deviceErrorAddress      = 0x%016llX", entry->deviceErrorAddress));
            COMMON_LVVV(("entry->errorResolution         = 0x%08X",    entry->errorResolution));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->errorType               == DmiBits64MemoryErrorInformationErrorType::OK,             NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->errorGranularity        == DmiBits64MemoryErrorInformationErrorGranularity::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->errorOperation          == DmiBits64MemoryErrorInformationErrorOperation::UNKNOWN,   NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->vendorSyndrome          == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->memoryArrayErrorAddress == 0x8000000000000000,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceErrorAddress      == 0x8000000000000000,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->errorResolution         == 0x80000000,                                               NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBits64MemoryErrorInformationEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiManagementDeviceEntry(DmiManagementDeviceEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id = %u",     entry->description.id));
            COMMON_LVVV(("entry->type           = %s",     enumToFullString(entry->type)));
            COMMON_LVVV(("entry->address        = 0x%08X", entry->address));
            COMMON_LVVV(("entry->addressType    = %s",     enumToFullString(entry->addressType)));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->type           == DmiManagementDeviceType::OTHER,        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->address        == 0x00000000,                            NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->addressType    == DmiManagementDeviceAddressType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiManagementDeviceComponentEntry(DmiManagementDeviceComponentEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->description.id         = %u",     entry->description.id));
            COMMON_LVVV(("entry->managementDeviceHandle = 0x%04X", entry->managementDeviceHandle));
            COMMON_LVVV(("entry->componentHandle        = 0x%04X", entry->componentHandle));
            COMMON_LVVV(("entry->thresholdHandle        = 0x%04X", entry->thresholdHandle));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->description.id         == 1,      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->managementDeviceHandle == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->componentHandle        == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->thresholdHandle        == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceComponentEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->description.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->description)
                    {
                        COMMON_LVVV(("description = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiManagementDeviceThresholdDataEntry(DmiManagementDeviceThresholdDataEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->lowerThresholdNonCritical    = %u", entry->lowerThresholdNonCritical));
            COMMON_LVVV(("entry->upperThresholdNonCritical    = %u", entry->upperThresholdNonCritical));
            COMMON_LVVV(("entry->lowerThresholdCritical       = %u", entry->lowerThresholdCritical));
            COMMON_LVVV(("entry->upperThresholdCritical       = %u", entry->upperThresholdCritical));
            COMMON_LVVV(("entry->lowerThresholdNonRecoverable = %u", entry->lowerThresholdNonRecoverable));
            COMMON_LVVV(("entry->upperThresholdNonRecoverable = %u", entry->upperThresholdNonRecoverable));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->lowerThresholdNonCritical    == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->upperThresholdNonCritical    == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->lowerThresholdCritical       == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->upperThresholdCritical       == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->lowerThresholdNonRecoverable == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->upperThresholdNonRecoverable == 0, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceThresholdDataEntry), NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemPowerSupplyEntry(DmiSystemPowerSupplyEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->powerUnitGroup                                     = %u",     entry->powerUnitGroup));
            COMMON_LVVV(("entry->location.id                                        = %u",     entry->location.id));
            COMMON_LVVV(("entry->deviceName.id                                      = %u",     entry->deviceName.id));
            COMMON_LVVV(("entry->manufacturer.id                                    = %u",     entry->manufacturer.id));
            COMMON_LVVV(("entry->serialNumber.id                                    = %u",     entry->serialNumber.id));
            COMMON_LVVV(("entry->assetTagNumber.id                                  = %u",     entry->assetTagNumber.id));
            COMMON_LVVV(("entry->modelPartNumber.id                                 = %u",     entry->modelPartNumber.id));
            COMMON_LVVV(("entry->revisionLevel.id                                   = %u",     entry->revisionLevel.id));
            COMMON_LVVV(("entry->maxPowerCapacity                                   = %u",     entry->maxPowerCapacity));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.hotReplaceable          = %u",     entry->powerSupplyCharacteristics.hotReplaceable));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.present                 = %u",     entry->powerSupplyCharacteristics.present));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.unplugged               = %u",     entry->powerSupplyCharacteristics.unplugged));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.inputVoltageRangeSwitch = %s",     enumToFullString((DmiSystemPowerSupplyInputVoltageRangeSwitch)entry->powerSupplyCharacteristics.inputVoltageRangeSwitch)));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.status                  = %s",     enumToFullString((DmiSystemPowerSupplyStatus)entry->powerSupplyCharacteristics.status)));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.type                    = %s",     enumToFullString((DmiSystemPowerSupplyType)entry->powerSupplyCharacteristics.type)));
            COMMON_LVVV(("entry->powerSupplyCharacteristics.value16                 = 0x%04X", entry->powerSupplyCharacteristics.value16));
            COMMON_LVVV(("entry->inputVoltageProbeHandle                            = 0x%04X", entry->inputVoltageProbeHandle));
            COMMON_LVVV(("entry->coolingDeviceHandle                                = 0x%04X", entry->coolingDeviceHandle));
            COMMON_LVVV(("entry->inputCurrentProbeHandle                            = 0x%04X", entry->inputCurrentProbeHandle));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->powerUnitGroup                                     == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->location.id                                        == 1,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceName.id                                      == 2,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->manufacturer.id                                    == 3,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->serialNumber.id                                    == 4,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->assetTagNumber.id                                  == 5,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->modelPartNumber.id                                 == 6,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->revisionLevel.id                                   == 7,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->maxPowerCapacity                                   == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.hotReplaceable          == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.present                 == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.unplugged               == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.inputVoltageRangeSwitch == DmiSystemPowerSupplyInputVoltageRangeSwitch::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.status                  == DmiSystemPowerSupplyStatus::OTHER,                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.type                    == DmiSystemPowerSupplyType::OTHER,                    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->powerSupplyCharacteristics.value16                 == 0x0000,                                             NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->inputVoltageProbeHandle                            == 0x0000,                                             NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->coolingDeviceHandle                                == 0x0000,                                             NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->inputCurrentProbeHandle                            == 0x0000,                                             NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemPowerSupplyEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            entry->location.id
            ||
            entry->deviceName.id
            ||
            entry->manufacturer.id
            ||
            entry->serialNumber.id
            ||
            entry->assetTagNumber.id
            ||
            entry->modelPartNumber.id
            ||
            entry->revisionLevel.id
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->location)
                    {
                        COMMON_LVVV(("location = %s", begin));
                    }
                    else
                    if (stringId == entry->deviceName)
                    {
                        COMMON_LVVV(("deviceName = %s", begin));
                    }
                    else
                    if (stringId == entry->manufacturer)
                    {
                        COMMON_LVVV(("manufacturer = %s", begin));
                    }
                    else
                    if (stringId == entry->serialNumber)
                    {
                        COMMON_LVVV(("serialNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->assetTagNumber)
                    {
                        COMMON_LVVV(("assetTagNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->modelPartNumber)
                    {
                        COMMON_LVVV(("modelPartNumber = %s", begin));
                    }
                    else
                    if (stringId == entry->revisionLevel)
                    {
                        COMMON_LVVV(("revisionLevel = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiAdditionalInformationEntry(DmiAdditionalInformationEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->numberOfAdditionalInformationEntries = %u", entry->numberOfAdditionalInformationEntries));



            // entry->additionalInformationEntries:
            {
#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                COMMON_LVVV(("entry->additionalInformationEntries:"));
                COMMON_LVVV(("-------------------------------------"));

                DmiAdditionalInformation *curInfo = &entry->additionalInformationEntries[0];

                for (i64 i = 0; i < entry->numberOfAdditionalInformationEntries; ++i)
                {
                    COMMON_LVVV(("curInfo->entryLength      = %u",     curInfo->entryLength));
                    COMMON_LVVV(("curInfo->referencedHandle = 0x%04X", curInfo->referencedHandle));
                    COMMON_LVVV(("curInfo->referencedOffset = %u",     curInfo->referencedOffset));
                    COMMON_LVVV(("curInfo->string.id        = %u",     curInfo->string.id));
                    COMMON_LVVV(("curInfo->value[0]         = 0x%02X", curInfo->value[0]));

                    curInfo = (DmiAdditionalInformation *)((u64)curInfo + curInfo->entryLength);
                }

                COMMON_LVVV(("-------------------------------------"));
#endif
            }
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->numberOfAdditionalInformationEntries             == 1,      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].entryLength      == 6,      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].referencedHandle == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].referencedOffset == 1,      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].string.id        == 0,      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].value[0]         == 0x00,   NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiAdditionalInformationEntry) + sizeof(DmiAdditionalInformation), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->numberOfAdditionalInformationEntries > 0)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiOnboardDevicesExtendedEntry(DmiOnboardDevicesExtendedEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        // Output variables
        {
            COMMON_LVVV(("entry->referenceDesignation.id       = %u",     entry->referenceDesignation.id));
            COMMON_LVVV(("entry->deviceType                    = %s",     enumToFullString((DmiOnboardDevicesExtendedDeviceType)entry->deviceType)));
            COMMON_LVVV(("entry->enabled                       = %u",     entry->enabled));
            COMMON_LVVV(("entry->deviceTypeAndEnabled          = 0x%02X", entry->deviceTypeAndEnabled));
            COMMON_LVVV(("entry->deviceTypeInstance            = %u",     entry->deviceTypeInstance));
            COMMON_LVVV(("entry->segmentGroupNumber            = %u",     entry->segmentGroupNumber));
            COMMON_LVVV(("entry->busNumber                     = %u",     entry->busNumber));
            COMMON_LVVV(("entry->functionNumber                = %u",     entry->functionNumber));
            COMMON_LVVV(("entry->deviceNumber                  = %u",     entry->deviceNumber));
            COMMON_LVVV(("entry->functionNumberAndDeviceNumber = 0x%02X", entry->functionNumberAndDeviceNumber));
        }



        // Check variables
        {
            // COMMON_TEST_ASSERT(entry->referenceDesignation.id       == 1,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceType                    == DmiOnboardDevicesExtendedDeviceType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->enabled                       == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceTypeAndEnabled          == 0x00,                                       NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceTypeInstance            == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->segmentGroupNumber            == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->busNumber                     == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->functionNumber                == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceNumber                  == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->functionNumberAndDeviceNumber == 0x00,                                       NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesExtendedEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->referenceDesignation.id)
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (stringId == entry->referenceDesignation)
                    {
                        COMMON_LVVV(("referenceDesignation = %s", begin));
                    }



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiInactiveEntry(DmiInactiveEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        // Output variables
        {
            // Nothing
        }



        // Check variables
        {
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiInactiveEntry), NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            ((u8 *)entry)[entry->header.length]     != 0
            ||
            ((u8 *)entry)[entry->header.length + 1] != 0
           )
        {
            char8 *cur   = (char8 *)entry + entry->header.length;
            char8 *begin = cur;

            AVOID_UNUSED(begin);

            COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



            DmiStringId stringId;

            do
            {
                if (cur[0] == 0)
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                    if (cur[1] == 0)
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);
        }
    }



    return NgosStatus::OK;
}

NgosStatus DMI::storeDmiMemoryDevices()
{
    COMMON_LT((""));



    u64 position = 0;



    for (i64 i = 0; i < (i64)sMemoryDeviceEntries.getSize(); ++i)
    {
        DmiMemoryDeviceEntry *entry = sMemoryDeviceEntries.at(i);

        DmiMemoryDeviceEntryV23 *entryV23 = DMI::getVersion() >= DMI_VERSION(2, 3) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV23) ? (DmiMemoryDeviceEntryV23 *)entry : nullptr;
        DmiMemoryDeviceEntryV27 *entryV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV27) ? (DmiMemoryDeviceEntryV27 *)entry : nullptr;
        DmiMemoryDeviceEntryV32 *entryV32 = DMI::getVersion() >= DMI_VERSION(3, 2) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV32) ? (DmiMemoryDeviceEntryV32 *)entry : nullptr;
        DmiMemoryDeviceEntryV33 *entryV33 = DMI::getVersion() >= DMI_VERSION(3, 3) && entry->header.length >= sizeof(DmiMemoryDeviceEntryV33) ? (DmiMemoryDeviceEntryV33 *)entry : nullptr;



        if (entry->memoryArrayHandle == sSystemPhysicalMemoryArrayHandle)
        {
            DmiMemoryDevice device;



            // Init memory device
            {
                device.memoryType = entry->memoryType;



                // Set speed
                {
                    if (entryV23)
                    {
                        if (entryV23->speed == DMI_MEMORY_DEVICE_SPEED_UNKNOWN)
                        {
                            device.speed = 0;
                        }
                        else
                        if (
                            entryV23->speed == DMI_MEMORY_DEVICE_SPEED_NEED_TO_EXTEND
                            &&
                            entryV33
                           )
                        {
                            device.speed = entryV33->extendedSpeed;
                        }
                        else
                        {
                            device.speed = entryV23->speed;
                        }
                    }
                    else
                    {
                        device.speed = 0;
                    }
                }



                // Set size
                {
                    if (entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_NOT_INSTALLED)
                    {
                        device.size = 0;
                    }
                    else
                    if (entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_UNKNOWN)
                    {
                        device.size = MEMORY_DEVICE_SIZE_UNKNOWN;
                    }
                    else
                    if (
                        entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_NEED_TO_EXTEND
                        &&
                        entryV27
                       )
                    {
                        device.size = entryV27->extendedSize.size();
                    }
                    else
                    {
                        device.size = entry->size.size();
                    }



                    if (
                        device.size != 0
                        &&
                        device.size != MEMORY_DEVICE_SIZE_UNKNOWN
                       )
                    {
                        sTotalAmountOfMemory += device.size;
                    }
                }



                // Set range
                {
                    u64 start = 0xFFFFFFFFFFFFFFFF;
                    u64 end   = 0;

                    for (i64 j = 0; j < (i64)sMemoryDeviceMappedAddressEntries.getSize(); ++j)
                    {
                        DmiMemoryDeviceMappedAddressEntry *deviceMappedAddress = sMemoryDeviceMappedAddressEntries.at(j);

                        if (deviceMappedAddress->memoryDeviceHandle == entry->header.handle)
                        {
                            DmiMemoryDeviceMappedAddressEntryV27 *deviceMappedAddressV27 = DMI::getVersion() >= DMI_VERSION(2, 7) && deviceMappedAddress->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntryV27) ? (DmiMemoryDeviceMappedAddressEntryV27 *)deviceMappedAddress : nullptr;



                            u64 newStart;
                            u64 newEnd;

                            if (
                                deviceMappedAddress->startingAddress.value == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_STARTING_ADDRESS_NEED_TO_EXTEND
                                &&
                                deviceMappedAddress->endingAddress.value == DMI_MEMORY_DEVICE_MAPPED_ADDRESS_ENDING_ADDRESS_NEED_TO_EXTEND
                                &&
                                deviceMappedAddressV27
                               )
                            {
                                newStart = deviceMappedAddressV27->extendedStartingAddress;
                                newEnd   = deviceMappedAddressV27->extendedEndingAddress;
                            }
                            else
                            {
                                newStart = deviceMappedAddress->startingAddress.address();
                                newEnd   = deviceMappedAddress->endingAddress.address(1);
                            }



                            if (newStart < start)
                            {
                                start = newStart;
                            }

                            if (newEnd > end)
                            {
                                end = newEnd;
                            }
                        }
                    }



                    if (end != 0)
                    {
                        COMMON_TEST_ASSERT(start != 0xFFFFFFFFFFFFFFFF, NgosStatus::ASSERTION);
                        COMMON_TEST_ASSERT(start < end,                 NgosStatus::ASSERTION);

                        device.start = start;
                        device.end   = end;
                    }
                    else
                    {
                        COMMON_TEST_ASSERT(start == 0xFFFFFFFFFFFFFFFF, NgosStatus::ASSERTION);

                        if (!sMemoryDeviceMappedAddressEntries.isEmpty())
                        {
                            device.start = 0;
                            device.end   = 0;
                        }
                        else
                        {
                            if (
                                device.size != 0
                                &&
                                device.size != MEMORY_DEVICE_SIZE_UNKNOWN
                               )
                            {
                                device.start =  position;
                                position     += device.size;
                                device.end   =  position;
                            }
                            else
                            {
                                device.start = 0;
                                device.end   = 0;
                            }
                        }
                    }
                }



                device.deviceLocator = nullptr;
                device.manufacturer  = nullptr;
                device.serialNumber  = nullptr;
                device.partNumber    = nullptr;
            }



            // Get strings
            {
                DmiStringId manufacturerStringId;
                DmiStringId serialNumberStringId;
                DmiStringId assetTagStringId;
                DmiStringId partNumberStringId;
                DmiStringId firmwareVersionStringId;

                if (entryV23)
                {
                    manufacturerStringId = entryV23->manufacturer;
                    serialNumberStringId = entryV23->serialNumber;
                    assetTagStringId     = entryV23->assetTag;
                    partNumberStringId   = entryV23->partNumber;

                    if (entryV32)
                    {
                        firmwareVersionStringId = entryV32->firmwareVersion;
                    }
                }



                if (
                    entry->deviceLocator.id
                    ||
                    entry->bankLocator.id
                    ||
                    manufacturerStringId.id
                    ||
                    serialNumberStringId.id
                    ||
                    assetTagStringId.id
                    ||
                    partNumberStringId.id
                    ||
                    firmwareVersionStringId.id
                   )
                {
                    char8 *cur   = (char8 *)entry + entry->header.length;
                    char8 *begin = cur;

                    AVOID_UNUSED(begin);

                    COMMON_TEST_ASSERT(cur[0] != 0 || cur[1] != 0, NgosStatus::ASSERTION);



                    DmiStringId stringId;

                    do
                    {
                        if (cur[0] == 0)
                        {
                            ++stringId;
                            COMMON_LVVV(("String #%u: %s", stringId.id, begin));



                            if (stringId == entry->deviceLocator)
                            {
                                COMMON_ASSERT_EXECUTION(storeString(begin, cur - begin + 1, &device.deviceLocator), NgosStatus::ASSERTION);
                            }
                            else
                            if (stringId == manufacturerStringId)
                            {
                                COMMON_ASSERT_EXECUTION(storeString(begin, cur - begin + 1, &device.manufacturer), NgosStatus::ASSERTION);
                            }
                            else
                            if (stringId == serialNumberStringId)
                            {
                                COMMON_ASSERT_EXECUTION(storeString(begin, cur - begin + 1, &device.serialNumber), NgosStatus::ASSERTION);
                            }
                            else
                            if (stringId == partNumberStringId)
                            {
                                COMMON_ASSERT_EXECUTION(storeString(begin, cur - begin + 1, &device.partNumber), NgosStatus::ASSERTION);
                            }



                            if (cur[1] == 0)
                            {
                                break;
                            }

                            begin = cur + 1;
                        }



                        ++cur;
                    } while(true);
                }
                else
                {
                    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
                }
            }



            if (device.size != 0)
            {
                COMMON_ASSERT_EXECUTION(sMemoryDevices.insert(sNumberOfInstalledMemoryDevices, device), NgosStatus::ASSERTION);

                ++sNumberOfInstalledMemoryDevices;
            }
            else
            {
                COMMON_ASSERT_EXECUTION(sMemoryDevices.append(device), NgosStatus::ASSERTION);
            }
        }
    }



    if (sMemoryDevices.isEmpty())
    {
        COMMON_LC(("Failed to get information about memory devices"));

        return NgosStatus::NOT_FOUND;
    }



    return NgosStatus::OK;
}

NgosStatus DMI::storeIdentity(DmiIdentity id, const char8 *address, u64 size)
{
    COMMON_LT((" | id = %u, address = 0x%p, size = %u", id, address, size));

    COMMON_ASSERT(address,  "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",    NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(sIdentities[(u64)id] == nullptr, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(storeString(address, size, &sIdentities[(u64)id]), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::storeUuid(DmiStoredUuid id, Uuid *uuid)
{ // Ignore CppNgosTraceVerifier
    COMMON_LT((" | id = %u, uuid = %s", id, uuidToString(uuid)));



    COMMON_TEST_ASSERT(sUuids[(u64)id] == nullptr, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sizeof(Uuid)    == 16,      NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in pro file
    sUuids[(u64)id] = uuid;
#else
    u8 *brkAddress;

    COMMON_ASSERT_EXECUTION(BRK::allocate(sizeof(Uuid), 1, &brkAddress), NgosStatus::ASSERTION);
    ((u64 *)brkAddress)[0] = ((u64 *)uuid)[0];
    ((u64 *)brkAddress)[1] = ((u64 *)uuid)[1];

    sUuids[(u64)id] = (Uuid *)brkAddress;
#endif



    return NgosStatus::OK;
}

NgosStatus DMI::storeString(const char8 *address, u64 size, const char8 **destination)
{
    COMMON_LT((" | address = 0x%p, size = %u, destination = 0x%p", address, size, destination));

    COMMON_ASSERT(address,     "address is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,    "size is zero",        NgosStatus::ASSERTION);
    COMMON_ASSERT(destination, "destination is null", NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in pro file
    *destination = address;

    AVOID_UNUSED(size);
#else
    COMMON_ASSERT_EXECUTION(BRK::allocate(size, 1, (u8 **)destination), NgosStatus::ASSERTION);
    memcpy((char8 *)*destination, address, size);
#endif



    return NgosStatus::OK;
}

u8 DMI::checksum(u8 *address, u64 size, u8 checksumValue)
{
    COMMON_LT((" | address = 0x%p, size = %u, checksumValue = %u", address, size, checksumValue));

    COMMON_ASSERT(address,  "address is null", 0);
    COMMON_ASSERT(size > 0, "size is zero",    0);



    u8 res = checksumValue;

    while (size > 0)
    {
        res -= *address;

        ++address;
        --size;
    }



    return res;
}
