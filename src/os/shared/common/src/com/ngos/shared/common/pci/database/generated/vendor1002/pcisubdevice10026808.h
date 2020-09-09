// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026808_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026808_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026808: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020310 = 0x10020310,
    SUBDEVICE_10020420 = 0x10020420,
    SUBDEVICE_103C030C = 0x103C030C,
    SUBDEVICE_13CC3D25 = 0x13CC3D25,
    SUBDEVICE_15C3030C = 0x15C3030C
};



inline const char8* enumToString(PciSubDevice10026808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026808::NONE:               return "NONE";
        case PciSubDevice10026808::SUBDEVICE_10020310: return "SUBDEVICE_10020310";
        case PciSubDevice10026808::SUBDEVICE_10020420: return "SUBDEVICE_10020420";
        case PciSubDevice10026808::SUBDEVICE_103C030C: return "SUBDEVICE_103C030C";
        case PciSubDevice10026808::SUBDEVICE_13CC3D25: return "SUBDEVICE_13CC3D25";
        case PciSubDevice10026808::SUBDEVICE_15C3030C: return "SUBDEVICE_15C3030C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026808 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026808::SUBDEVICE_10020310: return "FirePro S7000";
        case PciSubDevice10026808::SUBDEVICE_10020420: return "Radeon Sky 500";
        case PciSubDevice10026808::SUBDEVICE_103C030C: return "MED-X7000";
        case PciSubDevice10026808::SUBDEVICE_13CC3D25: return "MXRT-7500";
        case PciSubDevice10026808::SUBDEVICE_15C3030C: return "MED-X7000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026808_H
