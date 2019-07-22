#include "dmi.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>
#include <kernelbase/src/bits64/other/brk/brk.h>
#include <kernelbase/src/bits64/other/dmi/entry/dmimemorydeviceentry.h>
#include <kernelbase/src/bits64/other/ioremap/ioremap.h>
#include <kernelbase/src/bits64/other/uefi/uefi.h>



u32              DMI::sVersion;
u16              DMI::sNumberOfSmbiosStructures;
u32              DMI::sStructureTableLength;
u64              DMI::sStructureTableAddress;
u8               DMI::sChassisType;
u64              DMI::sNumberOfMemoryDevices;
DmiMemoryDevice *DMI::sMemoryDevices;
const char*      DMI::sIdentities[(u64)DmiIdentity::MAXIMUM];
DmiUuid*         DMI::sUuids[(u64)DmiStoredUuid::MAXIMUM];



NgosStatus DMI::init()
{
    COMMON_LT((""));



    UefiSmbios3ConfigurationTable *smbios3 = UEFI::getSmbios3Config();
    UefiSmbiosConfigurationTable  *smbios  = UEFI::getSmbiosConfig();



    if (smbios3)
    {
        UefiSmbios3ConfigurationTable *smbios3Mapped;

        COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)smbios3, sizeof(UefiSmbios3ConfigurationTable), (void **)&smbios3Mapped), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(initFromSmbios3(smbios3Mapped),                                                                         NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)smbios3Mapped, sizeof(UefiSmbios3ConfigurationTable)),                 NgosStatus::ASSERTION);
    }
    else
    if (smbios)
    {
        UefiSmbiosConfigurationTable *smbiosMapped;

        COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)smbios, sizeof(UefiSmbiosConfigurationTable), (void **)&smbiosMapped), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(initFromSmbios(smbiosMapped),                                                                        NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)smbiosMapped, sizeof(UefiSmbiosConfigurationTable)),                NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_LF(("DMI not present"));

        return NgosStatus::NOT_FOUND;
    }



    u8 *buf;

    COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping(sStructureTableAddress, sStructureTableLength, (void **)&buf), NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, decodeDmiEntry),                                                 NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(storeDmiMemoryDevices(buf),                                                             NgosStatus::ASSERTION);
    COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)buf, sStructureTableLength),                           NgosStatus::ASSERTION);



    COMMON_LV(("SMBIOS version is %u.%u", sVersion >> 16, (sVersion >> 8) & 0xFF));
    COMMON_LV(("DMI: %s %s, BIOS %s %s %s", sIdentities[(u64)DmiIdentity::SYSTEM_MANUFACTURER], sIdentities[(u64)DmiIdentity::SYSTEM_PRODUCT_NAME], sIdentities[(u64)DmiIdentity::BIOS_VENDOR], sIdentities[(u64)DmiIdentity::BIOS_VERSION], sIdentities[(u64)DmiIdentity::BIOS_RELEASE_DATE]));



    // Validation
    {
        COMMON_LVVV(("sVersion                  = 0x%08X", sVersion));
        COMMON_LVVV(("sNumberOfSmbiosStructures = %u",     sNumberOfSmbiosStructures));
        COMMON_LVVV(("sStructureTableLength     = %u",     sStructureTableLength));
        COMMON_LVVV(("sStructureTableAddress    = 0x%p",   sStructureTableAddress));
        COMMON_LVVV(("sChassisType              = %u",     sChassisType));
        COMMON_LVVV(("sNumberOfMemoryDevices    = %u",     sNumberOfMemoryDevices));

#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            COMMON_LVVV(("sMemoryDevices:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)sNumberOfMemoryDevices; ++i)
            {
                const char *device;
                const char *bank;



                if (sMemoryDevices[i].device)
                {
                    device = sMemoryDevices[i].device;
                }
                else
                {
                    device = "null";
                }



                if (sMemoryDevices[i].bank)
                {
                    bank = sMemoryDevices[i].bank;
                }
                else
                {
                    bank = "null";
                }



                COMMON_LVVV(("#%-3d: 0x%04X | %s | %s | %u", i, sMemoryDevices[i].handle, device, bank, sMemoryDevices[i].size));
            }

            COMMON_LVVV(("-------------------------------------"));



            COMMON_LVVV(("sIdentities:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)DmiIdentity::MAXIMUM; ++i)
            {
                if (sIdentities[i])
                {
                    COMMON_LVVV(("#%-23s: 0x%p | %s", dmiIdentityToString((DmiIdentity)i), sIdentities[i], sIdentities[i]));
                }
                else
                {
                    COMMON_LVVV(("#%-23s: 0x%p", dmiIdentityToString((DmiIdentity)i), sIdentities[i]));
                }
            }

            COMMON_LVVV(("-------------------------------------"));



            COMMON_LVVV(("sUuids:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)DmiStoredUuid::MAXIMUM; ++i)
            {
                if (sUuids[i])
                {
                    COMMON_LVVV(("#%-11s: 0x%p | {%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", dmiStoredUuidToString((DmiStoredUuid)i), sUuids[i], sUuids[i]->data1, sUuids[i]->data2, sUuids[i]->data3, sUuids[i]->data4, sUuids[i]->data5, sUuids[i]->data6[0], sUuids[i]->data6[1], sUuids[i]->data6[2], sUuids[i]->data6[3], sUuids[i]->data6[4], sUuids[i]->data6[5]));
                }
                else
                {
                    COMMON_LVVV(("#%-11s: 0x%p", dmiStoredUuidToString((DmiStoredUuid)i), sUuids[i]));
                }
            }

            COMMON_LVVV(("-------------------------------------"));
        }
#endif



        COMMON_TEST_ASSERT(sVersion                     == 0x00020800,         NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sNumberOfSmbiosStructures == 9,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sStructureTableLength     == 394,                NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sStructureTableAddress       == 0x000000003FBCB000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sChassisType                 == 1,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sNumberOfMemoryDevices       == 1,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sMemoryDevices[0].handle     == 0x1100,             NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sMemoryDevices[0].device     != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sMemoryDevices[0].bank       == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sMemoryDevices[0].size       == 1073741824,         NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT((u64)DmiIdentity::MAXIMUM    == 18,                 NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[0]               != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[1]               != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[2]               != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[3]               != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[4]               != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[5]               != 0,                  NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sIdentities[6]            != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[7]            != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[8]            != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[9]            1= 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[10]           != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[11]           != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[12]           != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[13]           != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(sIdentities[14]              != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[15]              != 0,                  NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sIdentities[16]           != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sIdentities[17]           != 0,                  NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT((u64)DmiStoredUuid::MAXIMUM  == 1,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sUuids[0]                    != 0,                  NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(sUuids[0]->data1          == 0x9FAE0773,         NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data2          == 0xF53F,             NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data3          == 0x4A15,             NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data4          == 0x8A,               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data5          == 0x11,               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[0]       == 0xED,               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[1]       == 0x76,               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[2]       == 0xA1,               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[3]       == 0x0F,               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[4]       == 0x4E,               NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(sUuids[0]->data6[5]       == 0x5B,               NgosStatus::ASSERTION); // Commented due to value variation
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



        COMMON_TEST_ASSERT((*((u64 *)smbios3->anchor) & 0xFFFFFFFFFF) == SMBIOS_3_ANCHOR,                                                                          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->entryPointStructureChecksum       == checksum((u8 *)smbios3, smbios3->entryPointLength, smbios3->entryPointStructureChecksum), NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->entryPointLength                  == 24,                                                                                       NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->majorVersion                      == 0,                                                                                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->minorVersion                      == 0,                                                                                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->docRevision                       == 0,                                                                                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->entryPointRevision                == 0,                                                                                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->reserved                          == 0,                                                                                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->structureTableMaximumSize         == 0,                                                                                        NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios3->structureTableAddress             == 0,                                                                                        NgosStatus::ASSERTION);
    }



    sVersion               = (smbios3->majorVersion << 16) + (smbios3->minorVersion << 8) + smbios3->docRevision;
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



        COMMON_TEST_ASSERT(smbios->anchor                                        == SMBIOS_ANCHOR,                                                                         NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->entryPointStructureChecksum                   == checksum((u8 *)smbios, smbios->entryPointLength, smbios->entryPointStructureChecksum), NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->entryPointLength                              == 31,                                                                                    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->majorVersion                                  == 2,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->minorVersion                                  == 8,                                                                                     NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios->maximumStructureSize                       == 81,                                                                                    NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios->entryPointRevision                            == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[0]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[1]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[2]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[3]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[4]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT((*((u64 *)smbios->intermediateAnchor) & 0xFFFFFFFFFF) == SMBIOS_INTERMEDIATE_ANCHOR,                                                            NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->intermediateChecksum                          == checksum((u8 *)&smbios->intermediateAnchor, 15, smbios->intermediateChecksum),         NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios->structureTableLength                       == 394,                                                                                   NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios->structureTableAddress                         == 0x000000003FBCB000,                                                                    NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(smbios->numberOfSmbiosStructures                   == 9,                                                                                     NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(smbios->bcdRevision                                   == 0x28,                                                                                  NgosStatus::ASSERTION);
    }



    sVersion                  = (smbios->majorVersion << 16) + (smbios->minorVersion << 8);
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

        COMMON_LVVV(("dmiEntryHeader->type   = %u",     dmiEntryHeader->type));
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

    COMMON_TEST_ASSERT(sStructureTableLength == cur - buf,                           NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(!sNumberOfSmbiosStructures || i == sNumberOfSmbiosStructures, NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::decodeDmiEntry(DmiEntryHeader *header)
{
    COMMON_LT((" | header = 0x%p", header));

    COMMON_ASSERT(header, "header is null", NgosStatus::ASSERTION);



    switch (header->type)
    {
        case DmiEntryType::BIOS:                     COMMON_ASSERT_EXECUTION(saveDmiBiosEntry((DmiBiosEntry *)header),           NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM:                   COMMON_ASSERT_EXECUTION(saveDmiSystemEntry((DmiSystemEntry *)header),       NgosStatus::ASSERTION); break;
        case DmiEntryType::BASEBOARD:                COMMON_ASSERT_EXECUTION(saveDmiBaseboardEntry((DmiBaseboardEntry *)header), NgosStatus::ASSERTION); break;
        case DmiEntryType::CHASSIS:                  COMMON_ASSERT_EXECUTION(saveDmiChassisEntry((DmiChassisEntry *)header),     NgosStatus::ASSERTION); break;
        case DmiEntryType::SYSTEM_SLOTS:             return NgosStatus::NOT_SUPPORTED;
        case DmiEntryType::OEM_STRINGS:              return NgosStatus::NOT_SUPPORTED;
        case DmiEntryType::IPMI_DEVICE:              return NgosStatus::NOT_SUPPORTED;
        case DmiEntryType::ONBOARD_DEVICES_EXTENDED: return NgosStatus::NOT_SUPPORTED;

        default:
        {
            COMMON_LVV(("Ignoring DMI entry at address 0x%p with type %u", header, header->type));
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
        COMMON_LVVV(("entry->vendor                 = %u",       entry->vendor));
        COMMON_LVVV(("entry->version                = %u",       entry->version));
        COMMON_LVVV(("entry->startingAddressSegment = 0x%04X",   entry->startingAddressSegment));
        COMMON_LVVV(("entry->releaseDate            = %u",       entry->releaseDate));
        COMMON_LVVV(("entry->romSize                = %u",       entry->romSize));
        COMMON_LVVV(("entry->characteristics        = 0x%016lX", entry->characteristics));



        COMMON_TEST_ASSERT(entry->vendor                 == 1,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->version                == 2,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->startingAddressSegment == 0xE800,             NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->releaseDate            == 3,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->romSize                == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->characteristics        == 0x0000000000000008, NgosStatus::ASSERTION);
    }



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%d: %s", stringId, begin));



            if (stringId == entry->vendor)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BIOS_VENDOR, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->version)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BIOS_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->releaseDate)
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
        COMMON_LVVV(("entry->manufacturer = %u",                                                 entry->manufacturer));
        COMMON_LVVV(("entry->productName  = %u",                                                 entry->productName));
        COMMON_LVVV(("entry->version      = %u",                                                 entry->version));
        COMMON_LVVV(("entry->serialNumber = %u",                                                 entry->serialNumber));
        COMMON_LVVV(("entry->uuid         = {%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", entry->uuid.data1, entry->uuid.data2, entry->uuid.data3, entry->uuid.data4, entry->uuid.data5, entry->uuid.data6[0], entry->uuid.data6[1], entry->uuid.data6[2], entry->uuid.data6[3], entry->uuid.data6[4], entry->uuid.data6[5]));
        COMMON_LVVV(("entry->wakeUpTime   = %u",                                                 entry->wakeUpTime));
        COMMON_LVVV(("entry->skuNumber    = %u",                                                 entry->skuNumber));
        COMMON_LVVV(("entry->family       = %u",                                                 entry->family));



        COMMON_TEST_ASSERT(entry->manufacturer     == 1,          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->productName      == 2,          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->version          == 3,          NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->serialNumber  == 4,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data1    == 0x9FAE0773, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data2    == 0xF53F,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data3    == 0x4A15,     NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data4    == 0x8A,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data5    == 0x11,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[0] == 0xED,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[1] == 0x76,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[2] == 0xA1,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[3] == 0x0F,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[4] == 0x4E,       NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->uuid.data6[5] == 0x5B,       NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->wakeUpTime       == 6,          NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->skuNumber     == 5,          NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->family        == 6,          NgosStatus::ASSERTION); // Commented due to value variation
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
            COMMON_LVVV(("String #%d: %s", stringId, begin));



            if (stringId == entry->manufacturer)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->productName)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_PRODUCT_NAME, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->version)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->serialNumber)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_SERIAL_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->skuNumber)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::SYSTEM_SKU_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->family)
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
        COMMON_LVVV(("entry->manufacturer                   = %u",     entry->manufacturer));
        COMMON_LVVV(("entry->product                        = %u",     entry->product));
        COMMON_LVVV(("entry->version                        = %u",     entry->version));
        COMMON_LVVV(("entry->serialNumber                   = %u",     entry->serialNumber));
        COMMON_LVVV(("entry->assetTag                       = %u",     entry->assetTag));
        COMMON_LVVV(("entry->featureFlags                   = 0x%02X", entry->featureFlags));
        COMMON_LVVV(("entry->locationInChassis              = %u",     entry->locationInChassis));
        COMMON_LVVV(("entry->chassisHandle                  = 0x%04X", entry->chassisHandle));
        COMMON_LVVV(("entry->boardType                      = %u",     entry->boardType));
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



        COMMON_TEST_ASSERT(entry->manufacturer                   == 1,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->product                        == 2,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->version                        == 3,      NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->serialNumber                == 4,      NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->assetTag                    == 5,      NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->featureFlags                   == 0x01,   NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->locationInChassis              == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->chassisHandle                  == 0x0300, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->boardType                      == 10,     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->numberOfContainedObjectHandles == 0,      NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->containedObjectHandles[0]   == 0,      NgosStatus::ASSERTION); // Commented due to value variation
    }



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%d: %s", stringId, begin));



            if (stringId == entry->manufacturer)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->product)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_PRODUCT, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->version)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->serialNumber)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_SERIAL_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->assetTag)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::BASEBOARD_ASSET_TAG, begin, cur - begin + 1), NgosStatus::ASSERTION);
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



    // Validation
    {
        COMMON_LVVV(("entry->manufacturer                 = %u", entry->manufacturer));
        COMMON_LVVV(("entry->type                         = %u", entry->type));
        COMMON_LVVV(("entry->version                      = %u", entry->version));
        COMMON_LVVV(("entry->serialNumber                 = %u", entry->serialNumber));
        COMMON_LVVV(("entry->assetTag                     = %u", entry->assetTag));
        COMMON_LVVV(("entry->bootUpState                  = %u", entry->bootUpState));
        COMMON_LVVV(("entry->powerSupplyState             = %u", entry->powerSupplyState));
        COMMON_LVVV(("entry->thermalState                 = %u", entry->thermalState));
        COMMON_LVVV(("entry->securityStatus               = %u", entry->securityStatus));
        COMMON_LVVV(("entry->oemDefined                   = %u", entry->oemDefined));
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
                for (i64 j = 0; j < entry->containedElementRecordLength; ++j)
                {
                    COMMON_LVVV(("#%-3d -3d: %u", i, j, entry->containedElements[i * j]));
                }
            }

            COMMON_LVVV(("-------------------------------------"));
        }
#endif



        COMMON_TEST_ASSERT(entry->manufacturer                 == 1, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->type                         == 1, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->version                      == 2, NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->serialNumber              == 3, NgosStatus::ASSERTION); // Commented due to value variation
        // COMMON_TEST_ASSERT(entry->assetTag                  == 4, NgosStatus::ASSERTION); // Commented due to value variation
        COMMON_TEST_ASSERT(entry->bootUpState                  == 3, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->powerSupplyState             == 3, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->thermalState                 == 3, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->securityStatus               == 2, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->oemDefined                   == 0, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->height                       == 0, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->numberOfPowerCords           == 0, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->containedElementCount        == 0, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->containedElementRecordLength == 0, NgosStatus::ASSERTION);
        // COMMON_TEST_ASSERT(entry->containedElements[0]      == 0, NgosStatus::ASSERTION); // Commented due to value variation
    }



    sChassisType = entry->type;



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%d: %s", stringId, begin));



            if (stringId == entry->manufacturer)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_MANUFACTURER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->version)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_VERSION, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->serialNumber)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_SERIAL_NUMBER, begin, cur - begin + 1), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->assetTag)
            {
                COMMON_ASSERT_EXECUTION(saveIdentity(DmiIdentity::CHASSIS_ASSET_TAG, begin, cur - begin + 1), NgosStatus::ASSERTION);
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

NgosStatus DMI::storeDmiMemoryDevices(u8 *buf)
{
    COMMON_LT((" | buf = 0x%p", buf));

    COMMON_ASSERT(buf, "buf is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, countDmiMemoryDevices), NgosStatus::ASSERTION);

    if (sNumberOfMemoryDevices)
    {
        COMMON_LVV(("Found memory devices: %u", sNumberOfMemoryDevices));

        COMMON_ASSERT_EXECUTION(BRK::allocate(sNumberOfMemoryDevices * sizeof(DmiMemoryDevice), 1, (u8 **)&sMemoryDevices), NgosStatus::ASSERTION);
        COMMON_ASSERT_EXECUTION(iterateDmiEntries(buf, saveDmiMemoryDevice),                                                NgosStatus::ASSERTION);
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
        COMMON_LVVV(("entry->physicalMemoryArrayHandle    = 0x%04X", entry->physicalMemoryArrayHandle));
        COMMON_LVVV(("entry->memoryErrorInformationHandle = 0x%04X", entry->memoryErrorInformationHandle));
        COMMON_LVVV(("entry->totalWidth                   = %u",     entry->totalWidth));
        COMMON_LVVV(("entry->dataWidth                    = %u",     entry->dataWidth));
        COMMON_LVVV(("entry->size                         = %u",     entry->size));
        COMMON_LVVV(("entry->formFactor                   = %u",     entry->formFactor));
        COMMON_LVVV(("entry->deviceSet                    = %u",     entry->deviceSet));
        COMMON_LVVV(("entry->deviceLocator                = %u",     entry->deviceLocator));
        COMMON_LVVV(("entry->bankLocator                  = %u",     entry->bankLocator));
        COMMON_LVVV(("entry->memoryType                   = %u",     entry->memoryType));
        COMMON_LVVV(("entry->typeDetail                   = %u",     entry->typeDetail));
        COMMON_LVVV(("entry->speed                        = %u",     entry->speed));
        COMMON_LVVV(("entry->manufacturer                 = %u",     entry->manufacturer));
        COMMON_LVVV(("entry->serialNumber                 = %u",     entry->serialNumber));
        COMMON_LVVV(("entry->assetTag                     = %u",     entry->assetTag));
        COMMON_LVVV(("entry->partNumber                   = %u",     entry->partNumber));
        COMMON_LVVV(("entry->attributes                   = %u",     entry->attributes));
        COMMON_LVVV(("entry->extendedSize                 = %u",     entry->extendedSize));
        COMMON_LVVV(("entry->configuredMemorySpeed        = %u",     entry->configuredMemorySpeed));
        COMMON_LVVV(("entry->minimumVoltage               = %u",     entry->minimumVoltage));
        COMMON_LVVV(("entry->maximumVoltage               = %u",     entry->maximumVoltage));
        COMMON_LVVV(("entry->configuredVoltage            = %u",     entry->configuredVoltage));



        COMMON_TEST_ASSERT(entry->physicalMemoryArrayHandle    == 0x1000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->memoryErrorInformationHandle == 0xFFFE, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->totalWidth                   == 65535,  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->dataWidth                    == 65535,  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->size                         == 1024,   NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->formFactor                   == 9,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->deviceSet                    == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->deviceLocator                == 1,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->bankLocator                  == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->memoryType                   == 7,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->typeDetail                   == 2,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->speed                        == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->manufacturer                 == 2,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->serialNumber                 == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->assetTag                     == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->partNumber                   == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->attributes                   == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->extendedSize                 == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->configuredMemorySpeed        == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->minimumVoltage               == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->maximumVoltage               == 0,      NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->configuredVoltage            == 0,      NgosStatus::ASSERTION);
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



    u8 *cur      = (u8 *)entry + entry->header.length;
    u8 *begin    = cur;
    u8  stringId = 0;

    do
    {
        if (!cur[0]) // cur[0] == 0
        {
            ++stringId;
            COMMON_LVVV(("String #%d: %s", stringId, begin));



            if (stringId == entry->deviceLocator)
            {
                COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].device), NgosStatus::ASSERTION);
            }
            else
            if (stringId == entry->bankLocator)
            {
                COMMON_ASSERT_EXECUTION(getString(begin, cur - begin + 1, (u8 **)&sMemoryDevices[memoryId].bank), NgosStatus::ASSERTION);
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

NgosStatus DMI::saveUuid(DmiStoredUuid id, const DmiUuid &uuid)
{ // Ignore CppNgosTraceVerifier
    COMMON_LT((" | id = %u, uuid = {%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X}", id, uuid.data1, uuid.data2, uuid.data3, uuid.data4, uuid.data5, uuid.data6[0], uuid.data6[1], uuid.data6[2], uuid.data6[3], uuid.data6[4], uuid.data6[5]));



    COMMON_TEST_ASSERT(sUuids[(u64)id] == 0,  NgosStatus::ASSERTION);
    COMMON_TEST_ASSERT(sizeof(DmiUuid) == 16, NgosStatus::ASSERTION);



    u8 *brkAddress;

    COMMON_ASSERT_EXECUTION(BRK::allocate(sizeof(DmiUuid), 1, &brkAddress), NgosStatus::ASSERTION);
    ((u64 *)brkAddress)[0] = ((u64 *)&uuid)[0];
    ((u64 *)brkAddress)[1] = ((u64 *)&uuid)[1];

    sUuids[(u64)id] = (DmiUuid *)brkAddress;



    return NgosStatus::OK;
}

NgosStatus DMI::getString(u8 *address, u64 size, u8 **destination)
{
    COMMON_LT((" | address = 0x%p, size = %u, destination = 0x%p", address, size, destination));

    COMMON_ASSERT(address,     "address is null",     NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0,    "size is zero",        NgosStatus::ASSERTION);
    COMMON_ASSERT(destination, "destination is null", NgosStatus::ASSERTION);



    COMMON_ASSERT_EXECUTION(BRK::allocate(size, 1, destination), NgosStatus::ASSERTION);
    memcpy(*destination, address, size);



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
