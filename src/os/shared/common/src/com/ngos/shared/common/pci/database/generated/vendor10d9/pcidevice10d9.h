// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10D9_PCIDEVICE10D9_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10D9_PCIDEVICE10D9_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10D9: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0431 = 0x0431,
    DEVICE_0512 = 0x0512,
    DEVICE_0531 = 0x0531,
    DEVICE_8625 = 0x8625,
    DEVICE_8626 = 0x8626,
    DEVICE_8888 = 0x8888
};



inline const char8* enumToString(PciDevice10D9 device10D9) // TEST: NO
{
    // COMMON_LT((" | device10D9 = %u", device10D9)); // Commented to avoid bad looking logs



    switch (device10D9)
    {
        case PciDevice10D9::NONE:        return "NONE";
        case PciDevice10D9::DEVICE_0431: return "DEVICE_0431";
        case PciDevice10D9::DEVICE_0512: return "DEVICE_0512";
        case PciDevice10D9::DEVICE_0531: return "DEVICE_0531";
        case PciDevice10D9::DEVICE_8625: return "DEVICE_8625";
        case PciDevice10D9::DEVICE_8626: return "DEVICE_8626";
        case PciDevice10D9::DEVICE_8888: return "DEVICE_8888";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10D9 device10D9) // TEST: NO
{
    // COMMON_LT((" | device10D9 = %u", device10D9)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10D9, enumToString(device10D9));

    return res;
}



inline const char8* enumToHumanString(PciDevice10D9 device10D9) // TEST: NO
{
    // COMMON_LT((" | device10D9 = %u", device10D9)); // Commented to avoid bad looking logs



    switch (device10D9)
    {
        case PciDevice10D9::DEVICE_0431: return "MX98715";
        case PciDevice10D9::DEVICE_0512: return "MX98713";
        case PciDevice10D9::DEVICE_0531: return "MX987x5";
        case PciDevice10D9::DEVICE_8625: return "MX86250";
        case PciDevice10D9::DEVICE_8626: return "Macronix MX86251 + 3Dfx Voodoo Rush";
        case PciDevice10D9::DEVICE_8888: return "MX86200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10D9_PCIDEVICE10D9_H
