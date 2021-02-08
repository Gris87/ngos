// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370042_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370042_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11370042: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11370047 = 0x11370047,
    SUBDEVICE_11370085 = 0x11370085,
    SUBDEVICE_113700CD = 0x113700CD,
    SUBDEVICE_113700CE = 0x113700CE,
    SUBDEVICE_1137012E = 0x1137012E,
    SUBDEVICE_1137014D = 0x1137014D,
    SUBDEVICE_11370217 = 0x11370217,
    SUBDEVICE_11370218 = 0x11370218
};



inline const char8* enumToString(PciSubDevice11370042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11370042::NONE:               return "NONE";
        case PciSubDevice11370042::SUBDEVICE_11370047: return "SUBDEVICE_11370047";
        case PciSubDevice11370042::SUBDEVICE_11370085: return "SUBDEVICE_11370085";
        case PciSubDevice11370042::SUBDEVICE_113700CD: return "SUBDEVICE_113700CD";
        case PciSubDevice11370042::SUBDEVICE_113700CE: return "SUBDEVICE_113700CE";
        case PciSubDevice11370042::SUBDEVICE_1137012E: return "SUBDEVICE_1137012E";
        case PciSubDevice11370042::SUBDEVICE_1137014D: return "SUBDEVICE_1137014D";
        case PciSubDevice11370042::SUBDEVICE_11370217: return "SUBDEVICE_11370217";
        case PciSubDevice11370042::SUBDEVICE_11370218: return "SUBDEVICE_11370218";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11370042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11370042 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11370042::SUBDEVICE_11370047: return "VIC P81E PCIe Management Controller";
        case PciSubDevice11370042::SUBDEVICE_11370085: return "VIC 1225 PCIe Management Controller";
        case PciSubDevice11370042::SUBDEVICE_113700CD: return "VIC 1285 PCIe Management Controller";
        case PciSubDevice11370042::SUBDEVICE_113700CE: return "VIC 1225T PCIe Management Controller";
        case PciSubDevice11370042::SUBDEVICE_1137012E: return "VIC 1227 PCIe Management Controller";
        case PciSubDevice11370042::SUBDEVICE_1137014D: return "VIC 1385 PCIe Management Controller";
        case PciSubDevice11370042::SUBDEVICE_11370217: return "VIC 1455 PCIe Management Controller";
        case PciSubDevice11370042::SUBDEVICE_11370218: return "VIC 1457 PCIe Management Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE11370042_H
