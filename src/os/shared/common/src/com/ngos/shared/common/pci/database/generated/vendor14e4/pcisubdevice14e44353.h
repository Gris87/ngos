// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44353_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44353_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44353: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028000E = 0x1028000E,
    SUBDEVICE_103C1509 = 0x103C1509,
    SUBDEVICE_106B0093 = 0x106B0093,
    SUBDEVICE_106B00D1 = 0x106B00D1,
    SUBDEVICE_106B00E9 = 0x106B00E9,
    SUBDEVICE_14E404D8 = 0x14E404D8
};



inline const char8* enumToString(PciSubDevice14E44353 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44353::NONE:               return "NONE";
        case PciSubDevice14E44353::SUBDEVICE_1028000E: return "SUBDEVICE_1028000E";
        case PciSubDevice14E44353::SUBDEVICE_103C1509: return "SUBDEVICE_103C1509";
        case PciSubDevice14E44353::SUBDEVICE_106B0093: return "SUBDEVICE_106B0093";
        case PciSubDevice14E44353::SUBDEVICE_106B00D1: return "SUBDEVICE_106B00D1";
        case PciSubDevice14E44353::SUBDEVICE_106B00E9: return "SUBDEVICE_106B00E9";
        case PciSubDevice14E44353::SUBDEVICE_14E404D8: return "SUBDEVICE_14E404D8";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44353 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44353 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44353::SUBDEVICE_1028000E: return "Wireless 1520 Half-size Mini PCIe Card";
        case PciSubDevice14E44353::SUBDEVICE_103C1509: return "WMIB-275N Half-size Mini PCIe Card";
        case PciSubDevice14E44353::SUBDEVICE_106B0093: return "AirPort Extreme";
        case PciSubDevice14E44353::SUBDEVICE_106B00D1: return "AirPort Extreme";
        case PciSubDevice14E44353::SUBDEVICE_106B00E9: return "AirPort Extreme";
        case PciSubDevice14E44353::SUBDEVICE_14E404D8: return "Pegatron UPWL6024";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44353_H
