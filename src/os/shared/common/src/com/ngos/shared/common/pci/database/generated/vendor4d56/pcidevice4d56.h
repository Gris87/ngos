// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4D56_PCIDEVICE4D56_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4D56_PCIDEVICE4D56_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4D56: bad_uint16 // Ignore CppEnumVerifier
{
    DEVICE_0000 = 0x0000,
    DEVICE_0001 = 0x0001,
    DEVICE_0010 = 0x0010,
    DEVICE_0020 = 0x0020,
    DEVICE_0030 = 0x0030
};



inline const char8* enumToString(PciDevice4D56 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4D56::DEVICE_0000: return "DEVICE_0000";
        case PciDevice4D56::DEVICE_0001: return "DEVICE_0001";
        case PciDevice4D56::DEVICE_0010: return "DEVICE_0010";
        case PciDevice4D56::DEVICE_0020: return "DEVICE_0020";
        case PciDevice4D56::DEVICE_0030: return "DEVICE_0030";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4D56 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice4D56 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4D56::DEVICE_0000: return "[mvHYPERION-CLe/CLb] CameraLink PCI Express x1 Frame Grabber";
        case PciDevice4D56::DEVICE_0001: return "[mvHYPERION-CLf/CLm] CameraLink PCI Express x4 Frame Grabber";
        case PciDevice4D56::DEVICE_0010: return "[mvHYPERION-16R16/-32R16] 16 Video Channel PCI Express x4 Frame Grabber";
        case PciDevice4D56::DEVICE_0020: return "[mvHYPERION-HD-SDI] HD-SDI PCI Express x4 Frame Grabber";
        case PciDevice4D56::DEVICE_0030: return "[mvHYPERION-HD-SDI-Merger] HD-SDI PCI Express x4 Frame Grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4D56_PCIDEVICE4D56_H
