// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCIDEVICE1957_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCIDEVICE1957_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1957/pcisubdevice19570084.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1957/pcisubdevice19570085.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1957/pcisubdevice195700b6.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1957/pcisubdevice19570111.h>
#include <com/ngos/shared/common/pci/database/generated/vendor1957/pcisubdevice1957c006.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1957: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0012 = 0x0012,
    DEVICE_0013 = 0x0013,
    DEVICE_0014 = 0x0014,
    DEVICE_0015 = 0x0015,
    DEVICE_0018 = 0x0018,
    DEVICE_0019 = 0x0019,
    DEVICE_001A = 0x001A,
    DEVICE_0020 = 0x0020,
    DEVICE_0021 = 0x0021,
    DEVICE_0022 = 0x0022,
    DEVICE_0023 = 0x0023,
    DEVICE_0030 = 0x0030,
    DEVICE_0031 = 0x0031,
    DEVICE_0032 = 0x0032,
    DEVICE_0033 = 0x0033,
    DEVICE_0040 = 0x0040,
    DEVICE_0041 = 0x0041,
    DEVICE_0050 = 0x0050,
    DEVICE_0051 = 0x0051,
    DEVICE_0052 = 0x0052,
    DEVICE_0053 = 0x0053,
    DEVICE_0060 = 0x0060,
    DEVICE_0061 = 0x0061,
    DEVICE_0070 = 0x0070,
    DEVICE_0071 = 0x0071,
    DEVICE_0078 = 0x0078,
    DEVICE_0079 = 0x0079,
    DEVICE_0080 = 0x0080,
    DEVICE_0081 = 0x0081,
    DEVICE_0082 = 0x0082,
    DEVICE_0083 = 0x0083,
    DEVICE_0084 = 0x0084,
    DEVICE_0085 = 0x0085,
    DEVICE_0086 = 0x0086,
    DEVICE_0087 = 0x0087,
    DEVICE_00B4 = 0x00B4,
    DEVICE_00B6 = 0x00B6,
    DEVICE_00C2 = 0x00C2,
    DEVICE_00C3 = 0x00C3,
    DEVICE_00C4 = 0x00C4,
    DEVICE_00C5 = 0x00C5,
    DEVICE_00C6 = 0x00C6,
    DEVICE_00C7 = 0x00C7,
    DEVICE_0100 = 0x0100,
    DEVICE_0101 = 0x0101,
    DEVICE_0102 = 0x0102,
    DEVICE_0103 = 0x0103,
    DEVICE_0108 = 0x0108,
    DEVICE_0109 = 0x0109,
    DEVICE_010A = 0x010A,
    DEVICE_010B = 0x010B,
    DEVICE_0110 = 0x0110,
    DEVICE_0111 = 0x0111,
    DEVICE_0118 = 0x0118,
    DEVICE_0119 = 0x0119,
    DEVICE_0128 = 0x0128,
    DEVICE_0400 = 0x0400,
    DEVICE_0401 = 0x0401,
    DEVICE_0408 = 0x0408,
    DEVICE_0409 = 0x0409,
    DEVICE_041F = 0x041F,
    DEVICE_0440 = 0x0440,
    DEVICE_0441 = 0x0441,
    DEVICE_0446 = 0x0446,
    DEVICE_0447 = 0x0447,
    DEVICE_0830 = 0x0830,
    DEVICE_0831 = 0x0831,
    DEVICE_0838 = 0x0838,
    DEVICE_0839 = 0x0839,
    DEVICE_580C = 0x580C,
    DEVICE_7010 = 0x7010,
    DEVICE_7011 = 0x7011,
    DEVICE_7018 = 0x7018,
    DEVICE_C006 = 0xC006,
    DEVICE_FC02 = 0xFC02,
    DEVICE_FC03 = 0xFC03
};



inline const char8* enumToString(PciDevice1957 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1957::NONE:        return "NONE";
        case PciDevice1957::DEVICE_0012: return "DEVICE_0012";
        case PciDevice1957::DEVICE_0013: return "DEVICE_0013";
        case PciDevice1957::DEVICE_0014: return "DEVICE_0014";
        case PciDevice1957::DEVICE_0015: return "DEVICE_0015";
        case PciDevice1957::DEVICE_0018: return "DEVICE_0018";
        case PciDevice1957::DEVICE_0019: return "DEVICE_0019";
        case PciDevice1957::DEVICE_001A: return "DEVICE_001A";
        case PciDevice1957::DEVICE_0020: return "DEVICE_0020";
        case PciDevice1957::DEVICE_0021: return "DEVICE_0021";
        case PciDevice1957::DEVICE_0022: return "DEVICE_0022";
        case PciDevice1957::DEVICE_0023: return "DEVICE_0023";
        case PciDevice1957::DEVICE_0030: return "DEVICE_0030";
        case PciDevice1957::DEVICE_0031: return "DEVICE_0031";
        case PciDevice1957::DEVICE_0032: return "DEVICE_0032";
        case PciDevice1957::DEVICE_0033: return "DEVICE_0033";
        case PciDevice1957::DEVICE_0040: return "DEVICE_0040";
        case PciDevice1957::DEVICE_0041: return "DEVICE_0041";
        case PciDevice1957::DEVICE_0050: return "DEVICE_0050";
        case PciDevice1957::DEVICE_0051: return "DEVICE_0051";
        case PciDevice1957::DEVICE_0052: return "DEVICE_0052";
        case PciDevice1957::DEVICE_0053: return "DEVICE_0053";
        case PciDevice1957::DEVICE_0060: return "DEVICE_0060";
        case PciDevice1957::DEVICE_0061: return "DEVICE_0061";
        case PciDevice1957::DEVICE_0070: return "DEVICE_0070";
        case PciDevice1957::DEVICE_0071: return "DEVICE_0071";
        case PciDevice1957::DEVICE_0078: return "DEVICE_0078";
        case PciDevice1957::DEVICE_0079: return "DEVICE_0079";
        case PciDevice1957::DEVICE_0080: return "DEVICE_0080";
        case PciDevice1957::DEVICE_0081: return "DEVICE_0081";
        case PciDevice1957::DEVICE_0082: return "DEVICE_0082";
        case PciDevice1957::DEVICE_0083: return "DEVICE_0083";
        case PciDevice1957::DEVICE_0084: return "DEVICE_0084";
        case PciDevice1957::DEVICE_0085: return "DEVICE_0085";
        case PciDevice1957::DEVICE_0086: return "DEVICE_0086";
        case PciDevice1957::DEVICE_0087: return "DEVICE_0087";
        case PciDevice1957::DEVICE_00B4: return "DEVICE_00B4";
        case PciDevice1957::DEVICE_00B6: return "DEVICE_00B6";
        case PciDevice1957::DEVICE_00C2: return "DEVICE_00C2";
        case PciDevice1957::DEVICE_00C3: return "DEVICE_00C3";
        case PciDevice1957::DEVICE_00C4: return "DEVICE_00C4";
        case PciDevice1957::DEVICE_00C5: return "DEVICE_00C5";
        case PciDevice1957::DEVICE_00C6: return "DEVICE_00C6";
        case PciDevice1957::DEVICE_00C7: return "DEVICE_00C7";
        case PciDevice1957::DEVICE_0100: return "DEVICE_0100";
        case PciDevice1957::DEVICE_0101: return "DEVICE_0101";
        case PciDevice1957::DEVICE_0102: return "DEVICE_0102";
        case PciDevice1957::DEVICE_0103: return "DEVICE_0103";
        case PciDevice1957::DEVICE_0108: return "DEVICE_0108";
        case PciDevice1957::DEVICE_0109: return "DEVICE_0109";
        case PciDevice1957::DEVICE_010A: return "DEVICE_010A";
        case PciDevice1957::DEVICE_010B: return "DEVICE_010B";
        case PciDevice1957::DEVICE_0110: return "DEVICE_0110";
        case PciDevice1957::DEVICE_0111: return "DEVICE_0111";
        case PciDevice1957::DEVICE_0118: return "DEVICE_0118";
        case PciDevice1957::DEVICE_0119: return "DEVICE_0119";
        case PciDevice1957::DEVICE_0128: return "DEVICE_0128";
        case PciDevice1957::DEVICE_0400: return "DEVICE_0400";
        case PciDevice1957::DEVICE_0401: return "DEVICE_0401";
        case PciDevice1957::DEVICE_0408: return "DEVICE_0408";
        case PciDevice1957::DEVICE_0409: return "DEVICE_0409";
        case PciDevice1957::DEVICE_041F: return "DEVICE_041F";
        case PciDevice1957::DEVICE_0440: return "DEVICE_0440";
        case PciDevice1957::DEVICE_0441: return "DEVICE_0441";
        case PciDevice1957::DEVICE_0446: return "DEVICE_0446";
        case PciDevice1957::DEVICE_0447: return "DEVICE_0447";
        case PciDevice1957::DEVICE_0830: return "DEVICE_0830";
        case PciDevice1957::DEVICE_0831: return "DEVICE_0831";
        case PciDevice1957::DEVICE_0838: return "DEVICE_0838";
        case PciDevice1957::DEVICE_0839: return "DEVICE_0839";
        case PciDevice1957::DEVICE_580C: return "DEVICE_580C";
        case PciDevice1957::DEVICE_7010: return "DEVICE_7010";
        case PciDevice1957::DEVICE_7011: return "DEVICE_7011";
        case PciDevice1957::DEVICE_7018: return "DEVICE_7018";
        case PciDevice1957::DEVICE_C006: return "DEVICE_C006";
        case PciDevice1957::DEVICE_FC02: return "DEVICE_FC02";
        case PciDevice1957::DEVICE_FC03: return "DEVICE_FC03";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1957 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1957 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1957::DEVICE_0012: return "MPC8548E";
        case PciDevice1957::DEVICE_0013: return "MPC8548";
        case PciDevice1957::DEVICE_0014: return "MPC8543E";
        case PciDevice1957::DEVICE_0015: return "MPC8543";
        case PciDevice1957::DEVICE_0018: return "MPC8547E";
        case PciDevice1957::DEVICE_0019: return "MPC8545E";
        case PciDevice1957::DEVICE_001A: return "MPC8545";
        case PciDevice1957::DEVICE_0020: return "MPC8568E";
        case PciDevice1957::DEVICE_0021: return "MPC8568";
        case PciDevice1957::DEVICE_0022: return "MPC8567E";
        case PciDevice1957::DEVICE_0023: return "MPC8567";
        case PciDevice1957::DEVICE_0030: return "MPC8533E";
        case PciDevice1957::DEVICE_0031: return "MPC8533";
        case PciDevice1957::DEVICE_0032: return "MPC8544E";
        case PciDevice1957::DEVICE_0033: return "MPC8544";
        case PciDevice1957::DEVICE_0040: return "MPC8572E";
        case PciDevice1957::DEVICE_0041: return "MPC8572";
        case PciDevice1957::DEVICE_0050: return "MPC8536E";
        case PciDevice1957::DEVICE_0051: return "MPC8536";
        case PciDevice1957::DEVICE_0052: return "MPC8535E";
        case PciDevice1957::DEVICE_0053: return "MPC8535";
        case PciDevice1957::DEVICE_0060: return "MPC8569";
        case PciDevice1957::DEVICE_0061: return "MPC8569E";
        case PciDevice1957::DEVICE_0070: return "P2020E";
        case PciDevice1957::DEVICE_0071: return "P2020";
        case PciDevice1957::DEVICE_0078: return "P2010E";
        case PciDevice1957::DEVICE_0079: return "P2010";
        case PciDevice1957::DEVICE_0080: return "MPC8349E";
        case PciDevice1957::DEVICE_0081: return "MPC8349";
        case PciDevice1957::DEVICE_0082: return "MPC8347E TBGA";
        case PciDevice1957::DEVICE_0083: return "MPC8347 TBGA";
        case PciDevice1957::DEVICE_0084: return "MPC8347E PBGA";
        case PciDevice1957::DEVICE_0085: return "MPC8347 PBGA";
        case PciDevice1957::DEVICE_0086: return "MPC8343E";
        case PciDevice1957::DEVICE_0087: return "MPC8343";
        case PciDevice1957::DEVICE_00B4: return "MPC8315E";
        case PciDevice1957::DEVICE_00B6: return "MPC8314E";
        case PciDevice1957::DEVICE_00C2: return "MPC8379E";
        case PciDevice1957::DEVICE_00C3: return "MPC8379";
        case PciDevice1957::DEVICE_00C4: return "MPC8378E";
        case PciDevice1957::DEVICE_00C5: return "MPC8378";
        case PciDevice1957::DEVICE_00C6: return "MPC8377E";
        case PciDevice1957::DEVICE_00C7: return "MPC8377";
        case PciDevice1957::DEVICE_0100: return "P1020E";
        case PciDevice1957::DEVICE_0101: return "P1020";
        case PciDevice1957::DEVICE_0102: return "P1021E";
        case PciDevice1957::DEVICE_0103: return "P1021";
        case PciDevice1957::DEVICE_0108: return "P1011E";
        case PciDevice1957::DEVICE_0109: return "P1011";
        case PciDevice1957::DEVICE_010A: return "P1012E";
        case PciDevice1957::DEVICE_010B: return "P1012";
        case PciDevice1957::DEVICE_0110: return "P1022E";
        case PciDevice1957::DEVICE_0111: return "P1022";
        case PciDevice1957::DEVICE_0118: return "P1013E";
        case PciDevice1957::DEVICE_0119: return "P1013";
        case PciDevice1957::DEVICE_0128: return "P1010";
        case PciDevice1957::DEVICE_0400: return "P4080E";
        case PciDevice1957::DEVICE_0401: return "P4080";
        case PciDevice1957::DEVICE_0408: return "P4040E";
        case PciDevice1957::DEVICE_0409: return "P4040";
        case PciDevice1957::DEVICE_041F: return "P3041";
        case PciDevice1957::DEVICE_0440: return "T4240 with security";
        case PciDevice1957::DEVICE_0441: return "T4240 without security";
        case PciDevice1957::DEVICE_0446: return "T4160 with security";
        case PciDevice1957::DEVICE_0447: return "T4160 without security";
        case PciDevice1957::DEVICE_0830: return "T2080 with security";
        case PciDevice1957::DEVICE_0831: return "T2080 without security";
        case PciDevice1957::DEVICE_0838: return "T2081 with security";
        case PciDevice1957::DEVICE_0839: return "T2081 without security";
        case PciDevice1957::DEVICE_580C: return "MPC5121e";
        case PciDevice1957::DEVICE_7010: return "MPC8641 PCI Host Bridge";
        case PciDevice1957::DEVICE_7011: return "MPC8641D PCI Host Bridge";
        case PciDevice1957::DEVICE_7018: return "MPC8610";
        case PciDevice1957::DEVICE_C006: return "MPC8308";
        case PciDevice1957::DEVICE_FC02: return "RedStone";
        case PciDevice1957::DEVICE_FC03: return "CFI";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice1957 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1957::DEVICE_0012: return "Unknown device";
        case PciDevice1957::DEVICE_0013: return "Unknown device";
        case PciDevice1957::DEVICE_0014: return "Unknown device";
        case PciDevice1957::DEVICE_0015: return "Unknown device";
        case PciDevice1957::DEVICE_0018: return "Unknown device";
        case PciDevice1957::DEVICE_0019: return "Unknown device";
        case PciDevice1957::DEVICE_001A: return "Unknown device";
        case PciDevice1957::DEVICE_0020: return "Unknown device";
        case PciDevice1957::DEVICE_0021: return "Unknown device";
        case PciDevice1957::DEVICE_0022: return "Unknown device";
        case PciDevice1957::DEVICE_0023: return "Unknown device";
        case PciDevice1957::DEVICE_0030: return "Unknown device";
        case PciDevice1957::DEVICE_0031: return "Unknown device";
        case PciDevice1957::DEVICE_0032: return "Unknown device";
        case PciDevice1957::DEVICE_0033: return "Unknown device";
        case PciDevice1957::DEVICE_0040: return "Unknown device";
        case PciDevice1957::DEVICE_0041: return "Unknown device";
        case PciDevice1957::DEVICE_0050: return "Unknown device";
        case PciDevice1957::DEVICE_0051: return "Unknown device";
        case PciDevice1957::DEVICE_0052: return "Unknown device";
        case PciDevice1957::DEVICE_0053: return "Unknown device";
        case PciDevice1957::DEVICE_0060: return "Unknown device";
        case PciDevice1957::DEVICE_0061: return "Unknown device";
        case PciDevice1957::DEVICE_0070: return "Unknown device";
        case PciDevice1957::DEVICE_0071: return "Unknown device";
        case PciDevice1957::DEVICE_0078: return "Unknown device";
        case PciDevice1957::DEVICE_0079: return "Unknown device";
        case PciDevice1957::DEVICE_0080: return "Unknown device";
        case PciDevice1957::DEVICE_0081: return "Unknown device";
        case PciDevice1957::DEVICE_0082: return "Unknown device";
        case PciDevice1957::DEVICE_0083: return "Unknown device";
        case PciDevice1957::DEVICE_0084: return enumToHumanString((PciSubDevice19570084)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1957::DEVICE_0085: return enumToHumanString((PciSubDevice19570085)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1957::DEVICE_0086: return "Unknown device";
        case PciDevice1957::DEVICE_0087: return "Unknown device";
        case PciDevice1957::DEVICE_00B4: return "Unknown device";
        case PciDevice1957::DEVICE_00B6: return enumToHumanString((PciSubDevice195700B6)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1957::DEVICE_00C2: return "Unknown device";
        case PciDevice1957::DEVICE_00C3: return "Unknown device";
        case PciDevice1957::DEVICE_00C4: return "Unknown device";
        case PciDevice1957::DEVICE_00C5: return "Unknown device";
        case PciDevice1957::DEVICE_00C6: return "Unknown device";
        case PciDevice1957::DEVICE_00C7: return "Unknown device";
        case PciDevice1957::DEVICE_0100: return "Unknown device";
        case PciDevice1957::DEVICE_0101: return "Unknown device";
        case PciDevice1957::DEVICE_0102: return "Unknown device";
        case PciDevice1957::DEVICE_0103: return "Unknown device";
        case PciDevice1957::DEVICE_0108: return "Unknown device";
        case PciDevice1957::DEVICE_0109: return "Unknown device";
        case PciDevice1957::DEVICE_010A: return "Unknown device";
        case PciDevice1957::DEVICE_010B: return "Unknown device";
        case PciDevice1957::DEVICE_0110: return "Unknown device";
        case PciDevice1957::DEVICE_0111: return enumToHumanString((PciSubDevice19570111)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1957::DEVICE_0118: return "Unknown device";
        case PciDevice1957::DEVICE_0119: return "Unknown device";
        case PciDevice1957::DEVICE_0128: return "Unknown device";
        case PciDevice1957::DEVICE_0400: return "Unknown device";
        case PciDevice1957::DEVICE_0401: return "Unknown device";
        case PciDevice1957::DEVICE_0408: return "Unknown device";
        case PciDevice1957::DEVICE_0409: return "Unknown device";
        case PciDevice1957::DEVICE_041F: return "Unknown device";
        case PciDevice1957::DEVICE_0440: return "Unknown device";
        case PciDevice1957::DEVICE_0441: return "Unknown device";
        case PciDevice1957::DEVICE_0446: return "Unknown device";
        case PciDevice1957::DEVICE_0447: return "Unknown device";
        case PciDevice1957::DEVICE_0830: return "Unknown device";
        case PciDevice1957::DEVICE_0831: return "Unknown device";
        case PciDevice1957::DEVICE_0838: return "Unknown device";
        case PciDevice1957::DEVICE_0839: return "Unknown device";
        case PciDevice1957::DEVICE_580C: return "Unknown device";
        case PciDevice1957::DEVICE_7010: return "Unknown device";
        case PciDevice1957::DEVICE_7011: return "Unknown device";
        case PciDevice1957::DEVICE_7018: return "Unknown device";
        case PciDevice1957::DEVICE_C006: return enumToHumanString((PciSubDevice1957C006)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice1957::DEVICE_FC02: return "Unknown device";
        case PciDevice1957::DEVICE_FC03: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCIDEVICE1957_H
