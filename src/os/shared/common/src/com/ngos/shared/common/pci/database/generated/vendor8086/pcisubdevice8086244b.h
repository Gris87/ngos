// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086244B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101401C6 = 0x101401C6,
    SUBDEVICE_102800C7 = 0x102800C7,
    SUBDEVICE_102800D8 = 0x102800D8,
    SUBDEVICE_1028010E = 0x1028010E,
    SUBDEVICE_103C126F = 0x103C126F,
    SUBDEVICE_10438027 = 0x10438027,
    SUBDEVICE_147B0505 = 0x147B0505,
    SUBDEVICE_147B0507 = 0x147B0507,
    SUBDEVICE_15D93280 = 0x15D93280,
    SUBDEVICE_80864532 = 0x80864532,
    SUBDEVICE_80864557 = 0x80864557,
    SUBDEVICE_80864D44 = 0x80864D44,
    SUBDEVICE_80865744 = 0x80865744
};



inline const char8* enumToString(PciSubDevice8086244B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086244B::NONE:               return "NONE";
        case PciSubDevice8086244B::SUBDEVICE_101401C6: return "SUBDEVICE_101401C6";
        case PciSubDevice8086244B::SUBDEVICE_102800C7: return "SUBDEVICE_102800C7";
        case PciSubDevice8086244B::SUBDEVICE_102800D8: return "SUBDEVICE_102800D8";
        case PciSubDevice8086244B::SUBDEVICE_1028010E: return "SUBDEVICE_1028010E";
        case PciSubDevice8086244B::SUBDEVICE_103C126F: return "SUBDEVICE_103C126F";
        case PciSubDevice8086244B::SUBDEVICE_10438027: return "SUBDEVICE_10438027";
        case PciSubDevice8086244B::SUBDEVICE_147B0505: return "SUBDEVICE_147B0505";
        case PciSubDevice8086244B::SUBDEVICE_147B0507: return "SUBDEVICE_147B0507";
        case PciSubDevice8086244B::SUBDEVICE_15D93280: return "SUBDEVICE_15D93280";
        case PciSubDevice8086244B::SUBDEVICE_80864532: return "SUBDEVICE_80864532";
        case PciSubDevice8086244B::SUBDEVICE_80864557: return "SUBDEVICE_80864557";
        case PciSubDevice8086244B::SUBDEVICE_80864D44: return "SUBDEVICE_80864D44";
        case PciSubDevice8086244B::SUBDEVICE_80865744: return "SUBDEVICE_80865744";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086244B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086244B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086244B::SUBDEVICE_101401C6: return "Netvista A40/A40p";
        case PciSubDevice8086244B::SUBDEVICE_102800C7: return "Dimension 8100";
        case PciSubDevice8086244B::SUBDEVICE_102800D8: return "Precision 530";
        case PciSubDevice8086244B::SUBDEVICE_1028010E: return "Optiplex GX240";
        case PciSubDevice8086244B::SUBDEVICE_103C126F: return "e-pc 40";
        case PciSubDevice8086244B::SUBDEVICE_10438027: return "TUSL2-C Mainboard";
        case PciSubDevice8086244B::SUBDEVICE_147B0505: return "BL7 motherboard";
        case PciSubDevice8086244B::SUBDEVICE_147B0507: return "TH7II-RAID";
        case PciSubDevice8086244B::SUBDEVICE_15D93280: return "Supermicro P4SBE Mainboard";
        case PciSubDevice8086244B::SUBDEVICE_80864532: return "Desktop Board D815EEA2/D815EFV";
        case PciSubDevice8086244B::SUBDEVICE_80864557: return "D815EGEW Mainboard";
        case PciSubDevice8086244B::SUBDEVICE_80864D44: return "D850EMV2 motherboard";
        case PciSubDevice8086244B::SUBDEVICE_80865744: return "S845WD1-E mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086244B_H
