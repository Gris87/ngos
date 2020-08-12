// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1267_PCIDEVICE1267_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1267_PCIDEVICE1267_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1267: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5352 = 0x5352,
    DEVICE_5A4B = 0x5A4B
};



inline const char8* enumToString(PciDevice1267 device1267) // TEST: NO
{
    // COMMON_LT((" | device1267 = %u", device1267)); // Commented to avoid bad looking logs



    switch (device1267)
    {
        case PciDevice1267::NONE:        return "NONE";
        case PciDevice1267::DEVICE_5352: return "DEVICE_5352";
        case PciDevice1267::DEVICE_5A4B: return "DEVICE_5A4B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1267 device1267) // TEST: NO
{
    // COMMON_LT((" | device1267 = %u", device1267)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1267, enumToString(device1267));

    return res;
}



inline const char8* enumToHumanString(PciDevice1267 device1267) // TEST: NO
{
    // COMMON_LT((" | device1267 = %u", device1267)); // Commented to avoid bad looking logs



    switch (device1267)
    {
        case PciDevice1267::DEVICE_5352: return "PCR2101";
        case PciDevice1267::DEVICE_5A4B: return "Telsat Turbo";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1267_PCIDEVICE1267_H
