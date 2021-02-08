// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10F1_PCIDEVICE10F1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10F1_PCIDEVICE10F1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10F1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2865 = 0x2865,
    DEVICE_5300 = 0x5300
};



inline const char8* enumToString(PciDevice10F1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10F1::NONE:        return "NONE";
        case PciDevice10F1::DEVICE_2865: return "DEVICE_2865";
        case PciDevice10F1::DEVICE_5300: return "DEVICE_5300";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10F1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice10F1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice10F1::DEVICE_2865: return "Tyan Thunder K8E S2865";
        case PciDevice10F1::DEVICE_5300: return "Tyan S5380 Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10F1_PCIDEVICE10F1_H
