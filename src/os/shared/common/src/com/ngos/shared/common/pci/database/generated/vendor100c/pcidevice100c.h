// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100C_PCIDEVICE100C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100C_PCIDEVICE100C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice100C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3202 = 0x3202,
    DEVICE_3205 = 0x3205,
    DEVICE_3206 = 0x3206,
    DEVICE_3207 = 0x3207,
    DEVICE_3208 = 0x3208,
    DEVICE_4702 = 0x4702
};



inline const char8* enumToString(PciDevice100C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice100C::NONE:        return "NONE";
        case PciDevice100C::DEVICE_3202: return "DEVICE_3202";
        case PciDevice100C::DEVICE_3205: return "DEVICE_3205";
        case PciDevice100C::DEVICE_3206: return "DEVICE_3206";
        case PciDevice100C::DEVICE_3207: return "DEVICE_3207";
        case PciDevice100C::DEVICE_3208: return "DEVICE_3208";
        case PciDevice100C::DEVICE_4702: return "DEVICE_4702";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice100C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice100C device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice100C::DEVICE_3202: return "ET4000/W32p rev A";
        case PciDevice100C::DEVICE_3205: return "ET4000/W32p rev B";
        case PciDevice100C::DEVICE_3206: return "ET4000/W32p rev C";
        case PciDevice100C::DEVICE_3207: return "ET4000/W32p rev D";
        case PciDevice100C::DEVICE_3208: return "ET6000";
        case PciDevice100C::DEVICE_4702: return "ET6300";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100C_PCIDEVICE100C_H
