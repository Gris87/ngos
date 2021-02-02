// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5555_PCIDEVICE5555_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5555_PCIDEVICE5555_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice5555: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_3B00 = 0x3B00
};



inline const char8* enumToString(PciDevice5555 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5555::NONE:        return "NONE";
        case PciDevice5555::DEVICE_0003: return "DEVICE_0003";
        case PciDevice5555::DEVICE_3B00: return "DEVICE_3B00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice5555 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice5555 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice5555::DEVICE_0003: return "TURBOstor HFP-832 [HiPPI NIC]";
        case PciDevice5555::DEVICE_3B00: return "Epiphan DVI2PCIe video capture card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5555_PCIDEVICE5555_H
