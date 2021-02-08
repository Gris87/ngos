// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862486_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862486_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862486: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140223 = 0x10140223,
    SUBDEVICE_10140503 = 0x10140503,
    SUBDEVICE_1014051A = 0x1014051A,
    SUBDEVICE_101F1025 = 0x101F1025,
    SUBDEVICE_10431496 = 0x10431496,
    SUBDEVICE_104D80E7 = 0x104D80E7,
    SUBDEVICE_134D4C21 = 0x134D4C21,
    SUBDEVICE_144D2115 = 0x144D2115,
    SUBDEVICE_14F15421 = 0x14F15421
};



inline const char8* enumToString(PciSubDevice80862486 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862486::NONE:               return "NONE";
        case PciSubDevice80862486::SUBDEVICE_10140223: return "SUBDEVICE_10140223";
        case PciSubDevice80862486::SUBDEVICE_10140503: return "SUBDEVICE_10140503";
        case PciSubDevice80862486::SUBDEVICE_1014051A: return "SUBDEVICE_1014051A";
        case PciSubDevice80862486::SUBDEVICE_101F1025: return "SUBDEVICE_101F1025";
        case PciSubDevice80862486::SUBDEVICE_10431496: return "SUBDEVICE_10431496";
        case PciSubDevice80862486::SUBDEVICE_104D80E7: return "SUBDEVICE_104D80E7";
        case PciSubDevice80862486::SUBDEVICE_134D4C21: return "SUBDEVICE_134D4C21";
        case PciSubDevice80862486::SUBDEVICE_144D2115: return "SUBDEVICE_144D2115";
        case PciSubDevice80862486::SUBDEVICE_14F15421: return "SUBDEVICE_14F15421";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862486 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862486 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862486::SUBDEVICE_10140223: return "ThinkPad A/T/X Series";
        case PciSubDevice80862486::SUBDEVICE_10140503: return "ThinkPad R31";
        case PciSubDevice80862486::SUBDEVICE_1014051A: return "ThinkPad A/T/X Series";
        case PciSubDevice80862486::SUBDEVICE_101F1025: return "620 Series";
        case PciSubDevice80862486::SUBDEVICE_10431496: return "PCtel HSP56 MR";
        case PciSubDevice80862486::SUBDEVICE_104D80E7: return "VAIO PCG-GR214EP/GR214MP/GR215MP/GR314MP/GR315MP";
        case PciSubDevice80862486::SUBDEVICE_134D4C21: return "Dell Inspiron 2100 internal modem";
        case PciSubDevice80862486::SUBDEVICE_144D2115: return "vpr Matrix 170B4 internal modem";
        case PciSubDevice80862486::SUBDEVICE_14F15421: return "MD56ORD V.92 MDC Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862486_H
