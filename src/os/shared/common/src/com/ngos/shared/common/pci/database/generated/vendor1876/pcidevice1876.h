// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1876_PCIDEVICE1876_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1876_PCIDEVICE1876_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1876: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A101 = 0xA101,
    DEVICE_A102 = 0xA102,
    DEVICE_A103 = 0xA103
};



inline const char8* enumToString(PciDevice1876 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1876::NONE:        return "NONE";
        case PciDevice1876::DEVICE_A101: return "DEVICE_A101";
        case PciDevice1876::DEVICE_A102: return "DEVICE_A102";
        case PciDevice1876::DEVICE_A103: return "DEVICE_A103";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1876 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1876 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1876::DEVICE_A101: return "VigraWATCH PCI";
        case PciDevice1876::DEVICE_A102: return "VigraWATCH PMC";
        case PciDevice1876::DEVICE_A103: return "Vigra I/O";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1876_PCIDEVICE1876_H
