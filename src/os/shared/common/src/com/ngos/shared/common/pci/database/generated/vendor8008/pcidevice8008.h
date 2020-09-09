// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8008_PCIDEVICE8008_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8008_PCIDEVICE8008_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice8008: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0015 = 0x0015
};



inline const char8* enumToString(PciDevice8008 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8008::NONE:        return "NONE";
        case PciDevice8008::DEVICE_0010: return "DEVICE_0010";
        case PciDevice8008::DEVICE_0011: return "DEVICE_0011";
        case PciDevice8008::DEVICE_0015: return "DEVICE_0015";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice8008 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice8008 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice8008::DEVICE_0010: return "WDOG1 [PCI-Watchdog 1]";
        case PciDevice8008::DEVICE_0011: return "PWDOG2 [PCI-Watchdog 2]";
        case PciDevice8008::DEVICE_0015: return "Clock77/PCI & Clock77/PCIe (DCF-77 receiver)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8008_PCIDEVICE8008_H
