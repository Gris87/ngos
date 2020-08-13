// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5168_PCIDEVICE5168_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5168_PCIDEVICE5168_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5168: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0300 = 0x0300,
    DEVICE_0301 = 0x0301
};



inline const char8* enumToString(PciDevice5168 device5168) // TEST: NO
{
    // COMMON_LT((" | device5168 = %u", device5168)); // Commented to avoid bad looking logs



    switch (device5168)
    {
        case PciDevice5168::NONE:        return "NONE";
        case PciDevice5168::DEVICE_0300: return "DEVICE_0300";
        case PciDevice5168::DEVICE_0301: return "DEVICE_0301";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5168 device5168) // TEST: NO
{
    // COMMON_LT((" | device5168 = %u", device5168)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5168, enumToString(device5168));

    return res;
}



inline const char8* enumToHumanString(PciDevice5168 device5168) // TEST: NO
{
    // COMMON_LT((" | device5168 = %u", device5168)); // Commented to avoid bad looking logs



    switch (device5168)
    {
        case PciDevice5168::DEVICE_0300: return "FlyDVB-S";
        case PciDevice5168::DEVICE_0301: return "FlyDVB-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5168_PCIDEVICE5168_H
