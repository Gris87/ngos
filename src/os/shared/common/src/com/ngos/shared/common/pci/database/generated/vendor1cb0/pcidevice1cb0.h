// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCIDEVICE1CB0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCIDEVICE1CB0_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1CB0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_D000 = 0xD000
};



inline const char8* enumToString(PciDevice1CB0 device1CB0) // TEST: NO
{
    // COMMON_LT((" | device1CB0 = %u", device1CB0)); // Commented to avoid bad looking logs



    switch (device1CB0)
    {
        case PciDevice1CB0::NONE:        return "NONE";
        case PciDevice1CB0::DEVICE_D000: return "DEVICE_D000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1CB0 device1CB0) // TEST: NO
{
    // COMMON_LT((" | device1CB0 = %u", device1CB0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1CB0, enumToString(device1CB0));

    return res;
}



inline const char8* enumToHumanString(PciDevice1CB0 device1CB0) // TEST: NO
{
    // COMMON_LT((" | device1CB0 = %u", device1CB0)); // Commented to avoid bad looking logs



    switch (device1CB0)
    {
        case PciDevice1CB0::DEVICE_D000: return "Venice NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCIDEVICE1CB0_H
