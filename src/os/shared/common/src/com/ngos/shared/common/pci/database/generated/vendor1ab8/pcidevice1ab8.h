// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AB8_PCIDEVICE1AB8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AB8_PCIDEVICE1AB8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AB8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4000 = 0x4000,
    DEVICE_4005 = 0x4005,
    DEVICE_4006 = 0x4006
};



inline const char8* enumToString(PciDevice1AB8 device1AB8) // TEST: NO
{
    // COMMON_LT((" | device1AB8 = %u", device1AB8)); // Commented to avoid bad looking logs



    switch (device1AB8)
    {
        case PciDevice1AB8::NONE:        return "NONE";
        case PciDevice1AB8::DEVICE_4000: return "DEVICE_4000";
        case PciDevice1AB8::DEVICE_4005: return "DEVICE_4005";
        case PciDevice1AB8::DEVICE_4006: return "DEVICE_4006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AB8 device1AB8) // TEST: NO
{
    // COMMON_LT((" | device1AB8 = %u", device1AB8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1AB8, enumToString(device1AB8));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AB8 device1AB8) // TEST: NO
{
    // COMMON_LT((" | device1AB8 = %u", device1AB8)); // Commented to avoid bad looking logs



    switch (device1AB8)
    {
        case PciDevice1AB8::DEVICE_4000: return "Virtual Machine Communication Interface";
        case PciDevice1AB8::DEVICE_4005: return "Accelerated Virtual Video Adapter";
        case PciDevice1AB8::DEVICE_4006: return "Memory Ballooning Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AB8_PCIDEVICE1AB8_H
