// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B051F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B2100 = 0x102B2100
};



inline const char8* enumToString(PciSubDevice102B051F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B051F::NONE:               return "NONE";
        case PciSubDevice102B051F::SUBDEVICE_102B2100: return "SUBDEVICE_102B2100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B051F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B051F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B051F::SUBDEVICE_102B2100: return "MGA-2164WA [Millennium II A]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051F_H
