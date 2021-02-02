// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271C5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271C5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100271C5: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_104310B2 = 0x104310B2,
    SUBDEVICE_106B0080 = 0x106B0080
};



inline const char8* enumToString(PciSubDevice100271C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100271C5::NONE:               return "NONE";
        case PciSubDevice100271C5::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice100271C5::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice100271C5::SUBDEVICE_104310B2: return "SUBDEVICE_104310B2";
        case PciSubDevice100271C5::SUBDEVICE_106B0080: return "SUBDEVICE_106B0080";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100271C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100271C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100271C5::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice100271C5::SUBDEVICE_103C30A3: return "Compaq NW8440";
        case PciSubDevice100271C5::SUBDEVICE_104310B2: return "A6J-Q008";
        case PciSubDevice100271C5::SUBDEVICE_106B0080: return "MacBook Pro";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100271C5_H
