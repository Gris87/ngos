// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A2005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104D8044 = 0x104D8044,
    SUBDEVICE_104D8045 = 0x104D8045,
    SUBDEVICE_104D8055 = 0x104D8055,
    SUBDEVICE_104D8056 = 0x104D8056,
    SUBDEVICE_104D805A = 0x104D805A,
    SUBDEVICE_104D805F = 0x104D805F,
    SUBDEVICE_104D8074 = 0x104D8074
};



inline const char8* enumToString(PciSubDevice127A2005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2005::NONE:               return "NONE";
        case PciSubDevice127A2005::SUBDEVICE_104D8044: return "SUBDEVICE_104D8044";
        case PciSubDevice127A2005::SUBDEVICE_104D8045: return "SUBDEVICE_104D8045";
        case PciSubDevice127A2005::SUBDEVICE_104D8055: return "SUBDEVICE_104D8055";
        case PciSubDevice127A2005::SUBDEVICE_104D8056: return "SUBDEVICE_104D8056";
        case PciSubDevice127A2005::SUBDEVICE_104D805A: return "SUBDEVICE_104D805A";
        case PciSubDevice127A2005::SUBDEVICE_104D805F: return "SUBDEVICE_104D805F";
        case PciSubDevice127A2005::SUBDEVICE_104D8074: return "SUBDEVICE_104D8074";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A2005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A2005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A2005::SUBDEVICE_104D8044: return "229-DFSV";
        case PciSubDevice127A2005::SUBDEVICE_104D8045: return "229-DFSV";
        case PciSubDevice127A2005::SUBDEVICE_104D8055: return "PBE/Aztech 235W-DFSV";
        case PciSubDevice127A2005::SUBDEVICE_104D8056: return "235-DFSV";
        case PciSubDevice127A2005::SUBDEVICE_104D805A: return "Modem";
        case PciSubDevice127A2005::SUBDEVICE_104D805F: return "Modem";
        case PciSubDevice127A2005::SUBDEVICE_104D8074: return "Modem";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A2005_H
