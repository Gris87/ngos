// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18880_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18880_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F18880: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00702259 = 0x00702259,
    SUBDEVICE_00706A18 = 0x00706A18,
    SUBDEVICE_0070C108 = 0x0070C108,
    SUBDEVICE_14613100 = 0x14613100,
    SUBDEVICE_56542389 = 0x56542389,
    SUBDEVICE_56542390 = 0x56542390
};



inline const char8* enumToString(PciSubDevice14F18880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18880::NONE:               return "NONE";
        case PciSubDevice14F18880::SUBDEVICE_00702259: return "SUBDEVICE_00702259";
        case PciSubDevice14F18880::SUBDEVICE_00706A18: return "SUBDEVICE_00706A18";
        case PciSubDevice14F18880::SUBDEVICE_0070C108: return "SUBDEVICE_0070C108";
        case PciSubDevice14F18880::SUBDEVICE_14613100: return "SUBDEVICE_14613100";
        case PciSubDevice14F18880::SUBDEVICE_56542389: return "SUBDEVICE_56542389";
        case PciSubDevice14F18880::SUBDEVICE_56542390: return "SUBDEVICE_56542390";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F18880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F18880 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18880::SUBDEVICE_00702259: return "WinTV HVR-1250";
        case PciSubDevice14F18880::SUBDEVICE_00706A18: return "WinTV-quadHD";
        case PciSubDevice14F18880::SUBDEVICE_0070C108: return "WinTV-HVR-4400-HD model 1278";
        case PciSubDevice14F18880::SUBDEVICE_14613100: return "CE310B SD PCIe Video Capture Card";
        case PciSubDevice14F18880::SUBDEVICE_56542389: return "GoTView X5 DVD Hybrid PCI-E";
        case PciSubDevice14F18880::SUBDEVICE_56542390: return "GoTView X5 3D HYBRID PCI-E";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18880_H
