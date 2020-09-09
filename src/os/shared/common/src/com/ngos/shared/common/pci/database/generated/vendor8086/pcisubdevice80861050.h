// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861050_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861050_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861050: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140287 = 0x10140287,
    SUBDEVICE_1028019D = 0x1028019D,
    SUBDEVICE_1462728C = 0x1462728C,
    SUBDEVICE_1462758C = 0x1462758C,
    SUBDEVICE_80863020 = 0x80863020,
    SUBDEVICE_8086302F = 0x8086302F,
    SUBDEVICE_80863427 = 0x80863427
};



inline const char8* enumToString(PciSubDevice80861050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861050::NONE:               return "NONE";
        case PciSubDevice80861050::SUBDEVICE_10140287: return "SUBDEVICE_10140287";
        case PciSubDevice80861050::SUBDEVICE_1028019D: return "SUBDEVICE_1028019D";
        case PciSubDevice80861050::SUBDEVICE_1462728C: return "SUBDEVICE_1462728C";
        case PciSubDevice80861050::SUBDEVICE_1462758C: return "SUBDEVICE_1462758C";
        case PciSubDevice80861050::SUBDEVICE_80863020: return "SUBDEVICE_80863020";
        case PciSubDevice80861050::SUBDEVICE_8086302F: return "SUBDEVICE_8086302F";
        case PciSubDevice80861050::SUBDEVICE_80863427: return "SUBDEVICE_80863427";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861050::SUBDEVICE_10140287: return "ThinkCentre S50";
        case PciSubDevice80861050::SUBDEVICE_1028019D: return "Dimension 3000";
        case PciSubDevice80861050::SUBDEVICE_1462728C: return "865PE Neo2 (MS-6728)";
        case PciSubDevice80861050::SUBDEVICE_1462758C: return "MS-6758 (875P Neo)";
        case PciSubDevice80861050::SUBDEVICE_80863020: return "D865PERL mainboard";
        case PciSubDevice80861050::SUBDEVICE_8086302F: return "Desktop Board D865GBF";
        case PciSubDevice80861050::SUBDEVICE_80863427: return "S875WP1-E mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861050_H
