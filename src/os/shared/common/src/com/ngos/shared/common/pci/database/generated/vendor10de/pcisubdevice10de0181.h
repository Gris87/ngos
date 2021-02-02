// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0181_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0181_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0181: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438063 = 0x10438063,
    SUBDEVICE_1043806F = 0x1043806F,
    SUBDEVICE_14628880 = 0x14628880,
    SUBDEVICE_14628900 = 0x14628900,
    SUBDEVICE_14629350 = 0x14629350,
    SUBDEVICE_147B8F0D = 0x147B8F0D,
    SUBDEVICE_15541111 = 0x15541111
};



inline const char8* enumToString(PciSubDevice10DE0181 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0181::NONE:               return "NONE";
        case PciSubDevice10DE0181::SUBDEVICE_10438063: return "SUBDEVICE_10438063";
        case PciSubDevice10DE0181::SUBDEVICE_1043806F: return "SUBDEVICE_1043806F";
        case PciSubDevice10DE0181::SUBDEVICE_14628880: return "SUBDEVICE_14628880";
        case PciSubDevice10DE0181::SUBDEVICE_14628900: return "SUBDEVICE_14628900";
        case PciSubDevice10DE0181::SUBDEVICE_14629350: return "SUBDEVICE_14629350";
        case PciSubDevice10DE0181::SUBDEVICE_147B8F0D: return "SUBDEVICE_147B8F0D";
        case PciSubDevice10DE0181::SUBDEVICE_15541111: return "SUBDEVICE_15541111";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0181 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0181 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0181::SUBDEVICE_10438063: return "GeForce4 MX 440 AGP 8X";
        case PciSubDevice10DE0181::SUBDEVICE_1043806F: return "V9180 Magic";
        case PciSubDevice10DE0181::SUBDEVICE_14628880: return "MS-StarForce GeForce4 MX 440 with AGP8X";
        case PciSubDevice10DE0181::SUBDEVICE_14628900: return "MS-8890 GeForce 4 MX440 AGP8X";
        case PciSubDevice10DE0181::SUBDEVICE_14629350: return "MSI GeForce4 MX T8X with AGP8X";
        case PciSubDevice10DE0181::SUBDEVICE_147B8F0D: return "Siluro GF4 MX-8X";
        case PciSubDevice10DE0181::SUBDEVICE_15541111: return "PixelView MVGA-NVG18A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0181_H
