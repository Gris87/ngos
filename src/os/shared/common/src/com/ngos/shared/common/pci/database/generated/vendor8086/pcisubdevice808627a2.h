// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808627A2: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C30A1 = 0x103C30A1,
    SUBDEVICE_103C30D5 = 0x103C30D5,
    SUBDEVICE_17AA201A = 0x17AA201A,
    SUBDEVICE_99021584 = 0x99021584
};



inline const char8* enumToString(PciSubDevice808627A2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627A2::NONE:               return "NONE";
        case PciSubDevice808627A2::SUBDEVICE_103C30A1: return "SUBDEVICE_103C30A1";
        case PciSubDevice808627A2::SUBDEVICE_103C30D5: return "SUBDEVICE_103C30D5";
        case PciSubDevice808627A2::SUBDEVICE_17AA201A: return "SUBDEVICE_17AA201A";
        case PciSubDevice808627A2::SUBDEVICE_99021584: return "SUBDEVICE_99021584";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808627A2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808627A2 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808627A2::SUBDEVICE_103C30A1: return "NC2400";
        case PciSubDevice808627A2::SUBDEVICE_103C30D5: return "530 Laptop";
        case PciSubDevice808627A2::SUBDEVICE_17AA201A: return "ThinkPad R60/T60/X60 series";
        case PciSubDevice808627A2::SUBDEVICE_99021584: return "CCE MPL-D10H120F";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808627A2_H
