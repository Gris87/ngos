// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A3C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A3C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863A3C: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028028C = 0x1028028C,
    SUBDEVICE_1028028D = 0x1028028D,
    SUBDEVICE_103C330B = 0x103C330B,
    SUBDEVICE_104382D4 = 0x104382D4,
    SUBDEVICE_14585006 = 0x14585006
};



inline const char8* enumToString(PciSubDevice80863A3C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A3C::NONE:               return "NONE";
        case PciSubDevice80863A3C::SUBDEVICE_1028028C: return "SUBDEVICE_1028028C";
        case PciSubDevice80863A3C::SUBDEVICE_1028028D: return "SUBDEVICE_1028028D";
        case PciSubDevice80863A3C::SUBDEVICE_103C330B: return "SUBDEVICE_103C330B";
        case PciSubDevice80863A3C::SUBDEVICE_104382D4: return "SUBDEVICE_104382D4";
        case PciSubDevice80863A3C::SUBDEVICE_14585006: return "SUBDEVICE_14585006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863A3C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863A3C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A3C::SUBDEVICE_1028028C: return "PowerEdge R410 USB EHCI Controller";
        case PciSubDevice80863A3C::SUBDEVICE_1028028D: return "PowerEdge T410 USB EHCI Controller";
        case PciSubDevice80863A3C::SUBDEVICE_103C330B: return "ProLiant G6 series";
        case PciSubDevice80863A3C::SUBDEVICE_104382D4: return "P5Q Deluxe Motherboard";
        case PciSubDevice80863A3C::SUBDEVICE_14585006: return "Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A3C_H
