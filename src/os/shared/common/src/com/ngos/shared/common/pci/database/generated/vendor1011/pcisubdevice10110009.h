// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10110009: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250310 = 0x10250310,
    SUBDEVICE_10B82001 = 0x10B82001,
    SUBDEVICE_10B82002 = 0x10B82002,
    SUBDEVICE_10B82003 = 0x10B82003,
    SUBDEVICE_11092400 = 0x11092400,
    SUBDEVICE_11122300 = 0x11122300,
    SUBDEVICE_11122320 = 0x11122320,
    SUBDEVICE_11122340 = 0x11122340,
    SUBDEVICE_11131207 = 0x11131207,
    SUBDEVICE_11861100 = 0x11861100,
    SUBDEVICE_11861112 = 0x11861112,
    SUBDEVICE_11861140 = 0x11861140,
    SUBDEVICE_11861142 = 0x11861142,
    SUBDEVICE_11F60503 = 0x11F60503,
    SUBDEVICE_12829100 = 0x12829100,
    SUBDEVICE_13851100 = 0x13851100,
    SUBDEVICE_26460001 = 0x26460001
};



inline const char8* enumToString(PciSubDevice10110009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10110009::NONE:               return "NONE";
        case PciSubDevice10110009::SUBDEVICE_10250310: return "SUBDEVICE_10250310";
        case PciSubDevice10110009::SUBDEVICE_10B82001: return "SUBDEVICE_10B82001";
        case PciSubDevice10110009::SUBDEVICE_10B82002: return "SUBDEVICE_10B82002";
        case PciSubDevice10110009::SUBDEVICE_10B82003: return "SUBDEVICE_10B82003";
        case PciSubDevice10110009::SUBDEVICE_11092400: return "SUBDEVICE_11092400";
        case PciSubDevice10110009::SUBDEVICE_11122300: return "SUBDEVICE_11122300";
        case PciSubDevice10110009::SUBDEVICE_11122320: return "SUBDEVICE_11122320";
        case PciSubDevice10110009::SUBDEVICE_11122340: return "SUBDEVICE_11122340";
        case PciSubDevice10110009::SUBDEVICE_11131207: return "SUBDEVICE_11131207";
        case PciSubDevice10110009::SUBDEVICE_11861100: return "SUBDEVICE_11861100";
        case PciSubDevice10110009::SUBDEVICE_11861112: return "SUBDEVICE_11861112";
        case PciSubDevice10110009::SUBDEVICE_11861140: return "SUBDEVICE_11861140";
        case PciSubDevice10110009::SUBDEVICE_11861142: return "SUBDEVICE_11861142";
        case PciSubDevice10110009::SUBDEVICE_11F60503: return "SUBDEVICE_11F60503";
        case PciSubDevice10110009::SUBDEVICE_12829100: return "SUBDEVICE_12829100";
        case PciSubDevice10110009::SUBDEVICE_13851100: return "SUBDEVICE_13851100";
        case PciSubDevice10110009::SUBDEVICE_26460001: return "SUBDEVICE_26460001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10110009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10110009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10110009::SUBDEVICE_10250310: return "21140 Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_10B82001: return "SMC9332BDT EtherPower 10/100";
        case PciSubDevice10110009::SUBDEVICE_10B82002: return "SMC9332BVT EtherPower T4 10/100";
        case PciSubDevice10110009::SUBDEVICE_10B82003: return "SMC9334BDT EtherPower 10/100 (1-port)";
        case PciSubDevice10110009::SUBDEVICE_11092400: return "ANA-6944A/TX Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_11122300: return "RNS2300 Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_11122320: return "RNS2320 Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_11122340: return "RNS2340 Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_11131207: return "EN-1207-TX Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_11861100: return "DFE-500TX Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_11861112: return "DFE-570TX Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_11861140: return "DFE-660 Cardbus Ethernet 10/100";
        case PciSubDevice10110009::SUBDEVICE_11861142: return "DFE-660 Cardbus Ethernet 10/100";
        case PciSubDevice10110009::SUBDEVICE_11F60503: return "Freedomline Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_12829100: return "AEF-380TXD Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_13851100: return "FA310TX Fast Ethernet";
        case PciSubDevice10110009::SUBDEVICE_26460001: return "KNE100TX Fast Ethernet";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110009_H
