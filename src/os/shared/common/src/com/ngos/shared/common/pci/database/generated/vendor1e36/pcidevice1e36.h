// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E36: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_8011 = 0x8011,
    DEVICE_8012 = 0x8012
};



inline const char8* enumToString(PciDevice1E36 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E36::NONE:        return "NONE";
        case PciDevice1E36::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1E36::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1E36::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1E36::DEVICE_8011: return "DEVICE_8011";
        case PciDevice1E36::DEVICE_8012: return "DEVICE_8012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E36 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E36 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E36::DEVICE_0001: return "T10 [CloudBlazer]";
        case PciDevice1E36::DEVICE_0002: return "T11 [CloudBlazer]";
        case PciDevice1E36::DEVICE_0003: return "T10s [CloudBlazer]";
        case PciDevice1E36::DEVICE_8011: return "I10 [CloudBlazer]";
        case PciDevice1E36::DEVICE_8012: return "I10L [CloudBlazer]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H
