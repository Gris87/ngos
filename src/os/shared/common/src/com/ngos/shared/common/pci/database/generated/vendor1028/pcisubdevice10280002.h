// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280002_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280002_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10280002: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280002 = 0x10280002,
    SUBDEVICE_102800D1 = 0x102800D1,
    SUBDEVICE_102800D9 = 0x102800D9
};



inline const char8* enumToString(PciSubDevice10280002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10280002::NONE:               return "NONE";
        case PciSubDevice10280002::SUBDEVICE_10280002: return "SUBDEVICE_10280002";
        case PciSubDevice10280002::SUBDEVICE_102800D1: return "SUBDEVICE_102800D1";
        case PciSubDevice10280002::SUBDEVICE_102800D9: return "SUBDEVICE_102800D9";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10280002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10280002 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10280002::SUBDEVICE_10280002: return "PowerEdge 4400";
        case PciSubDevice10280002::SUBDEVICE_102800D1: return "PERC 3/DiV [Viper]";
        case PciSubDevice10280002::SUBDEVICE_102800D9: return "PERC 3/DiL [Lexus]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE10280002_H
