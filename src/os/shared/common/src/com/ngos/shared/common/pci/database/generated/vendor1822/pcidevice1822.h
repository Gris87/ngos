// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1822_PCIDEVICE1822_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1822_PCIDEVICE1822_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1822: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4E35 = 0x4E35
};



inline const char8* enumToString(PciDevice1822 device1822) // TEST: NO
{
    // COMMON_LT((" | device1822 = %u", device1822)); // Commented to avoid bad looking logs



    switch (device1822)
    {
        case PciDevice1822::NONE:        return "NONE";
        case PciDevice1822::DEVICE_4E35: return "DEVICE_4E35";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1822 device1822) // TEST: NO
{
    // COMMON_LT((" | device1822 = %u", device1822)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1822, enumToString(device1822));

    return res;
}



inline const char8* enumToHumanString(PciDevice1822 device1822) // TEST: NO
{
    // COMMON_LT((" | device1822 = %u", device1822)); // Commented to avoid bad looking logs



    switch (device1822)
    {
        case PciDevice1822::DEVICE_4E35: return "Mantis DTV PCI Bridge Controller [Ver 1.0]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1822_PCIDEVICE1822_H
