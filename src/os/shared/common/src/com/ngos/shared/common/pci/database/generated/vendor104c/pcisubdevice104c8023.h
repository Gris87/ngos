// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8023_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8023_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8023: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280168 = 0x10280168,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_1043808B = 0x1043808B,
    SUBDEVICE_1043815B = 0x1043815B,
    SUBDEVICE_14438023 = 0x14438023,
    SUBDEVICE_80865044 = 0x80865044
};



inline const char8* enumToString(PciSubDevice104C8023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8023::NONE:               return "NONE";
        case PciSubDevice104C8023::SUBDEVICE_10280168: return "SUBDEVICE_10280168";
        case PciSubDevice104C8023::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice104C8023::SUBDEVICE_1043808B: return "SUBDEVICE_1043808B";
        case PciSubDevice104C8023::SUBDEVICE_1043815B: return "SUBDEVICE_1043815B";
        case PciSubDevice104C8023::SUBDEVICE_14438023: return "SUBDEVICE_14438023";
        case PciSubDevice104C8023::SUBDEVICE_80865044: return "SUBDEVICE_80865044";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8023 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8023::SUBDEVICE_10280168: return "Precision Workstation 670 Mainboard";
        case PciSubDevice104C8023::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice104C8023::SUBDEVICE_1043808B: return "K8N4/A8N Series Mainboard";
        case PciSubDevice104C8023::SUBDEVICE_1043815B: return "P5W DH Deluxe Motherboard";
        case PciSubDevice104C8023::SUBDEVICE_14438023: return "FireCard400";
        case PciSubDevice104C8023::SUBDEVICE_80865044: return "Desktop Board DP35DP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8023_H
