// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624DB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624DB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624DB: u32 // Ignore CppEnumVerifier
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
    SUBDEVICE_1028019A = 0x1028019A,
    SUBDEVICE_103C006A = 0x103C006A,
    SUBDEVICE_103C12BC = 0x103C12BC,
    SUBDEVICE_104380A6 = 0x104380A6,
    SUBDEVICE_145824D2 = 0x145824D2,
    SUBDEVICE_14627280 = 0x14627280,
    SUBDEVICE_14627580 = 0x14627580,
    SUBDEVICE_14627650 = 0x14627650,
    SUBDEVICE_15653101 = 0x15653101,
    SUBDEVICE_15D94580 = 0x15D94580,
    SUBDEVICE_1734101C = 0x1734101C,
    SUBDEVICE_808624DB = 0x808624DB,
    SUBDEVICE_80863427 = 0x80863427,
    SUBDEVICE_80864246 = 0x80864246,
    SUBDEVICE_80864C43 = 0x80864C43,
    SUBDEVICE_8086524C = 0x8086524C
};



inline const char8* enumToString(PciSubDevice808624DB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624DB::NONE:               return "NONE";
        case PciSubDevice808624DB::SUBDEVICE_10140287: return "SUBDEVICE_10140287";
        case PciSubDevice808624DB::SUBDEVICE_101402DD: return "SUBDEVICE_101402DD";
        case PciSubDevice808624DB::SUBDEVICE_101402ED: return "SUBDEVICE_101402ED";
        case PciSubDevice808624DB::SUBDEVICE_10280168: return "SUBDEVICE_10280168";
        case PciSubDevice808624DB::SUBDEVICE_10280169: return "SUBDEVICE_10280169";
        case PciSubDevice808624DB::SUBDEVICE_1028016C: return "SUBDEVICE_1028016C";
        case PciSubDevice808624DB::SUBDEVICE_1028016D: return "SUBDEVICE_1028016D";
        case PciSubDevice808624DB::SUBDEVICE_10280170: return "SUBDEVICE_10280170";
        case PciSubDevice808624DB::SUBDEVICE_1028019A: return "SUBDEVICE_1028019A";
        case PciSubDevice808624DB::SUBDEVICE_103C006A: return "SUBDEVICE_103C006A";
        case PciSubDevice808624DB::SUBDEVICE_103C12BC: return "SUBDEVICE_103C12BC";
        case PciSubDevice808624DB::SUBDEVICE_104380A6: return "SUBDEVICE_104380A6";
        case PciSubDevice808624DB::SUBDEVICE_145824D2: return "SUBDEVICE_145824D2";
        case PciSubDevice808624DB::SUBDEVICE_14627280: return "SUBDEVICE_14627280";
        case PciSubDevice808624DB::SUBDEVICE_14627580: return "SUBDEVICE_14627580";
        case PciSubDevice808624DB::SUBDEVICE_14627650: return "SUBDEVICE_14627650";
        case PciSubDevice808624DB::SUBDEVICE_15653101: return "SUBDEVICE_15653101";
        case PciSubDevice808624DB::SUBDEVICE_15D94580: return "SUBDEVICE_15D94580";
        case PciSubDevice808624DB::SUBDEVICE_1734101C: return "SUBDEVICE_1734101C";
        case PciSubDevice808624DB::SUBDEVICE_808624DB: return "SUBDEVICE_808624DB";
        case PciSubDevice808624DB::SUBDEVICE_80863427: return "SUBDEVICE_80863427";
        case PciSubDevice808624DB::SUBDEVICE_80864246: return "SUBDEVICE_80864246";
        case PciSubDevice808624DB::SUBDEVICE_80864C43: return "SUBDEVICE_80864C43";
        case PciSubDevice808624DB::SUBDEVICE_8086524C: return "SUBDEVICE_8086524C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624DB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624DB subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624DB::SUBDEVICE_10140287: return "ThinkCentre S50";
        case PciSubDevice808624DB::SUBDEVICE_101402DD: return "eServer xSeries server mainboard";
        case PciSubDevice808624DB::SUBDEVICE_101402ED: return "eServer xSeries server mainboard";
        case PciSubDevice808624DB::SUBDEVICE_10280168: return "Precision Workstation 670 Mainboard";
        case PciSubDevice808624DB::SUBDEVICE_10280169: return "Precision 470";
        case PciSubDevice808624DB::SUBDEVICE_1028016C: return "PowerEdge 1850 IDE Controller";
        case PciSubDevice808624DB::SUBDEVICE_1028016D: return "PowerEdge 2850 IDE Controller";
        case PciSubDevice808624DB::SUBDEVICE_10280170: return "PowerEdge 6850 IDE Controller";
        case PciSubDevice808624DB::SUBDEVICE_1028019A: return "PowerEdge SC1425";
        case PciSubDevice808624DB::SUBDEVICE_103C006A: return "NX9500";
        case PciSubDevice808624DB::SUBDEVICE_103C12BC: return "d530 CMT (DG746A)";
        case PciSubDevice808624DB::SUBDEVICE_104380A6: return "P4P800/P5P800 series motherboard";
        case PciSubDevice808624DB::SUBDEVICE_145824D2: return "GA-8IPE1000 Pro2 motherboard (865PE)";
        case PciSubDevice808624DB::SUBDEVICE_14627280: return "865PE Neo2 (MS-6728)";
        case PciSubDevice808624DB::SUBDEVICE_14627580: return "MSI 875P";
        case PciSubDevice808624DB::SUBDEVICE_14627650: return "Hetis 865GV-E (MS-7065)";
        case PciSubDevice808624DB::SUBDEVICE_15653101: return "P4TSV Motherboard (865G)";
        case PciSubDevice808624DB::SUBDEVICE_15D94580: return "P4SCE Mainboard";
        case PciSubDevice808624DB::SUBDEVICE_1734101C: return "PRIMERGY RX/TX S2 series onboard IDE";
        case PciSubDevice808624DB::SUBDEVICE_808624DB: return "P4C800 Mainboard";
        case PciSubDevice808624DB::SUBDEVICE_80863427: return "S875WP1-E mainboard";
        case PciSubDevice808624DB::SUBDEVICE_80864246: return "Desktop Board D865GBF";
        case PciSubDevice808624DB::SUBDEVICE_80864C43: return "Desktop Board D865GLC";
        case PciSubDevice808624DB::SUBDEVICE_8086524C: return "D865PERL mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624DB_H
