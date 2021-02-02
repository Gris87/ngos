// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B47C1_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B47C1_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102B47C1: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102B0000 = 0x102B0000,
    SUBDEVICE_102B4B80 = 0x102B4B80,
    SUBDEVICE_102B4B81 = 0x102B4B81,
    SUBDEVICE_102B4D80 = 0x102B4D80,
    SUBDEVICE_102B4D81 = 0x102B4D81,
    SUBDEVICE_102B4E80 = 0x102B4E80,
    SUBDEVICE_102B4E81 = 0x102B4E81
};



inline const char8* enumToString(PciSubDevice102B47C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B47C1::NONE:               return "NONE";
        case PciSubDevice102B47C1::SUBDEVICE_102B0000: return "SUBDEVICE_102B0000";
        case PciSubDevice102B47C1::SUBDEVICE_102B4B80: return "SUBDEVICE_102B4B80";
        case PciSubDevice102B47C1::SUBDEVICE_102B4B81: return "SUBDEVICE_102B4B81";
        case PciSubDevice102B47C1::SUBDEVICE_102B4D80: return "SUBDEVICE_102B4D80";
        case PciSubDevice102B47C1::SUBDEVICE_102B4D81: return "SUBDEVICE_102B4D81";
        case PciSubDevice102B47C1::SUBDEVICE_102B4E80: return "SUBDEVICE_102B4E80";
        case PciSubDevice102B47C1::SUBDEVICE_102B4E81: return "SUBDEVICE_102B4E81";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102B47C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102B47C1 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102B47C1::SUBDEVICE_102B0000: return "Solios frame grabber";
        case PciSubDevice102B47C1::SUBDEVICE_102B4B80: return "Solios eCL/XCL (single-Medium) frame grabber";
        case PciSubDevice102B47C1::SUBDEVICE_102B4B81: return "Solios eCL/XCL (dual-Base) frame grabber";
        case PciSubDevice102B47C1::SUBDEVICE_102B4D80: return "Solios eV-CL (single-Medium) frame grabber";
        case PciSubDevice102B47C1::SUBDEVICE_102B4D81: return "Solios eV-CL (dual-Base) frame grabber";
        case PciSubDevice102B47C1::SUBDEVICE_102B4E80: return "Solios eM-CL (single-Medium) frame grabber";
        case PciSubDevice102B47C1::SUBDEVICE_102B4E81: return "Solios eM-CL (dual-Base) frame grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR102B_PCISUBDEVICE102B47C1_H
