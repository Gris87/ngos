// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19BA_PCIDEVICE19BA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19BA_PCIDEVICE19BA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice19BA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_2330 = 0x2330
};



inline const char8* enumToString(PciDevice19BA device19BA) // TEST: NO
{
    // COMMON_LT((" | device19BA = %u", device19BA)); // Commented to avoid bad looking logs



    switch (device19BA)
    {
        case PciDevice19BA::NONE:        return "NONE";
        case PciDevice19BA::DEVICE_2330: return "DEVICE_2330";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice19BA device19BA) // TEST: NO
{
    // COMMON_LT((" | device19BA = %u", device19BA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device19BA, enumToString(device19BA));

    return res;
}



inline const char8* enumToHumanString(PciDevice19BA device19BA) // TEST: NO
{
    // COMMON_LT((" | device19BA = %u", device19BA)); // Commented to avoid bad looking logs



    switch (device19BA)
    {
        case PciDevice19BA::DEVICE_2330: return "ZyWALL Turbo Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19BA_PCIDEVICE19BA_H
