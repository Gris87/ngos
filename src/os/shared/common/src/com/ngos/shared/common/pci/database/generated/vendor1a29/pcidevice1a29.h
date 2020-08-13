// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A29_PCIDEVICE1A29_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A29_PCIDEVICE1A29_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A29: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4338 = 0x4338,
    DEVICE_4E36 = 0x4E36,
    DEVICE_4E37 = 0x4E37
};



inline const char8* enumToString(PciDevice1A29 device1A29) // TEST: NO
{
    // COMMON_LT((" | device1A29 = %u", device1A29)); // Commented to avoid bad looking logs



    switch (device1A29)
    {
        case PciDevice1A29::NONE:        return "NONE";
        case PciDevice1A29::DEVICE_4338: return "DEVICE_4338";
        case PciDevice1A29::DEVICE_4E36: return "DEVICE_4E36";
        case PciDevice1A29::DEVICE_4E37: return "DEVICE_4E37";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A29 device1A29) // TEST: NO
{
    // COMMON_LT((" | device1A29 = %u", device1A29)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A29, enumToString(device1A29));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A29 device1A29) // TEST: NO
{
    // COMMON_LT((" | device1A29 = %u", device1A29)); // Commented to avoid bad looking logs



    switch (device1A29)
    {
        case PciDevice1A29::DEVICE_4338: return "CP8 Content Processor ASIC";
        case PciDevice1A29::DEVICE_4E36: return "NP6 Network Processor";
        case PciDevice1A29::DEVICE_4E37: return "NP7 Network Processor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A29_PCIDEVICE1A29_H
