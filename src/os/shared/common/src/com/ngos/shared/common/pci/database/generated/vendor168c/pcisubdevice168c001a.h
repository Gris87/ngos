// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C001A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1052168C = 0x1052168C,
    SUBDEVICE_1113EE20 = 0x1113EE20,
    SUBDEVICE_1113EE24 = 0x1113EE24,
    SUBDEVICE_11863A15 = 0x11863A15,
    SUBDEVICE_11863A16 = 0x11863A16,
    SUBDEVICE_11863A1C = 0x11863A1C,
    SUBDEVICE_11863A1D = 0x11863A1D,
    SUBDEVICE_11863A23 = 0x11863A23,
    SUBDEVICE_11863A24 = 0x11863A24,
    SUBDEVICE_11863B08 = 0x11863B08,
    SUBDEVICE_168C001A = 0x168C001A,
    SUBDEVICE_168C1052 = 0x168C1052,
    SUBDEVICE_168C2052 = 0x168C2052,
    SUBDEVICE_16EC0122 = 0x16EC0122,
    SUBDEVICE_17370053 = 0x17370053,
    SUBDEVICE_1799700C = 0x1799700C,
    SUBDEVICE_1799701D = 0x1799701D,
    SUBDEVICE_17F90008 = 0x17F90008,
    SUBDEVICE_17F90018 = 0x17F90018
};



inline const char8* enumToString(PciSubDevice168C001A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C001A::NONE:               return "NONE";
        case PciSubDevice168C001A::SUBDEVICE_1052168C: return "SUBDEVICE_1052168C";
        case PciSubDevice168C001A::SUBDEVICE_1113EE20: return "SUBDEVICE_1113EE20";
        case PciSubDevice168C001A::SUBDEVICE_1113EE24: return "SUBDEVICE_1113EE24";
        case PciSubDevice168C001A::SUBDEVICE_11863A15: return "SUBDEVICE_11863A15";
        case PciSubDevice168C001A::SUBDEVICE_11863A16: return "SUBDEVICE_11863A16";
        case PciSubDevice168C001A::SUBDEVICE_11863A1C: return "SUBDEVICE_11863A1C";
        case PciSubDevice168C001A::SUBDEVICE_11863A1D: return "SUBDEVICE_11863A1D";
        case PciSubDevice168C001A::SUBDEVICE_11863A23: return "SUBDEVICE_11863A23";
        case PciSubDevice168C001A::SUBDEVICE_11863A24: return "SUBDEVICE_11863A24";
        case PciSubDevice168C001A::SUBDEVICE_11863B08: return "SUBDEVICE_11863B08";
        case PciSubDevice168C001A::SUBDEVICE_168C001A: return "SUBDEVICE_168C001A";
        case PciSubDevice168C001A::SUBDEVICE_168C1052: return "SUBDEVICE_168C1052";
        case PciSubDevice168C001A::SUBDEVICE_168C2052: return "SUBDEVICE_168C2052";
        case PciSubDevice168C001A::SUBDEVICE_16EC0122: return "SUBDEVICE_16EC0122";
        case PciSubDevice168C001A::SUBDEVICE_17370053: return "SUBDEVICE_17370053";
        case PciSubDevice168C001A::SUBDEVICE_1799700C: return "SUBDEVICE_1799700C";
        case PciSubDevice168C001A::SUBDEVICE_1799701D: return "SUBDEVICE_1799701D";
        case PciSubDevice168C001A::SUBDEVICE_17F90008: return "SUBDEVICE_17F90008";
        case PciSubDevice168C001A::SUBDEVICE_17F90018: return "SUBDEVICE_17F90018";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C001A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C001A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C001A::SUBDEVICE_1052168C: return "Sweex Wireless Lan PC Card 54Mbps";
        case PciSubDevice168C001A::SUBDEVICE_1113EE20: return "SMC Wireless CardBus Adapter 802.11g (SMCWCB-G EU)";
        case PciSubDevice168C001A::SUBDEVICE_1113EE24: return "SMC Wireless PCI Card WPCI-G";
        case PciSubDevice168C001A::SUBDEVICE_11863A15: return "AirPlus G DWL-G630 Wireless Cardbus Adapter (rev.D1)";
        case PciSubDevice168C001A::SUBDEVICE_11863A16: return "AirPlus G DWL-G510 Wireless PCI Adapter(rev.B)";
        case PciSubDevice168C001A::SUBDEVICE_11863A1C: return "WNA-1330 Notebook Adapter";
        case PciSubDevice168C001A::SUBDEVICE_11863A1D: return "WDA-1320 Desktop Adapter";
        case PciSubDevice168C001A::SUBDEVICE_11863A23: return "AirPlus G DWL-G520+A Wireless PCI Adapter";
        case PciSubDevice168C001A::SUBDEVICE_11863A24: return "AirPlus G DWL-G650+A Wireless Cardbus Adapter";
        case PciSubDevice168C001A::SUBDEVICE_11863B08: return "AirPlus G DWL-G630 Wireless Cardbus Adapter (rev.C1)";
        case PciSubDevice168C001A::SUBDEVICE_168C001A: return "Belkin FD7000";
        case PciSubDevice168C001A::SUBDEVICE_168C1052: return "TP-Link TL-WN510G Wireless CardBus Adapter";
        case PciSubDevice168C001A::SUBDEVICE_168C2052: return "Compex Wireless 802.11 b/g MiniPCI Adapter, Rev A1 [WLM54G]";
        case PciSubDevice168C001A::SUBDEVICE_16EC0122: return "Wireless PCI Adapter Model 5418";
        case PciSubDevice168C001A::SUBDEVICE_17370053: return "WPC54G v7 802.11g Wireless-G Notebook Adapter";
        case PciSubDevice168C001A::SUBDEVICE_1799700C: return "F5D7000 v5000 Wireless G Desktop Card";
        case PciSubDevice168C001A::SUBDEVICE_1799701D: return "F5D7010 v5000 Wireless G Notebook Card";
        case PciSubDevice168C001A::SUBDEVICE_17F90008: return "DX-WGNBC 802.11bg Wireless CardBus Adapter";
        case PciSubDevice168C001A::SUBDEVICE_17F90018: return "DX-WGDTC 802.11bg Wireless PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C001A_H
