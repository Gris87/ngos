// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1067_PCIDEVICE1067_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1067_PCIDEVICE1067_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1067: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0301 = 0x0301,
    DEVICE_0304 = 0x0304,
    DEVICE_0308 = 0x0308,
    DEVICE_1002 = 0x1002
};



inline const char8* enumToString(PciDevice1067 device1067) // TEST: NO
{
    // COMMON_LT((" | device1067 = %u", device1067)); // Commented to avoid bad looking logs



    switch (device1067)
    {
        case PciDevice1067::NONE:        return "NONE";
        case PciDevice1067::DEVICE_0301: return "DEVICE_0301";
        case PciDevice1067::DEVICE_0304: return "DEVICE_0304";
        case PciDevice1067::DEVICE_0308: return "DEVICE_0308";
        case PciDevice1067::DEVICE_1002: return "DEVICE_1002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1067 device1067) // TEST: NO
{
    // COMMON_LT((" | device1067 = %u", device1067)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1067, enumToString(device1067));

    return res;
}



inline const char8* enumToHumanString(PciDevice1067 device1067) // TEST: NO
{
    // COMMON_LT((" | device1067 = %u", device1067)); // Commented to avoid bad looking logs



    switch (device1067)
    {
        case PciDevice1067::DEVICE_0301: return "AccelGraphics AccelECLIPSE";
        case PciDevice1067::DEVICE_0304: return "AccelGALAXY A2100 [OEM Evans & Sutherland]";
        case PciDevice1067::DEVICE_0308: return "Tornado 3000 [OEM Evans & Sutherland]";
        case PciDevice1067::DEVICE_1002: return "VG500 [VolumePro Volume Rendering Accelerator]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1067_PCIDEVICE1067_H
