// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1138_PCIDEVICE1138_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1138_PCIDEVICE1138_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1138: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8905 = 0x8905
};



inline const char8* enumToString(PciDevice1138 device1138) // TEST: NO
{
    // COMMON_LT((" | device1138 = %u", device1138)); // Commented to avoid bad looking logs



    switch (device1138)
    {
        case PciDevice1138::NONE:        return "NONE";
        case PciDevice1138::DEVICE_8905: return "DEVICE_8905";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1138 device1138) // TEST: NO
{
    // COMMON_LT((" | device1138 = %u", device1138)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1138, enumToString(device1138));

    return res;
}



inline const char8* enumToHumanString(PciDevice1138 device1138) // TEST: NO
{
    // COMMON_LT((" | device1138 = %u", device1138)); // Commented to avoid bad looking logs



    switch (device1138)
    {
        case PciDevice1138::DEVICE_8905: return "8905 [STD 32 Bridge]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1138_PCIDEVICE1138_H
