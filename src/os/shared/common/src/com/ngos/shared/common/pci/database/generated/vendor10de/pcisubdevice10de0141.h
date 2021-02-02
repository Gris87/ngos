// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0141_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0141_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0141: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104381B0 = 0x104381B0,
    SUBDEVICE_107D593A = 0x107D593A,
    SUBDEVICE_107D597B = 0x107D597B,
    SUBDEVICE_14583124 = 0x14583124
};



inline const char8* enumToString(PciSubDevice10DE0141 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0141::NONE:               return "NONE";
        case PciSubDevice10DE0141::SUBDEVICE_104381B0: return "SUBDEVICE_104381B0";
        case PciSubDevice10DE0141::SUBDEVICE_107D593A: return "SUBDEVICE_107D593A";
        case PciSubDevice10DE0141::SUBDEVICE_107D597B: return "SUBDEVICE_107D597B";
        case PciSubDevice10DE0141::SUBDEVICE_14583124: return "SUBDEVICE_14583124";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0141 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0141 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0141::SUBDEVICE_104381B0: return "EN6600 Silencer";
        case PciSubDevice10DE0141::SUBDEVICE_107D593A: return "LR2A22 128MB TV OUT";
        case PciSubDevice10DE0141::SUBDEVICE_107D597B: return "WINFAST PX6600";
        case PciSubDevice10DE0141::SUBDEVICE_14583124: return "GV-NX66128DP Turbo Force Edition";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0141_H
