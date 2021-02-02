// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18811_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18811_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F18811: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00703400 = 0x00703400,
    SUBDEVICE_00703401 = 0x00703401,
    SUBDEVICE_00706902 = 0x00706902,
    SUBDEVICE_00709402 = 0x00709402,
    SUBDEVICE_00709600 = 0x00709600,
    SUBDEVICE_14628606 = 0x14628606,
    SUBDEVICE_18ACD500 = 0x18ACD500,
    SUBDEVICE_18ACD810 = 0x18ACD810,
    SUBDEVICE_18ACD820 = 0x18ACD820,
    SUBDEVICE_18ACDB00 = 0x18ACDB00,
    SUBDEVICE_56542388 = 0x56542388
};



inline const char8* enumToString(PciSubDevice14F18811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18811::NONE:               return "NONE";
        case PciSubDevice14F18811::SUBDEVICE_00703400: return "SUBDEVICE_00703400";
        case PciSubDevice14F18811::SUBDEVICE_00703401: return "SUBDEVICE_00703401";
        case PciSubDevice14F18811::SUBDEVICE_00706902: return "SUBDEVICE_00706902";
        case PciSubDevice14F18811::SUBDEVICE_00709402: return "SUBDEVICE_00709402";
        case PciSubDevice14F18811::SUBDEVICE_00709600: return "SUBDEVICE_00709600";
        case PciSubDevice14F18811::SUBDEVICE_14628606: return "SUBDEVICE_14628606";
        case PciSubDevice14F18811::SUBDEVICE_18ACD500: return "SUBDEVICE_18ACD500";
        case PciSubDevice14F18811::SUBDEVICE_18ACD810: return "SUBDEVICE_18ACD810";
        case PciSubDevice14F18811::SUBDEVICE_18ACD820: return "SUBDEVICE_18ACD820";
        case PciSubDevice14F18811::SUBDEVICE_18ACDB00: return "SUBDEVICE_18ACDB00";
        case PciSubDevice14F18811::SUBDEVICE_56542388: return "SUBDEVICE_56542388";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F18811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F18811 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18811::SUBDEVICE_00703400: return "WinTV 34604";
        case PciSubDevice14F18811::SUBDEVICE_00703401: return "Hauppauge WinTV 34xxx models";
        case PciSubDevice14F18811::SUBDEVICE_00706902: return "WinTV HVR-4000-HD";
        case PciSubDevice14F18811::SUBDEVICE_00709402: return "WinTV-HVR1100 DVB-T/Hybrid";
        case PciSubDevice14F18811::SUBDEVICE_00709600: return "WinTV 88x Audio";
        case PciSubDevice14F18811::SUBDEVICE_14628606: return "MSI TV-@nywhere Master";
        case PciSubDevice14F18811::SUBDEVICE_18ACD500: return "DViCO FusionHDTV5 Gold";
        case PciSubDevice14F18811::SUBDEVICE_18ACD810: return "DViCO FusionHDTV3 Gold-Q";
        case PciSubDevice14F18811::SUBDEVICE_18ACD820: return "DViCO FusionHDTV3 Gold-T";
        case PciSubDevice14F18811::SUBDEVICE_18ACDB00: return "DVICO FusionHDTV DVB-T1";
        case PciSubDevice14F18811::SUBDEVICE_56542388: return "GoTView PCI Hybrid Audio Capture Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18811_H
