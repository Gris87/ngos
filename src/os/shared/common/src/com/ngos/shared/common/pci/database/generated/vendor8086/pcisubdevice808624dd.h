// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624DD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624DD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624DD: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140287 = 0x10140287,
    SUBDEVICE_101402DD = 0x101402DD,
    SUBDEVICE_101402ED = 0x101402ED,
    SUBDEVICE_10280168 = 0x10280168,
    SUBDEVICE_10280169 = 0x10280169,
    SUBDEVICE_1028016C = 0x1028016C,
    SUBDEVICE_1028016D = 0x1028016D,
    SUBDEVICE_10280170 = 0x10280170,
    SUBDEVICE_10280183 = 0x10280183,
    SUBDEVICE_1028019A = 0x1028019A,
    SUBDEVICE_103C006A = 0x103C006A,
    SUBDEVICE_103C12BC = 0x103C12BC,
    SUBDEVICE_103C3208 = 0x103C3208,
    SUBDEVICE_104380A6 = 0x104380A6,
    SUBDEVICE_14585006 = 0x14585006,
    SUBDEVICE_14627280 = 0x14627280,
    SUBDEVICE_14627650 = 0x14627650,
    SUBDEVICE_80863427 = 0x80863427,
    SUBDEVICE_80864246 = 0x80864246,
    SUBDEVICE_80864C43 = 0x80864C43,
    SUBDEVICE_8086524C = 0x8086524C
};



inline const char8* enumToString(PciSubDevice808624DD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624DD::NONE:               return "NONE";
        case PciSubDevice808624DD::SUBDEVICE_10140287: return "SUBDEVICE_10140287";
        case PciSubDevice808624DD::SUBDEVICE_101402DD: return "SUBDEVICE_101402DD";
        case PciSubDevice808624DD::SUBDEVICE_101402ED: return "SUBDEVICE_101402ED";
        case PciSubDevice808624DD::SUBDEVICE_10280168: return "SUBDEVICE_10280168";
        case PciSubDevice808624DD::SUBDEVICE_10280169: return "SUBDEVICE_10280169";
        case PciSubDevice808624DD::SUBDEVICE_1028016C: return "SUBDEVICE_1028016C";
        case PciSubDevice808624DD::SUBDEVICE_1028016D: return "SUBDEVICE_1028016D";
        case PciSubDevice808624DD::SUBDEVICE_10280170: return "SUBDEVICE_10280170";
        case PciSubDevice808624DD::SUBDEVICE_10280183: return "SUBDEVICE_10280183";
        case PciSubDevice808624DD::SUBDEVICE_1028019A: return "SUBDEVICE_1028019A";
        case PciSubDevice808624DD::SUBDEVICE_103C006A: return "SUBDEVICE_103C006A";
        case PciSubDevice808624DD::SUBDEVICE_103C12BC: return "SUBDEVICE_103C12BC";
        case PciSubDevice808624DD::SUBDEVICE_103C3208: return "SUBDEVICE_103C3208";
        case PciSubDevice808624DD::SUBDEVICE_104380A6: return "SUBDEVICE_104380A6";
        case PciSubDevice808624DD::SUBDEVICE_14585006: return "SUBDEVICE_14585006";
        case PciSubDevice808624DD::SUBDEVICE_14627280: return "SUBDEVICE_14627280";
        case PciSubDevice808624DD::SUBDEVICE_14627650: return "SUBDEVICE_14627650";
        case PciSubDevice808624DD::SUBDEVICE_80863427: return "SUBDEVICE_80863427";
        case PciSubDevice808624DD::SUBDEVICE_80864246: return "SUBDEVICE_80864246";
        case PciSubDevice808624DD::SUBDEVICE_80864C43: return "SUBDEVICE_80864C43";
        case PciSubDevice808624DD::SUBDEVICE_8086524C: return "SUBDEVICE_8086524C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624DD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624DD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624DD::SUBDEVICE_10140287: return "ThinkCentre S50";
        case PciSubDevice808624DD::SUBDEVICE_101402DD: return "eServer xSeries server mainboard";
        case PciSubDevice808624DD::SUBDEVICE_101402ED: return "eServer xSeries server mainboard";
        case PciSubDevice808624DD::SUBDEVICE_10280168: return "Precision Workstation 670 Mainboard";
        case PciSubDevice808624DD::SUBDEVICE_10280169: return "Precision 470";
        case PciSubDevice808624DD::SUBDEVICE_1028016C: return "PowerEdge 1850 onboard EHCI";
        case PciSubDevice808624DD::SUBDEVICE_1028016D: return "PowerEdge 2850 onboard EHCI";
        case PciSubDevice808624DD::SUBDEVICE_10280170: return "PowerEdge 6850 onboard EHCI";
        case PciSubDevice808624DD::SUBDEVICE_10280183: return "PowerEdge 1800";
        case PciSubDevice808624DD::SUBDEVICE_1028019A: return "PowerEdge SC1425";
        case PciSubDevice808624DD::SUBDEVICE_103C006A: return "NX9500";
        case PciSubDevice808624DD::SUBDEVICE_103C12BC: return "d530 CMT (DG746A)";
        case PciSubDevice808624DD::SUBDEVICE_103C3208: return "ProLiant DL140 G2";
        case PciSubDevice808624DD::SUBDEVICE_104380A6: return "P4P800/P5P800 series motherboard";
        case PciSubDevice808624DD::SUBDEVICE_14585006: return "GA-8IPE1000 Pro2 motherboard (865PE)";
        case PciSubDevice808624DD::SUBDEVICE_14627280: return "865PE Neo2 (MS-6728)";
        case PciSubDevice808624DD::SUBDEVICE_14627650: return "Hetis 865GV-E (MS-7065)";
        case PciSubDevice808624DD::SUBDEVICE_80863427: return "S875WP1-E mainboard";
        case PciSubDevice808624DD::SUBDEVICE_80864246: return "Desktop Board D865GBF";
        case PciSubDevice808624DD::SUBDEVICE_80864C43: return "Desktop Board D865GLC";
        case PciSubDevice808624DD::SUBDEVICE_8086524C: return "D865PERL mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624DD_H
