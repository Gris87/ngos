// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B26_PCIDEVICE1B26_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B26_PCIDEVICE1B26_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B26: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_C132 = 0xC132,
    DEVICE_C1C0 = 0xC1C0,
    DEVICE_C1C1 = 0xC1C1,
    DEVICE_C250 = 0xC250,
    DEVICE_C251 = 0xC251,
    DEVICE_C2C0 = 0xC2C0,
    DEVICE_C2C1 = 0xC2C1,
    DEVICE_CB20 = 0xCB20,
    DEVICE_CB40 = 0xCB40,
    DEVICE_CB80 = 0xCB80
};



inline const char8* enumToString(PciDevice1B26 device1B26) // TEST: NO
{
    // COMMON_LT((" | device1B26 = %u", device1B26)); // Commented to avoid bad looking logs



    switch (device1B26)
    {
        case PciDevice1B26::NONE:        return "NONE";
        case PciDevice1B26::DEVICE_C132: return "DEVICE_C132";
        case PciDevice1B26::DEVICE_C1C0: return "DEVICE_C1C0";
        case PciDevice1B26::DEVICE_C1C1: return "DEVICE_C1C1";
        case PciDevice1B26::DEVICE_C250: return "DEVICE_C250";
        case PciDevice1B26::DEVICE_C251: return "DEVICE_C251";
        case PciDevice1B26::DEVICE_C2C0: return "DEVICE_C2C0";
        case PciDevice1B26::DEVICE_C2C1: return "DEVICE_C2C1";
        case PciDevice1B26::DEVICE_CB20: return "DEVICE_CB20";
        case PciDevice1B26::DEVICE_CB40: return "DEVICE_CB40";
        case PciDevice1B26::DEVICE_CB80: return "DEVICE_CB80";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B26 device1B26) // TEST: NO
{
    // COMMON_LT((" | device1B26 = %u", device1B26)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B26, enumToString(device1B26));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B26 device1B26) // TEST: NO
{
    // COMMON_LT((" | device1B26 = %u", device1B26)); // Commented to avoid bad looking logs



    switch (device1B26)
    {
        case PciDevice1B26::DEVICE_C132: return "COMBO-LXT155";
        case PciDevice1B26::DEVICE_C1C0: return "NFB-100G1-e0";
        case PciDevice1B26::DEVICE_C1C1: return "NFB-100G1-e1";
        case PciDevice1B26::DEVICE_C250: return "NFB-200G2-master";
        case PciDevice1B26::DEVICE_C251: return "NFB-200G2-slave";
        case PciDevice1B26::DEVICE_C2C0: return "NFB-100G2-e0";
        case PciDevice1B26::DEVICE_C2C1: return "NFB-100G2-e1";
        case PciDevice1B26::DEVICE_CB20: return "COMBO-20G";
        case PciDevice1B26::DEVICE_CB40: return "COMBO-40G";
        case PciDevice1B26::DEVICE_CB80: return "NFB-40G2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B26_PCIDEVICE1B26_H
