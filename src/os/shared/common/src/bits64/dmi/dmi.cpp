#include "dmi.h"

#include <common/src/bits64/dmi/entry/dmimemorydeviceentry.h>
#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>
#include <common/src/bits64/string/utils.h>
#include <uuid/utils.h>

#ifdef UEFI_APPLICATION // Defined in Makefile
#include <uefibase/src/bits64/uefi/uefi.h>
#else
#include <kernelbase/src/bits64/other/brk/brk.h>
#include <kernelbase/src/bits64/other/ioremap/ioremap.h>
#include <kernelbase/src/bits64/other/uefi/uefi.h>
#endif



#define DMI_VERSION(major, minor)        (((major) << 16) + ((minor) << 8))
#define DMI_VERSION_3(major, minor, doc) (((major) << 16) + ((minor) << 8) + (doc))

#define DMI_CHASSIS_CONTAINED_ELEMENT(entry, i) (DmiChassisContainedElement *)((u64)(entry)->containedElements + (i) * (entry)->containedElementRecordLength)



u32              DMI::sVersion;
u16              DMI::sNumberOfSmbiosStructures;
u32              DMI::sStructureTableLength;
u64              DMI::sStructureTableAddress;
DmiChassisType   DMI::sChassisType;
u64              DMI::sNumberOfMemoryDevices;
DmiMemoryDevice *DMI::sMemoryDevices;
const char8*     DMI::sIdentities[(u64)DmiIdentity::MAXIMUM];
Uuid*            DMI::sUuids[(u64)DmiStoredUuid::MAXIMUM];



NgosStatus DMI::init()
{
    COMMON_LT((""));



    UefiSmbios3ConfigurationTable *smbios3 = UEFI::getSmbios3Config();

    if (smbios3)
    {
#ifdef UEFI_APPLICATION // Defined in Makefile
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
#ifdef UEFI_APPLICATION // Defined in Makefile
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



#ifdef UEFI_APPLICATION // Defined in Makefile
    COMMON_ASSERT_EXECUTION(iterateDmiEntries((u8 *)sStructureTableAddress, decodeDmiEntry), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(storeDmiMemoryDevices((u8 *)sStructureTableAddress),             NgosStatus::ASSERTION);
#else
    u8 *buf;

    COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping(sStructureTableAddress, sStructureTableLength, (void **)&buf), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, decodeDmiEntry),                                                 NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(storeDmiMemoryDevices(buf),                                                             NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)buf, sStructureTableLength),                           NgosStatus::ASSERTION);
#endif



    COMMON_LV(("SMBIOS version is %u.%u", sVersion >> 16, (sVersion >> 8) & 0xFF));
    COMMON_LV(("DMI: %s %s, BIOS %s %s %s", sIdentities[(u64)DmiIdentity::SYSTEM_MANUFACTURER], sIdentities[(u64)DmiIdentity::SYSTEM_PRODUCT_NAME], sIdentities[(u64)DmiIdentity::BIOS_VENDOR], sIdentities[(u64)DmiIdentity::BIOS_VERSION], sIdentities[(u64)DmiIdentity::BIOS_RELEASE_DATE]));



    // Validation
    {
        COMMON_LVVV(("sVersion                  = 0x%08X", sVersion));
        COMMON_LVVV(("sNumberOfSmbiosStructures = %u",     sNumberOfSmbiosStructures));
        COMMON_LVVV(("sStructureTableLength     = %u",     sStructureTableLength));
        COMMON_LVVV(("sStructureTableAddress    = 0x%p",   sStructureTableAddress));
        COMMON_LVVV(("sChassisType              = %s",     enumToFullString(sChassisType)));
        COMMON_LVVV(("sNumberOfMemoryDevices    = %u",     sNumberOfMemoryDevices));

#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            COMMON_LVVV(("sMemoryDevices:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)sNumberOfMemoryDevices; ++i)
            {
                COMMON_LVVV(("#%-3d: 0x%04X | %s | %s | %s | %s | %s | %s | %s | %s", i, sMemoryDevices[i].handle, bytesToString(sMemoryDevices[i].size), stringToString(sMemoryDevices[i].device), stringToString(sMemoryDevices[i].bank), stringToString(sMemoryDevices[i].manufacturer), stringToString(sMemoryDevices[i].serialNumber), stringToString(sMemoryDevices[i].assetTag), stringToString(sMemoryDevices[i].partNumber), stringToString(sMemoryDevices[i].firmwareVersion)));
            }

            COMMON_LVVV(("-------------------------------------"));



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



            COMMON_LVVV(("sUuids:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)DmiStoredUuid::MAXIMUM; ++i)
            {
                COMMON_LVVV(("%-11s: %s", enumToFullString((DmiStoredUuid)i), uuidToString(sUuids[i])));
            }

            COMMON_LVVV(("-------------------------------------"));
        }
#endif



        // COMMON_TEST_ASSERT(sVersion                  == 0x00020800,              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sNumberOfSmbiosStructures == 9,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sStructureTableLength     == 395,                     NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sStructureTableAddress       != 0,                       NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sChassisType              == DmiChassisType::DESKTOP, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sNumberOfMemoryDevices    == 1,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices[0].handle  == 0x1100,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices[0].device  != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices[0].bank    == 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sMemoryDevices[0].size    == 1073741824,              NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((u64)DmiIdentity::MAXIMUM    == 26,                      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[0]               != 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[1]               != 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[2]               != 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[3]               != 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[4]               != 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[5]               != 0,                       NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sIdentities[6]            != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[7]            != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[8]            != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[9]            1= 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[10]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[11]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[12]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[13]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[14]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sIdentities[15]              != 0,                       NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sIdentities[16]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[17]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[18]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[19]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sIdentities[20]              != 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[21]              != 0,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[22]              != 0,                       NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sIdentities[23]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[24]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[25]           != 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((u64)DmiStoredUuid::MAXIMUM  == 1,                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sUuids[0]                    != 0,                       NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sUuids[0]->data1          == 0x9FAE0773,              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data2          == 0xF53F,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data3          == 0x4A15,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data4          == 0x8A,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data5          == 0x11,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[0]       == 0xED,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[1]       == 0x76,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[2]       == 0xA1,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[3]       == 0x0F,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[4]       == 0x4E,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[5]       == 0x5B,                    NgosStatus::ASSERTION); // Commented due to value variation
    }



    return NgosStatus::OK;
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
        COMMON_LVVV(("smbios3->reserved                    = %u",   smbios3->reserved));
        COMMON_LVVV(("smbios3->structureTableMaximumSize   = %u",   smbios3->structureTableMaximumSize));
        COMMON_LVVV(("smbios3->structureTableAddress       = 0x%p", smbios3->structureTableAddress));



        COMMON_TEST_ASSERT((*(u64 *)smbios3->anchor & 0x000000FFFFFFFFFF) == SMBIOS_3_ANCHOR,                                                                          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->entryPointStructureChecksum           == checksum((u8 *)smbios3, smbios3->entryPointLength, smbios3->entryPointStructureChecksum), NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->entryPointLength                      == 24,                                                                                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->majorVersion                          == 3,                                                                                        NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios3->minorVersion                       == 2,                                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(smbios3->docRevision                        == 0,                                                                                        NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios3->entryPointRevision                    == 1,                                                                                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->reserved                              == 0,                                                                                        NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios3->structureTableMaximumSize          == 4070,                                                                                     NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios3->structureTableAddress                 != 0,                                                                                        NgosStatus::ASSERTION);
    }



    sVersion               = DMI_VERSION_3(smbios3->majorVersion, smbios3->minorVersion, smbios3->docRevision);
    sStructureTableLength  = smbios3->structureTableMaximumSize;
    sStructureTableAddress = smbios3->structureTableAddress;



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
    sStructureTableLength     = smbios->structureTableLength;
    sStructureTableAddress    = smbios->structureTableAddress;



    return NgosStatus::OK;
}

NgosStatus DMI::iterateDmiEntries(u8 *buf, process_dmi_entry processDmiEntry)
{
    COMMON_LT((" | buf = 0x%p, processDmiEntry = 0x%p", buf, processDmiEntry));

    COMMON_ASSERT(buf,             "buf is null",             NgosStatus::ASSERTION);
    COMMON_ASSERT(processDmiEntry, "processDmiEntry is null", NgosStatus::ASSERTION);



    i64  i   = 0;
    u8  *cur = buf;
    u8  *end = buf + sStructureTableLength;

    while (
           (
            !sNumberOfSmbiosStructures // sNumberOfSmbiosStructures == 0
            ||
            i < sNumberOfSmbiosStructures
           )
           &&
           cur + sizeof(DmiEntryHeader) <= end
          )
    {
        DmiEntryHeader *dmiEntryHeader = (DmiEntryHeader *)cur;



        COMMON_LVV(("Processing DMI header at address 0x%p", dmiEntryHeader));

        COMMON_LVVV(("dmiEntryHeader->type   = %s",     enumToFullString(dmiEntryHeader->type)));
        COMMON_LVVV(("dmiEntryHeader->length = %u",     dmiEntryHeader->length));
        COMMON_LVVV(("dmiEntryHeader->handle = 0x%04X", dmiEntryHeader->handle));



        cur += dmiEntryHeader->length;

        // We are getting total DMI entry size until we met 2 zeros in buffer that let us avoid issues on decoding
        while (
               (cur < end - 1)
               &&
               (
                cur[0]
                ||
                cur[1]
               )
              )
        {
            ++cur;
        }

        if (cur < end - 1)
        {
            COMMON_ASSERT_EXECUTION(processDmiEntry(dmiEntryHeader), NgosStatus::ASSERTION);
        }
        else
        {
            break;
        }



        cur += 2;
        ++i;



        // Starting from SMBIOS 3 there is no information about amount of entries.
        // Therefore we should stop iterating when we met entry with the special DmiEntryType::END_OF_TABLE type
        if (
            !sNumberOfSmbiosStructures // sNumberOfSmbiosStructures == 0
            &&
            dmiEntryHeader->type == DmiEntryType::END_OF_TABLE
           )
        {
            break;
        }
    }

    COMMON_TEST_ASSERT(cur                             == end,                       NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sStructureTableLength           == cur - buf,                 NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!sNumberOfSmbiosStructures || i == sNumberOfSmbiosStructures, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::decodeDmiEntry(DmiEntryHeader *header)
{
    COMMON_LT((" | header = 0x%p", header));

    COMMON_ASSERT(header, "header is null", NgosStatus::ASSERTION);



    switch (header->type)
    {
        case DmiEntryType::BIOS:                        COMMON_ASSERT_EXECUTION(saveDmiBiosEntry((DmiBiosEntry *)header),                                         NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM:                      COMMON_ASSERT_EXECUTION(saveDmiSystemEntry((DmiSystemEntry *)header),                                     NgosStatus::ASSERTION); break;
        case DmiEntryType::BASEBOARD:                   COMMON_ASSERT_EXECUTION(saveDmiBaseboardEntry((DmiBaseboardEntry *)header),                               NgosStatus::ASSERTION); break;
        case DmiEntryType::CHASSIS:                     COMMON_ASSERT_EXECUTION(saveDmiChassisEntry((DmiChassisEntry *)header),                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::PROCESSOR:                   COMMON_ASSERT_EXECUTION(saveDmiProcessorEntry((DmiProcessorEntry *)header),                               NgosStatus::ASSERTION); break;
        case DmiEntryType::PHYSICAL_MEMORY_ARRAY:       COMMON_ASSERT_EXECUTION(saveDmiPhysicalMemoryArrayEntry((DmiPhysicalMemoryArrayEntry *)header),           NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS: COMMON_ASSERT_EXECUTION(saveDmiMemoryArrayMappedAddressEntry((DmiMemoryArrayMappedAddressEntry *)header), NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_BOOT:                 COMMON_ASSERT_EXECUTION(saveDmiSystemBootEntry((DmiSystemBootEntry *)header),                             NgosStatus::ASSERTION); break;

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



    // Validation
    {
        COMMON_LVVV(("entry->vendorStringId          = %u",     entry->vendorStringId));
        COMMON_LVVV(("entry->biosVersionStringId     = %u",     entry->biosVersionStringId));
        COMMON_LVVV(("entry->biosSegment             = 0x%04X", entry->biosSegment));
        COMMON_LVVV(("entry->biosReleaseDateStringId = %u",     entry->biosReleaseDateStringId));
        COMMON_LVVV(("entry->biosSize                = %u",     entry->biosSize));
        COMMON_LVVV(("entry->biosCharacteristics     = %s",     flagsToFullString(entry->biosCharacteristics)));

        if (sVersion >= DMI_VERSION(2, 1))
        {
            COMMON_LVVV(("entry->biosCharacteristicsExtension.biosReserved = %s", flagsToFullString(entry->biosCharacteristicsExtension.biosReserved)));

            if (sVersion >= DMI_VERSION(2, 3))
            {
                COMMON_LVVV(("entry->biosCharacteristicsExtension.systemReserved = %s", flagsToFullString(entry->biosCharacteristicsExtension.systemReserved)));
                COMMON_LVVV(("entry->systemBiosMajorRelease                      = %u", entry->systemBiosMajorRelease));
                COMMON_LVVV(("entry->systemBiosMinorRelease                      = %u", entry->systemBiosMinorRelease));
                COMMON_LVVV(("entry->embeddedControllerFirmwareMajorRelease      = %u", entry->embeddedControllerFirmwareMajorRelease));
                COMMON_LVVV(("entry->embeddedControllerFirmwareMinorRelease      = %u", entry->embeddedControllerFirmwareMinorRelease));

                if (sVersion >= DMI_VERSION(3, 1))
                {
                    COMMON_LVVV(("entry->extendedBiosSize.size = %u", entry->extendedBiosSize.size));
                    COMMON_LVVV(("entry->extendedBiosSize.unit = %u", entry->extendedBiosSize.unit));
                }
            }
        }



        COMMON_TEST_ASSERT(entry->vendorStringId          == 1,                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->biosVersionStringId     == 2,                                                                     NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->biosSegment          == 0xE800,                                                                NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->biosReleaseDateStringId == 3,                                                                     NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->biosSize             == 39,                                                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->biosCharacteristics  == FLAGS(DmiBiosCharacteristicsFlag::BIOS_CHARACTERISTICS_NOT_SUPPORTED), NgosStatus::ASSERTION); // Commented due to value variation

        if (sVersion >= DMI_VERSION(2, 1))
        {
            // COMMON_TEST_ASSERT(entry->biosCharacteristicsExtension.biosReserved == FLAG(DmiBiosCharacteristicsBiosReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

            if (sVersion >= DMI_VERSION(2, 3))
            {
                // COMMON_TEST_ASSERT(entry->biosCharacteristicsExtension.systemReserved == FLAG(DmiBiosCharacteristicsSystemReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->systemBiosMajorRelease                      == 15,                                                   NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->systemBiosMinorRelease                      == 103,                                                  NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->embeddedControllerFirmwareMajorRelease      == 151,                                                  NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->embeddedControllerFirmwareMinorRelease      == 78,                                                   NgosStatus::ASSERTION); // Commented due to value variation

                if (sVersion >= DMI_VERSION(3, 1))
                {
                    // COMMON_TEST_ASSERT(entry->extendedBiosSize.size == 0, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->extendedBiosSize.unit == 0, NgosStatus::ASSERTION); // Commented due to value variation

                    COMMON_TEST_ASSERT(entry->header.length >= 26,                   NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry), NgosStatus::ASSERTION);
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= 24,                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry) - 2, NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 19,                       NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry) - 7, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 18,                       NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry) - 8, NgosStatus::ASSERTION);
        }
    }



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%u: %s", stringId, begin));



            if (stringId == entry->vendorStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BIOS_VENDOR, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->biosVersionStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BIOS_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->biosReleaseDateStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BIOS_RELEASE_DATE, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }



            if (!cur[1]) // cur[1] == 0
            {
                break;
            }

            begin = cur + 1;
        }



        ++cur;
    } while(true);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemEntry(DmiSystemEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->manufacturerStringId = %u", entry->manufacturerStringId));
        COMMON_LVVV(("entry->productNameStringId  = %u", entry->productNameStringId));
        COMMON_LVVV(("entry->versionStringId      = %u", entry->versionStringId));
        COMMON_LVVV(("entry->serialNumberStringId = %u", entry->serialNumberStringId));
        COMMON_LVVV(("entry->uuid                 = %s", uuidToString(entry->uuid)));
        COMMON_LVVV(("entry->wakeUpTime           = %s", enumToFullString(entry->wakeUpTime)));
        COMMON_LVVV(("entry->skuNumberStringId    = %u", entry->skuNumberStringId));
        COMMON_LVVV(("entry->familyStringId       = %u", entry->familyStringId));



        COMMON_TEST_ASSERT(entry->manufacturerStringId     == 1,                                 NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->productNameStringId      == 2,                                 NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->versionStringId          == 3,                                 NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->serialNumberStringId  == 4,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data1            == 0x9FAE0773,                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data2            == 0xF53F,                            NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data3            == 0x4A15,                            NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data4            == 0x8A,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data5            == 0x11,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[0]         == 0xED,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[1]         == 0x76,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[2]         == 0xA1,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[3]         == 0x0F,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[4]         == 0x4E,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[5]         == 0x5B,                              NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->wakeUpTime               == DmiSystemWakeUpTime::POWER_SWITCH, NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->skuNumberStringId     == 5,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->familyStringId        == 6,                                 NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 27,                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry), NgosStatus::ASSERTION);
    }



    COMMON_ASSERT_EXECUTION(saveUuid(DmiStoredUuid::SYSTEM_UUID, entry->uuid), NgosStatus::ASSERTION);



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%u: %s", stringId, begin));



            if (stringId == entry->manufacturerStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->productNameStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_PRODUCT_NAME, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->versionStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->serialNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_SERIAL_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->skuNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_SKU_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->familyStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_FAMILY, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }



            if (!cur[1]) // cur[1] == 0
            {
                break;
            }

            begin = cur + 1;
        }



        ++cur;
    } while(true);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiBaseboardEntry(DmiBaseboardEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->manufacturerStringId           = %u",     entry->manufacturerStringId));
        COMMON_LVVV(("entry->productStringId                = %u",     entry->productStringId));
        COMMON_LVVV(("entry->versionStringId                = %u",     entry->versionStringId));
        COMMON_LVVV(("entry->serialNumberStringId           = %u",     entry->serialNumberStringId));
        COMMON_LVVV(("entry->assetTagStringId               = %u",     entry->assetTagStringId));
        COMMON_LVVV(("entry->featureFlags                   = %s",     flagsToFullString(entry->featureFlags)));
        COMMON_LVVV(("entry->locationInChassisStringId      = %u",     entry->locationInChassisStringId));
        COMMON_LVVV(("entry->chassisHandle                  = 0x%04X", entry->chassisHandle));
        COMMON_LVVV(("entry->boardType                      = %s",     enumToFullString(entry->boardType)));
        COMMON_LVVV(("entry->numberOfContainedObjectHandles = %u",     entry->numberOfContainedObjectHandles));

#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            COMMON_LVVV(("entry->containedObjectHandles:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < entry->numberOfContainedObjectHandles; ++i)
            {
                COMMON_LVVV(("#%-3d: 0x%04X", i, entry->containedObjectHandles[i]));
            }

            COMMON_LVVV(("-------------------------------------"));
        }
#endif



        COMMON_TEST_ASSERT(entry->manufacturerStringId           == 1,                                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->productStringId                == 2,                                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->versionStringId                == 3,                                           NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->serialNumberStringId        == 4,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->assetTagStringId            == 5,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->featureFlags                == FLAGS(DmiBaseboardFeatureFlag::MOTHERBOARD), NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->locationInChassisStringId   == 6,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->chassisHandle               == 0x0300,                                      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->boardType                   == DmiBaseboardType::MOTHERBOARD,               NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->numberOfContainedObjectHandles == 0,                                           NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->containedObjectHandles[0]   == 0,                                           NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 15                        + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBaseboardEntry) + entry->numberOfContainedObjectHandles * sizeof(entry->containedObjectHandles[0]), NgosStatus::ASSERTION);
    }



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%u: %s", stringId, begin));



            if (stringId == entry->manufacturerStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->productStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_PRODUCT, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->versionStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->serialNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_SERIAL_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->assetTagStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_ASSET_TAG, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->locationInChassisStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_LOCATION_IN_CHASSIS, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }



            if (!cur[1]) // cur[1] == 0
            {
                break;
            }

            begin = cur + 1;
        }



        ++cur;
    } while(true);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiChassisEntry(DmiChassisEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    sChassisType = entry->type;

    u8 skuNumberStringId = 0;

    if (sVersion >= DMI_VERSION(2, 7))
    {
        skuNumberStringId = *(u8 *)DMI_CHASSIS_CONTAINED_ELEMENT(entry, entry->containedElementCount);
    }



    // Validation
    {
        COMMON_LVVV(("entry->manufacturerStringId = %u", entry->manufacturerStringId));
        COMMON_LVVV(("entry->type                 = %s", enumToFullString(entry->type)));
        COMMON_LVVV(("entry->versionStringId      = %u", entry->versionStringId));
        COMMON_LVVV(("entry->serialNumberStringId = %u", entry->serialNumberStringId));
        COMMON_LVVV(("entry->assetTagStringId     = %u", entry->assetTagStringId));
        COMMON_LVVV(("entry->bootUpState          = %s", enumToFullString(entry->bootUpState)));
        COMMON_LVVV(("entry->powerSupplyState     = %s", enumToFullString(entry->powerSupplyState)));
        COMMON_LVVV(("entry->thermalState         = %s", enumToFullString(entry->thermalState)));
        COMMON_LVVV(("entry->securityStatus       = %s", enumToFullString(entry->securityStatus)));
        COMMON_LVVV(("entry->oemDefined[0]        = %u", entry->oemDefined[0]));
        COMMON_LVVV(("entry->oemDefined[1]        = %u", entry->oemDefined[1]));
        COMMON_LVVV(("entry->oemDefined[2]        = %u", entry->oemDefined[2]));
        COMMON_LVVV(("entry->oemDefined[3]        = %u", entry->oemDefined[3]));

        if (sVersion >= DMI_VERSION(2, 7))
        {
            COMMON_LVVV(("entry->height                       = %u", entry->height));
            COMMON_LVVV(("entry->numberOfPowerCords           = %u", entry->numberOfPowerCords));
            COMMON_LVVV(("entry->containedElementCount        = %u", entry->containedElementCount));
            COMMON_LVVV(("entry->containedElementRecordLength = %u", entry->containedElementRecordLength));

#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
            {
                COMMON_LVVV(("entry->containedElements:"));
                COMMON_LVVV(("-------------------------------------"));

                for (i64 i = 0; i < entry->containedElementCount; ++i)
                {
                    DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entry, i);

                    COMMON_LVVV(("containedElement[%-3d]->type    = %s", i, enumToFullString(containedElement->type)));
                    COMMON_LVVV(("containedElement[%-3d]->minimum = %u", i, containedElement->minimum));
                    COMMON_LVVV(("containedElement[%-3d]->maximum = %u", i, containedElement->maximum));
                }

                COMMON_LVVV(("-------------------------------------"));
            }
#endif

            COMMON_LVVV(("skuNumberStringId = %u", skuNumberStringId));
        }



        COMMON_TEST_ASSERT(entry->manufacturerStringId    == 1,                                 NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->type                 == DmiChassisType::DESKTOP,           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->versionStringId      == 2,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->serialNumberStringId == 3,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->assetTagStringId     == 4,                                 NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->bootUpState             == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->powerSupplyState        == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->thermalState         == DmiChassisState::SAFE,             NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->securityStatus       == DmiChassisSecurityStatus::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->oemDefined[0]           == 0,                                 NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->oemDefined[1]           == 0,                                 NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->oemDefined[2]           == 0,                                 NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->oemDefined[3]           == 0,                                 NgosStatus::ASSERTION);

        if (sVersion >= DMI_VERSION(2, 7))
        {
            // COMMON_TEST_ASSERT(entry->height                                    == 0,                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->numberOfPowerCords                        == 1,                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->containedElementCount                     == 0,                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->containedElementRecordLength              == 3,                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->type    == DmiChassisType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->minimum == 0,                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->maximum == 0,                     NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(skuNumberStringId                                == 5,                     NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= 21                      + entry->containedElementCount * entry->containedElementRecordLength + 1, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) + entry->containedElementCount * entry->containedElementRecordLength + 1, NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 17,                          NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) - 4, NgosStatus::ASSERTION);
        }
    }



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%u: %s", stringId, begin));



            if (stringId == entry->manufacturerStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->versionStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->serialNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_SERIAL_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->assetTagStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_ASSET_TAG, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == skuNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_SKU_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }



            if (!cur[1]) // cur[1] == 0
            {
                break;
            }

            begin = cur + 1;
        }



        ++cur;
    } while(true);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiProcessorEntry(DmiProcessorEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->socketStringId                   = %u",     entry->socketStringId));
        COMMON_LVVV(("entry->processorType                    = %s",     enumToFullString(entry->processorType)));
        COMMON_LVVV(("entry->processorFamily                  = %s",     enumToFullString(entry->processorFamily)));
        COMMON_LVVV(("entry->processorManufactureStringId     = %u",     entry->processorManufactureStringId));
        COMMON_LVVV(("entry->processorId.signature.steppingId = %u",     entry->processorId.signature.steppingId));
        COMMON_LVVV(("entry->processorId.signature.model      = %u",     entry->processorId.signature.model));
        COMMON_LVVV(("entry->processorId.signature.family     = %u",     entry->processorId.signature.family));
        COMMON_LVVV(("entry->processorId.signature.type       = %u",     entry->processorId.signature.type));
        COMMON_LVVV(("entry->processorId.signature.xModel     = %u",     entry->processorId.signature.xModel));
        COMMON_LVVV(("entry->processorId.signature.xFamily    = %u",     entry->processorId.signature.xFamily));
        COMMON_LVVV(("entry->processorId.featureFlags         = %s",     flagsToFullString(entry->processorId.featureFlags)));
        COMMON_LVVV(("entry->processorVersionStringId         = %u",     entry->processorVersionStringId));
        COMMON_LVVV(("entry->voltage                          = %s",     flagsToFullString(entry->voltage)));
        COMMON_LVVV(("entry->externalClock                    = %u",     entry->externalClock));
        COMMON_LVVV(("entry->maxSpeed                         = %u",     entry->maxSpeed));
        COMMON_LVVV(("entry->currentSpeed                     = %u",     entry->currentSpeed));
        COMMON_LVVV(("entry->status                           = %u",     entry->status));
        COMMON_LVVV(("entry->processorUpgrade                 = %s",     enumToFullString(entry->processorUpgrade)));
        COMMON_LVVV(("entry->l1CacheHandle                    = 0x%04X", entry->l1CacheHandle));
        COMMON_LVVV(("entry->l2CacheHandle                    = 0x%04X", entry->l2CacheHandle));
        COMMON_LVVV(("entry->l3CacheHandle                    = 0x%04X", entry->l3CacheHandle));
        COMMON_LVVV(("entry->serialNumberStringId             = %u",     entry->serialNumberStringId));
        COMMON_LVVV(("entry->assetTagStringId                 = %u",     entry->assetTagStringId));
        COMMON_LVVV(("entry->partNumberStringId               = %u",     entry->partNumberStringId));

        if (sVersion >= DMI_VERSION(2, 5))
        {
            COMMON_LVVV(("entry->coreCount                = %u",     entry->coreCount));
            COMMON_LVVV(("entry->enabledCoreCount         = %u",     entry->enabledCoreCount));
            COMMON_LVVV(("entry->threadCount              = %u",     entry->threadCount));
            COMMON_LVVV(("entry->processorCharacteristics = 0x%04X", entry->processorCharacteristics));

            if (sVersion >= DMI_VERSION(2, 6))
            {
                COMMON_LVVV(("entry->processorFamily2 = %s", enumToFullString(entry->processorFamily2)));

                if (sVersion >= DMI_VERSION(3, 0))
                {
                    COMMON_LVVV(("entry->coreCount2        = %u", entry->coreCount2));
                    COMMON_LVVV(("entry->enabledCoreCount2 = %u", entry->enabledCoreCount2));
                    COMMON_LVVV(("entry->threadCount2      = %u", entry->threadCount2));
                }
            }
        }



        // Ignore CppAlignmentVerifier [BEGIN]
        // COMMON_TEST_ASSERT(entry->socketStringId                   == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->processorType                       == DmiProcessorType::CENTRAL_PROCESSOR,  NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->processorFamily                  == DmiProcessorFamily::OTHER,            NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->processorManufactureStringId        == 2,                                    NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->processorId.signature.steppingId == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.signature.model      == 12,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.signature.family     == 6,                                    NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->processorId.signature.type          == 0,                                    NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->processorId.signature.xModel     == 3,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.signature.xFamily    == 0,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.featureFlags         == FLAGS(DmiProcessorFeatureFlag::FPU                            // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::VME                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::DE                           // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::PSE                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::TSC                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::MSR                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::PAE                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::MCE                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::CX8                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::APIC                         // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::SEP                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::MTRR                         // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::PGE                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::MCA                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::CMOV                         // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::PAT                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::PSE36                        // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::CLFSH                        // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::MMX                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::FXSR                         // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::SSE                          // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::SSE2                         // Commented due to value variation
        //                                                                     , DmiProcessorFeatureFlag::SS), NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorVersionStringId         == 3,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->voltage                          == FLAG(DmiProcessorVoltageFlag::NONE),  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->externalClock                    == 100,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maxSpeed                         == 2000,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->currentSpeed                     == 2000,                                 NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->status                              == 65,                                   NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->processorUpgrade                 == DmiProcessorUpgrade::OTHER,           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->l1CacheHandle                    == 0xFFFF,                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->l2CacheHandle                    == 0xFFFF,                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->l3CacheHandle                    == 0xFFFF,                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->serialNumberStringId             == 4,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->assetTagStringId                 == 5,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->partNumberStringId               == 6,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // Ignore CppAlignmentVerifier [END]

        if (sVersion >= DMI_VERSION(2, 5))
        {
            // COMMON_TEST_ASSERT(entry->coreCount                == 2,      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->enabledCoreCount         == 2,      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->threadCount              == 2,      NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->processorCharacteristics == 0x0002, NgosStatus::ASSERTION); // Commented due to value variation

            if (sVersion >= DMI_VERSION(2, 6))
            {
                // COMMON_TEST_ASSERT(entry->processorFamily2 == DmiProcessorFamily2::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

                if (sVersion >= DMI_VERSION(3, 0))
                {
                    // COMMON_TEST_ASSERT(entry->coreCount2        == 2, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->enabledCoreCount2 == 2, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->threadCount2      == 2, NgosStatus::ASSERTION); // Commented due to value variation

                    COMMON_TEST_ASSERT(entry->header.length >= 48,                        NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry), NgosStatus::ASSERTION);
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= 42,                            NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 6, NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 40,                            NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 8, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 35,                             NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 13, NgosStatus::ASSERTION);
        }
    }



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%u: %s", stringId, begin));



            if (stringId == entry->socketStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::PROCESSOR_SOCKET, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->processorManufactureStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::PROCESSOR_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->processorVersionStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::PROCESSOR_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->serialNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::PROCESSOR_SERIAL_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->assetTagStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::PROCESSOR_ASSET_TAG, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->partNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::PROCESSOR_PART_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }



            if (!cur[1]) // cur[1] == 0
            {
                break;
            }

            begin = cur + 1;
        }



        ++cur;
    } while(true);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiPhysicalMemoryArrayEntry(DmiPhysicalMemoryArrayEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        COMMON_LVVV(("entry->location                     = %s",     enumToFullString(entry->location)));
        COMMON_LVVV(("entry->use                          = %s",     enumToFullString(entry->use)));
        COMMON_LVVV(("entry->memoryErrorCorrection        = %s",     enumToFullString(entry->memoryErrorCorrection)));
        COMMON_LVVV(("entry->maximumCapacity              = 0x%08X", entry->maximumCapacity));
        COMMON_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
        COMMON_LVVV(("entry->numberOfMemoryDevices        = %u",     entry->numberOfMemoryDevices));

        if (sVersion >= DMI_VERSION(2, 7))
        {
            COMMON_LVVV(("entry->extendedMaximumCapacity = 0x%016lX", entry->extendedMaximumCapacity));
        }



        // COMMON_TEST_ASSERT(entry->location                     == DmiPhysicalMemoryArrayLocation::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->use                          == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY,             NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryErrorCorrection        == DmiPhysicalMemoryArrayErrorCorrection::MULTI_BIT_ECC, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumCapacity              == 0x00100000,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->numberOfMemoryDevices        == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation

        if (sVersion >= DMI_VERSION(2, 7))
        {
            // COMMON_TEST_ASSERT(entry->extendedMaximumCapacity == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= 23,                                  NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntry), NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 15,                                      NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPhysicalMemoryArrayEntry) - 8, NgosStatus::ASSERTION);
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



    AVOID_UNUSED(entry);



    // Validation
    {
        COMMON_LVVV(("entry->startingAddress   = 0x%08X", entry->startingAddress));
        COMMON_LVVV(("entry->endingAddress     = 0x%08X", entry->endingAddress));
        COMMON_LVVV(("entry->memoryArrayHandle = 0x%04X", entry->memoryArrayHandle));
        COMMON_LVVV(("entry->partitionWidth    = %u",     entry->partitionWidth));

        if (sVersion >= DMI_VERSION(2, 7))
        {
            COMMON_LVVV(("entry->extendedStartingAddress = 0x%016lX", entry->extendedStartingAddress));
            COMMON_LVVV(("entry->extendedEndingAddress   = 0x%016lX", entry->extendedEndingAddress));
        }



        // COMMON_TEST_ASSERT(entry->startingAddress   == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->endingAddress     == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryArrayHandle == 0x1000,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->partitionWidth    == 1,          NgosStatus::ASSERTION); // Commented due to value variation

        if (sVersion >= DMI_VERSION(2, 7))
        {
            // COMMON_TEST_ASSERT(entry->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= 31,                                       NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntry), NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 15,                                            NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryArrayMappedAddressEntry) - 16, NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiSystemBootEntry(DmiSystemBootEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        COMMON_LVVV(("entry->bootStatus = %s", enumToFullString(entry->bootStatus)));

        // COMMON_TEST_ASSERT(entry->bootStatus == DmiSystemBootStatus::NO_ERROR, NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 11,                         NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemBootEntry), NgosStatus::ASSERTION);
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::storeDmiMemoryDevices(u8 *buf)
{
    COMMON_LT((" | buf = 0x%p", buf));

    COMMON_ASSERT(buf, "buf is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, countDmiMemoryDevices), NgosStatus::ASSERTION);

    if (sNumberOfMemoryDevices)
    {
        COMMON_LVV(("Found memory devices: %u", sNumberOfMemoryDevices));

        u64 size = sNumberOfMemoryDevices * sizeof(DmiMemoryDevice);



#ifdef UEFI_APPLICATION // Defined in Makefile
        if (UEFI::allocatePool(UefiMemoryType::LOADER_DATA, size, (void **)&sMemoryDevices) != UefiStatus::SUCCESS)
        {
            COMMON_LF(("Failed to allocate pool(%u) for memory devices", size));

            return NgosStatus::OUT_OF_MEMORY;
        }

        COMMON_LVV(("Allocated pool(0x%p, %u) for memory devices", sMemoryDevices, size));
#else
        COMMON_ASSERT_EXECUTION(BRK::allocate(size, 1, (u8 **)&sMemoryDevices), NgosStatus::ASSERTION);
#endif

        COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, saveDmiMemoryDevice), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_LW(("Memory devices not found"));
    }



    return NgosStatus::OK;
}

NgosStatus DMI::countDmiMemoryDevices(DmiEntryHeader *header)
{
    COMMON_LT((" | header = 0x%p", header));

    COMMON_ASSERT(header, "header is null", NgosStatus::ASSERTION);



    if (header->type != DmiEntryType::MEMORY_DEVICE)
    {
        return NgosStatus::OK;
    }



    COMMON_LVV(("DmiEntryType::MEMORY_DEVICE found at address 0x%p", header));

    ++sNumberOfMemoryDevices;



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiMemoryDevice(DmiEntryHeader *header)
{
    COMMON_LT((" | header = 0x%p", header));

    COMMON_ASSERT(header, "header is null", NgosStatus::ASSERTION);



    if (header->type != DmiEntryType::MEMORY_DEVICE)
    {
        return NgosStatus::OK;
    }

    DmiMemoryDeviceEntry *entry = (DmiMemoryDeviceEntry *)header;



    // Validation
    {
        COMMON_LVVV(("entry->memoryArrayHandle            = 0x%04X", entry->memoryArrayHandle));
        COMMON_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
        COMMON_LVVV(("entry->totalWidth                   = %u",     entry->totalWidth));
        COMMON_LVVV(("entry->dataWidth                    = %u",     entry->dataWidth));
        COMMON_LVVV(("entry->size                         = %u",     entry->size));
        COMMON_LVVV(("entry->formFactor                   = %s",     enumToFullString(entry->formFactor)));
        COMMON_LVVV(("entry->deviceSet                    = %u",     entry->deviceSet));
        COMMON_LVVV(("entry->deviceLocatorStringId        = %u",     entry->deviceLocatorStringId));
        COMMON_LVVV(("entry->bankLocatorStringId          = %u",     entry->bankLocatorStringId));
        COMMON_LVVV(("entry->memoryType                   = %s",     enumToFullString(entry->memoryType)));
        COMMON_LVVV(("entry->typeDetail                   = %s",     flagsToFullString(entry->typeDetail)));
        COMMON_LVVV(("entry->speed                        = %u",     entry->speed));
        COMMON_LVVV(("entry->manufacturerStringId         = %u",     entry->manufacturerStringId));
        COMMON_LVVV(("entry->serialNumberStringId         = %u",     entry->serialNumberStringId));
        COMMON_LVVV(("entry->assetTagStringId             = %u",     entry->assetTagStringId));
        COMMON_LVVV(("entry->partNumberStringId           = %u",     entry->partNumberStringId));

        if (sVersion >= DMI_VERSION(2, 7))
        {
            COMMON_LVVV(("entry->attributes            = 0x%02X", entry->attributes));
            COMMON_LVVV(("entry->extendedSize          = %u",     entry->extendedSize));
            COMMON_LVVV(("entry->configuredMemorySpeed = %u",     entry->configuredMemorySpeed));

            if (sVersion >= DMI_VERSION(2, 8))
            {
                COMMON_LVVV(("entry->minimumVoltage    = %u", entry->minimumVoltage));
                COMMON_LVVV(("entry->maximumVoltage    = %u", entry->maximumVoltage));
                COMMON_LVVV(("entry->configuredVoltage = %u", entry->configuredVoltage));

                if (sVersion >= DMI_VERSION(3, 2))
                {
                    COMMON_LVVV(("entry->memoryTechnology                        = %s", enumToFullString(entry->memoryTechnology)));
                    COMMON_LVVV(("entry->memoryOperatingModeCapability           = %s", flagsToFullString(entry->memoryOperatingModeCapability)));
                    COMMON_LVVV(("entry->firmwareVersionStringId                 = %u", entry->firmwareVersionStringId));
                    COMMON_LVVV(("entry->moduleManufacturerID                    = %u", entry->moduleManufacturerID));
                    COMMON_LVVV(("entry->moduleProductID                         = %u", entry->moduleProductID));
                    COMMON_LVVV(("entry->memorySubsystemControllerManufacturerID = %u", entry->memorySubsystemControllerManufacturerID));
                    COMMON_LVVV(("entry->memorySubsystemControllerProductID      = %u", entry->memorySubsystemControllerProductID));
                    COMMON_LVVV(("entry->nonVolatileSize                         = %u", entry->nonVolatileSize));
                    COMMON_LVVV(("entry->volatileSize                            = %u", entry->volatileSize));
                    COMMON_LVVV(("entry->cacheSize                               = %u", entry->cacheSize));
                    COMMON_LVVV(("entry->logicalSize                             = %u", entry->logicalSize));
                }
            }
        }



        // COMMON_TEST_ASSERT(entry->memoryArrayHandle         == 0x1000,                                      NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                      NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->totalWidth                == 65535,                                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->dataWidth                 == 65535,                                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->size                      == 1024,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->formFactor                == DmiMemoryDeviceFormFactor::DIMM,             NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->deviceSet                    == 0,                                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->deviceLocatorStringId        == 1,                                           NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->bankLocatorStringId       == 2,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryType                == DmiMemoryDeviceType::RAM,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->typeDetail                == FLAGS(DmiMemoryDeviceTypeDetailFlag::OTHER), NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->speed                     == 0,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->manufacturerStringId      == 3,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->serialNumberStringId      == 4,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->assetTagStringId          == 5,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->partNumberStringId        == 6,                                           NgosStatus::ASSERTION); // Commented due to value variation

        if (sVersion >= DMI_VERSION(2, 7))
        {
            // COMMON_TEST_ASSERT(entry->attributes            == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->extendedSize          == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->configuredMemorySpeed == 0, NgosStatus::ASSERTION); // Commented due to value variation

            if (sVersion >= DMI_VERSION(2, 8))
            {
                // COMMON_TEST_ASSERT(entry->minimumVoltage    == 0, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->maximumVoltage    == 0, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->configuredVoltage == 0, NgosStatus::ASSERTION); // Commented due to value variation

                if (sVersion >= DMI_VERSION(3, 2))
                {
                    COMMON_TEST_ASSERT(entry->memoryTechnology                        == DmiMemoryDeviceTechnology::NONE,                         NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->memoryOperatingModeCapability           == FLAGS(DmiMemoryDeviceOperatingModeCapabilityFlag::NONE), NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->firmwareVersionStringId                 == 7,                                                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->moduleManufacturerID                    == 0,                                                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->moduleProductID                         == 0,                                                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->memorySubsystemControllerManufacturerID == 0,                                                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->memorySubsystemControllerProductID      == 0,                                                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->nonVolatileSize                         == 0,                                                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->volatileSize                            == 0,                                                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->cacheSize                               == 0,                                                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->logicalSize                             == 0,                                                       NgosStatus::ASSERTION);

                    COMMON_TEST_ASSERT(entry->header.length >= 84,                           NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry), NgosStatus::ASSERTION);
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= 40,                                NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 44, NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 34,                                NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 50, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 27,                                NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 57, NgosStatus::ASSERTION);
        }
    }



    static u64 memoryId;

    COMMON_TEST_ASSERT(memoryId < sNumberOfMemoryDevices, NgosStatus::ASSERTION);



    sMemoryDevices[memoryId].handle = entry->header.handle;

    if (!entry->size)   // entry->size == 0 // Not installed
    {
        sMemoryDevices[memoryId].size = 0;
    }
    else
    if (entry->size == 0xFFFF)  // Uknown value
    {
        sMemoryDevices[memoryId].size = 0xFFFFFFFFFFFFFFFF;
    }
    else
    if (entry->size & (1ULL << 15))  // If last bit is set then units is KB
    {
        sMemoryDevices[memoryId].size = (u64)(entry->size & 0x7FFF) << 10; // "<< 10" == "* 1024"
    }
    else
    if (entry->size == 0x7FFF)  // Special case when size is more than 32 GB - 1 MB and we need to use extended size instead
    {
        sMemoryDevices[memoryId].size = (u64)entry->extendedSize << 20;
    }
    else
    {
        sMemoryDevices[memoryId].size = (u64)entry->size << 20;
    }

    sMemoryDevices[memoryId].device          = nullptr;
    sMemoryDevices[memoryId].bank            = nullptr;
    sMemoryDevices[memoryId].manufacturer    = nullptr;
    sMemoryDevices[memoryId].serialNumber    = nullptr;
    sMemoryDevices[memoryId].assetTag        = nullptr;
    sMemoryDevices[memoryId].partNumber      = nullptr;
    sMemoryDevices[memoryId].firmwareVersion = nullptr;



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%u: %s", stringId, begin));



            if (stringId == entry->deviceLocatorStringId)
            {
                COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].device), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->bankLocatorStringId)
            {
                COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].bank), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->manufacturerStringId)
            {
                COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].manufacturer), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->serialNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].serialNumber), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->assetTagStringId)
            {
                COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].assetTag), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->partNumberStringId)
            {
                COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].partNumber), NgosStatus::ASSERTION);
            }
            else
            {
                if (sVersion >= DMI_VERSION(3, 2))
                {
                    if (stringId == entry->firmwareVersionStringId)
                    {
                        COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].firmwareVersion), NgosStatus::ASSERTION);
                    }
                }
            }



            if (!cur[1]) // cur[1] == 0
            {
                break;
            }

            begin = cur + 1;
        }



        ++cur;
    } while(true);



    ++memoryId;



    return NgosStatus::OK;
}

NgosStatus DMI::saveIdentity(DmiIdentity id, u8 *address, u64 size)
{
    COMMON_LT((" | id = %u, address = 0x%p, size = %u", id, address, size));

    COMMON_ASSERT(address,  "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",    NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(sIdentities[(u64)id] == 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(getString(address, size, (u8 **)&sIdentities[(u64)id]), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveUuid(DmiStoredUuid id, const Uuid &uuid)
{ // Ignore CppNgosTraceVerifier
    COMMON_LT((" | id = %u, uuid = %s", id, uuidToString(uuid)));



    COMMON_TEST_ASSERT(sUuids[(u64)id] == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sizeof(Uuid) == 16,   NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in Makefile
    sUuids[(u64)id] = (Uuid *)&uuid; // TODO: Invalid UUID stored
#else
    u8 *brkAddress;

    COMMON_ASSERT_EXECUTION(BRK::allocate(sizeof(Uuid), 1, &brkAddress), NgosStatus::ASSERTION);
    ((u64 *)brkAddress)[0] = ((u64 *)&uuid)[0];
    ((u64 *)brkAddress)[1] = ((u64 *)&uuid)[1];

    sUuids[(u64)id] = (Uuid *)brkAddress;
#endif



    return NgosStatus::OK;
}

NgosStatus DMI::getString(u8 *address, u64 size, u8 **destination)
{
    COMMON_LT((" | address = 0x%p, size = %u, destination = 0x%p", address, size, destination));

    COMMON_ASSERT(address,     "address is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,    "size is zero",        NgosStatus::ASSERTION);
    COMMON_ASSERT(destination, "destination is null", NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in Makefile
    *destination = address;

    AVOID_UNUSED(size);
#else
    COMMON_ASSERT_EXECUTION(BRK::allocate(size, 1, destination), NgosStatus::ASSERTION);
    memcpy(*destination, address, size);
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
