// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50212_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50212_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E50212: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E5D303 = 0x19E5D303,
    SUBDEVICE_19E5D306 = 0x19E5D306
};



inline const char8* enumToString(PciSubDevice19E50212 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50212::NONE:               return "NONE";
        case PciSubDevice19E50212::SUBDEVICE_19E5D303: return "SUBDEVICE_19E5D303";
        case PciSubDevice19E50212::SUBDEVICE_19E5D306: return "SUBDEVICE_19E5D306";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E50212 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E50212 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50212::SUBDEVICE_19E5D303: return "Hi1822 SP522 (2*8G FC)";
        case PciSubDevice19E50212::SUBDEVICE_19E5D306: return "Hi1822 SP523 (2*8G FC)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50212_H
