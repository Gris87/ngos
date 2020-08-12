// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCIDEVICE4C53_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCIDEVICE4C53_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4C53: u16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001
};



inline const char8* enumToString(PciDevice4C53 device4C53) // TEST: NO
{
    // COMMON_LT((" | device4C53 = %u", device4C53)); // Commented to avoid bad looking logs



    switch (device4C53)
    {
        case PciDevice4C53::DEVICE_0000: return "DEVICE_0000";
        case PciDevice4C53::DEVICE_0001: return "DEVICE_0001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4C53 device4C53) // TEST: NO
{
    // COMMON_LT((" | device4C53 = %u", device4C53)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device4C53, enumToString(device4C53));

    return res;
}



inline const char8* enumToHumanString(PciDevice4C53 device4C53) // TEST: NO
{
    // COMMON_LT((" | device4C53 = %u", device4C53)); // Commented to avoid bad looking logs



    switch (device4C53)
    {
        case PciDevice4C53::DEVICE_0000: return "PLUSTEST device";
        case PciDevice4C53::DEVICE_0001: return "PLUSTEST-MM device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4C53_PCIDEVICE4C53_H
