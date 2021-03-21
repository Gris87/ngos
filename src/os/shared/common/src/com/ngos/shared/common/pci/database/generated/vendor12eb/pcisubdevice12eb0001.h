// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12EB0001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00000300 = 0x00000300,
    SUBDEVICE_104D8036 = 0x104D8036,
    SUBDEVICE_10922000 = 0x10922000,
    SUBDEVICE_10922100 = 0x10922100,
    SUBDEVICE_10922110 = 0x10922110,
    SUBDEVICE_10922200 = 0x10922200,
    SUBDEVICE_122D1002 = 0x122D1002,
    SUBDEVICE_12EB0001 = 0x12EB0001,
    SUBDEVICE_50533355 = 0x50533355,
    SUBDEVICE_50B21111 = 0x50B21111
};



inline const char8* enumToString(PciSubDevice12EB0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12EB0001::NONE:               return "NONE";
        case PciSubDevice12EB0001::SUBDEVICE_00000300: return "SUBDEVICE_00000300";
        case PciSubDevice12EB0001::SUBDEVICE_104D8036: return "SUBDEVICE_104D8036";
        case PciSubDevice12EB0001::SUBDEVICE_10922000: return "SUBDEVICE_10922000";
        case PciSubDevice12EB0001::SUBDEVICE_10922100: return "SUBDEVICE_10922100";
        case PciSubDevice12EB0001::SUBDEVICE_10922110: return "SUBDEVICE_10922110";
        case PciSubDevice12EB0001::SUBDEVICE_10922200: return "SUBDEVICE_10922200";
        case PciSubDevice12EB0001::SUBDEVICE_122D1002: return "SUBDEVICE_122D1002";
        case PciSubDevice12EB0001::SUBDEVICE_12EB0001: return "SUBDEVICE_12EB0001";
        case PciSubDevice12EB0001::SUBDEVICE_50533355: return "SUBDEVICE_50533355";
        case PciSubDevice12EB0001::SUBDEVICE_50B21111: return "SUBDEVICE_50B21111";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12EB0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12EB0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12EB0001::SUBDEVICE_00000300: return "Terasound A3D PCI";
        case PciSubDevice12EB0001::SUBDEVICE_104D8036: return "AU8820 Vortex Digital Audio Processor";
        case PciSubDevice12EB0001::SUBDEVICE_10922000: return "Sonic Impact A3D";
        case PciSubDevice12EB0001::SUBDEVICE_10922100: return "Sonic Impact A3D";
        case PciSubDevice12EB0001::SUBDEVICE_10922110: return "Sonic Impact A3D";
        case PciSubDevice12EB0001::SUBDEVICE_10922200: return "Sonic Impact A3D";
        case PciSubDevice12EB0001::SUBDEVICE_122D1002: return "SC 338-A3D";
        case PciSubDevice12EB0001::SUBDEVICE_12EB0001: return "AU8820 Vortex Digital Audio Processor";
        case PciSubDevice12EB0001::SUBDEVICE_50533355: return "Montego";
        case PciSubDevice12EB0001::SUBDEVICE_50B21111: return "XLerate";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12EB_PCISUBDEVICE12EB0001_H
