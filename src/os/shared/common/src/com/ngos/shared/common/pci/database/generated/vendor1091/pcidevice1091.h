// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1091_PCIDEVICE1091_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1091_PCIDEVICE1091_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1091: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0060 = 0x0060,
    DEVICE_00E4 = 0x00E4,
    DEVICE_0720 = 0x0720,
    DEVICE_0780 = 0x0780,
    DEVICE_07A0 = 0x07A0,
    DEVICE_1091 = 0x1091
};



inline const char8* enumToString(PciDevice1091 device1091) // TEST: NO
{
    // COMMON_LT((" | device1091 = %u", device1091)); // Commented to avoid bad looking logs



    switch (device1091)
    {
        case PciDevice1091::NONE:        return "NONE";
        case PciDevice1091::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1091::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1091::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1091::DEVICE_0041: return "DEVICE_0041";
        case PciDevice1091::DEVICE_0060: return "DEVICE_0060";
        case PciDevice1091::DEVICE_00E4: return "DEVICE_00E4";
        case PciDevice1091::DEVICE_0720: return "DEVICE_0720";
        case PciDevice1091::DEVICE_0780: return "DEVICE_0780";
        case PciDevice1091::DEVICE_07A0: return "DEVICE_07A0";
        case PciDevice1091::DEVICE_1091: return "DEVICE_1091";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1091 device1091) // TEST: NO
{
    // COMMON_LT((" | device1091 = %u", device1091)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1091, enumToString(device1091));

    return res;
}



inline const char8* enumToHumanString(PciDevice1091 device1091) // TEST: NO
{
    // COMMON_LT((" | device1091 = %u", device1091)); // Commented to avoid bad looking logs



    switch (device1091)
    {
        case PciDevice1091::DEVICE_0020: return "3D graphics processor";
        case PciDevice1091::DEVICE_0021: return "3D graphics processor w/Texturing";
        case PciDevice1091::DEVICE_0040: return "3D graphics frame buffer";
        case PciDevice1091::DEVICE_0041: return "3D graphics frame buffer";
        case PciDevice1091::DEVICE_0060: return "Proprietary bus bridge";
        case PciDevice1091::DEVICE_00E4: return "Powerstorm 4D50T";
        case PciDevice1091::DEVICE_0720: return "Motion JPEG codec";
        case PciDevice1091::DEVICE_0780: return "Intense3D Wildcat 3410 (MSMT496)";
        case PciDevice1091::DEVICE_07A0: return "Sun Expert3D-Lite Graphics Accelerator";
        case PciDevice1091::DEVICE_1091: return "Sun Expert3D Graphics Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1091_PCIDEVICE1091_H
