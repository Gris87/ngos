// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F68788_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F68788_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13F68788: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438269 = 0x10438269,
    SUBDEVICE_10438275 = 0x10438275,
    SUBDEVICE_104382B7 = 0x104382B7,
    SUBDEVICE_10438314 = 0x10438314,
    SUBDEVICE_10438327 = 0x10438327,
    SUBDEVICE_1043834F = 0x1043834F,
    SUBDEVICE_1043835C = 0x1043835C,
    SUBDEVICE_1043835D = 0x1043835D,
    SUBDEVICE_1043835E = 0x1043835E,
    SUBDEVICE_1043838E = 0x1043838E,
    SUBDEVICE_10438428 = 0x10438428,
    SUBDEVICE_10438467 = 0x10438467,
    SUBDEVICE_10438521 = 0x10438521,
    SUBDEVICE_10438522 = 0x10438522,
    SUBDEVICE_104385F4 = 0x104385F4,
    SUBDEVICE_13F68782 = 0x13F68782,
    SUBDEVICE_13F6FFFF = 0x13F6FFFF,
    SUBDEVICE_14C31710 = 0x14C31710,
    SUBDEVICE_14C31711 = 0x14C31711,
    SUBDEVICE_14C31713 = 0x14C31713,
    SUBDEVICE_1A580910 = 0x1A580910,
    SUBDEVICE_415A5431 = 0x415A5431,
    SUBDEVICE_5431017A = 0x5431017A,
    SUBDEVICE_584D3781 = 0x584D3781,
    SUBDEVICE_72849761 = 0x72849761,
    SUBDEVICE_72849781 = 0x72849781,
    SUBDEVICE_72849783 = 0x72849783,
    SUBDEVICE_72849787 = 0x72849787
};



inline const char8* enumToString(PciSubDevice13F68788 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13F68788::NONE:               return "NONE";
        case PciSubDevice13F68788::SUBDEVICE_10438269: return "SUBDEVICE_10438269";
        case PciSubDevice13F68788::SUBDEVICE_10438275: return "SUBDEVICE_10438275";
        case PciSubDevice13F68788::SUBDEVICE_104382B7: return "SUBDEVICE_104382B7";
        case PciSubDevice13F68788::SUBDEVICE_10438314: return "SUBDEVICE_10438314";
        case PciSubDevice13F68788::SUBDEVICE_10438327: return "SUBDEVICE_10438327";
        case PciSubDevice13F68788::SUBDEVICE_1043834F: return "SUBDEVICE_1043834F";
        case PciSubDevice13F68788::SUBDEVICE_1043835C: return "SUBDEVICE_1043835C";
        case PciSubDevice13F68788::SUBDEVICE_1043835D: return "SUBDEVICE_1043835D";
        case PciSubDevice13F68788::SUBDEVICE_1043835E: return "SUBDEVICE_1043835E";
        case PciSubDevice13F68788::SUBDEVICE_1043838E: return "SUBDEVICE_1043838E";
        case PciSubDevice13F68788::SUBDEVICE_10438428: return "SUBDEVICE_10438428";
        case PciSubDevice13F68788::SUBDEVICE_10438467: return "SUBDEVICE_10438467";
        case PciSubDevice13F68788::SUBDEVICE_10438521: return "SUBDEVICE_10438521";
        case PciSubDevice13F68788::SUBDEVICE_10438522: return "SUBDEVICE_10438522";
        case PciSubDevice13F68788::SUBDEVICE_104385F4: return "SUBDEVICE_104385F4";
        case PciSubDevice13F68788::SUBDEVICE_13F68782: return "SUBDEVICE_13F68782";
        case PciSubDevice13F68788::SUBDEVICE_13F6FFFF: return "SUBDEVICE_13F6FFFF";
        case PciSubDevice13F68788::SUBDEVICE_14C31710: return "SUBDEVICE_14C31710";
        case PciSubDevice13F68788::SUBDEVICE_14C31711: return "SUBDEVICE_14C31711";
        case PciSubDevice13F68788::SUBDEVICE_14C31713: return "SUBDEVICE_14C31713";
        case PciSubDevice13F68788::SUBDEVICE_1A580910: return "SUBDEVICE_1A580910";
        case PciSubDevice13F68788::SUBDEVICE_415A5431: return "SUBDEVICE_415A5431";
        case PciSubDevice13F68788::SUBDEVICE_5431017A: return "SUBDEVICE_5431017A";
        case PciSubDevice13F68788::SUBDEVICE_584D3781: return "SUBDEVICE_584D3781";
        case PciSubDevice13F68788::SUBDEVICE_72849761: return "SUBDEVICE_72849761";
        case PciSubDevice13F68788::SUBDEVICE_72849781: return "SUBDEVICE_72849781";
        case PciSubDevice13F68788::SUBDEVICE_72849783: return "SUBDEVICE_72849783";
        case PciSubDevice13F68788::SUBDEVICE_72849787: return "SUBDEVICE_72849787";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13F68788 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13F68788 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13F68788::SUBDEVICE_10438269: return "Virtuoso 200 (Xonar D2)";
        case PciSubDevice13F68788::SUBDEVICE_10438275: return "Virtuoso 100 (Xonar DX)";
        case PciSubDevice13F68788::SUBDEVICE_104382B7: return "Virtuoso 200 (Xonar D2X)";
        case PciSubDevice13F68788::SUBDEVICE_10438314: return "Virtuoso 200 (Xonar HDAV1.3)";
        case PciSubDevice13F68788::SUBDEVICE_10438327: return "Virtuoso 100 (Xonar DX)";
        case PciSubDevice13F68788::SUBDEVICE_1043834F: return "Virtuoso 100 (Xonar D1)";
        case PciSubDevice13F68788::SUBDEVICE_1043835C: return "Virtuoso 100 (Xonar Essence STX)";
        case PciSubDevice13F68788::SUBDEVICE_1043835D: return "Virtuoso 100 (Xonar ST)";
        case PciSubDevice13F68788::SUBDEVICE_1043835E: return "Virtuoso 200 (Xonar HDAV1.3 Slim)";
        case PciSubDevice13F68788::SUBDEVICE_1043838E: return "Virtuoso 66 (Xonar DS)";
        case PciSubDevice13F68788::SUBDEVICE_10438428: return "Virtuoso 100 (Xonar Xense)";
        case PciSubDevice13F68788::SUBDEVICE_10438467: return "CMi8786 (Xonar DG)";
        case PciSubDevice13F68788::SUBDEVICE_10438521: return "CMi8786 (Xonar DGX)";
        case PciSubDevice13F68788::SUBDEVICE_10438522: return "Xonar DSX";
        case PciSubDevice13F68788::SUBDEVICE_104385F4: return "Virtuoso 100 (Xonar Essence STX II)";
        case PciSubDevice13F68788::SUBDEVICE_13F68782: return "PCI 2.0 HD Audio";
        case PciSubDevice13F68788::SUBDEVICE_13F6FFFF: return "CMi8787-HG2PCI";
        case PciSubDevice13F68788::SUBDEVICE_14C31710: return "HiFier Fantasia";
        case PciSubDevice13F68788::SUBDEVICE_14C31711: return "HiFier Serenade";
        case PciSubDevice13F68788::SUBDEVICE_14C31713: return "HiFier Serenade III";
        case PciSubDevice13F68788::SUBDEVICE_1A580910: return "Barracuda AC-1";
        case PciSubDevice13F68788::SUBDEVICE_415A5431: return "X-Meridian 7.1";
        case PciSubDevice13F68788::SUBDEVICE_5431017A: return "X-Meridian 7.1 2G";
        case PciSubDevice13F68788::SUBDEVICE_584D3781: return "HDA X-Purity 7.1 Platinum";
        case PciSubDevice13F68788::SUBDEVICE_72849761: return "CLARO";
        case PciSubDevice13F68788::SUBDEVICE_72849781: return "CLARO halo";
        case PciSubDevice13F68788::SUBDEVICE_72849783: return "eCLARO";
        case PciSubDevice13F68788::SUBDEVICE_72849787: return "CLARO II";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F68788_H
