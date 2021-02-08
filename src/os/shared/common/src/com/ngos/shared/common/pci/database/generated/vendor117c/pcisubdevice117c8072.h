// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C8072_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C8072_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C8072: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C0072 = 0x117C0072,
    SUBDEVICE_117C0073 = 0x117C0073,
    SUBDEVICE_117C0082 = 0x117C0082
};



inline const char8* enumToString(PciSubDevice117C8072 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C8072::NONE:               return "NONE";
        case PciSubDevice117C8072::SUBDEVICE_117C0072: return "SUBDEVICE_117C0072";
        case PciSubDevice117C8072::SUBDEVICE_117C0073: return "SUBDEVICE_117C0073";
        case PciSubDevice117C8072::SUBDEVICE_117C0082: return "SUBDEVICE_117C0082";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C8072 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C8072 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C8072::SUBDEVICE_117C0072: return "ExpressSAS H12F0";
        case PciSubDevice117C8072::SUBDEVICE_117C0073: return "ExpressSAS H120F";
        case PciSubDevice117C8072::SUBDEVICE_117C0082: return "ExpressSAS H1288";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C8072_H
