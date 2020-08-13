// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1435_PCIDEVICE1435_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1435_PCIDEVICE1435_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1435: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4520 = 0x4520,
    DEVICE_6020 = 0x6020,
    DEVICE_6030 = 0x6030,
    DEVICE_6420 = 0x6420,
    DEVICE_6430 = 0x6430,
    DEVICE_6431 = 0x6431,
    DEVICE_7520 = 0x7520,
    DEVICE_7540 = 0x7540,
    DEVICE_7820 = 0x7820
};



inline const char8* enumToString(PciDevice1435 device1435) // TEST: NO
{
    // COMMON_LT((" | device1435 = %u", device1435)); // Commented to avoid bad looking logs



    switch (device1435)
    {
        case PciDevice1435::NONE:        return "NONE";
        case PciDevice1435::DEVICE_4520: return "DEVICE_4520";
        case PciDevice1435::DEVICE_6020: return "DEVICE_6020";
        case PciDevice1435::DEVICE_6030: return "DEVICE_6030";
        case PciDevice1435::DEVICE_6420: return "DEVICE_6420";
        case PciDevice1435::DEVICE_6430: return "DEVICE_6430";
        case PciDevice1435::DEVICE_6431: return "DEVICE_6431";
        case PciDevice1435::DEVICE_7520: return "DEVICE_7520";
        case PciDevice1435::DEVICE_7540: return "DEVICE_7540";
        case PciDevice1435::DEVICE_7820: return "DEVICE_7820";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1435 device1435) // TEST: NO
{
    // COMMON_LT((" | device1435 = %u", device1435)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1435, enumToString(device1435));

    return res;
}



inline const char8* enumToHumanString(PciDevice1435 device1435) // TEST: NO
{
    // COMMON_LT((" | device1435 = %u", device1435)); // Commented to avoid bad looking logs



    switch (device1435)
    {
        case PciDevice1435::DEVICE_4520: return "PCI4520";
        case PciDevice1435::DEVICE_6020: return "SPM6020";
        case PciDevice1435::DEVICE_6030: return "SPM6030";
        case PciDevice1435::DEVICE_6420: return "SPM186420";
        case PciDevice1435::DEVICE_6430: return "SPM176430";
        case PciDevice1435::DEVICE_6431: return "SPM176431";
        case PciDevice1435::DEVICE_7520: return "DM7520";
        case PciDevice1435::DEVICE_7540: return "SDM7540";
        case PciDevice1435::DEVICE_7820: return "DM7820";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1435_PCIDEVICE1435_H
