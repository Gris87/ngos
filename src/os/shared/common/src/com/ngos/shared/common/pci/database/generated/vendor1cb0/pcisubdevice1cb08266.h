// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB08266_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB08266_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1CB08266: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1CB02021 = 0x1CB02021,
    SUBDEVICE_1CB02121 = 0x1CB02121,
    SUBDEVICE_1CB02F21 = 0x1CB02F21,
    SUBDEVICE_1CB02F22 = 0x1CB02F22
};



inline const char8* enumToString(PciSubDevice1CB08266 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1CB08266::NONE:               return "NONE";
        case PciSubDevice1CB08266::SUBDEVICE_1CB02021: return "SUBDEVICE_1CB02021";
        case PciSubDevice1CB08266::SUBDEVICE_1CB02121: return "SUBDEVICE_1CB02121";
        case PciSubDevice1CB08266::SUBDEVICE_1CB02F21: return "SUBDEVICE_1CB02F21";
        case PciSubDevice1CB08266::SUBDEVICE_1CB02F22: return "SUBDEVICE_1CB02F22";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1CB08266 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1CB08266 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1CB08266::SUBDEVICE_1CB02021: return "SP4 Series OCS U.2 SSD";
        case PciSubDevice1CB08266::SUBDEVICE_1CB02121: return "SP4 Series ZNS U.2 SSD";
        case PciSubDevice1CB08266::SUBDEVICE_1CB02F21: return "SP4E Series NVMe U.2 SSD(1920/3840/7680GB)";
        case PciSubDevice1CB08266::SUBDEVICE_1CB02F22: return "SP4X Series NVMe U.2 SSD(1600/3200/6400GB)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1CB0_PCISUBDEVICE1CB08266_H
