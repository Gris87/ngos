// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280013_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280013_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10280013: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028016C = 0x1028016C,
    SUBDEVICE_1028016D = 0x1028016D,
    SUBDEVICE_1028016E = 0x1028016E,
    SUBDEVICE_1028016F = 0x1028016F,
    SUBDEVICE_10280170 = 0x10280170
};



inline const char8* enumToString(PciSubDevice10280013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10280013::NONE:               return "NONE";
        case PciSubDevice10280013::SUBDEVICE_1028016C: return "SUBDEVICE_1028016C";
        case PciSubDevice10280013::SUBDEVICE_1028016D: return "SUBDEVICE_1028016D";
        case PciSubDevice10280013::SUBDEVICE_1028016E: return "SUBDEVICE_1028016E";
        case PciSubDevice10280013::SUBDEVICE_1028016F: return "SUBDEVICE_1028016F";
        case PciSubDevice10280013::SUBDEVICE_10280170: return "SUBDEVICE_10280170";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10280013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10280013 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10280013::SUBDEVICE_1028016C: return "PowerEdge Expandable RAID Controller 4e/Si";
        case PciSubDevice10280013::SUBDEVICE_1028016D: return "PowerEdge Expandable RAID Controller 4e/Di";
        case PciSubDevice10280013::SUBDEVICE_1028016E: return "PowerEdge Expandable RAID Controller 4e/Di";
        case PciSubDevice10280013::SUBDEVICE_1028016F: return "PowerEdge Expandable RAID Controller 4e/Di";
        case PciSubDevice10280013::SUBDEVICE_10280170: return "PowerEdge Expandable RAID Controller 4e/Di";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280013_H
