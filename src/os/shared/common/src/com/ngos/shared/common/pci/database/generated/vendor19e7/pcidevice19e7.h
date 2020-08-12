// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E7_PCIDEVICE19E7_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E7_PCIDEVICE19E7_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice19E7: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1003 = 0x1003,
    DEVICE_1004 = 0x1004,
    DEVICE_1005 = 0x1005
};



inline const char8* enumToString(PciDevice19E7 device19E7) // TEST: NO
{
    // COMMON_LT((" | device19E7 = %u", device19E7)); // Commented to avoid bad looking logs



    switch (device19E7)
    {
        case PciDevice19E7::NONE:        return "NONE";
        case PciDevice19E7::DEVICE_1001: return "DEVICE_1001";
        case PciDevice19E7::DEVICE_1002: return "DEVICE_1002";
        case PciDevice19E7::DEVICE_1003: return "DEVICE_1003";
        case PciDevice19E7::DEVICE_1004: return "DEVICE_1004";
        case PciDevice19E7::DEVICE_1005: return "DEVICE_1005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice19E7 device19E7) // TEST: NO
{
    // COMMON_LT((" | device19E7 = %u", device19E7)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device19E7, enumToString(device19E7));

    return res;
}



inline const char8* enumToHumanString(PciDevice19E7 device19E7) // TEST: NO
{
    // COMMON_LT((" | device19E7 = %u", device19E7)); // Commented to avoid bad looking logs



    switch (device19E7)
    {
        case PciDevice19E7::DEVICE_1001: return "STIX DSP Card";
        case PciDevice19E7::DEVICE_1002: return "STIX - 1 Port T1/E1 Card";
        case PciDevice19E7::DEVICE_1003: return "STIX - 2 Port T1/E1 Card";
        case PciDevice19E7::DEVICE_1004: return "STIX - 4 Port T1/E1 Card";
        case PciDevice19E7::DEVICE_1005: return "STIX - 4 Port FXS Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E7_PCIDEVICE19E7_H
