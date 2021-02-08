// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050053_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050053_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050053: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_9005FFFF = 0x9005FFFF
};



inline const char8* enumToString(PciSubDevice90050053 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050053::NONE:               return "NONE";
        case PciSubDevice90050053::SUBDEVICE_9005FFFF: return "SUBDEVICE_9005FFFF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050053 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050053 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050053::SUBDEVICE_9005FFFF: return "AIC-7896 SCSI Controller mainboard implementation";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050053_H
