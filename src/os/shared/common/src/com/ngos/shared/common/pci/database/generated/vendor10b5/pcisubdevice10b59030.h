// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59030_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59030_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B59030: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10B52695 = 0x10B52695,
    SUBDEVICE_10B52862 = 0x10B52862,
    SUBDEVICE_10B52906 = 0x10B52906,
    SUBDEVICE_10B52940 = 0x10B52940,
    SUBDEVICE_10B52977 = 0x10B52977,
    SUBDEVICE_10B52978 = 0x10B52978,
    SUBDEVICE_10B53025 = 0x10B53025,
    SUBDEVICE_10B53068 = 0x10B53068,
    SUBDEVICE_10B53463 = 0x10B53463,
    SUBDEVICE_10B53591 = 0x10B53591,
    SUBDEVICE_12FE0111 = 0x12FE0111,
    SUBDEVICE_13699C01 = 0x13699C01,
    SUBDEVICE_13699D01 = 0x13699D01,
    SUBDEVICE_13699D02 = 0x13699D02,
    SUBDEVICE_13699E01 = 0x13699E01,
    SUBDEVICE_13699F01 = 0x13699F01,
    SUBDEVICE_13699F02 = 0x13699F02,
    SUBDEVICE_1369A001 = 0x1369A001,
    SUBDEVICE_1369A701 = 0x1369A701,
    SUBDEVICE_1369A801 = 0x1369A801,
    SUBDEVICE_13973136 = 0x13973136,
    SUBDEVICE_13973137 = 0x13973137,
    SUBDEVICE_15180200 = 0x15180200,
    SUBDEVICE_15ED1002 = 0x15ED1002,
    SUBDEVICE_15ED1003 = 0x15ED1003,
    SUBDEVICE_E1C50001 = 0xE1C50001,
    SUBDEVICE_E1C50005 = 0xE1C50005,
    SUBDEVICE_E1C50006 = 0xE1C50006
};



inline const char8* enumToString(PciSubDevice10B59030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59030::NONE:               return "NONE";
        case PciSubDevice10B59030::SUBDEVICE_10B52695: return "SUBDEVICE_10B52695";
        case PciSubDevice10B59030::SUBDEVICE_10B52862: return "SUBDEVICE_10B52862";
        case PciSubDevice10B59030::SUBDEVICE_10B52906: return "SUBDEVICE_10B52906";
        case PciSubDevice10B59030::SUBDEVICE_10B52940: return "SUBDEVICE_10B52940";
        case PciSubDevice10B59030::SUBDEVICE_10B52977: return "SUBDEVICE_10B52977";
        case PciSubDevice10B59030::SUBDEVICE_10B52978: return "SUBDEVICE_10B52978";
        case PciSubDevice10B59030::SUBDEVICE_10B53025: return "SUBDEVICE_10B53025";
        case PciSubDevice10B59030::SUBDEVICE_10B53068: return "SUBDEVICE_10B53068";
        case PciSubDevice10B59030::SUBDEVICE_10B53463: return "SUBDEVICE_10B53463";
        case PciSubDevice10B59030::SUBDEVICE_10B53591: return "SUBDEVICE_10B53591";
        case PciSubDevice10B59030::SUBDEVICE_12FE0111: return "SUBDEVICE_12FE0111";
        case PciSubDevice10B59030::SUBDEVICE_13699C01: return "SUBDEVICE_13699C01";
        case PciSubDevice10B59030::SUBDEVICE_13699D01: return "SUBDEVICE_13699D01";
        case PciSubDevice10B59030::SUBDEVICE_13699D02: return "SUBDEVICE_13699D02";
        case PciSubDevice10B59030::SUBDEVICE_13699E01: return "SUBDEVICE_13699E01";
        case PciSubDevice10B59030::SUBDEVICE_13699F01: return "SUBDEVICE_13699F01";
        case PciSubDevice10B59030::SUBDEVICE_13699F02: return "SUBDEVICE_13699F02";
        case PciSubDevice10B59030::SUBDEVICE_1369A001: return "SUBDEVICE_1369A001";
        case PciSubDevice10B59030::SUBDEVICE_1369A701: return "SUBDEVICE_1369A701";
        case PciSubDevice10B59030::SUBDEVICE_1369A801: return "SUBDEVICE_1369A801";
        case PciSubDevice10B59030::SUBDEVICE_13973136: return "SUBDEVICE_13973136";
        case PciSubDevice10B59030::SUBDEVICE_13973137: return "SUBDEVICE_13973137";
        case PciSubDevice10B59030::SUBDEVICE_15180200: return "SUBDEVICE_15180200";
        case PciSubDevice10B59030::SUBDEVICE_15ED1002: return "SUBDEVICE_15ED1002";
        case PciSubDevice10B59030::SUBDEVICE_15ED1003: return "SUBDEVICE_15ED1003";
        case PciSubDevice10B59030::SUBDEVICE_E1C50001: return "SUBDEVICE_E1C50001";
        case PciSubDevice10B59030::SUBDEVICE_E1C50005: return "SUBDEVICE_E1C50005";
        case PciSubDevice10B59030::SUBDEVICE_E1C50006: return "SUBDEVICE_E1C50006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B59030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B59030 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B59030::SUBDEVICE_10B52695: return "Hilscher CIF50-PB/DPS Profibus";
        case PciSubDevice10B59030::SUBDEVICE_10B52862: return "Alpermann+Velte PCL PCI LV (3V/5V): Timecode Reader Board";
        case PciSubDevice10B59030::SUBDEVICE_10B52906: return "Alpermann+Velte PCI TS (3V/5V): Time Synchronisation Board";
        case PciSubDevice10B59030::SUBDEVICE_10B52940: return "Alpermann+Velte PCL PCI D (3V/5V): Timecode Reader Board";
        case PciSubDevice10B59030::SUBDEVICE_10B52977: return "IXXAT iPC-I XC16/PCI CAN Board";
        case PciSubDevice10B59030::SUBDEVICE_10B52978: return "SH ARC-PCIu/SH ARC-PCI104/SH ARC-PCIe SOHARD ARCNET card";
        case PciSubDevice10B59030::SUBDEVICE_10B53025: return "Alpermann+Velte PCL PCI L (3V/5V): Timecode Reader Board";
        case PciSubDevice10B59030::SUBDEVICE_10B53068: return "Alpermann+Velte PCL PCI HD (3V/5V): Timecode Reader Board";
        case PciSubDevice10B59030::SUBDEVICE_10B53463: return "Alpermann+Velte PCL PCI D (v2) (3V/5V): Timecode Reader Board";
        case PciSubDevice10B59030::SUBDEVICE_10B53591: return "PLURA PCL PCI L (v2) (3.3V/5V): Time Code Reader Board";
        case PciSubDevice10B59030::SUBDEVICE_12FE0111: return "CPCI-ASIO4 (ESD 4-port Serial Interface Board)";
        case PciSubDevice10B59030::SUBDEVICE_13699C01: return "VX222v2";
        case PciSubDevice10B59030::SUBDEVICE_13699D01: return "VX222-Mic";
        case PciSubDevice10B59030::SUBDEVICE_13699D02: return "VX222-Mic";
        case PciSubDevice10B59030::SUBDEVICE_13699E01: return "PCX924v2";
        case PciSubDevice10B59030::SUBDEVICE_13699F01: return "PCX924-Mic";
        case PciSubDevice10B59030::SUBDEVICE_13699F02: return "PCX924-Mic";
        case PciSubDevice10B59030::SUBDEVICE_1369A001: return "PCX22v2";
        case PciSubDevice10B59030::SUBDEVICE_1369A701: return "LCM220v2";
        case PciSubDevice10B59030::SUBDEVICE_1369A801: return "LCM200";
        case PciSubDevice10B59030::SUBDEVICE_13973136: return "4xS0-ISDN PCI Adapter";
        case PciSubDevice10B59030::SUBDEVICE_13973137: return "S2M-E1-ISDN PCI Adapter";
        case PciSubDevice10B59030::SUBDEVICE_15180200: return "ThinkIO-C";
        case PciSubDevice10B59030::SUBDEVICE_15ED1002: return "MCCS 8-port Serial Hot Swap";
        case PciSubDevice10B59030::SUBDEVICE_15ED1003: return "MCCS 16-port Serial Hot Swap";
        case PciSubDevice10B59030::SUBDEVICE_E1C50001: return "TE1-PCI";
        case PciSubDevice10B59030::SUBDEVICE_E1C50005: return "TA1-PCI";
        case PciSubDevice10B59030::SUBDEVICE_E1C50006: return "TA1-PCI4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCISUBDEVICE10B59030_H
