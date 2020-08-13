// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1139_PCIDEVICE1139_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1139_PCIDEVICE1139_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1139: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1139 device1139) // TEST: NO
{
    // COMMON_LT((" | device1139 = %u", device1139)); // Commented to avoid bad looking logs



    switch (device1139)
    {
        case PciDevice1139::NONE:        return "NONE";
        case PciDevice1139::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1139 device1139) // TEST: NO
{
    // COMMON_LT((" | device1139 = %u", device1139)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1139, enumToString(device1139));

    return res;
}



inline const char8* enumToHumanString(PciDevice1139 device1139) // TEST: NO
{
    // COMMON_LT((" | device1139 = %u", device1139)); // Commented to avoid bad looking logs



    switch (device1139)
    {
        case PciDevice1139::DEVICE_0001: return "VGA Compatible 3D Graphics";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1139_PCIDEVICE1139_H
