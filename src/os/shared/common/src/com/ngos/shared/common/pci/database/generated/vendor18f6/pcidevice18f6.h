// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F6_PCIDEVICE18F6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F6_PCIDEVICE18F6_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice18F6: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_1050 = 0x1050,
    DEVICE_1051 = 0x1051,
    DEVICE_2000 = 0x2000,
    DEVICE_2001 = 0x2001
};



inline const char8* enumToString(PciDevice18F6 device18F6) // TEST: NO
{
    // COMMON_LT((" | device18F6 = %u", device18F6)); // Commented to avoid bad looking logs



    switch (device18F6)
    {
        case PciDevice18F6::NONE:        return "NONE";
        case PciDevice18F6::DEVICE_1000: return "DEVICE_1000";
        case PciDevice18F6::DEVICE_1001: return "DEVICE_1001";
        case PciDevice18F6::DEVICE_1050: return "DEVICE_1050";
        case PciDevice18F6::DEVICE_1051: return "DEVICE_1051";
        case PciDevice18F6::DEVICE_2000: return "DEVICE_2000";
        case PciDevice18F6::DEVICE_2001: return "DEVICE_2001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice18F6 device18F6) // TEST: NO
{
    // COMMON_LT((" | device18F6 = %u", device18F6)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device18F6, enumToString(device18F6));

    return res;
}



inline const char8* enumToHumanString(PciDevice18F6 device18F6) // TEST: NO
{
    // COMMON_LT((" | device18F6 = %u", device18F6)); // Commented to avoid bad looking logs



    switch (device18F6)
    {
        case PciDevice18F6::DEVICE_1000: return "[Nexsis] Switch Virtual P2P PCIe Bridge";
        case PciDevice18F6::DEVICE_1001: return "[Texsis] Switch Virtual P2P PCIe Bridge";
        case PciDevice18F6::DEVICE_1050: return "[Nexsis] Switch Virtual P2P PCI Bridge";
        case PciDevice18F6::DEVICE_1051: return "[Texsis] Switch Virtual P2P PCI Bridge";
        case PciDevice18F6::DEVICE_2000: return "[Nexsis] Switch Integrated Mgmt. Endpoint";
        case PciDevice18F6::DEVICE_2001: return "[Texsis] Switch Integrated Mgmt. Endpoint";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR18F6_PCIDEVICE18F6_H
