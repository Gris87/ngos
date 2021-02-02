// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2537_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2537_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B2537: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B1820 = 0x102B1820,
    SUBDEVICE_102B1830 = 0x102B1830,
    SUBDEVICE_102B1850 = 0x102B1850,
    SUBDEVICE_102B1860 = 0x102B1860,
    SUBDEVICE_102B1880 = 0x102B1880,
    SUBDEVICE_102B1C10 = 0x102B1C10,
    SUBDEVICE_102B2811 = 0x102B2811,
    SUBDEVICE_102B2821 = 0x102B2821,
    SUBDEVICE_102B2841 = 0x102B2841,
    SUBDEVICE_102B2851 = 0x102B2851,
    SUBDEVICE_102B2871 = 0x102B2871,
    SUBDEVICE_102B2C11 = 0x102B2C11,
    SUBDEVICE_102B2C21 = 0x102B2C21,
    SUBDEVICE_102B2C31 = 0x102B2C31,
    SUBDEVICE_102B2C41 = 0x102B2C41,
    SUBDEVICE_102B3001 = 0x102B3001,
    SUBDEVICE_102B3011 = 0x102B3011,
    SUBDEVICE_102B3041 = 0x102B3041,
    SUBDEVICE_102B3051 = 0x102B3051,
    SUBDEVICE_102B3061 = 0x102B3061,
    SUBDEVICE_102B3081 = 0x102B3081
};



inline const char8* enumToString(PciSubDevice102B2537 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B2537::NONE:               return "NONE";
        case PciSubDevice102B2537::SUBDEVICE_102B1820: return "SUBDEVICE_102B1820";
        case PciSubDevice102B2537::SUBDEVICE_102B1830: return "SUBDEVICE_102B1830";
        case PciSubDevice102B2537::SUBDEVICE_102B1850: return "SUBDEVICE_102B1850";
        case PciSubDevice102B2537::SUBDEVICE_102B1860: return "SUBDEVICE_102B1860";
        case PciSubDevice102B2537::SUBDEVICE_102B1880: return "SUBDEVICE_102B1880";
        case PciSubDevice102B2537::SUBDEVICE_102B1C10: return "SUBDEVICE_102B1C10";
        case PciSubDevice102B2537::SUBDEVICE_102B2811: return "SUBDEVICE_102B2811";
        case PciSubDevice102B2537::SUBDEVICE_102B2821: return "SUBDEVICE_102B2821";
        case PciSubDevice102B2537::SUBDEVICE_102B2841: return "SUBDEVICE_102B2841";
        case PciSubDevice102B2537::SUBDEVICE_102B2851: return "SUBDEVICE_102B2851";
        case PciSubDevice102B2537::SUBDEVICE_102B2871: return "SUBDEVICE_102B2871";
        case PciSubDevice102B2537::SUBDEVICE_102B2C11: return "SUBDEVICE_102B2C11";
        case PciSubDevice102B2537::SUBDEVICE_102B2C21: return "SUBDEVICE_102B2C21";
        case PciSubDevice102B2537::SUBDEVICE_102B2C31: return "SUBDEVICE_102B2C31";
        case PciSubDevice102B2537::SUBDEVICE_102B2C41: return "SUBDEVICE_102B2C41";
        case PciSubDevice102B2537::SUBDEVICE_102B3001: return "SUBDEVICE_102B3001";
        case PciSubDevice102B2537::SUBDEVICE_102B3011: return "SUBDEVICE_102B3011";
        case PciSubDevice102B2537::SUBDEVICE_102B3041: return "SUBDEVICE_102B3041";
        case PciSubDevice102B2537::SUBDEVICE_102B3051: return "SUBDEVICE_102B3051";
        case PciSubDevice102B2537::SUBDEVICE_102B3061: return "SUBDEVICE_102B3061";
        case PciSubDevice102B2537::SUBDEVICE_102B3081: return "SUBDEVICE_102B3081";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B2537 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B2537 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B2537::SUBDEVICE_102B1820: return "Millennium P750 64MB";
        case PciSubDevice102B2537::SUBDEVICE_102B1830: return "Millennium P650 64MB";
        case PciSubDevice102B2537::SUBDEVICE_102B1850: return "RAD2mp";
        case PciSubDevice102B2537::SUBDEVICE_102B1860: return "RAD3mp";
        case PciSubDevice102B2537::SUBDEVICE_102B1880: return "Sono S10";
        case PciSubDevice102B2537::SUBDEVICE_102B1C10: return "QID 128MB";
        case PciSubDevice102B2537::SUBDEVICE_102B2811: return "Millennium P650 Low-profile PCI 64MB";
        case PciSubDevice102B2537::SUBDEVICE_102B2821: return "Millennium P650 Low-profile PCI";
        case PciSubDevice102B2537::SUBDEVICE_102B2841: return "RAD PCI";
        case PciSubDevice102B2537::SUBDEVICE_102B2851: return "Spectrum PCI";
        case PciSubDevice102B2537::SUBDEVICE_102B2871: return "EpicA TC2";
        case PciSubDevice102B2537::SUBDEVICE_102B2C11: return "QID Low-profile PCI";
        case PciSubDevice102B2537::SUBDEVICE_102B2C21: return "QID LP PCI LW";
        case PciSubDevice102B2537::SUBDEVICE_102B2C31: return "QID LP PCI";
        case PciSubDevice102B2537::SUBDEVICE_102B2C41: return "EpicA TC4";
        case PciSubDevice102B2537::SUBDEVICE_102B3001: return "Extio F1400";
        case PciSubDevice102B2537::SUBDEVICE_102B3011: return "Extio F1220";
        case PciSubDevice102B2537::SUBDEVICE_102B3041: return "RG-200DL";
        case PciSubDevice102B2537::SUBDEVICE_102B3051: return "RG-400SL";
        case PciSubDevice102B2537::SUBDEVICE_102B3061: return "Extio F1420";
        case PciSubDevice102B2537::SUBDEVICE_102B3081: return "Extio F1240";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B2537_H
