// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60111_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60111_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13F60111: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10190970 = 0x10190970,
    SUBDEVICE_10438035 = 0x10438035,
    SUBDEVICE_10438077 = 0x10438077,
    SUBDEVICE_104380E2 = 0x104380E2,
    SUBDEVICE_13F60111 = 0x13F60111,
    SUBDEVICE_13F69761 = 0x13F69761,
    SUBDEVICE_153B1144 = 0x153B1144,
    SUBDEVICE_153B1170 = 0x153B1170,
    SUBDEVICE_1681A000 = 0x1681A000,
    SUBDEVICE_17AB0604 = 0x17AB0604,
    SUBDEVICE_17AB0605 = 0x17AB0605,
    SUBDEVICE_17AB7777 = 0x17AB7777,
    SUBDEVICE_270F1103 = 0x270F1103,
    SUBDEVICE_270FF462 = 0x270FF462,
    SUBDEVICE_584D3731 = 0x584D3731,
    SUBDEVICE_584D3741 = 0x584D3741,
    SUBDEVICE_584D3751 = 0x584D3751,
    SUBDEVICE_584D3761 = 0x584D3761,
    SUBDEVICE_584D3771 = 0x584D3771,
    SUBDEVICE_72848384 = 0x72848384
};



inline const char8* enumToString(PciSubDevice13F60111 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13F60111::NONE:               return "NONE";
        case PciSubDevice13F60111::SUBDEVICE_10190970: return "SUBDEVICE_10190970";
        case PciSubDevice13F60111::SUBDEVICE_10438035: return "SUBDEVICE_10438035";
        case PciSubDevice13F60111::SUBDEVICE_10438077: return "SUBDEVICE_10438077";
        case PciSubDevice13F60111::SUBDEVICE_104380E2: return "SUBDEVICE_104380E2";
        case PciSubDevice13F60111::SUBDEVICE_13F60111: return "SUBDEVICE_13F60111";
        case PciSubDevice13F60111::SUBDEVICE_13F69761: return "SUBDEVICE_13F69761";
        case PciSubDevice13F60111::SUBDEVICE_153B1144: return "SUBDEVICE_153B1144";
        case PciSubDevice13F60111::SUBDEVICE_153B1170: return "SUBDEVICE_153B1170";
        case PciSubDevice13F60111::SUBDEVICE_1681A000: return "SUBDEVICE_1681A000";
        case PciSubDevice13F60111::SUBDEVICE_17AB0604: return "SUBDEVICE_17AB0604";
        case PciSubDevice13F60111::SUBDEVICE_17AB0605: return "SUBDEVICE_17AB0605";
        case PciSubDevice13F60111::SUBDEVICE_17AB7777: return "SUBDEVICE_17AB7777";
        case PciSubDevice13F60111::SUBDEVICE_270F1103: return "SUBDEVICE_270F1103";
        case PciSubDevice13F60111::SUBDEVICE_270FF462: return "SUBDEVICE_270FF462";
        case PciSubDevice13F60111::SUBDEVICE_584D3731: return "SUBDEVICE_584D3731";
        case PciSubDevice13F60111::SUBDEVICE_584D3741: return "SUBDEVICE_584D3741";
        case PciSubDevice13F60111::SUBDEVICE_584D3751: return "SUBDEVICE_584D3751";
        case PciSubDevice13F60111::SUBDEVICE_584D3761: return "SUBDEVICE_584D3761";
        case PciSubDevice13F60111::SUBDEVICE_584D3771: return "SUBDEVICE_584D3771";
        case PciSubDevice13F60111::SUBDEVICE_72848384: return "SUBDEVICE_72848384";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13F60111 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13F60111 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13F60111::SUBDEVICE_10190970: return "P6STP-FL motherboard";
        case PciSubDevice13F60111::SUBDEVICE_10438035: return "CUSI-FX motherboard";
        case PciSubDevice13F60111::SUBDEVICE_10438077: return "CMbad_int8738 6-channel audio controller";
        case PciSubDevice13F60111::SUBDEVICE_104380E2: return "CMbad_int8738 6ch-MX";
        case PciSubDevice13F60111::SUBDEVICE_13F60111: return "CMbad_int8738/C3DX PCI Audio Device";
        case PciSubDevice13F60111::SUBDEVICE_13F69761: return "Theatron Agrippa";
        case PciSubDevice13F60111::SUBDEVICE_153B1144: return "Aureon 5.1";
        case PciSubDevice13F60111::SUBDEVICE_153B1170: return "Aureon 7.1";
        case PciSubDevice13F60111::SUBDEVICE_1681A000: return "Gamesurround MUSE XL";
        case PciSubDevice13F60111::SUBDEVICE_17AB0604: return "PSC604 Dynamic Edge";
        case PciSubDevice13F60111::SUBDEVICE_17AB0605: return "PSC605 Sonic Edge";
        case PciSubDevice13F60111::SUBDEVICE_17AB7777: return "PSC605 Sonic Edge";
        case PciSubDevice13F60111::SUBDEVICE_270F1103: return "CT-7NJS Ultra motherboard";
        case PciSubDevice13F60111::SUBDEVICE_270FF462: return "7NJL1 motherboard";
        case PciSubDevice13F60111::SUBDEVICE_584D3731: return "Digital X-Mystique";
        case PciSubDevice13F60111::SUBDEVICE_584D3741: return "X-Plosion 7.1";
        case PciSubDevice13F60111::SUBDEVICE_584D3751: return "X-Raider 7.1";
        case PciSubDevice13F60111::SUBDEVICE_584D3761: return "X-Mystique 7.1 LP";
        case PciSubDevice13F60111::SUBDEVICE_584D3771: return "X-Mystique 7.1 LP Value";
        case PciSubDevice13F60111::SUBDEVICE_72848384: return "Striker 7.1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR13F6_PCISUBDEVICE13F60111_H
