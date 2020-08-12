// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C5_PCIDEVICE12C5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C5_PCIDEVICE12C5_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12C5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_007E = 0x007E,
    DEVICE_007F = 0x007F,
    DEVICE_0081 = 0x0081,
    DEVICE_0085 = 0x0085,
    DEVICE_0086 = 0x0086
};



inline const char8* enumToString(PciDevice12C5 device12C5) // TEST: NO
{
    // COMMON_LT((" | device12C5 = %u", device12C5)); // Commented to avoid bad looking logs



    switch (device12C5)
    {
        case PciDevice12C5::NONE:        return "NONE";
        case PciDevice12C5::DEVICE_007E: return "DEVICE_007E";
        case PciDevice12C5::DEVICE_007F: return "DEVICE_007F";
        case PciDevice12C5::DEVICE_0081: return "DEVICE_0081";
        case PciDevice12C5::DEVICE_0085: return "DEVICE_0085";
        case PciDevice12C5::DEVICE_0086: return "DEVICE_0086";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12C5 device12C5) // TEST: NO
{
    // COMMON_LT((" | device12C5 = %u", device12C5)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12C5, enumToString(device12C5));

    return res;
}



inline const char8* enumToHumanString(PciDevice12C5 device12C5) // TEST: NO
{
    // COMMON_LT((" | device12C5 = %u", device12C5)); // Commented to avoid bad looking logs



    switch (device12C5)
    {
        case PciDevice12C5::DEVICE_007E: return "Imaging/Scanning Subsystem Engine";
        case PciDevice12C5::DEVICE_007F: return "Imaging/Scanning Subsystem Engine";
        case PciDevice12C5::DEVICE_0081: return "PCIVST [Grayscale Thresholding Engine]";
        case PciDevice12C5::DEVICE_0085: return "Video Simulator/Sender";
        case PciDevice12C5::DEVICE_0086: return "THR2 Multi-scale Thresholder";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12C5_PCIDEVICE12C5_H
