// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F0024_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F0024_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice114F0024: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_114F0030 = 0x114F0030,
    SUBDEVICE_114F0031 = 0x114F0031
};



inline const char8* enumToString(PciSubDevice114F0024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice114F0024::NONE:               return "NONE";
        case PciSubDevice114F0024::SUBDEVICE_114F0030: return "SUBDEVICE_114F0030";
        case PciSubDevice114F0024::SUBDEVICE_114F0031: return "SUBDEVICE_114F0031";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice114F0024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice114F0024 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice114F0024::SUBDEVICE_114F0030: return "DataFire RAS BRI U Adapter";
        case PciSubDevice114F0024::SUBDEVICE_114F0031: return "DataFire RAS BRI S/T Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F0024_H
