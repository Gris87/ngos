// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18D2_PCIDEVICE18D2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18D2_PCIDEVICE18D2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18D2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3069 = 0x3069
};



inline const char8* enumToString(PciDevice18D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18D2::NONE:        return "NONE";
        case PciDevice18D2::DEVICE_3069: return "DEVICE_3069";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice18D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice18D2::DEVICE_3069: return "DC-105v2 ISDN controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18D2_PCIDEVICE18D2_H
