// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1626_PCIDEVICE1626_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1626_PCIDEVICE1626_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1626: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8410 = 0x8410
};



inline const char8* enumToString(PciDevice1626 device1626) // TEST: NO
{
    // COMMON_LT((" | device1626 = %u", device1626)); // Commented to avoid bad looking logs



    switch (device1626)
    {
        case PciDevice1626::NONE:        return "NONE";
        case PciDevice1626::DEVICE_8410: return "DEVICE_8410";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1626 device1626) // TEST: NO
{
    // COMMON_LT((" | device1626 = %u", device1626)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1626, enumToString(device1626));

    return res;
}



inline const char8* enumToHumanString(PciDevice1626 device1626) // TEST: NO
{
    // COMMON_LT((" | device1626 = %u", device1626)); // Commented to avoid bad looking logs



    switch (device1626)
    {
        case PciDevice1626::DEVICE_8410: return "RTL81xx Fast Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1626_PCIDEVICE1626_H
