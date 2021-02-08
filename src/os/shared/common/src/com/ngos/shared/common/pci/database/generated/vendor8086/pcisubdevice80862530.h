// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862530_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862530_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862530: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102800C7 = 0x102800C7,
    SUBDEVICE_147B0507 = 0x147B0507
};



inline const char8* enumToString(PciSubDevice80862530 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862530::NONE:               return "NONE";
        case PciSubDevice80862530::SUBDEVICE_102800C7: return "SUBDEVICE_102800C7";
        case PciSubDevice80862530::SUBDEVICE_147B0507: return "SUBDEVICE_147B0507";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862530 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862530 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862530::SUBDEVICE_102800C7: return "Dimension 8100";
        case PciSubDevice80862530::SUBDEVICE_147B0507: return "TH7II-RAID";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862530_H
