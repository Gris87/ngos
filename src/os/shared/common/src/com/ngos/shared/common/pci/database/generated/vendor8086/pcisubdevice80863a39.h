// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A39_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A39_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863A39: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028028C = 0x1028028C,
    SUBDEVICE_1028028D = 0x1028028D,
    SUBDEVICE_103C330B = 0x103C330B,
    SUBDEVICE_104382D4 = 0x104382D4,
    SUBDEVICE_14585004 = 0x14585004
};



inline const char8* enumToString(PciSubDevice80863A39 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A39::NONE:               return "NONE";
        case PciSubDevice80863A39::SUBDEVICE_1028028C: return "SUBDEVICE_1028028C";
        case PciSubDevice80863A39::SUBDEVICE_1028028D: return "SUBDEVICE_1028028D";
        case PciSubDevice80863A39::SUBDEVICE_103C330B: return "SUBDEVICE_103C330B";
        case PciSubDevice80863A39::SUBDEVICE_104382D4: return "SUBDEVICE_104382D4";
        case PciSubDevice80863A39::SUBDEVICE_14585004: return "SUBDEVICE_14585004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863A39 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863A39 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A39::SUBDEVICE_1028028C: return "PowerEdge R410 USB UHCI Controller";
        case PciSubDevice80863A39::SUBDEVICE_1028028D: return "PowerEdge T410 USB UHCI Controller";
        case PciSubDevice80863A39::SUBDEVICE_103C330B: return "ProLiant ML150 G6 Server";
        case PciSubDevice80863A39::SUBDEVICE_104382D4: return "P5Q Deluxe Motherboard";
        case PciSubDevice80863A39::SUBDEVICE_14585004: return "Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A39_H
