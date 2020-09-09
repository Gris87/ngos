// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR021B_PCIDEVICE021B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR021B_PCIDEVICE021B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice021B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8139 = 0x8139
};



inline const char8* enumToString(PciDevice021B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice021B::NONE:        return "NONE";
        case PciDevice021B::DEVICE_8139: return "DEVICE_8139";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice021B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice021B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice021B::DEVICE_8139: return "HNE-300 (RealTek RTL8139c) [iPaq Networking]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR021B_PCIDEVICE021B_H
