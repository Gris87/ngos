// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A2F0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A2F0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086A2F0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14627A72 = 0x14627A72,
    SUBDEVICE_1462FA72 = 0x1462FA72
};



inline const char8* enumToString(PciSubDevice8086A2F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086A2F0::NONE:               return "NONE";
        case PciSubDevice8086A2F0::SUBDEVICE_14627A72: return "SUBDEVICE_14627A72";
        case PciSubDevice8086A2F0::SUBDEVICE_1462FA72: return "SUBDEVICE_1462FA72";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086A2F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086A2F0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086A2F0::SUBDEVICE_14627A72: return "H270 PC MATE";
        case PciSubDevice8086A2F0::SUBDEVICE_1462FA72: return "H270 PC MATE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086A2F0_H
