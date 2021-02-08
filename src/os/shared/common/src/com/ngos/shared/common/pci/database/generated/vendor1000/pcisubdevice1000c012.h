// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000C012_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000C012_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1000C012: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1D490003 = 0x1D490003
};



inline const char8* enumToString(PciSubDevice1000C012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000C012::NONE:               return "NONE";
        case PciSubDevice1000C012::SUBDEVICE_1D490003: return "SUBDEVICE_1D490003";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1000C012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1000C012 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1000C012::SUBDEVICE_1D490003: return "ThinkSystem 1611-8P PCIe Gen4 NVMe Switch Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE1000C012_H
