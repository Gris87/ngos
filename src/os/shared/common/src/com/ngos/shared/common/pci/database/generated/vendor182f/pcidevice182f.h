// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182F_PCIDEVICE182F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182F_PCIDEVICE182F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice182F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000B = 0x000B
};



inline const char8* enumToString(PciDevice182F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice182F::NONE:        return "NONE";
        case PciDevice182F::DEVICE_000B: return "DEVICE_000B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice182F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice182F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice182F::DEVICE_000B: return "BCM5785 [HT1000] SATA (RAID Mode)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR182F_PCIDEVICE182F_H
