// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0023_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0023_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0023: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0308340B = 0x0308340B,
    SUBDEVICE_11540365 = 0x11540365,
    SUBDEVICE_11540367 = 0x11540367,
    SUBDEVICE_11863A6A = 0x11863A6A,
    SUBDEVICE_11863A6B = 0x11863A6B,
    SUBDEVICE_11863A6D = 0x11863A6D,
    SUBDEVICE_11863A76 = 0x11863A76,
    SUBDEVICE_17370059 = 0x17370059,
    SUBDEVICE_17370069 = 0x17370069,
    SUBDEVICE_17370072 = 0x17370072,
    SUBDEVICE_17998011 = 0x17998011,
    SUBDEVICE_187E3411 = 0x187E3411,
    SUBDEVICE_19762008 = 0x19762008
};



inline const char8* enumToString(PciSubDevice168C0023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0023::NONE:               return "NONE";
        case PciSubDevice168C0023::SUBDEVICE_0308340B: return "SUBDEVICE_0308340B";
        case PciSubDevice168C0023::SUBDEVICE_11540365: return "SUBDEVICE_11540365";
        case PciSubDevice168C0023::SUBDEVICE_11540367: return "SUBDEVICE_11540367";
        case PciSubDevice168C0023::SUBDEVICE_11863A6A: return "SUBDEVICE_11863A6A";
        case PciSubDevice168C0023::SUBDEVICE_11863A6B: return "SUBDEVICE_11863A6B";
        case PciSubDevice168C0023::SUBDEVICE_11863A6D: return "SUBDEVICE_11863A6D";
        case PciSubDevice168C0023::SUBDEVICE_11863A76: return "SUBDEVICE_11863A76";
        case PciSubDevice168C0023::SUBDEVICE_17370059: return "SUBDEVICE_17370059";
        case PciSubDevice168C0023::SUBDEVICE_17370069: return "SUBDEVICE_17370069";
        case PciSubDevice168C0023::SUBDEVICE_17370072: return "SUBDEVICE_17370072";
        case PciSubDevice168C0023::SUBDEVICE_17998011: return "SUBDEVICE_17998011";
        case PciSubDevice168C0023::SUBDEVICE_187E3411: return "SUBDEVICE_187E3411";
        case PciSubDevice168C0023::SUBDEVICE_19762008: return "SUBDEVICE_19762008";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0023::SUBDEVICE_0308340B: return "NWD-170N 802.11bgn Wireless CardBus Adapter";
        case PciSubDevice168C0023::SUBDEVICE_11540365: return "Buffalo WLP-CB-AG300 802.11abgn Cardbus Adapter";
        case PciSubDevice168C0023::SUBDEVICE_11540367: return "WLI-CB-AG301N 802.11abgn Wireless CardBus Adapter";
        case PciSubDevice168C0023::SUBDEVICE_11863A6A: return "DWA-642 802.11n RangeBooster N CardBus Adapter";
        case PciSubDevice168C0023::SUBDEVICE_11863A6B: return "DWA-547 802.11n RangeBooster N 650 DeskTop Adapter";
        case PciSubDevice168C0023::SUBDEVICE_11863A6D: return "DWA-552 802.11n Xtreme N Desktop Adapter (rev A1)";
        case PciSubDevice168C0023::SUBDEVICE_11863A76: return "DWA-645 802.11n RangeBooster N 650 Notebook Adapter (rev A1)";
        case PciSubDevice168C0023::SUBDEVICE_17370059: return "WPC300N v2 Wireless-N Notebook Adapter";
        case PciSubDevice168C0023::SUBDEVICE_17370069: return "WPC100 v1 802.11n RangePlus Wireless Notebook Adapter";
        case PciSubDevice168C0023::SUBDEVICE_17370072: return "WMP110 v1 802.11n RangePlus Wireless PCI Adapter";
        case PciSubDevice168C0023::SUBDEVICE_17998011: return "F5D8011 v1 802.11n N1 Wireless Notebook Card";
        case PciSubDevice168C0023::SUBDEVICE_187E3411: return "NWD-370N 802.11n Wireless PCI Adapter";
        case PciSubDevice168C0023::SUBDEVICE_19762008: return "TEW-621PC 802.11bgn Wireless CardBus Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0023_H
