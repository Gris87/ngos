// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861043_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861043_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861043: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C08B0 = 0x103C08B0,
    SUBDEVICE_80862522 = 0x80862522,
    SUBDEVICE_80862527 = 0x80862527,
    SUBDEVICE_80862561 = 0x80862561,
    SUBDEVICE_80862581 = 0x80862581
};



inline const char8* enumToString(PciSubDevice80861043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861043::NONE:               return "NONE";
        case PciSubDevice80861043::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";
        case PciSubDevice80861043::SUBDEVICE_80862522: return "SUBDEVICE_80862522";
        case PciSubDevice80861043::SUBDEVICE_80862527: return "SUBDEVICE_80862527";
        case PciSubDevice80861043::SUBDEVICE_80862561: return "SUBDEVICE_80862561";
        case PciSubDevice80861043::SUBDEVICE_80862581: return "SUBDEVICE_80862581";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861043 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861043::SUBDEVICE_103C08B0: return "tc1100 tablet";
        case PciSubDevice80861043::SUBDEVICE_80862522: return "Samsung X10/P30 integrated WLAN";
        case PciSubDevice80861043::SUBDEVICE_80862527: return "MIM2000/Centrino";
        case PciSubDevice80861043::SUBDEVICE_80862561: return "Dell Latitude D800";
        case PciSubDevice80861043::SUBDEVICE_80862581: return "Toshiba Satellite M10";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861043_H
