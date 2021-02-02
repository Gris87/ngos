// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1191_PCIDEVICE1191_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1191_PCIDEVICE1191_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1191: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0007 = 0x0007,
    DEVICE_0008 = 0x0008,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000B = 0x000B,
    DEVICE_000D = 0x000D,
    DEVICE_000E = 0x000E,
    DEVICE_8002 = 0x8002,
    DEVICE_8010 = 0x8010,
    DEVICE_8020 = 0x8020,
    DEVICE_8030 = 0x8030,
    DEVICE_8040 = 0x8040,
    DEVICE_8050 = 0x8050,
    DEVICE_8060 = 0x8060,
    DEVICE_8080 = 0x8080,
    DEVICE_8081 = 0x8081,
    DEVICE_808A = 0x808A
};



inline const char8* enumToString(PciDevice1191 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1191::NONE:        return "NONE";
        case PciDevice1191::DEVICE_0003: return "DEVICE_0003";
        case PciDevice1191::DEVICE_0004: return "DEVICE_0004";
        case PciDevice1191::DEVICE_0005: return "DEVICE_0005";
        case PciDevice1191::DEVICE_0006: return "DEVICE_0006";
        case PciDevice1191::DEVICE_0007: return "DEVICE_0007";
        case PciDevice1191::DEVICE_0008: return "DEVICE_0008";
        case PciDevice1191::DEVICE_0009: return "DEVICE_0009";
        case PciDevice1191::DEVICE_000A: return "DEVICE_000A";
        case PciDevice1191::DEVICE_000B: return "DEVICE_000B";
        case PciDevice1191::DEVICE_000D: return "DEVICE_000D";
        case PciDevice1191::DEVICE_000E: return "DEVICE_000E";
        case PciDevice1191::DEVICE_8002: return "DEVICE_8002";
        case PciDevice1191::DEVICE_8010: return "DEVICE_8010";
        case PciDevice1191::DEVICE_8020: return "DEVICE_8020";
        case PciDevice1191::DEVICE_8030: return "DEVICE_8030";
        case PciDevice1191::DEVICE_8040: return "DEVICE_8040";
        case PciDevice1191::DEVICE_8050: return "DEVICE_8050";
        case PciDevice1191::DEVICE_8060: return "DEVICE_8060";
        case PciDevice1191::DEVICE_8080: return "DEVICE_8080";
        case PciDevice1191::DEVICE_8081: return "DEVICE_8081";
        case PciDevice1191::DEVICE_808A: return "DEVICE_808A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1191 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1191 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1191::DEVICE_0003: return "SCSI Cache Host Adapter";
        case PciDevice1191::DEVICE_0004: return "ATP8400";
        case PciDevice1191::DEVICE_0005: return "ATP850UF";
        case PciDevice1191::DEVICE_0006: return "ATP860 NO-BIOS";
        case PciDevice1191::DEVICE_0007: return "ATP860";
        case PciDevice1191::DEVICE_0008: return "ATP865 NO-ROM";
        case PciDevice1191::DEVICE_0009: return "ATP865";
        case PciDevice1191::DEVICE_000A: return "ATP867-A";
        case PciDevice1191::DEVICE_000B: return "ATP867-B";
        case PciDevice1191::DEVICE_000D: return "ATP8620";
        case PciDevice1191::DEVICE_000E: return "ATP8620";
        case PciDevice1191::DEVICE_8002: return "AEC6710 SCSI-2 Host Adapter";
        case PciDevice1191::DEVICE_8010: return "AEC6712UW SCSI";
        case PciDevice1191::DEVICE_8020: return "AEC6712U SCSI";
        case PciDevice1191::DEVICE_8030: return "AEC6712S SCSI";
        case PciDevice1191::DEVICE_8040: return "AEC6712D SCSI";
        case PciDevice1191::DEVICE_8050: return "AEC6712SUW SCSI";
        case PciDevice1191::DEVICE_8060: return "AEC6712 SCSI";
        case PciDevice1191::DEVICE_8080: return "AEC67160 SCSI";
        case PciDevice1191::DEVICE_8081: return "AEC67160S SCSI";
        case PciDevice1191::DEVICE_808A: return "AEC67162 2-ch. LVD SCSI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1191_PCIDEVICE1191_H
