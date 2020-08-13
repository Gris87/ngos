// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR118D_PCIDEVICE118D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR118D_PCIDEVICE118D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice118D: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0012 = 0x0012,
    DEVICE_0014 = 0x0014,
    DEVICE_0024 = 0x0024,
    DEVICE_0044 = 0x0044,
    DEVICE_0112 = 0x0112,
    DEVICE_0114 = 0x0114,
    DEVICE_0124 = 0x0124,
    DEVICE_0144 = 0x0144,
    DEVICE_0212 = 0x0212,
    DEVICE_0214 = 0x0214,
    DEVICE_0224 = 0x0224,
    DEVICE_0244 = 0x0244,
    DEVICE_0312 = 0x0312,
    DEVICE_0314 = 0x0314,
    DEVICE_0324 = 0x0324,
    DEVICE_0344 = 0x0344,
    DEVICE_B04E = 0xB04E
};



inline const char8* enumToString(PciDevice118D device118D) // TEST: NO
{
    // COMMON_LT((" | device118D = %u", device118D)); // Commented to avoid bad looking logs



    switch (device118D)
    {
        case PciDevice118D::NONE:        return "NONE";
        case PciDevice118D::DEVICE_0001: return "DEVICE_0001";
        case PciDevice118D::DEVICE_0012: return "DEVICE_0012";
        case PciDevice118D::DEVICE_0014: return "DEVICE_0014";
        case PciDevice118D::DEVICE_0024: return "DEVICE_0024";
        case PciDevice118D::DEVICE_0044: return "DEVICE_0044";
        case PciDevice118D::DEVICE_0112: return "DEVICE_0112";
        case PciDevice118D::DEVICE_0114: return "DEVICE_0114";
        case PciDevice118D::DEVICE_0124: return "DEVICE_0124";
        case PciDevice118D::DEVICE_0144: return "DEVICE_0144";
        case PciDevice118D::DEVICE_0212: return "DEVICE_0212";
        case PciDevice118D::DEVICE_0214: return "DEVICE_0214";
        case PciDevice118D::DEVICE_0224: return "DEVICE_0224";
        case PciDevice118D::DEVICE_0244: return "DEVICE_0244";
        case PciDevice118D::DEVICE_0312: return "DEVICE_0312";
        case PciDevice118D::DEVICE_0314: return "DEVICE_0314";
        case PciDevice118D::DEVICE_0324: return "DEVICE_0324";
        case PciDevice118D::DEVICE_0344: return "DEVICE_0344";
        case PciDevice118D::DEVICE_B04E: return "DEVICE_B04E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice118D device118D) // TEST: NO
{
    // COMMON_LT((" | device118D = %u", device118D)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device118D, enumToString(device118D));

    return res;
}



inline const char8* enumToHumanString(PciDevice118D device118D) // TEST: NO
{
    // COMMON_LT((" | device118D = %u", device118D)); // Commented to avoid bad looking logs



    switch (device118D)
    {
        case PciDevice118D::DEVICE_0001: return "Raptor-PCI framegrabber";
        case PciDevice118D::DEVICE_0012: return "Model 12 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0014: return "Model 14 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0024: return "Model 24 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0044: return "Model 44 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0112: return "Model 12 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0114: return "Model 14 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0124: return "Model 24 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0144: return "Model 44 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0212: return "Model 12 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0214: return "Model 14 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0224: return "Model 24 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0244: return "Model 44 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0312: return "Model 12 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0314: return "Model 14 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0324: return "Model 24 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_0344: return "Model 44 Road Runner Frame Grabber";
        case PciDevice118D::DEVICE_B04E: return "Claxon CXP4 CoaXPress frame grabber";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR118D_PCIDEVICE118D_H
