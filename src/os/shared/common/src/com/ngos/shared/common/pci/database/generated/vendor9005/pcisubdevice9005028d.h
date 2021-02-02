// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice9005028D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_90050550 = 0x90050550,
    SUBDEVICE_90050551 = 0x90050551,
    SUBDEVICE_90050552 = 0x90050552,
    SUBDEVICE_90050553 = 0x90050553,
    SUBDEVICE_90050554 = 0x90050554
};



inline const char8* enumToString(PciSubDevice9005028D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005028D::NONE:               return "NONE";
        case PciSubDevice9005028D::SUBDEVICE_90050550: return "SUBDEVICE_90050550";
        case PciSubDevice9005028D::SUBDEVICE_90050551: return "SUBDEVICE_90050551";
        case PciSubDevice9005028D::SUBDEVICE_90050552: return "SUBDEVICE_90050552";
        case PciSubDevice9005028D::SUBDEVICE_90050553: return "SUBDEVICE_90050553";
        case PciSubDevice9005028D::SUBDEVICE_90050554: return "SUBDEVICE_90050554";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice9005028D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice9005028D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice9005028D::SUBDEVICE_90050550: return "Series 8 - ASR-82405 - 24 internal 0 external 12G SAS Port/PCIe 3.0";
        case PciSubDevice9005028D::SUBDEVICE_90050551: return "Series 8 - ASR-81605 - 16 internal 0 external 12G SAS Port/PCIe 3.0";
        case PciSubDevice9005028D::SUBDEVICE_90050552: return "Series 8 - ASR-8805 - 8 internal 0 external 12G SAS Port/PCIe 3.0";
        case PciSubDevice9005028D::SUBDEVICE_90050553: return "Series 8 - ASR-8085 - 0 internal 8 external 12G SAS Port/PCIe 3.0";
        case PciSubDevice9005028D::SUBDEVICE_90050554: return "Series 8 - ASR-8885 - 8 internal 8 external 12G SAS Port/PCIe 3.0";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCISUBDEVICE9005028D_H
