// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D4_PCIDEVICE12D4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D4_PCIDEVICE12D4_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12D4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0200 = 0x0200
};



inline const char8* enumToString(PciDevice12D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12D4::NONE:        return "NONE";
        case PciDevice12D4::DEVICE_0200: return "DEVICE_0200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice12D4 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice12D4::DEVICE_0200: return "T1 Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D4_PCIDEVICE12D4_H
