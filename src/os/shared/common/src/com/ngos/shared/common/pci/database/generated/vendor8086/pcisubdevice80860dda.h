// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860DDA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860DDA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860DDA: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1BD40076 = 0x1BD40076
};



inline const char8* enumToString(PciSubDevice80860DDA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860DDA::NONE:               return "NONE";
        case PciSubDevice80860DDA::SUBDEVICE_1BD40076: return "SUBDEVICE_1BD40076";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860DDA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860DDA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860DDA::SUBDEVICE_1BD40076: return "Ethernet Connection F102IX722 for 10GbE SFP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860DDA_H
