// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EA_PCIDEVICE10EA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EA_PCIDEVICE10EA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10EA: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1680 = 0x1680,
    DEVICE_1682 = 0x1682,
    DEVICE_1683 = 0x1683,
    DEVICE_2000 = 0x2000,
    DEVICE_2010 = 0x2010,
    DEVICE_5000 = 0x5000,
    DEVICE_5050 = 0x5050,
    DEVICE_5202 = 0x5202,
    DEVICE_5252 = 0x5252
};



inline const char8* enumToString(PciDevice10EA device10EA) // TEST: NO
{
    // COMMON_LT((" | device10EA = %u", device10EA)); // Commented to avoid bad looking logs



    switch (device10EA)
    {
        case PciDevice10EA::NONE:        return "NONE";
        case PciDevice10EA::DEVICE_1680: return "DEVICE_1680";
        case PciDevice10EA::DEVICE_1682: return "DEVICE_1682";
        case PciDevice10EA::DEVICE_1683: return "DEVICE_1683";
        case PciDevice10EA::DEVICE_2000: return "DEVICE_2000";
        case PciDevice10EA::DEVICE_2010: return "DEVICE_2010";
        case PciDevice10EA::DEVICE_5000: return "DEVICE_5000";
        case PciDevice10EA::DEVICE_5050: return "DEVICE_5050";
        case PciDevice10EA::DEVICE_5202: return "DEVICE_5202";
        case PciDevice10EA::DEVICE_5252: return "DEVICE_5252";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10EA device10EA) // TEST: NO
{
    // COMMON_LT((" | device10EA = %u", device10EA)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10EA, enumToString(device10EA));

    return res;
}



inline const char8* enumToHumanString(PciDevice10EA device10EA) // TEST: NO
{
    // COMMON_LT((" | device10EA = %u", device10EA)); // Commented to avoid bad looking logs



    switch (device10EA)
    {
        case PciDevice10EA::DEVICE_1680: return "IGA-1680";
        case PciDevice10EA::DEVICE_1682: return "IGA-1682";
        case PciDevice10EA::DEVICE_1683: return "IGA-1683";
        case PciDevice10EA::DEVICE_2000: return "CyberPro 2000";
        case PciDevice10EA::DEVICE_2010: return "CyberPro 2000A";
        case PciDevice10EA::DEVICE_5000: return "CyberPro 5000";
        case PciDevice10EA::DEVICE_5050: return "CyberPro 5050";
        case PciDevice10EA::DEVICE_5202: return "CyberPro 5202";
        case PciDevice10EA::DEVICE_5252: return "CyberPro5252";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EA_PCIDEVICE10EA_H
