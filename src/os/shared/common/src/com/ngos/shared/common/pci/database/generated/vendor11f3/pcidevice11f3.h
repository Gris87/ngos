// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F3_PCIDEVICE11F3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F3_PCIDEVICE11F3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11F3: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0011 = 0x0011
};



inline const char8* enumToString(PciDevice11F3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11F3::NONE:        return "NONE";
        case PciDevice11F3::DEVICE_0011: return "DEVICE_0011";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11F3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11F3 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11F3::DEVICE_0011: return "KPCI-PIO24";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11F3_PCIDEVICE11F3_H
