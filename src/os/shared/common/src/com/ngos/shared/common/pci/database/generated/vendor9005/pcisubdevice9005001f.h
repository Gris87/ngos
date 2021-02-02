// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005001F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005001F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice9005001F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_9005000F = 0x9005000F,
    SUBDEVICE_9005A180 = 0x9005A180
};



inline const char8* enumToString(PciSubDevice9005001F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005001F::NONE:               return "NONE";
        case PciSubDevice9005001F::SUBDEVICE_9005000F: return "SUBDEVICE_9005000F";
        case PciSubDevice9005001F::SUBDEVICE_9005A180: return "SUBDEVICE_9005A180";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice9005001F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice9005001F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005001F::SUBDEVICE_9005000F: return "2940U2W SCSI Controller";
        case PciSubDevice9005001F::SUBDEVICE_9005A180: return "2940U2W SCSI Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005001F_H
