// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5455_PCIDEVICE5455_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5455_PCIDEVICE5455_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5455: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4458 = 0x4458
};



inline const char8* enumToString(PciDevice5455 device5455) // TEST: NO
{
    // COMMON_LT((" | device5455 = %u", device5455)); // Commented to avoid bad looking logs



    switch (device5455)
    {
        case PciDevice5455::NONE:        return "NONE";
        case PciDevice5455::DEVICE_4458: return "DEVICE_4458";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5455 device5455) // TEST: NO
{
    // COMMON_LT((" | device5455 = %u", device5455)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5455, enumToString(device5455));

    return res;
}



inline const char8* enumToHumanString(PciDevice5455 device5455) // TEST: NO
{
    // COMMON_LT((" | device5455 = %u", device5455)); // Commented to avoid bad looking logs



    switch (device5455)
    {
        case PciDevice5455::DEVICE_4458: return "S5933";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5455_PCIDEVICE5455_H
