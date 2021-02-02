// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151A_PCIDEVICE151A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151A_PCIDEVICE151A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice151A: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1002 = 0x1002,
    DEVICE_1004 = 0x1004,
    DEVICE_1008 = 0x1008
};



inline const char8* enumToString(PciDevice151A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice151A::NONE:        return "NONE";
        case PciDevice151A::DEVICE_1002: return "DEVICE_1002";
        case PciDevice151A::DEVICE_1004: return "DEVICE_1004";
        case PciDevice151A::DEVICE_1008: return "DEVICE_1008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice151A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice151A device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice151A::DEVICE_1002: return "PCI-1002";
        case PciDevice151A::DEVICE_1004: return "PCI-1004";
        case PciDevice151A::DEVICE_1008: return "PCI-1008";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR151A_PCIDEVICE151A_H
