// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCIDEVICE1102_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCIDEVICE1102_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1102: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000B = 0x000B,
    DEVICE_0012 = 0x0012,
    DEVICE_4001 = 0x4001,
    DEVICE_7002 = 0x7002,
    DEVICE_7003 = 0x7003,
    DEVICE_7004 = 0x7004,
    DEVICE_7005 = 0x7005,
    DEVICE_7006 = 0x7006,
    DEVICE_8938 = 0x8938
};



inline const char8* enumToString(PciDevice1102 device1102) // TEST: NO
{
    // COMMON_LT((" | device1102 = %u", device1102)); // Commented to avoid bad looking logs



    switch (device1102)
    {
        case PciDevice1102::NONE:        return "NONE";
        case PciDevice1102::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1102::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1102::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1102::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1102::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1102::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1102::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1102::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1102::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1102::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1102::DEVICE_4001: return "DEVICE_4001";
        case PciDevice1102::DEVICE_7002: return "DEVICE_7002";
        case PciDevice1102::DEVICE_7003: return "DEVICE_7003";
        case PciDevice1102::DEVICE_7004: return "DEVICE_7004";
        case PciDevice1102::DEVICE_7005: return "DEVICE_7005";
        case PciDevice1102::DEVICE_7006: return "DEVICE_7006";
        case PciDevice1102::DEVICE_8938: return "DEVICE_8938";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1102 device1102) // TEST: NO
{
    // COMMON_LT((" | device1102 = %u", device1102)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1102, enumToString(device1102));

    return res;
}



inline const char8* enumToHumanString(PciDevice1102 device1102) // TEST: NO
{
    // COMMON_LT((" | device1102 = %u", device1102)); // Commented to avoid bad looking logs



    switch (device1102)
    {
        case PciDevice1102::DEVICE_0002: return "EMU10k1 [Sound Blaster Live! Series]";
        case PciDevice1102::DEVICE_0003: return "SB AWE64(D)";
        case PciDevice1102::DEVICE_0004: return "EMU10k2/CA0100/CA0102/CA10200 [Sound Blaster Audigy Series]";
        case PciDevice1102::DEVICE_0005: return "EMU20k1 [Sound Blaster X-Fi Series]";
        case PciDevice1102::DEVICE_0006: return "EMU10k1X / CA0103 [SB Live! OEM / SB 5.1 / Ectiva 5.1]";
        case PciDevice1102::DEVICE_0007: return "CA0106/CA0111 [SB Live!/Audigy/X-Fi Series]";
        case PciDevice1102::DEVICE_0008: return "CA0108/CA10300 [Sound Blaster Audigy Series]";
        case PciDevice1102::DEVICE_0009: return "CA0110 [Sound Blaster X-Fi Xtreme Audio]";
        case PciDevice1102::DEVICE_000B: return "EMU20k2 [Sound Blaster X-Fi Titanium Series]";
        case PciDevice1102::DEVICE_0012: return "Sound Core3D [Sound Blaster Recon3D / Z-Series]";
        case PciDevice1102::DEVICE_4001: return "SB Audigy FireWire Port";
        case PciDevice1102::DEVICE_7002: return "SB Live! Game Port";
        case PciDevice1102::DEVICE_7003: return "SB Audigy Game Port";
        case PciDevice1102::DEVICE_7004: return "[SB Live! Value] Input device controller";
        case PciDevice1102::DEVICE_7005: return "SB Audigy LS Game Port";
        case PciDevice1102::DEVICE_7006: return "[SB X-Fi Xtreme Audio] CA0110-IBG PCIe to PCI Bridge";
        case PciDevice1102::DEVICE_8938: return "Ectiva EV1938";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCIDEVICE1102_H
