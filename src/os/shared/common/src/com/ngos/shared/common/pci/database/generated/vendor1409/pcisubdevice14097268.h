// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCISUBDEVICE14097268_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCISUBDEVICE14097268_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14097268: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14090103 = 0x14090103,
    SUBDEVICE_14090104 = 0x14090104
};



inline const char8* enumToString(PciSubDevice14097268 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14097268::NONE:               return "NONE";
        case PciSubDevice14097268::SUBDEVICE_14090103: return "SUBDEVICE_14090103";
        case PciSubDevice14097268::SUBDEVICE_14090104: return "SUBDEVICE_14090104";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14097268 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14097268 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14097268::SUBDEVICE_14090103: return "PAR4008A";
        case PciSubDevice14097268::SUBDEVICE_14090104: return "PAR4018A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1409_PCISUBDEVICE14097268_H
