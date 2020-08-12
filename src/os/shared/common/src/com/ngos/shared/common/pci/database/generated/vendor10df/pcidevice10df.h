// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCIDEVICE10DF_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCIDEVICE10DF_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10DF: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0720 = 0x0720,
    DEVICE_0722 = 0x0722,
    DEVICE_0723 = 0x0723,
    DEVICE_0724 = 0x0724,
    DEVICE_0728 = 0x0728,
    DEVICE_072A = 0x072A,
    DEVICE_072B = 0x072B,
    DEVICE_072C = 0x072C,
    DEVICE_1AE5 = 0x1AE5,
    DEVICE_E100 = 0xE100,
    DEVICE_E131 = 0xE131,
    DEVICE_E180 = 0xE180,
    DEVICE_E200 = 0xE200,
    DEVICE_E208 = 0xE208,
    DEVICE_E220 = 0xE220,
    DEVICE_E240 = 0xE240,
    DEVICE_E260 = 0xE260,
    DEVICE_E268 = 0xE268,
    DEVICE_E300 = 0xE300,
    DEVICE_F011 = 0xF011,
    DEVICE_F015 = 0xF015,
    DEVICE_F085 = 0xF085,
    DEVICE_F095 = 0xF095,
    DEVICE_F098 = 0xF098,
    DEVICE_F0A1 = 0xF0A1,
    DEVICE_F0A5 = 0xF0A5,
    DEVICE_F0B5 = 0xF0B5,
    DEVICE_F0D1 = 0xF0D1,
    DEVICE_F0D5 = 0xF0D5,
    DEVICE_F0E1 = 0xF0E1,
    DEVICE_F0E5 = 0xF0E5,
    DEVICE_F0F5 = 0xF0F5,
    DEVICE_F100 = 0xF100,
    DEVICE_F111 = 0xF111,
    DEVICE_F112 = 0xF112,
    DEVICE_F180 = 0xF180,
    DEVICE_F400 = 0xF400,
    DEVICE_F700 = 0xF700,
    DEVICE_F701 = 0xF701,
    DEVICE_F800 = 0xF800,
    DEVICE_F801 = 0xF801,
    DEVICE_F900 = 0xF900,
    DEVICE_F901 = 0xF901,
    DEVICE_F980 = 0xF980,
    DEVICE_F981 = 0xF981,
    DEVICE_F982 = 0xF982,
    DEVICE_FA00 = 0xFA00,
    DEVICE_FB00 = 0xFB00,
    DEVICE_FC00 = 0xFC00,
    DEVICE_FC10 = 0xFC10,
    DEVICE_FC20 = 0xFC20,
    DEVICE_FC40 = 0xFC40,
    DEVICE_FC50 = 0xFC50,
    DEVICE_FD00 = 0xFD00,
    DEVICE_FD11 = 0xFD11,
    DEVICE_FD12 = 0xFD12,
    DEVICE_FE00 = 0xFE00,
    DEVICE_FE05 = 0xFE05,
    DEVICE_FE11 = 0xFE11,
    DEVICE_FE12 = 0xFE12,
    DEVICE_FF00 = 0xFF00
};



inline const char8* enumToString(PciDevice10DF device10DF) // TEST: NO
{
    // COMMON_LT((" | device10DF = %u", device10DF)); // Commented to avoid bad looking logs



    switch (device10DF)
    {
        case PciDevice10DF::NONE:        return "NONE";
        case PciDevice10DF::DEVICE_0720: return "DEVICE_0720";
        case PciDevice10DF::DEVICE_0722: return "DEVICE_0722";
        case PciDevice10DF::DEVICE_0723: return "DEVICE_0723";
        case PciDevice10DF::DEVICE_0724: return "DEVICE_0724";
        case PciDevice10DF::DEVICE_0728: return "DEVICE_0728";
        case PciDevice10DF::DEVICE_072A: return "DEVICE_072A";
        case PciDevice10DF::DEVICE_072B: return "DEVICE_072B";
        case PciDevice10DF::DEVICE_072C: return "DEVICE_072C";
        case PciDevice10DF::DEVICE_1AE5: return "DEVICE_1AE5";
        case PciDevice10DF::DEVICE_E100: return "DEVICE_E100";
        case PciDevice10DF::DEVICE_E131: return "DEVICE_E131";
        case PciDevice10DF::DEVICE_E180: return "DEVICE_E180";
        case PciDevice10DF::DEVICE_E200: return "DEVICE_E200";
        case PciDevice10DF::DEVICE_E208: return "DEVICE_E208";
        case PciDevice10DF::DEVICE_E220: return "DEVICE_E220";
        case PciDevice10DF::DEVICE_E240: return "DEVICE_E240";
        case PciDevice10DF::DEVICE_E260: return "DEVICE_E260";
        case PciDevice10DF::DEVICE_E268: return "DEVICE_E268";
        case PciDevice10DF::DEVICE_E300: return "DEVICE_E300";
        case PciDevice10DF::DEVICE_F011: return "DEVICE_F011";
        case PciDevice10DF::DEVICE_F015: return "DEVICE_F015";
        case PciDevice10DF::DEVICE_F085: return "DEVICE_F085";
        case PciDevice10DF::DEVICE_F095: return "DEVICE_F095";
        case PciDevice10DF::DEVICE_F098: return "DEVICE_F098";
        case PciDevice10DF::DEVICE_F0A1: return "DEVICE_F0A1";
        case PciDevice10DF::DEVICE_F0A5: return "DEVICE_F0A5";
        case PciDevice10DF::DEVICE_F0B5: return "DEVICE_F0B5";
        case PciDevice10DF::DEVICE_F0D1: return "DEVICE_F0D1";
        case PciDevice10DF::DEVICE_F0D5: return "DEVICE_F0D5";
        case PciDevice10DF::DEVICE_F0E1: return "DEVICE_F0E1";
        case PciDevice10DF::DEVICE_F0E5: return "DEVICE_F0E5";
        case PciDevice10DF::DEVICE_F0F5: return "DEVICE_F0F5";
        case PciDevice10DF::DEVICE_F100: return "DEVICE_F100";
        case PciDevice10DF::DEVICE_F111: return "DEVICE_F111";
        case PciDevice10DF::DEVICE_F112: return "DEVICE_F112";
        case PciDevice10DF::DEVICE_F180: return "DEVICE_F180";
        case PciDevice10DF::DEVICE_F400: return "DEVICE_F400";
        case PciDevice10DF::DEVICE_F700: return "DEVICE_F700";
        case PciDevice10DF::DEVICE_F701: return "DEVICE_F701";
        case PciDevice10DF::DEVICE_F800: return "DEVICE_F800";
        case PciDevice10DF::DEVICE_F801: return "DEVICE_F801";
        case PciDevice10DF::DEVICE_F900: return "DEVICE_F900";
        case PciDevice10DF::DEVICE_F901: return "DEVICE_F901";
        case PciDevice10DF::DEVICE_F980: return "DEVICE_F980";
        case PciDevice10DF::DEVICE_F981: return "DEVICE_F981";
        case PciDevice10DF::DEVICE_F982: return "DEVICE_F982";
        case PciDevice10DF::DEVICE_FA00: return "DEVICE_FA00";
        case PciDevice10DF::DEVICE_FB00: return "DEVICE_FB00";
        case PciDevice10DF::DEVICE_FC00: return "DEVICE_FC00";
        case PciDevice10DF::DEVICE_FC10: return "DEVICE_FC10";
        case PciDevice10DF::DEVICE_FC20: return "DEVICE_FC20";
        case PciDevice10DF::DEVICE_FC40: return "DEVICE_FC40";
        case PciDevice10DF::DEVICE_FC50: return "DEVICE_FC50";
        case PciDevice10DF::DEVICE_FD00: return "DEVICE_FD00";
        case PciDevice10DF::DEVICE_FD11: return "DEVICE_FD11";
        case PciDevice10DF::DEVICE_FD12: return "DEVICE_FD12";
        case PciDevice10DF::DEVICE_FE00: return "DEVICE_FE00";
        case PciDevice10DF::DEVICE_FE05: return "DEVICE_FE05";
        case PciDevice10DF::DEVICE_FE11: return "DEVICE_FE11";
        case PciDevice10DF::DEVICE_FE12: return "DEVICE_FE12";
        case PciDevice10DF::DEVICE_FF00: return "DEVICE_FF00";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10DF device10DF) // TEST: NO
{
    // COMMON_LT((" | device10DF = %u", device10DF)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10DF, enumToString(device10DF));

    return res;
}



inline const char8* enumToHumanString(PciDevice10DF device10DF) // TEST: NO
{
    // COMMON_LT((" | device10DF = %u", device10DF)); // Commented to avoid bad looking logs



    switch (device10DF)
    {
        case PciDevice10DF::DEVICE_0720: return "OneConnect NIC (Skyhawk)";
        case PciDevice10DF::DEVICE_0722: return "OneConnect iSCSI Initiator (Skyhawk)";
        case PciDevice10DF::DEVICE_0723: return "OneConnect iSCSI Initiator + Target (Skyhawk)";
        case PciDevice10DF::DEVICE_0724: return "OneConnect FCoE Initiator (Skyhawk)";
        case PciDevice10DF::DEVICE_0728: return "OneConnect NIC (Skyhawk-VF)";
        case PciDevice10DF::DEVICE_072A: return "OneConnect iSCSI Initiator (Skyhawk-VF)";
        case PciDevice10DF::DEVICE_072B: return "OneConnect iSCSI Initiator + Target (Skyhawk-VF)";
        case PciDevice10DF::DEVICE_072C: return "OneConnect FCoE Initiator (Skyhawk-VF)";
        case PciDevice10DF::DEVICE_1AE5: return "LP6000 Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_E100: return "Proteus-X: LightPulse IOV Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_E131: return "LightPulse 8Gb/s PCIe Shared I/O Fibre Channel Adapter";
        case PciDevice10DF::DEVICE_E180: return "Proteus-X: LightPulse IOV Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_E200: return "LPe15000/LPe16000 Series 8Gb/16Gb Fibre Channel Adapter";
        case PciDevice10DF::DEVICE_E208: return "LightPulse 16Gb Fibre Channel Host Adapter (Lancer-VF)";
        case PciDevice10DF::DEVICE_E220: return "OneConnect NIC (Lancer)";
        case PciDevice10DF::DEVICE_E240: return "OneConnect iSCSI Initiator (Lancer)";
        case PciDevice10DF::DEVICE_E260: return "OneConnect FCoE Initiator (Lancer)";
        case PciDevice10DF::DEVICE_E268: return "OneConnect 10Gb FCoE Converged Network Adapter (Lancer-VF)";
        case PciDevice10DF::DEVICE_E300: return "LPe31000/LPe32000 Series 16Gb/32Gb Fibre Channel Adapter";
        case PciDevice10DF::DEVICE_F011: return "Saturn: LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F015: return "Saturn: LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F085: return "LP850 Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F095: return "LP952 Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F098: return "LP982 Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F0A1: return "Thor LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F0A5: return "Thor LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F0B5: return "Viper LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F0D1: return "Helios LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F0D5: return "Helios LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F0E1: return "Zephyr LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F0E5: return "Zephyr LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F0F5: return "Neptune LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F100: return "LPe12000 Series 8Gb Fibre Channel Adapter";
        case PciDevice10DF::DEVICE_F111: return "Saturn-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F112: return "Saturn-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F180: return "LPSe12002 EmulexSecure Fibre Channel Adapter";
        case PciDevice10DF::DEVICE_F400: return "LPe35000/LPe36000 Series 32Gb/64Gb Fibre Channel Adapter";
        case PciDevice10DF::DEVICE_F700: return "LP7000 Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F701: return "LP7000 Fibre Channel Host Adapter Alternate ID (JX1:2-3, JX2:1-2)";
        case PciDevice10DF::DEVICE_F800: return "LP8000 Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F801: return "LP8000 Fibre Channel Host Adapter Alternate ID (JX1:2-3, JX2:1-2)";
        case PciDevice10DF::DEVICE_F900: return "LP9000 Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F901: return "LP9000 Fibre Channel Host Adapter Alternate ID (JX1:2-3, JX2:1-2)";
        case PciDevice10DF::DEVICE_F980: return "LP9802 Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_F981: return "LP9802 Fibre Channel Host Adapter Alternate ID";
        case PciDevice10DF::DEVICE_F982: return "LP9802 Fibre Channel Host Adapter Alternate ID";
        case PciDevice10DF::DEVICE_FA00: return "Thor-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FB00: return "Viper LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FC00: return "Thor-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FC10: return "Helios-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FC20: return "Zephyr-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FC40: return "Saturn-X: LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FC50: return "Proteus-X: LightPulse IOV Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FD00: return "Helios-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FD11: return "Helios-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FD12: return "Helios-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FE00: return "Zephyr-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FE05: return "Zephyr-X: LightPulse FCoE Adapter";
        case PciDevice10DF::DEVICE_FE11: return "Zephyr-X LightPulse Fibre Channel Host Adapter";
        case PciDevice10DF::DEVICE_FE12: return "Zephyr-X LightPulse FCoE Adapter";
        case PciDevice10DF::DEVICE_FF00: return "Neptune LightPulse Fibre Channel Host Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DF_PCIDEVICE10DF_H
