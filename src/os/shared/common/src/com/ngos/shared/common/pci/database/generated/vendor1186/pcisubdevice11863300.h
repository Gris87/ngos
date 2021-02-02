// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11863300_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11863300_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11863300: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11863300 = 0x11863300,
    SUBDEVICE_11863301 = 0x11863301
};



inline const char8* enumToString(PciSubDevice11863300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11863300::NONE:               return "NONE";
        case PciSubDevice11863300::SUBDEVICE_11863300: return "SUBDEVICE_11863300";
        case PciSubDevice11863300::SUBDEVICE_11863301: return "SUBDEVICE_11863301";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11863300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11863300 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11863300::SUBDEVICE_11863300: return "DWL-610 Wireless Cardbus Adapter";
        case PciSubDevice11863300::SUBDEVICE_11863301: return "DWL-510 Wireless PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11863300_H
