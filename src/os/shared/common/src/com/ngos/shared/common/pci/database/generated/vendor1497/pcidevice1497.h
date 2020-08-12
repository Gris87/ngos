// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1497_PCIDEVICE1497_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1497_PCIDEVICE1497_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1497: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1497 = 0x1497
};



inline const char8* enumToString(PciDevice1497 device1497) // TEST: NO
{
    // COMMON_LT((" | device1497 = %u", device1497)); // Commented to avoid bad looking logs



    switch (device1497)
    {
        case PciDevice1497::NONE:        return "NONE";
        case PciDevice1497::DEVICE_1497: return "DEVICE_1497";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1497 device1497) // TEST: NO
{
    // COMMON_LT((" | device1497 = %u", device1497)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1497, enumToString(device1497));

    return res;
}



inline const char8* enumToHumanString(PciDevice1497 device1497) // TEST: NO
{
    // COMMON_LT((" | device1497 = %u", device1497)); // Commented to avoid bad looking logs



    switch (device1497)
    {
        case PciDevice1497::DEVICE_1497: return "SMA Technologie AG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1497_PCIDEVICE1497_H
