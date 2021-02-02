// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10222000_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10222000_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10222000: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10142000 = 0x10142000,
    SUBDEVICE_10222000 = 0x10222000,
    SUBDEVICE_103C104C = 0x103C104C,
    SUBDEVICE_103C1064 = 0x103C1064,
    SUBDEVICE_103C1065 = 0x103C1065,
    SUBDEVICE_103C106C = 0x103C106C,
    SUBDEVICE_103C106E = 0x103C106E,
    SUBDEVICE_103C10EA = 0x103C10EA,
    SUBDEVICE_11131220 = 0x11131220,
    SUBDEVICE_12592450 = 0x12592450,
    SUBDEVICE_12592454 = 0x12592454,
    SUBDEVICE_12592700 = 0x12592700,
    SUBDEVICE_12592701 = 0x12592701,
    SUBDEVICE_12592702 = 0x12592702,
    SUBDEVICE_12592703 = 0x12592703,
    SUBDEVICE_12592704 = 0x12592704,
    SUBDEVICE_4C531000 = 0x4C531000,
    SUBDEVICE_4C531010 = 0x4C531010,
    SUBDEVICE_4C531020 = 0x4C531020,
    SUBDEVICE_4C531030 = 0x4C531030,
    SUBDEVICE_4C531040 = 0x4C531040,
    SUBDEVICE_4C531060 = 0x4C531060
};



inline const char8* enumToString(PciSubDevice10222000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10222000::NONE:               return "NONE";
        case PciSubDevice10222000::SUBDEVICE_10142000: return "SUBDEVICE_10142000";
        case PciSubDevice10222000::SUBDEVICE_10222000: return "SUBDEVICE_10222000";
        case PciSubDevice10222000::SUBDEVICE_103C104C: return "SUBDEVICE_103C104C";
        case PciSubDevice10222000::SUBDEVICE_103C1064: return "SUBDEVICE_103C1064";
        case PciSubDevice10222000::SUBDEVICE_103C1065: return "SUBDEVICE_103C1065";
        case PciSubDevice10222000::SUBDEVICE_103C106C: return "SUBDEVICE_103C106C";
        case PciSubDevice10222000::SUBDEVICE_103C106E: return "SUBDEVICE_103C106E";
        case PciSubDevice10222000::SUBDEVICE_103C10EA: return "SUBDEVICE_103C10EA";
        case PciSubDevice10222000::SUBDEVICE_11131220: return "SUBDEVICE_11131220";
        case PciSubDevice10222000::SUBDEVICE_12592450: return "SUBDEVICE_12592450";
        case PciSubDevice10222000::SUBDEVICE_12592454: return "SUBDEVICE_12592454";
        case PciSubDevice10222000::SUBDEVICE_12592700: return "SUBDEVICE_12592700";
        case PciSubDevice10222000::SUBDEVICE_12592701: return "SUBDEVICE_12592701";
        case PciSubDevice10222000::SUBDEVICE_12592702: return "SUBDEVICE_12592702";
        case PciSubDevice10222000::SUBDEVICE_12592703: return "SUBDEVICE_12592703";
        case PciSubDevice10222000::SUBDEVICE_12592704: return "SUBDEVICE_12592704";
        case PciSubDevice10222000::SUBDEVICE_4C531000: return "SUBDEVICE_4C531000";
        case PciSubDevice10222000::SUBDEVICE_4C531010: return "SUBDEVICE_4C531010";
        case PciSubDevice10222000::SUBDEVICE_4C531020: return "SUBDEVICE_4C531020";
        case PciSubDevice10222000::SUBDEVICE_4C531030: return "SUBDEVICE_4C531030";
        case PciSubDevice10222000::SUBDEVICE_4C531040: return "SUBDEVICE_4C531040";
        case PciSubDevice10222000::SUBDEVICE_4C531060: return "SUBDEVICE_4C531060";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10222000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10222000 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10222000::SUBDEVICE_10142000: return "NetFinity 10/100 Fast Ethernet";
        case PciSubDevice10222000::SUBDEVICE_10222000: return "PCnet - Fast 79C971";
        case PciSubDevice10222000::SUBDEVICE_103C104C: return "Ethernet with LAN remote power Adapter";
        case PciSubDevice10222000::SUBDEVICE_103C1064: return "Ethernet with LAN remote power Adapter";
        case PciSubDevice10222000::SUBDEVICE_103C1065: return "Ethernet with LAN remote power Adapter";
        case PciSubDevice10222000::SUBDEVICE_103C106C: return "Ethernet with LAN remote power Adapter";
        case PciSubDevice10222000::SUBDEVICE_103C106E: return "Ethernet with LAN remote power Adapter";
        case PciSubDevice10222000::SUBDEVICE_103C10EA: return "Ethernet with LAN remote power Adapter";
        case PciSubDevice10222000::SUBDEVICE_11131220: return "EN1220 10/100 Fast Ethernet";
        case PciSubDevice10222000::SUBDEVICE_12592450: return "AT-2450 10/100 Fast Ethernet";
        case PciSubDevice10222000::SUBDEVICE_12592454: return "AT-2450v4 10Mb Ethernet Adapter";
        case PciSubDevice10222000::SUBDEVICE_12592700: return "AT-2700TX 10/100 Fast Ethernet";
        case PciSubDevice10222000::SUBDEVICE_12592701: return "AT-2700FX 100Mb Ethernet";
        case PciSubDevice10222000::SUBDEVICE_12592702: return "AT-2700FTX 10/100 Mb Fiber/Copper Fast Ethernet";
        case PciSubDevice10222000::SUBDEVICE_12592703: return "AT-2701FX";
        case PciSubDevice10222000::SUBDEVICE_12592704: return "AT-2701FTX 10/100 Mb Fiber/Copper Fast Ethernet";
        case PciSubDevice10222000::SUBDEVICE_4C531000: return "CC7/CR7/CP7/VC7/VP7/VR7 mainboard";
        case PciSubDevice10222000::SUBDEVICE_4C531010: return "CP5/CR6 mainboard";
        case PciSubDevice10222000::SUBDEVICE_4C531020: return "VR6 mainboard";
        case PciSubDevice10222000::SUBDEVICE_4C531030: return "PC5 mainboard";
        case PciSubDevice10222000::SUBDEVICE_4C531040: return "CL7 mainboard";
        case PciSubDevice10222000::SUBDEVICE_4C531060: return "PC7 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE10222000_H
