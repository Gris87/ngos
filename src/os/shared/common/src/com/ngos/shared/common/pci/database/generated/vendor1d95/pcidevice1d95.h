// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D95_PCIDEVICE1D95_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D95_PCIDEVICE1D95_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D95: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice1D95 device1D95) // TEST: NO
{
    // COMMON_LT((" | device1D95 = %u", device1D95)); // Commented to avoid bad looking logs



    switch (device1D95)
    {
        case PciDevice1D95::NONE:        return "NONE";
        case PciDevice1D95::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1D95::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D95 device1D95) // TEST: NO
{
    // COMMON_LT((" | device1D95 = %u", device1D95)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1D95, enumToString(device1D95));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D95 device1D95) // TEST: NO
{
    // COMMON_LT((" | device1D95 = %u", device1D95)); // Commented to avoid bad looking logs



    switch (device1D95)
    {
        case PciDevice1D95::DEVICE_0001: return "Colossus GC2 [C2]";
        case PciDevice1D95::DEVICE_0002: return "Colossus GC1 [S1]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D95_PCIDEVICE1D95_H
