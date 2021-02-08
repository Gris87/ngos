// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086109E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086109E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086109E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_8086A01F = 0x8086A01F,
    SUBDEVICE_8086A11F = 0x8086A11F
};



inline const char8* enumToString(PciSubDevice8086109E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086109E::NONE:               return "NONE";
        case PciSubDevice8086109E::SUBDEVICE_8086A01F: return "SUBDEVICE_8086A01F";
        case PciSubDevice8086109E::SUBDEVICE_8086A11F: return "SUBDEVICE_8086A11F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086109E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086109E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086109E::SUBDEVICE_8086A01F: return "PRO/10GbE CX4 Server Adapter";
        case PciSubDevice8086109E::SUBDEVICE_8086A11F: return "PRO/10GbE CX4 Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086109E_H
