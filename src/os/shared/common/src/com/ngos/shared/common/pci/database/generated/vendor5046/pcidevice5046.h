// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5046_PCIDEVICE5046_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5046_PCIDEVICE5046_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5046: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1001 = 0x1001
};



inline const char8* enumToString(PciDevice5046 device5046) // TEST: NO
{
    // COMMON_LT((" | device5046 = %u", device5046)); // Commented to avoid bad looking logs



    switch (device5046)
    {
        case PciDevice5046::NONE:        return "NONE";
        case PciDevice5046::DEVICE_1001: return "DEVICE_1001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5046 device5046) // TEST: NO
{
    // COMMON_LT((" | device5046 = %u", device5046)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device5046, enumToString(device5046));

    return res;
}



inline const char8* enumToHumanString(PciDevice5046 device5046) // TEST: NO
{
    // COMMON_LT((" | device5046 = %u", device5046)); // Commented to avoid bad looking logs



    switch (device5046)
    {
        case PciDevice5046::DEVICE_1001: return "PCI Radio";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5046_PCIDEVICE5046_H
