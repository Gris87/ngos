// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A88_PCIDEVICE1A88_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A88_PCIDEVICE1A88_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1A88: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4D45 = 0x4D45
};



inline const char8* enumToString(PciDevice1A88 device1A88) // TEST: NO
{
    // COMMON_LT((" | device1A88 = %u", device1A88)); // Commented to avoid bad looking logs



    switch (device1A88)
    {
        case PciDevice1A88::NONE:        return "NONE";
        case PciDevice1A88::DEVICE_4D45: return "DEVICE_4D45";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1A88 device1A88) // TEST: NO
{
    // COMMON_LT((" | device1A88 = %u", device1A88)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1A88, enumToString(device1A88));

    return res;
}



inline const char8* enumToHumanString(PciDevice1A88 device1A88) // TEST: NO
{
    // COMMON_LT((" | device1A88 = %u", device1A88)); // Commented to avoid bad looking logs



    switch (device1A88)
    {
        case PciDevice1A88::DEVICE_4D45: return "Multifunction IP core";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1A88_PCIDEVICE1A88_H
