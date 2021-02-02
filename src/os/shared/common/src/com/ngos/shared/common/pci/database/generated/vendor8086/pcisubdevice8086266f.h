// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086266F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280177 = 0x10280177,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_104380A6 = 0x104380A6,
    SUBDEVICE_1458266F = 0x1458266F,
    SUBDEVICE_14627028 = 0x14627028,
    SUBDEVICE_1734105C = 0x1734105C,
    SUBDEVICE_E4BF0CCD = 0xE4BF0CCD,
    SUBDEVICE_E4BF0CD3 = 0xE4BF0CD3,
    SUBDEVICE_E4BF58B1 = 0xE4BF58B1
};



inline const char8* enumToString(PciSubDevice8086266F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086266F::NONE:               return "NONE";
        case PciSubDevice8086266F::SUBDEVICE_10280177: return "SUBDEVICE_10280177";
        case PciSubDevice8086266F::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice8086266F::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice8086266F::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice8086266F::SUBDEVICE_104380A6: return "SUBDEVICE_104380A6";
        case PciSubDevice8086266F::SUBDEVICE_1458266F: return "SUBDEVICE_1458266F";
        case PciSubDevice8086266F::SUBDEVICE_14627028: return "SUBDEVICE_14627028";
        case PciSubDevice8086266F::SUBDEVICE_1734105C: return "SUBDEVICE_1734105C";
        case PciSubDevice8086266F::SUBDEVICE_E4BF0CCD: return "SUBDEVICE_E4BF0CCD";
        case PciSubDevice8086266F::SUBDEVICE_E4BF0CD3: return "SUBDEVICE_E4BF0CD3";
        case PciSubDevice8086266F::SUBDEVICE_E4BF58B1: return "SUBDEVICE_E4BF58B1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086266F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086266F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086266F::SUBDEVICE_10280177: return "Dimension 8400";
        case PciSubDevice8086266F::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice8086266F::SUBDEVICE_103C0944: return "Compaq nc6220 Notebook PC";
        case PciSubDevice8086266F::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice8086266F::SUBDEVICE_104380A6: return "P5GD1-VW Mainboard";
        case PciSubDevice8086266F::SUBDEVICE_1458266F: return "GA-8I915ME-G Mainboard";
        case PciSubDevice8086266F::SUBDEVICE_14627028: return "915P/G Neo2";
        case PciSubDevice8086266F::SUBDEVICE_1734105C: return "Scenic W620";
        case PciSubDevice8086266F::SUBDEVICE_E4BF0CCD: return "CCD-CALYPSO";
        case PciSubDevice8086266F::SUBDEVICE_E4BF0CD3: return "CD3-JIVE";
        case PciSubDevice8086266F::SUBDEVICE_E4BF58B1: return "XB1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266F_H
