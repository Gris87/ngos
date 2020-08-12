// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR116A_PCIDEVICE116A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR116A_PCIDEVICE116A_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice116A: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_6100 = 0x6100,
    DEVICE_6800 = 0x6800,
    DEVICE_7100 = 0x7100,
    DEVICE_7800 = 0x7800
};



inline const char8* enumToString(PciDevice116A device116A) // TEST: NO
{
    // COMMON_LT((" | device116A = %u", device116A)); // Commented to avoid bad looking logs



    switch (device116A)
    {
        case PciDevice116A::NONE:        return "NONE";
        case PciDevice116A::DEVICE_6100: return "DEVICE_6100";
        case PciDevice116A::DEVICE_6800: return "DEVICE_6800";
        case PciDevice116A::DEVICE_7100: return "DEVICE_7100";
        case PciDevice116A::DEVICE_7800: return "DEVICE_7800";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice116A device116A) // TEST: NO
{
    // COMMON_LT((" | device116A = %u", device116A)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device116A, enumToString(device116A));

    return res;
}



inline const char8* enumToHumanString(PciDevice116A device116A) // TEST: NO
{
    // COMMON_LT((" | device116A = %u", device116A)); // Commented to avoid bad looking logs



    switch (device116A)
    {
        case PciDevice116A::DEVICE_6100: return "Bus/Tag Channel";
        case PciDevice116A::DEVICE_6800: return "Escon Channel";
        case PciDevice116A::DEVICE_7100: return "Bus/Tag Channel";
        case PciDevice116A::DEVICE_7800: return "Escon Channel";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR116A_PCIDEVICE116A_H
