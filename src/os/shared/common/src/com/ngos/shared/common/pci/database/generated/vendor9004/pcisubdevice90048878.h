// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90048878_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90048878_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90048878: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90047888 = 0x90047888
};



inline const char8* enumToString(PciSubDevice90048878 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90048878::NONE:               return "NONE";
        case PciSubDevice90048878::SUBDEVICE_90047888: return "SUBDEVICE_90047888";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90048878 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90048878 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90048878::SUBDEVICE_90047888: return "AHA-2930UW SCSI Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9004_PCISUBDEVICE90048878_H
