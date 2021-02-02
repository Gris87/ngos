// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050010_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050010: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90052180 = 0x90052180,
    SUBDEVICE_90058100 = 0x90058100,
    SUBDEVICE_9005A100 = 0x9005A100,
    SUBDEVICE_9005A180 = 0x9005A180,
    SUBDEVICE_9005E100 = 0x9005E100
};



inline const char8* enumToString(PciSubDevice90050010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050010::NONE:               return "NONE";
        case PciSubDevice90050010::SUBDEVICE_90052180: return "SUBDEVICE_90052180";
        case PciSubDevice90050010::SUBDEVICE_90058100: return "SUBDEVICE_90058100";
        case PciSubDevice90050010::SUBDEVICE_9005A100: return "SUBDEVICE_9005A100";
        case PciSubDevice90050010::SUBDEVICE_9005A180: return "SUBDEVICE_9005A180";
        case PciSubDevice90050010::SUBDEVICE_9005E100: return "SUBDEVICE_9005E100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050010::SUBDEVICE_90052180: return "AHA-2940U2 SCSI Controller";
        case PciSubDevice90050010::SUBDEVICE_90058100: return "AHA-2940U2B SCSI Controller";
        case PciSubDevice90050010::SUBDEVICE_9005A100: return "AHA-2940U2B SCSI Controller";
        case PciSubDevice90050010::SUBDEVICE_9005A180: return "AIC-3860Q [AHA-2940U2W/GE] SCSI Controller";
        case PciSubDevice90050010::SUBDEVICE_9005E100: return "AHA-2950U2B SCSI Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050010_H
