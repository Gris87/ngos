// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862659_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862659_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862659: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140565 = 0x10140565,
    SUBDEVICE_10280177 = 0x10280177,
    SUBDEVICE_10280179 = 0x10280179,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_104380A6 = 0x104380A6,
    SUBDEVICE_14582659 = 0x14582659,
    SUBDEVICE_14627028 = 0x14627028,
    SUBDEVICE_1734105C = 0x1734105C,
    SUBDEVICE_E4BF0CCD = 0xE4BF0CCD,
    SUBDEVICE_E4BF0CD3 = 0xE4BF0CD3,
    SUBDEVICE_E4BF58B1 = 0xE4BF58B1
};



inline const char8* enumToString(PciSubDevice80862659 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862659::NONE:               return "NONE";
        case PciSubDevice80862659::SUBDEVICE_10140565: return "SUBDEVICE_10140565";
        case PciSubDevice80862659::SUBDEVICE_10280177: return "SUBDEVICE_10280177";
        case PciSubDevice80862659::SUBDEVICE_10280179: return "SUBDEVICE_10280179";
        case PciSubDevice80862659::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice80862659::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice80862659::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice80862659::SUBDEVICE_104380A6: return "SUBDEVICE_104380A6";
        case PciSubDevice80862659::SUBDEVICE_14582659: return "SUBDEVICE_14582659";
        case PciSubDevice80862659::SUBDEVICE_14627028: return "SUBDEVICE_14627028";
        case PciSubDevice80862659::SUBDEVICE_1734105C: return "SUBDEVICE_1734105C";
        case PciSubDevice80862659::SUBDEVICE_E4BF0CCD: return "SUBDEVICE_E4BF0CCD";
        case PciSubDevice80862659::SUBDEVICE_E4BF0CD3: return "SUBDEVICE_E4BF0CD3";
        case PciSubDevice80862659::SUBDEVICE_E4BF58B1: return "SUBDEVICE_E4BF58B1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862659 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862659 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862659::SUBDEVICE_10140565: return "ThinkPad X41";
        case PciSubDevice80862659::SUBDEVICE_10280177: return "Dimension 8400";
        case PciSubDevice80862659::SUBDEVICE_10280179: return "Optiplex GX280";
        case PciSubDevice80862659::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice80862659::SUBDEVICE_103C0944: return "Compaq nc6220 Notebook PC";
        case PciSubDevice80862659::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice80862659::SUBDEVICE_104380A6: return "P5GD1-VW Mainboard";
        case PciSubDevice80862659::SUBDEVICE_14582659: return "GA-8I915ME-G Mainboard";
        case PciSubDevice80862659::SUBDEVICE_14627028: return "915P/G Neo2";
        case PciSubDevice80862659::SUBDEVICE_1734105C: return "Scenic W620";
        case PciSubDevice80862659::SUBDEVICE_E4BF0CCD: return "CCD-CALYPSO";
        case PciSubDevice80862659::SUBDEVICE_E4BF0CD3: return "CD3-JIVE";
        case PciSubDevice80862659::SUBDEVICE_E4BF58B1: return "XB1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862659_H
