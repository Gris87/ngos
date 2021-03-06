// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1394_PCISUBDEVICE13940001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1394_PCISUBDEVICE13940001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13940001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11864800 = 0x11864800,
    SUBDEVICE_13940001 = 0x13940001
};



inline const char8* enumToString(PciSubDevice13940001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13940001::NONE:               return "NONE";
        case PciSubDevice13940001::SUBDEVICE_11864800: return "SUBDEVICE_11864800";
        case PciSubDevice13940001::SUBDEVICE_13940001: return "SUBDEVICE_13940001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13940001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13940001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13940001::SUBDEVICE_11864800: return "DGE-500SX";
        case PciSubDevice13940001::SUBDEVICE_13940001: return "NetCelerator Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1394_PCISUBDEVICE13940001_H
