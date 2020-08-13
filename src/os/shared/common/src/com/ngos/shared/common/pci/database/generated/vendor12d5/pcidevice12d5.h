// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D5_PCIDEVICE12D5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D5_PCIDEVICE12D5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice12D5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_1000 = 0x1000
};



inline const char8* enumToString(PciDevice12D5 device12D5) // TEST: NO
{
    // COMMON_LT((" | device12D5 = %u", device12D5)); // Commented to avoid bad looking logs



    switch (device12D5)
    {
        case PciDevice12D5::NONE:        return "NONE";
        case PciDevice12D5::DEVICE_0003: return "DEVICE_0003";
        case PciDevice12D5::DEVICE_1000: return "DEVICE_1000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice12D5 device12D5) // TEST: NO
{
    // COMMON_LT((" | device12D5 = %u", device12D5)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device12D5, enumToString(device12D5));

    return res;
}



inline const char8* enumToHumanString(PciDevice12D5 device12D5) // TEST: NO
{
    // COMMON_LT((" | device12D5 = %u", device12D5)); // Commented to avoid bad looking logs



    switch (device12D5)
    {
        case PciDevice12D5::DEVICE_0003: return "BSP16";
        case PciDevice12D5::DEVICE_1000: return "BSP15";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D5_PCIDEVICE12D5_H
