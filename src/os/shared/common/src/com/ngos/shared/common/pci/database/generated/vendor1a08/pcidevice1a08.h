// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A08_PCIDEVICE1A08_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A08_PCIDEVICE1A08_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A08: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000
};



inline const char8* enumToString(PciDevice1A08 device1A08) // TEST: NO
{
    // COMMON_LT((" | device1A08 = %u", device1A08)); // Commented to avoid bad looking logs



    switch (device1A08)
    {
        case PciDevice1A08::DEVICE_0000: return "DEVICE_0000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A08 device1A08) // TEST: NO
{
    // COMMON_LT((" | device1A08 = %u", device1A08)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A08, enumToString(device1A08));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A08 device1A08) // TEST: NO
{
    // COMMON_LT((" | device1A08 = %u", device1A08)); // Commented to avoid bad looking logs



    switch (device1A08)
    {
        case PciDevice1A08::DEVICE_0000: return "SC15064";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A08_PCIDEVICE1A08_H
