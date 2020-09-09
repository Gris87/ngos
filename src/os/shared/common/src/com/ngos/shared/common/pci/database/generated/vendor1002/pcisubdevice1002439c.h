// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002439C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002439C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002439C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10024392 = 0x10024392,
    SUBDEVICE_10192120 = 0x10192120,
    SUBDEVICE_103C1609 = 0x103C1609,
    SUBDEVICE_104382EF = 0x104382EF,
    SUBDEVICE_105B0E13 = 0x105B0E13
};



inline const char8* enumToString(PciSubDevice1002439C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002439C::NONE:               return "NONE";
        case PciSubDevice1002439C::SUBDEVICE_10024392: return "SUBDEVICE_10024392";
        case PciSubDevice1002439C::SUBDEVICE_10192120: return "SUBDEVICE_10192120";
        case PciSubDevice1002439C::SUBDEVICE_103C1609: return "SUBDEVICE_103C1609";
        case PciSubDevice1002439C::SUBDEVICE_104382EF: return "SUBDEVICE_104382EF";
        case PciSubDevice1002439C::SUBDEVICE_105B0E13: return "SUBDEVICE_105B0E13";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002439C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002439C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002439C::SUBDEVICE_10024392: return "MSI MS-7713 motherboard";
        case PciSubDevice1002439C::SUBDEVICE_10192120: return "A785GM-M";
        case PciSubDevice1002439C::SUBDEVICE_103C1609: return "ProLiant MicroServer N36L";
        case PciSubDevice1002439C::SUBDEVICE_104382EF: return "M3A78-EH Motherboard";
        case PciSubDevice1002439C::SUBDEVICE_105B0E13: return "N15235/A74MX mainboard / AMD SB700";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002439C_H
