// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863340_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863340_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863340: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140529 = 0x10140529,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_103C0890 = 0x103C0890,
    SUBDEVICE_103C08B0 = 0x103C08B0,
    SUBDEVICE_144DC005 = 0x144DC005,
    SUBDEVICE_144DC00C = 0x144DC00C
};



inline const char8* enumToString(PciSubDevice80863340 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863340::NONE:               return "NONE";
        case PciSubDevice80863340::SUBDEVICE_10140529: return "SUBDEVICE_10140529";
        case PciSubDevice80863340::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice80863340::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice80863340::SUBDEVICE_103C0890: return "SUBDEVICE_103C0890";
        case PciSubDevice80863340::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";
        case PciSubDevice80863340::SUBDEVICE_144DC005: return "SUBDEVICE_144DC005";
        case PciSubDevice80863340::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863340 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863340 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863340::SUBDEVICE_10140529: return "Thinkpad T40 series";
        case PciSubDevice80863340::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice80863340::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice80863340::SUBDEVICE_103C0890: return "NC6000 laptop";
        case PciSubDevice80863340::SUBDEVICE_103C08B0: return "tc1100 tablet";
        case PciSubDevice80863340::SUBDEVICE_144DC005: return "X10 Laptop";
        case PciSubDevice80863340::SUBDEVICE_144DC00C: return "P30/P35 notebook";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863340_H
