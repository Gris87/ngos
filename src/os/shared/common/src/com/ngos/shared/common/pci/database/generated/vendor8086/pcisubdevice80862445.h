// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862445_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862445_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862445: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11000B = 0x0E11000B,
    SUBDEVICE_0E110088 = 0x0E110088,
    SUBDEVICE_101401C6 = 0x101401C6,
    SUBDEVICE_10251016 = 0x10251016,
    SUBDEVICE_102800D8 = 0x102800D8,
    SUBDEVICE_103C126F = 0x103C126F,
    SUBDEVICE_104D80DF = 0x104D80DF,
    SUBDEVICE_14623370 = 0x14623370,
    SUBDEVICE_147B0505 = 0x147B0505,
    SUBDEVICE_147B0507 = 0x147B0507,
    SUBDEVICE_80864557 = 0x80864557,
    SUBDEVICE_80864656 = 0x80864656
};



inline const char8* enumToString(PciSubDevice80862445 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862445::NONE:               return "NONE";
        case PciSubDevice80862445::SUBDEVICE_0E11000B: return "SUBDEVICE_0E11000B";
        case PciSubDevice80862445::SUBDEVICE_0E110088: return "SUBDEVICE_0E110088";
        case PciSubDevice80862445::SUBDEVICE_101401C6: return "SUBDEVICE_101401C6";
        case PciSubDevice80862445::SUBDEVICE_10251016: return "SUBDEVICE_10251016";
        case PciSubDevice80862445::SUBDEVICE_102800D8: return "SUBDEVICE_102800D8";
        case PciSubDevice80862445::SUBDEVICE_103C126F: return "SUBDEVICE_103C126F";
        case PciSubDevice80862445::SUBDEVICE_104D80DF: return "SUBDEVICE_104D80DF";
        case PciSubDevice80862445::SUBDEVICE_14623370: return "SUBDEVICE_14623370";
        case PciSubDevice80862445::SUBDEVICE_147B0505: return "SUBDEVICE_147B0505";
        case PciSubDevice80862445::SUBDEVICE_147B0507: return "SUBDEVICE_147B0507";
        case PciSubDevice80862445::SUBDEVICE_80864557: return "SUBDEVICE_80864557";
        case PciSubDevice80862445::SUBDEVICE_80864656: return "SUBDEVICE_80864656";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862445 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862445 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862445::SUBDEVICE_0E11000B: return "Compaq Deskpro EN Audio";
        case PciSubDevice80862445::SUBDEVICE_0E110088: return "Evo D500";
        case PciSubDevice80862445::SUBDEVICE_101401C6: return "Netvista A40/A40p";
        case PciSubDevice80862445::SUBDEVICE_10251016: return "Travelmate 612 TX";
        case PciSubDevice80862445::SUBDEVICE_102800D8: return "Precision 530";
        case PciSubDevice80862445::SUBDEVICE_103C126F: return "e-pc 40";
        case PciSubDevice80862445::SUBDEVICE_104D80DF: return "Vaio PCG-FX403";
        case PciSubDevice80862445::SUBDEVICE_14623370: return "STAC9721 AC";
        case PciSubDevice80862445::SUBDEVICE_147B0505: return "BL7 motherboard";
        case PciSubDevice80862445::SUBDEVICE_147B0507: return "TH7II-RAID";
        case PciSubDevice80862445::SUBDEVICE_80864557: return "D815EGEW Mainboard";
        case PciSubDevice80862445::SUBDEVICE_80864656: return "Desktop Board D815EFV";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862445_H
