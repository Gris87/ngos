// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11861002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11861002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11861002: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11861002 = 0x11861002,
    SUBDEVICE_11861012 = 0x11861012
};



inline const char8* enumToString(PciSubDevice11861002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11861002::NONE:               return "NONE";
        case PciSubDevice11861002::SUBDEVICE_11861002: return "SUBDEVICE_11861002";
        case PciSubDevice11861002::SUBDEVICE_11861012: return "SUBDEVICE_11861012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11861002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11861002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11861002::SUBDEVICE_11861002: return "DFE-550TX/FX";
        case PciSubDevice11861002::SUBDEVICE_11861012: return "DFE-580TX";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1186_PCISUBDEVICE11861002_H
