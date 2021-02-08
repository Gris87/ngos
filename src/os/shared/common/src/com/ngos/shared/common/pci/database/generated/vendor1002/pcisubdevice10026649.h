// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026649_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026649_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10026649: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020B0C = 0x10020B0C,
    SUBDEVICE_103C0B0C = 0x103C0B0C,
    SUBDEVICE_103C230C = 0x103C230C,
    SUBDEVICE_13CC3D2A = 0x13CC3D2A
};



inline const char8* enumToString(PciSubDevice10026649 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026649::NONE:               return "NONE";
        case PciSubDevice10026649::SUBDEVICE_10020B0C: return "SUBDEVICE_10020B0C";
        case PciSubDevice10026649::SUBDEVICE_103C0B0C: return "SUBDEVICE_103C0B0C";
        case PciSubDevice10026649::SUBDEVICE_103C230C: return "SUBDEVICE_103C230C";
        case PciSubDevice10026649::SUBDEVICE_13CC3D2A: return "SUBDEVICE_13CC3D2A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10026649 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10026649 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10026649::SUBDEVICE_10020B0C: return "FirePro W4300";
        case PciSubDevice10026649::SUBDEVICE_103C0B0C: return "Bonaire [FirePro W4300]";
        case PciSubDevice10026649::SUBDEVICE_103C230C: return "FirePro W5100";
        case PciSubDevice10026649::SUBDEVICE_13CC3D2A: return "MXRT-5600";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10026649_H
