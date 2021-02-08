// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1005: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438451 = 0x10438451,
    SUBDEVICE_10DE1035 = 0x10DE1035,
    SUBDEVICE_38422790 = 0x38422790,
    SUBDEVICE_38422791 = 0x38422791,
    SUBDEVICE_38422793 = 0x38422793,
    SUBDEVICE_38422794 = 0x38422794,
    SUBDEVICE_38422795 = 0x38422795
};



inline const char8* enumToString(PciSubDevice10DE1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1005::NONE:               return "NONE";
        case PciSubDevice10DE1005::SUBDEVICE_10438451: return "SUBDEVICE_10438451";
        case PciSubDevice10DE1005::SUBDEVICE_10DE1035: return "SUBDEVICE_10DE1035";
        case PciSubDevice10DE1005::SUBDEVICE_38422790: return "SUBDEVICE_38422790";
        case PciSubDevice10DE1005::SUBDEVICE_38422791: return "SUBDEVICE_38422791";
        case PciSubDevice10DE1005::SUBDEVICE_38422793: return "SUBDEVICE_38422793";
        case PciSubDevice10DE1005::SUBDEVICE_38422794: return "SUBDEVICE_38422794";
        case PciSubDevice10DE1005::SUBDEVICE_38422795: return "SUBDEVICE_38422795";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1005::SUBDEVICE_10438451: return "GTXTITAN-6GD5";
        case PciSubDevice10DE1005::SUBDEVICE_10DE1035: return "GeForce GTX Titan";
        case PciSubDevice10DE1005::SUBDEVICE_38422790: return "GeForce GTX Titan";
        case PciSubDevice10DE1005::SUBDEVICE_38422791: return "GeForce GTX Titan SC";
        case PciSubDevice10DE1005::SUBDEVICE_38422793: return "GeForce GTX Titan SC Signature";
        case PciSubDevice10DE1005::SUBDEVICE_38422794: return "GeForce GTX Titan SC Hydro Copper";
        case PciSubDevice10DE1005::SUBDEVICE_38422795: return "GeForce GTX Titan SC Hydro Copper Signature";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1005_H
