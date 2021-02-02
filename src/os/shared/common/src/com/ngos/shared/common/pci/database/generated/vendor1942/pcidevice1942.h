// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1942_PCIDEVICE1942_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1942_PCIDEVICE1942_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1942: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_E511 = 0xE511,
    DEVICE_E521 = 0xE521
};



inline const char8* enumToString(PciDevice1942 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1942::NONE:        return "NONE";
        case PciDevice1942::DEVICE_E511: return "DEVICE_E511";
        case PciDevice1942::DEVICE_E521: return "DEVICE_E521";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1942 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1942 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1942::DEVICE_E511: return "Advance X620 accelerator card";
        case PciDevice1942::DEVICE_E521: return "Advance e620 accelerator card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1942_PCIDEVICE1942_H
