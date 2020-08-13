// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18AC_PCIDEVICE18AC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18AC_PCIDEVICE18AC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18AC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_D500 = 0xD500,
    DEVICE_D800 = 0xD800,
    DEVICE_D810 = 0xD810,
    DEVICE_D820 = 0xD820,
    DEVICE_DB30 = 0xDB30,
    DEVICE_DB40 = 0xDB40,
    DEVICE_DB78 = 0xDB78
};



inline const char8* enumToString(PciDevice18AC device18AC) // TEST: NO
{
    // COMMON_LT((" | device18AC = %u", device18AC)); // Commented to avoid bad looking logs



    switch (device18AC)
    {
        case PciDevice18AC::NONE:        return "NONE";
        case PciDevice18AC::DEVICE_D500: return "DEVICE_D500";
        case PciDevice18AC::DEVICE_D800: return "DEVICE_D800";
        case PciDevice18AC::DEVICE_D810: return "DEVICE_D810";
        case PciDevice18AC::DEVICE_D820: return "DEVICE_D820";
        case PciDevice18AC::DEVICE_DB30: return "DEVICE_DB30";
        case PciDevice18AC::DEVICE_DB40: return "DEVICE_DB40";
        case PciDevice18AC::DEVICE_DB78: return "DEVICE_DB78";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18AC device18AC) // TEST: NO
{
    // COMMON_LT((" | device18AC = %u", device18AC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device18AC, enumToString(device18AC));

    return res;
}



inline const char8* enumToHumanString(PciDevice18AC device18AC) // TEST: NO
{
    // COMMON_LT((" | device18AC = %u", device18AC)); // Commented to avoid bad looking logs



    switch (device18AC)
    {
        case PciDevice18AC::DEVICE_D500: return "FusionHDTV 5";
        case PciDevice18AC::DEVICE_D800: return "FusionHDTV 3 Gold";
        case PciDevice18AC::DEVICE_D810: return "FusionHDTV 3 Gold-Q";
        case PciDevice18AC::DEVICE_D820: return "FusionHDTV 3 Gold-T";
        case PciDevice18AC::DEVICE_DB30: return "FusionHDTV DVB-T Pro";
        case PciDevice18AC::DEVICE_DB40: return "FusionHDTV DVB-T Hybrid";
        case PciDevice18AC::DEVICE_DB78: return "FusionHDTV DVB-T Dual Express";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18AC_PCIDEVICE18AC_H
