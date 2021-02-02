// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B47A1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B47A1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B47A1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B4BE0 = 0x102B4BE0,
    SUBDEVICE_102B4BE1 = 0x102B4BE1,
    SUBDEVICE_102B4BE2 = 0x102B4BE2
};



inline const char8* enumToString(PciSubDevice102B47A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B47A1::NONE:               return "NONE";
        case PciSubDevice102B47A1::SUBDEVICE_102B4BE0: return "SUBDEVICE_102B4BE0";
        case PciSubDevice102B47A1::SUBDEVICE_102B4BE1: return "SUBDEVICE_102B4BE1";
        case PciSubDevice102B47A1::SUBDEVICE_102B4BE2: return "SUBDEVICE_102B4BE2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B47A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B47A1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B47A1::SUBDEVICE_102B4BE0: return "Solios eA/XA (single) frame grabber";
        case PciSubDevice102B47A1::SUBDEVICE_102B4BE1: return "Solios eA/XA (dual) frame grabber";
        case PciSubDevice102B47A1::SUBDEVICE_102B4BE2: return "Solios eA/XA (quad) frame grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B47A1_H
