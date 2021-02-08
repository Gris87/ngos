// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A3B_PCIDEVICE1A3B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A3B_PCIDEVICE1A3B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A3B: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1112 = 0x1112
};



inline const char8* enumToString(PciDevice1A3B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A3B::NONE:        return "NONE";
        case PciDevice1A3B::DEVICE_1112: return "DEVICE_1112";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A3B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A3B device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A3B::DEVICE_1112: return "AR9285 Wireless Network Adapter (PCI-Express)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A3B_PCIDEVICE1A3B_H
