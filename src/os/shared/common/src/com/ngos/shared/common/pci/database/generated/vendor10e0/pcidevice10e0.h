// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E0_PCIDEVICE10E0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E0_PCIDEVICE10E0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10E0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5026 = 0x5026,
    DEVICE_5027 = 0x5027,
    DEVICE_5028 = 0x5028,
    DEVICE_8849 = 0x8849,
    DEVICE_8853 = 0x8853,
    DEVICE_9128 = 0x9128
};



inline const char8* enumToString(PciDevice10E0 device10E0) // TEST: NO
{
    // COMMON_LT((" | device10E0 = %u", device10E0)); // Commented to avoid bad looking logs



    switch (device10E0)
    {
        case PciDevice10E0::NONE:        return "NONE";
        case PciDevice10E0::DEVICE_5026: return "DEVICE_5026";
        case PciDevice10E0::DEVICE_5027: return "DEVICE_5027";
        case PciDevice10E0::DEVICE_5028: return "DEVICE_5028";
        case PciDevice10E0::DEVICE_8849: return "DEVICE_8849";
        case PciDevice10E0::DEVICE_8853: return "DEVICE_8853";
        case PciDevice10E0::DEVICE_9128: return "DEVICE_9128";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10E0 device10E0) // TEST: NO
{
    // COMMON_LT((" | device10E0 = %u", device10E0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10E0, enumToString(device10E0));

    return res;
}



inline const char8* enumToHumanString(PciDevice10E0 device10E0) // TEST: NO
{
    // COMMON_LT((" | device10E0 = %u", device10E0)); // Commented to avoid bad looking logs



    switch (device10E0)
    {
        case PciDevice10E0::DEVICE_5026: return "IMS5026/27/28";
        case PciDevice10E0::DEVICE_5027: return "IMS5027";
        case PciDevice10E0::DEVICE_5028: return "IMS5028";
        case PciDevice10E0::DEVICE_8849: return "IMS8849";
        case PciDevice10E0::DEVICE_8853: return "IMS8853";
        case PciDevice10E0::DEVICE_9128: return "IMS9128 [Twin turbo 128]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E0_PCIDEVICE10E0_H
