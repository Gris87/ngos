// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1227_PCIDEVICE1227_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1227_PCIDEVICE1227_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1227: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0006 = 0x0006,
    DEVICE_0023 = 0x0023,
    DEVICE_0045 = 0x0045,
    DEVICE_004A = 0x004A
};



inline const char8* enumToString(PciDevice1227 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1227::NONE:        return "NONE";
        case PciDevice1227::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1227::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1227::DEVICE_0045: return "DEVICE_0045";
        case PciDevice1227::DEVICE_004A: return "DEVICE_004A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1227 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1227 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1227::DEVICE_0006: return "Raptor GFX 8P";
        case PciDevice1227::DEVICE_0023: return "Raptor GFX [1100T]";
        case PciDevice1227::DEVICE_0045: return "Raptor 4000-L [Linux version]";
        case PciDevice1227::DEVICE_004A: return "Raptor 4000-LR-L [Linux version]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1227_PCIDEVICE1227_H
