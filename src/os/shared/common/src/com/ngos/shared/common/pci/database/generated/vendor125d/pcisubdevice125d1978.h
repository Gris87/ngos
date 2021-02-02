// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1978_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1978_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice125D1978: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B112 = 0x0E11B112,
    SUBDEVICE_1033803C = 0x1033803C,
    SUBDEVICE_10338058 = 0x10338058,
    SUBDEVICE_10924000 = 0x10924000,
    SUBDEVICE_11790001 = 0x11790001
};



inline const char8* enumToString(PciSubDevice125D1978 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1978::NONE:               return "NONE";
        case PciSubDevice125D1978::SUBDEVICE_0E11B112: return "SUBDEVICE_0E11B112";
        case PciSubDevice125D1978::SUBDEVICE_1033803C: return "SUBDEVICE_1033803C";
        case PciSubDevice125D1978::SUBDEVICE_10338058: return "SUBDEVICE_10338058";
        case PciSubDevice125D1978::SUBDEVICE_10924000: return "SUBDEVICE_10924000";
        case PciSubDevice125D1978::SUBDEVICE_11790001: return "SUBDEVICE_11790001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice125D1978 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice125D1978 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice125D1978::SUBDEVICE_0E11B112: return "Armada M700/E500";
        case PciSubDevice125D1978::SUBDEVICE_1033803C: return "ES1978 Maestro-2E Audiodrive";
        case PciSubDevice125D1978::SUBDEVICE_10338058: return "ES1978 Maestro-2E Audiodrive";
        case PciSubDevice125D1978::SUBDEVICE_10924000: return "Monster Sound MX400";
        case PciSubDevice125D1978::SUBDEVICE_11790001: return "ES1978 Maestro-2E Audiodrive";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR125D_PCISUBDEVICE125D1978_H
