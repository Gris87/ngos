// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8129_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8129_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC8129: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10EC8129 = 0x10EC8129,
    SUBDEVICE_11EC8129 = 0x11EC8129
};



inline const char8* enumToString(PciSubDevice10EC8129 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8129::NONE:               return "NONE";
        case PciSubDevice10EC8129::SUBDEVICE_10EC8129: return "SUBDEVICE_10EC8129";
        case PciSubDevice10EC8129::SUBDEVICE_11EC8129: return "SUBDEVICE_11EC8129";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC8129 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC8129 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8129::SUBDEVICE_10EC8129: return "RT8129 Fast Ethernet Adapter";
        case PciSubDevice10EC8129::SUBDEVICE_11EC8129: return "RTL8111/8168 PCIe Gigabit Ethernet (misconfigured)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8129_H
