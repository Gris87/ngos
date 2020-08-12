// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BA_PCIDEVICE10BA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BA_PCIDEVICE10BA_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10BA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0301 = 0x0301,
    DEVICE_0304 = 0x0304,
    DEVICE_0308 = 0x0308,
    DEVICE_1002 = 0x1002
};



inline const char8* enumToString(PciDevice10BA device10BA) // TEST: NO
{
    // COMMON_LT((" | device10BA = %u", device10BA)); // Commented to avoid bad looking logs



    switch (device10BA)
    {
        case PciDevice10BA::NONE:        return "NONE";
        case PciDevice10BA::DEVICE_0301: return "DEVICE_0301";
        case PciDevice10BA::DEVICE_0304: return "DEVICE_0304";
        case PciDevice10BA::DEVICE_0308: return "DEVICE_0308";
        case PciDevice10BA::DEVICE_1002: return "DEVICE_1002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10BA device10BA) // TEST: NO
{
    // COMMON_LT((" | device10BA = %u", device10BA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10BA, enumToString(device10BA));

    return res;
}



inline const char8* enumToHumanString(PciDevice10BA device10BA) // TEST: NO
{
    // COMMON_LT((" | device10BA = %u", device10BA)); // Commented to avoid bad looking logs



    switch (device10BA)
    {
        case PciDevice10BA::DEVICE_0301: return "AccelGraphics AccelECLIPSE";
        case PciDevice10BA::DEVICE_0304: return "AccelGALAXY A2100 [OEM Evans & Sutherland]";
        case PciDevice10BA::DEVICE_0308: return "Tornado 3000 [OEM Evans & Sutherland]";
        case PciDevice10BA::DEVICE_1002: return "VG500 [VolumePro Volume Rendering Accelerator]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10BA_PCIDEVICE10BA_H
