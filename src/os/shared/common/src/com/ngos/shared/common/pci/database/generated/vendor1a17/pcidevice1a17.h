// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A17_PCIDEVICE1A17_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A17_PCIDEVICE1A17_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A17: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8002 = 0x8002
};



inline const char8* enumToString(PciDevice1A17 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A17::NONE:        return "NONE";
        case PciDevice1A17::DEVICE_8002: return "DEVICE_8002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A17 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A17 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1A17::DEVICE_8002: return "PB-10GE-2P 10GbE Security Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A17_PCIDEVICE1A17_H
