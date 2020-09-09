// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1904_PCIDEVICE1904_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1904_PCIDEVICE1904_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1904: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2031 = 0x2031,
    DEVICE_8139 = 0x8139
};



inline const char8* enumToString(PciDevice1904 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1904::NONE:        return "NONE";
        case PciDevice1904::DEVICE_2031: return "DEVICE_2031";
        case PciDevice1904::DEVICE_8139: return "DEVICE_8139";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1904 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1904 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1904::DEVICE_2031: return "SC92031 PCI Fast Ethernet Adapter";
        case PciDevice1904::DEVICE_8139: return "RTL8139D [Realtek] PCI 10/100BaseTX ethernet adaptor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1904_PCIDEVICE1904_H
