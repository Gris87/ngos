// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051B_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051B_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B051B: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B051B = 0x102B051B,
    SUBDEVICE_102B1100 = 0x102B1100,
    SUBDEVICE_102B1200 = 0x102B1200,
    SUBDEVICE_102B2100 = 0x102B2100
};



inline const char8* enumToString(PciSubDevice102B051B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B051B::NONE:               return "NONE";
        case PciSubDevice102B051B::SUBDEVICE_102B051B: return "SUBDEVICE_102B051B";
        case PciSubDevice102B051B::SUBDEVICE_102B1100: return "SUBDEVICE_102B1100";
        case PciSubDevice102B051B::SUBDEVICE_102B1200: return "SUBDEVICE_102B1200";
        case PciSubDevice102B051B::SUBDEVICE_102B2100: return "SUBDEVICE_102B2100";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B051B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B051B subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B051B::SUBDEVICE_102B051B: return "MGA-2164W Millennium II";
        case PciSubDevice102B051B::SUBDEVICE_102B1100: return "MGA-2164W Millennium II";
        case PciSubDevice102B051B::SUBDEVICE_102B1200: return "MGA-2164W Millennium II";
        case PciSubDevice102B051B::SUBDEVICE_102B2100: return "MGA-2164W Millennium II";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B051B_H
