// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B96_PCIDEVICE1B96_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B96_PCIDEVICE1B96_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B96: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2200 = 0x2200,
    DEVICE_2201 = 0x2201,
    DEVICE_2300 = 0x2300,
    DEVICE_2400 = 0x2400,
    DEVICE_2401 = 0x2401,
    DEVICE_2402 = 0x2402,
    DEVICE_2404 = 0x2404,
    DEVICE_2500 = 0x2500,
    DEVICE_2600 = 0x2600,
    DEVICE_3714 = 0x3714,
    DEVICE_3734 = 0x3734
};



inline const char8* enumToString(PciDevice1B96 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B96::NONE:        return "NONE";
        case PciDevice1B96::DEVICE_2200: return "DEVICE_2200";
        case PciDevice1B96::DEVICE_2201: return "DEVICE_2201";
        case PciDevice1B96::DEVICE_2300: return "DEVICE_2300";
        case PciDevice1B96::DEVICE_2400: return "DEVICE_2400";
        case PciDevice1B96::DEVICE_2401: return "DEVICE_2401";
        case PciDevice1B96::DEVICE_2402: return "DEVICE_2402";
        case PciDevice1B96::DEVICE_2404: return "DEVICE_2404";
        case PciDevice1B96::DEVICE_2500: return "DEVICE_2500";
        case PciDevice1B96::DEVICE_2600: return "DEVICE_2600";
        case PciDevice1B96::DEVICE_3714: return "DEVICE_3714";
        case PciDevice1B96::DEVICE_3734: return "DEVICE_3734";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B96 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B96 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1B96::DEVICE_2200: return "Ultrastar DC SN630 NVMe SSD";
        case PciDevice1B96::DEVICE_2201: return "Ultrastar DC SN630 NVMe SSD";
        case PciDevice1B96::DEVICE_2300: return "Ultrastar DC SN840 NVMe SSD";
        case PciDevice1B96::DEVICE_2400: return "Ultrastar DC SN640 NVMe SSD";
        case PciDevice1B96::DEVICE_2401: return "Ultrastar DC SN640 NVMe SSD";
        case PciDevice1B96::DEVICE_2402: return "Ultrastar DC SN640 NVMe SSD";
        case PciDevice1B96::DEVICE_2404: return "Ultrastar DC SN640 NVMe SSD";
        case PciDevice1B96::DEVICE_2500: return "Ultrastar DC SN840 NVMe SSD";
        case PciDevice1B96::DEVICE_2600: return "Ultrastar DC ZN540 ZNS NVMe SSD";
        case PciDevice1B96::DEVICE_3714: return "PC SN730 NVMe SSD";
        case PciDevice1B96::DEVICE_3734: return "PC SN730 NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B96_PCIDEVICE1B96_H
