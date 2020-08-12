// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E3_PCIDEVICE19E3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E3_PCIDEVICE19E3_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice19E3: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_5801 = 0x5801,
    DEVICE_5808 = 0x5808,
    DEVICE_DD52 = 0xDD52
};



inline const char8* enumToString(PciDevice19E3 device19E3) // TEST: NO
{
    // COMMON_LT((" | device19E3 = %u", device19E3)); // Commented to avoid bad looking logs



    switch (device19E3)
    {
        case PciDevice19E3::NONE:        return "NONE";
        case PciDevice19E3::DEVICE_5801: return "DEVICE_5801";
        case PciDevice19E3::DEVICE_5808: return "DEVICE_5808";
        case PciDevice19E3::DEVICE_DD52: return "DEVICE_DD52";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice19E3 device19E3) // TEST: NO
{
    // COMMON_LT((" | device19E3 = %u", device19E3)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device19E3, enumToString(device19E3));

    return res;
}



inline const char8* enumToHumanString(PciDevice19E3 device19E3) // TEST: NO
{
    // COMMON_LT((" | device19E3 = %u", device19E3)); // Commented to avoid bad looking logs



    switch (device19E3)
    {
        case PciDevice19E3::DEVICE_5801: return "DDRdrive X1";
        case PciDevice19E3::DEVICE_5808: return "DDRdrive X8";
        case PciDevice19E3::DEVICE_DD52: return "DDRdrive X1-30";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E3_PCIDEVICE19E3_H
