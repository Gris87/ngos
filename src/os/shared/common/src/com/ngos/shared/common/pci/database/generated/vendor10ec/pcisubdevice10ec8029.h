// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8029_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8029_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC8029: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B82011 = 0x10B82011,
    SUBDEVICE_10EC8029 = 0x10EC8029,
    SUBDEVICE_11131208 = 0x11131208,
    SUBDEVICE_11860300 = 0x11860300,
    SUBDEVICE_12592400 = 0x12592400,
    SUBDEVICE_1AF41100 = 0x1AF41100
};



inline const char8* enumToString(PciSubDevice10EC8029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8029::NONE:               return "NONE";
        case PciSubDevice10EC8029::SUBDEVICE_10B82011: return "SUBDEVICE_10B82011";
        case PciSubDevice10EC8029::SUBDEVICE_10EC8029: return "SUBDEVICE_10EC8029";
        case PciSubDevice10EC8029::SUBDEVICE_11131208: return "SUBDEVICE_11131208";
        case PciSubDevice10EC8029::SUBDEVICE_11860300: return "SUBDEVICE_11860300";
        case PciSubDevice10EC8029::SUBDEVICE_12592400: return "SUBDEVICE_12592400";
        case PciSubDevice10EC8029::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC8029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC8029 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8029::SUBDEVICE_10B82011: return "EZ-Card (SMC1208)";
        case PciSubDevice10EC8029::SUBDEVICE_10EC8029: return "RTL-8029(AS)";
        case PciSubDevice10EC8029::SUBDEVICE_11131208: return "EN1208";
        case PciSubDevice10EC8029::SUBDEVICE_11860300: return "DE-528";
        case PciSubDevice10EC8029::SUBDEVICE_12592400: return "AT-2400";
        case PciSubDevice10EC8029::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8029_H
