// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F0_PCIDEVICE11F0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F0_PCIDEVICE11F0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11F0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4231 = 0x4231,
    DEVICE_4232 = 0x4232,
    DEVICE_4233 = 0x4233,
    DEVICE_4234 = 0x4234,
    DEVICE_4235 = 0x4235,
    DEVICE_4236 = 0x4236,
    DEVICE_4731 = 0x4731
};



inline const char8* enumToString(PciDevice11F0 device11F0) // TEST: NO
{
    // COMMON_LT((" | device11F0 = %u", device11F0)); // Commented to avoid bad looking logs



    switch (device11F0)
    {
        case PciDevice11F0::NONE:        return "NONE";
        case PciDevice11F0::DEVICE_4231: return "DEVICE_4231";
        case PciDevice11F0::DEVICE_4232: return "DEVICE_4232";
        case PciDevice11F0::DEVICE_4233: return "DEVICE_4233";
        case PciDevice11F0::DEVICE_4234: return "DEVICE_4234";
        case PciDevice11F0::DEVICE_4235: return "DEVICE_4235";
        case PciDevice11F0::DEVICE_4236: return "DEVICE_4236";
        case PciDevice11F0::DEVICE_4731: return "DEVICE_4731";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11F0 device11F0) // TEST: NO
{
    // COMMON_LT((" | device11F0 = %u", device11F0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device11F0, enumToString(device11F0));

    return res;
}



inline const char8* enumToHumanString(PciDevice11F0 device11F0) // TEST: NO
{
    // COMMON_LT((" | device11F0 = %u", device11F0)); // Commented to avoid bad looking logs



    switch (device11F0)
    {
        case PciDevice11F0::DEVICE_4231: return "FDDI";
        case PciDevice11F0::DEVICE_4232: return "FASTline UTP Quattro";
        case PciDevice11F0::DEVICE_4233: return "FASTline FO";
        case PciDevice11F0::DEVICE_4234: return "FASTline UTP";
        case PciDevice11F0::DEVICE_4235: return "FASTline-II UTP";
        case PciDevice11F0::DEVICE_4236: return "FASTline-II FO";
        case PciDevice11F0::DEVICE_4731: return "GIGAline";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F0_PCIDEVICE11F0_H
