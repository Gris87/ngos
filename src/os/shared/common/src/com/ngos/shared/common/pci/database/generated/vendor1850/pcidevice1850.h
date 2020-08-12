// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1850_PCIDEVICE1850_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1850_PCIDEVICE1850_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1850: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0048 = 0x0048
};



inline const char8* enumToString(PciDevice1850 device1850) // TEST: NO
{
    // COMMON_LT((" | device1850 = %u", device1850)); // Commented to avoid bad looking logs



    switch (device1850)
    {
        case PciDevice1850::NONE:        return "NONE";
        case PciDevice1850::DEVICE_0048: return "DEVICE_0048";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1850 device1850) // TEST: NO
{
    // COMMON_LT((" | device1850 = %u", device1850)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1850, enumToString(device1850));

    return res;
}



inline const char8* enumToHumanString(PciDevice1850 device1850) // TEST: NO
{
    // COMMON_LT((" | device1850 = %u", device1850)); // Commented to avoid bad looking logs



    switch (device1850)
    {
        case PciDevice1850::DEVICE_0048: return "EK220-66401 Computer Interface Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1850_PCIDEVICE1850_H
