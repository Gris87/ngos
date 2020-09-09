// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862592_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862592_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862592: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140582 = 0x10140582,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_103C308A = 0x103C308A,
    SUBDEVICE_10431881 = 0x10431881,
    SUBDEVICE_E4BF0CCD = 0xE4BF0CCD,
    SUBDEVICE_E4BF0CD3 = 0xE4BF0CD3,
    SUBDEVICE_E4BF58B1 = 0xE4BF58B1
};



inline const char8* enumToString(PciSubDevice80862592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862592::NONE:               return "NONE";
        case PciSubDevice80862592::SUBDEVICE_10140582: return "SUBDEVICE_10140582";
        case PciSubDevice80862592::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice80862592::SUBDEVICE_103C308A: return "SUBDEVICE_103C308A";
        case PciSubDevice80862592::SUBDEVICE_10431881: return "SUBDEVICE_10431881";
        case PciSubDevice80862592::SUBDEVICE_E4BF0CCD: return "SUBDEVICE_E4BF0CCD";
        case PciSubDevice80862592::SUBDEVICE_E4BF0CD3: return "SUBDEVICE_E4BF0CD3";
        case PciSubDevice80862592::SUBDEVICE_E4BF58B1: return "SUBDEVICE_E4BF58B1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862592 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862592::SUBDEVICE_10140582: return "ThinkPad X41";
        case PciSubDevice80862592::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice80862592::SUBDEVICE_103C308A: return "NC6220";
        case PciSubDevice80862592::SUBDEVICE_10431881: return "GMA 900 915GM Integrated Graphics";
        case PciSubDevice80862592::SUBDEVICE_E4BF0CCD: return "CCD-CALYPSO";
        case PciSubDevice80862592::SUBDEVICE_E4BF0CD3: return "CD3-JIVE";
        case PciSubDevice80862592::SUBDEVICE_E4BF58B1: return "XB1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862592_H
