// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086266E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140581 = 0x10140581,
    SUBDEVICE_1025006A = 0x1025006A,
    SUBDEVICE_10280177 = 0x10280177,
    SUBDEVICE_10280179 = 0x10280179,
    SUBDEVICE_10280182 = 0x10280182,
    SUBDEVICE_10280187 = 0x10280187,
    SUBDEVICE_10280188 = 0x10280188,
    SUBDEVICE_103C0934 = 0x103C0934,
    SUBDEVICE_103C0944 = 0x103C0944,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_103C3006 = 0x103C3006,
    SUBDEVICE_1458A002 = 0x1458A002,
    SUBDEVICE_152D0745 = 0x152D0745,
    SUBDEVICE_1734105A = 0x1734105A
};



inline const char8* enumToString(PciSubDevice8086266E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086266E::NONE:               return "NONE";
        case PciSubDevice8086266E::SUBDEVICE_10140581: return "SUBDEVICE_10140581";
        case PciSubDevice8086266E::SUBDEVICE_1025006A: return "SUBDEVICE_1025006A";
        case PciSubDevice8086266E::SUBDEVICE_10280177: return "SUBDEVICE_10280177";
        case PciSubDevice8086266E::SUBDEVICE_10280179: return "SUBDEVICE_10280179";
        case PciSubDevice8086266E::SUBDEVICE_10280182: return "SUBDEVICE_10280182";
        case PciSubDevice8086266E::SUBDEVICE_10280187: return "SUBDEVICE_10280187";
        case PciSubDevice8086266E::SUBDEVICE_10280188: return "SUBDEVICE_10280188";
        case PciSubDevice8086266E::SUBDEVICE_103C0934: return "SUBDEVICE_103C0934";
        case PciSubDevice8086266E::SUBDEVICE_103C0944: return "SUBDEVICE_103C0944";
        case PciSubDevice8086266E::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice8086266E::SUBDEVICE_103C3006: return "SUBDEVICE_103C3006";
        case PciSubDevice8086266E::SUBDEVICE_1458A002: return "SUBDEVICE_1458A002";
        case PciSubDevice8086266E::SUBDEVICE_152D0745: return "SUBDEVICE_152D0745";
        case PciSubDevice8086266E::SUBDEVICE_1734105A: return "SUBDEVICE_1734105A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086266E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086266E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086266E::SUBDEVICE_10140581: return "ThinkPad X41 (Analog Devices AD1981B codec)";
        case PciSubDevice8086266E::SUBDEVICE_1025006A: return "Realtek ALC 655 codec (in Acer TravelMate 2410 serie laptop)";
        case PciSubDevice8086266E::SUBDEVICE_10280177: return "Dimension 8400";
        case PciSubDevice8086266E::SUBDEVICE_10280179: return "Optiplex GX280";
        case PciSubDevice8086266E::SUBDEVICE_10280182: return "Latitude D610 Laptop";
        case PciSubDevice8086266E::SUBDEVICE_10280187: return "Precision M70 Laptop";
        case PciSubDevice8086266E::SUBDEVICE_10280188: return "Inspiron 6000 laptop";
        case PciSubDevice8086266E::SUBDEVICE_103C0934: return "Compaq nw8240/nx8220";
        case PciSubDevice8086266E::SUBDEVICE_103C0944: return "Compaq NC6220";
        case PciSubDevice8086266E::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice8086266E::SUBDEVICE_103C3006: return "DC7100 SFF(DX878AV)";
        case PciSubDevice8086266E::SUBDEVICE_1458A002: return "GA-8I915ME-G Mainboard";
        case PciSubDevice8086266E::SUBDEVICE_152D0745: return "Packard Bell A8550 Laptop";
        case PciSubDevice8086266E::SUBDEVICE_1734105A: return "Scenic W620";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086266E_H
