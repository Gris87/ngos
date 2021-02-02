// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44331_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44331_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44331: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_106B00D6 = 0x106B00D6,
    SUBDEVICE_106B00E4 = 0x106B00E4,
    SUBDEVICE_106B00EF = 0x106B00EF,
    SUBDEVICE_106B00F4 = 0x106B00F4,
    SUBDEVICE_106B00F5 = 0x106B00F5,
    SUBDEVICE_106B010E = 0x106B010E,
    SUBDEVICE_106B010F = 0x106B010F
};



inline const char8* enumToString(PciSubDevice14E44331 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44331::NONE:               return "NONE";
        case PciSubDevice14E44331::SUBDEVICE_106B00D6: return "SUBDEVICE_106B00D6";
        case PciSubDevice14E44331::SUBDEVICE_106B00E4: return "SUBDEVICE_106B00E4";
        case PciSubDevice14E44331::SUBDEVICE_106B00EF: return "SUBDEVICE_106B00EF";
        case PciSubDevice14E44331::SUBDEVICE_106B00F4: return "SUBDEVICE_106B00F4";
        case PciSubDevice14E44331::SUBDEVICE_106B00F5: return "SUBDEVICE_106B00F5";
        case PciSubDevice14E44331::SUBDEVICE_106B010E: return "SUBDEVICE_106B010E";
        case PciSubDevice14E44331::SUBDEVICE_106B010F: return "SUBDEVICE_106B010F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44331 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44331 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44331::SUBDEVICE_106B00D6: return "AirPort Extreme";
        case PciSubDevice14E44331::SUBDEVICE_106B00E4: return "AirPort Extreme";
        case PciSubDevice14E44331::SUBDEVICE_106B00EF: return "AirPort Extreme";
        case PciSubDevice14E44331::SUBDEVICE_106B00F4: return "AirPort Extreme";
        case PciSubDevice14E44331::SUBDEVICE_106B00F5: return "AirPort Extreme";
        case PciSubDevice14E44331::SUBDEVICE_106B010E: return "AirPort Extreme";
        case PciSubDevice14E44331::SUBDEVICE_106B010F: return "AirPort Extreme";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44331_H
