// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029710_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029710_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029710: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10192120 = 0x10192120,
    SUBDEVICE_104383A2 = 0x104383A2
};



inline const char8* enumToString(PciSubDevice10029710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029710::NONE:               return "NONE";
        case PciSubDevice10029710::SUBDEVICE_10192120: return "SUBDEVICE_10192120";
        case PciSubDevice10029710::SUBDEVICE_104383A2: return "SUBDEVICE_104383A2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029710 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029710::SUBDEVICE_10192120: return "A785GM-M";
        case PciSubDevice10029710::SUBDEVICE_104383A2: return "M4A785TD Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029710_H
