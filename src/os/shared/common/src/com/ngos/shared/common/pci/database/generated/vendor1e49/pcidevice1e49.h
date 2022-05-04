// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E49_PCIDEVICE1E49_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E49_PCIDEVICE1E49_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1E49: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0041 = 0x0041,
    DEVICE_1013 = 0x1013
};



inline const char8* enumToString(PciDevice1E49 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E49::NONE:        return "NONE";
        case PciDevice1E49::DEVICE_0041: return "DEVICE_0041";
        case PciDevice1E49::DEVICE_1013: return "DEVICE_1013";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1E49 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1E49 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1E49::DEVICE_0041: return "ZHITAI TiPro7000";
        case PciDevice1E49::DEVICE_1013: return "PC210";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1E49_PCIDEVICE1E49_H
