// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR187E_PCIDEVICE187E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR187E_PCIDEVICE187E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice187E: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3403 = 0x3403,
    DEVICE_340E = 0x340E
};



inline const char8* enumToString(PciDevice187E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice187E::NONE:        return "NONE";
        case PciDevice187E::DEVICE_3403: return "DEVICE_3403";
        case PciDevice187E::DEVICE_340E: return "DEVICE_340E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice187E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice187E device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice187E::DEVICE_3403: return "ZyAir G-110 802.11g";
        case PciDevice187E::DEVICE_340E: return "M-302 802.11g XtremeMIMO";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR187E_PCIDEVICE187E_H
