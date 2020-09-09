// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B71700_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B71700_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10B71700: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380EB = 0x104380EB,
    SUBDEVICE_10B70010 = 0x10B70010,
    SUBDEVICE_10B70020 = 0x10B70020,
    SUBDEVICE_147B1407 = 0x147B1407
};



inline const char8* enumToString(PciSubDevice10B71700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B71700::NONE:               return "NONE";
        case PciSubDevice10B71700::SUBDEVICE_104380EB: return "SUBDEVICE_104380EB";
        case PciSubDevice10B71700::SUBDEVICE_10B70010: return "SUBDEVICE_10B70010";
        case PciSubDevice10B71700::SUBDEVICE_10B70020: return "SUBDEVICE_10B70020";
        case PciSubDevice10B71700::SUBDEVICE_147B1407: return "SUBDEVICE_147B1407";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10B71700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10B71700 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10B71700::SUBDEVICE_104380EB: return "A7V600/P4P800/K8V motherboard";
        case PciSubDevice10B71700::SUBDEVICE_10B70010: return "3C940 Gigabit LOM Ethernet Adapter";
        case PciSubDevice10B71700::SUBDEVICE_10B70020: return "3C941 Gigabit LOM Ethernet Adapter";
        case PciSubDevice10B71700::SUBDEVICE_147B1407: return "KV8-MAX3 motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B7_PCISUBDEVICE10B71700_H
