// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005008F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005008F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice9005008F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11790001 = 0x11790001,
    SUBDEVICE_15D99005 = 0x15D99005
};



inline const char8* enumToString(PciSubDevice9005008F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005008F::NONE:               return "NONE";
        case PciSubDevice9005008F::SUBDEVICE_11790001: return "SUBDEVICE_11790001";
        case PciSubDevice9005008F::SUBDEVICE_15D99005: return "SUBDEVICE_15D99005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice9005008F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice9005008F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005008F::SUBDEVICE_11790001: return "Magnia Z310";
        case PciSubDevice9005008F::SUBDEVICE_15D99005: return "Onboard SCSI Host Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005008F_H
