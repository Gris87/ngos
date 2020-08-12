// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCIDEVICE1412_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCIDEVICE1412_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1412: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1712 = 0x1712,
    DEVICE_1724 = 0x1724
};



inline const char8* enumToString(PciDevice1412 device1412) // TEST: NO
{
    // COMMON_LT((" | device1412 = %u", device1412)); // Commented to avoid bad looking logs



    switch (device1412)
    {
        case PciDevice1412::NONE:        return "NONE";
        case PciDevice1412::DEVICE_1712: return "DEVICE_1712";
        case PciDevice1412::DEVICE_1724: return "DEVICE_1724";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1412 device1412) // TEST: NO
{
    // COMMON_LT((" | device1412 = %u", device1412)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1412, enumToString(device1412));

    return res;
}



inline const char8* enumToHumanString(PciDevice1412 device1412) // TEST: NO
{
    // COMMON_LT((" | device1412 = %u", device1412)); // Commented to avoid bad looking logs



    switch (device1412)
    {
        case PciDevice1412::DEVICE_1712: return "ICE1712 [Envy24] PCI Multi-Channel I/O Controller";
        case PciDevice1412::DEVICE_1724: return "VT1720/24 [Envy24PT/HT] PCI Multi-Channel Audio Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1412_PCIDEVICE1412_H
