// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCISUBDEVICE1C580003_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCISUBDEVICE1C580003_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1C580003: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101404F5 = 0x101404F5,
    SUBDEVICE_101404F6 = 0x101404F6,
    SUBDEVICE_1C580003 = 0x1C580003
};



inline const char8* enumToString(PciSubDevice1C580003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C580003::NONE:               return "NONE";
        case PciSubDevice1C580003::SUBDEVICE_101404F5: return "SUBDEVICE_101404F5";
        case PciSubDevice1C580003::SUBDEVICE_101404F6: return "SUBDEVICE_101404F6";
        case PciSubDevice1C580003::SUBDEVICE_1C580003: return "SUBDEVICE_1C580003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1C580003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1C580003 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1C580003::SUBDEVICE_101404F5: return "PCIe3 1.6TB NVMe Flash Adapter";
        case PciSubDevice1C580003::SUBDEVICE_101404F6: return "PCIe3 3.2TB NVMe Flash Adapter";
        case PciSubDevice1C580003::SUBDEVICE_1C580003: return "Ultrastar SN100/SN150 NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1C58_PCISUBDEVICE1C580003_H
