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
                COMMON_LVVV(("#%-3d: 0x%04X | %-5s | %s | %s | %s | %s | %s | %s | %s", i, sMemoryDevices[i].handle, bytesToString(sMemoryDevices[i].size), stringToString(sMemoryDevices[i].device), stringToString(sMemoryDevices[i].bank), stringToString(sMemoryDevices[i].manufacturer), stringToString(sMemoryDevices[i].serialNumber), stringToString(sMemoryDevices[i].assetTag), stringToString(sMemoryDevices[i].partNumber), stringToString(sMemoryDevices[i].firmwareVersion)));
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

NgosStatus DMI::iterateDmiEntries(u8 *buf, process_dmi_entry processDmiEntry)
{
    COMMON_LT((" | buf = 0x%p, processDmiEntry = 0x%p", buf, processDmiEntry));

    COMMON_ASSERT(buf,             "buf is null",             NgosStatus::ASSERTION);
    COMMON_ASSERT(processDmiEntry, "processDmiEntry is null", NgosStatus::ASSERTION);



    i64  i   = 0;
    u8  *cur = buf;

    while (
           !sNumberOfSmbiosStructures // sNumberOfSmbiosStructures == 0
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
        while (
               cur[0]
               ||
               cur[1]
              )
        {
            ++cur;
        }

        COMMON_ASSERT_EXECUTION(processDmiEntry(dmiEntryHeader), NgosStatus::ASSERTION);



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

    COMMON_TEST_ASSERT(!sNumberOfSmbiosStructures || cur == buf + sStructureTableLength, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!sNumberOfSmbiosStructures || i   == sNumberOfSmbiosStructures,   NgosStatus::ASSERTION);



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
        case DmiEntryType::MEMORY_ARRAY_MAPPED_ADDRESS:      COMMON_ASSERT_EXECUTION(saveDmiMemoryArrayMappedAddressEntry((DmiMemoryArrayMappedAddressEntry *)header),           NgosStatus::ASSERTION); break;
        case DmiEntryType::MEMORY_DEVICE_MAPPED_ADDRESS:     COMMON_ASSERT_EXECUTION(saveDmiMemoryDeviceMappedAddressEntry((DmiMemoryDeviceMappedAddressEntry *)header),         NgosStatus::ASSERTION); break;
        case DmiEntryType::PORTABLE_BATTERY:                 COMMON_ASSERT_EXECUTION(saveDmiPortableBatteryEntry((DmiPortableBatteryEntry *)header),                             NgosStatus::ASSERTION); break;
        case DmiEntryType::VOLTAGE_PROBE:                    COMMON_ASSERT_EXECUTION(saveDmiVoltageProbeEntry((DmiVoltageProbeEntry *)header),                                   NgosStatus::ASSERTION); break;
        case DmiEntryType::COOLING_DEVICE:                   COMMON_ASSERT_EXECUTION(saveDmiCoolingDeviceEntry((DmiCoolingDeviceEntry *)header),                                 NgosStatus::ASSERTION); break;
        case DmiEntryType::TEMPERATURE_PROBE:                COMMON_ASSERT_EXECUTION(saveDmiTemperatureProbeEntry((DmiTemperatureProbeEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::ELECTRICAL_CURRENT_PROBE:         COMMON_ASSERT_EXECUTION(saveDmiElectricalCurrentProbeEntry((DmiElectricalCurrentProbeEntry *)header),               NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_BOOT:                      COMMON_ASSERT_EXECUTION(saveDmiSystemBootEntry((DmiSystemBootEntry *)header),                                       NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE:                COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceEntry((DmiManagementDeviceEntry *)header),                           NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE_COMPONENT:      COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceComponentEntry((DmiManagementDeviceComponentEntry *)header),         NgosStatus::ASSERTION); break;
        case DmiEntryType::MANAGEMENT_DEVICE_THRESHOLD_DATA: COMMON_ASSERT_EXECUTION(saveDmiManagementDeviceThresholdDataEntry((DmiManagementDeviceThresholdDataEntry *)header), NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_POWER_SUPPLY:              COMMON_ASSERT_EXECUTION(saveDmiSystemPowerSupplyEntry((DmiSystemPowerSupplyEntry *)header),                         NgosStatus::ASSERTION); break;
        case DmiEntryType::ADDITIONAL:                       COMMON_ASSERT_EXECUTION(saveDmiAdditionalInformationEntry((DmiAdditionalInformationEntry *)header),                 NgosStatus::ASSERTION); break;
        case DmiEntryType::ONBOARD_DEVICES_EXTENDED:         COMMON_ASSERT_EXECUTION(saveDmiOnboardDevicesExtendedEntry((DmiOnboardDevicesExtendedEntry *)header),               NgosStatus::ASSERTION); break;

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
        COMMON_LVVV(("entry->vendorStringId             = %u",     entry->vendorStringId));
        COMMON_LVVV(("entry->biosVersionStringId        = %u",     entry->biosVersionStringId));
        COMMON_LVVV(("entry->biosStartingAddressSegment = 0x%04X", entry->biosStartingAddressSegment));
        COMMON_LVVV(("entry->biosReleaseDateStringId    = %u",     entry->biosReleaseDateStringId));
        COMMON_LVVV(("entry->biosRomSize                = 0x%02X", entry->biosRomSize));
        COMMON_LVVV(("entry->biosCharacteristics        = %s",     flagsToFullString(entry->biosCharacteristics)));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            COMMON_LVVV(("entry->biosCharacteristicsExtension.biosReserved = %s", flagsToFullString(entry->biosCharacteristicsExtension.biosReserved)));

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                COMMON_LVVV(("entry->biosCharacteristicsExtension.systemReserved = %s", flagsToFullString(entry->biosCharacteristicsExtension.systemReserved)));

                if (DMI::getVersion() >= DMI_VERSION(2, 4))
                {
                    COMMON_LVVV(("entry->systemBiosMajorRelease                 = %u", entry->systemBiosMajorRelease));
                    COMMON_LVVV(("entry->systemBiosMinorRelease                 = %u", entry->systemBiosMinorRelease));
                    COMMON_LVVV(("entry->embeddedControllerFirmwareMajorRelease = %u", entry->embeddedControllerFirmwareMajorRelease));
                    COMMON_LVVV(("entry->embeddedControllerFirmwareMinorRelease = %u", entry->embeddedControllerFirmwareMinorRelease));

                    if (DMI::getVersion() >= DMI_VERSION(3, 1))
                    {
                        COMMON_LVVV(("entry->extendedBiosRomSize.value   = %u",     entry->extendedBiosRomSize.value));
                        COMMON_LVVV(("entry->extendedBiosRomSize.unit    = %s",     enumToFullString((DmiBiosExtendedRomSizeUnit)entry->extendedBiosRomSize.unit)));
                        COMMON_LVVV(("entry->extendedBiosRomSize.value16 = 0x%04X", entry->extendedBiosRomSize.value16));
                        COMMON_LVVV(("entry->extendedBiosRomSize         = %s",     bytesToString(entry->extendedBiosRomSize.size())));
                    }
                }
            }
        }



        COMMON_TEST_ASSERT(entry->vendorStringId                == 1,                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->biosVersionStringId           == 2,                                                                     NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->biosStartingAddressSegment == 0xE800,                                                                NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->biosReleaseDateStringId       == 3,                                                                     NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->biosRomSize                == 0xFF,                                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->biosCharacteristics        == FLAGS(DmiBiosCharacteristicsFlag::BIOS_CHARACTERISTICS_NOT_SUPPORTED), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // COMMON_TEST_ASSERT(entry->biosCharacteristicsExtension.biosReserved == FLAG(DmiBiosCharacteristicsBiosReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                // COMMON_TEST_ASSERT(entry->biosCharacteristicsExtension.systemReserved == FLAG(DmiBiosCharacteristicsSystemReservedFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(2, 4))
                {
                    // COMMON_TEST_ASSERT(entry->systemBiosMajorRelease                 == 15,  NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->systemBiosMinorRelease                 == 103, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->embeddedControllerFirmwareMajorRelease == 151, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->embeddedControllerFirmwareMinorRelease == 78,  NgosStatus::ASSERTION); // Commented due to value variation

                    if (DMI::getVersion() >= DMI_VERSION(3, 1))
                    {
                        // COMMON_TEST_ASSERT(entry->extendedBiosRomSize.value   == 0,                                     NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entry->extendedBiosRomSize.unit    == DmiBiosExtendedRomSizeUnit::MEGABYTES, NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entry->extendedBiosRomSize.value16 == 0x0000,                                NgosStatus::ASSERTION); // Commented due to value variation

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
                    COMMON_TEST_ASSERT(entry->header.length >= 20,                       NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosEntry) - 6, NgosStatus::ASSERTION);
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



    // Get strings
    {
        if (
            entry->vendorStringId
            ||
            entry->biosVersionStringId
            ||
            entry->biosReleaseDateStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

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



    // Validation
    {
        COMMON_LVVV(("entry->manufacturerStringId = %u", entry->manufacturerStringId));
        COMMON_LVVV(("entry->productNameStringId  = %u", entry->productNameStringId));
        COMMON_LVVV(("entry->versionStringId      = %u", entry->versionStringId));
        COMMON_LVVV(("entry->serialNumberStringId = %u", entry->serialNumberStringId));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            COMMON_LVVV(("entry->uuid       = %s", uuidToString(entry->uuid)));
            COMMON_LVVV(("entry->wakeUpType = %s", enumToFullString(entry->wakeUpType)));

            if (DMI::getVersion() >= DMI_VERSION(2, 4))
            {
                COMMON_LVVV(("entry->skuNumberStringId = %u", entry->skuNumberStringId));
                COMMON_LVVV(("entry->familyStringId    = %u", entry->familyStringId));
            }
        }



        COMMON_TEST_ASSERT(entry->manufacturerStringId    == 1, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->productNameStringId     == 2, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->versionStringId         == 3, NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->serialNumberStringId == 4, NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // COMMON_TEST_ASSERT(entry->uuid.data1    == 0x9FAE0773,                        NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data2    == 0xF53F,                            NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data3    == 0x4A15,                            NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data4    == 0x8A,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data5    == 0x11,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data6[0] == 0xED,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data6[1] == 0x76,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data6[2] == 0xA1,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data6[3] == 0x0F,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data6[4] == 0x4E,                              NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->uuid.data6[5] == 0x5B,                              NgosStatus::ASSERTION); // Commented due to value variation
            COMMON_TEST_ASSERT(entry->wakeUpType       == DmiSystemWakeUpType::POWER_SWITCH, NgosStatus::ASSERTION);

            if (DMI::getVersion() >= DMI_VERSION(2, 4))
            {
                // COMMON_TEST_ASSERT(entry->skuNumberStringId == 5, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->familyStringId    == 6, NgosStatus::ASSERTION); // Commented due to value variation

                COMMON_TEST_ASSERT(entry->header.length >= 27,                     NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 25,                         NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry) - 2, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 8,                           NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemEntry) - 19, NgosStatus::ASSERTION);
        }
    }



    COMMON_ASSERT_EXECUTION(saveUuid(DmiStoredUuid::SYSTEM_UUID, &entry->uuid), NgosStatus::ASSERTION);



    // Get strings
    {
        u8 skuNumberStringId = 0;
        u8 familyStringId    = 0;

        if (DMI::getVersion() >= DMI_VERSION(2, 4))
        {
            skuNumberStringId = entry->skuNumberStringId;
            familyStringId    = entry->familyStringId;
        }



        if (
            entry->manufacturerStringId
            ||
            entry->productNameStringId
            ||
            entry->versionStringId
            ||
            entry->serialNumberStringId
            ||
            skuNumberStringId
            ||
            familyStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

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
                    if (stringId == skuNumberStringId)
                    {
                        COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_SKU_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == familyStringId)
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
        }
        else
        {
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);
        }
    }



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



    // Get strings
    {
        if (
            entry->manufacturerStringId
            ||
            entry->productStringId
            ||
            entry->versionStringId
            ||
            entry->serialNumberStringId
            ||
            entry->assetTagStringId
            ||
            entry->locationInChassisStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

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



    sChassisType = (DmiChassisType)entry->type;

    u8 skuNumberStringId = 0;

    if (DMI::getVersion() >= DMI_VERSION(2, 7))
    {
        skuNumberStringId = *(u8 *)DMI_CHASSIS_CONTAINED_ELEMENT(entry, entry->containedElementCount);
    }



    // Validation
    {
        COMMON_LVVV(("entry->manufacturerStringId = %u",     entry->manufacturerStringId));
        COMMON_LVVV(("entry->type                 = %s",     enumToFullString((DmiChassisType)entry->type)));
        COMMON_LVVV(("entry->locked               = %u",     entry->locked));
        COMMON_LVVV(("entry->typeAndLocked        = 0x%02X", entry->typeAndLocked));
        COMMON_LVVV(("entry->versionStringId      = %u",     entry->versionStringId));
        COMMON_LVVV(("entry->serialNumberStringId = %u",     entry->serialNumberStringId));
        COMMON_LVVV(("entry->assetTagStringId     = %u",     entry->assetTagStringId));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            COMMON_LVVV(("entry->bootUpState      = %s", enumToFullString(entry->bootUpState)));
            COMMON_LVVV(("entry->powerSupplyState = %s", enumToFullString(entry->powerSupplyState)));
            COMMON_LVVV(("entry->thermalState     = %s", enumToFullString(entry->thermalState)));
            COMMON_LVVV(("entry->securityStatus   = %s", enumToFullString(entry->securityStatus)));

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                COMMON_LVVV(("entry->oemDefined                   = 0x%08X", entry->oemDefined));
                COMMON_LVVV(("entry->height                       = %u",     entry->height));
                COMMON_LVVV(("entry->numberOfPowerCords           = %u",     entry->numberOfPowerCords));
                COMMON_LVVV(("entry->containedElementCount        = %u",     entry->containedElementCount));
                COMMON_LVVV(("entry->containedElementRecordLength = %u",     entry->containedElementRecordLength));

#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
                {
                    COMMON_LVVV(("entry->containedElements:"));
                    COMMON_LVVV(("-------------------------------------"));

                    for (i64 i = 0; i < entry->containedElementCount; ++i)
                    {
                        DmiChassisContainedElement *containedElement = DMI_CHASSIS_CONTAINED_ELEMENT(entry, i);

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
                }
#endif

                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    COMMON_LVVV(("skuNumberStringId = %u", skuNumberStringId));
                }
            }
        }



        COMMON_TEST_ASSERT(entry->manufacturerStringId    == 1,                       NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->type                 == DmiChassisType::DESKTOP, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->locked               == 0,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->typeAndLocked        == 0x03,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->versionStringId      == 2,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->serialNumberStringId == 3,                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->assetTagStringId     == 4,                       NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            COMMON_TEST_ASSERT(entry->bootUpState       == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->powerSupplyState  == DmiChassisState::SAFE,             NgosStatus::ASSERTION);
            // COMMON_TEST_ASSERT(entry->thermalState   == DmiChassisState::SAFE,             NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->securityStatus == DmiChassisSecurityStatus::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                COMMON_TEST_ASSERT(entry->oemDefined                                             == 0x00000000,                                           NgosStatus::ASSERTION);
                // COMMON_TEST_ASSERT(entry->height                                              == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->numberOfPowerCords                                  == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->containedElementCount                               == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->containedElementRecordLength                        == 3,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->type.typeSelect   == DmiChassisContainedElementTypeSelect::DMI_ENTRY_TYPE, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->type.dmiEntryType == DmiEntryType::SYSTEM_POWER_SUPPLY,                    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->type.value8       == 0xA7,                                                 NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->minimum           == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(DMI_CHASSIS_CONTAINED_ELEMENT(entry, 0)->maximum           == 0,                                                    NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    // COMMON_TEST_ASSERT(skuNumberStringId == 5, NgosStatus::ASSERTION); // Commented due to value variation

                    COMMON_TEST_ASSERT(entry->header.length >= 21                      + entry->containedElementCount * entry->containedElementRecordLength + 1, NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) + entry->containedElementCount * entry->containedElementRecordLength + 1, NgosStatus::ASSERTION);
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= 21                      + entry->containedElementCount * entry->containedElementRecordLength, NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) + entry->containedElementCount * entry->containedElementRecordLength, NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 13,                          NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) - 8, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 9,                            NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiChassisEntry) - 12, NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (
            entry->manufacturerStringId
            ||
            entry->versionStringId
            ||
            entry->serialNumberStringId
            ||
            entry->assetTagStringId
            ||
            skuNumberStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

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



    // Validation
    {
        COMMON_LVVV(("entry->socketDesignationStringId            = %u",     entry->socketDesignationStringId));
        COMMON_LVVV(("entry->processorType                        = %s",     enumToFullString(entry->processorType)));
        COMMON_LVVV(("entry->processorFamily                      = %s",     enumToFullString(entry->processorFamily)));
        COMMON_LVVV(("entry->processorManufactureStringId         = %u",     entry->processorManufactureStringId));
        COMMON_LVVV(("entry->processorId.signature.stepping       = %u",     entry->processorId.signature.stepping));
        COMMON_LVVV(("entry->processorId.signature.model          = %u",     entry->processorId.signature.model));
        COMMON_LVVV(("entry->processorId.signature.family         = %u",     entry->processorId.signature.family));
        COMMON_LVVV(("entry->processorId.signature.type           = %u",     entry->processorId.signature.type));
        COMMON_LVVV(("entry->processorId.signature.extendedModel  = %u",     entry->processorId.signature.extendedModel));
        COMMON_LVVV(("entry->processorId.signature.extendedFamily = %u",     entry->processorId.signature.extendedFamily));
        COMMON_LVVV(("entry->processorId.signature.value32        = 0x%08X", entry->processorId.signature.value32));
        COMMON_LVVV(("entry->processorId.featureFlags             = %s",     flagsToFullString(entry->processorId.featureFlags)));
        COMMON_LVVV(("entry->processorVersionStringId             = %u",     entry->processorVersionStringId));
        COMMON_LVVV(("entry->voltage.modeType                     = %s",     enumToFullString((DmiProcessorVoltageModeType)entry->voltage.modeType)));

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

        COMMON_LVVV(("entry->voltage.value8   = 0x%02X", entry->voltage.value8));
        COMMON_LVVV(("entry->externalClock    = %u",     entry->externalClock));
        COMMON_LVVV(("entry->maxSpeed         = %u",     entry->maxSpeed));
        COMMON_LVVV(("entry->currentSpeed     = %u",     entry->currentSpeed));
        COMMON_LVVV(("entry->status           = %s",     enumToFullString((DmiProcessorStatus)entry->status)));
        COMMON_LVVV(("entry->socketPopulated  = %u",     entry->socketPopulated));
        COMMON_LVVV(("entry->processorStatus  = 0x%02X", entry->processorStatus));
        COMMON_LVVV(("entry->processorUpgrade = %s",     enumToFullString(entry->processorUpgrade)));

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            COMMON_LVVV(("entry->l1CacheHandle = 0x%04X", entry->l1CacheHandle));
            COMMON_LVVV(("entry->l2CacheHandle = 0x%04X", entry->l2CacheHandle));
            COMMON_LVVV(("entry->l3CacheHandle = 0x%04X", entry->l3CacheHandle));

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                COMMON_LVVV(("entry->serialNumberStringId = %u", entry->serialNumberStringId));
                COMMON_LVVV(("entry->assetTagStringId     = %u", entry->assetTagStringId));
                COMMON_LVVV(("entry->partNumberStringId   = %u", entry->partNumberStringId));

                if (DMI::getVersion() >= DMI_VERSION(2, 5))
                {
                    COMMON_LVVV(("entry->coreCount                = %u", entry->coreCount));
                    COMMON_LVVV(("entry->enabledCoreCount         = %u", entry->enabledCoreCount));
                    COMMON_LVVV(("entry->threadCount              = %u", entry->threadCount));
                    COMMON_LVVV(("entry->processorCharacteristics = %s", flagsToFullString(entry->processorCharacteristics)));

                    if (DMI::getVersion() >= DMI_VERSION(2, 6))
                    {
                        COMMON_LVVV(("entry->processorFamily2 = %s", enumToFullString(entry->processorFamily2)));

                        if (DMI::getVersion() >= DMI_VERSION(3, 0))
                        {
                            COMMON_LVVV(("entry->coreCount2        = %u", entry->coreCount2));
                            COMMON_LVVV(("entry->enabledCoreCount2 = %u", entry->enabledCoreCount2));
                            COMMON_LVVV(("entry->threadCount2      = %u", entry->threadCount2));
                        }
                    }
                }
            }
        }



        // Ignore CppAlignmentVerifier [BEGIN]
        // COMMON_TEST_ASSERT(entry->socketDesignationStringId            == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->processorType                           == DmiProcessorType::CENTRAL_PROCESSOR,  NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->processorFamily                      == DmiProcessorFamily::OTHER,            NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->processorManufactureStringId            == 2,                                    NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->processorId.signature.stepping       == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.signature.model          == 12,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.signature.family         == 6,                                    NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->processorId.signature.type              == 0,                                    NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->processorId.signature.extendedModel  == 3,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.signature.extendedFamily == 0,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.signature.value32        == 0x00000000,                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorId.featureFlags             == FLAGS(DmiProcessorFeatureFlag::FPU                            // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::VME                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::DE                           // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::PSE                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::TSC                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::MSR                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::PAE                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::MCE                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::CX8                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::APIC                         // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::SEP                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::MTRR                         // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::PGE                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::MCA                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::CMOV                         // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::PAT                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::PSE36                        // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::CLFSH                        // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::MMX                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::FXSR                         // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::SSE                          // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::SSE2                         // Commented due to value variation
        //                                                                         , DmiProcessorFeatureFlag::SS), NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorVersionStringId             == 3,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->voltage                              == FLAG(DmiProcessorVoltageFlag::NONE),  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->externalClock                        == 100,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maxSpeed                             == 2000,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->currentSpeed                         == 2000,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->status                               == DmiProcessorStatus::ENABLED,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->socketPopulated                      == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorStatus                      == 0x41,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->processorUpgrade                     == DmiProcessorUpgrade::OTHER,           NgosStatus::ASSERTION); // Commented due to value variation
        // Ignore CppAlignmentVerifier [END]

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // COMMON_TEST_ASSERT(entry->l1CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->l2CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->l3CacheHandle == 0xFFFF, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 3))
            {
                // COMMON_TEST_ASSERT(entry->serialNumberStringId == 4, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->assetTagStringId     == 5, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->partNumberStringId   == 6, NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(2, 5))
                {
                    // COMMON_TEST_ASSERT(entry->coreCount                == 2,                                                      NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->enabledCoreCount         == 2,                                                      NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->threadCount              == 2,                                                      NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->processorCharacteristics == FLAGS(DmiProcessorCharacteristicsFlag::SUPPORT_64_BIT), NgosStatus::ASSERTION); // Commented due to value variation

                    if (DMI::getVersion() >= DMI_VERSION(2, 6))
                    {
                        // COMMON_TEST_ASSERT(entry->processorFamily2 == DmiProcessorFamily2::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

                        if (DMI::getVersion() >= DMI_VERSION(3, 0))
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
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 32,                             NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 16, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 26,                             NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiProcessorEntry) - 22, NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        u8 serialNumberStringId = 0;
        u8 assetTagStringId     = 0;
        u8 partNumberStringId   = 0;

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            serialNumberStringId = entry->serialNumberStringId;
            assetTagStringId     = entry->assetTagStringId;
            partNumberStringId   = entry->partNumberStringId;
        }



        if (
            entry->socketDesignationStringId
            ||
            entry->processorManufactureStringId
            ||
            entry->processorVersionStringId
            ||
            serialNumberStringId
            ||
            assetTagStringId
            ||
            partNumberStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (stringId == entry->socketDesignationStringId)
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
                    if (stringId == serialNumberStringId)
                    {
                        COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::PROCESSOR_SERIAL_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == assetTagStringId)
                    {
                        COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::PROCESSOR_ASSET_TAG, begin, cur - begin + 1), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == partNumberStringId)
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



    // Validation
    {
        COMMON_LVVV(("entry->socketDesignationStringId          = %u",     entry->socketDesignationStringId));
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

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            COMMON_LVVV(("entry->cacheSpeed          = %u", entry->cacheSpeed));
            COMMON_LVVV(("entry->errorCorrectionType = %s", enumToFullString(entry->errorCorrectionType)));
            COMMON_LVVV(("entry->systemCacheType     = %s", enumToFullString(entry->systemCacheType)));
            COMMON_LVVV(("entry->associativity       = %s", enumToFullString(entry->associativity)));

            if (DMI::getVersion() >= DMI_VERSION(3, 1))
            {
                COMMON_LVVV(("entry->maximumCacheSize2.value       = %u",     entry->maximumCacheSize2.value));
                COMMON_LVVV(("entry->maximumCacheSize2.granularity = %s",     enumToFullString((DmiCacheSizeGranularity)entry->maximumCacheSize2.granularity)));
                COMMON_LVVV(("entry->maximumCacheSize2.value32     = 0x%08X", entry->maximumCacheSize2.value32));
                COMMON_LVVV(("entry->maximumCacheSize2             = %s",     bytesToString(entry->maximumCacheSize2.size())));
                COMMON_LVVV(("entry->installedSize2.value          = %u",     entry->installedSize2.value));
                COMMON_LVVV(("entry->installedSize2.granularity    = %s",     enumToFullString((DmiCacheSizeGranularity)entry->installedSize2.granularity)));
                COMMON_LVVV(("entry->installedSize2.value32        = 0x%08X", entry->installedSize2.value32));
                COMMON_LVVV(("entry->installedSize2                = %s",     bytesToString(entry->installedSize2.size())));
            }
        }



        // COMMON_TEST_ASSERT(entry->socketDesignationStringId          == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->cacheConfiguration.level           == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->cacheConfiguration.socketed        == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->cacheConfiguration.location        == DmiCacheLocation::UNKNOWN,                      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->cacheConfiguration.enabled         == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->cacheConfiguration.operationalMode == DmiCacheOperationalMode::UNKNOWN,               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->cacheConfiguration.value16         == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumCacheSize.value             == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumCacheSize.granularity       == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumCacheSize.value16           == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->installedSize.value                == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->installedSize.granularity          == 0,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->installedSize.value16              == 0x0000,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->supportedSramType                  == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->currentSramType                    == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 1))
        {
            // COMMON_TEST_ASSERT(entry->cacheSpeed          == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->errorCorrectionType == DmiCacheErrorCorrectionType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->systemCacheType     == DmiCacheType::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->associativity       == DmiCacheAssociativity::OTHER,       NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(3, 1))
            {
                // COMMON_TEST_ASSERT(entry->maximumCacheSize2.value       == 1,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->maximumCacheSize2.granularity == 1,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->maximumCacheSize2.value32     == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->installedSize2.value          == 1,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->installedSize2.granularity    == 1,          NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->installedSize2.value32        == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation

                COMMON_TEST_ASSERT(entry->header.length >= 27,                    NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry), NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 19,                        NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry) - 8, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 15,                         NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCacheEntry) - 12, NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->socketDesignationStringId)
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (!cur[1]) // cur[1] == 0
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
        COMMON_LVVV(("entry->internalReferenceDesignatorStringId = %u", entry->internalReferenceDesignatorStringId));
        COMMON_LVVV(("entry->internalConnectorType               = %s", enumToFullString(entry->internalConnectorType)));
        COMMON_LVVV(("entry->externalReferenceDesignatorStringId = %u", entry->externalReferenceDesignatorStringId));
        COMMON_LVVV(("entry->externalConnectorType               = %s", enumToFullString(entry->externalConnectorType)));
        COMMON_LVVV(("entry->portType                            = %s", enumToFullString(entry->portType)));



        // COMMON_TEST_ASSERT(entry->internalReferenceDesignatorStringId == 1,                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->internalConnectorType               == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->externalReferenceDesignatorStringId == 2,                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->externalConnectorType               == DmiPortConnectorType::OTHER,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->portType                            == DmiPortConnectorPortType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 9,                             NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPortConnectorEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (
            entry->internalReferenceDesignatorStringId
            ||
            entry->externalReferenceDesignatorStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (!cur[1]) // cur[1] == 0
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



    // Validation
    {
        COMMON_LVVV(("entry->slotDesignationStringId = %u",     entry->slotDesignationStringId));
        COMMON_LVVV(("entry->slotType                = %s",     enumToFullString(entry->slotType)));
        COMMON_LVVV(("entry->slotDataBusWidth        = %s",     enumToFullString(entry->slotDataBusWidth)));
        COMMON_LVVV(("entry->currentUsage            = %s",     enumToFullString(entry->currentUsage)));
        COMMON_LVVV(("entry->slotLength              = %s",     enumToFullString(entry->slotLength)));
        COMMON_LVVV(("entry->slotID                  = 0x%04X", entry->slotID));
        COMMON_LVVV(("entry->slotCharacteristics     = %s",     flagsToFullString(entry->slotCharacteristics)));

        if (DMI::getVersion() >= DMI_VERSION(2, 6))
        {
            COMMON_LVVV(("entry->segmentGroupNumber            = %u",     entry->segmentGroupNumber));
            COMMON_LVVV(("entry->busNumber                     = %u",     entry->busNumber));
            COMMON_LVVV(("entry->functionNumber                = %u",     entry->functionNumber));
            COMMON_LVVV(("entry->deviceNumber                  = %u",     entry->deviceNumber));
            COMMON_LVVV(("entry->functionNumberAndDeviceNumber = 0x%02X", entry->functionNumberAndDeviceNumber));

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                COMMON_LVVV(("entry->dataBusWidth      = %u", entry->dataBusWidth));
                COMMON_LVVV(("entry->peerGroupingCount = %u", entry->peerGroupingCount));

                for (i64 i = 0; i < entry->peerGroupingCount; ++i)
                {
                    COMMON_LVVV(("entry->peerGroups[%d].segmentGroupNumber            = %u",     i, entry->peerGroups[i].segmentGroupNumber));
                    COMMON_LVVV(("entry->peerGroups[%d].busNumber                     = %u",     i, entry->peerGroups[i].busNumber));
                    COMMON_LVVV(("entry->peerGroups[%d].functionNumber                = %u",     i, entry->peerGroups[i].functionNumber));
                    COMMON_LVVV(("entry->peerGroups[%d].deviceNumber                  = %u",     i, entry->peerGroups[i].deviceNumber));
                    COMMON_LVVV(("entry->peerGroups[%d].functionNumberAndDeviceNumber = 0x%02X", i, entry->peerGroups[i].functionNumberAndDeviceNumber));
                    COMMON_LVVV(("entry->peerGroups[%d].dataBusWidth                  = %u",     i, entry->peerGroups[i].dataBusWidth));
                }
            }
        }



        // COMMON_TEST_ASSERT(entry->slotDesignationStringId == 1,                                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->slotType                == DmiSystemSlotsType::UNKNOWN,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->slotDataBusWidth        == DmiSystemSlotsDataBusWidth::UNKNOWN,            NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->currentUsage            == DmiSystemSlotsUsage::AVAILABLE,                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->slotLength              == DmiSystemSlotsLength::UNKNOWN,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->slotID                  == 0x0001,                                         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->slotCharacteristics     == FLAGS(DmiSystemSlotsCharacteristicsFlag::NONE), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 6))
        {
            // COMMON_TEST_ASSERT(entry->segmentGroupNumber            == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->busNumber                     == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->functionNumber                == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->deviceNumber                  == 1,    NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->functionNumberAndDeviceNumber == 0x00, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                // COMMON_TEST_ASSERT(entry->dataBusWidth                                == 0,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->peerGroupingCount                           == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->peerGroups[0].segmentGroupNumber            == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->peerGroups[0].busNumber                     == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->peerGroups[0].functionNumber                == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->peerGroups[0].deviceNumber                  == 1,    NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->peerGroups[0].functionNumberAndDeviceNumber == 0x00, NgosStatus::ASSERTION); // Commented due to value variation
                // COMMON_TEST_ASSERT(entry->peerGroups[0].dataBusWidth                  == 0,    NgosStatus::ASSERTION); // Commented due to value variation

                COMMON_TEST_ASSERT(entry->header.length >= 19 + entry->peerGroupingCount * 5,                          NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry) + entry->peerGroupingCount * 5, NgosStatus::ASSERTION);
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 17,                              NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry) - 2, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 13,                              NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemSlotsEntry) - 6, NgosStatus::ASSERTION);
        }
    }



    // Get strings
    {
        if (entry->slotDesignationStringId)
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (!cur[1]) // cur[1] == 0
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



    u8 count = (entry->header.length - sizeof(entry->header)) / sizeof(entry->device[0]);

    // Validation
    {
        for (i64 i = 0; i < count; ++i)
        {
            COMMON_LVVV(("entry->device[%d].deviceType           = %s",     i, enumToFullString((DmiOnboardDevicesDeviceType)entry->device[i].deviceType)));
            COMMON_LVVV(("entry->device[%d].enabled              = %u",     i, entry->device[i].enabled));
            COMMON_LVVV(("entry->device[%d].deviceTypeAndEnabled = 0x%02X", i, entry->device[i].deviceTypeAndEnabled));
            COMMON_LVVV(("entry->device[%d].descriptionStringId  = %u",     i, entry->device[i].descriptionStringId));
        }



        COMMON_TEST_ASSERT(count                                                       >  0,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT((DmiOnboardDevicesDeviceType)entry->device[0].deviceType == DmiOnboardDevicesDeviceType::UNKNOWN, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->device[0].enabled                                 == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->device[0].deviceTypeAndEnabled                    == 0x00,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->device[0].descriptionStringId                     == 1,                                    NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 6,                                                                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesEntry) + sizeof(DmiOnboardDevicesDevice), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (
            count > 0
            &&
            entry->device[0].descriptionStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (!cur[1]) // cur[1] == 0
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
        COMMON_LVVV(("entry->stringCount = %u", entry->stringCount));



        // COMMON_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 5,                          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOemStringsEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (entry->stringCount > 0)
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (!cur[1]) // cur[1] == 0
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);



            COMMON_TEST_ASSERT(stringId == entry->stringCount, NgosStatus::ASSERTION);
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
        COMMON_LVVV(("entry->stringCount = %u", entry->stringCount));



        // COMMON_TEST_ASSERT(entry->stringCount == 1, NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 5,                                   NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemConfigurationEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (entry->stringCount > 0)
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (!cur[1]) // cur[1] == 0
                    {
                        break;
                    }

                    begin = cur + 1;
                }



                ++cur;
            } while(true);



            COMMON_TEST_ASSERT(stringId == entry->stringCount, NgosStatus::ASSERTION);
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
        COMMON_LVVV(("entry->installableLanguages    = %u", entry->installableLanguages));
        COMMON_LVVV(("entry->flags                   = %s", flagsToFullString(entry->flags)));
        COMMON_LVVV(("entry->currentLanguageStringId = %u", entry->currentLanguageStringId));



        // COMMON_TEST_ASSERT(entry->installableLanguages    == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->flags                   == FLAGS(DmiBiosLanguageFlags::NONE), NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->currentLanguageStringId == 1,                                 NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 22,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiBiosLanguageEntry), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (
            entry->installableLanguages
            ||
            entry->currentLanguageStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (!cur[1]) // cur[1] == 0
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



    u8 count = (entry->header.length - sizeof(entry->header) - sizeof(entry->groupNameStringId)) / sizeof(entry->group[0]);

    // Validation
    {
        COMMON_LVVV(("entry->groupNameStringId = %u", entry->groupNameStringId));

        for (i64 i = 0; i < count; ++i)
        {
            COMMON_LVVV(("entry->group[%d].type   = %s",     i, enumToFullString(entry->group[i].type)));
            COMMON_LVVV(("entry->group[%d].handle = 0x%04X", i, entry->group[i].handle));
        }



        // COMMON_TEST_ASSERT(entry->groupNameStringId == 1,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->group[0].type     == DmiEntryType::BIOS, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->group[0].handle   == 0x0000,             NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 8,                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiGroupAssociationsEntry) + sizeof(DmiGroupAssociationsGroup), NgosStatus::ASSERTION);
    }



    // Get strings
    {
        if (entry->groupNameStringId)
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (!cur[1]) // cur[1] == 0
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



    AVOID_UNUSED(entry);



    // Validation
    {
        COMMON_LVVV(("entry->location                     = %s",     enumToFullString(entry->location)));
        COMMON_LVVV(("entry->use                          = %s",     enumToFullString(entry->use)));
        COMMON_LVVV(("entry->memoryErrorCorrection        = %s",     enumToFullString(entry->memoryErrorCorrection)));
        COMMON_LVVV(("entry->maximumCapacity              = 0x%08X", entry->maximumCapacity));
        COMMON_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
        COMMON_LVVV(("entry->numberOfMemoryDevices        = %u",     entry->numberOfMemoryDevices));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            COMMON_LVVV(("entry->extendedMaximumCapacity = 0x%016lX", entry->extendedMaximumCapacity));
        }



        // COMMON_TEST_ASSERT(entry->location                     == DmiPhysicalMemoryArrayLocation::OTHER,                NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->use                          == DmiPhysicalMemoryArrayUse::SYSTEM_MEMORY,             NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryErrorCorrection        == DmiPhysicalMemoryArrayErrorCorrection::MULTI_BIT_ECC, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumCapacity              == 0x00100000,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->numberOfMemoryDevices        == 1,                                                    NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
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

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            COMMON_LVVV(("entry->extendedStartingAddress = 0x%016lX", entry->extendedStartingAddress));
            COMMON_LVVV(("entry->extendedEndingAddress   = 0x%016lX", entry->extendedEndingAddress));
        }



        // COMMON_TEST_ASSERT(entry->startingAddress   == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->endingAddress     == 0x000FFFFF, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryArrayHandle == 0x1000,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->partitionWidth    == 1,          NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
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

NgosStatus DMI::saveDmiMemoryDeviceMappedAddressEntry(DmiMemoryDeviceMappedAddressEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        COMMON_LVVV(("entry->startingAddress                = 0x%08X", entry->startingAddress));
        COMMON_LVVV(("entry->endingAddress                  = 0x%08X", entry->endingAddress));
        COMMON_LVVV(("entry->memoryDeviceHandle             = 0x%04X", entry->memoryDeviceHandle));
        COMMON_LVVV(("entry->memoryArrayMappedAddressHandle = 0x%04X", entry->memoryArrayMappedAddressHandle));
        COMMON_LVVV(("entry->partitionRowPosition           = %u",     entry->partitionRowPosition));
        COMMON_LVVV(("entry->interleavePosition             = %u",     entry->interleavePosition));
        COMMON_LVVV(("entry->interleavedDataDepth           = %u",     entry->interleavedDataDepth));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            COMMON_LVVV(("entry->extendedStartingAddress = 0x%016lX", entry->extendedStartingAddress));
            COMMON_LVVV(("entry->extendedEndingAddress   = 0x%016lX", entry->extendedEndingAddress));
        }



        // COMMON_TEST_ASSERT(entry->startingAddress                == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->endingAddress                  == 0x00000000, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryDeviceHandle             == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryArrayMappedAddressHandle == 0x0000,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->partitionRowPosition           == 1,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->interleavePosition             == 1,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->interleavedDataDepth           == 1,          NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // COMMON_TEST_ASSERT(entry->extendedStartingAddress == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->extendedEndingAddress   == 0x0000000000000000, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= 35,                                        NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntry), NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 19,                                             NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceMappedAddressEntry) - 16, NgosStatus::ASSERTION);
        }
    }



    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length]     == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(((u8 *)entry)[entry->header.length + 1] == 0, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiPortableBatteryEntry(DmiPortableBatteryEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->locationStringId            = %u",             entry->locationStringId));
        COMMON_LVVV(("entry->manufacturerStringId        = %u",             entry->manufacturerStringId));
        COMMON_LVVV(("entry->manufactureDateStringId     = %u",             entry->manufactureDateStringId));
        COMMON_LVVV(("entry->serialNumberStringId        = %u",             entry->serialNumberStringId));
        COMMON_LVVV(("entry->deviceNameStringId          = %u",             entry->deviceNameStringId));
        COMMON_LVVV(("entry->deviceChemistry             = %s",             enumToFullString(entry->deviceChemistry)));
        COMMON_LVVV(("entry->deviceCapacity              = %u",             entry->deviceCapacity));
        COMMON_LVVV(("entry->designVoltage               = %u",             entry->designVoltage));
        COMMON_LVVV(("entry->sbdsVersionNumberStringId   = %u",             entry->sbdsVersionNumberStringId));
        COMMON_LVVV(("entry->maximumErrorInBatteryData   = %u",             entry->maximumErrorInBatteryData));
        COMMON_LVVV(("entry->sbdsSerialNumber            = %u",             entry->sbdsSerialNumber));
        COMMON_LVVV(("entry->sbdsManufactureDate.date    = %u",             entry->sbdsManufactureDate.date));
        COMMON_LVVV(("entry->sbdsManufactureDate.month   = %u",             entry->sbdsManufactureDate.month));
        COMMON_LVVV(("entry->sbdsManufactureDate.year    = %u",             entry->sbdsManufactureDate.year));
        COMMON_LVVV(("entry->sbdsManufactureDate.value16 = 0x%04X",         entry->sbdsManufactureDate.value16));
        COMMON_LVVV(("entry->sbdsManufactureDate         = %04u-%02u-%02u", entry->sbdsManufactureDate.realYear(), entry->sbdsManufactureDate.month, entry->sbdsManufactureDate.date));
        COMMON_LVVV(("entry->sbdsDeviceChemistryStringId = %u",             entry->sbdsDeviceChemistryStringId));
        COMMON_LVVV(("entry->designCapacityMultiplier    = %u",             entry->designCapacityMultiplier));
        COMMON_LVVV(("entry->oemSpecific                 = 0x%08X",         entry->oemSpecific));



        // COMMON_TEST_ASSERT(entry->locationStringId            == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->manufacturerStringId        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->manufactureDateStringId     == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->serialNumberStringId        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceNameStringId          == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceChemistry             == DmiPortableBatteryDeviceChemistry::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceCapacity              == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->designVoltage               == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->sbdsVersionNumberStringId   == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumErrorInBatteryData   == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->sbdsSerialNumber            == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->sbdsManufactureDate.date    == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->sbdsManufactureDate.month   == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->sbdsManufactureDate.year    == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->sbdsManufactureDate.value16 == 0x0000,                                   NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->sbdsDeviceChemistryStringId == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->designCapacityMultiplier    == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->oemSpecific                 == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 26,                              NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiPortableBatteryEntry), NgosStatus::ASSERTION);
    }



    if (
        entry->locationStringId
        ||
        entry->manufacturerStringId
        ||
        entry->manufactureDateStringId
        ||
        entry->serialNumberStringId
        ||
        entry->deviceNameStringId
        ||
        entry->sbdsVersionNumberStringId
        ||
        entry->sbdsDeviceChemistryStringId
       )
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiVoltageProbeEntry(DmiVoltageProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->descriptionStringId = %u",     entry->descriptionStringId));
        COMMON_LVVV(("entry->location            = %s",     enumToFullString((DmiVoltageProbeLocation)entry->location)));
        COMMON_LVVV(("entry->status              = %s",     enumToFullString((DmiVoltageProbeStatus)entry->status)));
        COMMON_LVVV(("entry->locationAndStatus   = 0x%02X", entry->locationAndStatus));
        COMMON_LVVV(("entry->maximumValue        = %u",     entry->maximumValue));
        COMMON_LVVV(("entry->minimumValue        = %u",     entry->minimumValue));
        COMMON_LVVV(("entry->resolution          = %u",     entry->resolution));
        COMMON_LVVV(("entry->tolerance           = %u",     entry->tolerance));
        COMMON_LVVV(("entry->accuracy            = %u",     entry->accuracy));
        COMMON_LVVV(("entry->oemDefined          = 0x%08X", entry->oemDefined));
        COMMON_LVVV(("entry->nominalValue        = %u",     entry->nominalValue));



        // COMMON_TEST_ASSERT(entry->descriptionStringId == 1,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->location            == DmiVoltageProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->status              == DmiVoltageProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->locationAndStatus   == 0x00,                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumValue        == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->minimumValue        == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->resolution          == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->tolerance           == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->accuracy            == 0,                              NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->oemDefined          == 0x00000000,                     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->nominalValue        == 0,                              NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 22,                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiVoltageProbeEntry), NgosStatus::ASSERTION);
    }



    if (entry->descriptionStringId)
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiCoolingDeviceEntry(DmiCoolingDeviceEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->temperatureProbeHandle = 0x%04X", entry->temperatureProbeHandle));
        COMMON_LVVV(("entry->deviceType             = %s",     enumToFullString((DmiCoolingDeviceType)entry->deviceType)));
        COMMON_LVVV(("entry->status                 = %s",     enumToFullString((DmiCoolingDeviceStatus)entry->status)));
        COMMON_LVVV(("entry->deviceTypeAndStatus    = 0x%02X", entry->deviceTypeAndStatus));
        COMMON_LVVV(("entry->coolingUnitGroup       = %u",     entry->coolingUnitGroup));
        COMMON_LVVV(("entry->oemDefined             = 0x%08X", entry->oemDefined));
        COMMON_LVVV(("entry->nominalSpeed           = %u",     entry->nominalSpeed));

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            COMMON_LVVV(("entry->descriptionStringId = %u", entry->descriptionStringId));
        }



        // COMMON_TEST_ASSERT(entry->temperatureProbeHandle == 0x0000,                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceType             == DmiCoolingDeviceType::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->status                 == DmiCoolingDeviceStatus::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceTypeAndStatus    == 0x00,                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->coolingUnitGroup       == 0,                             NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->oemDefined             == 0x00000000,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->nominalSpeed           == 0,                             NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 7))
        {
            // COMMON_TEST_ASSERT(entry->descriptionStringId == 1, NgosStatus::ASSERTION); // Commented due to value variation

            COMMON_TEST_ASSERT(entry->header.length >= 15,                            NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry), NgosStatus::ASSERTION);
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 14,                                NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiCoolingDeviceEntry) - 1, NgosStatus::ASSERTION);
        }
    }



    if (
        DMI::getVersion() >= DMI_VERSION(2, 7)
        &&
        entry->descriptionStringId
       )
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiTemperatureProbeEntry(DmiTemperatureProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->descriptionStringId = %u",     entry->descriptionStringId));
        COMMON_LVVV(("entry->location            = %s",     enumToFullString((DmiTemperatureProbeLocation)entry->location)));
        COMMON_LVVV(("entry->status              = %s",     enumToFullString((DmiTemperatureProbeStatus)entry->status)));
        COMMON_LVVV(("entry->locationAndStatus   = 0x%02X", entry->locationAndStatus));
        COMMON_LVVV(("entry->maximumValue        = %u",     entry->maximumValue));
        COMMON_LVVV(("entry->minimumValue        = %u",     entry->minimumValue));
        COMMON_LVVV(("entry->resolution          = %u",     entry->resolution));
        COMMON_LVVV(("entry->tolerance           = %u",     entry->tolerance));
        COMMON_LVVV(("entry->accuracy            = %u",     entry->accuracy));
        COMMON_LVVV(("entry->oemDefined          = 0x%08X", entry->oemDefined));
        COMMON_LVVV(("entry->nominalValue        = %u",     entry->nominalValue));



        // COMMON_TEST_ASSERT(entry->descriptionStringId == 1,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->location            == DmiTemperatureProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->status              == DmiTemperatureProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->locationAndStatus   == 0x00,                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumValue        == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->minimumValue        == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->resolution          == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->tolerance           == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->accuracy            == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->oemDefined          == 0x00000000,                         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->nominalValue        == 0,                                  NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 22,                               NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiTemperatureProbeEntry), NgosStatus::ASSERTION);
    }



    if (entry->descriptionStringId)
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiElectricalCurrentProbeEntry(DmiElectricalCurrentProbeEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->descriptionStringId = %u",     entry->descriptionStringId));
        COMMON_LVVV(("entry->location            = %s",     enumToFullString((DmiElectricalCurrentProbeLocation)entry->location)));
        COMMON_LVVV(("entry->status              = %s",     enumToFullString((DmiElectricalCurrentProbeStatus)entry->status)));
        COMMON_LVVV(("entry->locationAndStatus   = 0x%02X", entry->locationAndStatus));
        COMMON_LVVV(("entry->maximumValue        = %u",     entry->maximumValue));
        COMMON_LVVV(("entry->minimumValue        = %u",     entry->minimumValue));
        COMMON_LVVV(("entry->resolution          = %u",     entry->resolution));
        COMMON_LVVV(("entry->tolerance           = %u",     entry->tolerance));
        COMMON_LVVV(("entry->accuracy            = %u",     entry->accuracy));
        COMMON_LVVV(("entry->oemDefined          = 0x%08X", entry->oemDefined));
        COMMON_LVVV(("entry->nominalValue        = %u",     entry->nominalValue));



        // COMMON_TEST_ASSERT(entry->descriptionStringId == 1,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->location            == DmiElectricalCurrentProbeLocation::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->status              == DmiElectricalCurrentProbeStatus::OTHER,   NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->locationAndStatus   == 0x00,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->maximumValue        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->minimumValue        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->resolution          == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->tolerance           == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->accuracy            == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->oemDefined          == 0x00000000,                               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->nominalValue        == 0,                                        NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 22,                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiElectricalCurrentProbeEntry), NgosStatus::ASSERTION);
    }



    if (entry->descriptionStringId)
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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

NgosStatus DMI::saveDmiManagementDeviceEntry(DmiManagementDeviceEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->descriptionStringId = %u",     entry->descriptionStringId));
        COMMON_LVVV(("entry->type                = %s",     enumToFullString(entry->type)));
        COMMON_LVVV(("entry->address             = 0x%08X", entry->address));
        COMMON_LVVV(("entry->addressType         = %s",     enumToFullString(entry->addressType)));



        // COMMON_TEST_ASSERT(entry->descriptionStringId == 1,                                     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->type                == DmiManagementDeviceType::OTHER,        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->address             == 0x00000000,                            NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->addressType         == DmiManagementDeviceAddressType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 11,                               NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceEntry), NgosStatus::ASSERTION);
    }



    if (entry->descriptionStringId)
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiManagementDeviceComponentEntry(DmiManagementDeviceComponentEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->descriptionStringId    = %u",     entry->descriptionStringId));
        COMMON_LVVV(("entry->managementDeviceHandle = 0x%04X", entry->managementDeviceHandle));
        COMMON_LVVV(("entry->componentHandle        = 0x%04X", entry->componentHandle));
        COMMON_LVVV(("entry->thresholdHandle        = 0x%04X", entry->thresholdHandle));



        // COMMON_TEST_ASSERT(entry->descriptionStringId    == 1,      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->managementDeviceHandle == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->componentHandle        == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->thresholdHandle        == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 11,                                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceComponentEntry), NgosStatus::ASSERTION);
    }



    if (entry->descriptionStringId)
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiManagementDeviceThresholdDataEntry(DmiManagementDeviceThresholdDataEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    AVOID_UNUSED(entry);



    // Validation
    {
        COMMON_LVVV(("entry->lowerThresholdNonCritical    = %u", entry->lowerThresholdNonCritical));
        COMMON_LVVV(("entry->upperThresholdNonCritical    = %u", entry->upperThresholdNonCritical));
        COMMON_LVVV(("entry->lowerThresholdCritical       = %u", entry->lowerThresholdCritical));
        COMMON_LVVV(("entry->upperThresholdCritical       = %u", entry->upperThresholdCritical));
        COMMON_LVVV(("entry->lowerThresholdNonRecoverable = %u", entry->lowerThresholdNonRecoverable));
        COMMON_LVVV(("entry->upperThresholdNonRecoverable = %u", entry->upperThresholdNonRecoverable));

        // COMMON_TEST_ASSERT(entry->lowerThresholdNonCritical    == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->upperThresholdNonCritical    == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->lowerThresholdCritical       == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->upperThresholdCritical       == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->lowerThresholdNonRecoverable == 0, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->upperThresholdNonRecoverable == 0, NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 16,                                            NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiManagementDeviceThresholdDataEntry), NgosStatus::ASSERTION);
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
        COMMON_LVVV(("entry->powerUnitGroup                                     = %u",     entry->powerUnitGroup));
        COMMON_LVVV(("entry->locationStringId                                   = %u",     entry->locationStringId));
        COMMON_LVVV(("entry->deviceNameStringId                                 = %u",     entry->deviceNameStringId));
        COMMON_LVVV(("entry->manufacturerStringId                               = %u",     entry->manufacturerStringId));
        COMMON_LVVV(("entry->serialNumberStringId                               = %u",     entry->serialNumberStringId));
        COMMON_LVVV(("entry->assetTagNumberStringId                             = %u",     entry->assetTagNumberStringId));
        COMMON_LVVV(("entry->modelPartNumberStringId                            = %u",     entry->modelPartNumberStringId));
        COMMON_LVVV(("entry->revisionLevelStringId                              = %u",     entry->revisionLevelStringId));
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



        // COMMON_TEST_ASSERT(entry->powerUnitGroup                                     == 0,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->locationStringId                                   == 1,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceNameStringId                                 == 2,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->manufacturerStringId                               == 3,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->serialNumberStringId                               == 4,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->assetTagNumberStringId                             == 5,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->modelPartNumberStringId                            == 6,                                                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->revisionLevelStringId                              == 7,                                                  NgosStatus::ASSERTION); // Commented due to value variation
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

        COMMON_TEST_ASSERT(entry->header.length >= 22,                                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiSystemPowerSupplyEntry), NgosStatus::ASSERTION);
    }



    if (
        entry->locationStringId
        ||
        entry->deviceNameStringId
        ||
        entry->manufacturerStringId
        ||
        entry->serialNumberStringId
        ||
        entry->assetTagNumberStringId
        ||
        entry->modelPartNumberStringId
        ||
        entry->revisionLevelStringId
       )
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiAdditionalInformationEntry(DmiAdditionalInformationEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->numberOfAdditionalInformationEntries = %u", entry->numberOfAdditionalInformationEntries));



        DmiAdditionalInformation *curInfo = &entry->additionalInformationEntries[0];

        for (i64 i = 0; i < entry->numberOfAdditionalInformationEntries; ++i)
        {
            COMMON_LVVV(("curInfo->entryLength      = %u",     curInfo->entryLength));
            COMMON_LVVV(("curInfo->referencedHandle = 0x%04X", curInfo->referencedHandle));
            COMMON_LVVV(("curInfo->referencedOffset = %u",     curInfo->referencedOffset));
            COMMON_LVVV(("curInfo->stringStringId   = %u",     curInfo->stringStringId));
            COMMON_LVVV(("curInfo->value[0]         = %u",     curInfo->value[0]));

            curInfo = (DmiAdditionalInformation *)((u64)curInfo + curInfo->entryLength);
        }



        // COMMON_TEST_ASSERT(entry->numberOfAdditionalInformationEntries             == 1,      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].entryLength      == 6,      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].referencedHandle == 0x0000, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].referencedOffset == 1,      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].stringStringId   == 0,      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->additionalInformationEntries[0].value[0]         == 0,      NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 5,                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiAdditionalInformationEntry), NgosStatus::ASSERTION);
    }



    if (entry->numberOfAdditionalInformationEntries > 0)
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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



    return NgosStatus::OK;
}

NgosStatus DMI::saveDmiOnboardDevicesExtendedEntry(DmiOnboardDevicesExtendedEntry *entry)
{
    COMMON_LT((" | entry = 0x%p", entry));

    COMMON_ASSERT(entry, "entry is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("entry->referenceDesignationStringId  = %u",     entry->referenceDesignationStringId));
        COMMON_LVVV(("entry->deviceType                    = %s",     enumToFullString((DmiOnboardDevicesExtendedDeviceType)entry->deviceType)));
        COMMON_LVVV(("entry->enabled                       = %u",     entry->enabled));
        COMMON_LVVV(("entry->deviceTypeAndEnabled          = 0x%02X", entry->deviceTypeAndEnabled));
        COMMON_LVVV(("entry->deviceTypeInstance            = %u",     entry->deviceTypeInstance));
        COMMON_LVVV(("entry->segmentGroupNumber            = %u",     entry->segmentGroupNumber));
        COMMON_LVVV(("entry->busNumber                     = %u",     entry->busNumber));
        COMMON_LVVV(("entry->functionNumber                = %u",     entry->functionNumber));
        COMMON_LVVV(("entry->deviceNumber                  = %u",     entry->deviceNumber));
        COMMON_LVVV(("entry->functionNumberAndDeviceNumber = 0x%02X", entry->functionNumberAndDeviceNumber));



        // COMMON_TEST_ASSERT(entry->referenceDesignationStringId  == 1,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceType                    == DmiOnboardDevicesExtendedDeviceType::OTHER, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->enabled                       == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceTypeAndEnabled          == 0x00,                                       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceTypeInstance            == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->segmentGroupNumber            == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->busNumber                     == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->functionNumber                == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->deviceNumber                  == 0,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->functionNumberAndDeviceNumber == 0x00,                                       NgosStatus::ASSERTION); // Commented due to value variation

        COMMON_TEST_ASSERT(entry->header.length >= 11,                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiOnboardDevicesExtendedEntry), NgosStatus::ASSERTION);
    }



    if (entry->referenceDesignationStringId)
    {
        COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



        char8 *cur      = (char8 *)entry + entry->header.length;
        char8 *begin    = cur;
        u8     stringId = 0;

        AVOID_UNUSED(begin);

        do
        {
            if (!cur[0]) // cur[0] == 0
            {
                ++stringId;
                COMMON_LVVV(("String #%u: %s", stringId, begin));



                if (!cur[1]) // cur[1] == 0
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

        COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, saveDmiMemoryDeviceEntry), NgosStatus::ASSERTION);
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

NgosStatus DMI::saveDmiMemoryDeviceEntry(DmiEntryHeader *header)
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
        COMMON_LVVV(("entry->size.value                   = %u",     entry->size.value));
        COMMON_LVVV(("entry->size.granularity             = %s",     enumToFullString((DmiMemoryDeviceSizeGranularity)entry->size.granularity)));
        COMMON_LVVV(("entry->size.value16                 = 0x%04X", entry->size.value16));
        COMMON_LVVV(("entry->size                         = %s",     bytesToString(entry->size.size())));
        COMMON_LVVV(("entry->formFactor                   = %s",     enumToFullString(entry->formFactor)));
        COMMON_LVVV(("entry->deviceSet                    = %u",     entry->deviceSet));
        COMMON_LVVV(("entry->deviceLocatorStringId        = %u",     entry->deviceLocatorStringId));
        COMMON_LVVV(("entry->bankLocatorStringId          = %u",     entry->bankLocatorStringId));
        COMMON_LVVV(("entry->memoryType                   = %s",     enumToFullString(entry->memoryType)));
        COMMON_LVVV(("entry->typeDetail                   = %s",     flagsToFullString(entry->typeDetail)));

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            COMMON_LVVV(("entry->speed                = %u", entry->speed));
            COMMON_LVVV(("entry->manufacturerStringId = %u", entry->manufacturerStringId));
            COMMON_LVVV(("entry->serialNumberStringId = %u", entry->serialNumberStringId));
            COMMON_LVVV(("entry->assetTagStringId     = %u", entry->assetTagStringId));
            COMMON_LVVV(("entry->partNumberStringId   = %u", entry->partNumberStringId));

            if (DMI::getVersion() >= DMI_VERSION(2, 6))
            {
                COMMON_LVVV(("entry->attributes.rank   = %u",     entry->attributes.rank));
                COMMON_LVVV(("entry->attributes.value8 = 0x%02X", entry->attributes.value8));

                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    COMMON_LVVV(("entry->extendedSize          = %u", entry->extendedSize));
                    COMMON_LVVV(("entry->configuredMemorySpeed = %u", entry->configuredMemorySpeed));

                    if (DMI::getVersion() >= DMI_VERSION(2, 8))
                    {
                        COMMON_LVVV(("entry->minimumVoltage    = %u", entry->minimumVoltage));
                        COMMON_LVVV(("entry->maximumVoltage    = %u", entry->maximumVoltage));
                        COMMON_LVVV(("entry->configuredVoltage = %u", entry->configuredVoltage));

                        if (DMI::getVersion() >= DMI_VERSION(3, 2))
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

                            if (DMI::getVersion() >= DMI_VERSION(3, 3))
                            {
                                COMMON_LVVV(("entry->extendedSpeed                 = %u", entry->extendedSpeed));
                                COMMON_LVVV(("entry->extendedConfiguredMemorySpeed = %u", entry->extendedConfiguredMemorySpeed));
                            }
                        }
                    }
                }
            }
        }



        // COMMON_TEST_ASSERT(entry->memoryArrayHandle         == 0x1000,                                      NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE,                                      NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->totalWidth                == 64,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->dataWidth                 == 64,                                          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->size.value                == 1024,                                        NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->size.granularity          == DmiMemoryDeviceSizeGranularity::_1_MEGABYTE, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->size.value16              == 0x0400,                                      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->formFactor                == DmiMemoryDeviceFormFactor::DIMM,             NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->deviceSet                    == 0,                                           NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->deviceLocatorStringId        == 1,                                           NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->bankLocatorStringId       == 2,                                           NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->memoryType                == DmiMemoryDeviceType::RAM,                    NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->typeDetail                == FLAGS(DmiMemoryDeviceTypeDetailFlag::OTHER), NgosStatus::ASSERTION); // Commented due to value variation

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            // COMMON_TEST_ASSERT(entry->speed                == 0, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->manufacturerStringId == 3, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->serialNumberStringId == 4, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->assetTagStringId     == 5, NgosStatus::ASSERTION); // Commented due to value variation
            // COMMON_TEST_ASSERT(entry->partNumberStringId   == 6, NgosStatus::ASSERTION); // Commented due to value variation

            if (DMI::getVersion() >= DMI_VERSION(2, 6))
            {
                // COMMON_TEST_ASSERT(entry->attributes == 0, NgosStatus::ASSERTION); // Commented due to value variation

                if (DMI::getVersion() >= DMI_VERSION(2, 7))
                {
                    // COMMON_TEST_ASSERT(entry->extendedSize          == 0, NgosStatus::ASSERTION); // Commented due to value variation
                    // COMMON_TEST_ASSERT(entry->configuredMemorySpeed == 0, NgosStatus::ASSERTION); // Commented due to value variation

                    if (DMI::getVersion() >= DMI_VERSION(2, 8))
                    {
                        // COMMON_TEST_ASSERT(entry->minimumVoltage    == 0, NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entry->maximumVoltage    == 0, NgosStatus::ASSERTION); // Commented due to value variation
                        // COMMON_TEST_ASSERT(entry->configuredVoltage == 0, NgosStatus::ASSERTION); // Commented due to value variation

                        if (DMI::getVersion() >= DMI_VERSION(3, 2))
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

                            if (DMI::getVersion() >= DMI_VERSION(3, 3))
                            {
                                // COMMON_TEST_ASSERT(entry->extendedSpeed                 == 0, NgosStatus::ASSERTION); // Commented due to value variation
                                // COMMON_TEST_ASSERT(entry->extendedConfiguredMemorySpeed == 0, NgosStatus::ASSERTION); // Commented due to value variation

                                COMMON_TEST_ASSERT(entry->header.length >= 92,                           NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry), NgosStatus::ASSERTION);
                            }
                            else
                            {
                                COMMON_TEST_ASSERT(entry->header.length >= 84,                               NgosStatus::ASSERTION);
                                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 8, NgosStatus::ASSERTION);
                            }
                        }
                        else
                        {
                            COMMON_TEST_ASSERT(entry->header.length >= 40,                                NgosStatus::ASSERTION);
                            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 52, NgosStatus::ASSERTION);
                        }
                    }
                    else
                    {
                        COMMON_TEST_ASSERT(entry->header.length >= 34,                                NgosStatus::ASSERTION);
                        COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 58, NgosStatus::ASSERTION);
                    }
                }
                else
                {
                    COMMON_TEST_ASSERT(entry->header.length >= 33,                                NgosStatus::ASSERTION);
                    COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 59, NgosStatus::ASSERTION);
                }
            }
            else
            {
                COMMON_TEST_ASSERT(entry->header.length >= 27,                                NgosStatus::ASSERTION);
                COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 65, NgosStatus::ASSERTION);
            }
        }
        else
        {
            COMMON_TEST_ASSERT(entry->header.length >= 21,                                NgosStatus::ASSERTION);
            COMMON_TEST_ASSERT(entry->header.length >= sizeof(DmiMemoryDeviceEntry) - 71, NgosStatus::ASSERTION);
        }
    }



    static u64 memoryId;

    COMMON_TEST_ASSERT(memoryId < sNumberOfMemoryDevices, NgosStatus::ASSERTION);



    // Init memory device
    {
        sMemoryDevices[memoryId].handle = entry->header.handle;

        if (entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_NOT_INSTALLED)
        {
            sMemoryDevices[memoryId].size = 0;
        }
        else
        if (entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_UNKNOWN)
        {
            sMemoryDevices[memoryId].size = 0xFFFFFFFFFFFFFFFF;
        }
        else
        if (
            entry->size.value16 == DMI_MEMORY_DEVICE_SIZE_NEED_TO_EXTEND
            &&
            DMI::getVersion() >= DMI_VERSION(2, 7)
           )
        {
            sMemoryDevices[memoryId].size = (u64)entry->extendedSize << 20;
        }
        else
        {
            sMemoryDevices[memoryId].size = entry->size.size();
        }

        sMemoryDevices[memoryId].device          = nullptr;
        sMemoryDevices[memoryId].bank            = nullptr;
        sMemoryDevices[memoryId].manufacturer    = nullptr;
        sMemoryDevices[memoryId].serialNumber    = nullptr;
        sMemoryDevices[memoryId].assetTag        = nullptr;
        sMemoryDevices[memoryId].partNumber      = nullptr;
        sMemoryDevices[memoryId].firmwareVersion = nullptr;
    }



    // Get strings
    {
        u8 manufacturerStringId    = 0;
        u8 serialNumberStringId    = 0;
        u8 assetTagStringId        = 0;
        u8 partNumberStringId      = 0;
        u8 firmwareVersionStringId = 0;

        if (DMI::getVersion() >= DMI_VERSION(2, 3))
        {
            manufacturerStringId = entry->manufacturerStringId;
            serialNumberStringId = entry->serialNumberStringId;
            assetTagStringId     = entry->assetTagStringId;
            partNumberStringId   = entry->partNumberStringId;

            if (DMI::getVersion() >= DMI_VERSION(3, 2))
            {
                firmwareVersionStringId = entry->firmwareVersionStringId;
            }
        }



        if (
            entry->deviceLocatorStringId
            ||
            entry->bankLocatorStringId
            ||
            manufacturerStringId
            ||
            serialNumberStringId
            ||
            assetTagStringId
            ||
            partNumberStringId
            ||
            firmwareVersionStringId
           )
        {
            COMMON_TEST_ASSERT((((u8 *)entry)[entry->header.length] != 0) || (((u8 *)entry)[entry->header.length + 1] != 0), NgosStatus::ASSERTION);



            char8 *cur      = (char8 *)entry + entry->header.length;
            char8 *begin    = cur;
            u8     stringId = 0;

            AVOID_UNUSED(begin);

            do
            {
                if (!cur[0]) // cur[0] == 0
                {
                    ++stringId;
                    COMMON_LVVV(("String #%u: %s", stringId, begin));



                    if (stringId == entry->deviceLocatorStringId)
                    {
                        COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, &sMemoryDevices[memoryId].device), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == entry->bankLocatorStringId)
                    {
                        COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, &sMemoryDevices[memoryId].bank), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == manufacturerStringId)
                    {
                        COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, &sMemoryDevices[memoryId].manufacturer), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == serialNumberStringId)
                    {
                        COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, &sMemoryDevices[memoryId].serialNumber), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == assetTagStringId)
                    {
                        COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, &sMemoryDevices[memoryId].assetTag), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == partNumberStringId)
                    {
                        COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, &sMemoryDevices[memoryId].partNumber), NgosStatus::ASSERTION);
                    }
                    else
                    if (stringId == firmwareVersionStringId)
                    {
                        COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, &sMemoryDevices[memoryId].firmwareVersion), NgosStatus::ASSERTION);
                    }



                    if (!cur[1]) // cur[1] == 0
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



    ++memoryId;



    return NgosStatus::OK;
}

NgosStatus DMI::saveIdentity(DmiIdentity id, const char8 *address, u64 size)
{
    COMMON_LT((" | id = %u, address = 0x%p, size = %u", id, address, size));

    COMMON_ASSERT(address,  "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",    NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(sIdentities[(u64)id] == 0, NgosStatus::ASSERTION);

    COMMON_ASSERT_EXECUTION(getString(address, size, &sIdentities[(u64)id]), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::saveUuid(DmiStoredUuid id, Uuid *uuid)
{ // Ignore CppNgosTraceVerifier
    COMMON_LT((" | id = %u, uuid = %s", id, uuidToString(uuid)));



    COMMON_TEST_ASSERT(sUuids[(u64)id] == 0, NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sizeof(Uuid) == 16,   NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in Makefile
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

NgosStatus DMI::getString(const char8 *address, u64 size, const char8 **destination)
{
    COMMON_LT((" | address = 0x%p, size = %u, destination = 0x%p", address, size, destination));

    COMMON_ASSERT(address,     "address is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,    "size is zero",        NgosStatus::ASSERTION);
    COMMON_ASSERT(destination, "destination is null", NgosStatus::ASSERTION);



#ifdef UEFI_APPLICATION // Defined in Makefile
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
