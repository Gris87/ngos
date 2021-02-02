// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086088E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086088E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086088E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80864060 = 0x80864060,
    SUBDEVICE_80864460 = 0x80864460
};



inline const char8* enumToString(PciSubDevice8086088E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086088E::NONE:               return "NONE";
        case PciSubDevice8086088E::SUBDEVICE_80864060: return "SUBDEVICE_80864060";
        case PciSubDevice8086088E::SUBDEVICE_80864460: return "SUBDEVICE_80864460";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086088E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086088E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086088E::SUBDEVICE_80864060: return "Centrino Advanced-N 6235 AGN";
        case PciSubDevice8086088E::SUBDEVICE_80864460: return "Centrino Advanced-N 6235 AGN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086088E_H
