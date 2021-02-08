// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14BA_PCIDEVICE14BA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14BA_PCIDEVICE14BA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14BA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0600 = 0x0600
};



inline const char8* enumToString(PciDevice14BA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14BA::NONE:        return "NONE";
        case PciDevice14BA::DEVICE_0600: return "DEVICE_0600";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14BA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14BA device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14BA::DEVICE_0600: return "ARC-PCI/22";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14BA_PCIDEVICE14BA_H
