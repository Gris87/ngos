// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44319_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44319_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E44319: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280005 = 0x10280005,
    SUBDEVICE_10280006 = 0x10280006,
    SUBDEVICE_103C1358 = 0x103C1358,
    SUBDEVICE_103C1359 = 0x103C1359,
    SUBDEVICE_103C135A = 0x103C135A
};



inline const char8* enumToString(PciSubDevice14E44319 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44319::NONE:               return "NONE";
        case PciSubDevice14E44319::SUBDEVICE_10280005: return "SUBDEVICE_10280005";
        case PciSubDevice14E44319::SUBDEVICE_10280006: return "SUBDEVICE_10280006";
        case PciSubDevice14E44319::SUBDEVICE_103C1358: return "SUBDEVICE_103C1358";
        case PciSubDevice14E44319::SUBDEVICE_103C1359: return "SUBDEVICE_103C1359";
        case PciSubDevice14E44319::SUBDEVICE_103C135A: return "SUBDEVICE_103C135A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E44319 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E44319 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E44319::SUBDEVICE_10280005: return "Wireless 1470 Dual Band WLAN Mini-PCI Card";
        case PciSubDevice14E44319::SUBDEVICE_10280006: return "Wireless 1470 Dual Band WLAN PC Card";
        case PciSubDevice14E44319::SUBDEVICE_103C1358: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44319::SUBDEVICE_103C1359: return "Broadcom 802.11a/b/g WLAN";
        case PciSubDevice14E44319::SUBDEVICE_103C135A: return "Broadcom 802.11a/b/g WLAN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E44319_H
