// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E44_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E44_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024E44: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1002515E = 0x1002515E,
    SUBDEVICE_10025965 = 0x10025965
};



inline const char8* enumToString(PciSubDevice10024E44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024E44::NONE:               return "NONE";
        case PciSubDevice10024E44::SUBDEVICE_1002515E: return "SUBDEVICE_1002515E";
        case PciSubDevice10024E44::SUBDEVICE_10025965: return "SUBDEVICE_10025965";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024E44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024E44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024E44::SUBDEVICE_1002515E: return "Radeon ES1000";
        case PciSubDevice10024E44::SUBDEVICE_10025965: return "Radeon ES1000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024E44_H
