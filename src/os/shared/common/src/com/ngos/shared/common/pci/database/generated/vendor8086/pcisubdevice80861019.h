// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861019_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861019_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861019: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14581019 = 0x14581019,
    SUBDEVICE_1458E000 = 0x1458E000,
    SUBDEVICE_80861019 = 0x80861019,
    SUBDEVICE_8086301F = 0x8086301F,
    SUBDEVICE_80863025 = 0x80863025,
    SUBDEVICE_8086302C = 0x8086302C,
    SUBDEVICE_80863427 = 0x80863427
};



inline const char8* enumToString(PciSubDevice80861019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861019::NONE:               return "NONE";
        case PciSubDevice80861019::SUBDEVICE_14581019: return "SUBDEVICE_14581019";
        case PciSubDevice80861019::SUBDEVICE_1458E000: return "SUBDEVICE_1458E000";
        case PciSubDevice80861019::SUBDEVICE_80861019: return "SUBDEVICE_80861019";
        case PciSubDevice80861019::SUBDEVICE_8086301F: return "SUBDEVICE_8086301F";
        case PciSubDevice80861019::SUBDEVICE_80863025: return "SUBDEVICE_80863025";
        case PciSubDevice80861019::SUBDEVICE_8086302C: return "SUBDEVICE_8086302C";
        case PciSubDevice80861019::SUBDEVICE_80863427: return "SUBDEVICE_80863427";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861019::SUBDEVICE_14581019: return "GA-8IPE1000 Pro2 motherboard (865PE)";
        case PciSubDevice80861019::SUBDEVICE_1458E000: return "Intel Gigabit Ethernet (Kenai II)";
        case PciSubDevice80861019::SUBDEVICE_80861019: return "PRO/1000 CT Desktop Connection";
        case PciSubDevice80861019::SUBDEVICE_8086301F: return "D865PERL mainboard";
        case PciSubDevice80861019::SUBDEVICE_80863025: return "D875PBZ motherboard";
        case PciSubDevice80861019::SUBDEVICE_8086302C: return "D865GBF Mainboard";
        case PciSubDevice80861019::SUBDEVICE_80863427: return "S875WP1-E mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861019_H
