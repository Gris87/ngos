// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1987_PCIDEVICE1987_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1987_PCIDEVICE1987_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1987: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5007 = 0x5007,
    DEVICE_5012 = 0x5012,
    DEVICE_5013 = 0x5013,
    DEVICE_5016 = 0x5016,
    DEVICE_5018 = 0x5018
};



inline const char8* enumToString(PciDevice1987 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1987::NONE:        return "NONE";
        case PciDevice1987::DEVICE_5007: return "DEVICE_5007";
        case PciDevice1987::DEVICE_5012: return "DEVICE_5012";
        case PciDevice1987::DEVICE_5013: return "DEVICE_5013";
        case PciDevice1987::DEVICE_5016: return "DEVICE_5016";
        case PciDevice1987::DEVICE_5018: return "DEVICE_5018";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1987 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1987 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1987::DEVICE_5007: return "E7 NVMe Controller";
        case PciDevice1987::DEVICE_5012: return "E12 NVMe Controller";
        case PciDevice1987::DEVICE_5013: return "PS5013 E13 NVMe Controller";
        case PciDevice1987::DEVICE_5016: return "E16 PCIe4 NVMe Controller";
        case PciDevice1987::DEVICE_5018: return "E18 PCIe4 NVMe Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1987_PCIDEVICE1987_H
