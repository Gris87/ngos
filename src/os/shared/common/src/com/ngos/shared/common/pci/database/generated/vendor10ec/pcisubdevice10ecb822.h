// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10ECB822_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10ECB822_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10ECB822: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C831B = 0x103C831B,
    SUBDEVICE_17AA5124 = 0x17AA5124,
    SUBDEVICE_17AAB023 = 0x17AAB023
};



inline const char8* enumToString(PciSubDevice10ECB822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10ECB822::NONE:               return "NONE";
        case PciSubDevice10ECB822::SUBDEVICE_103C831B: return "SUBDEVICE_103C831B";
        case PciSubDevice10ECB822::SUBDEVICE_17AA5124: return "SUBDEVICE_17AA5124";
        case PciSubDevice10ECB822::SUBDEVICE_17AAB023: return "SUBDEVICE_17AAB023";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10ECB822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10ECB822 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10ECB822::SUBDEVICE_103C831B: return "Realtek RTL8822BE 802.11ac 2 x 2 Wi-Fi + Bluetooth 4.2 Combo Adapter (MU-MIMO supported)";
        case PciSubDevice10ECB822::SUBDEVICE_17AA5124: return "ThinkPad E595";
        case PciSubDevice10ECB822::SUBDEVICE_17AAB023: return "ThinkPad E595";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10ECB822_H
