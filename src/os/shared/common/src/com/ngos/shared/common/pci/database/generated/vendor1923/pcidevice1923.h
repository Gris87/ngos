// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1923_PCIDEVICE1923_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1923_PCIDEVICE1923_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1923: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0040 = 0x0040,
    DEVICE_0100 = 0x0100,
    DEVICE_0300 = 0x0300,
    DEVICE_0400 = 0x0400
};



inline const char8* enumToString(PciDevice1923 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1923::NONE:        return "NONE";
        case PciDevice1923::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1923::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1923::DEVICE_0300: return "DEVICE_0300";
        case PciDevice1923::DEVICE_0400: return "DEVICE_0400";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1923 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1923 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1923::DEVICE_0040: return "A200/Remora FXO/FXS Analog AFT card";
        case PciDevice1923::DEVICE_0100: return "A104d QUAD T1/E1 AFT card";
        case PciDevice1923::DEVICE_0300: return "A101 single-port T1/E1";
        case PciDevice1923::DEVICE_0400: return "A104u Quad T1/E1 AFT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1923_PCIDEVICE1923_H
