// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1682_PCIDEVICE1682_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1682_PCIDEVICE1682_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1682: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5701 = 0x5701,
    DEVICE_C580 = 0xC580
};



inline const char8* enumToString(PciDevice1682 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1682::NONE:        return "NONE";
        case PciDevice1682::DEVICE_5701: return "DEVICE_5701";
        case PciDevice1682::DEVICE_C580: return "DEVICE_C580";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1682 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1682 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1682::DEVICE_5701: return "Radeon 5700 XT Thicc III Ultra";
        case PciDevice1682::DEVICE_C580: return "Radeon RX 580";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1682_PCIDEVICE1682_H
