// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6C_PCIDEVICE1D6C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6C_PCIDEVICE1D6C_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1D6C: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1003 = 0x1003,
    DEVICE_1004 = 0x1004,
    DEVICE_1005 = 0x1005,
    DEVICE_1006 = 0x1006,
    DEVICE_1007 = 0x1007,
    DEVICE_1008 = 0x1008,
    DEVICE_1009 = 0x1009,
    DEVICE_100A = 0x100A,
    DEVICE_100B = 0x100B,
    DEVICE_100C = 0x100C,
    DEVICE_100D = 0x100D,
    DEVICE_100E = 0x100E,
    DEVICE_100F = 0x100F,
    DEVICE_1010 = 0x1010,
    DEVICE_1011 = 0x1011,
    DEVICE_1012 = 0x1012,
    DEVICE_1013 = 0x1013,
    DEVICE_1014 = 0x1014,
    DEVICE_1015 = 0x1015,
    DEVICE_1016 = 0x1016,
    DEVICE_4200 = 0x4200
};



inline const char8* enumToString(PciDevice1D6C device1D6C) // TEST: NO
{
    // COMMON_LT((" | device1D6C = %u", device1D6C)); // Commented to avoid bad looking logs



    switch (device1D6C)
    {
        case PciDevice1D6C::NONE:        return "NONE";
        case PciDevice1D6C::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1D6C::DEVICE_1002: return "DEVICE_1002";
        case PciDevice1D6C::DEVICE_1003: return "DEVICE_1003";
        case PciDevice1D6C::DEVICE_1004: return "DEVICE_1004";
        case PciDevice1D6C::DEVICE_1005: return "DEVICE_1005";
        case PciDevice1D6C::DEVICE_1006: return "DEVICE_1006";
        case PciDevice1D6C::DEVICE_1007: return "DEVICE_1007";
        case PciDevice1D6C::DEVICE_1008: return "DEVICE_1008";
        case PciDevice1D6C::DEVICE_1009: return "DEVICE_1009";
        case PciDevice1D6C::DEVICE_100A: return "DEVICE_100A";
        case PciDevice1D6C::DEVICE_100B: return "DEVICE_100B";
        case PciDevice1D6C::DEVICE_100C: return "DEVICE_100C";
        case PciDevice1D6C::DEVICE_100D: return "DEVICE_100D";
        case PciDevice1D6C::DEVICE_100E: return "DEVICE_100E";
        case PciDevice1D6C::DEVICE_100F: return "DEVICE_100F";
        case PciDevice1D6C::DEVICE_1010: return "DEVICE_1010";
        case PciDevice1D6C::DEVICE_1011: return "DEVICE_1011";
        case PciDevice1D6C::DEVICE_1012: return "DEVICE_1012";
        case PciDevice1D6C::DEVICE_1013: return "DEVICE_1013";
        case PciDevice1D6C::DEVICE_1014: return "DEVICE_1014";
        case PciDevice1D6C::DEVICE_1015: return "DEVICE_1015";
        case PciDevice1D6C::DEVICE_1016: return "DEVICE_1016";
        case PciDevice1D6C::DEVICE_4200: return "DEVICE_4200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1D6C device1D6C) // TEST: NO
{
    // COMMON_LT((" | device1D6C = %u", device1D6C)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1D6C, enumToString(device1D6C));

    return res;
}



inline const char8* enumToHumanString(PciDevice1D6C device1D6C) // TEST: NO
{
    // COMMON_LT((" | device1D6C = %u", device1D6C)); // Commented to avoid bad looking logs



    switch (device1D6C)
    {
        case PciDevice1D6C::DEVICE_1001: return "A5PL-E1";
        case PciDevice1D6C::DEVICE_1002: return "A5PL-E7";
        case PciDevice1D6C::DEVICE_1003: return "S5PEDS-AB";
        case PciDevice1D6C::DEVICE_1004: return "KC705-K325";
        case PciDevice1D6C::DEVICE_1005: return "ZC706-Z045";
        case PciDevice1D6C::DEVICE_1006: return "KCU105-KU040";
        case PciDevice1D6C::DEVICE_1007: return "XUSP3S-VU095 [Jasper]";
        case PciDevice1D6C::DEVICE_1008: return "XUSPL4-VU065 [Mustang UltraScale]";
        case PciDevice1D6C::DEVICE_1009: return "XUSPL4-VU3P [Mustang UltraScale+]";
        case PciDevice1D6C::DEVICE_100A: return "A10PL4-A10GX115";
        case PciDevice1D6C::DEVICE_100B: return "K35-2SFP";
        case PciDevice1D6C::DEVICE_100C: return "K35-4SFP";
        case PciDevice1D6C::DEVICE_100D: return "AR-ARKA-FX0 [Arkville 32B DPDK Data Mover]";
        case PciDevice1D6C::DEVICE_100E: return "AR-ARKA-FX1 [Arkville 64B DPDK Data Mover]";
        case PciDevice1D6C::DEVICE_100F: return "AR-ARKA-FX1 [Arkville 64B DPDK Data Mover for Versal]";
        case PciDevice1D6C::DEVICE_1010: return "AR-ARKA-FX1 [Arkville 64B DPDK Data Mover for Agilex]";
        case PciDevice1D6C::DEVICE_1011: return "AR-MAN-U50 [Manitou Class Accelerator for U50]";
        case PciDevice1D6C::DEVICE_1012: return "AR-MAN-U200 [Manitou Class Accelerator for U200]";
        case PciDevice1D6C::DEVICE_1013: return "AR-MAN-U250 [Manitou Class Accelerator for U250]";
        case PciDevice1D6C::DEVICE_1014: return "AR-MAN-U280 [Manitou Class Accelerator for U280]";
        case PciDevice1D6C::DEVICE_1015: return "AR-ARK-BBDEV-FX0 [Arkville 32B DPDK Baseband Device]";
        case PciDevice1D6C::DEVICE_1016: return "AR-ARK-BBDEV-FX1 [Arkville 64B DPDK Baseband Device]";
        case PciDevice1D6C::DEVICE_4200: return "A5PL-E1-10GETI [10 GbE Ethernet Traffic Instrument]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D6C_PCIDEVICE1D6C_H
