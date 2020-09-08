// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14A4_PCIDEVICE14A4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14A4_PCIDEVICE14A4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14A4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_22F1 = 0x22F1,
    DEVICE_4318 = 0x4318
};



inline const char8* enumToString(PciDevice14A4 device14A4) // TEST: NO
{
    // COMMON_LT((" | device14A4 = %u", device14A4)); // Commented to avoid bad looking logs



    switch (device14A4)
    {
        case PciDevice14A4::NONE:        return "NONE";
        case PciDevice14A4::DEVICE_22F1: return "DEVICE_22F1";
        case PciDevice14A4::DEVICE_4318: return "DEVICE_4318";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14A4 device14A4) // TEST: NO
{
    // COMMON_LT((" | device14A4 = %u", device14A4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device14A4, enumToString(device14A4));

    return res;
}



inline const char8* enumToHumanString(PciDevice14A4 device14A4) // TEST: NO
{
    // COMMON_LT((" | device14A4 = %u", device14A4)); // Commented to avoid bad looking logs



    switch (device14A4)
    {
        case PciDevice14A4::DEVICE_22F1: return "M8Pe Series NVMe SSD";
        case PciDevice14A4::DEVICE_4318: return "Broadcom BCM4318 [AirForce One 54g] 802.11g WLAN Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14A4_PCIDEVICE14A4_H