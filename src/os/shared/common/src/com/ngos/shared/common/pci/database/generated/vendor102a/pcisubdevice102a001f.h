// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A001F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A001F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102A001F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_9005000F = 0x9005000F,
    SUBDEVICE_90050106 = 0x90050106,
    SUBDEVICE_9005A180 = 0x9005A180
};



inline const char8* enumToString(PciSubDevice102A001F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102A001F::NONE:               return "NONE";
        case PciSubDevice102A001F::SUBDEVICE_9005000F: return "SUBDEVICE_9005000F";
        case PciSubDevice102A001F::SUBDEVICE_90050106: return "SUBDEVICE_90050106";
        case PciSubDevice102A001F::SUBDEVICE_9005A180: return "SUBDEVICE_9005A180";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102A001F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102A001F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102A001F::SUBDEVICE_9005000F: return "2940U2W SCSI Controller";
        case PciSubDevice102A001F::SUBDEVICE_90050106: return "2940U2W SCSI Controller";
        case PciSubDevice102A001F::SUBDEVICE_9005A180: return "2940U2W SCSI Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102A_PCISUBDEVICE102A001F_H
