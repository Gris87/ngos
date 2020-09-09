// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861537_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861537_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861537: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10590110 = 0x10590110,
    SUBDEVICE_10590111 = 0x10590111,
    SUBDEVICE_10590120 = 0x10590120,
    SUBDEVICE_10590130 = 0x10590130,
    SUBDEVICE_10590140 = 0x10590140,
    SUBDEVICE_10590150 = 0x10590150,
    SUBDEVICE_10590170 = 0x10590170
};



inline const char8* enumToString(PciSubDevice80861537 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861537::NONE:               return "NONE";
        case PciSubDevice80861537::SUBDEVICE_10590110: return "SUBDEVICE_10590110";
        case PciSubDevice80861537::SUBDEVICE_10590111: return "SUBDEVICE_10590111";
        case PciSubDevice80861537::SUBDEVICE_10590120: return "SUBDEVICE_10590120";
        case PciSubDevice80861537::SUBDEVICE_10590130: return "SUBDEVICE_10590130";
        case PciSubDevice80861537::SUBDEVICE_10590140: return "SUBDEVICE_10590140";
        case PciSubDevice80861537::SUBDEVICE_10590150: return "SUBDEVICE_10590150";
        case PciSubDevice80861537::SUBDEVICE_10590170: return "SUBDEVICE_10590170";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861537 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861537 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861537::SUBDEVICE_10590110: return "T4005 1GbE interface";
        case PciSubDevice80861537::SUBDEVICE_10590111: return "T4007 1GbE interface";
        case PciSubDevice80861537::SUBDEVICE_10590120: return "T4008 1GbE interface";
        case PciSubDevice80861537::SUBDEVICE_10590130: return "T4009 1GbE interface";
        case PciSubDevice80861537::SUBDEVICE_10590140: return "T2035 1GbE interface";
        case PciSubDevice80861537::SUBDEVICE_10590150: return "RD-01068 1GbE interface";
        case PciSubDevice80861537::SUBDEVICE_10590170: return "RD-01213 10GbE interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861537_H
