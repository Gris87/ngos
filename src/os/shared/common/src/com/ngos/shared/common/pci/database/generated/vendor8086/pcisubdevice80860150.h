// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860150_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860150_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860150: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104384CA = 0x104384CA,
    SUBDEVICE_1458D000 = 0x1458D000,
    SUBDEVICE_15D90624 = 0x15D90624,
    SUBDEVICE_18490150 = 0x18490150
};



inline const char8* enumToString(PciSubDevice80860150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860150::NONE:               return "NONE";
        case PciSubDevice80860150::SUBDEVICE_104384CA: return "SUBDEVICE_104384CA";
        case PciSubDevice80860150::SUBDEVICE_1458D000: return "SUBDEVICE_1458D000";
        case PciSubDevice80860150::SUBDEVICE_15D90624: return "SUBDEVICE_15D90624";
        case PciSubDevice80860150::SUBDEVICE_18490150: return "SUBDEVICE_18490150";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860150 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860150::SUBDEVICE_104384CA: return "P8 series motherboard";
        case PciSubDevice80860150::SUBDEVICE_1458D000: return "Ivy Bridge GT1 [HD Graphics]";
        case PciSubDevice80860150::SUBDEVICE_15D90624: return "X9SCM-F Motherboard";
        case PciSubDevice80860150::SUBDEVICE_18490150: return "Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860150_H
