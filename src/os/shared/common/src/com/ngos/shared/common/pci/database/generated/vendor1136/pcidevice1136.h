// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1136_PCIDEVICE1136_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1136_PCIDEVICE1136_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1136: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002
};



inline const char8* enumToString(PciDevice1136 device1136) // TEST: NO
{
    // COMMON_LT((" | device1136 = %u", device1136)); // Commented to avoid bad looking logs



    switch (device1136)
    {
        case PciDevice1136::NONE:        return "NONE";
        case PciDevice1136::DEVICE_0002: return "DEVICE_0002";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1136 device1136) // TEST: NO
{
    // COMMON_LT((" | device1136 = %u", device1136)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1136, enumToString(device1136));

    return res;
}



inline const char8* enumToHumanString(PciDevice1136 device1136) // TEST: NO
{
    // COMMON_LT((" | device1136 = %u", device1136)); // Commented to avoid bad looking logs



    switch (device1136)
    {
        case PciDevice1136::DEVICE_0002: return "PCI-JTAG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1136_PCIDEVICE1136_H
