// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0094_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0094_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C0094: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C0094 = 0x117C0094,
    SUBDEVICE_117C00A0 = 0x117C00A0,
    SUBDEVICE_117C00A1 = 0x117C00A1,
    SUBDEVICE_117C00A2 = 0x117C00A2,
    SUBDEVICE_117C00A3 = 0x117C00A3,
    SUBDEVICE_117C00AC = 0x117C00AC
};



inline const char8* enumToString(PciSubDevice117C0094 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0094::NONE:               return "NONE";
        case PciSubDevice117C0094::SUBDEVICE_117C0094: return "SUBDEVICE_117C0094";
        case PciSubDevice117C0094::SUBDEVICE_117C00A0: return "SUBDEVICE_117C00A0";
        case PciSubDevice117C0094::SUBDEVICE_117C00A1: return "SUBDEVICE_117C00A1";
        case PciSubDevice117C0094::SUBDEVICE_117C00A2: return "SUBDEVICE_117C00A2";
        case PciSubDevice117C0094::SUBDEVICE_117C00A3: return "SUBDEVICE_117C00A3";
        case PciSubDevice117C0094::SUBDEVICE_117C00AC: return "SUBDEVICE_117C00AC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C0094 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C0094 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0094::SUBDEVICE_117C0094: return "Celerity FC-162P";
        case PciSubDevice117C0094::SUBDEVICE_117C00A0: return "Celerity FC-161P";
        case PciSubDevice117C0094::SUBDEVICE_117C00A1: return "Celerity FC-164P";
        case PciSubDevice117C0094::SUBDEVICE_117C00A2: return "Celerity FC-321E";
        case PciSubDevice117C0094::SUBDEVICE_117C00A3: return "Celerity FC-322E";
        case PciSubDevice117C0094::SUBDEVICE_117C00AC: return "Celerity FC-324E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0094_H
