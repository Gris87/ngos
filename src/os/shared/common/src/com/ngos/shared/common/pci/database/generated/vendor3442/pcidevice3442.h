// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3442_PCIDEVICE3442_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3442_PCIDEVICE3442_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice3442: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1783 = 0x1783,
    DEVICE_1922 = 0x1922
};



inline const char8* enumToString(PciDevice3442 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice3442::NONE:        return "NONE";
        case PciDevice3442::DEVICE_1783: return "DEVICE_1783";
        case PciDevice3442::DEVICE_1922: return "DEVICE_1922";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice3442 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice3442 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice3442::DEVICE_1783: return "AS-i 3.0 cPCI Master";
        case PciDevice3442::DEVICE_1922: return "AS-i 3.0 PCI Master";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3442_PCIDEVICE3442_H
