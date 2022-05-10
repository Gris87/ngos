// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F2200_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F2200_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1F3F2200: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1F3F0185 = 0x1F3F0185,
    SUBDEVICE_1F3F01A1 = 0x1F3F01A1,
    SUBDEVICE_1F3F01A4 = 0x1F3F01A4,
    SUBDEVICE_1F3F01A8 = 0x1F3F01A8,
    SUBDEVICE_1F3F01AD = 0x1F3F01AD
};



inline const char8* enumToString(PciSubDevice1F3F2200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F2200::NONE:               return "NONE";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F0185: return "SUBDEVICE_1F3F0185";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F01A1: return "SUBDEVICE_1F3F01A1";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F01A4: return "SUBDEVICE_1F3F01A4";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F01A8: return "SUBDEVICE_1F3F01A8";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F01AD: return "SUBDEVICE_1F3F01AD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1F3F2200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1F3F2200 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F0185: return "RAID Controller 16 Ports with 2G Cache";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F01A1: return "RAID Controller 40 Ports with 2G Cache";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F01A4: return "RAID Controller 16 Ports with 4G Cache";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F01A8: return "RAID Controller 32 Ports with 4G Cache";
        case PciSubDevice1F3F2200::SUBDEVICE_1F3F01AD: return "RAID Controller 40 Ports with 4G Cache";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F2200_H
