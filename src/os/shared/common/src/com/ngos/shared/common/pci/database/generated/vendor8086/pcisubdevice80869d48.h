// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D48_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D48_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80869D48: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102806DC = 0x102806DC,
    SUBDEVICE_102806F3 = 0x102806F3,
    SUBDEVICE_103C8079 = 0x103C8079
};



inline const char8* enumToString(PciSubDevice80869D48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869D48::NONE:               return "NONE";
        case PciSubDevice80869D48::SUBDEVICE_102806DC: return "SUBDEVICE_102806DC";
        case PciSubDevice80869D48::SUBDEVICE_102806F3: return "SUBDEVICE_102806F3";
        case PciSubDevice80869D48::SUBDEVICE_103C8079: return "SUBDEVICE_103C8079";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80869D48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80869D48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869D48::SUBDEVICE_102806DC: return "Latitude E7470";
        case PciSubDevice80869D48::SUBDEVICE_102806F3: return "Latitude 3570";
        case PciSubDevice80869D48::SUBDEVICE_103C8079: return "EliteBook 840 G3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D48_H
