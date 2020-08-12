// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17A0_PCIDEVICE17A0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17A0_PCIDEVICE17A0_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice17A0: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_7163 = 0x7163,
    DEVICE_8083 = 0x8083,
    DEVICE_8084 = 0x8084,
    DEVICE_9750 = 0x9750
};



inline const char8* enumToString(PciDevice17A0 device17A0) // TEST: NO
{
    // COMMON_LT((" | device17A0 = %u", device17A0)); // Commented to avoid bad looking logs



    switch (device17A0)
    {
        case PciDevice17A0::NONE:        return "NONE";
        case PciDevice17A0::DEVICE_7163: return "DEVICE_7163";
        case PciDevice17A0::DEVICE_8083: return "DEVICE_8083";
        case PciDevice17A0::DEVICE_8084: return "DEVICE_8084";
        case PciDevice17A0::DEVICE_9750: return "DEVICE_9750";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice17A0 device17A0) // TEST: NO
{
    // COMMON_LT((" | device17A0 = %u", device17A0)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device17A0, enumToString(device17A0));

    return res;
}



inline const char8* enumToHumanString(PciDevice17A0 device17A0) // TEST: NO
{
    // COMMON_LT((" | device17A0 = %u", device17A0)); // Commented to avoid bad looking logs



    switch (device17A0)
    {
        case PciDevice17A0::DEVICE_7163: return "GL9701 PCIe to PCI Bridge";
        case PciDevice17A0::DEVICE_8083: return "GL880 USB 1.1 UHCI controller";
        case PciDevice17A0::DEVICE_8084: return "GL880 USB 2.0 EHCI controller";
        case PciDevice17A0::DEVICE_9750: return "GL9750 SD Host Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR17A0_PCIDEVICE17A0_H
