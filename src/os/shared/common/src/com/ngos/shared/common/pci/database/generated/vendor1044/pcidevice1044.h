// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCIDEVICE1044_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCIDEVICE1044_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1044: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1012 = 0x1012,
    DEVICE_A400 = 0xA400,
    DEVICE_A500 = 0xA500,
    DEVICE_A501 = 0xA501,
    DEVICE_A511 = 0xA511,
    DEVICE_C066 = 0xC066
};



inline const char8* enumToString(PciDevice1044 device1044) // TEST: NO
{
    // COMMON_LT((" | device1044 = %u", device1044)); // Commented to avoid bad looking logs



    switch (device1044)
    {
        case PciDevice1044::NONE:        return "NONE";
        case PciDevice1044::DEVICE_1012: return "DEVICE_1012";
        case PciDevice1044::DEVICE_A400: return "DEVICE_A400";
        case PciDevice1044::DEVICE_A500: return "DEVICE_A500";
        case PciDevice1044::DEVICE_A501: return "DEVICE_A501";
        case PciDevice1044::DEVICE_A511: return "DEVICE_A511";
        case PciDevice1044::DEVICE_C066: return "DEVICE_C066";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1044 device1044) // TEST: NO
{
    // COMMON_LT((" | device1044 = %u", device1044)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1044, enumToString(device1044));

    return res;
}



inline const char8* enumToHumanString(PciDevice1044 device1044) // TEST: NO
{
    // COMMON_LT((" | device1044 = %u", device1044)); // Commented to avoid bad looking logs



    switch (device1044)
    {
        case PciDevice1044::DEVICE_1012: return "Domino RAID Engine";
        case PciDevice1044::DEVICE_A400: return "SmartCache/Raid I-IV Controller";
        case PciDevice1044::DEVICE_A500: return "PCI Bridge";
        case PciDevice1044::DEVICE_A501: return "SmartRAID V Controller";
        case PciDevice1044::DEVICE_A511: return "SmartRAID V Controller";
        case PciDevice1044::DEVICE_C066: return "3010S Ultra3 Dual Channel";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1044_PCIDEVICE1044_H
