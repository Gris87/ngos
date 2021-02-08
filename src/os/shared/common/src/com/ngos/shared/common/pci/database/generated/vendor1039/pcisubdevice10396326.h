// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396326_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396326_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10396326: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10396326 = 0x10396326,
    SUBDEVICE_10920A50 = 0x10920A50,
    SUBDEVICE_10920A70 = 0x10920A70,
    SUBDEVICE_10924910 = 0x10924910,
    SUBDEVICE_10924920 = 0x10924920,
    SUBDEVICE_10B06326 = 0x10B06326,
    SUBDEVICE_15696326 = 0x15696326
};



inline const char8* enumToString(PciSubDevice10396326 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10396326::NONE:               return "NONE";
        case PciSubDevice10396326::SUBDEVICE_10396326: return "SUBDEVICE_10396326";
        case PciSubDevice10396326::SUBDEVICE_10920A50: return "SUBDEVICE_10920A50";
        case PciSubDevice10396326::SUBDEVICE_10920A70: return "SUBDEVICE_10920A70";
        case PciSubDevice10396326::SUBDEVICE_10924910: return "SUBDEVICE_10924910";
        case PciSubDevice10396326::SUBDEVICE_10924920: return "SUBDEVICE_10924920";
        case PciSubDevice10396326::SUBDEVICE_10B06326: return "SUBDEVICE_10B06326";
        case PciSubDevice10396326::SUBDEVICE_15696326: return "SUBDEVICE_15696326";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10396326 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10396326 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10396326::SUBDEVICE_10396326: return "SiS6326 GUI Accelerator";
        case PciSubDevice10396326::SUBDEVICE_10920A50: return "SpeedStar A50";
        case PciSubDevice10396326::SUBDEVICE_10920A70: return "SpeedStar A70";
        case PciSubDevice10396326::SUBDEVICE_10924910: return "SpeedStar A70";
        case PciSubDevice10396326::SUBDEVICE_10924920: return "SpeedStar A70";
        case PciSubDevice10396326::SUBDEVICE_10B06326: return "S6110-B (AGP)";
        case PciSubDevice10396326::SUBDEVICE_15696326: return "SiS6326 GUI Accelerator";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1039_PCISUBDEVICE10396326_H
