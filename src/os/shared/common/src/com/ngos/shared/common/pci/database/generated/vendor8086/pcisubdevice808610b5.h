// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610B5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610B5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808610B5: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C3109 = 0x103C3109,
    SUBDEVICE_80861099 = 0x80861099,
    SUBDEVICE_80861199 = 0x80861199
};



inline const char8* enumToString(PciSubDevice808610B5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610B5::NONE:               return "NONE";
        case PciSubDevice808610B5::SUBDEVICE_103C3109: return "SUBDEVICE_103C3109";
        case PciSubDevice808610B5::SUBDEVICE_80861099: return "SUBDEVICE_80861099";
        case PciSubDevice808610B5::SUBDEVICE_80861199: return "SUBDEVICE_80861199";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808610B5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808610B5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808610B5::SUBDEVICE_103C3109: return "NC340T PCI-X Quad-port Gigabit Server Adapter";
        case PciSubDevice808610B5::SUBDEVICE_80861099: return "PRO/1000 GT Quad Port Server Adapter";
        case PciSubDevice808610B5::SUBDEVICE_80861199: return "PRO/1000 GT Quad Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808610B5_H
