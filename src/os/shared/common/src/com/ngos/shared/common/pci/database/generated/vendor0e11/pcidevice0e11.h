// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCIDEVICE0E11_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCIDEVICE0E11_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0e11/pcisubdevice0e110046.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0e11/pcisubdevice0e11a0f0.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0e11/pcisubdevice0e11a0f7.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0e11/pcisubdevice0e11ae10.h>
#include <com/ngos/shared/common/pci/database/generated/vendor0e11/pcisubdevice0e11b178.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice0E11: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0002 = 0x0002,
    DEVICE_0046 = 0x0046,
    DEVICE_0049 = 0x0049,
    DEVICE_004A = 0x004A,
    DEVICE_005A = 0x005A,
    DEVICE_007C = 0x007C,
    DEVICE_007D = 0x007D,
    DEVICE_0085 = 0x0085,
    DEVICE_00B1 = 0x00B1,
    DEVICE_00BB = 0x00BB,
    DEVICE_00CA = 0x00CA,
    DEVICE_00CB = 0x00CB,
    DEVICE_00CF = 0x00CF,
    DEVICE_00D0 = 0x00D0,
    DEVICE_00D1 = 0x00D1,
    DEVICE_00E3 = 0x00E3,
    DEVICE_0508 = 0x0508,
    DEVICE_1000 = 0x1000,
    DEVICE_2000 = 0x2000,
    DEVICE_3032 = 0x3032,
    DEVICE_3033 = 0x3033,
    DEVICE_3034 = 0x3034,
    DEVICE_4000 = 0x4000,
    DEVICE_4040 = 0x4040,
    DEVICE_4048 = 0x4048,
    DEVICE_4050 = 0x4050,
    DEVICE_4051 = 0x4051,
    DEVICE_4058 = 0x4058,
    DEVICE_4070 = 0x4070,
    DEVICE_4080 = 0x4080,
    DEVICE_4082 = 0x4082,
    DEVICE_4083 = 0x4083,
    DEVICE_4091 = 0x4091,
    DEVICE_409A = 0x409A,
    DEVICE_409B = 0x409B,
    DEVICE_409C = 0x409C,
    DEVICE_409D = 0x409D,
    DEVICE_6010 = 0x6010,
    DEVICE_7020 = 0x7020,
    DEVICE_A0EC = 0xA0EC,
    DEVICE_A0F0 = 0xA0F0,
    DEVICE_A0F3 = 0xA0F3,
    DEVICE_A0F7 = 0xA0F7,
    DEVICE_A0F8 = 0xA0F8,
    DEVICE_A0FC = 0xA0FC,
    DEVICE_AE10 = 0xAE10,
    DEVICE_AE29 = 0xAE29,
    DEVICE_AE2A = 0xAE2A,
    DEVICE_AE2B = 0xAE2B,
    DEVICE_AE31 = 0xAE31,
    DEVICE_AE32 = 0xAE32,
    DEVICE_AE33 = 0xAE33,
    DEVICE_AE34 = 0xAE34,
    DEVICE_AE35 = 0xAE35,
    DEVICE_AE40 = 0xAE40,
    DEVICE_AE43 = 0xAE43,
    DEVICE_AE69 = 0xAE69,
    DEVICE_AE6C = 0xAE6C,
    DEVICE_AE6D = 0xAE6D,
    DEVICE_B011 = 0xB011,
    DEVICE_B012 = 0xB012,
    DEVICE_B01E = 0xB01E,
    DEVICE_B01F = 0xB01F,
    DEVICE_B02F = 0xB02F,
    DEVICE_B030 = 0xB030,
    DEVICE_B04A = 0xB04A,
    DEVICE_B060 = 0xB060,
    DEVICE_B0C6 = 0xB0C6,
    DEVICE_B0C7 = 0xB0C7,
    DEVICE_B0D7 = 0xB0D7,
    DEVICE_B0DD = 0xB0DD,
    DEVICE_B0DE = 0xB0DE,
    DEVICE_B0DF = 0xB0DF,
    DEVICE_B0E0 = 0xB0E0,
    DEVICE_B0E1 = 0xB0E1,
    DEVICE_B123 = 0xB123,
    DEVICE_B134 = 0xB134,
    DEVICE_B13C = 0xB13C,
    DEVICE_B144 = 0xB144,
    DEVICE_B163 = 0xB163,
    DEVICE_B164 = 0xB164,
    DEVICE_B178 = 0xB178,
    DEVICE_B1A4 = 0xB1A4,
    DEVICE_B200 = 0xB200,
    DEVICE_B203 = 0xB203,
    DEVICE_B204 = 0xB204,
    DEVICE_C000 = 0xC000,
    DEVICE_F130 = 0xF130,
    DEVICE_F150 = 0xF150
};



inline const char8* enumToString(PciDevice0E11 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0E11::NONE:        return "NONE";
        case PciDevice0E11::DEVICE_0001: return "DEVICE_0001";
        case PciDevice0E11::DEVICE_0002: return "DEVICE_0002";
        case PciDevice0E11::DEVICE_0046: return "DEVICE_0046";
        case PciDevice0E11::DEVICE_0049: return "DEVICE_0049";
        case PciDevice0E11::DEVICE_004A: return "DEVICE_004A";
        case PciDevice0E11::DEVICE_005A: return "DEVICE_005A";
        case PciDevice0E11::DEVICE_007C: return "DEVICE_007C";
        case PciDevice0E11::DEVICE_007D: return "DEVICE_007D";
        case PciDevice0E11::DEVICE_0085: return "DEVICE_0085";
        case PciDevice0E11::DEVICE_00B1: return "DEVICE_00B1";
        case PciDevice0E11::DEVICE_00BB: return "DEVICE_00BB";
        case PciDevice0E11::DEVICE_00CA: return "DEVICE_00CA";
        case PciDevice0E11::DEVICE_00CB: return "DEVICE_00CB";
        case PciDevice0E11::DEVICE_00CF: return "DEVICE_00CF";
        case PciDevice0E11::DEVICE_00D0: return "DEVICE_00D0";
        case PciDevice0E11::DEVICE_00D1: return "DEVICE_00D1";
        case PciDevice0E11::DEVICE_00E3: return "DEVICE_00E3";
        case PciDevice0E11::DEVICE_0508: return "DEVICE_0508";
        case PciDevice0E11::DEVICE_1000: return "DEVICE_1000";
        case PciDevice0E11::DEVICE_2000: return "DEVICE_2000";
        case PciDevice0E11::DEVICE_3032: return "DEVICE_3032";
        case PciDevice0E11::DEVICE_3033: return "DEVICE_3033";
        case PciDevice0E11::DEVICE_3034: return "DEVICE_3034";
        case PciDevice0E11::DEVICE_4000: return "DEVICE_4000";
        case PciDevice0E11::DEVICE_4040: return "DEVICE_4040";
        case PciDevice0E11::DEVICE_4048: return "DEVICE_4048";
        case PciDevice0E11::DEVICE_4050: return "DEVICE_4050";
        case PciDevice0E11::DEVICE_4051: return "DEVICE_4051";
        case PciDevice0E11::DEVICE_4058: return "DEVICE_4058";
        case PciDevice0E11::DEVICE_4070: return "DEVICE_4070";
        case PciDevice0E11::DEVICE_4080: return "DEVICE_4080";
        case PciDevice0E11::DEVICE_4082: return "DEVICE_4082";
        case PciDevice0E11::DEVICE_4083: return "DEVICE_4083";
        case PciDevice0E11::DEVICE_4091: return "DEVICE_4091";
        case PciDevice0E11::DEVICE_409A: return "DEVICE_409A";
        case PciDevice0E11::DEVICE_409B: return "DEVICE_409B";
        case PciDevice0E11::DEVICE_409C: return "DEVICE_409C";
        case PciDevice0E11::DEVICE_409D: return "DEVICE_409D";
        case PciDevice0E11::DEVICE_6010: return "DEVICE_6010";
        case PciDevice0E11::DEVICE_7020: return "DEVICE_7020";
        case PciDevice0E11::DEVICE_A0EC: return "DEVICE_A0EC";
        case PciDevice0E11::DEVICE_A0F0: return "DEVICE_A0F0";
        case PciDevice0E11::DEVICE_A0F3: return "DEVICE_A0F3";
        case PciDevice0E11::DEVICE_A0F7: return "DEVICE_A0F7";
        case PciDevice0E11::DEVICE_A0F8: return "DEVICE_A0F8";
        case PciDevice0E11::DEVICE_A0FC: return "DEVICE_A0FC";
        case PciDevice0E11::DEVICE_AE10: return "DEVICE_AE10";
        case PciDevice0E11::DEVICE_AE29: return "DEVICE_AE29";
        case PciDevice0E11::DEVICE_AE2A: return "DEVICE_AE2A";
        case PciDevice0E11::DEVICE_AE2B: return "DEVICE_AE2B";
        case PciDevice0E11::DEVICE_AE31: return "DEVICE_AE31";
        case PciDevice0E11::DEVICE_AE32: return "DEVICE_AE32";
        case PciDevice0E11::DEVICE_AE33: return "DEVICE_AE33";
        case PciDevice0E11::DEVICE_AE34: return "DEVICE_AE34";
        case PciDevice0E11::DEVICE_AE35: return "DEVICE_AE35";
        case PciDevice0E11::DEVICE_AE40: return "DEVICE_AE40";
        case PciDevice0E11::DEVICE_AE43: return "DEVICE_AE43";
        case PciDevice0E11::DEVICE_AE69: return "DEVICE_AE69";
        case PciDevice0E11::DEVICE_AE6C: return "DEVICE_AE6C";
        case PciDevice0E11::DEVICE_AE6D: return "DEVICE_AE6D";
        case PciDevice0E11::DEVICE_B011: return "DEVICE_B011";
        case PciDevice0E11::DEVICE_B012: return "DEVICE_B012";
        case PciDevice0E11::DEVICE_B01E: return "DEVICE_B01E";
        case PciDevice0E11::DEVICE_B01F: return "DEVICE_B01F";
        case PciDevice0E11::DEVICE_B02F: return "DEVICE_B02F";
        case PciDevice0E11::DEVICE_B030: return "DEVICE_B030";
        case PciDevice0E11::DEVICE_B04A: return "DEVICE_B04A";
        case PciDevice0E11::DEVICE_B060: return "DEVICE_B060";
        case PciDevice0E11::DEVICE_B0C6: return "DEVICE_B0C6";
        case PciDevice0E11::DEVICE_B0C7: return "DEVICE_B0C7";
        case PciDevice0E11::DEVICE_B0D7: return "DEVICE_B0D7";
        case PciDevice0E11::DEVICE_B0DD: return "DEVICE_B0DD";
        case PciDevice0E11::DEVICE_B0DE: return "DEVICE_B0DE";
        case PciDevice0E11::DEVICE_B0DF: return "DEVICE_B0DF";
        case PciDevice0E11::DEVICE_B0E0: return "DEVICE_B0E0";
        case PciDevice0E11::DEVICE_B0E1: return "DEVICE_B0E1";
        case PciDevice0E11::DEVICE_B123: return "DEVICE_B123";
        case PciDevice0E11::DEVICE_B134: return "DEVICE_B134";
        case PciDevice0E11::DEVICE_B13C: return "DEVICE_B13C";
        case PciDevice0E11::DEVICE_B144: return "DEVICE_B144";
        case PciDevice0E11::DEVICE_B163: return "DEVICE_B163";
        case PciDevice0E11::DEVICE_B164: return "DEVICE_B164";
        case PciDevice0E11::DEVICE_B178: return "DEVICE_B178";
        case PciDevice0E11::DEVICE_B1A4: return "DEVICE_B1A4";
        case PciDevice0E11::DEVICE_B200: return "DEVICE_B200";
        case PciDevice0E11::DEVICE_B203: return "DEVICE_B203";
        case PciDevice0E11::DEVICE_B204: return "DEVICE_B204";
        case PciDevice0E11::DEVICE_C000: return "DEVICE_C000";
        case PciDevice0E11::DEVICE_F130: return "DEVICE_F130";
        case PciDevice0E11::DEVICE_F150: return "DEVICE_F150";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice0E11 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice0E11 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0E11::DEVICE_0001: return "PCI to EISA Bridge";
        case PciDevice0E11::DEVICE_0002: return "PCI to ISA Bridge";
        case PciDevice0E11::DEVICE_0046: return "Smart Array 64xx";
        case PciDevice0E11::DEVICE_0049: return "NC7132 Gigabit Upgrade Module";
        case PciDevice0E11::DEVICE_004A: return "NC6136 Gigabit Server Adapter";
        case PciDevice0E11::DEVICE_005A: return "Remote Insight II board - Lights-Out";
        case PciDevice0E11::DEVICE_007C: return "NC7770 1000BaseTX";
        case PciDevice0E11::DEVICE_007D: return "NC6770 1000BaseTX";
        case PciDevice0E11::DEVICE_0085: return "NC7780 1000BaseTX";
        case PciDevice0E11::DEVICE_00B1: return "Remote Insight II board - PCI device";
        case PciDevice0E11::DEVICE_00BB: return "NC7760";
        case PciDevice0E11::DEVICE_00CA: return "NC7771";
        case PciDevice0E11::DEVICE_00CB: return "NC7781";
        case PciDevice0E11::DEVICE_00CF: return "NC7772";
        case PciDevice0E11::DEVICE_00D0: return "NC7782";
        case PciDevice0E11::DEVICE_00D1: return "NC7783";
        case PciDevice0E11::DEVICE_00E3: return "NC7761";
        case PciDevice0E11::DEVICE_0508: return "Netelligent 4/16 Token Ring";
        case PciDevice0E11::DEVICE_1000: return "Triflex/Pentium Bridge, Model 1000";
        case PciDevice0E11::DEVICE_2000: return "Triflex/Pentium Bridge, Model 2000";
        case PciDevice0E11::DEVICE_3032: return "QVision 1280/p";
        case PciDevice0E11::DEVICE_3033: return "QVision 1280/p";
        case PciDevice0E11::DEVICE_3034: return "QVision 1280/p";
        case PciDevice0E11::DEVICE_4000: return "4000 [Triflex]";
        case PciDevice0E11::DEVICE_4040: return "Integrated Array";
        case PciDevice0E11::DEVICE_4048: return "Compaq Raid LC2";
        case PciDevice0E11::DEVICE_4050: return "Smart Array 4200";
        case PciDevice0E11::DEVICE_4051: return "Smart Array 4250ES";
        case PciDevice0E11::DEVICE_4058: return "Smart Array 431";
        case PciDevice0E11::DEVICE_4070: return "Smart Array 5300";
        case PciDevice0E11::DEVICE_4080: return "Smart Array 5i";
        case PciDevice0E11::DEVICE_4082: return "Smart Array 532";
        case PciDevice0E11::DEVICE_4083: return "Smart Array 5312";
        case PciDevice0E11::DEVICE_4091: return "Smart Array 6i";
        case PciDevice0E11::DEVICE_409A: return "Smart Array 641";
        case PciDevice0E11::DEVICE_409B: return "Smart Array 642";
        case PciDevice0E11::DEVICE_409C: return "Smart Array 6400";
        case PciDevice0E11::DEVICE_409D: return "Smart Array 6400 EM";
        case PciDevice0E11::DEVICE_6010: return "HotPlug PCI Bridge 6010";
        case PciDevice0E11::DEVICE_7020: return "USB Controller";
        case PciDevice0E11::DEVICE_A0EC: return "Fibre Channel Host Controller";
        case PciDevice0E11::DEVICE_A0F0: return "Advanced System Management Controller";
        case PciDevice0E11::DEVICE_A0F3: return "Triflex PCI to ISA Bridge";
        case PciDevice0E11::DEVICE_A0F7: return "PCI Hotplug Controller";
        case PciDevice0E11::DEVICE_A0F8: return "ZFMicro Chipset USB";
        case PciDevice0E11::DEVICE_A0FC: return "FibreChannel HBA Tachyon";
        case PciDevice0E11::DEVICE_AE10: return "Smart-2/P RAID Controller";
        case PciDevice0E11::DEVICE_AE29: return "MIS-L";
        case PciDevice0E11::DEVICE_AE2A: return "MPC";
        case PciDevice0E11::DEVICE_AE2B: return "MIS-E";
        case PciDevice0E11::DEVICE_AE31: return "System Management Controller";
        case PciDevice0E11::DEVICE_AE32: return "Netelligent 10/100 TX PCI UTP";
        case PciDevice0E11::DEVICE_AE33: return "Triflex Dual EIDE Controller";
        case PciDevice0E11::DEVICE_AE34: return "Netelligent 10 T PCI UTP";
        case PciDevice0E11::DEVICE_AE35: return "Integrated NetFlex-3/P";
        case PciDevice0E11::DEVICE_AE40: return "Netelligent Dual 10/100 TX PCI UTP";
        case PciDevice0E11::DEVICE_AE43: return "Netelligent Integrated 10/100 TX UTP";
        case PciDevice0E11::DEVICE_AE69: return "CETUS-L";
        case PciDevice0E11::DEVICE_AE6C: return "Northstar";
        case PciDevice0E11::DEVICE_AE6D: return "NorthStar CPU to PCI Bridge";
        case PciDevice0E11::DEVICE_B011: return "Netelligent 10/100 TX Embedded UTP";
        case PciDevice0E11::DEVICE_B012: return "Netelligent 10 T/2 PCI UTP/Coax";
        case PciDevice0E11::DEVICE_B01E: return "NC3120 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B01F: return "NC3122 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B02F: return "NC1120 Ethernet NIC";
        case PciDevice0E11::DEVICE_B030: return "Netelligent 10/100 TX UTP";
        case PciDevice0E11::DEVICE_B04A: return "10/100 TX PCI Intel WOL UTP Controller";
        case PciDevice0E11::DEVICE_B060: return "Smart Array 5300 Controller";
        case PciDevice0E11::DEVICE_B0C6: return "NC3161 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B0C7: return "NC3160 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B0D7: return "NC3121 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B0DD: return "NC3131 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B0DE: return "NC3132 Fast Ethernet Module";
        case PciDevice0E11::DEVICE_B0DF: return "NC6132 Gigabit Module";
        case PciDevice0E11::DEVICE_B0E0: return "NC6133 Gigabit Module";
        case PciDevice0E11::DEVICE_B0E1: return "NC3133 Fast Ethernet Module";
        case PciDevice0E11::DEVICE_B123: return "NC6134 Gigabit NIC";
        case PciDevice0E11::DEVICE_B134: return "NC3163 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B13C: return "NC3162 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B144: return "NC3123 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B163: return "NC3134 Fast Ethernet NIC";
        case PciDevice0E11::DEVICE_B164: return "NC3165 Fast Ethernet Upgrade Module";
        case PciDevice0E11::DEVICE_B178: return "Smart Array 5i/532";
        case PciDevice0E11::DEVICE_B1A4: return "NC7131 Gigabit Server Adapter";
        case PciDevice0E11::DEVICE_B200: return "Memory Hot-Plug Controller";
        case PciDevice0E11::DEVICE_B203: return "Integrated Lights Out Controller";
        case PciDevice0E11::DEVICE_B204: return "Integrated Lights Out Processor";
        case PciDevice0E11::DEVICE_C000: return "Remote Insight Lights-Out Edition";
        case PciDevice0E11::DEVICE_F130: return "NetFlex-3/P ThunderLAN 1.0";
        case PciDevice0E11::DEVICE_F150: return "NetFlex-3/P ThunderLAN 2.3";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice0E11 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice0E11::DEVICE_0001: return "Unknown device";
        case PciDevice0E11::DEVICE_0002: return "Unknown device";
        case PciDevice0E11::DEVICE_0046: return enumToHumanString((PciSubDevice0E110046)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0E11::DEVICE_0049: return "Unknown device";
        case PciDevice0E11::DEVICE_004A: return "Unknown device";
        case PciDevice0E11::DEVICE_005A: return "Unknown device";
        case PciDevice0E11::DEVICE_007C: return "Unknown device";
        case PciDevice0E11::DEVICE_007D: return "Unknown device";
        case PciDevice0E11::DEVICE_0085: return "Unknown device";
        case PciDevice0E11::DEVICE_00B1: return "Unknown device";
        case PciDevice0E11::DEVICE_00BB: return "Unknown device";
        case PciDevice0E11::DEVICE_00CA: return "Unknown device";
        case PciDevice0E11::DEVICE_00CB: return "Unknown device";
        case PciDevice0E11::DEVICE_00CF: return "Unknown device";
        case PciDevice0E11::DEVICE_00D0: return "Unknown device";
        case PciDevice0E11::DEVICE_00D1: return "Unknown device";
        case PciDevice0E11::DEVICE_00E3: return "Unknown device";
        case PciDevice0E11::DEVICE_0508: return "Unknown device";
        case PciDevice0E11::DEVICE_1000: return "Unknown device";
        case PciDevice0E11::DEVICE_2000: return "Unknown device";
        case PciDevice0E11::DEVICE_3032: return "Unknown device";
        case PciDevice0E11::DEVICE_3033: return "Unknown device";
        case PciDevice0E11::DEVICE_3034: return "Unknown device";
        case PciDevice0E11::DEVICE_4000: return "Unknown device";
        case PciDevice0E11::DEVICE_4040: return "Unknown device";
        case PciDevice0E11::DEVICE_4048: return "Unknown device";
        case PciDevice0E11::DEVICE_4050: return "Unknown device";
        case PciDevice0E11::DEVICE_4051: return "Unknown device";
        case PciDevice0E11::DEVICE_4058: return "Unknown device";
        case PciDevice0E11::DEVICE_4070: return "Unknown device";
        case PciDevice0E11::DEVICE_4080: return "Unknown device";
        case PciDevice0E11::DEVICE_4082: return "Unknown device";
        case PciDevice0E11::DEVICE_4083: return "Unknown device";
        case PciDevice0E11::DEVICE_4091: return "Unknown device";
        case PciDevice0E11::DEVICE_409A: return "Unknown device";
        case PciDevice0E11::DEVICE_409B: return "Unknown device";
        case PciDevice0E11::DEVICE_409C: return "Unknown device";
        case PciDevice0E11::DEVICE_409D: return "Unknown device";
        case PciDevice0E11::DEVICE_6010: return "Unknown device";
        case PciDevice0E11::DEVICE_7020: return "Unknown device";
        case PciDevice0E11::DEVICE_A0EC: return "Unknown device";
        case PciDevice0E11::DEVICE_A0F0: return enumToHumanString((PciSubDevice0E11A0F0)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0E11::DEVICE_A0F3: return "Unknown device";
        case PciDevice0E11::DEVICE_A0F7: return enumToHumanString((PciSubDevice0E11A0F7)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0E11::DEVICE_A0F8: return "Unknown device";
        case PciDevice0E11::DEVICE_A0FC: return "Unknown device";
        case PciDevice0E11::DEVICE_AE10: return enumToHumanString((PciSubDevice0E11AE10)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0E11::DEVICE_AE29: return "Unknown device";
        case PciDevice0E11::DEVICE_AE2A: return "Unknown device";
        case PciDevice0E11::DEVICE_AE2B: return "Unknown device";
        case PciDevice0E11::DEVICE_AE31: return "Unknown device";
        case PciDevice0E11::DEVICE_AE32: return "Unknown device";
        case PciDevice0E11::DEVICE_AE33: return "Unknown device";
        case PciDevice0E11::DEVICE_AE34: return "Unknown device";
        case PciDevice0E11::DEVICE_AE35: return "Unknown device";
        case PciDevice0E11::DEVICE_AE40: return "Unknown device";
        case PciDevice0E11::DEVICE_AE43: return "Unknown device";
        case PciDevice0E11::DEVICE_AE69: return "Unknown device";
        case PciDevice0E11::DEVICE_AE6C: return "Unknown device";
        case PciDevice0E11::DEVICE_AE6D: return "Unknown device";
        case PciDevice0E11::DEVICE_B011: return "Unknown device";
        case PciDevice0E11::DEVICE_B012: return "Unknown device";
        case PciDevice0E11::DEVICE_B01E: return "Unknown device";
        case PciDevice0E11::DEVICE_B01F: return "Unknown device";
        case PciDevice0E11::DEVICE_B02F: return "Unknown device";
        case PciDevice0E11::DEVICE_B030: return "Unknown device";
        case PciDevice0E11::DEVICE_B04A: return "Unknown device";
        case PciDevice0E11::DEVICE_B060: return "Unknown device";
        case PciDevice0E11::DEVICE_B0C6: return "Unknown device";
        case PciDevice0E11::DEVICE_B0C7: return "Unknown device";
        case PciDevice0E11::DEVICE_B0D7: return "Unknown device";
        case PciDevice0E11::DEVICE_B0DD: return "Unknown device";
        case PciDevice0E11::DEVICE_B0DE: return "Unknown device";
        case PciDevice0E11::DEVICE_B0DF: return "Unknown device";
        case PciDevice0E11::DEVICE_B0E0: return "Unknown device";
        case PciDevice0E11::DEVICE_B0E1: return "Unknown device";
        case PciDevice0E11::DEVICE_B123: return "Unknown device";
        case PciDevice0E11::DEVICE_B134: return "Unknown device";
        case PciDevice0E11::DEVICE_B13C: return "Unknown device";
        case PciDevice0E11::DEVICE_B144: return "Unknown device";
        case PciDevice0E11::DEVICE_B163: return "Unknown device";
        case PciDevice0E11::DEVICE_B164: return "Unknown device";
        case PciDevice0E11::DEVICE_B178: return enumToHumanString((PciSubDevice0E11B178)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice0E11::DEVICE_B1A4: return "Unknown device";
        case PciDevice0E11::DEVICE_B200: return "Unknown device";
        case PciDevice0E11::DEVICE_B203: return "Unknown device";
        case PciDevice0E11::DEVICE_B204: return "Unknown device";
        case PciDevice0E11::DEVICE_C000: return "Unknown device";
        case PciDevice0E11::DEVICE_F130: return "Unknown device";
        case PciDevice0E11::DEVICE_F150: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR0E11_PCIDEVICE0E11_H
