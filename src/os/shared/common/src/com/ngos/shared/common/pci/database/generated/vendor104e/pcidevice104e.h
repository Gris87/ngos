// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104E_PCIDEVICE104E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104E_PCIDEVICE104E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice104E: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0017 = 0x0017,
    DEVICE_0107 = 0x0107,
    DEVICE_0109 = 0x0109,
    DEVICE_0111 = 0x0111,
    DEVICE_0217 = 0x0217,
    DEVICE_0317 = 0x0317
};



inline const char8* enumToString(PciDevice104E device104E) // TEST: NO
{
    // COMMON_LT((" | device104E = %u", device104E)); // Commented to avoid bad looking logs



    switch (device104E)
    {
        case PciDevice104E::NONE:        return "NONE";
        case PciDevice104E::DEVICE_0017: return "DEVICE_0017";
        case PciDevice104E::DEVICE_0107: return "DEVICE_0107";
        case PciDevice104E::DEVICE_0109: return "DEVICE_0109";
        case PciDevice104E::DEVICE_0111: return "DEVICE_0111";
        case PciDevice104E::DEVICE_0217: return "DEVICE_0217";
        case PciDevice104E::DEVICE_0317: return "DEVICE_0317";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice104E device104E) // TEST: NO
{
    // COMMON_LT((" | device104E = %u", device104E)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device104E, enumToString(device104E));

    return res;
}



inline const char8* enumToHumanString(PciDevice104E device104E) // TEST: NO
{
    // COMMON_LT((" | device104E = %u", device104E)); // Commented to avoid bad looking logs



    switch (device104E)
    {
        case PciDevice104E::DEVICE_0017: return "OTI-64017";
        case PciDevice104E::DEVICE_0107: return "OTI-107 [Spitfire]";
        case PciDevice104E::DEVICE_0109: return "Video Adapter";
        case PciDevice104E::DEVICE_0111: return "OTI-64111 [Spitfire]";
        case PciDevice104E::DEVICE_0217: return "OTI-64217";
        case PciDevice104E::DEVICE_0317: return "OTI-64317";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104E_PCIDEVICE104E_H
