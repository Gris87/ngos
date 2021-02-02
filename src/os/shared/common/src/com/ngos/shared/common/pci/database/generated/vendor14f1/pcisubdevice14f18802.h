// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18802_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18802_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F18802: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_00702801 = 0x00702801,
    SUBDEVICE_00706902 = 0x00706902,
    SUBDEVICE_00709002 = 0x00709002,
    SUBDEVICE_00709402 = 0x00709402,
    SUBDEVICE_00709600 = 0x00709600,
    SUBDEVICE_10434823 = 0x10434823,
    SUBDEVICE_107D663C = 0x107D663C,
    SUBDEVICE_107D665F = 0x107D665F,
    SUBDEVICE_14F10187 = 0x14F10187,
    SUBDEVICE_17DE08A1 = 0x17DE08A1,
    SUBDEVICE_17DE08A6 = 0x17DE08A6,
    SUBDEVICE_18ACD500 = 0x18ACD500,
    SUBDEVICE_18ACD810 = 0x18ACD810,
    SUBDEVICE_18ACD820 = 0x18ACD820,
    SUBDEVICE_18ACDB00 = 0x18ACDB00,
    SUBDEVICE_18ACDB10 = 0x18ACDB10,
    SUBDEVICE_56542388 = 0x56542388,
    SUBDEVICE_70633000 = 0x70633000,
    SUBDEVICE_70635500 = 0x70635500
};



inline const char8* enumToString(PciSubDevice14F18802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18802::NONE:               return "NONE";
        case PciSubDevice14F18802::SUBDEVICE_00702801: return "SUBDEVICE_00702801";
        case PciSubDevice14F18802::SUBDEVICE_00706902: return "SUBDEVICE_00706902";
        case PciSubDevice14F18802::SUBDEVICE_00709002: return "SUBDEVICE_00709002";
        case PciSubDevice14F18802::SUBDEVICE_00709402: return "SUBDEVICE_00709402";
        case PciSubDevice14F18802::SUBDEVICE_00709600: return "SUBDEVICE_00709600";
        case PciSubDevice14F18802::SUBDEVICE_10434823: return "SUBDEVICE_10434823";
        case PciSubDevice14F18802::SUBDEVICE_107D663C: return "SUBDEVICE_107D663C";
        case PciSubDevice14F18802::SUBDEVICE_107D665F: return "SUBDEVICE_107D665F";
        case PciSubDevice14F18802::SUBDEVICE_14F10187: return "SUBDEVICE_14F10187";
        case PciSubDevice14F18802::SUBDEVICE_17DE08A1: return "SUBDEVICE_17DE08A1";
        case PciSubDevice14F18802::SUBDEVICE_17DE08A6: return "SUBDEVICE_17DE08A6";
        case PciSubDevice14F18802::SUBDEVICE_18ACD500: return "SUBDEVICE_18ACD500";
        case PciSubDevice14F18802::SUBDEVICE_18ACD810: return "SUBDEVICE_18ACD810";
        case PciSubDevice14F18802::SUBDEVICE_18ACD820: return "SUBDEVICE_18ACD820";
        case PciSubDevice14F18802::SUBDEVICE_18ACDB00: return "SUBDEVICE_18ACDB00";
        case PciSubDevice14F18802::SUBDEVICE_18ACDB10: return "SUBDEVICE_18ACDB10";
        case PciSubDevice14F18802::SUBDEVICE_56542388: return "SUBDEVICE_56542388";
        case PciSubDevice14F18802::SUBDEVICE_70633000: return "SUBDEVICE_70633000";
        case PciSubDevice14F18802::SUBDEVICE_70635500: return "SUBDEVICE_70635500";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F18802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F18802 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F18802::SUBDEVICE_00702801: return "Hauppauge WinTV 28xxx (Roslyn) models";
        case PciSubDevice14F18802::SUBDEVICE_00706902: return "WinTV HVR-4000-HD";
        case PciSubDevice14F18802::SUBDEVICE_00709002: return "Nova-T DVB-T Model 909";
        case PciSubDevice14F18802::SUBDEVICE_00709402: return "WinTV-HVR1100 DVB-T/Hybrid";
        case PciSubDevice14F18802::SUBDEVICE_00709600: return "WinTV 88x MPEG Encoder";
        case PciSubDevice14F18802::SUBDEVICE_10434823: return "PVR-416";
        case PciSubDevice14F18802::SUBDEVICE_107D663C: return "Leadtek PVR 2000";
        case PciSubDevice14F18802::SUBDEVICE_107D665F: return "WinFast DTV1000-T";
        case PciSubDevice14F18802::SUBDEVICE_14F10187: return "Conexant DVB-T reference design";
        case PciSubDevice14F18802::SUBDEVICE_17DE08A1: return "XPert DVB-T PCI BDA DVBT 23880 Transport Stream Capture";
        case PciSubDevice14F18802::SUBDEVICE_17DE08A6: return "KWorld/VStream XPert DVB-T";
        case PciSubDevice14F18802::SUBDEVICE_18ACD500: return "DViCO FusionHDTV5 Gold";
        case PciSubDevice14F18802::SUBDEVICE_18ACD810: return "DViCO FusionHDTV3 Gold-Q";
        case PciSubDevice14F18802::SUBDEVICE_18ACD820: return "DViCO FusionHDTV3 Gold-T";
        case PciSubDevice14F18802::SUBDEVICE_18ACDB00: return "DVICO FusionHDTV DVB-T1";
        case PciSubDevice14F18802::SUBDEVICE_18ACDB10: return "DVICO FusionHDTV DVB-T Plus";
        case PciSubDevice14F18802::SUBDEVICE_56542388: return "GoTView PCI Hybrid TS Capture Device";
        case PciSubDevice14F18802::SUBDEVICE_70633000: return "pcHDTV HD3000 HDTV";
        case PciSubDevice14F18802::SUBDEVICE_70635500: return "pcHDTV HD-5500";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F18802_H
