// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDeviceDD010003: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_DD010001 = 0xDD010001,
    SUBDEVICE_DD010002 = 0xDD010002,
    SUBDEVICE_DD010003 = 0xDD010003,
    SUBDEVICE_DD010004 = 0xDD010004,
    SUBDEVICE_DD010010 = 0xDD010010,
    SUBDEVICE_DD010020 = 0xDD010020,
    SUBDEVICE_DD010021 = 0xDD010021,
    SUBDEVICE_DD010030 = 0xDD010030,
    SUBDEVICE_DD01DB03 = 0xDD01DB03
};



inline const char8* enumToString(PciSubDeviceDD010003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceDD010003::NONE:               return "NONE";
        case PciSubDeviceDD010003::SUBDEVICE_DD010001: return "SUBDEVICE_DD010001";
        case PciSubDeviceDD010003::SUBDEVICE_DD010002: return "SUBDEVICE_DD010002";
        case PciSubDeviceDD010003::SUBDEVICE_DD010003: return "SUBDEVICE_DD010003";
        case PciSubDeviceDD010003::SUBDEVICE_DD010004: return "SUBDEVICE_DD010004";
        case PciSubDeviceDD010003::SUBDEVICE_DD010010: return "SUBDEVICE_DD010010";
        case PciSubDeviceDD010003::SUBDEVICE_DD010020: return "SUBDEVICE_DD010020";
        case PciSubDeviceDD010003::SUBDEVICE_DD010021: return "SUBDEVICE_DD010021";
        case PciSubDeviceDD010003::SUBDEVICE_DD010030: return "SUBDEVICE_DD010030";
        case PciSubDeviceDD010003::SUBDEVICE_DD01DB03: return "SUBDEVICE_DD01DB03";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDeviceDD010003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDeviceDD010003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDeviceDD010003::SUBDEVICE_DD010001: return "Octopus DVB adapter";
        case PciSubDeviceDD010003::SUBDEVICE_DD010002: return "Octopus LE DVB adapter";
        case PciSubDeviceDD010003::SUBDEVICE_DD010003: return "Octopus OEM";
        case PciSubDeviceDD010003::SUBDEVICE_DD010004: return "Octopus V3 DVB adapter";
        case PciSubDeviceDD010003::SUBDEVICE_DD010010: return "Octopus Mini";
        case PciSubDeviceDD010003::SUBDEVICE_DD010020: return "Cine S2 V6 DVB adapter";
        case PciSubDeviceDD010003::SUBDEVICE_DD010021: return "Cine S2 V6.5 DVB adapter";
        case PciSubDeviceDD010003::SUBDEVICE_DD010030: return "Cine CT V6.1 DVB adapter";
        case PciSubDeviceDD010003::SUBDEVICE_DD01DB03: return "Mystique SaTiX-S2 V3 DVB adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDORDD01_PCISUBDEVICEDD010003_H
