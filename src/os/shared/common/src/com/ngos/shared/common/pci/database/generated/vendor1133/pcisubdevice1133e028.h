// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E028_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E028_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E028: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11332800 = 0x11332800,
    SUBDEVICE_1133E028 = 0x1133E028
};



inline const char8* enumToString(PciSubDevice1133E028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E028::NONE:               return "NONE";
        case PciSubDevice1133E028::SUBDEVICE_11332800: return "SUBDEVICE_11332800";
        case PciSubDevice1133E028::SUBDEVICE_1133E028: return "SUBDEVICE_1133E028";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E028 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E028::SUBDEVICE_11332800: return "Diva V-Analog-8 PCI v1";
        case PciSubDevice1133E028::SUBDEVICE_1133E028: return "Diva Analog-8 PCI v1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E028_H
