// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C6_PCIDEVICE13C6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C6_PCIDEVICE13C6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice13C6: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0520 = 0x0520,
    DEVICE_0620 = 0x0620,
    DEVICE_0820 = 0x0820,
    DEVICE_0830 = 0x0830,
    DEVICE_1004 = 0x1004
};



inline const char8* enumToString(PciDevice13C6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C6::NONE:        return "NONE";
        case PciDevice13C6::DEVICE_0520: return "DEVICE_0520";
        case PciDevice13C6::DEVICE_0620: return "DEVICE_0620";
        case PciDevice13C6::DEVICE_0820: return "DEVICE_0820";
        case PciDevice13C6::DEVICE_0830: return "DEVICE_0830";
        case PciDevice13C6::DEVICE_1004: return "DEVICE_1004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice13C6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice13C6 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice13C6::DEVICE_0520: return "CEI-520 A429 Card";
        case PciDevice13C6::DEVICE_0620: return "CEI-620 A429 Card";
        case PciDevice13C6::DEVICE_0820: return "CEI-820 A429 Card";
        case PciDevice13C6::DEVICE_0830: return "CEI-830 A429 Card";
        case PciDevice13C6::DEVICE_1004: return "P-SER Multi-channel PMC to RS-485/422/232 adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13C6_PCIDEVICE13C6_H
