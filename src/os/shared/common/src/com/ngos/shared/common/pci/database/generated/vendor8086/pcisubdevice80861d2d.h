// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861D2D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861D2D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861D2D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102804F7 = 0x102804F7,
    SUBDEVICE_103C18A9 = 0x103C18A9,
    SUBDEVICE_15D9066B = 0x15D9066B
};



inline const char8* enumToString(PciSubDevice80861D2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861D2D::NONE:               return "NONE";
        case PciSubDevice80861D2D::SUBDEVICE_102804F7: return "SUBDEVICE_102804F7";
        case PciSubDevice80861D2D::SUBDEVICE_103C18A9: return "SUBDEVICE_103C18A9";
        case PciSubDevice80861D2D::SUBDEVICE_15D9066B: return "SUBDEVICE_15D9066B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861D2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861D2D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861D2D::SUBDEVICE_102804F7: return "C602J on PowerEdge R320 server";
        case PciSubDevice80861D2D::SUBDEVICE_103C18A9: return "HP DL360e G8";
        case PciSubDevice80861D2D::SUBDEVICE_15D9066B: return "X9SRL-F";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861D2D_H
