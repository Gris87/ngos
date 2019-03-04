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

        COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)smbios3Mapped, sizeof(UefiSmbios3ConfigurationTable)), NgosStatus::ASSERTION);
    }
    else
    if (smbios)
    {
        UefiSmbiosConfigurationTable *smbiosMapped;

        COMMON_ASSERT_EXECUTION(IORemap::addFixedMapping((u64)smbios, sizeof(UefiSmbiosConfigurationTable), (void **)&smbiosMapped), NgosStatus::ASSERTION);

        COMMON_ASSERT_EXECUTION(IORemap::removeFixedMapping((u64)smbiosMapped, sizeof(UefiSmbiosConfigurationTable)), NgosStatus::ASSERTION);
    }
    else
    {
        COMMON_LF(("DMI not present"));

        return NgosStatus::NOT_FOUND;
    }



    return NgosStatus::OK;
}
