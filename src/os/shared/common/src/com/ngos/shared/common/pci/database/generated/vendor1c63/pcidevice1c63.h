// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C63_PCIDEVICE1C63_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C63_PCIDEVICE1C63_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C63: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0008 = 0x0008
};



inline const char8* enumToString(PciDevice1C63 device1C63) // TEST: NO
{
    // COMMON_LT((" | device1C63 = %u", device1C63)); // Commented to avoid bad looking logs



    switch (device1C63)
    {
        case PciDevice1C63::NONE:        return "NONE";
        case PciDevice1C63::DEVICE_0008: return "DEVICE_0008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C63 device1C63) // TEST: NO
{
    // COMMON_LT((" | device1C63 = %u", device1C63)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C63, enumToString(device1C63));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C63 device1C63) // TEST: NO
{
    // COMMON_LT((" | device1C63 = %u", device1C63)); // Commented to avoid bad looking logs



    switch (device1C63)
    {
        case PciDevice1C63::DEVICE_0008: return "K1927BB1Ya [EC8430] Angara Interconnection Network Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C63_PCIDEVICE1C63_H
