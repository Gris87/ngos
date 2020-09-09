// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE8_PCIDEVICE1AE8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE8_PCIDEVICE1AE8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AE8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0A40 = 0x0A40,
    DEVICE_0A41 = 0x0A41,
    DEVICE_0A44 = 0x0A44,
    DEVICE_0E44 = 0x0E44
};



inline const char8* enumToString(PciDevice1AE8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AE8::NONE:        return "NONE";
        case PciDevice1AE8::DEVICE_0A40: return "DEVICE_0A40";
        case PciDevice1AE8::DEVICE_0A41: return "DEVICE_0A41";
        case PciDevice1AE8::DEVICE_0A44: return "DEVICE_0A44";
        case PciDevice1AE8::DEVICE_0E44: return "DEVICE_0E44";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AE8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AE8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AE8::DEVICE_0A40: return "microEnable IV-BASE x1";
        case PciDevice1AE8::DEVICE_0A41: return "microEnable IV-FULL x1";
        case PciDevice1AE8::DEVICE_0A44: return "microEnable IV-FULL x4";
        case PciDevice1AE8::DEVICE_0E44: return "microEnable IV-GigE x4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE8_PCIDEVICE1AE8_H
