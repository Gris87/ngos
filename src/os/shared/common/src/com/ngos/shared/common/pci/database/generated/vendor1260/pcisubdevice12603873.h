// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603873_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603873_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12603873: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10CF1169 = 0x10CF1169,
    SUBDEVICE_11863501 = 0x11863501,
    SUBDEVICE_11863700 = 0x11863700,
    SUBDEVICE_13854105 = 0x13854105,
    SUBDEVICE_16680414 = 0x16680414,
    SUBDEVICE_16A51601 = 0x16A51601,
    SUBDEVICE_17373874 = 0x17373874,
    SUBDEVICE_40337033 = 0x40337033,
    SUBDEVICE_80862510 = 0x80862510,
    SUBDEVICE_80862513 = 0x80862513
};



inline const char8* enumToString(PciSubDevice12603873 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12603873::NONE:               return "NONE";
        case PciSubDevice12603873::SUBDEVICE_10CF1169: return "SUBDEVICE_10CF1169";
        case PciSubDevice12603873::SUBDEVICE_11863501: return "SUBDEVICE_11863501";
        case PciSubDevice12603873::SUBDEVICE_11863700: return "SUBDEVICE_11863700";
        case PciSubDevice12603873::SUBDEVICE_13854105: return "SUBDEVICE_13854105";
        case PciSubDevice12603873::SUBDEVICE_16680414: return "SUBDEVICE_16680414";
        case PciSubDevice12603873::SUBDEVICE_16A51601: return "SUBDEVICE_16A51601";
        case PciSubDevice12603873::SUBDEVICE_17373874: return "SUBDEVICE_17373874";
        case PciSubDevice12603873::SUBDEVICE_40337033: return "SUBDEVICE_40337033";
        case PciSubDevice12603873::SUBDEVICE_80862510: return "SUBDEVICE_80862510";
        case PciSubDevice12603873::SUBDEVICE_80862513: return "SUBDEVICE_80862513";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12603873 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12603873 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12603873::SUBDEVICE_10CF1169: return "MBH7WM01-8734 802.11b Wireless Mini PCI Card [ISL3874]";
        case PciSubDevice12603873::SUBDEVICE_11863501: return "DWL-520 Wireless PCI Adapter (rev A or B) [ISL3874]";
        case PciSubDevice12603873::SUBDEVICE_11863700: return "DWL-520 Wireless PCI Adapter (rev E1) [ISL3872]";
        case PciSubDevice12603873::SUBDEVICE_13854105: return "MA311 802.11b wireless adapter [ISL3874]";
        case PciSubDevice12603873::SUBDEVICE_16680414: return "HWP01170-01 802.11b PCI Wireless Adapter";
        case PciSubDevice12603873::SUBDEVICE_16A51601: return "AIR.mate PC-400 PCI Wireless LAN Adapter";
        case PciSubDevice12603873::SUBDEVICE_17373874: return "WMP11 v1 802.11b Wireless-B PCI Adapter [ISL3874]";
        case PciSubDevice12603873::SUBDEVICE_40337033: return "PCW200 802.11b Wireless PCI Adapter [ISL3874]";
        case PciSubDevice12603873::SUBDEVICE_80862510: return "M3AWEB Wireless 802.11b MiniPCI Adapter";
        case PciSubDevice12603873::SUBDEVICE_80862513: return "Wireless 802.11b MiniPCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1260_PCISUBDEVICE12603873_H
