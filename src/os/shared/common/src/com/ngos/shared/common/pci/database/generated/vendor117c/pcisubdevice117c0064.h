// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0064_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0064_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice117C0064: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_117C0063 = 0x117C0063,
    SUBDEVICE_117C0064 = 0x117C0064,
    SUBDEVICE_117C0065 = 0x117C0065
};



inline const char8* enumToString(PciSubDevice117C0064 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0064::NONE:               return "NONE";
        case PciSubDevice117C0064::SUBDEVICE_117C0063: return "SUBDEVICE_117C0063";
        case PciSubDevice117C0064::SUBDEVICE_117C0064: return "SUBDEVICE_117C0064";
        case PciSubDevice117C0064::SUBDEVICE_117C0065: return "SUBDEVICE_117C0065";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice117C0064 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice117C0064 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice117C0064::SUBDEVICE_117C0063: return "Celerity FC-161E";
        case PciSubDevice117C0064::SUBDEVICE_117C0064: return "Celerity FC-162E";
        case PciSubDevice117C0064::SUBDEVICE_117C0065: return "Celerity FC-164E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR117C_PCISUBDEVICE117C0064_H
