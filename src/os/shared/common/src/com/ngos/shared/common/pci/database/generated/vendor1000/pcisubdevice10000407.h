// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000407_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000407_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000407: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10000530 = 0x10000530,
    SUBDEVICE_10000531 = 0x10000531,
    SUBDEVICE_10000532 = 0x10000532,
    SUBDEVICE_10280531 = 0x10280531,
    SUBDEVICE_10280533 = 0x10280533,
    SUBDEVICE_80860530 = 0x80860530,
    SUBDEVICE_80860532 = 0x80860532
};



inline const char8* enumToString(PciSubDevice10000407 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000407::NONE:               return "NONE";
        case PciSubDevice10000407::SUBDEVICE_10000530: return "SUBDEVICE_10000530";
        case PciSubDevice10000407::SUBDEVICE_10000531: return "SUBDEVICE_10000531";
        case PciSubDevice10000407::SUBDEVICE_10000532: return "SUBDEVICE_10000532";
        case PciSubDevice10000407::SUBDEVICE_10280531: return "SUBDEVICE_10280531";
        case PciSubDevice10000407::SUBDEVICE_10280533: return "SUBDEVICE_10280533";
        case PciSubDevice10000407::SUBDEVICE_80860530: return "SUBDEVICE_80860530";
        case PciSubDevice10000407::SUBDEVICE_80860532: return "SUBDEVICE_80860532";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000407 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000407 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000407::SUBDEVICE_10000530: return "MegaRAID 530 SCSI 320-0X RAID Controller";
        case PciSubDevice10000407::SUBDEVICE_10000531: return "MegaRAID 531 SCSI 320-4X RAID Controller";
        case PciSubDevice10000407::SUBDEVICE_10000532: return "MegaRAID 532 SCSI 320-2X RAID Controller";
        case PciSubDevice10000407::SUBDEVICE_10280531: return "PowerEdge Expandable RAID Controller 4/QC";
        case PciSubDevice10000407::SUBDEVICE_10280533: return "PowerEdge Expandable RAID Controller 4/QC";
        case PciSubDevice10000407::SUBDEVICE_80860530: return "MegaRAID Intel RAID Controller SRCZCRX";
        case PciSubDevice10000407::SUBDEVICE_80860532: return "MegaRAID Intel RAID Controller SRCU42X";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000407_H
