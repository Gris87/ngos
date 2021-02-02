// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0675_PCIDEVICE0675_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0675_PCIDEVICE0675_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0675: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1700 = 0x1700,
    DEVICE_1702 = 0x1702,
    DEVICE_1703 = 0x1703,
    DEVICE_1704 = 0x1704
};



inline const char8* enumToString(PciDevice0675 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0675::NONE:        return "NONE";
        case PciDevice0675::DEVICE_1700: return "DEVICE_1700";
        case PciDevice0675::DEVICE_1702: return "DEVICE_1702";
        case PciDevice0675::DEVICE_1703: return "DEVICE_1703";
        case PciDevice0675::DEVICE_1704: return "DEVICE_1704";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0675 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice0675 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0675::DEVICE_1700: return "IS64PH ISDN Adapter";
        case PciDevice0675::DEVICE_1702: return "IS64PH ISDN Adapter";
        case PciDevice0675::DEVICE_1703: return "ISDN Adapter (PCI Bus, DV, W)";
        case PciDevice0675::DEVICE_1704: return "ISDN Adapter (PCI Bus, D, C)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0675_PCIDEVICE0675_H
