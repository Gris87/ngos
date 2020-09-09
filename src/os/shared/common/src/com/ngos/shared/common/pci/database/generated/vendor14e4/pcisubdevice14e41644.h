// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41644_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41644_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E41644: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140277 = 0x10140277,
    SUBDEVICE_102800D1 = 0x102800D1,
    SUBDEVICE_10280106 = 0x10280106,
    SUBDEVICE_10280109 = 0x10280109,
    SUBDEVICE_1028010A = 0x1028010A,
    SUBDEVICE_10B71000 = 0x10B71000,
    SUBDEVICE_10B71001 = 0x10B71001,
    SUBDEVICE_10B71002 = 0x10B71002,
    SUBDEVICE_10B71003 = 0x10B71003,
    SUBDEVICE_10B71004 = 0x10B71004,
    SUBDEVICE_10B71005 = 0x10B71005,
    SUBDEVICE_10B71008 = 0x10B71008,
    SUBDEVICE_14E40002 = 0x14E40002,
    SUBDEVICE_14E40003 = 0x14E40003,
    SUBDEVICE_14E40004 = 0x14E40004,
    SUBDEVICE_14E41028 = 0x14E41028,
    SUBDEVICE_14E41644 = 0x14E41644
};



inline const char8* enumToString(PciSubDevice14E41644 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41644::NONE:               return "NONE";
        case PciSubDevice14E41644::SUBDEVICE_10140277: return "SUBDEVICE_10140277";
        case PciSubDevice14E41644::SUBDEVICE_102800D1: return "SUBDEVICE_102800D1";
        case PciSubDevice14E41644::SUBDEVICE_10280106: return "SUBDEVICE_10280106";
        case PciSubDevice14E41644::SUBDEVICE_10280109: return "SUBDEVICE_10280109";
        case PciSubDevice14E41644::SUBDEVICE_1028010A: return "SUBDEVICE_1028010A";
        case PciSubDevice14E41644::SUBDEVICE_10B71000: return "SUBDEVICE_10B71000";
        case PciSubDevice14E41644::SUBDEVICE_10B71001: return "SUBDEVICE_10B71001";
        case PciSubDevice14E41644::SUBDEVICE_10B71002: return "SUBDEVICE_10B71002";
        case PciSubDevice14E41644::SUBDEVICE_10B71003: return "SUBDEVICE_10B71003";
        case PciSubDevice14E41644::SUBDEVICE_10B71004: return "SUBDEVICE_10B71004";
        case PciSubDevice14E41644::SUBDEVICE_10B71005: return "SUBDEVICE_10B71005";
        case PciSubDevice14E41644::SUBDEVICE_10B71008: return "SUBDEVICE_10B71008";
        case PciSubDevice14E41644::SUBDEVICE_14E40002: return "SUBDEVICE_14E40002";
        case PciSubDevice14E41644::SUBDEVICE_14E40003: return "SUBDEVICE_14E40003";
        case PciSubDevice14E41644::SUBDEVICE_14E40004: return "SUBDEVICE_14E40004";
        case PciSubDevice14E41644::SUBDEVICE_14E41028: return "SUBDEVICE_14E41028";
        case PciSubDevice14E41644::SUBDEVICE_14E41644: return "SUBDEVICE_14E41644";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E41644 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E41644 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E41644::SUBDEVICE_10140277: return "Broadcom Vigil B5700 1000Base-T";
        case PciSubDevice14E41644::SUBDEVICE_102800D1: return "Broadcom BCM5700";
        case PciSubDevice14E41644::SUBDEVICE_10280106: return "Broadcom BCM5700";
        case PciSubDevice14E41644::SUBDEVICE_10280109: return "Broadcom BCM5700 1000Base-T";
        case PciSubDevice14E41644::SUBDEVICE_1028010A: return "Broadcom BCM5700 1000BaseTX";
        case PciSubDevice14E41644::SUBDEVICE_10B71000: return "3C996-T 1000Base-T";
        case PciSubDevice14E41644::SUBDEVICE_10B71001: return "3C996B-T 1000Base-T";
        case PciSubDevice14E41644::SUBDEVICE_10B71002: return "3C996C-T 1000Base-T";
        case PciSubDevice14E41644::SUBDEVICE_10B71003: return "3C997-T 1000Base-T Dual Port";
        case PciSubDevice14E41644::SUBDEVICE_10B71004: return "3C996-SX 1000Base-SX";
        case PciSubDevice14E41644::SUBDEVICE_10B71005: return "3C997-SX 1000Base-SX Dual Port";
        case PciSubDevice14E41644::SUBDEVICE_10B71008: return "3C942 Gigabit LOM (31X31)";
        case PciSubDevice14E41644::SUBDEVICE_14E40002: return "NetXtreme 1000Base-SX";
        case PciSubDevice14E41644::SUBDEVICE_14E40003: return "NetXtreme 1000Base-SX";
        case PciSubDevice14E41644::SUBDEVICE_14E40004: return "NetXtreme 1000Base-T";
        case PciSubDevice14E41644::SUBDEVICE_14E41028: return "NetXtreme 1000BaseTX";
        case PciSubDevice14E41644::SUBDEVICE_14E41644: return "BCM5700 1000Base-T";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E41644_H
