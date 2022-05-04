// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E36: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0023 = 0x0023,
    DEVICE_0024 = 0x0024,
    DEVICE_8001 = 0x8001,
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
        case PciDevice1E36::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1E36::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1E36::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1E36::DEVICE_0024: return "DEVICE_0024";
        case PciDevice1E36::DEVICE_8001: return "DEVICE_8001";
        case PciDevice1E36::DEVICE_8011: return "DEVICE_8011";
        case PciDevice1E36::DEVICE_8012: return "DEVICE_8012";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E36 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E36 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E36::DEVICE_0001: return "T10 [CloudBlazer]";
        case PciDevice1E36::DEVICE_0002: return "T11 [CloudBlazer]";
        case PciDevice1E36::DEVICE_0003: return "T10(QSFP-DD) [CloudBlazer]";
        case PciDevice1E36::DEVICE_0021: return "T20(32GB) [CloudBlazer]";
        case PciDevice1E36::DEVICE_0022: return "T20(64GB) [CloudBlazer]";
        case PciDevice1E36::DEVICE_0023: return "T21(32GB) [CloudBlazer]";
        case PciDevice1E36::DEVICE_0024: return "T21(64GB) [CloudBlazer]";
        case PciDevice1E36::DEVICE_8001: return "I20 [CloudBlazer]";
        case PciDevice1E36::DEVICE_8011: return "I10 [CloudBlazer]";
        case PciDevice1E36::DEVICE_8012: return "I10L [CloudBlazer]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E36_PCIDEVICE1E36_H
