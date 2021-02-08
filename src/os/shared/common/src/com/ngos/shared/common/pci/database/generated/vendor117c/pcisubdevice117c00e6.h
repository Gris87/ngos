// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00E6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00E6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C00E6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C00C0 = 0x117C00C0,
    SUBDEVICE_117C00C1 = 0x117C00C1,
    SUBDEVICE_117C00C2 = 0x117C00C2,
    SUBDEVICE_117C00C3 = 0x117C00C3,
    SUBDEVICE_117C00C4 = 0x117C00C4
};



inline const char8* enumToString(PciSubDevice117C00E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C00E6::NONE:               return "NONE";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C0: return "SUBDEVICE_117C00C0";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C1: return "SUBDEVICE_117C00C1";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C2: return "SUBDEVICE_117C00C2";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C3: return "SUBDEVICE_117C00C3";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C4: return "SUBDEVICE_117C00C4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C00E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C00E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C00E6::SUBDEVICE_117C00C0: return "ExpressSAS H1280 GT";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C1: return "ExpressSAS H1208 GT";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C2: return "ExpressSAS H1244 GT";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C3: return "ExpressSAS H12F0 GT";
        case PciSubDevice117C00E6::SUBDEVICE_117C00C4: return "ExpressSAS H120F GT";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C00E6_H
