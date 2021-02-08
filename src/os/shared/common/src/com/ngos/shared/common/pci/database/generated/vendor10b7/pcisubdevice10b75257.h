// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B75257_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B75257_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B75257: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B75C57 = 0x10B75C57
};



inline const char8* enumToString(PciSubDevice10B75257 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B75257::NONE:               return "NONE";
        case PciSubDevice10B75257::SUBDEVICE_10B75C57: return "SUBDEVICE_10B75C57";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B75257 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B75257 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B75257::SUBDEVICE_10B75C57: return "FE575C-3Com 10/100 LAN CardBus-Fast Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B75257_H
