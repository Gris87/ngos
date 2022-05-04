// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCISUBDEVICE1C5F000E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCISUBDEVICE1C5F000E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1C5F000E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1C5F0B20 = 0x1C5F0B20,
    SUBDEVICE_1C5F0B21 = 0x1C5F0B21,
    SUBDEVICE_1C5F0B30 = 0x1C5F0B30,
    SUBDEVICE_1C5F0B31 = 0x1C5F0B31,
    SUBDEVICE_1C5F0B40 = 0x1C5F0B40,
    SUBDEVICE_1C5F0B41 = 0x1C5F0B41,
    SUBDEVICE_1C5F4B20 = 0x1C5F4B20,
    SUBDEVICE_1C5F4B21 = 0x1C5F4B21,
    SUBDEVICE_1C5F4B30 = 0x1C5F4B30,
    SUBDEVICE_1C5F4B31 = 0x1C5F4B31,
    SUBDEVICE_1C5F4B40 = 0x1C5F4B40,
    SUBDEVICE_1C5F4B41 = 0x1C5F4B41
};



inline const char8* enumToString(PciSubDevice1C5F000E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5F000E::NONE:               return "NONE";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B20: return "SUBDEVICE_1C5F0B20";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B21: return "SUBDEVICE_1C5F0B21";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B30: return "SUBDEVICE_1C5F0B30";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B31: return "SUBDEVICE_1C5F0B31";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B40: return "SUBDEVICE_1C5F0B40";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B41: return "SUBDEVICE_1C5F0B41";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B20: return "SUBDEVICE_1C5F4B20";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B21: return "SUBDEVICE_1C5F4B21";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B30: return "SUBDEVICE_1C5F4B30";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B31: return "SUBDEVICE_1C5F4B31";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B40: return "SUBDEVICE_1C5F4B40";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B41: return "SUBDEVICE_1C5F4B41";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1C5F000E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1C5F000E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B20: return "NVMe SSD PBlaze6 6530 1920G AIC";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B21: return "NVMe SSD PBlaze6 6530 1920G 2.5\" U.2";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B30: return "NVMe SSD PBlaze6 6530 3840G AIC";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B31: return "NVMe SSD PBlaze6 6530 3840G 2.5\" U.2";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B40: return "NVMe SSD PBlaze6 6530 7680G AIC";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F0B41: return "NVMe SSD PBlaze6 6530 7680G 2.5\" U.2";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B20: return "NVMe SSD PBlaze6 6530 1600G AIC";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B21: return "NVMe SSD PBlaze6 6530 1600G 2.5\" U.2";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B30: return "NVMe SSD PBlaze6 6530 3200G AIC";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B31: return "NVMe SSD PBlaze6 6530 3200G 2.5\" U.2";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B40: return "NVMe SSD PBlaze6 6530 6400G AIC";
        case PciSubDevice1C5F000E::SUBDEVICE_1C5F4B41: return "NVMe SSD PBlaze6 6530 6400G 2.5\" U.2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C5F_PCISUBDEVICE1C5F000E_H
