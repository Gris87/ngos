// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E018_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E018_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E018: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11331800 = 0x11331800,
    SUBDEVICE_1133E018 = 0x1133E018
};



inline const char8* enumToString(PciSubDevice1133E018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E018::NONE:               return "NONE";
        case PciSubDevice1133E018::SUBDEVICE_11331800: return "SUBDEVICE_11331800";
        case PciSubDevice1133E018::SUBDEVICE_1133E018: return "SUBDEVICE_1133E018";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E018 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E018::SUBDEVICE_11331800: return "Diva V-BRI-2 PCI v2";
        case PciSubDevice1133E018::SUBDEVICE_1133E018: return "Diva BRI-2 PCI v2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E018_H
