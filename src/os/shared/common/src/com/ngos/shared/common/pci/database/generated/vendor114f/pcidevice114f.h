// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCIDEVICE114F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCIDEVICE114F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor114f/pcisubdevice114f001d.h>
#include <com/ngos/shared/common/pci/database/generated/vendor114f/pcisubdevice114f0024.h>
#include <com/ngos/shared/common/pci/database/generated/vendor114f/pcisubdevice114f0040.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice114F: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_0003 = 0x0003,
    DEVICE_0004 = 0x0004,
    DEVICE_0005 = 0x0005,
    DEVICE_0006 = 0x0006,
    DEVICE_0009 = 0x0009,
    DEVICE_000A = 0x000A,
    DEVICE_000C = 0x000C,
    DEVICE_000D = 0x000D,
    DEVICE_0011 = 0x0011,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_0016 = 0x0016,
    DEVICE_0017 = 0x0017,
    DEVICE_001A = 0x001A,
    DEVICE_001B = 0x001B,
    DEVICE_001C = 0x001C,
    DEVICE_001D = 0x001D,
    DEVICE_0023 = 0x0023,
    DEVICE_0024 = 0x0024,
    DEVICE_0026 = 0x0026,
    DEVICE_0027 = 0x0027,
    DEVICE_0028 = 0x0028,
    DEVICE_0029 = 0x0029,
    DEVICE_0034 = 0x0034,
    DEVICE_0035 = 0x0035,
    DEVICE_0040 = 0x0040,
    DEVICE_0042 = 0x0042,
    DEVICE_0043 = 0x0043,
    DEVICE_0044 = 0x0044,
    DEVICE_0045 = 0x0045,
    DEVICE_004E = 0x004E,
    DEVICE_0070 = 0x0070,
    DEVICE_0071 = 0x0071,
    DEVICE_0072 = 0x0072,
    DEVICE_0073 = 0x0073,
    DEVICE_00B0 = 0x00B0,
    DEVICE_00B1 = 0x00B1,
    DEVICE_00C8 = 0x00C8,
    DEVICE_00C9 = 0x00C9,
    DEVICE_00CA = 0x00CA,
    DEVICE_00CB = 0x00CB,
    DEVICE_00CC = 0x00CC,
    DEVICE_00CD = 0x00CD,
    DEVICE_00CE = 0x00CE,
    DEVICE_00D0 = 0x00D0,
    DEVICE_00D1 = 0x00D1,
    DEVICE_00F1 = 0x00F1,
    DEVICE_00F4 = 0x00F4,
    DEVICE_6001 = 0x6001
};



inline const char8* enumToString(PciDevice114F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice114F::NONE:        return "NONE";
        case PciDevice114F::DEVICE_0002: return "DEVICE_0002";
        case PciDevice114F::DEVICE_0003: return "DEVICE_0003";
        case PciDevice114F::DEVICE_0004: return "DEVICE_0004";
        case PciDevice114F::DEVICE_0005: return "DEVICE_0005";
        case PciDevice114F::DEVICE_0006: return "DEVICE_0006";
        case PciDevice114F::DEVICE_0009: return "DEVICE_0009";
        case PciDevice114F::DEVICE_000A: return "DEVICE_000A";
        case PciDevice114F::DEVICE_000C: return "DEVICE_000C";
        case PciDevice114F::DEVICE_000D: return "DEVICE_000D";
        case PciDevice114F::DEVICE_0011: return "DEVICE_0011";
        case PciDevice114F::DEVICE_0012: return "DEVICE_0012";
        case PciDevice114F::DEVICE_0013: return "DEVICE_0013";
        case PciDevice114F::DEVICE_0014: return "DEVICE_0014";
        case PciDevice114F::DEVICE_0015: return "DEVICE_0015";
        case PciDevice114F::DEVICE_0016: return "DEVICE_0016";
        case PciDevice114F::DEVICE_0017: return "DEVICE_0017";
        case PciDevice114F::DEVICE_001A: return "DEVICE_001A";
        case PciDevice114F::DEVICE_001B: return "DEVICE_001B";
        case PciDevice114F::DEVICE_001C: return "DEVICE_001C";
        case PciDevice114F::DEVICE_001D: return "DEVICE_001D";
        case PciDevice114F::DEVICE_0023: return "DEVICE_0023";
        case PciDevice114F::DEVICE_0024: return "DEVICE_0024";
        case PciDevice114F::DEVICE_0026: return "DEVICE_0026";
        case PciDevice114F::DEVICE_0027: return "DEVICE_0027";
        case PciDevice114F::DEVICE_0028: return "DEVICE_0028";
        case PciDevice114F::DEVICE_0029: return "DEVICE_0029";
        case PciDevice114F::DEVICE_0034: return "DEVICE_0034";
        case PciDevice114F::DEVICE_0035: return "DEVICE_0035";
        case PciDevice114F::DEVICE_0040: return "DEVICE_0040";
        case PciDevice114F::DEVICE_0042: return "DEVICE_0042";
        case PciDevice114F::DEVICE_0043: return "DEVICE_0043";
        case PciDevice114F::DEVICE_0044: return "DEVICE_0044";
        case PciDevice114F::DEVICE_0045: return "DEVICE_0045";
        case PciDevice114F::DEVICE_004E: return "DEVICE_004E";
        case PciDevice114F::DEVICE_0070: return "DEVICE_0070";
        case PciDevice114F::DEVICE_0071: return "DEVICE_0071";
        case PciDevice114F::DEVICE_0072: return "DEVICE_0072";
        case PciDevice114F::DEVICE_0073: return "DEVICE_0073";
        case PciDevice114F::DEVICE_00B0: return "DEVICE_00B0";
        case PciDevice114F::DEVICE_00B1: return "DEVICE_00B1";
        case PciDevice114F::DEVICE_00C8: return "DEVICE_00C8";
        case PciDevice114F::DEVICE_00C9: return "DEVICE_00C9";
        case PciDevice114F::DEVICE_00CA: return "DEVICE_00CA";
        case PciDevice114F::DEVICE_00CB: return "DEVICE_00CB";
        case PciDevice114F::DEVICE_00CC: return "DEVICE_00CC";
        case PciDevice114F::DEVICE_00CD: return "DEVICE_00CD";
        case PciDevice114F::DEVICE_00CE: return "DEVICE_00CE";
        case PciDevice114F::DEVICE_00D0: return "DEVICE_00D0";
        case PciDevice114F::DEVICE_00D1: return "DEVICE_00D1";
        case PciDevice114F::DEVICE_00F1: return "DEVICE_00F1";
        case PciDevice114F::DEVICE_00F4: return "DEVICE_00F4";
        case PciDevice114F::DEVICE_6001: return "DEVICE_6001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice114F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice114F device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice114F::DEVICE_0002: return "AccelePort EPC";
        case PciDevice114F::DEVICE_0003: return "RightSwitch SE-6";
        case PciDevice114F::DEVICE_0004: return "AccelePort Xem";
        case PciDevice114F::DEVICE_0005: return "AccelePort Xr";
        case PciDevice114F::DEVICE_0006: return "AccelePort Xr, C/X";
        case PciDevice114F::DEVICE_0009: return "AccelePort Xr/J";
        case PciDevice114F::DEVICE_000A: return "AccelePort EPC/J";
        case PciDevice114F::DEVICE_000C: return "DataFirePRIme T1 (1-port)";
        case PciDevice114F::DEVICE_000D: return "SyncPort 2-Port (x.25/FR)";
        case PciDevice114F::DEVICE_0011: return "AccelePort 8r EIA-232 (IBM)";
        case PciDevice114F::DEVICE_0012: return "AccelePort 8r EIA-422";
        case PciDevice114F::DEVICE_0013: return "AccelePort Xr";
        case PciDevice114F::DEVICE_0014: return "AccelePort 8r EIA-422";
        case PciDevice114F::DEVICE_0015: return "AccelePort Xem";
        case PciDevice114F::DEVICE_0016: return "AccelePort EPC/X";
        case PciDevice114F::DEVICE_0017: return "AccelePort C/X";
        case PciDevice114F::DEVICE_001A: return "DataFirePRIme E1 (1-port)";
        case PciDevice114F::DEVICE_001B: return "AccelePort C/X (IBM)";
        case PciDevice114F::DEVICE_001C: return "AccelePort Xr (SAIP)";
        case PciDevice114F::DEVICE_001D: return "DataFire RAS T1/E1/PRI";
        case PciDevice114F::DEVICE_0023: return "AccelePort RAS";
        case PciDevice114F::DEVICE_0024: return "DataFire RAS B4 ST/U";
        case PciDevice114F::DEVICE_0026: return "AccelePort 4r 920";
        case PciDevice114F::DEVICE_0027: return "AccelePort Xr 920";
        case PciDevice114F::DEVICE_0028: return "ClassicBoard 4";
        case PciDevice114F::DEVICE_0029: return "ClassicBoard 8";
        case PciDevice114F::DEVICE_0034: return "AccelePort 2r 920";
        case PciDevice114F::DEVICE_0035: return "DataFire DSP T1/E1/PRI cPCI";
        case PciDevice114F::DEVICE_0040: return "AccelePort Xp";
        case PciDevice114F::DEVICE_0042: return "AccelePort 2p";
        case PciDevice114F::DEVICE_0043: return "AccelePort 4p";
        case PciDevice114F::DEVICE_0044: return "AccelePort 8p";
        case PciDevice114F::DEVICE_0045: return "AccelePort 16p";
        case PciDevice114F::DEVICE_004E: return "AccelePort 32p";
        case PciDevice114F::DEVICE_0070: return "Datafire Micro V IOM2 (Europe)";
        case PciDevice114F::DEVICE_0071: return "Datafire Micro V (Europe)";
        case PciDevice114F::DEVICE_0072: return "Datafire Micro V IOM2 (North America)";
        case PciDevice114F::DEVICE_0073: return "Datafire Micro V (North America)";
        case PciDevice114F::DEVICE_00B0: return "Digi Neo 4";
        case PciDevice114F::DEVICE_00B1: return "Digi Neo 8";
        case PciDevice114F::DEVICE_00C8: return "Digi Neo 2 DB9";
        case PciDevice114F::DEVICE_00C9: return "Digi Neo 2 DB9 PRI";
        case PciDevice114F::DEVICE_00CA: return "Digi Neo 2 RJ45";
        case PciDevice114F::DEVICE_00CB: return "Digi Neo 2 RJ45 PRI";
        case PciDevice114F::DEVICE_00CC: return "Digi Neo 1 422";
        case PciDevice114F::DEVICE_00CD: return "Digi Neo 1 422 485";
        case PciDevice114F::DEVICE_00CE: return "Digi Neo 2 422 485";
        case PciDevice114F::DEVICE_00D0: return "ClassicBoard 4 422";
        case PciDevice114F::DEVICE_00D1: return "ClassicBoard 8 422";
        case PciDevice114F::DEVICE_00F1: return "Digi Neo PCI-E 4 port";
        case PciDevice114F::DEVICE_00F4: return "Digi Neo 4 (IBM version)";
        case PciDevice114F::DEVICE_6001: return "Avanstar";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice114F device, u16 subsystemVendorID, u16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice114F::DEVICE_0002: return "Unknown device";
        case PciDevice114F::DEVICE_0003: return "Unknown device";
        case PciDevice114F::DEVICE_0004: return "Unknown device";
        case PciDevice114F::DEVICE_0005: return "Unknown device";
        case PciDevice114F::DEVICE_0006: return "Unknown device";
        case PciDevice114F::DEVICE_0009: return "Unknown device";
        case PciDevice114F::DEVICE_000A: return "Unknown device";
        case PciDevice114F::DEVICE_000C: return "Unknown device";
        case PciDevice114F::DEVICE_000D: return "Unknown device";
        case PciDevice114F::DEVICE_0011: return "Unknown device";
        case PciDevice114F::DEVICE_0012: return "Unknown device";
        case PciDevice114F::DEVICE_0013: return "Unknown device";
        case PciDevice114F::DEVICE_0014: return "Unknown device";
        case PciDevice114F::DEVICE_0015: return "Unknown device";
        case PciDevice114F::DEVICE_0016: return "Unknown device";
        case PciDevice114F::DEVICE_0017: return "Unknown device";
        case PciDevice114F::DEVICE_001A: return "Unknown device";
        case PciDevice114F::DEVICE_001B: return "Unknown device";
        case PciDevice114F::DEVICE_001C: return "Unknown device";
        case PciDevice114F::DEVICE_001D: return enumToHumanString((PciSubDevice114F001D)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice114F::DEVICE_0023: return "Unknown device";
        case PciDevice114F::DEVICE_0024: return enumToHumanString((PciSubDevice114F0024)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice114F::DEVICE_0026: return "Unknown device";
        case PciDevice114F::DEVICE_0027: return "Unknown device";
        case PciDevice114F::DEVICE_0028: return "Unknown device";
        case PciDevice114F::DEVICE_0029: return "Unknown device";
        case PciDevice114F::DEVICE_0034: return "Unknown device";
        case PciDevice114F::DEVICE_0035: return "Unknown device";
        case PciDevice114F::DEVICE_0040: return enumToHumanString((PciSubDevice114F0040)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice114F::DEVICE_0042: return "Unknown device";
        case PciDevice114F::DEVICE_0043: return "Unknown device";
        case PciDevice114F::DEVICE_0044: return "Unknown device";
        case PciDevice114F::DEVICE_0045: return "Unknown device";
        case PciDevice114F::DEVICE_004E: return "Unknown device";
        case PciDevice114F::DEVICE_0070: return "Unknown device";
        case PciDevice114F::DEVICE_0071: return "Unknown device";
        case PciDevice114F::DEVICE_0072: return "Unknown device";
        case PciDevice114F::DEVICE_0073: return "Unknown device";
        case PciDevice114F::DEVICE_00B0: return "Unknown device";
        case PciDevice114F::DEVICE_00B1: return "Unknown device";
        case PciDevice114F::DEVICE_00C8: return "Unknown device";
        case PciDevice114F::DEVICE_00C9: return "Unknown device";
        case PciDevice114F::DEVICE_00CA: return "Unknown device";
        case PciDevice114F::DEVICE_00CB: return "Unknown device";
        case PciDevice114F::DEVICE_00CC: return "Unknown device";
        case PciDevice114F::DEVICE_00CD: return "Unknown device";
        case PciDevice114F::DEVICE_00CE: return "Unknown device";
        case PciDevice114F::DEVICE_00D0: return "Unknown device";
        case PciDevice114F::DEVICE_00D1: return "Unknown device";
        case PciDevice114F::DEVICE_00F1: return "Unknown device";
        case PciDevice114F::DEVICE_00F4: return "Unknown device";
        case PciDevice114F::DEVICE_6001: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCIDEVICE114F_H
