// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B051A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B0100 = 0x102B0100,
    SUBDEVICE_102B051A = 0x102B051A,
    SUBDEVICE_102B1100 = 0x102B1100,
    SUBDEVICE_102B1200 = 0x102B1200,
    SUBDEVICE_1100102B = 0x1100102B,
    SUBDEVICE_110A0018 = 0x110A0018
};



inline const char8* enumToString(PciSubDevice102B051A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B051A::NONE:               return "NONE";
        case PciSubDevice102B051A::SUBDEVICE_102B0100: return "SUBDEVICE_102B0100";
        case PciSubDevice102B051A::SUBDEVICE_102B051A: return "SUBDEVICE_102B051A";
        case PciSubDevice102B051A::SUBDEVICE_102B1100: return "SUBDEVICE_102B1100";
        case PciSubDevice102B051A::SUBDEVICE_102B1200: return "SUBDEVICE_102B1200";
        case PciSubDevice102B051A::SUBDEVICE_1100102B: return "SUBDEVICE_1100102B";
        case PciSubDevice102B051A::SUBDEVICE_110A0018: return "SUBDEVICE_110A0018";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B051A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B051A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B051A::SUBDEVICE_102B0100: return "MGA-1064SG Mystique";
        case PciSubDevice102B051A::SUBDEVICE_102B051A: return "MGA-1164SG Mystique 220";
        case PciSubDevice102B051A::SUBDEVICE_102B1100: return "MGA-1084SG Mystique";
        case PciSubDevice102B051A::SUBDEVICE_102B1200: return "MGA-1084SG Mystique";
        case PciSubDevice102B051A::SUBDEVICE_1100102B: return "MGA-1084SG Mystique";
        case PciSubDevice102B051A::SUBDEVICE_110A0018: return "Scenic Pro C5 (D1025)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051A_H
