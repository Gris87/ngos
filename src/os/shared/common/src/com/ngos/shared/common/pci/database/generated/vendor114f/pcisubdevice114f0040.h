// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F0040_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F0040_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice114F0040: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_114F0042 = 0x114F0042,
    SUBDEVICE_114F0043 = 0x114F0043,
    SUBDEVICE_114F0044 = 0x114F0044,
    SUBDEVICE_114F0045 = 0x114F0045,
    SUBDEVICE_114F004E = 0x114F004E
};



inline const char8* enumToString(PciSubDevice114F0040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice114F0040::NONE:               return "NONE";
        case PciSubDevice114F0040::SUBDEVICE_114F0042: return "SUBDEVICE_114F0042";
        case PciSubDevice114F0040::SUBDEVICE_114F0043: return "SUBDEVICE_114F0043";
        case PciSubDevice114F0040::SUBDEVICE_114F0044: return "SUBDEVICE_114F0044";
        case PciSubDevice114F0040::SUBDEVICE_114F0045: return "SUBDEVICE_114F0045";
        case PciSubDevice114F0040::SUBDEVICE_114F004E: return "SUBDEVICE_114F004E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice114F0040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice114F0040 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice114F0040::SUBDEVICE_114F0042: return "AccelePort 2p PCI";
        case PciSubDevice114F0040::SUBDEVICE_114F0043: return "AccelePort 4p PCI";
        case PciSubDevice114F0040::SUBDEVICE_114F0044: return "AccelePort 8p PCI";
        case PciSubDevice114F0040::SUBDEVICE_114F0045: return "AccelePort 16p PCI";
        case PciSubDevice114F0040::SUBDEVICE_114F004E: return "AccelePort 32p PCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR114F_PCISUBDEVICE114F0040_H
