// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100E_PCIDEVICE100E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100E_PCIDEVICE100E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice100E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_9000 = 0x9000,
    DEVICE_9001 = 0x9001,
    DEVICE_9002 = 0x9002,
    DEVICE_9100 = 0x9100
};



inline const char8* enumToString(PciDevice100E device100E) // TEST: NO
{
    // COMMON_LT((" | device100E = %u", device100E)); // Commented to avoid bad looking logs



    switch (device100E)
    {
        case PciDevice100E::NONE:        return "NONE";
        case PciDevice100E::DEVICE_9000: return "DEVICE_9000";
        case PciDevice100E::DEVICE_9001: return "DEVICE_9001";
        case PciDevice100E::DEVICE_9002: return "DEVICE_9002";
        case PciDevice100E::DEVICE_9100: return "DEVICE_9100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice100E device100E) // TEST: NO
{
    // COMMON_LT((" | device100E = %u", device100E)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device100E, enumToString(device100E));

    return res;
}



inline const char8* enumToHumanString(PciDevice100E device100E) // TEST: NO
{
    // COMMON_LT((" | device100E = %u", device100E)); // Commented to avoid bad looking logs



    switch (device100E)
    {
        case PciDevice100E::DEVICE_9000: return "P9000 Viper";
        case PciDevice100E::DEVICE_9001: return "P9000 Viper";
        case PciDevice100E::DEVICE_9002: return "P9000 Viper";
        case PciDevice100E::DEVICE_9100: return "P9100 Viper Pro/SE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100E_PCIDEVICE100E_H
