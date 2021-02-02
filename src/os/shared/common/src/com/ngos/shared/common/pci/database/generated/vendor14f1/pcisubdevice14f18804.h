// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18804_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18804_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F18804: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00706902 = 0x00706902,
    SUBDEVICE_00709002 = 0x00709002,
    SUBDEVICE_00709402 = 0x00709402,
    SUBDEVICE_70635500 = 0x70635500
};



inline const char8* enumToString(PciSubDevice14F18804 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18804::NONE:               return "NONE";
        case PciSubDevice14F18804::SUBDEVICE_00706902: return "SUBDEVICE_00706902";
        case PciSubDevice14F18804::SUBDEVICE_00709002: return "SUBDEVICE_00709002";
        case PciSubDevice14F18804::SUBDEVICE_00709402: return "SUBDEVICE_00709402";
        case PciSubDevice14F18804::SUBDEVICE_70635500: return "SUBDEVICE_70635500";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F18804 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F18804 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18804::SUBDEVICE_00706902: return "WinTV HVR-4000-HD";
        case PciSubDevice14F18804::SUBDEVICE_00709002: return "Nova-T DVB-T Model 909";
        case PciSubDevice14F18804::SUBDEVICE_00709402: return "WinTV-HVR1100 DVB-T/Hybrid";
        case PciSubDevice14F18804::SUBDEVICE_70635500: return "pcHDTV HD-5500";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18804_H
