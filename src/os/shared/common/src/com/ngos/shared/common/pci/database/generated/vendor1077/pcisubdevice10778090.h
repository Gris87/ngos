// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778090_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778090_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10778090: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10770001 = 0x10770001,
    SUBDEVICE_10770002 = 0x10770002,
    SUBDEVICE_10770003 = 0x10770003,
    SUBDEVICE_10770004 = 0x10770004,
    SUBDEVICE_10770005 = 0x10770005,
    SUBDEVICE_10770006 = 0x10770006,
    SUBDEVICE_10770007 = 0x10770007,
    SUBDEVICE_10770009 = 0x10770009,
    SUBDEVICE_1077000B = 0x1077000B,
    SUBDEVICE_1077000C = 0x1077000C,
    SUBDEVICE_1077000D = 0x1077000D,
    SUBDEVICE_1077000E = 0x1077000E,
    SUBDEVICE_1077000F = 0x1077000F,
    SUBDEVICE_10770010 = 0x10770010,
    SUBDEVICE_10770011 = 0x10770011,
    SUBDEVICE_10770012 = 0x10770012,
    SUBDEVICE_10770053 = 0x10770053,
    SUBDEVICE_10770054 = 0x10770054,
    SUBDEVICE_10770055 = 0x10770055,
    SUBDEVICE_10770056 = 0x10770056,
    SUBDEVICE_10770057 = 0x10770057,
    SUBDEVICE_10770065 = 0x10770065,
    SUBDEVICE_10770066 = 0x10770066,
    SUBDEVICE_1590021A = 0x1590021A,
    SUBDEVICE_1590021B = 0x1590021B,
    SUBDEVICE_1590021E = 0x1590021E,
    SUBDEVICE_1590021F = 0x1590021F,
    SUBDEVICE_159002BD = 0x159002BD
};



inline const char8* enumToString(PciSubDevice10778090 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778090::NONE:               return "NONE";
        case PciSubDevice10778090::SUBDEVICE_10770001: return "SUBDEVICE_10770001";
        case PciSubDevice10778090::SUBDEVICE_10770002: return "SUBDEVICE_10770002";
        case PciSubDevice10778090::SUBDEVICE_10770003: return "SUBDEVICE_10770003";
        case PciSubDevice10778090::SUBDEVICE_10770004: return "SUBDEVICE_10770004";
        case PciSubDevice10778090::SUBDEVICE_10770005: return "SUBDEVICE_10770005";
        case PciSubDevice10778090::SUBDEVICE_10770006: return "SUBDEVICE_10770006";
        case PciSubDevice10778090::SUBDEVICE_10770007: return "SUBDEVICE_10770007";
        case PciSubDevice10778090::SUBDEVICE_10770009: return "SUBDEVICE_10770009";
        case PciSubDevice10778090::SUBDEVICE_1077000B: return "SUBDEVICE_1077000B";
        case PciSubDevice10778090::SUBDEVICE_1077000C: return "SUBDEVICE_1077000C";
        case PciSubDevice10778090::SUBDEVICE_1077000D: return "SUBDEVICE_1077000D";
        case PciSubDevice10778090::SUBDEVICE_1077000E: return "SUBDEVICE_1077000E";
        case PciSubDevice10778090::SUBDEVICE_1077000F: return "SUBDEVICE_1077000F";
        case PciSubDevice10778090::SUBDEVICE_10770010: return "SUBDEVICE_10770010";
        case PciSubDevice10778090::SUBDEVICE_10770011: return "SUBDEVICE_10770011";
        case PciSubDevice10778090::SUBDEVICE_10770012: return "SUBDEVICE_10770012";
        case PciSubDevice10778090::SUBDEVICE_10770053: return "SUBDEVICE_10770053";
        case PciSubDevice10778090::SUBDEVICE_10770054: return "SUBDEVICE_10770054";
        case PciSubDevice10778090::SUBDEVICE_10770055: return "SUBDEVICE_10770055";
        case PciSubDevice10778090::SUBDEVICE_10770056: return "SUBDEVICE_10770056";
        case PciSubDevice10778090::SUBDEVICE_10770057: return "SUBDEVICE_10770057";
        case PciSubDevice10778090::SUBDEVICE_10770065: return "SUBDEVICE_10770065";
        case PciSubDevice10778090::SUBDEVICE_10770066: return "SUBDEVICE_10770066";
        case PciSubDevice10778090::SUBDEVICE_1590021A: return "SUBDEVICE_1590021A";
        case PciSubDevice10778090::SUBDEVICE_1590021B: return "SUBDEVICE_1590021B";
        case PciSubDevice10778090::SUBDEVICE_1590021E: return "SUBDEVICE_1590021E";
        case PciSubDevice10778090::SUBDEVICE_1590021F: return "SUBDEVICE_1590021F";
        case PciSubDevice10778090::SUBDEVICE_159002BD: return "SUBDEVICE_159002BD";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10778090 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10778090 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10778090::SUBDEVICE_10770001: return "25GE 2P QL41262HxCU-DE Adapter";
        case PciSubDevice10778090::SUBDEVICE_10770002: return "10GE 2P QL41112HxCU-DE Adapter";
        case PciSubDevice10778090::SUBDEVICE_10770003: return "4x10GE QL41164HxRJ CNA";
        case PciSubDevice10778090::SUBDEVICE_10770004: return "4x10GE QL41164HFCU CNA";
        case PciSubDevice10778090::SUBDEVICE_10770005: return "QLogic 4x10GE QL41164HMRJ CNA";
        case PciSubDevice10778090::SUBDEVICE_10770006: return "QLogic 4x10GE QL41164HMCU CNA";
        case PciSubDevice10778090::SUBDEVICE_10770007: return "QLogic 2x1GE+2x10GE QL41264HMCU CNA";
        case PciSubDevice10778090::SUBDEVICE_10770009: return "QLogic 2x1GE+2x10GE QL41162HMRJ CNA";
        case PciSubDevice10778090::SUBDEVICE_1077000B: return "25GE 2P QL41262HxCU-DE Adapter";
        case PciSubDevice10778090::SUBDEVICE_1077000C: return "QLogic 2x25GE QL41262HMCU CNA";
        case PciSubDevice10778090::SUBDEVICE_1077000D: return "FastLinQ QL41262H 25GbE FCoE Adapter (SR-IOV VF)";
        case PciSubDevice10778090::SUBDEVICE_1077000E: return "FastLinQ QL41162H 10GbE iSCSI Adapter (SR-IOV VF)";
        case PciSubDevice10778090::SUBDEVICE_1077000F: return "2x25GE QL41262HMKR CNA";
        case PciSubDevice10778090::SUBDEVICE_10770010: return "2x25GE QL41232HMKR NIC";
        case PciSubDevice10778090::SUBDEVICE_10770011: return "FastLinQ QL41212H 25GbE Adapter (SR-IOV VF)";
        case PciSubDevice10778090::SUBDEVICE_10770012: return "FastLinQ QL41112H 10GbE Adapter (SR-IOV VF)";
        case PciSubDevice10778090::SUBDEVICE_10770053: return "QLogic 2x25GE QL41232HQCU NIC";
        case PciSubDevice10778090::SUBDEVICE_10770054: return "QLogic 2x10GE QL41132HQRJ NIC";
        case PciSubDevice10778090::SUBDEVICE_10770055: return "QLogic 2x10GE QL41132HQCU NIC";
        case PciSubDevice10778090::SUBDEVICE_10770056: return "2x10GE QL41132HxRJ NIC";
        case PciSubDevice10778090::SUBDEVICE_10770057: return "2x25GE QL41232HxCU NIC";
        case PciSubDevice10778090::SUBDEVICE_10770065: return "QLogic 4x10GE QL41154HQRJ CNA";
        case PciSubDevice10778090::SUBDEVICE_10770066: return "QLogic 4x10GE QL41154HQCU CNA";
        case PciSubDevice10778090::SUBDEVICE_1590021A: return "10GbE 2P QL41162HLRJ-HP Adapter";
        case PciSubDevice10778090::SUBDEVICE_1590021B: return "10GbE 2P QL41162HLRJ-HP Adapter";
        case PciSubDevice10778090::SUBDEVICE_1590021E: return "10/25GbE 2P QL41162HMRJ-HP Adapter";
        case PciSubDevice10778090::SUBDEVICE_1590021F: return "10/25GbE 2P QL41262HMCU-HP Adapter";
        case PciSubDevice10778090::SUBDEVICE_159002BD: return "10Gb 2P 524SFP+ NIC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1077_PCISUBDEVICE10778090_H
