// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0049_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0049_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C0049: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C0049 = 0x117C0049,
    SUBDEVICE_117C004A = 0x117C004A,
    SUBDEVICE_117C004B = 0x117C004B,
    SUBDEVICE_117C004C = 0x117C004C,
    SUBDEVICE_117C004D = 0x117C004D,
    SUBDEVICE_117C004E = 0x117C004E
};



inline const char8* enumToString(PciSubDevice117C0049 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0049::NONE:               return "NONE";
        case PciSubDevice117C0049::SUBDEVICE_117C0049: return "SUBDEVICE_117C0049";
        case PciSubDevice117C0049::SUBDEVICE_117C004A: return "SUBDEVICE_117C004A";
        case PciSubDevice117C0049::SUBDEVICE_117C004B: return "SUBDEVICE_117C004B";
        case PciSubDevice117C0049::SUBDEVICE_117C004C: return "SUBDEVICE_117C004C";
        case PciSubDevice117C0049::SUBDEVICE_117C004D: return "SUBDEVICE_117C004D";
        case PciSubDevice117C0049::SUBDEVICE_117C004E: return "SUBDEVICE_117C004E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C0049 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C0049 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0049::SUBDEVICE_117C0049: return "ExpressSAS R680";
        case PciSubDevice117C0049::SUBDEVICE_117C004A: return "ExpressSAS R608";
        case PciSubDevice117C0049::SUBDEVICE_117C004B: return "ExpressSAS R60F";
        case PciSubDevice117C0049::SUBDEVICE_117C004C: return "ExpressSAS R6F0";
        case PciSubDevice117C0049::SUBDEVICE_117C004D: return "ExpressSAS R644";
        case PciSubDevice117C0049::SUBDEVICE_117C004E: return "ExpressSAS R648";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0049_H
