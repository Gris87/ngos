// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR31AB_PCIDEVICE31AB_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR31AB_PCIDEVICE31AB_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice31AB: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1FAA = 0x1FAA
};



inline const char8* enumToString(PciDevice31AB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice31AB::NONE:        return "NONE";
        case PciDevice31AB::DEVICE_1FAA: return "DEVICE_1FAA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice31AB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice31AB device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice31AB::DEVICE_1FAA: return "ZEW1602 802.11b/g Wireless Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR31AB_PCIDEVICE31AB_H
