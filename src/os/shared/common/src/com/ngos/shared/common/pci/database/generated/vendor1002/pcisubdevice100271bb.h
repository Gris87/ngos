// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271BB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271BB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100271BB: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13CC3D13 = 0x13CC3D13,
    SUBDEVICE_13CC3D15 = 0x13CC3D15
};



inline const char8* enumToString(PciSubDevice100271BB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100271BB::NONE:               return "NONE";
        case PciSubDevice100271BB::SUBDEVICE_13CC3D13: return "SUBDEVICE_13CC3D13";
        case PciSubDevice100271BB::SUBDEVICE_13CC3D15: return "SUBDEVICE_13CC3D15";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100271BB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100271BB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100271BB::SUBDEVICE_13CC3D13: return "MXRT-1150 (Secondary)";
        case PciSubDevice100271BB::SUBDEVICE_13CC3D15: return "MXRT-2150 (Secondary)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271BB_H
