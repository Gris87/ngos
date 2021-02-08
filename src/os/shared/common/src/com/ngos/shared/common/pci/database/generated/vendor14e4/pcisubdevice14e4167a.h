// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4167A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4167A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4167A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102801DA = 0x102801DA,
    SUBDEVICE_102801DE = 0x102801DE,
    SUBDEVICE_102801DF = 0x102801DF,
    SUBDEVICE_10280214 = 0x10280214,
    SUBDEVICE_1028021E = 0x1028021E
};



inline const char8* enumToString(PciSubDevice14E4167A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4167A::NONE:               return "NONE";
        case PciSubDevice14E4167A::SUBDEVICE_102801DA: return "SUBDEVICE_102801DA";
        case PciSubDevice14E4167A::SUBDEVICE_102801DE: return "SUBDEVICE_102801DE";
        case PciSubDevice14E4167A::SUBDEVICE_102801DF: return "SUBDEVICE_102801DF";
        case PciSubDevice14E4167A::SUBDEVICE_10280214: return "SUBDEVICE_10280214";
        case PciSubDevice14E4167A::SUBDEVICE_1028021E: return "SUBDEVICE_1028021E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4167A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4167A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4167A::SUBDEVICE_102801DA: return "OptiPlex 745";
        case PciSubDevice14E4167A::SUBDEVICE_102801DE: return "Precision 390";
        case PciSubDevice14E4167A::SUBDEVICE_102801DF: return "PowerEdge SC440";
        case PciSubDevice14E4167A::SUBDEVICE_10280214: return "Precision T3400";
        case PciSubDevice14E4167A::SUBDEVICE_1028021E: return "Precision T5400";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4167A_H
