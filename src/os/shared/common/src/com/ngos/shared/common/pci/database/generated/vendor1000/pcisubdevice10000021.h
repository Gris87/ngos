// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000021_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000021_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000021: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10001000 = 0x10001000,
    SUBDEVICE_10001010 = 0x10001010,
    SUBDEVICE_103C1300 = 0x103C1300,
    SUBDEVICE_103C1310 = 0x103C1310,
    SUBDEVICE_103C1330 = 0x103C1330,
    SUBDEVICE_103C1340 = 0x103C1340,
    SUBDEVICE_124B1070 = 0x124B1070,
    SUBDEVICE_4C531080 = 0x4C531080,
    SUBDEVICE_4C531300 = 0x4C531300,
    SUBDEVICE_4C531310 = 0x4C531310
};



inline const char8* enumToString(PciSubDevice10000021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000021::NONE:               return "NONE";
        case PciSubDevice10000021::SUBDEVICE_10001000: return "SUBDEVICE_10001000";
        case PciSubDevice10000021::SUBDEVICE_10001010: return "SUBDEVICE_10001010";
        case PciSubDevice10000021::SUBDEVICE_103C1300: return "SUBDEVICE_103C1300";
        case PciSubDevice10000021::SUBDEVICE_103C1310: return "SUBDEVICE_103C1310";
        case PciSubDevice10000021::SUBDEVICE_103C1330: return "SUBDEVICE_103C1330";
        case PciSubDevice10000021::SUBDEVICE_103C1340: return "SUBDEVICE_103C1340";
        case PciSubDevice10000021::SUBDEVICE_124B1070: return "SUBDEVICE_124B1070";
        case PciSubDevice10000021::SUBDEVICE_4C531080: return "SUBDEVICE_4C531080";
        case PciSubDevice10000021::SUBDEVICE_4C531300: return "SUBDEVICE_4C531300";
        case PciSubDevice10000021::SUBDEVICE_4C531310: return "SUBDEVICE_4C531310";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000021 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000021::SUBDEVICE_10001000: return "LSI53C1000/1000R/1010R/1010-66 PCI to Ultra160 SCSI Controller";
        case PciSubDevice10000021::SUBDEVICE_10001010: return "Asus TR-DLS onboard 53C1010-66";
        case PciSubDevice10000021::SUBDEVICE_103C1300: return "Ultra160 SCSI [AB306A]";
        case PciSubDevice10000021::SUBDEVICE_103C1310: return "Ultra160 SCSI [A9918A]";
        case PciSubDevice10000021::SUBDEVICE_103C1330: return "Ultra160 SCSI [A7059A]";
        case PciSubDevice10000021::SUBDEVICE_103C1340: return "Ultra160 SCSI [A7060A]";
        case PciSubDevice10000021::SUBDEVICE_124B1070: return "PMC-USCSI3";
        case PciSubDevice10000021::SUBDEVICE_4C531080: return "CT8 mainboard";
        case PciSubDevice10000021::SUBDEVICE_4C531300: return "P017 mezzanine (32-bit PMC)";
        case PciSubDevice10000021::SUBDEVICE_4C531310: return "P017 mezzanine (64-bit PMC)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000021_H
