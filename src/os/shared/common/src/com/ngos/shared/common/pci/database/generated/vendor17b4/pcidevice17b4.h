// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17B4_PCIDEVICE17B4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17B4_PCIDEVICE17B4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17B4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0015 = 0x0015,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017
};



inline const char8* enumToString(PciDevice17B4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17B4::NONE:        return "NONE";
        case PciDevice17B4::DEVICE_0011: return "DEVICE_0011";
        case PciDevice17B4::DEVICE_0012: return "DEVICE_0012";
        case PciDevice17B4::DEVICE_0015: return "DEVICE_0015";
        case PciDevice17B4::DEVICE_0016: return "DEVICE_0016";
        case PciDevice17B4::DEVICE_0017: return "DEVICE_0017";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17B4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice17B4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice17B4::DEVICE_0011: return "WebEnhance 100 GZIP Compression Card";
        case PciDevice17B4::DEVICE_0012: return "WebEnhance 200 GZIP Compression Card";
        case PciDevice17B4::DEVICE_0015: return "WebEnhance 300 GZIP Compression Card";
        case PciDevice17B4::DEVICE_0016: return "StorCompress 300 GZIP Compression Card";
        case PciDevice17B4::DEVICE_0017: return "StorSecure 300 GZIP Compression and AES Encryption Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17B4_PCIDEVICE17B4_H
