// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18852_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18852_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F18852: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00708010 = 0x00708010,
    SUBDEVICE_0070F038 = 0x0070F038,
    SUBDEVICE_107D6F22 = 0x107D6F22,
    SUBDEVICE_12ABD585 = 0x12ABD585,
    SUBDEVICE_13C23013 = 0x13C23013,
    SUBDEVICE_1461C039 = 0x1461C039,
    SUBDEVICE_153B117E = 0x153B117E,
    SUBDEVICE_18ACDB78 = 0x18ACDB78,
    SUBDEVICE_42540950 = 0x42540950,
    SUBDEVICE_42540952 = 0x42540952,
    SUBDEVICE_42540982 = 0x42540982,
    SUBDEVICE_42549580 = 0x42549580,
    SUBDEVICE_4254980C = 0x4254980C
};



inline const char8* enumToString(PciSubDevice14F18852 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18852::NONE:               return "NONE";
        case PciSubDevice14F18852::SUBDEVICE_00708010: return "SUBDEVICE_00708010";
        case PciSubDevice14F18852::SUBDEVICE_0070F038: return "SUBDEVICE_0070F038";
        case PciSubDevice14F18852::SUBDEVICE_107D6F22: return "SUBDEVICE_107D6F22";
        case PciSubDevice14F18852::SUBDEVICE_12ABD585: return "SUBDEVICE_12ABD585";
        case PciSubDevice14F18852::SUBDEVICE_13C23013: return "SUBDEVICE_13C23013";
        case PciSubDevice14F18852::SUBDEVICE_1461C039: return "SUBDEVICE_1461C039";
        case PciSubDevice14F18852::SUBDEVICE_153B117E: return "SUBDEVICE_153B117E";
        case PciSubDevice14F18852::SUBDEVICE_18ACDB78: return "SUBDEVICE_18ACDB78";
        case PciSubDevice14F18852::SUBDEVICE_42540950: return "SUBDEVICE_42540950";
        case PciSubDevice14F18852::SUBDEVICE_42540952: return "SUBDEVICE_42540952";
        case PciSubDevice14F18852::SUBDEVICE_42540982: return "SUBDEVICE_42540982";
        case PciSubDevice14F18852::SUBDEVICE_42549580: return "SUBDEVICE_42549580";
        case PciSubDevice14F18852::SUBDEVICE_4254980C: return "SUBDEVICE_4254980C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F18852 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F18852 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18852::SUBDEVICE_00708010: return "WinTV HVR-1400 ExpressCard";
        case PciSubDevice14F18852::SUBDEVICE_0070F038: return "WinTV HVR-5525";
        case PciSubDevice14F18852::SUBDEVICE_107D6F22: return "WinFast PxTV1200";
        case PciSubDevice14F18852::SUBDEVICE_12ABD585: return "PE988J Hybrid ATSC/QAM PCI-E AVS Video Capture (SoftEncoder)";
        case PciSubDevice14F18852::SUBDEVICE_13C23013: return "TT-budget CT2-4500 CI";
        case PciSubDevice14F18852::SUBDEVICE_1461C039: return "AVerTV Hybrid Express (A577)";
        case PciSubDevice14F18852::SUBDEVICE_153B117E: return "Cinergy T PCIe Dual";
        case PciSubDevice14F18852::SUBDEVICE_18ACDB78: return "FusionHDTV DVB-T Dual Express";
        case PciSubDevice14F18852::SUBDEVICE_42540950: return "S950";
        case PciSubDevice14F18852::SUBDEVICE_42540952: return "S952";
        case PciSubDevice14F18852::SUBDEVICE_42540982: return "T982";
        case PciSubDevice14F18852::SUBDEVICE_42549580: return "T9580";
        case PciSubDevice14F18852::SUBDEVICE_4254980C: return "T980C";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18852_H
