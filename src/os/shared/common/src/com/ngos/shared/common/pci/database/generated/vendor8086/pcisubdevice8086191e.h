// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086191E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086191E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086191E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102806D6 = 0x102806D6,
    SUBDEVICE_102806E6 = 0x102806E6
};



inline const char8* enumToString(PciSubDevice8086191E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086191E::NONE:               return "NONE";
        case PciSubDevice8086191E::SUBDEVICE_102806D6: return "SUBDEVICE_102806D6";
        case PciSubDevice8086191E::SUBDEVICE_102806E6: return "SUBDEVICE_102806E6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086191E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086191E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086191E::SUBDEVICE_102806D6: return "Latitude 7275 tablet";
        case PciSubDevice8086191E::SUBDEVICE_102806E6: return "Latitude 11 5175 2-in-1";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086191E_H
