// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000097_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000097_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000097: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003090 = 0x10003090,
    SUBDEVICE_100030A0 = 0x100030A0,
    SUBDEVICE_100030E0 = 0x100030E0,
    SUBDEVICE_10003130 = 0x10003130,
    SUBDEVICE_10281F45 = 0x10281F45,
    SUBDEVICE_10281F46 = 0x10281F46,
    SUBDEVICE_10281F53 = 0x10281F53,
    SUBDEVICE_10281FD2 = 0x10281FD2,
    SUBDEVICE_10281FD3 = 0x10281FD3,
    SUBDEVICE_15D90808 = 0x15D90808,
    SUBDEVICE_1BD40008 = 0x1BD40008,
    SUBDEVICE_1BD4000B = 0x1BD4000B,
    SUBDEVICE_1BD4000C = 0x1BD4000C,
    SUBDEVICE_1BD40011 = 0x1BD40011,
    SUBDEVICE_1BD40012 = 0x1BD40012,
    SUBDEVICE_1BD4001F = 0x1BD4001F,
    SUBDEVICE_1BD40020 = 0x1BD40020,
    SUBDEVICE_1BD40026 = 0x1BD40026,
    SUBDEVICE_1BD40027 = 0x1BD40027,
    SUBDEVICE_1BD40028 = 0x1BD40028
};



inline const char8* enumToString(PciSubDevice10000097 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000097::NONE:               return "NONE";
        case PciSubDevice10000097::SUBDEVICE_10003090: return "SUBDEVICE_10003090";
        case PciSubDevice10000097::SUBDEVICE_100030A0: return "SUBDEVICE_100030A0";
        case PciSubDevice10000097::SUBDEVICE_100030E0: return "SUBDEVICE_100030E0";
        case PciSubDevice10000097::SUBDEVICE_10003130: return "SUBDEVICE_10003130";
        case PciSubDevice10000097::SUBDEVICE_10281F45: return "SUBDEVICE_10281F45";
        case PciSubDevice10000097::SUBDEVICE_10281F46: return "SUBDEVICE_10281F46";
        case PciSubDevice10000097::SUBDEVICE_10281F53: return "SUBDEVICE_10281F53";
        case PciSubDevice10000097::SUBDEVICE_10281FD2: return "SUBDEVICE_10281FD2";
        case PciSubDevice10000097::SUBDEVICE_10281FD3: return "SUBDEVICE_10281FD3";
        case PciSubDevice10000097::SUBDEVICE_15D90808: return "SUBDEVICE_15D90808";
        case PciSubDevice10000097::SUBDEVICE_1BD40008: return "SUBDEVICE_1BD40008";
        case PciSubDevice10000097::SUBDEVICE_1BD4000B: return "SUBDEVICE_1BD4000B";
        case PciSubDevice10000097::SUBDEVICE_1BD4000C: return "SUBDEVICE_1BD4000C";
        case PciSubDevice10000097::SUBDEVICE_1BD40011: return "SUBDEVICE_1BD40011";
        case PciSubDevice10000097::SUBDEVICE_1BD40012: return "SUBDEVICE_1BD40012";
        case PciSubDevice10000097::SUBDEVICE_1BD4001F: return "SUBDEVICE_1BD4001F";
        case PciSubDevice10000097::SUBDEVICE_1BD40020: return "SUBDEVICE_1BD40020";
        case PciSubDevice10000097::SUBDEVICE_1BD40026: return "SUBDEVICE_1BD40026";
        case PciSubDevice10000097::SUBDEVICE_1BD40027: return "SUBDEVICE_1BD40027";
        case PciSubDevice10000097::SUBDEVICE_1BD40028: return "SUBDEVICE_1BD40028";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000097 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000097 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000097::SUBDEVICE_10003090: return "SAS9311-8i";
        case PciSubDevice10000097::SUBDEVICE_100030A0: return "SAS9300-8e";
        case PciSubDevice10000097::SUBDEVICE_100030E0: return "SAS9300-8i";
        case PciSubDevice10000097::SUBDEVICE_10003130: return "SAS 9300-16i";
        case PciSubDevice10000097::SUBDEVICE_10281F45: return "HBA330 Adapter";
        case PciSubDevice10000097::SUBDEVICE_10281F46: return "12Gbps HBA";
        case PciSubDevice10000097::SUBDEVICE_10281F53: return "HBA330 Mini";
        case PciSubDevice10000097::SUBDEVICE_10281FD2: return "HBA330 MX";
        case PciSubDevice10000097::SUBDEVICE_10281FD3: return "HBA330 MMZ";
        case PciSubDevice10000097::SUBDEVICE_15D90808: return "AOC-S3008L-L8e";
        case PciSubDevice10000097::SUBDEVICE_1BD40008: return "12G SAS3008IMR Onboard";
        case PciSubDevice10000097::SUBDEVICE_1BD4000B: return "12G SAS3008IR";
        case PciSubDevice10000097::SUBDEVICE_1BD4000C: return "12G SAS3008IT";
        case PciSubDevice10000097::SUBDEVICE_1BD40011: return "Inspur 12Gb 8i-3008 IT SAS HBA";
        case PciSubDevice10000097::SUBDEVICE_1BD40012: return "12Gb SAS3008IR UDM";
        case PciSubDevice10000097::SUBDEVICE_1BD4001F: return "12G SAS3008IR Onboard";
        case PciSubDevice10000097::SUBDEVICE_1BD40020: return "12G SAS3008IT Onboard";
        case PciSubDevice10000097::SUBDEVICE_1BD40026: return "12G SAS3008IT RACK";
        case PciSubDevice10000097::SUBDEVICE_1BD40027: return "12G SAS3008IMR RACK";
        case PciSubDevice10000097::SUBDEVICE_1BD40028: return "12G SAS3008IR RACK";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000097_H
