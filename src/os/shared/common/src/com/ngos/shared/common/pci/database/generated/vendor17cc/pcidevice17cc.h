// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CC_PCIDEVICE17CC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CC_PCIDEVICE17CC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17CC: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2280 = 0x2280
};



inline const char8* enumToString(PciDevice17CC device17CC) // TEST: NO
{
    // COMMON_LT((" | device17CC = %u", device17CC)); // Commented to avoid bad looking logs



    switch (device17CC)
    {
        case PciDevice17CC::NONE:        return "NONE";
        case PciDevice17CC::DEVICE_2280: return "DEVICE_2280";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17CC device17CC) // TEST: NO
{
    // COMMON_LT((" | device17CC = %u", device17CC)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device17CC, enumToString(device17CC));

    return res;
}



inline const char8* enumToHumanString(PciDevice17CC device17CC) // TEST: NO
{
    // COMMON_LT((" | device17CC = %u", device17CC)); // Commented to avoid bad looking logs



    switch (device17CC)
    {
        case PciDevice17CC::DEVICE_2280: return "USB 2.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17CC_PCIDEVICE17CC_H
