// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC1_PCIDEVICE1CC1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC1_PCIDEVICE1CC1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CC1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8201 = 0x8201
};



inline const char8* enumToString(PciDevice1CC1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1CC1::NONE:        return "NONE";
        case PciDevice1CC1::DEVICE_8201: return "DEVICE_8201";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CC1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CC1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1CC1::DEVICE_8201: return "XPG SX8200 Pro PCIe Gen3x4 M.2 2280 Solid State Drive";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CC1_PCIDEVICE1CC1_H
