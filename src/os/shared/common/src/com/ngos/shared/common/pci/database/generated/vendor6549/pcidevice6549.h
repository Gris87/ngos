// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6549_PCIDEVICE6549_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6549_PCIDEVICE6549_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice6549: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1200 = 0x1200
};



inline const char8* enumToString(PciDevice6549 device6549) // TEST: NO
{
    // COMMON_LT((" | device6549 = %u", device6549)); // Commented to avoid bad looking logs



    switch (device6549)
    {
        case PciDevice6549::NONE:        return "NONE";
        case PciDevice6549::DEVICE_1200: return "DEVICE_1200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice6549 device6549) // TEST: NO
{
    // COMMON_LT((" | device6549 = %u", device6549)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device6549, enumToString(device6549));

    return res;
}



inline const char8* enumToHumanString(PciDevice6549 device6549) // TEST: NO
{
    // COMMON_LT((" | device6549 = %u", device6549)); // Commented to avoid bad looking logs



    switch (device6549)
    {
        case PciDevice6549::DEVICE_1200: return "TERA1200 PC-over-IP Host";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR6549_PCIDEVICE6549_H
