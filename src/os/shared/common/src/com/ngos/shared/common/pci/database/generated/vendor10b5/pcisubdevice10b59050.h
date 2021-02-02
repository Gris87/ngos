// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59050_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59050_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B59050: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B51067 = 0x10B51067,
    SUBDEVICE_10B5114E = 0x10B5114E,
    SUBDEVICE_10B51169 = 0x10B51169,
    SUBDEVICE_10B51172 = 0x10B51172,
    SUBDEVICE_10B52036 = 0x10B52036,
    SUBDEVICE_10B52221 = 0x10B52221,
    SUBDEVICE_10B52273 = 0x10B52273,
    SUBDEVICE_10B52431 = 0x10B52431,
    SUBDEVICE_10B52905 = 0x10B52905,
    SUBDEVICE_10B53196 = 0x10B53196,
    SUBDEVICE_10B59050 = 0x10B59050,
    SUBDEVICE_12FE0001 = 0x12FE0001,
    SUBDEVICE_13698901 = 0x13698901,
    SUBDEVICE_13698F01 = 0x13698F01,
    SUBDEVICE_13699401 = 0x13699401,
    SUBDEVICE_13699501 = 0x13699501,
    SUBDEVICE_14980362 = 0x14980362,
    SUBDEVICE_15220001 = 0x15220001,
    SUBDEVICE_15220002 = 0x15220002,
    SUBDEVICE_15220003 = 0x15220003,
    SUBDEVICE_15220004 = 0x15220004,
    SUBDEVICE_15220010 = 0x15220010,
    SUBDEVICE_15220020 = 0x15220020,
    SUBDEVICE_15ED1000 = 0x15ED1000,
    SUBDEVICE_15ED1001 = 0x15ED1001,
    SUBDEVICE_15ED1002 = 0x15ED1002,
    SUBDEVICE_15ED1003 = 0x15ED1003,
    SUBDEVICE_56542036 = 0x56542036,
    SUBDEVICE_56543132 = 0x56543132,
    SUBDEVICE_56545634 = 0x56545634,
    SUBDEVICE_D531C002 = 0xD531C002,
    SUBDEVICE_D84D4006 = 0xD84D4006,
    SUBDEVICE_D84D4008 = 0xD84D4008,
    SUBDEVICE_D84D4014 = 0xD84D4014,
    SUBDEVICE_D84D4018 = 0xD84D4018,
    SUBDEVICE_D84D4025 = 0xD84D4025,
    SUBDEVICE_D84D4027 = 0xD84D4027,
    SUBDEVICE_D84D4028 = 0xD84D4028,
    SUBDEVICE_D84D4036 = 0xD84D4036,
    SUBDEVICE_D84D4037 = 0xD84D4037,
    SUBDEVICE_D84D4038 = 0xD84D4038,
    SUBDEVICE_D84D4052 = 0xD84D4052,
    SUBDEVICE_D84D4053 = 0xD84D4053,
    SUBDEVICE_D84D4055 = 0xD84D4055,
    SUBDEVICE_D84D4058 = 0xD84D4058,
    SUBDEVICE_D84D4065 = 0xD84D4065,
    SUBDEVICE_D84D4068 = 0xD84D4068,
    SUBDEVICE_D84D4078 = 0xD84D4078
};



inline const char8* enumToString(PciSubDevice10B59050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59050::NONE:               return "NONE";
        case PciSubDevice10B59050::SUBDEVICE_10B51067: return "SUBDEVICE_10B51067";
        case PciSubDevice10B59050::SUBDEVICE_10B5114E: return "SUBDEVICE_10B5114E";
        case PciSubDevice10B59050::SUBDEVICE_10B51169: return "SUBDEVICE_10B51169";
        case PciSubDevice10B59050::SUBDEVICE_10B51172: return "SUBDEVICE_10B51172";
        case PciSubDevice10B59050::SUBDEVICE_10B52036: return "SUBDEVICE_10B52036";
        case PciSubDevice10B59050::SUBDEVICE_10B52221: return "SUBDEVICE_10B52221";
        case PciSubDevice10B59050::SUBDEVICE_10B52273: return "SUBDEVICE_10B52273";
        case PciSubDevice10B59050::SUBDEVICE_10B52431: return "SUBDEVICE_10B52431";
        case PciSubDevice10B59050::SUBDEVICE_10B52905: return "SUBDEVICE_10B52905";
        case PciSubDevice10B59050::SUBDEVICE_10B53196: return "SUBDEVICE_10B53196";
        case PciSubDevice10B59050::SUBDEVICE_10B59050: return "SUBDEVICE_10B59050";
        case PciSubDevice10B59050::SUBDEVICE_12FE0001: return "SUBDEVICE_12FE0001";
        case PciSubDevice10B59050::SUBDEVICE_13698901: return "SUBDEVICE_13698901";
        case PciSubDevice10B59050::SUBDEVICE_13698F01: return "SUBDEVICE_13698F01";
        case PciSubDevice10B59050::SUBDEVICE_13699401: return "SUBDEVICE_13699401";
        case PciSubDevice10B59050::SUBDEVICE_13699501: return "SUBDEVICE_13699501";
        case PciSubDevice10B59050::SUBDEVICE_14980362: return "SUBDEVICE_14980362";
        case PciSubDevice10B59050::SUBDEVICE_15220001: return "SUBDEVICE_15220001";
        case PciSubDevice10B59050::SUBDEVICE_15220002: return "SUBDEVICE_15220002";
        case PciSubDevice10B59050::SUBDEVICE_15220003: return "SUBDEVICE_15220003";
        case PciSubDevice10B59050::SUBDEVICE_15220004: return "SUBDEVICE_15220004";
        case PciSubDevice10B59050::SUBDEVICE_15220010: return "SUBDEVICE_15220010";
        case PciSubDevice10B59050::SUBDEVICE_15220020: return "SUBDEVICE_15220020";
        case PciSubDevice10B59050::SUBDEVICE_15ED1000: return "SUBDEVICE_15ED1000";
        case PciSubDevice10B59050::SUBDEVICE_15ED1001: return "SUBDEVICE_15ED1001";
        case PciSubDevice10B59050::SUBDEVICE_15ED1002: return "SUBDEVICE_15ED1002";
        case PciSubDevice10B59050::SUBDEVICE_15ED1003: return "SUBDEVICE_15ED1003";
        case PciSubDevice10B59050::SUBDEVICE_56542036: return "SUBDEVICE_56542036";
        case PciSubDevice10B59050::SUBDEVICE_56543132: return "SUBDEVICE_56543132";
        case PciSubDevice10B59050::SUBDEVICE_56545634: return "SUBDEVICE_56545634";
        case PciSubDevice10B59050::SUBDEVICE_D531C002: return "SUBDEVICE_D531C002";
        case PciSubDevice10B59050::SUBDEVICE_D84D4006: return "SUBDEVICE_D84D4006";
        case PciSubDevice10B59050::SUBDEVICE_D84D4008: return "SUBDEVICE_D84D4008";
        case PciSubDevice10B59050::SUBDEVICE_D84D4014: return "SUBDEVICE_D84D4014";
        case PciSubDevice10B59050::SUBDEVICE_D84D4018: return "SUBDEVICE_D84D4018";
        case PciSubDevice10B59050::SUBDEVICE_D84D4025: return "SUBDEVICE_D84D4025";
        case PciSubDevice10B59050::SUBDEVICE_D84D4027: return "SUBDEVICE_D84D4027";
        case PciSubDevice10B59050::SUBDEVICE_D84D4028: return "SUBDEVICE_D84D4028";
        case PciSubDevice10B59050::SUBDEVICE_D84D4036: return "SUBDEVICE_D84D4036";
        case PciSubDevice10B59050::SUBDEVICE_D84D4037: return "SUBDEVICE_D84D4037";
        case PciSubDevice10B59050::SUBDEVICE_D84D4038: return "SUBDEVICE_D84D4038";
        case PciSubDevice10B59050::SUBDEVICE_D84D4052: return "SUBDEVICE_D84D4052";
        case PciSubDevice10B59050::SUBDEVICE_D84D4053: return "SUBDEVICE_D84D4053";
        case PciSubDevice10B59050::SUBDEVICE_D84D4055: return "SUBDEVICE_D84D4055";
        case PciSubDevice10B59050::SUBDEVICE_D84D4058: return "SUBDEVICE_D84D4058";
        case PciSubDevice10B59050::SUBDEVICE_D84D4065: return "SUBDEVICE_D84D4065";
        case PciSubDevice10B59050::SUBDEVICE_D84D4068: return "SUBDEVICE_D84D4068";
        case PciSubDevice10B59050::SUBDEVICE_D84D4078: return "SUBDEVICE_D84D4078";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B59050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B59050 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59050::SUBDEVICE_10B51067: return "IXXAT CAN bad_int165";
        case PciSubDevice10B59050::SUBDEVICE_10B5114E: return "Wasco WITIO PCbad_int168extended";
        case PciSubDevice10B59050::SUBDEVICE_10B51169: return "Wasco OPTOIO32standard 32 digital in, 32 digital out";
        case PciSubDevice10B59050::SUBDEVICE_10B51172: return "IK220 (Heidenhain)";
        case PciSubDevice10B59050::SUBDEVICE_10B52036: return "SatPak GPS";
        case PciSubDevice10B59050::SUBDEVICE_10B52221: return "Alpermann+Velte PCL PCI LV: Timecode Reader Board";
        case PciSubDevice10B59050::SUBDEVICE_10B52273: return "SH ARC-PCI SOHARD ARCNET card";
        case PciSubDevice10B59050::SUBDEVICE_10B52431: return "Alpermann+Velte PCL PCI D: Timecode Reader Board";
        case PciSubDevice10B59050::SUBDEVICE_10B52905: return "Alpermann+Velte PCI TS: Time Synchronisation Board";
        case PciSubDevice10B59050::SUBDEVICE_10B53196: return "Goramo PLX200SYN sync serial card";
        case PciSubDevice10B59050::SUBDEVICE_10B59050: return "PCI-I04 PCI Passive PC/CAN Interface";
        case PciSubDevice10B59050::SUBDEVICE_12FE0001: return "CAN-PCI/331 CAN bus controller";
        case PciSubDevice10B59050::SUBDEVICE_13698901: return "PCX11+ PCI";
        case PciSubDevice10B59050::SUBDEVICE_13698F01: return "VX222";
        case PciSubDevice10B59050::SUBDEVICE_13699401: return "PCX924";
        case PciSubDevice10B59050::SUBDEVICE_13699501: return "PCX22";
        case PciSubDevice10B59050::SUBDEVICE_14980362: return "TPMC866 8 Channel Serial Card";
        case PciSubDevice10B59050::SUBDEVICE_15220001: return "RockForce 4 Port V.90 Data/Fax/Voice Modem";
        case PciSubDevice10B59050::SUBDEVICE_15220002: return "RockForce 2 Port V.90 Data/Fax/Voice Modem";
        case PciSubDevice10B59050::SUBDEVICE_15220003: return "RockForce 6 Port V.90 Data/Fax/Voice Modem";
        case PciSubDevice10B59050::SUBDEVICE_15220004: return "RockForce 8 Port V.90 Data/Fax/Voice Modem";
        case PciSubDevice10B59050::SUBDEVICE_15220010: return "RockForce2000 4 Port V.90 Data/Fax/Voice Modem";
        case PciSubDevice10B59050::SUBDEVICE_15220020: return "RockForce2000 2 Port V.90 Data/Fax/Voice Modem";
        case PciSubDevice10B59050::SUBDEVICE_15ED1000: return "Macrolink MCCS 8-port Serial";
        case PciSubDevice10B59050::SUBDEVICE_15ED1001: return "Macrolink MCCS 16-port Serial";
        case PciSubDevice10B59050::SUBDEVICE_15ED1002: return "Macrolink MCCS 8-port Serial Hot Swap";
        case PciSubDevice10B59050::SUBDEVICE_15ED1003: return "Macrolink MCCS 16-port Serial Hot Swap";
        case PciSubDevice10B59050::SUBDEVICE_56542036: return "OpenSwitch 6 Telephony card";
        case PciSubDevice10B59050::SUBDEVICE_56543132: return "OpenSwitch 12 Telephony card";
        case PciSubDevice10B59050::SUBDEVICE_56545634: return "OpenLine4 Telephony Card";
        case PciSubDevice10B59050::SUBDEVICE_D531C002: return "PCIntelliCAN 2xSJA1000 CAN bus";
        case PciSubDevice10B59050::SUBDEVICE_D84D4006: return "EX-4006 1P";
        case PciSubDevice10B59050::SUBDEVICE_D84D4008: return "EX-4008 1P EPP/ECP";
        case PciSubDevice10B59050::SUBDEVICE_D84D4014: return "EX-4014 2P";
        case PciSubDevice10B59050::SUBDEVICE_D84D4018: return "EX-4018 3P EPP/ECP";
        case PciSubDevice10B59050::SUBDEVICE_D84D4025: return "EX-4025 1S(16C550) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4027: return "EX-4027 1S(16C650) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4028: return "EX-4028 1S(16C850) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4036: return "EX-4036 2S(16C650) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4037: return "EX-4037 2S(16C650) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4038: return "EX-4038 2S(16C850) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4052: return "EX-4052 1S(16C550) RS-422/485";
        case PciSubDevice10B59050::SUBDEVICE_D84D4053: return "EX-4053 2S(16C550) RS-422/485";
        case PciSubDevice10B59050::SUBDEVICE_D84D4055: return "EX-4055 4S(16C550) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4058: return "EX-4055 4S(16C650) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4065: return "EX-4065 8S(16C550) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4068: return "EX-4068 8S(16C650) RS-232";
        case PciSubDevice10B59050::SUBDEVICE_D84D4078: return "EX-4078 2S(16C552) RS-232+1P";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59050_H
