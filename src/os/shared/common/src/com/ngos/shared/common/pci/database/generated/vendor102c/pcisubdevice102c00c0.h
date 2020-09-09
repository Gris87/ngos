// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C00C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C00C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102C00C0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102C00C0 = 0x102C00C0,
    SUBDEVICE_4C531000 = 0x4C531000,
    SUBDEVICE_4C531010 = 0x4C531010,
    SUBDEVICE_4C531020 = 0x4C531020,
    SUBDEVICE_4C531030 = 0x4C531030,
    SUBDEVICE_4C531050 = 0x4C531050,
    SUBDEVICE_4C531051 = 0x4C531051
};



inline const char8* enumToString(PciSubDevice102C00C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102C00C0::NONE:               return "NONE";
        case PciSubDevice102C00C0::SUBDEVICE_102C00C0: return "SUBDEVICE_102C00C0";
        case PciSubDevice102C00C0::SUBDEVICE_4C531000: return "SUBDEVICE_4C531000";
        case PciSubDevice102C00C0::SUBDEVICE_4C531010: return "SUBDEVICE_4C531010";
        case PciSubDevice102C00C0::SUBDEVICE_4C531020: return "SUBDEVICE_4C531020";
        case PciSubDevice102C00C0::SUBDEVICE_4C531030: return "SUBDEVICE_4C531030";
        case PciSubDevice102C00C0::SUBDEVICE_4C531050: return "SUBDEVICE_4C531050";
        case PciSubDevice102C00C0::SUBDEVICE_4C531051: return "SUBDEVICE_4C531051";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102C00C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102C00C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102C00C0::SUBDEVICE_102C00C0: return "F69000 HiQVideo";
        case PciSubDevice102C00C0::SUBDEVICE_4C531000: return "CC7/CR7/CP7/VC7/VP7/VR7 mainboard";
        case PciSubDevice102C00C0::SUBDEVICE_4C531010: return "CP5/CR6 mainboard";
        case PciSubDevice102C00C0::SUBDEVICE_4C531020: return "VR6 mainboard";
        case PciSubDevice102C00C0::SUBDEVICE_4C531030: return "PC5 mainboard";
        case PciSubDevice102C00C0::SUBDEVICE_4C531050: return "CT7 mainboard";
        case PciSubDevice102C00C0::SUBDEVICE_4C531051: return "CE7 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102C_PCISUBDEVICE102C00C0_H
