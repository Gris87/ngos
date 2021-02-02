// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDeviceDD010007: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_DD010023 = 0xDD010023
};



inline const char8* enumToString(PciSubDeviceDD010007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceDD010007::NONE:               return "NONE";
        case PciSubDeviceDD010007::SUBDEVICE_DD010023: return "SUBDEVICE_DD010023";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDeviceDD010007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDeviceDD010007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceDD010007::SUBDEVICE_DD010023: return "Max S8 4/8";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010007_H
