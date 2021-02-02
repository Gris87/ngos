// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B475D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B475D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B475D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B4B90 = 0x102B4B90,
    SUBDEVICE_102B4B91 = 0x102B4B91,
    SUBDEVICE_102B4B92 = 0x102B4B92,
    SUBDEVICE_102B4B93 = 0x102B4B93,
    SUBDEVICE_102B4B94 = 0x102B4B94
};



inline const char8* enumToString(PciSubDevice102B475D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B475D::NONE:               return "NONE";
        case PciSubDevice102B475D::SUBDEVICE_102B4B90: return "SUBDEVICE_102B4B90";
        case PciSubDevice102B475D::SUBDEVICE_102B4B91: return "SUBDEVICE_102B4B91";
        case PciSubDevice102B475D::SUBDEVICE_102B4B92: return "SUBDEVICE_102B4B92";
        case PciSubDevice102B475D::SUBDEVICE_102B4B93: return "SUBDEVICE_102B4B93";
        case PciSubDevice102B475D::SUBDEVICE_102B4B94: return "SUBDEVICE_102B4B94";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B475D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B475D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B475D::SUBDEVICE_102B4B90: return "Vio Duo frame grabber (single channel)";
        case PciSubDevice102B475D::SUBDEVICE_102B4B91: return "Vio Duo frame grabber";
        case PciSubDevice102B475D::SUBDEVICE_102B4B92: return "Vio Analog frame grabber";
        case PciSubDevice102B475D::SUBDEVICE_102B4B93: return "Vio SDI Frame Grabber";
        case PciSubDevice102B475D::SUBDEVICE_102B4B94: return "Vio DVI-A frame grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B475D_H
