// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1080_PCIDEVICE1080_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1080_PCIDEVICE1080_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1080: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0600 = 0x0600,
    DEVICE_C691 = 0xC691,
    DEVICE_C693 = 0xC693
};



inline const char8* enumToString(PciDevice1080 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1080::NONE:        return "NONE";
        case PciDevice1080::DEVICE_0600: return "DEVICE_0600";
        case PciDevice1080::DEVICE_C691: return "DEVICE_C691";
        case PciDevice1080::DEVICE_C693: return "DEVICE_C693";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1080 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1080 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1080::DEVICE_0600: return "82C599";
        case PciDevice1080::DEVICE_C691: return "Cypress CY82C691";
        case PciDevice1080::DEVICE_C693: return "82c693";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1080_PCIDEVICE1080_H
