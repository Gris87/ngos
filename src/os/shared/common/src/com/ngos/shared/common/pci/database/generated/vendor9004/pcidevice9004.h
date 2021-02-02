// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCIDEVICE9004_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCIDEVICE9004_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90045078.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90045647.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90046075.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90046178.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90046915.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90047815.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90047895.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90048078.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90048178.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90048778.h>
#include <com/ngos/shared/common/pci/database/generated/vendor9004/pcisubdevice90048878.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9004: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0078 = 0x0078,
    DEVICE_1078 = 0x1078,
    DEVICE_1160 = 0x1160,
    DEVICE_2178 = 0x2178,
    DEVICE_3860 = 0x3860,
    DEVICE_3B78 = 0x3B78,
    DEVICE_5075 = 0x5075,
    DEVICE_5078 = 0x5078,
    DEVICE_5175 = 0x5175,
    DEVICE_5178 = 0x5178,
    DEVICE_5275 = 0x5275,
    DEVICE_5278 = 0x5278,
    DEVICE_5375 = 0x5375,
    DEVICE_5378 = 0x5378,
    DEVICE_5475 = 0x5475,
    DEVICE_5478 = 0x5478,
    DEVICE_5575 = 0x5575,
    DEVICE_5578 = 0x5578,
    DEVICE_5647 = 0x5647,
    DEVICE_5675 = 0x5675,
    DEVICE_5678 = 0x5678,
    DEVICE_5775 = 0x5775,
    DEVICE_5778 = 0x5778,
    DEVICE_5800 = 0x5800,
    DEVICE_5900 = 0x5900,
    DEVICE_5905 = 0x5905,
    DEVICE_6038 = 0x6038,
    DEVICE_6075 = 0x6075,
    DEVICE_6078 = 0x6078,
    DEVICE_6178 = 0x6178,
    DEVICE_6278 = 0x6278,
    DEVICE_6378 = 0x6378,
    DEVICE_6478 = 0x6478,
    DEVICE_6578 = 0x6578,
    DEVICE_6678 = 0x6678,
    DEVICE_6778 = 0x6778,
    DEVICE_6915 = 0x6915,
    DEVICE_7078 = 0x7078,
    DEVICE_7178 = 0x7178,
    DEVICE_7278 = 0x7278,
    DEVICE_7378 = 0x7378,
    DEVICE_7478 = 0x7478,
    DEVICE_7578 = 0x7578,
    DEVICE_7678 = 0x7678,
    DEVICE_7710 = 0x7710,
    DEVICE_7711 = 0x7711,
    DEVICE_7778 = 0x7778,
    DEVICE_7810 = 0x7810,
    DEVICE_7815 = 0x7815,
    DEVICE_7850 = 0x7850,
    DEVICE_7855 = 0x7855,
    DEVICE_7860 = 0x7860,
    DEVICE_7870 = 0x7870,
    DEVICE_7871 = 0x7871,
    DEVICE_7872 = 0x7872,
    DEVICE_7873 = 0x7873,
    DEVICE_7874 = 0x7874,
    DEVICE_7880 = 0x7880,
    DEVICE_7890 = 0x7890,
    DEVICE_7891 = 0x7891,
    DEVICE_7892 = 0x7892,
    DEVICE_7893 = 0x7893,
    DEVICE_7894 = 0x7894,
    DEVICE_7895 = 0x7895,
    DEVICE_7896 = 0x7896,
    DEVICE_7897 = 0x7897,
    DEVICE_8078 = 0x8078,
    DEVICE_8178 = 0x8178,
    DEVICE_8278 = 0x8278,
    DEVICE_8378 = 0x8378,
    DEVICE_8478 = 0x8478,
    DEVICE_8578 = 0x8578,
    DEVICE_8678 = 0x8678,
    DEVICE_8778 = 0x8778,
    DEVICE_8878 = 0x8878,
    DEVICE_8B78 = 0x8B78,
    DEVICE_EC78 = 0xEC78
};



inline const char8* enumToString(PciDevice9004 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice9004::NONE:        return "NONE";
        case PciDevice9004::DEVICE_0078: return "DEVICE_0078";
        case PciDevice9004::DEVICE_1078: return "DEVICE_1078";
        case PciDevice9004::DEVICE_1160: return "DEVICE_1160";
        case PciDevice9004::DEVICE_2178: return "DEVICE_2178";
        case PciDevice9004::DEVICE_3860: return "DEVICE_3860";
        case PciDevice9004::DEVICE_3B78: return "DEVICE_3B78";
        case PciDevice9004::DEVICE_5075: return "DEVICE_5075";
        case PciDevice9004::DEVICE_5078: return "DEVICE_5078";
        case PciDevice9004::DEVICE_5175: return "DEVICE_5175";
        case PciDevice9004::DEVICE_5178: return "DEVICE_5178";
        case PciDevice9004::DEVICE_5275: return "DEVICE_5275";
        case PciDevice9004::DEVICE_5278: return "DEVICE_5278";
        case PciDevice9004::DEVICE_5375: return "DEVICE_5375";
        case PciDevice9004::DEVICE_5378: return "DEVICE_5378";
        case PciDevice9004::DEVICE_5475: return "DEVICE_5475";
        case PciDevice9004::DEVICE_5478: return "DEVICE_5478";
        case PciDevice9004::DEVICE_5575: return "DEVICE_5575";
        case PciDevice9004::DEVICE_5578: return "DEVICE_5578";
        case PciDevice9004::DEVICE_5647: return "DEVICE_5647";
        case PciDevice9004::DEVICE_5675: return "DEVICE_5675";
        case PciDevice9004::DEVICE_5678: return "DEVICE_5678";
        case PciDevice9004::DEVICE_5775: return "DEVICE_5775";
        case PciDevice9004::DEVICE_5778: return "DEVICE_5778";
        case PciDevice9004::DEVICE_5800: return "DEVICE_5800";
        case PciDevice9004::DEVICE_5900: return "DEVICE_5900";
        case PciDevice9004::DEVICE_5905: return "DEVICE_5905";
        case PciDevice9004::DEVICE_6038: return "DEVICE_6038";
        case PciDevice9004::DEVICE_6075: return "DEVICE_6075";
        case PciDevice9004::DEVICE_6078: return "DEVICE_6078";
        case PciDevice9004::DEVICE_6178: return "DEVICE_6178";
        case PciDevice9004::DEVICE_6278: return "DEVICE_6278";
        case PciDevice9004::DEVICE_6378: return "DEVICE_6378";
        case PciDevice9004::DEVICE_6478: return "DEVICE_6478";
        case PciDevice9004::DEVICE_6578: return "DEVICE_6578";
        case PciDevice9004::DEVICE_6678: return "DEVICE_6678";
        case PciDevice9004::DEVICE_6778: return "DEVICE_6778";
        case PciDevice9004::DEVICE_6915: return "DEVICE_6915";
        case PciDevice9004::DEVICE_7078: return "DEVICE_7078";
        case PciDevice9004::DEVICE_7178: return "DEVICE_7178";
        case PciDevice9004::DEVICE_7278: return "DEVICE_7278";
        case PciDevice9004::DEVICE_7378: return "DEVICE_7378";
        case PciDevice9004::DEVICE_7478: return "DEVICE_7478";
        case PciDevice9004::DEVICE_7578: return "DEVICE_7578";
        case PciDevice9004::DEVICE_7678: return "DEVICE_7678";
        case PciDevice9004::DEVICE_7710: return "DEVICE_7710";
        case PciDevice9004::DEVICE_7711: return "DEVICE_7711";
        case PciDevice9004::DEVICE_7778: return "DEVICE_7778";
        case PciDevice9004::DEVICE_7810: return "DEVICE_7810";
        case PciDevice9004::DEVICE_7815: return "DEVICE_7815";
        case PciDevice9004::DEVICE_7850: return "DEVICE_7850";
        case PciDevice9004::DEVICE_7855: return "DEVICE_7855";
        case PciDevice9004::DEVICE_7860: return "DEVICE_7860";
        case PciDevice9004::DEVICE_7870: return "DEVICE_7870";
        case PciDevice9004::DEVICE_7871: return "DEVICE_7871";
        case PciDevice9004::DEVICE_7872: return "DEVICE_7872";
        case PciDevice9004::DEVICE_7873: return "DEVICE_7873";
        case PciDevice9004::DEVICE_7874: return "DEVICE_7874";
        case PciDevice9004::DEVICE_7880: return "DEVICE_7880";
        case PciDevice9004::DEVICE_7890: return "DEVICE_7890";
        case PciDevice9004::DEVICE_7891: return "DEVICE_7891";
        case PciDevice9004::DEVICE_7892: return "DEVICE_7892";
        case PciDevice9004::DEVICE_7893: return "DEVICE_7893";
        case PciDevice9004::DEVICE_7894: return "DEVICE_7894";
        case PciDevice9004::DEVICE_7895: return "DEVICE_7895";
        case PciDevice9004::DEVICE_7896: return "DEVICE_7896";
        case PciDevice9004::DEVICE_7897: return "DEVICE_7897";
        case PciDevice9004::DEVICE_8078: return "DEVICE_8078";
        case PciDevice9004::DEVICE_8178: return "DEVICE_8178";
        case PciDevice9004::DEVICE_8278: return "DEVICE_8278";
        case PciDevice9004::DEVICE_8378: return "DEVICE_8378";
        case PciDevice9004::DEVICE_8478: return "DEVICE_8478";
        case PciDevice9004::DEVICE_8578: return "DEVICE_8578";
        case PciDevice9004::DEVICE_8678: return "DEVICE_8678";
        case PciDevice9004::DEVICE_8778: return "DEVICE_8778";
        case PciDevice9004::DEVICE_8878: return "DEVICE_8878";
        case PciDevice9004::DEVICE_8B78: return "DEVICE_8B78";
        case PciDevice9004::DEVICE_EC78: return "DEVICE_EC78";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9004 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice9004 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice9004::DEVICE_0078: return "AHA-2940U_CN";
        case PciDevice9004::DEVICE_1078: return "AIC-7810";
        case PciDevice9004::DEVICE_1160: return "AIC-1160 [Family Fibre Channel Adapter]";
        case PciDevice9004::DEVICE_2178: return "AIC-7821";
        case PciDevice9004::DEVICE_3860: return "AHA-2930CU";
        case PciDevice9004::DEVICE_3B78: return "AHA-4844W/4844UW";
        case PciDevice9004::DEVICE_5075: return "AIC-755x";
        case PciDevice9004::DEVICE_5078: return "AIC-7850T/7856T [AVA-2902/4/6 / AHA-2910]";
        case PciDevice9004::DEVICE_5175: return "AIC-755x";
        case PciDevice9004::DEVICE_5178: return "AIC-7851";
        case PciDevice9004::DEVICE_5275: return "AIC-755x";
        case PciDevice9004::DEVICE_5278: return "AIC-7852";
        case PciDevice9004::DEVICE_5375: return "AIC-755x";
        case PciDevice9004::DEVICE_5378: return "AIC-7850";
        case PciDevice9004::DEVICE_5475: return "AIC-755x";
        case PciDevice9004::DEVICE_5478: return "AIC-7850";
        case PciDevice9004::DEVICE_5575: return "AVA-2930";
        case PciDevice9004::DEVICE_5578: return "AIC-7855";
        case PciDevice9004::DEVICE_5647: return "ANA-7711 TCP Offload Engine";
        case PciDevice9004::DEVICE_5675: return "AIC-755x";
        case PciDevice9004::DEVICE_5678: return "AIC-7856";
        case PciDevice9004::DEVICE_5775: return "AIC-755x";
        case PciDevice9004::DEVICE_5778: return "AIC-7850";
        case PciDevice9004::DEVICE_5800: return "AIC-5800";
        case PciDevice9004::DEVICE_5900: return "ANA-5910/5930/5940 ATM155 & 25 LAN Adapter";
        case PciDevice9004::DEVICE_5905: return "ANA-5910A/5930A/5940A ATM Adapter";
        case PciDevice9004::DEVICE_6038: return "AIC-3860";
        case PciDevice9004::DEVICE_6075: return "AIC-1480 / APA-1480";
        case PciDevice9004::DEVICE_6078: return "AIC-7860";
        case PciDevice9004::DEVICE_6178: return "AIC-7861";
        case PciDevice9004::DEVICE_6278: return "AIC-7860";
        case PciDevice9004::DEVICE_6378: return "AIC-7860";
        case PciDevice9004::DEVICE_6478: return "AIC-786x";
        case PciDevice9004::DEVICE_6578: return "AIC-786x";
        case PciDevice9004::DEVICE_6678: return "AIC-786x";
        case PciDevice9004::DEVICE_6778: return "AIC-786x";
        case PciDevice9004::DEVICE_6915: return "ANA620xx/ANA69011A";
        case PciDevice9004::DEVICE_7078: return "AHA-294x / AIC-7870";
        case PciDevice9004::DEVICE_7178: return "AIC-7870P/7871 [AHA-2940/W/S76]";
        case PciDevice9004::DEVICE_7278: return "AHA-3940/3940W / AIC-7872";
        case PciDevice9004::DEVICE_7378: return "AHA-3985 / AIC-7873";
        case PciDevice9004::DEVICE_7478: return "AHA-2944/2944W / AIC-7874";
        case PciDevice9004::DEVICE_7578: return "AHA-3944/3944W / AIC-7875";
        case PciDevice9004::DEVICE_7678: return "AHA-4944W/UW / AIC-7876";
        case PciDevice9004::DEVICE_7710: return "ANA-7711F Network Accelerator Card (NAC) - Optical";
        case PciDevice9004::DEVICE_7711: return "ANA-7711C Network Accelerator Card (NAC) - Copper";
        case PciDevice9004::DEVICE_7778: return "AIC-787x";
        case PciDevice9004::DEVICE_7810: return "AIC-7810";
        case PciDevice9004::DEVICE_7815: return "AIC-7815 RAID+Memory Controller IC";
        case PciDevice9004::DEVICE_7850: return "AIC-7850";
        case PciDevice9004::DEVICE_7855: return "AHA-2930";
        case PciDevice9004::DEVICE_7860: return "AIC-7860";
        case PciDevice9004::DEVICE_7870: return "AIC-7870";
        case PciDevice9004::DEVICE_7871: return "AHA-2940";
        case PciDevice9004::DEVICE_7872: return "AHA-3940";
        case PciDevice9004::DEVICE_7873: return "AHA-3980";
        case PciDevice9004::DEVICE_7874: return "AHA-2944";
        case PciDevice9004::DEVICE_7880: return "AIC-7880P";
        case PciDevice9004::DEVICE_7890: return "AIC-7890";
        case PciDevice9004::DEVICE_7891: return "AIC-789x";
        case PciDevice9004::DEVICE_7892: return "AIC-789x";
        case PciDevice9004::DEVICE_7893: return "AIC-789x";
        case PciDevice9004::DEVICE_7894: return "AIC-789x";
        case PciDevice9004::DEVICE_7895: return "AHA-2940U/UW / AHA-39xx / AIC-7895";
        case PciDevice9004::DEVICE_7896: return "AIC-789x";
        case PciDevice9004::DEVICE_7897: return "AIC-789x";
        case PciDevice9004::DEVICE_8078: return "AIC-7880U";
        case PciDevice9004::DEVICE_8178: return "AIC-7870P/7881U [AHA-2940U/UW/D/S76]";
        case PciDevice9004::DEVICE_8278: return "AHA-3940U/UW/UWD / AIC-7882U";
        case PciDevice9004::DEVICE_8378: return "AHA-3940U/UW / AIC-7883U";
        case PciDevice9004::DEVICE_8478: return "AHA-2944UW / AIC-7884U";
        case PciDevice9004::DEVICE_8578: return "AHA-3944U/UWD / AIC-7885";
        case PciDevice9004::DEVICE_8678: return "AHA-4944UW / AIC-7886";
        case PciDevice9004::DEVICE_8778: return "AHA-2940UW Pro / AIC-788x";
        case PciDevice9004::DEVICE_8878: return "AHA-2930UW / AIC-7888";
        case PciDevice9004::DEVICE_8B78: return "ABA-1030";
        case PciDevice9004::DEVICE_EC78: return "AHA-4944W/UW";

        default: return "Unknown device";
    }
}



inline const char8* enumToHumanString(PciDevice9004 device, bad_uint16 subsystemVendorID, bad_uint16 subDeviceId) // TEST: NO
{
    // COMMON_LT((" | device = %u, subsystemVendorID = %u, subDeviceId = %u", device, subsystemVendorID, subDeviceId)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice9004::DEVICE_0078: return "Unknown device";
        case PciDevice9004::DEVICE_1078: return "Unknown device";
        case PciDevice9004::DEVICE_1160: return "Unknown device";
        case PciDevice9004::DEVICE_2178: return "Unknown device";
        case PciDevice9004::DEVICE_3860: return "Unknown device";
        case PciDevice9004::DEVICE_3B78: return "Unknown device";
        case PciDevice9004::DEVICE_5075: return "Unknown device";
        case PciDevice9004::DEVICE_5078: return enumToHumanString((PciSubDevice90045078)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_5175: return "Unknown device";
        case PciDevice9004::DEVICE_5178: return "Unknown device";
        case PciDevice9004::DEVICE_5275: return "Unknown device";
        case PciDevice9004::DEVICE_5278: return "Unknown device";
        case PciDevice9004::DEVICE_5375: return "Unknown device";
        case PciDevice9004::DEVICE_5378: return "Unknown device";
        case PciDevice9004::DEVICE_5475: return "Unknown device";
        case PciDevice9004::DEVICE_5478: return "Unknown device";
        case PciDevice9004::DEVICE_5575: return "Unknown device";
        case PciDevice9004::DEVICE_5578: return "Unknown device";
        case PciDevice9004::DEVICE_5647: return enumToHumanString((PciSubDevice90045647)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_5675: return "Unknown device";
        case PciDevice9004::DEVICE_5678: return "Unknown device";
        case PciDevice9004::DEVICE_5775: return "Unknown device";
        case PciDevice9004::DEVICE_5778: return "Unknown device";
        case PciDevice9004::DEVICE_5800: return "Unknown device";
        case PciDevice9004::DEVICE_5900: return "Unknown device";
        case PciDevice9004::DEVICE_5905: return "Unknown device";
        case PciDevice9004::DEVICE_6038: return "Unknown device";
        case PciDevice9004::DEVICE_6075: return enumToHumanString((PciSubDevice90046075)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_6078: return "Unknown device";
        case PciDevice9004::DEVICE_6178: return enumToHumanString((PciSubDevice90046178)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_6278: return "Unknown device";
        case PciDevice9004::DEVICE_6378: return "Unknown device";
        case PciDevice9004::DEVICE_6478: return "Unknown device";
        case PciDevice9004::DEVICE_6578: return "Unknown device";
        case PciDevice9004::DEVICE_6678: return "Unknown device";
        case PciDevice9004::DEVICE_6778: return "Unknown device";
        case PciDevice9004::DEVICE_6915: return enumToHumanString((PciSubDevice90046915)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_7078: return "Unknown device";
        case PciDevice9004::DEVICE_7178: return "Unknown device";
        case PciDevice9004::DEVICE_7278: return "Unknown device";
        case PciDevice9004::DEVICE_7378: return "Unknown device";
        case PciDevice9004::DEVICE_7478: return "Unknown device";
        case PciDevice9004::DEVICE_7578: return "Unknown device";
        case PciDevice9004::DEVICE_7678: return "Unknown device";
        case PciDevice9004::DEVICE_7710: return "Unknown device";
        case PciDevice9004::DEVICE_7711: return "Unknown device";
        case PciDevice9004::DEVICE_7778: return "Unknown device";
        case PciDevice9004::DEVICE_7810: return "Unknown device";
        case PciDevice9004::DEVICE_7815: return enumToHumanString((PciSubDevice90047815)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_7850: return "Unknown device";
        case PciDevice9004::DEVICE_7855: return "Unknown device";
        case PciDevice9004::DEVICE_7860: return "Unknown device";
        case PciDevice9004::DEVICE_7870: return "Unknown device";
        case PciDevice9004::DEVICE_7871: return "Unknown device";
        case PciDevice9004::DEVICE_7872: return "Unknown device";
        case PciDevice9004::DEVICE_7873: return "Unknown device";
        case PciDevice9004::DEVICE_7874: return "Unknown device";
        case PciDevice9004::DEVICE_7880: return "Unknown device";
        case PciDevice9004::DEVICE_7890: return "Unknown device";
        case PciDevice9004::DEVICE_7891: return "Unknown device";
        case PciDevice9004::DEVICE_7892: return "Unknown device";
        case PciDevice9004::DEVICE_7893: return "Unknown device";
        case PciDevice9004::DEVICE_7894: return "Unknown device";
        case PciDevice9004::DEVICE_7895: return enumToHumanString((PciSubDevice90047895)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_7896: return "Unknown device";
        case PciDevice9004::DEVICE_7897: return "Unknown device";
        case PciDevice9004::DEVICE_8078: return enumToHumanString((PciSubDevice90048078)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_8178: return enumToHumanString((PciSubDevice90048178)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_8278: return "Unknown device";
        case PciDevice9004::DEVICE_8378: return "Unknown device";
        case PciDevice9004::DEVICE_8478: return "Unknown device";
        case PciDevice9004::DEVICE_8578: return "Unknown device";
        case PciDevice9004::DEVICE_8678: return "Unknown device";
        case PciDevice9004::DEVICE_8778: return enumToHumanString((PciSubDevice90048778)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_8878: return enumToHumanString((PciSubDevice90048878)(subsystemVendorID << 16 | subDeviceId));
        case PciDevice9004::DEVICE_8B78: return "Unknown device";
        case PciDevice9004::DEVICE_EC78: return "Unknown device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCIDEVICE9004_H
