// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCISUBDEVICE13190802_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCISUBDEVICE13190802_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice13190802: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13191319 = 0x13191319
};



inline const char8* enumToString(PciSubDevice13190802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13190802::NONE:               return "NONE";
        case PciSubDevice13190802::SUBDEVICE_13191319: return "SUBDEVICE_13191319";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice13190802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice13190802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice13190802::SUBDEVICE_13191319: return "FM801 PCI Joystick";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1319_PCISUBDEVICE13190802_H
