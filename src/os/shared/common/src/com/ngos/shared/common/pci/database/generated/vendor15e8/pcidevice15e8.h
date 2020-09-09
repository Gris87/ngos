// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E8_PCIDEVICE15E8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E8_PCIDEVICE15E8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice15E8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0130 = 0x0130,
    DEVICE_0131 = 0x0131
};



inline const char8* enumToString(PciDevice15E8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15E8::NONE:        return "NONE";
        case PciDevice15E8::DEVICE_0130: return "DEVICE_0130";
        case PciDevice15E8::DEVICE_0131: return "DEVICE_0131";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice15E8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice15E8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice15E8::DEVICE_0130: return "Wireless PCI Card";
        case PciDevice15E8::DEVICE_0131: return "NCP130A2 Wireless NIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR15E8_PCIDEVICE15E8_H
