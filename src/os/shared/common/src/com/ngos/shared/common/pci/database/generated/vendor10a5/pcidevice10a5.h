// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A5_PCIDEVICE10A5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A5_PCIDEVICE10A5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10A5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_3052 = 0x3052,
    DEVICE_5449 = 0x5449
};



inline const char8* enumToString(PciDevice10A5 device10A5) // TEST: NO
{
    // COMMON_LT((" | device10A5 = %u", device10A5)); // Commented to avoid bad looking logs



    switch (device10A5)
    {
        case PciDevice10A5::NONE:        return "NONE";
        case PciDevice10A5::DEVICE_3052: return "DEVICE_3052";
        case PciDevice10A5::DEVICE_5449: return "DEVICE_5449";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10A5 device10A5) // TEST: NO
{
    // COMMON_LT((" | device10A5 = %u", device10A5)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10A5, enumToString(device10A5));

    return res;
}



inline const char8* enumToHumanString(PciDevice10A5 device10A5) // TEST: NO
{
    // COMMON_LT((" | device10A5 = %u", device10A5)); // Commented to avoid bad looking logs



    switch (device10A5)
    {
        case PciDevice10A5::DEVICE_3052: return "SmartPCI562 56K Modem";
        case PciDevice10A5::DEVICE_5449: return "SmartPCI561 modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10A5_PCIDEVICE10A5_H
