// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1090_PCIDEVICE1090_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1090_PCIDEVICE1090_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1090: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4610 = 0x4610,
    DEVICE_4620 = 0x4620
};



inline const char8* enumToString(PciDevice1090 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1090::NONE:        return "NONE";
        case PciDevice1090::DEVICE_4610: return "DEVICE_4610";
        case PciDevice1090::DEVICE_4620: return "DEVICE_4620";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1090 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1090 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1090::DEVICE_4610: return "PCI RTOM";
        case PciDevice1090::DEVICE_4620: return "GPIO HSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1090_PCIDEVICE1090_H
