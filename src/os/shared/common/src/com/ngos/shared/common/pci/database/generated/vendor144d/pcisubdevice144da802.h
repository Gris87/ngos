// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA802_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA802_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice144DA802: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_144DA801 = 0x144DA801
};



inline const char8* enumToString(PciSubDevice144DA802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA802::NONE:               return "NONE";
        case PciSubDevice144DA802::SUBDEVICE_144DA801: return "SUBDEVICE_144DA801";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice144DA802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice144DA802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice144DA802::SUBDEVICE_144DA801: return "PM963 2.5\" NVMe PCIe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR144D_PCISUBDEVICE144DA802_H
