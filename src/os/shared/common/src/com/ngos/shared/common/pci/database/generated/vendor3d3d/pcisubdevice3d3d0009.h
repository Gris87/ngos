// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0009_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0009_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice3D3D0009: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10400011 = 0x10400011,
    SUBDEVICE_10480A42 = 0x10480A42,
    SUBDEVICE_13E91000 = 0x13E91000,
    SUBDEVICE_3D3D0100 = 0x3D3D0100,
    SUBDEVICE_3D3D0111 = 0x3D3D0111,
    SUBDEVICE_3D3D0114 = 0x3D3D0114,
    SUBDEVICE_3D3D0116 = 0x3D3D0116,
    SUBDEVICE_3D3D0119 = 0x3D3D0119,
    SUBDEVICE_3D3D0120 = 0x3D3D0120,
    SUBDEVICE_3D3D0125 = 0x3D3D0125,
    SUBDEVICE_3D3D0127 = 0x3D3D0127
};



inline const char8* enumToString(PciSubDevice3D3D0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice3D3D0009::NONE:               return "NONE";
        case PciSubDevice3D3D0009::SUBDEVICE_10400011: return "SUBDEVICE_10400011";
        case PciSubDevice3D3D0009::SUBDEVICE_10480A42: return "SUBDEVICE_10480A42";
        case PciSubDevice3D3D0009::SUBDEVICE_13E91000: return "SUBDEVICE_13E91000";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0100: return "SUBDEVICE_3D3D0100";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0111: return "SUBDEVICE_3D3D0111";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0114: return "SUBDEVICE_3D3D0114";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0116: return "SUBDEVICE_3D3D0116";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0119: return "SUBDEVICE_3D3D0119";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0120: return "SUBDEVICE_3D3D0120";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0125: return "SUBDEVICE_3D3D0125";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0127: return "SUBDEVICE_3D3D0127";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice3D3D0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice3D3D0009 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice3D3D0009::SUBDEVICE_10400011: return "AccelStar II";
        case PciSubDevice3D3D0009::SUBDEVICE_10480A42: return "GLoria XXL";
        case PciSubDevice3D3D0009::SUBDEVICE_13E91000: return "6221L-4U";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0100: return "AccelStar II 3D Accelerator";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0111: return "Permedia 3: 16";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0114: return "Santa Ana";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0116: return "Oxygen GVX1";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0119: return "Scirocco";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0120: return "Santa Ana PCL";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0125: return "Oxygen VX1";
        case PciSubDevice3D3D0009::SUBDEVICE_3D3D0127: return "Permedia3 Create!";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR3D3D_PCISUBDEVICE3D3D0009_H
