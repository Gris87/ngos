// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E024_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E024_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E024: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11332400 = 0x11332400,
    SUBDEVICE_1133E024 = 0x1133E024
};



inline const char8* enumToString(PciSubDevice1133E024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E024::NONE:               return "NONE";
        case PciSubDevice1133E024::SUBDEVICE_11332400: return "SUBDEVICE_11332400";
        case PciSubDevice1133E024::SUBDEVICE_1133E024: return "SUBDEVICE_1133E024";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E024::SUBDEVICE_11332400: return "Diva V-Analog-4 PCI v1";
        case PciSubDevice1133E024::SUBDEVICE_1133E024: return "Diva Analog-4 PCI v1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E024_H
