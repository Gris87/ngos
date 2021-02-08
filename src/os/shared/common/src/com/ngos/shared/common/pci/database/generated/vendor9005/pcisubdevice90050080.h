// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050080_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050080_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050080: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11E2A0 = 0x0E11E2A0,
    SUBDEVICE_90056220 = 0x90056220,
    SUBDEVICE_900562A0 = 0x900562A0,
    SUBDEVICE_9005E220 = 0x9005E220,
    SUBDEVICE_9005E2A0 = 0x9005E2A0
};



inline const char8* enumToString(PciSubDevice90050080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050080::NONE:               return "NONE";
        case PciSubDevice90050080::SUBDEVICE_0E11E2A0: return "SUBDEVICE_0E11E2A0";
        case PciSubDevice90050080::SUBDEVICE_90056220: return "SUBDEVICE_90056220";
        case PciSubDevice90050080::SUBDEVICE_900562A0: return "SUBDEVICE_900562A0";
        case PciSubDevice90050080::SUBDEVICE_9005E220: return "SUBDEVICE_9005E220";
        case PciSubDevice90050080::SUBDEVICE_9005E2A0: return "SUBDEVICE_9005E2A0";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050080 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050080::SUBDEVICE_0E11E2A0: return "Compaq 64-Bit/66MHz Wide Ultra3 SCSI Adapter";
        case PciSubDevice90050080::SUBDEVICE_90056220: return "AHA-29160C";
        case PciSubDevice90050080::SUBDEVICE_900562A0: return "29160N Ultra160 SCSI Controller";
        case PciSubDevice90050080::SUBDEVICE_9005E220: return "29160LP Low Profile Ultra160 SCSI Controller";
        case PciSubDevice90050080::SUBDEVICE_9005E2A0: return "29160 Ultra160 SCSI Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050080_H
