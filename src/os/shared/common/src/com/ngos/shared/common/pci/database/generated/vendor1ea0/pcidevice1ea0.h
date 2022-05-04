// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EA0_PCIDEVICE1EA0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EA0_PCIDEVICE1EA0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1EA0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2A16 = 0x2A16,
    DEVICE_2A18 = 0x2A18
};



inline const char8* enumToString(PciDevice1EA0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EA0::NONE:        return "NONE";
        case PciDevice1EA0::DEVICE_2A16: return "DEVICE_2A16";
        case PciDevice1EA0::DEVICE_2A18: return "DEVICE_2A18";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1EA0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1EA0 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1EA0::DEVICE_2A16: return "Cloud Intelligent Inference Controller";
        case PciDevice1EA0::DEVICE_2A18: return "Video Transcode Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1EA0_PCIDEVICE1EA0_H
