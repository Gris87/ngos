// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCIDEVICE10C8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCIDEVICE10C8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10C8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0016 = 0x0016,
    DEVICE_0025 = 0x0025,
    DEVICE_0083 = 0x0083,
    DEVICE_8005 = 0x8005,
    DEVICE_8006 = 0x8006,
    DEVICE_8016 = 0x8016
};



inline const char8* enumToString(PciDevice10C8 device10C8) // TEST: NO
{
    // COMMON_LT((" | device10C8 = %u", device10C8)); // Commented to avoid bad looking logs



    switch (device10C8)
    {
        case PciDevice10C8::NONE:        return "NONE";
        case PciDevice10C8::DEVICE_0001: return "DEVICE_0001";
        case PciDevice10C8::DEVICE_0002: return "DEVICE_0002";
        case PciDevice10C8::DEVICE_0003: return "DEVICE_0003";
        case PciDevice10C8::DEVICE_0004: return "DEVICE_0004";
        case PciDevice10C8::DEVICE_0005: return "DEVICE_0005";
        case PciDevice10C8::DEVICE_0006: return "DEVICE_0006";
        case PciDevice10C8::DEVICE_0016: return "DEVICE_0016";
        case PciDevice10C8::DEVICE_0025: return "DEVICE_0025";
        case PciDevice10C8::DEVICE_0083: return "DEVICE_0083";
        case PciDevice10C8::DEVICE_8005: return "DEVICE_8005";
        case PciDevice10C8::DEVICE_8006: return "DEVICE_8006";
        case PciDevice10C8::DEVICE_8016: return "DEVICE_8016";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10C8 device10C8) // TEST: NO
{
    // COMMON_LT((" | device10C8 = %u", device10C8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10C8, enumToString(device10C8));

    return res;
}



inline const char8* enumToHumanString(PciDevice10C8 device10C8) // TEST: NO
{
    // COMMON_LT((" | device10C8 = %u", device10C8)); // Commented to avoid bad looking logs



    switch (device10C8)
    {
        case PciDevice10C8::DEVICE_0001: return "NM2070 [MagicGraph 128]";
        case PciDevice10C8::DEVICE_0002: return "NM2090 [MagicGraph 128V]";
        case PciDevice10C8::DEVICE_0003: return "NM2093 [MagicGraph 128ZV]";
        case PciDevice10C8::DEVICE_0004: return "NM2160 [MagicGraph 128XD]";
        case PciDevice10C8::DEVICE_0005: return "NM2200 [MagicGraph 256AV]";
        case PciDevice10C8::DEVICE_0006: return "NM2360 [MagicMedia 256ZX]";
        case PciDevice10C8::DEVICE_0016: return "NM2380 [MagicMedia 256XL+]";
        case PciDevice10C8::DEVICE_0025: return "NM2230 [MagicGraph 256AV+]";
        case PciDevice10C8::DEVICE_0083: return "NM2093 [MagicGraph 128ZV+]";
        case PciDevice10C8::DEVICE_8005: return "NM2200 [MagicMedia 256AV Audio]";
        case PciDevice10C8::DEVICE_8006: return "NM2360 [MagicMedia 256ZX Audio]";
        case PciDevice10C8::DEVICE_8016: return "NM2380 [MagicMedia 256XL+ Audio]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10C8_PCIDEVICE10C8_H
