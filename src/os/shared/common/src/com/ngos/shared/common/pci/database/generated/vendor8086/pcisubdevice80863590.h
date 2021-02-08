// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863590_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863590_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863590: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101402DD = 0x101402DD,
    SUBDEVICE_1028016C = 0x1028016C,
    SUBDEVICE_1028016D = 0x1028016D,
    SUBDEVICE_1028019A = 0x1028019A,
    SUBDEVICE_1734103E = 0x1734103E,
    SUBDEVICE_17751100 = 0x17751100,
    SUBDEVICE_4C5310D0 = 0x4C5310D0
};



inline const char8* enumToString(PciSubDevice80863590 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863590::NONE:               return "NONE";
        case PciSubDevice80863590::SUBDEVICE_101402DD: return "SUBDEVICE_101402DD";
        case PciSubDevice80863590::SUBDEVICE_1028016C: return "SUBDEVICE_1028016C";
        case PciSubDevice80863590::SUBDEVICE_1028016D: return "SUBDEVICE_1028016D";
        case PciSubDevice80863590::SUBDEVICE_1028019A: return "SUBDEVICE_1028019A";
        case PciSubDevice80863590::SUBDEVICE_1734103E: return "SUBDEVICE_1734103E";
        case PciSubDevice80863590::SUBDEVICE_17751100: return "SUBDEVICE_17751100";
        case PciSubDevice80863590::SUBDEVICE_4C5310D0: return "SUBDEVICE_4C5310D0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863590 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863590 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863590::SUBDEVICE_101402DD: return "eServer xSeries server mainboard";
        case PciSubDevice80863590::SUBDEVICE_1028016C: return "PowerEdge 1850 Memory Controller Hub";
        case PciSubDevice80863590::SUBDEVICE_1028016D: return "PowerEdge 2850 Memory Controller Hub";
        case PciSubDevice80863590::SUBDEVICE_1028019A: return "PowerEdge SC1425";
        case PciSubDevice80863590::SUBDEVICE_1734103E: return "PRIMERGY RX/TX S2 series";
        case PciSubDevice80863590::SUBDEVICE_17751100: return "CR11/VR11 Single Board Computer";
        case PciSubDevice80863590::SUBDEVICE_4C5310D0: return "Telum ASLP10 Processor AMC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863590_H
