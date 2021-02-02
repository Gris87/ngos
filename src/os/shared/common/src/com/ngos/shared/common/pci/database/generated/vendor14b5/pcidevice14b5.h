// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B5_PCIDEVICE14B5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B5_PCIDEVICE14B5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14B5: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200,
    DEVICE_0300 = 0x0300,
    DEVICE_0400 = 0x0400,
    DEVICE_0600 = 0x0600,
    DEVICE_0800 = 0x0800,
    DEVICE_0900 = 0x0900,
    DEVICE_0A00 = 0x0A00,
    DEVICE_0B00 = 0x0B00
};



inline const char8* enumToString(PciDevice14B5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14B5::NONE:        return "NONE";
        case PciDevice14B5::DEVICE_0200: return "DEVICE_0200";
        case PciDevice14B5::DEVICE_0300: return "DEVICE_0300";
        case PciDevice14B5::DEVICE_0400: return "DEVICE_0400";
        case PciDevice14B5::DEVICE_0600: return "DEVICE_0600";
        case PciDevice14B5::DEVICE_0800: return "DEVICE_0800";
        case PciDevice14B5::DEVICE_0900: return "DEVICE_0900";
        case PciDevice14B5::DEVICE_0A00: return "DEVICE_0A00";
        case PciDevice14B5::DEVICE_0B00: return "DEVICE_0B00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14B5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14B5 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14B5::DEVICE_0200: return "Scope";
        case PciDevice14B5::DEVICE_0300: return "Pulsar";
        case PciDevice14B5::DEVICE_0400: return "PulsarSRB";
        case PciDevice14B5::DEVICE_0600: return "Pulsar2";
        case PciDevice14B5::DEVICE_0800: return "DSP-Board";
        case PciDevice14B5::DEVICE_0900: return "DSP-Board";
        case PciDevice14B5::DEVICE_0A00: return "DSP-Board";
        case PciDevice14B5::DEVICE_0B00: return "DSP-Board";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14B5_PCIDEVICE14B5_H
