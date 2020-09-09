// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR136A_PCIDEVICE136A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR136A_PCIDEVICE136A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice136A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0004 = 0x0004,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_000A = 0x000A
};



inline const char8* enumToString(PciDevice136A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice136A::NONE:        return "NONE";
        case PciDevice136A::DEVICE_0004: return "DEVICE_0004";
        case PciDevice136A::DEVICE_0007: return "DEVICE_0007";
        case PciDevice136A::DEVICE_0008: return "DEVICE_0008";
        case PciDevice136A::DEVICE_000A: return "DEVICE_000A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice136A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice136A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice136A::DEVICE_0004: return "HST Saphir VII mini PCI";
        case PciDevice136A::DEVICE_0007: return "HST Saphir III E MultiLink 4";
        case PciDevice136A::DEVICE_0008: return "HST Saphir III E MultiLink 8";
        case PciDevice136A::DEVICE_000A: return "HST Saphir III E MultiLink 2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR136A_PCIDEVICE136A_H
