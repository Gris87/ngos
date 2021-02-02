// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0014_PCIDEVICE0014_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0014_PCIDEVICE0014_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0014: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7A00 = 0x7A00,
    DEVICE_7A02 = 0x7A02,
    DEVICE_7A03 = 0x7A03,
    DEVICE_7A04 = 0x7A04,
    DEVICE_7A05 = 0x7A05,
    DEVICE_7A06 = 0x7A06,
    DEVICE_7A07 = 0x7A07,
    DEVICE_7A08 = 0x7A08,
    DEVICE_7A09 = 0x7A09,
    DEVICE_7A0B = 0x7A0B,
    DEVICE_7A0C = 0x7A0C,
    DEVICE_7A0F = 0x7A0F,
    DEVICE_7A10 = 0x7A10,
    DEVICE_7A14 = 0x7A14,
    DEVICE_7A15 = 0x7A15,
    DEVICE_7A19 = 0x7A19,
    DEVICE_7A24 = 0x7A24,
    DEVICE_7A29 = 0x7A29
};



inline const char8* enumToString(PciDevice0014 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0014::NONE:        return "NONE";
        case PciDevice0014::DEVICE_7A00: return "DEVICE_7A00";
        case PciDevice0014::DEVICE_7A02: return "DEVICE_7A02";
        case PciDevice0014::DEVICE_7A03: return "DEVICE_7A03";
        case PciDevice0014::DEVICE_7A04: return "DEVICE_7A04";
        case PciDevice0014::DEVICE_7A05: return "DEVICE_7A05";
        case PciDevice0014::DEVICE_7A06: return "DEVICE_7A06";
        case PciDevice0014::DEVICE_7A07: return "DEVICE_7A07";
        case PciDevice0014::DEVICE_7A08: return "DEVICE_7A08";
        case PciDevice0014::DEVICE_7A09: return "DEVICE_7A09";
        case PciDevice0014::DEVICE_7A0B: return "DEVICE_7A0B";
        case PciDevice0014::DEVICE_7A0C: return "DEVICE_7A0C";
        case PciDevice0014::DEVICE_7A0F: return "DEVICE_7A0F";
        case PciDevice0014::DEVICE_7A10: return "DEVICE_7A10";
        case PciDevice0014::DEVICE_7A14: return "DEVICE_7A14";
        case PciDevice0014::DEVICE_7A15: return "DEVICE_7A15";
        case PciDevice0014::DEVICE_7A19: return "DEVICE_7A19";
        case PciDevice0014::DEVICE_7A24: return "DEVICE_7A24";
        case PciDevice0014::DEVICE_7A29: return "DEVICE_7A29";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0014 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice0014 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0014::DEVICE_7A00: return "Hyper Transport Bridge Controller";
        case PciDevice0014::DEVICE_7A02: return "APB (Advanced Peripheral Bus) Controller";
        case PciDevice0014::DEVICE_7A03: return "Gigabit Ethernet Controller";
        case PciDevice0014::DEVICE_7A04: return "OTG USB Controller";
        case PciDevice0014::DEVICE_7A05: return "Vivante GPU (Graphics Processing Unit)";
        case PciDevice0014::DEVICE_7A06: return "DC (Display Controller)";
        case PciDevice0014::DEVICE_7A07: return "HDA (High Definition Audio) Controller";
        case PciDevice0014::DEVICE_7A08: return "SATA AHCI Controller";
        case PciDevice0014::DEVICE_7A09: return "PCI-to-PCI Bridge";
        case PciDevice0014::DEVICE_7A0B: return "SPI Controller";
        case PciDevice0014::DEVICE_7A0C: return "LPC Controller";
        case PciDevice0014::DEVICE_7A0F: return "DMA (Direct Memory Access) Controller";
        case PciDevice0014::DEVICE_7A10: return "Hyper Transport Bridge Controller";
        case PciDevice0014::DEVICE_7A14: return "EHCI USB Controller";
        case PciDevice0014::DEVICE_7A15: return "Vivante GPU (Graphics Processing Unit)";
        case PciDevice0014::DEVICE_7A19: return "PCI-to-PCI Bridge";
        case PciDevice0014::DEVICE_7A24: return "OHCI USB Controller";
        case PciDevice0014::DEVICE_7A29: return "PCI-to-PCI Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0014_PCIDEVICE0014_H
