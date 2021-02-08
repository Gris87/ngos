// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1299_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1299_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1299: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA30BB = 0x17AA30BB,
    SUBDEVICE_17AA30DF = 0x17AA30DF,
    SUBDEVICE_17AA36A7 = 0x17AA36A7,
    SUBDEVICE_17AA36AF = 0x17AA36AF
};



inline const char8* enumToString(PciSubDevice10DE1299 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1299::NONE:               return "NONE";
        case PciSubDevice10DE1299::SUBDEVICE_17AA30BB: return "SUBDEVICE_17AA30BB";
        case PciSubDevice10DE1299::SUBDEVICE_17AA30DF: return "SUBDEVICE_17AA30DF";
        case PciSubDevice10DE1299::SUBDEVICE_17AA36A7: return "SUBDEVICE_17AA36A7";
        case PciSubDevice10DE1299::SUBDEVICE_17AA36AF: return "SUBDEVICE_17AA36AF";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1299 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1299 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1299::SUBDEVICE_17AA30BB: return "GeForce 920A";
        case PciSubDevice10DE1299::SUBDEVICE_17AA30DF: return "GeForce 920A";
        case PciSubDevice10DE1299::SUBDEVICE_17AA36A7: return "GeForce 920A";
        case PciSubDevice10DE1299::SUBDEVICE_17AA36AF: return "GeForce 920M";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1299_H
