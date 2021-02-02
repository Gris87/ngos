// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44301_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44301_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44301: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280407 = 0x10280407,
    SUBDEVICE_10430120 = 0x10430120,
    SUBDEVICE_16A51602 = 0x16A51602,
    SUBDEVICE_17374301 = 0x17374301
};



inline const char8* enumToString(PciSubDevice14E44301 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44301::NONE:               return "NONE";
        case PciSubDevice14E44301::SUBDEVICE_10280407: return "SUBDEVICE_10280407";
        case PciSubDevice14E44301::SUBDEVICE_10430120: return "SUBDEVICE_10430120";
        case PciSubDevice14E44301::SUBDEVICE_16A51602: return "SUBDEVICE_16A51602";
        case PciSubDevice14E44301::SUBDEVICE_17374301: return "SUBDEVICE_17374301";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44301 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44301 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44301::SUBDEVICE_10280407: return "TrueMobile 1180 Onboard WLAN";
        case PciSubDevice14E44301::SUBDEVICE_10430120: return "WL-103b Wireless LAN PC Card";
        case PciSubDevice14E44301::SUBDEVICE_16A51602: return "B-300 802.11b Wireless CardBus Adapter";
        case PciSubDevice14E44301::SUBDEVICE_17374301: return "WMP11 v2.7 802.11b Wireless-B PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44301_H
