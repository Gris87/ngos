// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050412_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050412_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice90050412: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90050412 = 0x90050412,
    SUBDEVICE_90050413 = 0x90050413
};



inline const char8* enumToString(PciSubDevice90050412 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050412::NONE:               return "NONE";
        case PciSubDevice90050412::SUBDEVICE_90050412: return "SUBDEVICE_90050412";
        case PciSubDevice90050412::SUBDEVICE_90050413: return "SUBDEVICE_90050413";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice90050412 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice90050412 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice90050412::SUBDEVICE_90050412: return "ASC-48300 (Spirit non-RAID)";
        case PciSubDevice90050412::SUBDEVICE_90050413: return "ASC-58300 (Oakmont non-RAID)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE90050412_H
