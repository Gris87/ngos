// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863582_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863582_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863582: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140562 = 0x10140562,
    SUBDEVICE_10280139 = 0x10280139,
    SUBDEVICE_1028014F = 0x1028014F,
    SUBDEVICE_10280152 = 0x10280152,
    SUBDEVICE_10280163 = 0x10280163,
    SUBDEVICE_1028018D = 0x1028018D,
    SUBDEVICE_114A0582 = 0x114A0582,
    SUBDEVICE_177510D0 = 0x177510D0,
    SUBDEVICE_1775CE90 = 0x1775CE90,
    SUBDEVICE_4C5310B0 = 0x4C5310B0,
    SUBDEVICE_4C5310E0 = 0x4C5310E0,
    SUBDEVICE_E4BF0CC9 = 0xE4BF0CC9,
    SUBDEVICE_E4BF0CD2 = 0xE4BF0CD2
};



inline const char8* enumToString(PciSubDevice80863582 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863582::NONE:               return "NONE";
        case PciSubDevice80863582::SUBDEVICE_10140562: return "SUBDEVICE_10140562";
        case PciSubDevice80863582::SUBDEVICE_10280139: return "SUBDEVICE_10280139";
        case PciSubDevice80863582::SUBDEVICE_1028014F: return "SUBDEVICE_1028014F";
        case PciSubDevice80863582::SUBDEVICE_10280152: return "SUBDEVICE_10280152";
        case PciSubDevice80863582::SUBDEVICE_10280163: return "SUBDEVICE_10280163";
        case PciSubDevice80863582::SUBDEVICE_1028018D: return "SUBDEVICE_1028018D";
        case PciSubDevice80863582::SUBDEVICE_114A0582: return "SUBDEVICE_114A0582";
        case PciSubDevice80863582::SUBDEVICE_177510D0: return "SUBDEVICE_177510D0";
        case PciSubDevice80863582::SUBDEVICE_1775CE90: return "SUBDEVICE_1775CE90";
        case PciSubDevice80863582::SUBDEVICE_4C5310B0: return "SUBDEVICE_4C5310B0";
        case PciSubDevice80863582::SUBDEVICE_4C5310E0: return "SUBDEVICE_4C5310E0";
        case PciSubDevice80863582::SUBDEVICE_E4BF0CC9: return "SUBDEVICE_E4BF0CC9";
        case PciSubDevice80863582::SUBDEVICE_E4BF0CD2: return "SUBDEVICE_E4BF0CD2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863582 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863582 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863582::SUBDEVICE_10140562: return "ThinkPad R50e";
        case PciSubDevice80863582::SUBDEVICE_10280139: return "Latitude D400";
        case PciSubDevice80863582::SUBDEVICE_1028014F: return "Latitude X300";
        case PciSubDevice80863582::SUBDEVICE_10280152: return "Latitude D500";
        case PciSubDevice80863582::SUBDEVICE_10280163: return "Latitude D505";
        case PciSubDevice80863582::SUBDEVICE_1028018D: return "Inspiron 700m/710m";
        case PciSubDevice80863582::SUBDEVICE_114A0582: return "PC8 integrated graphics";
        case PciSubDevice80863582::SUBDEVICE_177510D0: return "V5D Single Board Computer VGA";
        case PciSubDevice80863582::SUBDEVICE_1775CE90: return "CE9";
        case PciSubDevice80863582::SUBDEVICE_4C5310B0: return "CL9 mainboard";
        case PciSubDevice80863582::SUBDEVICE_4C5310E0: return "PSL09 PrPMC";
        case PciSubDevice80863582::SUBDEVICE_E4BF0CC9: return "CC9-SAMBA";
        case PciSubDevice80863582::SUBDEVICE_E4BF0CD2: return "CD2-BEBOP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863582_H
