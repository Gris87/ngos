// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627C5: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_103C30D5 = 0x103C30D5,
    SUBDEVICE_17AA200D = 0x17AA200D
};



inline const char8* enumToString(PciSubDevice808627C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627C5::NONE:               return "NONE";
        case PciSubDevice808627C5::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice808627C5::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice808627C5::SUBDEVICE_103C30D5: return "SUBDEVICE_103C30D5";
        case PciSubDevice808627C5::SUBDEVICE_17AA200D: return "SUBDEVICE_17AA200D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627C5::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice808627C5::SUBDEVICE_103C30A3: return "Compaq nw8440";
        case PciSubDevice808627C5::SUBDEVICE_103C30D5: return "530 Laptop";
        case PciSubDevice808627C5::SUBDEVICE_17AA200D: return "ThinkPad R60/T60/X60 series";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627C5_H
