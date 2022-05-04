// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00C5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00C5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C00C5: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C00C6 = 0x117C00C6,
    SUBDEVICE_117C00C7 = 0x117C00C7
};



inline const char8* enumToString(PciSubDevice117C00C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C00C5::NONE:               return "NONE";
        case PciSubDevice117C00C5::SUBDEVICE_117C00C6: return "SUBDEVICE_117C00C6";
        case PciSubDevice117C00C5::SUBDEVICE_117C00C7: return "SUBDEVICE_117C00C7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C00C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C00C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C00C5::SUBDEVICE_117C00C6: return "ExpressNVM S48F PCIe Gen4";
        case PciSubDevice117C00C5::SUBDEVICE_117C00C7: return "ExpressNVM S468 PCIe Gen4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00C5_H
