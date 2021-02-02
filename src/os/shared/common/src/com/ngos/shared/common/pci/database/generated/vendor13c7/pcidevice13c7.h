// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C7_PCIDEVICE13C7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C7_PCIDEVICE13C7_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13C7: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0ADC = 0x0ADC,
    DEVICE_0B10 = 0x0B10,
    DEVICE_0D10 = 0x0D10,
    DEVICE_524C = 0x524C,
    DEVICE_5744 = 0x5744
};



inline const char8* enumToString(PciDevice13C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C7::NONE:        return "NONE";
        case PciDevice13C7::DEVICE_0ADC: return "DEVICE_0ADC";
        case PciDevice13C7::DEVICE_0B10: return "DEVICE_0B10";
        case PciDevice13C7::DEVICE_0D10: return "DEVICE_0D10";
        case PciDevice13C7::DEVICE_524C: return "DEVICE_524C";
        case PciDevice13C7::DEVICE_5744: return "DEVICE_5744";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13C7 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C7::DEVICE_0ADC: return "PCI-ADC";
        case PciDevice13C7::DEVICE_0B10: return "PCI-PIO";
        case PciDevice13C7::DEVICE_0D10: return "PCI-DIO";
        case PciDevice13C7::DEVICE_524C: return "PCI-RLY";
        case PciDevice13C7::DEVICE_5744: return "PCI-WDT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C7_PCIDEVICE13C7_H
