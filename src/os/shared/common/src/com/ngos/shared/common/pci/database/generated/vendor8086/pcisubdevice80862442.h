// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862442_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862442_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862442: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101401C6 = 0x101401C6,
    SUBDEVICE_10251016 = 0x10251016,
    SUBDEVICE_102800C7 = 0x102800C7,
    SUBDEVICE_102800D8 = 0x102800D8,
    SUBDEVICE_1028010E = 0x1028010E,
    SUBDEVICE_103C126F = 0x103C126F,
    SUBDEVICE_10438027 = 0x10438027,
    SUBDEVICE_104D80DF = 0x104D80DF,
    SUBDEVICE_147B0505 = 0x147B0505,
    SUBDEVICE_147B0507 = 0x147B0507,
    SUBDEVICE_80864532 = 0x80864532,
    SUBDEVICE_80864557 = 0x80864557,
    SUBDEVICE_80864D44 = 0x80864D44,
    SUBDEVICE_80865744 = 0x80865744
};



inline const char8* enumToString(PciSubDevice80862442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862442::NONE:               return "NONE";
        case PciSubDevice80862442::SUBDEVICE_101401C6: return "SUBDEVICE_101401C6";
        case PciSubDevice80862442::SUBDEVICE_10251016: return "SUBDEVICE_10251016";
        case PciSubDevice80862442::SUBDEVICE_102800C7: return "SUBDEVICE_102800C7";
        case PciSubDevice80862442::SUBDEVICE_102800D8: return "SUBDEVICE_102800D8";
        case PciSubDevice80862442::SUBDEVICE_1028010E: return "SUBDEVICE_1028010E";
        case PciSubDevice80862442::SUBDEVICE_103C126F: return "SUBDEVICE_103C126F";
        case PciSubDevice80862442::SUBDEVICE_10438027: return "SUBDEVICE_10438027";
        case PciSubDevice80862442::SUBDEVICE_104D80DF: return "SUBDEVICE_104D80DF";
        case PciSubDevice80862442::SUBDEVICE_147B0505: return "SUBDEVICE_147B0505";
        case PciSubDevice80862442::SUBDEVICE_147B0507: return "SUBDEVICE_147B0507";
        case PciSubDevice80862442::SUBDEVICE_80864532: return "SUBDEVICE_80864532";
        case PciSubDevice80862442::SUBDEVICE_80864557: return "SUBDEVICE_80864557";
        case PciSubDevice80862442::SUBDEVICE_80864D44: return "SUBDEVICE_80864D44";
        case PciSubDevice80862442::SUBDEVICE_80865744: return "SUBDEVICE_80865744";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862442::SUBDEVICE_101401C6: return "Netvista A40/A40p";
        case PciSubDevice80862442::SUBDEVICE_10251016: return "Travelmate 612 TX";
        case PciSubDevice80862442::SUBDEVICE_102800C7: return "Dimension 8100";
        case PciSubDevice80862442::SUBDEVICE_102800D8: return "Precision 530";
        case PciSubDevice80862442::SUBDEVICE_1028010E: return "Optiplex GX240";
        case PciSubDevice80862442::SUBDEVICE_103C126F: return "e-pc 40";
        case PciSubDevice80862442::SUBDEVICE_10438027: return "TUSL2-C Mainboard";
        case PciSubDevice80862442::SUBDEVICE_104D80DF: return "Vaio PCG-FX403";
        case PciSubDevice80862442::SUBDEVICE_147B0505: return "BL7 motherboard";
        case PciSubDevice80862442::SUBDEVICE_147B0507: return "TH7II-RAID";
        case PciSubDevice80862442::SUBDEVICE_80864532: return "Desktop Board D815EEA2/D815EFV";
        case PciSubDevice80862442::SUBDEVICE_80864557: return "D815EGEW Mainboard";
        case PciSubDevice80862442::SUBDEVICE_80864D44: return "D850EMV2 motherboard";
        case PciSubDevice80862442::SUBDEVICE_80865744: return "S845WD1-E mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862442_H
