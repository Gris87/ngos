// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110019_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110019_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10110019: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1011500A = 0x1011500A,
    SUBDEVICE_1011500B = 0x1011500B,
    SUBDEVICE_10140001 = 0x10140001,
    SUBDEVICE_10250315 = 0x10250315,
    SUBDEVICE_1033800C = 0x1033800C,
    SUBDEVICE_1033800D = 0x1033800D,
    SUBDEVICE_103C125A = 0x103C125A,
    SUBDEVICE_108D0016 = 0x108D0016,
    SUBDEVICE_108D0017 = 0x108D0017,
    SUBDEVICE_10B82005 = 0x10B82005,
    SUBDEVICE_10B88034 = 0x10B88034,
    SUBDEVICE_10EF8169 = 0x10EF8169,
    SUBDEVICE_11092A00 = 0x11092A00,
    SUBDEVICE_11092B00 = 0x11092B00,
    SUBDEVICE_11093000 = 0x11093000,
    SUBDEVICE_11131207 = 0x11131207,
    SUBDEVICE_11132220 = 0x11132220,
    SUBDEVICE_115D0002 = 0x115D0002,
    SUBDEVICE_11790203 = 0x11790203,
    SUBDEVICE_11790204 = 0x11790204,
    SUBDEVICE_11861100 = 0x11861100,
    SUBDEVICE_11861101 = 0x11861101,
    SUBDEVICE_11861102 = 0x11861102,
    SUBDEVICE_11861112 = 0x11861112,
    SUBDEVICE_11F04235 = 0x11F04235,
    SUBDEVICE_12592800 = 0x12592800,
    SUBDEVICE_12660004 = 0x12660004,
    SUBDEVICE_12AF0019 = 0x12AF0019,
    SUBDEVICE_13740001 = 0x13740001,
    SUBDEVICE_13740002 = 0x13740002,
    SUBDEVICE_13740007 = 0x13740007,
    SUBDEVICE_13740008 = 0x13740008,
    SUBDEVICE_13852100 = 0x13852100,
    SUBDEVICE_13950001 = 0x13950001,
    SUBDEVICE_13D1AB01 = 0x13D1AB01,
    SUBDEVICE_1498000A = 0x1498000A,
    SUBDEVICE_1498000B = 0x1498000B,
    SUBDEVICE_1498000C = 0x1498000C,
    SUBDEVICE_14CB0100 = 0x14CB0100,
    SUBDEVICE_16682000 = 0x16682000,
    SUBDEVICE_26460001 = 0x26460001,
    SUBDEVICE_26460002 = 0x26460002,
    SUBDEVICE_80860001 = 0x80860001
};



inline const char8* enumToString(PciSubDevice10110019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10110019::NONE:               return "NONE";
        case PciSubDevice10110019::SUBDEVICE_1011500A: return "SUBDEVICE_1011500A";
        case PciSubDevice10110019::SUBDEVICE_1011500B: return "SUBDEVICE_1011500B";
        case PciSubDevice10110019::SUBDEVICE_10140001: return "SUBDEVICE_10140001";
        case PciSubDevice10110019::SUBDEVICE_10250315: return "SUBDEVICE_10250315";
        case PciSubDevice10110019::SUBDEVICE_1033800C: return "SUBDEVICE_1033800C";
        case PciSubDevice10110019::SUBDEVICE_1033800D: return "SUBDEVICE_1033800D";
        case PciSubDevice10110019::SUBDEVICE_103C125A: return "SUBDEVICE_103C125A";
        case PciSubDevice10110019::SUBDEVICE_108D0016: return "SUBDEVICE_108D0016";
        case PciSubDevice10110019::SUBDEVICE_108D0017: return "SUBDEVICE_108D0017";
        case PciSubDevice10110019::SUBDEVICE_10B82005: return "SUBDEVICE_10B82005";
        case PciSubDevice10110019::SUBDEVICE_10B88034: return "SUBDEVICE_10B88034";
        case PciSubDevice10110019::SUBDEVICE_10EF8169: return "SUBDEVICE_10EF8169";
        case PciSubDevice10110019::SUBDEVICE_11092A00: return "SUBDEVICE_11092A00";
        case PciSubDevice10110019::SUBDEVICE_11092B00: return "SUBDEVICE_11092B00";
        case PciSubDevice10110019::SUBDEVICE_11093000: return "SUBDEVICE_11093000";
        case PciSubDevice10110019::SUBDEVICE_11131207: return "SUBDEVICE_11131207";
        case PciSubDevice10110019::SUBDEVICE_11132220: return "SUBDEVICE_11132220";
        case PciSubDevice10110019::SUBDEVICE_115D0002: return "SUBDEVICE_115D0002";
        case PciSubDevice10110019::SUBDEVICE_11790203: return "SUBDEVICE_11790203";
        case PciSubDevice10110019::SUBDEVICE_11790204: return "SUBDEVICE_11790204";
        case PciSubDevice10110019::SUBDEVICE_11861100: return "SUBDEVICE_11861100";
        case PciSubDevice10110019::SUBDEVICE_11861101: return "SUBDEVICE_11861101";
        case PciSubDevice10110019::SUBDEVICE_11861102: return "SUBDEVICE_11861102";
        case PciSubDevice10110019::SUBDEVICE_11861112: return "SUBDEVICE_11861112";
        case PciSubDevice10110019::SUBDEVICE_11F04235: return "SUBDEVICE_11F04235";
        case PciSubDevice10110019::SUBDEVICE_12592800: return "SUBDEVICE_12592800";
        case PciSubDevice10110019::SUBDEVICE_12660004: return "SUBDEVICE_12660004";
        case PciSubDevice10110019::SUBDEVICE_12AF0019: return "SUBDEVICE_12AF0019";
        case PciSubDevice10110019::SUBDEVICE_13740001: return "SUBDEVICE_13740001";
        case PciSubDevice10110019::SUBDEVICE_13740002: return "SUBDEVICE_13740002";
        case PciSubDevice10110019::SUBDEVICE_13740007: return "SUBDEVICE_13740007";
        case PciSubDevice10110019::SUBDEVICE_13740008: return "SUBDEVICE_13740008";
        case PciSubDevice10110019::SUBDEVICE_13852100: return "SUBDEVICE_13852100";
        case PciSubDevice10110019::SUBDEVICE_13950001: return "SUBDEVICE_13950001";
        case PciSubDevice10110019::SUBDEVICE_13D1AB01: return "SUBDEVICE_13D1AB01";
        case PciSubDevice10110019::SUBDEVICE_1498000A: return "SUBDEVICE_1498000A";
        case PciSubDevice10110019::SUBDEVICE_1498000B: return "SUBDEVICE_1498000B";
        case PciSubDevice10110019::SUBDEVICE_1498000C: return "SUBDEVICE_1498000C";
        case PciSubDevice10110019::SUBDEVICE_14CB0100: return "SUBDEVICE_14CB0100";
        case PciSubDevice10110019::SUBDEVICE_16682000: return "SUBDEVICE_16682000";
        case PciSubDevice10110019::SUBDEVICE_26460001: return "SUBDEVICE_26460001";
        case PciSubDevice10110019::SUBDEVICE_26460002: return "SUBDEVICE_26460002";
        case PciSubDevice10110019::SUBDEVICE_80860001: return "SUBDEVICE_80860001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10110019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10110019 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10110019::SUBDEVICE_1011500A: return "DE500A Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_1011500B: return "DE500B Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_10140001: return "10/100 EtherJet Cardbus";
        case PciSubDevice10110019::SUBDEVICE_10250315: return "ALN315 Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_1033800C: return "PC-9821-CS01 100BASE-TX Interface Card";
        case PciSubDevice10110019::SUBDEVICE_1033800D: return "PC-9821NR-B06 100BASE-TX Interface Card";
        case PciSubDevice10110019::SUBDEVICE_103C125A: return "10/100Base-TX (PCI) [A5506B]";
        case PciSubDevice10110019::SUBDEVICE_108D0016: return "Rapidfire 2327 10/100 Ethernet";
        case PciSubDevice10110019::SUBDEVICE_108D0017: return "GoCard 2250 Ethernet 10/100 Cardbus";
        case PciSubDevice10110019::SUBDEVICE_10B82005: return "SMC8032DT Extreme Ethernet 10/100";
        case PciSubDevice10110019::SUBDEVICE_10B88034: return "SMC8034 Extreme Ethernet 10/100";
        case PciSubDevice10110019::SUBDEVICE_10EF8169: return "Cardbus Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11092A00: return "ANA-6911A/TX Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11092B00: return "ANA-6911A/TXC Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11093000: return "ANA-6922/TX Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11131207: return "Cheetah Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11132220: return "Cardbus Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_115D0002: return "Cardbus Ethernet 10/100";
        case PciSubDevice10110019::SUBDEVICE_11790203: return "Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11790204: return "Cardbus Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11861100: return "DFE-500TX Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11861101: return "DFE-500TX Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11861102: return "DFE-500TX Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11861112: return "DFE-570TX Quad Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_11F04235: return "21143 [FASTLine-II UTP 10/100]";
        case PciSubDevice10110019::SUBDEVICE_12592800: return "AT-2800Tx Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_12660004: return "Eagle Fast EtherMAX";
        case PciSubDevice10110019::SUBDEVICE_12AF0019: return "NetFlyer Cardbus Fast Ethernet";
        case PciSubDevice10110019::SUBDEVICE_13740001: return "Cardbus Ethernet Card 10/100";
        case PciSubDevice10110019::SUBDEVICE_13740002: return "Cardbus Ethernet Card 10/100";
        case PciSubDevice10110019::SUBDEVICE_13740007: return "Cardbus Ethernet Card 10/100";
        case PciSubDevice10110019::SUBDEVICE_13740008: return "Cardbus Ethernet Card 10/100";
        case PciSubDevice10110019::SUBDEVICE_13852100: return "FA510";
        case PciSubDevice10110019::SUBDEVICE_13950001: return "10/100 Ethernet CardBus PC Card";
        case PciSubDevice10110019::SUBDEVICE_13D1AB01: return "EtherFast 10/100 Cardbus (PCMPC200)";
        case PciSubDevice10110019::SUBDEVICE_1498000A: return "TPMC880-10 10/100Base-T and 10Base2 PMC Ethernet Adapter";
        case PciSubDevice10110019::SUBDEVICE_1498000B: return "TPMC880-11 Single 10/100Base-T PMC Ethernet Adapter";
        case PciSubDevice10110019::SUBDEVICE_1498000C: return "TPMC880-12 Single 10Base2 PMC Ethernet Adapter";
        case PciSubDevice10110019::SUBDEVICE_14CB0100: return "LNDL-100N 100Base-TX Ethernet PC Card";
        case PciSubDevice10110019::SUBDEVICE_16682000: return "FastNet Pro (PE2000)";
        case PciSubDevice10110019::SUBDEVICE_26460001: return "KNE100TX";
        case PciSubDevice10110019::SUBDEVICE_26460002: return "KNE-CB4TX";
        case PciSubDevice10110019::SUBDEVICE_80860001: return "EtherExpress PRO/100 Mobile CardBus 32";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1011_PCISUBDEVICE10110019_H
