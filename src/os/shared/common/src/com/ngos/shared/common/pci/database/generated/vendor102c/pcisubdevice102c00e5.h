// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C00E5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C00E5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102C00E5: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E11B049 = 0x0E11B049,
    SUBDEVICE_11790001 = 0x11790001
};



inline const char8* enumToString(PciSubDevice102C00E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102C00E5::NONE:               return "NONE";
        case PciSubDevice102C00E5::SUBDEVICE_0E11B049: return "SUBDEVICE_0E11B049";
        case PciSubDevice102C00E5::SUBDEVICE_11790001: return "SUBDEVICE_11790001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102C00E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102C00E5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102C00E5::SUBDEVICE_0E11B049: return "Armada 1700 Laptop Display Controller";
        case PciSubDevice102C00E5::SUBDEVICE_11790001: return "Satellite Pro/Satellite";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C00E5_H
