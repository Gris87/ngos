// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E022_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E022_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E022: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11332200 = 0x11332200,
    SUBDEVICE_1133E022 = 0x1133E022
};



inline const char8* enumToString(PciSubDevice1133E022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E022::NONE:               return "NONE";
        case PciSubDevice1133E022::SUBDEVICE_11332200: return "SUBDEVICE_11332200";
        case PciSubDevice1133E022::SUBDEVICE_1133E022: return "SUBDEVICE_1133E022";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E022 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E022::SUBDEVICE_11332200: return "Diva V-Analog-2 PCI v1";
        case PciSubDevice1133E022::SUBDEVICE_1133E022: return "Diva Analog-2 PCI v1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E022_H
