// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB3_PCIDEVICE1BB3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB3_PCIDEVICE1BB3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1BB3: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4304 = 0x4304,
    DEVICE_4309 = 0x4309,
    DEVICE_4310 = 0x4310,
    DEVICE_4E04 = 0x4E04,
    DEVICE_4E09 = 0x4E09,
    DEVICE_4E10 = 0x4E10,
    DEVICE_5304 = 0x5304,
    DEVICE_5308 = 0x5308,
    DEVICE_5310 = 0x5310
};



inline const char8* enumToString(PciDevice1BB3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BB3::NONE:        return "NONE";
        case PciDevice1BB3::DEVICE_4304: return "DEVICE_4304";
        case PciDevice1BB3::DEVICE_4309: return "DEVICE_4309";
        case PciDevice1BB3::DEVICE_4310: return "DEVICE_4310";
        case PciDevice1BB3::DEVICE_4E04: return "DEVICE_4E04";
        case PciDevice1BB3::DEVICE_4E09: return "DEVICE_4E09";
        case PciDevice1BB3::DEVICE_4E10: return "DEVICE_4E10";
        case PciDevice1BB3::DEVICE_5304: return "DEVICE_5304";
        case PciDevice1BB3::DEVICE_5308: return "DEVICE_5308";
        case PciDevice1BB3::DEVICE_5310: return "DEVICE_5310";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1BB3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1BB3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1BB3::DEVICE_4304: return "BC-04120A MPEG4 4 port video encoder / decoder";
        case PciDevice1BB3::DEVICE_4309: return "BC-08240A MPEG4 4 port video encoder / decoder";
        case PciDevice1BB3::DEVICE_4310: return "BC-16480A MPEG4 16 port video encoder / decoder";
        case PciDevice1BB3::DEVICE_4E04: return "BC-04120A 4 port MPEG4 video encoder / decoder";
        case PciDevice1BB3::DEVICE_4E09: return "BC-08240A 8 port MPEG4 video encoder / decoder";
        case PciDevice1BB3::DEVICE_4E10: return "BC-16480A 16 port MPEG4 video encoder / decoder";
        case PciDevice1BB3::DEVICE_5304: return "BC-H04120A 4 port H.264 video and audio encoder / decoder";
        case PciDevice1BB3::DEVICE_5308: return "BC-H08240A 8 port H.264 video and audio encoder / decoder";
        case PciDevice1BB3::DEVICE_5310: return "BC-H16480A 16 port H.264 video and audio encoder / decoder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1BB3_PCIDEVICE1BB3_H
