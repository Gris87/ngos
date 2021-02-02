// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024398_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024398_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024398: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10192120 = 0x10192120,
    SUBDEVICE_104382EF = 0x104382EF,
    SUBDEVICE_105B0E13 = 0x105B0E13,
    SUBDEVICE_15D9A811 = 0x15D9A811
};



inline const char8* enumToString(PciSubDevice10024398 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024398::NONE:               return "NONE";
        case PciSubDevice10024398::SUBDEVICE_10192120: return "SUBDEVICE_10192120";
        case PciSubDevice10024398::SUBDEVICE_104382EF: return "SUBDEVICE_104382EF";
        case PciSubDevice10024398::SUBDEVICE_105B0E13: return "SUBDEVICE_105B0E13";
        case PciSubDevice10024398::SUBDEVICE_15D9A811: return "SUBDEVICE_15D9A811";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024398 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024398 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024398::SUBDEVICE_10192120: return "A785GM-M";
        case PciSubDevice10024398::SUBDEVICE_104382EF: return "M3A78-EH Motherboard";
        case PciSubDevice10024398::SUBDEVICE_105B0E13: return "N15235/A74MX mainboard / AMD SB700";
        case PciSubDevice10024398::SUBDEVICE_15D9A811: return "H8DGU";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024398_H
