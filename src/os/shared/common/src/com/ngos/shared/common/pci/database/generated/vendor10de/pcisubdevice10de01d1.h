// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01D1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01D1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE01D1: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_107D5EFA = 0x107D5EFA,
    SUBDEVICE_107D5EFB = 0x107D5EFB,
    SUBDEVICE_14620345 = 0x14620345
};



inline const char8* enumToString(PciSubDevice10DE01D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE01D1::NONE:               return "NONE";
        case PciSubDevice10DE01D1::SUBDEVICE_107D5EFA: return "SUBDEVICE_107D5EFA";
        case PciSubDevice10DE01D1::SUBDEVICE_107D5EFB: return "SUBDEVICE_107D5EFB";
        case PciSubDevice10DE01D1::SUBDEVICE_14620345: return "SUBDEVICE_14620345";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE01D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE01D1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE01D1::SUBDEVICE_107D5EFA: return "WinFast PX7300LE-TD128";
        case PciSubDevice10DE01D1::SUBDEVICE_107D5EFB: return "WinFast PX7300LE-TD256";
        case PciSubDevice10DE01D1::SUBDEVICE_14620345: return "7300LE PCI Express Graphics Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01D1_H
