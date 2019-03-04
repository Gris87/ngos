#include "dmi.h"

#include <common/src/bits64/log/assert.h>
#include <common/src/bits64/log/log.h>
#include <kernelbase/src/bits64/other/ioremap/ioremap.h>
#include <kernelbase/src/bits64/other/uefi/uefi.h>



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
        COMMON_LVVV(("smbios3->structureTableAddress       = %u",   smbios3->structureTableAddress));
    }



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
