// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100215DE_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100215DE_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100215DE: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C8615 = 0x103C8615,
    SUBDEVICE_1043876B = 0x1043876B,
    SUBDEVICE_17AA5124 = 0x17AA5124,
    SUBDEVICE_EA50CC10 = 0xEA50CC10
};



inline const char8* enumToString(PciSubDevice100215DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100215DE::NONE:               return "NONE";
        case PciSubDevice100215DE::SUBDEVICE_103C8615: return "SUBDEVICE_103C8615";
        case PciSubDevice100215DE::SUBDEVICE_1043876B: return "SUBDEVICE_1043876B";
        case PciSubDevice100215DE::SUBDEVICE_17AA5124: return "SUBDEVICE_17AA5124";
        case PciSubDevice100215DE::SUBDEVICE_EA50CC10: return "SUBDEVICE_EA50CC10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100215DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100215DE subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100215DE::SUBDEVICE_103C8615: return "Pavilion Laptop 15-cw1xxx";
        case PciSubDevice100215DE::SUBDEVICE_1043876B: return "PRIME B450M-A Motherboard";
        case PciSubDevice100215DE::SUBDEVICE_17AA5124: return "ThinkPad E595";
        case PciSubDevice100215DE::SUBDEVICE_EA50CC10: return "RXi2-BP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE100215DE_H
