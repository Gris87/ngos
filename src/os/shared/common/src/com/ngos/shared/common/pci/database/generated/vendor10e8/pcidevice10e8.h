// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E8_PCIDEVICE10E8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E8_PCIDEVICE10E8_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10E8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1072 = 0x1072,
    DEVICE_2011 = 0x2011,
    DEVICE_4750 = 0x4750,
    DEVICE_5920 = 0x5920,
    DEVICE_8043 = 0x8043,
    DEVICE_8062 = 0x8062,
    DEVICE_807D = 0x807D,
    DEVICE_8088 = 0x8088,
    DEVICE_8089 = 0x8089,
    DEVICE_809C = 0x809C,
    DEVICE_80B9 = 0x80B9,
    DEVICE_80D7 = 0x80D7,
    DEVICE_80D8 = 0x80D8,
    DEVICE_80D9 = 0x80D9,
    DEVICE_80DA = 0x80DA,
    DEVICE_80FC = 0x80FC,
    DEVICE_811A = 0x811A,
    DEVICE_814C = 0x814C,
    DEVICE_8170 = 0x8170,
    DEVICE_81E6 = 0x81E6,
    DEVICE_828D = 0x828D,
    DEVICE_8291 = 0x8291,
    DEVICE_82C4 = 0x82C4,
    DEVICE_82C5 = 0x82C5,
    DEVICE_82C6 = 0x82C6,
    DEVICE_82C7 = 0x82C7,
    DEVICE_82CA = 0x82CA,
    DEVICE_82DB = 0x82DB,
    DEVICE_82E2 = 0x82E2,
    DEVICE_8406 = 0x8406,
    DEVICE_8407 = 0x8407,
    DEVICE_8851 = 0x8851,
    DEVICE_E004 = 0xE004
};



inline const char8* enumToString(PciDevice10E8 device10E8) // TEST: NO
{
    // COMMON_LT((" | device10E8 = %u", device10E8)); // Commented to avoid bad looking logs



    switch (device10E8)
    {
        case PciDevice10E8::NONE:        return "NONE";
        case PciDevice10E8::DEVICE_1072: return "DEVICE_1072";
        case PciDevice10E8::DEVICE_2011: return "DEVICE_2011";
        case PciDevice10E8::DEVICE_4750: return "DEVICE_4750";
        case PciDevice10E8::DEVICE_5920: return "DEVICE_5920";
        case PciDevice10E8::DEVICE_8043: return "DEVICE_8043";
        case PciDevice10E8::DEVICE_8062: return "DEVICE_8062";
        case PciDevice10E8::DEVICE_807D: return "DEVICE_807D";
        case PciDevice10E8::DEVICE_8088: return "DEVICE_8088";
        case PciDevice10E8::DEVICE_8089: return "DEVICE_8089";
        case PciDevice10E8::DEVICE_809C: return "DEVICE_809C";
        case PciDevice10E8::DEVICE_80B9: return "DEVICE_80B9";
        case PciDevice10E8::DEVICE_80D7: return "DEVICE_80D7";
        case PciDevice10E8::DEVICE_80D8: return "DEVICE_80D8";
        case PciDevice10E8::DEVICE_80D9: return "DEVICE_80D9";
        case PciDevice10E8::DEVICE_80DA: return "DEVICE_80DA";
        case PciDevice10E8::DEVICE_80FC: return "DEVICE_80FC";
        case PciDevice10E8::DEVICE_811A: return "DEVICE_811A";
        case PciDevice10E8::DEVICE_814C: return "DEVICE_814C";
        case PciDevice10E8::DEVICE_8170: return "DEVICE_8170";
        case PciDevice10E8::DEVICE_81E6: return "DEVICE_81E6";
        case PciDevice10E8::DEVICE_828D: return "DEVICE_828D";
        case PciDevice10E8::DEVICE_8291: return "DEVICE_8291";
        case PciDevice10E8::DEVICE_82C4: return "DEVICE_82C4";
        case PciDevice10E8::DEVICE_82C5: return "DEVICE_82C5";
        case PciDevice10E8::DEVICE_82C6: return "DEVICE_82C6";
        case PciDevice10E8::DEVICE_82C7: return "DEVICE_82C7";
        case PciDevice10E8::DEVICE_82CA: return "DEVICE_82CA";
        case PciDevice10E8::DEVICE_82DB: return "DEVICE_82DB";
        case PciDevice10E8::DEVICE_82E2: return "DEVICE_82E2";
        case PciDevice10E8::DEVICE_8406: return "DEVICE_8406";
        case PciDevice10E8::DEVICE_8407: return "DEVICE_8407";
        case PciDevice10E8::DEVICE_8851: return "DEVICE_8851";
        case PciDevice10E8::DEVICE_E004: return "DEVICE_E004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10E8 device10E8) // TEST: NO
{
    // COMMON_LT((" | device10E8 = %u", device10E8)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10E8, enumToString(device10E8));

    return res;
}



inline const char8* enumToHumanString(PciDevice10E8 device10E8) // TEST: NO
{
    // COMMON_LT((" | device10E8 = %u", device10E8)); // Commented to avoid bad looking logs



    switch (device10E8)
    {
        case PciDevice10E8::DEVICE_1072: return "INES GPIB-PCI (AMCC5920 based)";
        case PciDevice10E8::DEVICE_2011: return "Q-Motion Video Capture/Edit board";
        case PciDevice10E8::DEVICE_4750: return "S5930 [Matchmaker]";
        case PciDevice10E8::DEVICE_5920: return "S5920";
        case PciDevice10E8::DEVICE_8043: return "LANai4.x [Myrinet LANai interface chip]";
        case PciDevice10E8::DEVICE_8062: return "S5933_PARASTATION";
        case PciDevice10E8::DEVICE_807D: return "S5933 [Matchmaker]";
        case PciDevice10E8::DEVICE_8088: return "Kongsberg Spacetec Format Synchronizer";
        case PciDevice10E8::DEVICE_8089: return "Kongsberg Spacetec Serial Output Board";
        case PciDevice10E8::DEVICE_809C: return "S5933_HEPC3";
        case PciDevice10E8::DEVICE_80B9: return "Harmonix Hi-Card P8 (4x active ISDN BRI)";
        case PciDevice10E8::DEVICE_80D7: return "PCI-9112";
        case PciDevice10E8::DEVICE_80D8: return "PCI-7200";
        case PciDevice10E8::DEVICE_80D9: return "PCI-9118";
        case PciDevice10E8::DEVICE_80DA: return "PCI-9812";
        case PciDevice10E8::DEVICE_80FC: return "APCI1500 Signal processing controller (16 dig. inputs + 16 dig. outputs)";
        case PciDevice10E8::DEVICE_811A: return "PCI-IEEE1355-DS-DE Interface";
        case PciDevice10E8::DEVICE_814C: return "Fastcom ESCC-PCI (Commtech, Inc.)";
        case PciDevice10E8::DEVICE_8170: return "S5933 [Matchmaker] (Chipset Development Tool)";
        case PciDevice10E8::DEVICE_81E6: return "Multimedia video controller";
        case PciDevice10E8::DEVICE_828D: return "APCI3001 Signal processing controller (up to 16 analog inputs)";
        case PciDevice10E8::DEVICE_8291: return "Fastcom 232/8-PCI (Commtech, Inc.)";
        case PciDevice10E8::DEVICE_82C4: return "Fastcom 422/4-PCI (Commtech, Inc.)";
        case PciDevice10E8::DEVICE_82C5: return "Fastcom 422/2-PCI (Commtech, Inc.)";
        case PciDevice10E8::DEVICE_82C6: return "Fastcom IG422/1-PCI (Commtech, Inc.)";
        case PciDevice10E8::DEVICE_82C7: return "Fastcom IG232/2-PCI (Commtech, Inc.)";
        case PciDevice10E8::DEVICE_82CA: return "Fastcom 232/4-PCI (Commtech, Inc.)";
        case PciDevice10E8::DEVICE_82DB: return "AJA HDNTV HD SDI Framestore";
        case PciDevice10E8::DEVICE_82E2: return "Fastcom DIO24H-PCI (Commtech, Inc.)";
        case PciDevice10E8::DEVICE_8406: return "PCIcanx/PCIcan CAN interface [Kvaser AB]";
        case PciDevice10E8::DEVICE_8407: return "PCIcan II CAN interface (A1021, PCB-07, PCB-08) [Kvaser AB]";
        case PciDevice10E8::DEVICE_8851: return "S5933 on Innes Corp FM Radio Capture card";
        case PciDevice10E8::DEVICE_E004: return "X-Gene PCIe bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10E8_PCIDEVICE10E8_H
