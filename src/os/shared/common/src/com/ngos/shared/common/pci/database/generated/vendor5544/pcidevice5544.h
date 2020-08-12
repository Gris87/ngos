// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5544_PCIDEVICE5544_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5544_PCIDEVICE5544_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5544: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice5544 device5544) // TEST: NO
{
    // COMMON_LT((" | device5544 = %u", device5544)); // Commented to avoid bad looking logs



    switch (device5544)
    {
        case PciDevice5544::NONE:        return "NONE";
        case PciDevice5544::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5544 device5544) // TEST: NO
{
    // COMMON_LT((" | device5544 = %u", device5544)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5544, enumToString(device5544));

    return res;
}



inline const char8* enumToHumanString(PciDevice5544 device5544) // TEST: NO
{
    // COMMON_LT((" | device5544 = %u", device5544)); // Commented to avoid bad looking logs



    switch (device5544)
    {
        case PciDevice5544::DEVICE_0001: return "I-30xx Scanner Interface";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5544_PCIDEVICE5544_H
