// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864140_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864140_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864140: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10282134 = 0x10282134,
    SUBDEVICE_10282135 = 0x10282135,
    SUBDEVICE_10282136 = 0x10282136,
    SUBDEVICE_10282137 = 0x10282137,
    SUBDEVICE_10282138 = 0x10282138,
    SUBDEVICE_10282139 = 0x10282139
};



inline const char8* enumToString(PciSubDevice80864140 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864140::NONE:               return "NONE";
        case PciSubDevice80864140::SUBDEVICE_10282134: return "SUBDEVICE_10282134";
        case PciSubDevice80864140::SUBDEVICE_10282135: return "SUBDEVICE_10282135";
        case PciSubDevice80864140::SUBDEVICE_10282136: return "SUBDEVICE_10282136";
        case PciSubDevice80864140::SUBDEVICE_10282137: return "SUBDEVICE_10282137";
        case PciSubDevice80864140::SUBDEVICE_10282138: return "SUBDEVICE_10282138";
        case PciSubDevice80864140::SUBDEVICE_10282139: return "SUBDEVICE_10282139";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864140 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864140 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864140::SUBDEVICE_10282134: return "NVMe Datacenter SSD [Optane] SED 400GB 2.5\" U.2 (P5800X)";
        case PciSubDevice80864140::SUBDEVICE_10282135: return "NVMe Datacenter SSD [Optane] SED 800GB 2.5\" U.2 (P5800X)";
        case PciSubDevice80864140::SUBDEVICE_10282136: return "NVMe Datacenter SSD [Optane] SED 1.6TB 2.5\" U.2 (P5800X)";
        case PciSubDevice80864140::SUBDEVICE_10282137: return "NVMe Datacenter SSD [Optane] 400GB 2.5\" U.2 (P5800X)";
        case PciSubDevice80864140::SUBDEVICE_10282138: return "NVMe Datacenter SSD [Optane] 800GB 2.5\" U.2 (P5800X)";
        case PciSubDevice80864140::SUBDEVICE_10282139: return "NVMe Datacenter SSD [Optane] 1.6TB 2.5\" U.2 (P5800X)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864140_H
