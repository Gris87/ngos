// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862652_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862652_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862652: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280177 = 0x10280177,
    SUBDEVICE_14627028 = 0x14627028
};



inline const char8* enumToString(PciSubDevice80862652 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862652::NONE:               return "NONE";
        case PciSubDevice80862652::SUBDEVICE_10280177: return "SUBDEVICE_10280177";
        case PciSubDevice80862652::SUBDEVICE_14627028: return "SUBDEVICE_14627028";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862652 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862652 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862652::SUBDEVICE_10280177: return "Dimension 8400";
        case PciSubDevice80862652::SUBDEVICE_14627028: return "915P/G Neo2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862652_H
