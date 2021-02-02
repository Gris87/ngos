// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44324_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44324_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44324: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280001 = 0x10280001,
    SUBDEVICE_10280002 = 0x10280002,
    SUBDEVICE_10280003 = 0x10280003,
    SUBDEVICE_10280004 = 0x10280004,
    SUBDEVICE_103C12F9 = 0x103C12F9,
    SUBDEVICE_103C12FC = 0x103C12FC
};



inline const char8* enumToString(PciSubDevice14E44324 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44324::NONE:               return "NONE";
        case PciSubDevice14E44324::SUBDEVICE_10280001: return "SUBDEVICE_10280001";
        case PciSubDevice14E44324::SUBDEVICE_10280002: return "SUBDEVICE_10280002";
        case PciSubDevice14E44324::SUBDEVICE_10280003: return "SUBDEVICE_10280003";
        case PciSubDevice14E44324::SUBDEVICE_10280004: return "SUBDEVICE_10280004";
        case PciSubDevice14E44324::SUBDEVICE_103C12F9: return "SUBDEVICE_103C12F9";
        case PciSubDevice14E44324::SUBDEVICE_103C12FC: return "SUBDEVICE_103C12FC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44324 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44324 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44324::SUBDEVICE_10280001: return "Truemobile 1400";
        case PciSubDevice14E44324::SUBDEVICE_10280002: return "TrueMobile 1400 Dual Band WLAN PC Card";
        case PciSubDevice14E44324::SUBDEVICE_10280003: return "Truemobile 1450 MiniPCI";
        case PciSubDevice14E44324::SUBDEVICE_10280004: return "Wireless 1450 Dual Band WLAN PC Card";
        case PciSubDevice14E44324::SUBDEVICE_103C12F9: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44324::SUBDEVICE_103C12FC: return "Broadcom 802.11a/b/g WLAN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44324_H
