// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D1_PCIDEVICE11D1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D1_PCIDEVICE11D1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice11D1: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_01F7 = 0x01F7,
    DEVICE_01F9 = 0x01F9
};



inline const char8* enumToString(PciDevice11D1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11D1::NONE:        return "NONE";
        case PciDevice11D1::DEVICE_01F7: return "DEVICE_01F7";
        case PciDevice11D1::DEVICE_01F9: return "DEVICE_01F9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice11D1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice11D1 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice11D1::DEVICE_01F7: return "VxP524";
        case PciDevice11D1::DEVICE_01F9: return "VxP951";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11D1_PCIDEVICE11D1_H
