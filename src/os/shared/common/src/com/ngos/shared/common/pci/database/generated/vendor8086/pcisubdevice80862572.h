// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862572_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862572_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862572: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140287 = 0x10140287,
    SUBDEVICE_1028019D = 0x1028019D,
    SUBDEVICE_103C12BC = 0x103C12BC,
    SUBDEVICE_104380A5 = 0x104380A5,
    SUBDEVICE_14627650 = 0x14627650,
    SUBDEVICE_1734101B = 0x1734101B,
    SUBDEVICE_80864246 = 0x80864246,
    SUBDEVICE_80864C43 = 0x80864C43
};



inline const char8* enumToString(PciSubDevice80862572 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862572::NONE:               return "NONE";
        case PciSubDevice80862572::SUBDEVICE_10140287: return "SUBDEVICE_10140287";
        case PciSubDevice80862572::SUBDEVICE_1028019D: return "SUBDEVICE_1028019D";
        case PciSubDevice80862572::SUBDEVICE_103C12BC: return "SUBDEVICE_103C12BC";
        case PciSubDevice80862572::SUBDEVICE_104380A5: return "SUBDEVICE_104380A5";
        case PciSubDevice80862572::SUBDEVICE_14627650: return "SUBDEVICE_14627650";
        case PciSubDevice80862572::SUBDEVICE_1734101B: return "SUBDEVICE_1734101B";
        case PciSubDevice80862572::SUBDEVICE_80864246: return "SUBDEVICE_80864246";
        case PciSubDevice80862572::SUBDEVICE_80864C43: return "SUBDEVICE_80864C43";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862572 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862572 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862572::SUBDEVICE_10140287: return "ThinkCentre S50";
        case PciSubDevice80862572::SUBDEVICE_1028019D: return "Dimension 3000";
        case PciSubDevice80862572::SUBDEVICE_103C12BC: return "D530 sff(dc578av)";
        case PciSubDevice80862572::SUBDEVICE_104380A5: return "P5P800-MX Mainboard";
        case PciSubDevice80862572::SUBDEVICE_14627650: return "Hetis 865GV-E (MS-7065)";
        case PciSubDevice80862572::SUBDEVICE_1734101B: return "Fujitsu-Siemens Scenic E300 bad_int865GV";
        case PciSubDevice80862572::SUBDEVICE_80864246: return "Desktop Board D865GBF";
        case PciSubDevice80862572::SUBDEVICE_80864C43: return "Desktop Board D865GLC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862572_H
