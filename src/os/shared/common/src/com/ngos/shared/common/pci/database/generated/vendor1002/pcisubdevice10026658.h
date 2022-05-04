// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026658_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026658_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026658: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1043048F = 0x1043048F,
    SUBDEVICE_104304D3 = 0x104304D3,
    SUBDEVICE_1458227B = 0x1458227B,
    SUBDEVICE_148C0907 = 0x148C0907,
    SUBDEVICE_16820907 = 0x16820907,
    SUBDEVICE_16827360 = 0x16827360
};



inline const char8* enumToString(PciSubDevice10026658 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026658::NONE:               return "NONE";
        case PciSubDevice10026658::SUBDEVICE_1043048F: return "SUBDEVICE_1043048F";
        case PciSubDevice10026658::SUBDEVICE_104304D3: return "SUBDEVICE_104304D3";
        case PciSubDevice10026658::SUBDEVICE_1458227B: return "SUBDEVICE_1458227B";
        case PciSubDevice10026658::SUBDEVICE_148C0907: return "SUBDEVICE_148C0907";
        case PciSubDevice10026658::SUBDEVICE_16820907: return "SUBDEVICE_16820907";
        case PciSubDevice10026658::SUBDEVICE_16827360: return "SUBDEVICE_16827360";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026658 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026658 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026658::SUBDEVICE_1043048F: return "R7260X-DC2OC-2GD5";
        case PciSubDevice10026658::SUBDEVICE_104304D3: return "AMD Radeon R7 260X";
        case PciSubDevice10026658::SUBDEVICE_1458227B: return "Radeon R7 260X";
        case PciSubDevice10026658::SUBDEVICE_148C0907: return "Radeon R7 360";
        case PciSubDevice10026658::SUBDEVICE_16820907: return "Radeon R7 360";
        case PciSubDevice10026658::SUBDEVICE_16827360: return "Radeon R7 360";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026658_H
