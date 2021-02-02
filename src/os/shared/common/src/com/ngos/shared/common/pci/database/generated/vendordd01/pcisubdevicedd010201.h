// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010201_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010201_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDeviceDD010201: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_DD010001 = 0xDD010001
};



inline const char8* enumToString(PciSubDeviceDD010201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceDD010201::NONE:               return "NONE";
        case PciSubDeviceDD010201::SUBDEVICE_DD010001: return "SUBDEVICE_DD010001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDeviceDD010201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDeviceDD010201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceDD010201::SUBDEVICE_DD010001: return "Resi DVB-C Modulator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010201_H
