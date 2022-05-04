// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AA9_PCIDEVICE1AA9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AA9_PCIDEVICE1AA9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AA9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000D = 0x000D,
    DEVICE_000E = 0x000E,
    DEVICE_0014 = 0x0014,
    DEVICE_0018 = 0x0018
};



inline const char8* enumToString(PciDevice1AA9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AA9::NONE:        return "NONE";
        case PciDevice1AA9::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1AA9::DEVICE_000E: return "DEVICE_000E";
        case PciDevice1AA9::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1AA9::DEVICE_0018: return "DEVICE_0018";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AA9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AA9 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AA9::DEVICE_000D: return "SEL-3390S8 Serial Adapter";
        case PciDevice1AA9::DEVICE_000E: return "SEL-3390E4 Ethernet Adapter";
        case PciDevice1AA9::DEVICE_0014: return "SEL-3390T Time and Ethernet Adapter";
        case PciDevice1AA9::DEVICE_0018: return "SEL-3390E4 Ethernet Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AA9_PCIDEVICE1AA9_H
