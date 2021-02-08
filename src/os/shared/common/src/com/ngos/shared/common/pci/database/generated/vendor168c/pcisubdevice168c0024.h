// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0024_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0024_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0024: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_106B0087 = 0x106B0087,
    SUBDEVICE_11863A70 = 0x11863A70
};



inline const char8* enumToString(PciSubDevice168C0024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0024::NONE:               return "NONE";
        case PciSubDevice168C0024::SUBDEVICE_106B0087: return "SUBDEVICE_106B0087";
        case PciSubDevice168C0024::SUBDEVICE_11863A70: return "SUBDEVICE_11863A70";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0024::SUBDEVICE_106B0087: return "AirPort Extreme";
        case PciSubDevice168C0024::SUBDEVICE_11863A70: return "DWA-556 Xtreme N PCI Express Desktop Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0024_H
