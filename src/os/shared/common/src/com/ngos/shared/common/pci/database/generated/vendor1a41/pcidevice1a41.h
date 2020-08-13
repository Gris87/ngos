// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A41_PCIDEVICE1A41_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A41_PCIDEVICE1A41_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A41: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0200 = 0x0200,
    DEVICE_0201 = 0x0201,
    DEVICE_2000 = 0x2000
};



inline const char8* enumToString(PciDevice1A41 device1A41) // TEST: NO
{
    // COMMON_LT((" | device1A41 = %u", device1A41)); // Commented to avoid bad looking logs



    switch (device1A41)
    {
        case PciDevice1A41::NONE:        return "NONE";
        case PciDevice1A41::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1A41::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1A41::DEVICE_0200: return "DEVICE_0200";
        case PciDevice1A41::DEVICE_0201: return "DEVICE_0201";
        case PciDevice1A41::DEVICE_2000: return "DEVICE_2000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A41 device1A41) // TEST: NO
{
    // COMMON_LT((" | device1A41 = %u", device1A41)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A41, enumToString(device1A41));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A41 device1A41) // TEST: NO
{
    // COMMON_LT((" | device1A41 = %u", device1A41)); // Commented to avoid bad looking logs



    switch (device1A41)
    {
        case PciDevice1A41::DEVICE_0001: return "TILE64 processor";
        case PciDevice1A41::DEVICE_0002: return "TILEPro processor";
        case PciDevice1A41::DEVICE_0200: return "TILE-Gx processor";
        case PciDevice1A41::DEVICE_0201: return "TILE-Gx Processor Virtual Function";
        case PciDevice1A41::DEVICE_2000: return "TILE-Gx PCI Express Root Port";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A41_PCIDEVICE1A41_H
