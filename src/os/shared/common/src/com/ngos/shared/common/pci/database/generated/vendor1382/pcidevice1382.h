// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1382_PCIDEVICE1382_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1382_PCIDEVICE1382_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1382: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_2008 = 0x2008,
    DEVICE_2048 = 0x2048,
    DEVICE_2088 = 0x2088,
    DEVICE_20C8 = 0x20C8,
    DEVICE_4008 = 0x4008,
    DEVICE_4010 = 0x4010,
    DEVICE_4048 = 0x4048,
    DEVICE_4088 = 0x4088,
    DEVICE_4248 = 0x4248,
    DEVICE_4424 = 0x4424
};



inline const char8* enumToString(PciDevice1382 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1382::NONE:        return "NONE";
        case PciDevice1382::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1382::DEVICE_2008: return "DEVICE_2008";
        case PciDevice1382::DEVICE_2048: return "DEVICE_2048";
        case PciDevice1382::DEVICE_2088: return "DEVICE_2088";
        case PciDevice1382::DEVICE_20C8: return "DEVICE_20C8";
        case PciDevice1382::DEVICE_4008: return "DEVICE_4008";
        case PciDevice1382::DEVICE_4010: return "DEVICE_4010";
        case PciDevice1382::DEVICE_4048: return "DEVICE_4048";
        case PciDevice1382::DEVICE_4088: return "DEVICE_4088";
        case PciDevice1382::DEVICE_4248: return "DEVICE_4248";
        case PciDevice1382::DEVICE_4424: return "DEVICE_4424";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1382 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1382 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1382::DEVICE_0001: return "ARC88 audio recording card";
        case PciDevice1382::DEVICE_2008: return "Prodif 96 Pro sound system";
        case PciDevice1382::DEVICE_2048: return "Prodif Plus sound system";
        case PciDevice1382::DEVICE_2088: return "Marc 8 Midi sound system";
        case PciDevice1382::DEVICE_20C8: return "Marc A sound system";
        case PciDevice1382::DEVICE_4008: return "Marc 2 sound system";
        case PciDevice1382::DEVICE_4010: return "Marc 2 Pro sound system";
        case PciDevice1382::DEVICE_4048: return "Marc 4 MIDI sound system";
        case PciDevice1382::DEVICE_4088: return "Marc 4 Digi sound system";
        case PciDevice1382::DEVICE_4248: return "Marc X sound system";
        case PciDevice1382::DEVICE_4424: return "TRACE D4 Sound System";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1382_PCIDEVICE1382_H
