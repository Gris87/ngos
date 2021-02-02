// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100215DD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100215DD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100215DD: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C83C6 = 0x103C83C6,
    SUBDEVICE_1043876B = 0x1043876B,
    SUBDEVICE_1458D000 = 0x1458D000,
    SUBDEVICE_EA50CC10 = 0xEA50CC10
};



inline const char8* enumToString(PciSubDevice100215DD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100215DD::NONE:               return "NONE";
        case PciSubDevice100215DD::SUBDEVICE_103C83C6: return "SUBDEVICE_103C83C6";
        case PciSubDevice100215DD::SUBDEVICE_1043876B: return "SUBDEVICE_1043876B";
        case PciSubDevice100215DD::SUBDEVICE_1458D000: return "SUBDEVICE_1458D000";
        case PciSubDevice100215DD::SUBDEVICE_EA50CC10: return "SUBDEVICE_EA50CC10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100215DD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100215DD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100215DD::SUBDEVICE_103C83C6: return "Radeon Vega 8 Mobile";
        case PciSubDevice100215DD::SUBDEVICE_1043876B: return "PRIME Motherboard";
        case PciSubDevice100215DD::SUBDEVICE_1458D000: return "Radeon RX Vega 11";
        case PciSubDevice100215DD::SUBDEVICE_EA50CC10: return "RXi2-BP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100215DD_H
