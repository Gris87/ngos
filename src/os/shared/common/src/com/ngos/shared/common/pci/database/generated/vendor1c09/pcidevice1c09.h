// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C09_PCIDEVICE1C09_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C09_PCIDEVICE1C09_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1C09: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_4254 = 0x4254,
    DEVICE_4255 = 0x4255,
    DEVICE_4256 = 0x4256,
    DEVICE_4258 = 0x4258,
    DEVICE_4260 = 0x4260,
    DEVICE_4261 = 0x4261,
    DEVICE_4262 = 0x4262,
    DEVICE_4263 = 0x4263,
    DEVICE_4264 = 0x4264,
    DEVICE_4265 = 0x4265,
    DEVICE_5000 = 0x5000,
    DEVICE_5001 = 0x5001
};



inline const char8* enumToString(PciDevice1C09 device1C09) // TEST: NO
{
    // COMMON_LT((" | device1C09 = %u", device1C09)); // Commented to avoid bad looking logs



    switch (device1C09)
    {
        case PciDevice1C09::NONE:        return "NONE";
        case PciDevice1C09::DEVICE_4254: return "DEVICE_4254";
        case PciDevice1C09::DEVICE_4255: return "DEVICE_4255";
        case PciDevice1C09::DEVICE_4256: return "DEVICE_4256";
        case PciDevice1C09::DEVICE_4258: return "DEVICE_4258";
        case PciDevice1C09::DEVICE_4260: return "DEVICE_4260";
        case PciDevice1C09::DEVICE_4261: return "DEVICE_4261";
        case PciDevice1C09::DEVICE_4262: return "DEVICE_4262";
        case PciDevice1C09::DEVICE_4263: return "DEVICE_4263";
        case PciDevice1C09::DEVICE_4264: return "DEVICE_4264";
        case PciDevice1C09::DEVICE_4265: return "DEVICE_4265";
        case PciDevice1C09::DEVICE_5000: return "DEVICE_5000";
        case PciDevice1C09::DEVICE_5001: return "DEVICE_5001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1C09 device1C09) // TEST: NO
{
    // COMMON_LT((" | device1C09 = %u", device1C09)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1C09, enumToString(device1C09));

    return res;
}



inline const char8* enumToHumanString(PciDevice1C09 device1C09) // TEST: NO
{
    // COMMON_LT((" | device1C09 = %u", device1C09)); // Commented to avoid bad looking logs



    switch (device1C09)
    {
        case PciDevice1C09::DEVICE_4254: return "10G-PCIE3-8D-2S";
        case PciDevice1C09::DEVICE_4255: return "10G-PCIE3-8D-Q";
        case PciDevice1C09::DEVICE_4256: return "10G-PCIE3-8D-2S";
        case PciDevice1C09::DEVICE_4258: return "10G-PCIE3-8E-2S Network Adapter";
        case PciDevice1C09::DEVICE_4260: return "10G-PCIE3-8E-4S Network Adapter";
        case PciDevice1C09::DEVICE_4261: return "10G-PCIE3-8E-4S Network Adapter";
        case PciDevice1C09::DEVICE_4262: return "10G-PCIE3-8E-4S Network Adapter";
        case PciDevice1C09::DEVICE_4263: return "10G-PCIE3-8E-4S Network Adapter";
        case PciDevice1C09::DEVICE_4264: return "10G-PCIE3-8E-2S Network Adapter";
        case PciDevice1C09::DEVICE_4265: return "10G-PCIE3-8E-2S Network Adapter";
        case PciDevice1C09::DEVICE_5000: return "25G-PCIE3-8A-2S Security Intelligent Adapter";
        case PciDevice1C09::DEVICE_5001: return "25G-PCIE3-8B-2S Security Intelligent Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C09_PCIDEVICE1C09_H
