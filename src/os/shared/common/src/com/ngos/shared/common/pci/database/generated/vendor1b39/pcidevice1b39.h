// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B39_PCIDEVICE1B39_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B39_PCIDEVICE1B39_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B39: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice1B39 device1B39) // TEST: NO
{
    // COMMON_LT((" | device1B39 = %u", device1B39)); // Commented to avoid bad looking logs



    switch (device1B39)
    {
        case PciDevice1B39::NONE:        return "NONE";
        case PciDevice1B39::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B39 device1B39) // TEST: NO
{
    // COMMON_LT((" | device1B39 = %u", device1B39)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B39, enumToString(device1B39));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B39 device1B39) // TEST: NO
{
    // COMMON_LT((" | device1B39 = %u", device1B39)); // Commented to avoid bad looking logs



    switch (device1B39)
    {
        case PciDevice1B39::DEVICE_0001: return "S1120 PCIe Accelerator SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B39_PCIDEVICE1B39_H
