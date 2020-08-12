// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1797_PCIDEVICE1797_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1797_PCIDEVICE1797_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1797: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5864 = 0x5864,
    DEVICE_6801 = 0x6801,
    DEVICE_6802 = 0x6802,
    DEVICE_6810 = 0x6810,
    DEVICE_6811 = 0x6811,
    DEVICE_6812 = 0x6812,
    DEVICE_6813 = 0x6813,
    DEVICE_6814 = 0x6814,
    DEVICE_6815 = 0x6815,
    DEVICE_6816 = 0x6816,
    DEVICE_6817 = 0x6817,
    DEVICE_6864 = 0x6864
};



inline const char8* enumToString(PciDevice1797 device1797) // TEST: NO
{
    // COMMON_LT((" | device1797 = %u", device1797)); // Commented to avoid bad looking logs



    switch (device1797)
    {
        case PciDevice1797::NONE:        return "NONE";
        case PciDevice1797::DEVICE_5864: return "DEVICE_5864";
        case PciDevice1797::DEVICE_6801: return "DEVICE_6801";
        case PciDevice1797::DEVICE_6802: return "DEVICE_6802";
        case PciDevice1797::DEVICE_6810: return "DEVICE_6810";
        case PciDevice1797::DEVICE_6811: return "DEVICE_6811";
        case PciDevice1797::DEVICE_6812: return "DEVICE_6812";
        case PciDevice1797::DEVICE_6813: return "DEVICE_6813";
        case PciDevice1797::DEVICE_6814: return "DEVICE_6814";
        case PciDevice1797::DEVICE_6815: return "DEVICE_6815";
        case PciDevice1797::DEVICE_6816: return "DEVICE_6816";
        case PciDevice1797::DEVICE_6817: return "DEVICE_6817";
        case PciDevice1797::DEVICE_6864: return "DEVICE_6864";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1797 device1797) // TEST: NO
{
    // COMMON_LT((" | device1797 = %u", device1797)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1797, enumToString(device1797));

    return res;
}



inline const char8* enumToHumanString(PciDevice1797 device1797) // TEST: NO
{
    // COMMON_LT((" | device1797 = %u", device1797)); // Commented to avoid bad looking logs



    switch (device1797)
    {
        case PciDevice1797::DEVICE_5864: return "TW5864 multimedia video controller";
        case PciDevice1797::DEVICE_6801: return "TW6802 multimedia video card";
        case PciDevice1797::DEVICE_6802: return "TW6802 multimedia other device";
        case PciDevice1797::DEVICE_6810: return "TW6816 multimedia video controller";
        case PciDevice1797::DEVICE_6811: return "TW6816 multimedia video controller";
        case PciDevice1797::DEVICE_6812: return "TW6816 multimedia video controller";
        case PciDevice1797::DEVICE_6813: return "TW6816 multimedia video controller";
        case PciDevice1797::DEVICE_6814: return "TW6816 multimedia video controller";
        case PciDevice1797::DEVICE_6815: return "TW6816 multimedia video controller";
        case PciDevice1797::DEVICE_6816: return "TW6816 multimedia video controller";
        case PciDevice1797::DEVICE_6817: return "TW6816 multimedia video controller";
        case PciDevice1797::DEVICE_6864: return "TW6864 multimedia video controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1797_PCIDEVICE1797_H
