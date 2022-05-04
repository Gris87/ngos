// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6766_PCIDEVICE6766_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6766_PCIDEVICE6766_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice6766: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3D00 = 0x3D00,
    DEVICE_3D02 = 0x3D02,
    DEVICE_3D03 = 0x3D03,
    DEVICE_3D04 = 0x3D04,
    DEVICE_3D40 = 0x3D40,
    DEVICE_3D41 = 0x3D41
};



inline const char8* enumToString(PciDevice6766 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice6766::NONE:        return "NONE";
        case PciDevice6766::DEVICE_3D00: return "DEVICE_3D00";
        case PciDevice6766::DEVICE_3D02: return "DEVICE_3D02";
        case PciDevice6766::DEVICE_3D03: return "DEVICE_3D03";
        case PciDevice6766::DEVICE_3D04: return "DEVICE_3D04";
        case PciDevice6766::DEVICE_3D40: return "DEVICE_3D40";
        case PciDevice6766::DEVICE_3D41: return "DEVICE_3D41";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice6766 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice6766 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice6766::DEVICE_3D00: return "Arise-GT-10C0";
        case PciDevice6766::DEVICE_3D02: return "Arise 1020";
        case PciDevice6766::DEVICE_3D03: return "Arise-GT-1040";
        case PciDevice6766::DEVICE_3D04: return "Arise1010";
        case PciDevice6766::DEVICE_3D40: return "Arise-GT-10C0 High Definition Audio Controller";
        case PciDevice6766::DEVICE_3D41: return "Arise 1020 High Definition Audio Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6766_PCIDEVICE6766_H
