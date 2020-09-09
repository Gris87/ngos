// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C88005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C88005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10C88005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B0D1 = 0x0E11B0D1,
    SUBDEVICE_0E11B126 = 0x0E11B126,
    SUBDEVICE_101400DD = 0x101400DD,
    SUBDEVICE_10251003 = 0x10251003,
    SUBDEVICE_10280088 = 0x10280088,
    SUBDEVICE_1028008F = 0x1028008F,
    SUBDEVICE_103C0007 = 0x103C0007,
    SUBDEVICE_103C0008 = 0x103C0008,
    SUBDEVICE_103C000D = 0x103C000D,
    SUBDEVICE_10C88005 = 0x10C88005,
    SUBDEVICE_110A8005 = 0x110A8005,
    SUBDEVICE_14C00004 = 0x14C00004
};



inline const char8* enumToString(PciSubDevice10C88005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10C88005::NONE:               return "NONE";
        case PciSubDevice10C88005::SUBDEVICE_0E11B0D1: return "SUBDEVICE_0E11B0D1";
        case PciSubDevice10C88005::SUBDEVICE_0E11B126: return "SUBDEVICE_0E11B126";
        case PciSubDevice10C88005::SUBDEVICE_101400DD: return "SUBDEVICE_101400DD";
        case PciSubDevice10C88005::SUBDEVICE_10251003: return "SUBDEVICE_10251003";
        case PciSubDevice10C88005::SUBDEVICE_10280088: return "SUBDEVICE_10280088";
        case PciSubDevice10C88005::SUBDEVICE_1028008F: return "SUBDEVICE_1028008F";
        case PciSubDevice10C88005::SUBDEVICE_103C0007: return "SUBDEVICE_103C0007";
        case PciSubDevice10C88005::SUBDEVICE_103C0008: return "SUBDEVICE_103C0008";
        case PciSubDevice10C88005::SUBDEVICE_103C000D: return "SUBDEVICE_103C000D";
        case PciSubDevice10C88005::SUBDEVICE_10C88005: return "SUBDEVICE_10C88005";
        case PciSubDevice10C88005::SUBDEVICE_110A8005: return "SUBDEVICE_110A8005";
        case PciSubDevice10C88005::SUBDEVICE_14C00004: return "SUBDEVICE_14C00004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10C88005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10C88005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10C88005::SUBDEVICE_0E11B0D1: return "MagicMedia 256AV Audio Device on Discovery";
        case PciSubDevice10C88005::SUBDEVICE_0E11B126: return "MagicMedia 256AV Audio Device on Durango";
        case PciSubDevice10C88005::SUBDEVICE_101400DD: return "ThinkPad 390/i1720/i1721";
        case PciSubDevice10C88005::SUBDEVICE_10251003: return "MagicMedia 256AV Audio Device on TravelMate 720";
        case PciSubDevice10C88005::SUBDEVICE_10280088: return "Latitude CPi A";
        case PciSubDevice10C88005::SUBDEVICE_1028008F: return "MagicMedia 256AV Audio Device on Colorado Inspiron";
        case PciSubDevice10C88005::SUBDEVICE_103C0007: return "MagicMedia 256AV Audio Device on Voyager II";
        case PciSubDevice10C88005::SUBDEVICE_103C0008: return "MagicMedia 256AV Audio Device on Voyager III";
        case PciSubDevice10C88005::SUBDEVICE_103C000D: return "MagicMedia 256AV Audio Device on Omnibook 900";
        case PciSubDevice10C88005::SUBDEVICE_10C88005: return "MagicMedia 256AV Audio Device on FireAnt";
        case PciSubDevice10C88005::SUBDEVICE_110A8005: return "MagicMedia 256AV Audio Device";
        case PciSubDevice10C88005::SUBDEVICE_14C00004: return "MagicMedia 256AV Audio Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCISUBDEVICE10C88005_H
