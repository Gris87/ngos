// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1982_PCIDEVICE1982_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1982_PCIDEVICE1982_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1982: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1600 = 0x1600,
    DEVICE_16FF = 0x16FF
};



inline const char8* enumToString(PciDevice1982 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1982::NONE:        return "NONE";
        case PciDevice1982::DEVICE_1600: return "DEVICE_1600";
        case PciDevice1982::DEVICE_16FF: return "DEVICE_16FF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1982 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1982 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1982::DEVICE_1600: return "OX16C954 HOST-A";
        case PciDevice1982::DEVICE_16FF: return "OX16C954 HOST-B";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1982_PCIDEVICE1982_H
