#include "dmi.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <common/src/bits64/memory/memory.h>
#include <kernelbase/src/bits64/other/brk/brk.h>
#include <kernelbase/src/bits64/other/ioremap/ioremap.h>
#include <kernelbase/src/bits64/other/uefi/uefi.h>



u32         DMI::sVersion;
u16         DMI::sNumberOfSmbiosStructures;
u32         DMI::sStructureTableLength;
u64         DMI::sStructureTableAddress;
const char* DMI::sIdentities[(u64)DmiIdentity::MAX];



NgosStatus DMI::init()
{
    COMMON_LT((""));



    UefiSmbios3ConfigurationTable *smbios3 = UEFI::sSmbios3Config;
    UefiSmbiosConfigurationTable  *smbios  = UEFI::sSmbiosConfig;



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



    COMMON_LV(("DMI: %s %s, BIOS %s %s %s", sIdentities[(u64)DmiIdentity::SYSTEM_MANUFACTURER], sIdentities[(u64)DmiIdentity::SYSTEM_PRODUCT_NAME], sIdentities[(u64)DmiIdentity::BIOS_VENDOR], sIdentities[(u64)DmiIdentity::BIOS_VERSION], sIdentities[(u64)DmiIdentity::BIOS_RELEASE_DATE]));



    // Validation
    {
        COMMON_LVVV(("sVersion                  = 0x%08X", sVersion));
        COMMON_LVVV(("sNumberOfSmbiosStructures = %u",     sNumberOfSmbiosStructures));
        COMMON_LVVV(("sStructureTableLength     = %u",     sStructureTableLength));
        COMMON_LVVV(("sStructureTableAddress    = 0x%p",   sStructureTableAddress));

#if NGOS_BUILD_COMMON_LOG_LEVEL == OPTION_LOG_LEVEL_INHERIT && NGOS_BUILD_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE || NGOS_BUILD_COMMON_LOG_LEVEL >= OPTION_LOG_LEVEL_VERY_VERY_VERBOSE
        {
            COMMON_LVVV(("sIdentities:"));
            COMMON_LVVV(("-------------------------------------"));

            for (i64 i = 0; i < (i64)DmiIdentity::MAX; ++i)
            {
                if (sIdentities[i])
                {
                    COMMON_LVVV(("#%-3d: 0x%p | %s", i, sIdentities[i], sIdentities[i]));
                }
                else
                {
                    COMMON_LVVV(("#%-3d: 0x%p", i, sIdentities[i]));
                }
            }

            COMMON_LVVV(("-------------------------------------"));
        }
#endif



        COMMON_TEST_ASSERT(sVersion                  == 0x00020800,         NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sNumberOfSmbiosStructures == 9,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sStructureTableLength     == 394,                NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sStructureTableAddress    == 0x000000003FBCB000, NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT((u64)DmiIdentity::MAX     == 9,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[0]            != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[1]            != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[2]            != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[3]            != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[4]            != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[5]            != 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[6]            == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[7]            == 0,                  NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(sIdentities[8]            == 0,                  NgosStatus::ASSERTION);
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



    COMMON_ASSERT_EXECUTION(iterateDmiEntries(decodeDmiEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::initFromSmbios(UefiSmbiosConfigurationTable *smbios)
{
    COMMON_LT((" | smbios = 0x%p", smbios));

    COMMON_ASSERT(smbios, "smbios is null", NgosStatus::ASSERTION);



    // Validation
    {
        COMMON_LVVV(("smbios->anchor                      = %.4s",   &smbios->anchor));
        COMMON_LVVV(("smbios->entryPointStructureChecksum = %u",     smbios->entryPointStructureChecksum));
        COMMON_LVVV(("smbios->entryPointLength            = %u",     smbios->entryPointLength));
        COMMON_LVVV(("smbios->majorVersion                = %u",     smbios->majorVersion));
        COMMON_LVVV(("smbios->minorVersion                = %u",     smbios->minorVersion));
        COMMON_LVVV(("smbios->maximumStructureSize        = %u",     smbios->maximumStructureSize));
        COMMON_LVVV(("smbios->entryPointRevision          = %u",     smbios->entryPointRevision));
        COMMON_LVVV(("smbios->formattedArea[0]            = %u",     smbios->formattedArea[0]));
        COMMON_LVVV(("smbios->formattedArea[1]            = %u",     smbios->formattedArea[1]));
        COMMON_LVVV(("smbios->formattedArea[2]            = %u",     smbios->formattedArea[2]));
        COMMON_LVVV(("smbios->formattedArea[3]            = %u",     smbios->formattedArea[3]));
        COMMON_LVVV(("smbios->formattedArea[4]            = %u",     smbios->formattedArea[4]));
        COMMON_LVVV(("smbios->intermediateAnchor          = %.5s",   smbios->intermediateAnchor));
        COMMON_LVVV(("smbios->intermediateChecksum        = %u",     smbios->intermediateChecksum));
        COMMON_LVVV(("smbios->structureTableLength        = %u",     smbios->structureTableLength));
        COMMON_LVVV(("smbios->structureTableAddress       = 0x%p",   smbios->structureTableAddress));
        COMMON_LVVV(("smbios->numberOfSmbiosStructures    = %u",     smbios->numberOfSmbiosStructures));
        COMMON_LVVV(("smbios->bcdRevision                 = 0x%02X", smbios->bcdRevision));



        COMMON_TEST_ASSERT(smbios->anchor                                        == SMBIOS_ANCHOR,                                                                         NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->entryPointStructureChecksum                   == checksum((u8 *)smbios, smbios->entryPointLength, smbios->entryPointStructureChecksum), NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->entryPointLength                              == 31,                                                                                    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->majorVersion                                  == 2,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->minorVersion                                  == 8,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->maximumStructureSize                          == 81,                                                                                    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->entryPointRevision                            == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[0]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[1]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[2]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[3]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->formattedArea[4]                              == 0,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT((*((u64 *)smbios->intermediateAnchor) & 0xFFFFFFFFFF) == SMBIOS_INTERMEDIATE_ANCHOR,                                                            NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->intermediateChecksum                          == checksum((u8 *)&smbios->intermediateAnchor, 15, smbios->intermediateChecksum),         NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->structureTableLength                          == 394,                                                                                   NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->structureTableAddress                         == 0x000000003FBCB000,                                                                    NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->numberOfSmbiosStructures                      == 9,                                                                                     NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(smbios->bcdRevision                                   == 0x28,                                                                                  NgosStatus::ASSERTION);
    }



    sVersion                  = (smbios->majorVersion << 16) + (smbios->minorVersion << 8);
    sNumberOfSmbiosStructures = smbios->numberOfSmbiosStructures;
    sStructureTableLength     = smbios->structureTableLength;
    sStructureTableAddress    = smbios->structureTableAddress;



    COMMON_ASSERT_EXECUTION(iterateDmiEntries(decodeDmiEntry), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::iterateDmiEntries(process_dmi_entry processDmiEntry)
{
    COMMON_LT((" | processDmiEntry = 0x%p", processDmiEntry));

    COMMON_ASSERT(processDmiEntry, "processDmiEntry is null", NgosStatus::ASSERTION);



    u8 *buf;

    COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping(sStructureTableAddress, sStructureTableLength, (void **)&buf), NgosStatus::ASSERTION);



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

        COMMON_LVVV(("dmiEntryHeader->type   = %u", dmiEntryHeader->type));
        COMMON_LVVV(("dmiEntryHeader->length = %u", dmiEntryHeader->length));
        COMMON_LVVV(("dmiEntryHeader->handle = %u", dmiEntryHeader->handle));



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



    COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)buf, sStructureTableLength), NgosStatus::ASSERTION);



    return NgosStatus::OK;
}

NgosStatus DMI::decodeDmiEntry(DmiEntryHeader *header)
{
    COMMON_LT((" | header = 0x%p", header));

    COMMON_ASSERT(header, "header is null", NgosStatus::ASSERTION);



    switch (header->type)
    {
        case DmiEntryType::BIOS:
        {
            COMMON_ASSERT_EXECUTION(saveDmiBiosEntry((DmiBiosEntry *)header), NgosStatus::ASSERTION);
        }
        break;

        case DmiEntryType::SYSTEM:
        {
            COMMON_ASSERT_EXECUTION(saveDmiSystemEntry((DmiSystemEntry *)header), NgosStatus::ASSERTION);
        }
        break;

        case DmiEntryType::BASEBOARD:
        {

        }
        break;

        case DmiEntryType::CHASSIS:
        {

        }
        break;

        case DmiEntryType::SYSTEM_SLOTS:
        {

        }
        break;

        case DmiEntryType::ONBOARD_DEVICES:
        {

        }
        break;

        case DmiEntryType::OEM_STRINGS:
        {

        }
        break;

        case DmiEntryType::IPMI_DEVICE:
        {

        }
        break;

        case DmiEntryType::ONBOARD_DEVICES_EXTENDED:
        {

        }
        break;

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
        COMMON_TEST_ASSERT(entry->serialNumber     == 0,          NgosStatus::ASSERTION);
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
        COMMON_TEST_ASSERT(entry->skuNumber        == 0,          NgosStatus::ASSERTION);
        COMMON_TEST_ASSERT(entry->family           == 0,          NgosStatus::ASSERTION);
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

NgosStatus DMI::saveIdentity(DmiIdentity identity, u8 *address, u64 size)
{
    COMMON_LT((" | identity = %u, address = 0x%p, size = %u", identity, address, size));

    COMMON_ASSERT(address,  "address is null", NgosStatus::ASSERTION);
    COMMON_ASSERT(size > 0, "size is zero",    NgosStatus::ASSERTION);



    COMMON_TEST_ASSERT(sIdentities[(u64)identity] == 0, NgosStatus::ASSERTION);



    u8 *brkAddress;

    COMMON_ASSERT_EXECUTION(BRK::allocate(size, 1, &brkAddress), NgosStatus::ASSERTION);
    memcpy(brkAddress, address, size);

    sIdentities[(u64)identity] = (const char *)brkAddress;



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
