// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026809_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026809_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026809: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13CC3D23 = 0x13CC3D23,
    SUBDEVICE_13CC3D24 = 0x13CC3D24,
    SUBDEVICE_15C30B06 = 0x15C30B06
};



inline const char8* enumToString(PciSubDevice10026809 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026809::NONE:               return "NONE";
        case PciSubDevice10026809::SUBDEVICE_13CC3D23: return "SUBDEVICE_13CC3D23";
        case PciSubDevice10026809::SUBDEVICE_13CC3D24: return "SUBDEVICE_13CC3D24";
        case PciSubDevice10026809::SUBDEVICE_15C30B06: return "SUBDEVICE_15C30B06";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026809 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026809 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026809::SUBDEVICE_13CC3D23: return "MXRT-5500";
        case PciSubDevice10026809::SUBDEVICE_13CC3D24: return "MXRT-5550";
        case PciSubDevice10026809::SUBDEVICE_15C30B06: return "MED-X5000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026809_H
