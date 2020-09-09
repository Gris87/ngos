// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13EC_PCIDEVICE13EC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13EC_PCIDEVICE13EC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13EC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_000A = 0x000A
};



inline const char8* enumToString(PciDevice13EC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13EC::NONE:        return "NONE";
        case PciDevice13EC::DEVICE_000A: return "DEVICE_000A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13EC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13EC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13EC::DEVICE_000A: return "NPC-RC01 Remote control receiver";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13EC_PCIDEVICE13EC_H
