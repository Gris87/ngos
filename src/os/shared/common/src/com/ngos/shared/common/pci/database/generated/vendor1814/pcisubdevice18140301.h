// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140301_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140301_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18140301: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11863C08 = 0x11863C08,
    SUBDEVICE_11863C09 = 0x11863C09,
    SUBDEVICE_13D1ABE3 = 0x13D1ABE3,
    SUBDEVICE_1458E933 = 0x1458E933,
    SUBDEVICE_1458E934 = 0x1458E934,
    SUBDEVICE_1462B833 = 0x1462B833,
    SUBDEVICE_17370055 = 0x17370055,
    SUBDEVICE_1799700E = 0x1799700E,
    SUBDEVICE_1799701E = 0x1799701E,
    SUBDEVICE_17F90012 = 0x17F90012,
    SUBDEVICE_18142561 = 0x18142561
};



inline const char8* enumToString(PciSubDevice18140301 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140301::NONE:               return "NONE";
        case PciSubDevice18140301::SUBDEVICE_11863C08: return "SUBDEVICE_11863C08";
        case PciSubDevice18140301::SUBDEVICE_11863C09: return "SUBDEVICE_11863C09";
        case PciSubDevice18140301::SUBDEVICE_13D1ABE3: return "SUBDEVICE_13D1ABE3";
        case PciSubDevice18140301::SUBDEVICE_1458E933: return "SUBDEVICE_1458E933";
        case PciSubDevice18140301::SUBDEVICE_1458E934: return "SUBDEVICE_1458E934";
        case PciSubDevice18140301::SUBDEVICE_1462B833: return "SUBDEVICE_1462B833";
        case PciSubDevice18140301::SUBDEVICE_17370055: return "SUBDEVICE_17370055";
        case PciSubDevice18140301::SUBDEVICE_1799700E: return "SUBDEVICE_1799700E";
        case PciSubDevice18140301::SUBDEVICE_1799701E: return "SUBDEVICE_1799701E";
        case PciSubDevice18140301::SUBDEVICE_17F90012: return "SUBDEVICE_17F90012";
        case PciSubDevice18140301::SUBDEVICE_18142561: return "SUBDEVICE_18142561";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18140301 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18140301 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140301::SUBDEVICE_11863C08: return "AirPlus G DWL-G630 Wireless Cardbus Adapter (rev.E1)";
        case PciSubDevice18140301::SUBDEVICE_11863C09: return "DWL-G510 Rev C";
        case PciSubDevice18140301::SUBDEVICE_13D1ABE3: return "miniPCI Pluscom 802.11 a/b/g";
        case PciSubDevice18140301::SUBDEVICE_1458E933: return "GN-WI01GS";
        case PciSubDevice18140301::SUBDEVICE_1458E934: return "GN-WP01GS";
        case PciSubDevice18140301::SUBDEVICE_1462B833: return "MP54G5 (MS-6833B)";
        case PciSubDevice18140301::SUBDEVICE_17370055: return "WMP54G v4.1";
        case PciSubDevice18140301::SUBDEVICE_1799700E: return "F5D7000 v6000 Wireless G Desktop Card";
        case PciSubDevice18140301::SUBDEVICE_1799701E: return "F5D7010 v6000 Wireless G Notebook Card";
        case PciSubDevice18140301::SUBDEVICE_17F90012: return "AWLC3026T 802.11g Wireless CardBus Adapter";
        case PciSubDevice18140301::SUBDEVICE_18142561: return "EW-7108PCg/EW-7128g";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140301_H
