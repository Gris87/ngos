// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10001960_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10001960_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10001960: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10000518 = 0x10000518,
    SUBDEVICE_10000520 = 0x10000520,
    SUBDEVICE_10000522 = 0x10000522,
    SUBDEVICE_10000523 = 0x10000523,
    SUBDEVICE_10004523 = 0x10004523,
    SUBDEVICE_1000A520 = 0x1000A520,
    SUBDEVICE_10280518 = 0x10280518,
    SUBDEVICE_10280520 = 0x10280520,
    SUBDEVICE_10280531 = 0x10280531,
    SUBDEVICE_10280533 = 0x10280533,
    SUBDEVICE_80860520 = 0x80860520,
    SUBDEVICE_80860523 = 0x80860523
};



inline const char8* enumToString(PciSubDevice10001960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10001960::NONE:               return "NONE";
        case PciSubDevice10001960::SUBDEVICE_10000518: return "SUBDEVICE_10000518";
        case PciSubDevice10001960::SUBDEVICE_10000520: return "SUBDEVICE_10000520";
        case PciSubDevice10001960::SUBDEVICE_10000522: return "SUBDEVICE_10000522";
        case PciSubDevice10001960::SUBDEVICE_10000523: return "SUBDEVICE_10000523";
        case PciSubDevice10001960::SUBDEVICE_10004523: return "SUBDEVICE_10004523";
        case PciSubDevice10001960::SUBDEVICE_1000A520: return "SUBDEVICE_1000A520";
        case PciSubDevice10001960::SUBDEVICE_10280518: return "SUBDEVICE_10280518";
        case PciSubDevice10001960::SUBDEVICE_10280520: return "SUBDEVICE_10280520";
        case PciSubDevice10001960::SUBDEVICE_10280531: return "SUBDEVICE_10280531";
        case PciSubDevice10001960::SUBDEVICE_10280533: return "SUBDEVICE_10280533";
        case PciSubDevice10001960::SUBDEVICE_80860520: return "SUBDEVICE_80860520";
        case PciSubDevice10001960::SUBDEVICE_80860523: return "SUBDEVICE_80860523";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10001960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10001960 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10001960::SUBDEVICE_10000518: return "MegaRAID 518 SCSI 320-2 Controller";
        case PciSubDevice10001960::SUBDEVICE_10000520: return "MegaRAID 520 SCSI 320-1 Controller";
        case PciSubDevice10001960::SUBDEVICE_10000522: return "MegaRAID 522 i4 133 RAID Controller";
        case PciSubDevice10001960::SUBDEVICE_10000523: return "MegaRAID SATA 150-6 RAID Controller";
        case PciSubDevice10001960::SUBDEVICE_10004523: return "MegaRAID SATA 150-4 RAID Controller";
        case PciSubDevice10001960::SUBDEVICE_1000A520: return "MegaRAID ZCR SCSI 320-0 Controller";
        case PciSubDevice10001960::SUBDEVICE_10280518: return "MegaRAID 518 DELL PERC 4/DC RAID Controller";
        case PciSubDevice10001960::SUBDEVICE_10280520: return "MegaRAID 520 DELL PERC 4/SC RAID Controller";
        case PciSubDevice10001960::SUBDEVICE_10280531: return "PowerEdge Expandable RAID Controller 4/QC";
        case PciSubDevice10001960::SUBDEVICE_10280533: return "PowerEdge Expandable RAID Controller 4/QC";
        case PciSubDevice10001960::SUBDEVICE_80860520: return "MegaRAID RAID Controller SRCU41L";
        case PciSubDevice10001960::SUBDEVICE_80860523: return "MegaRAID RAID Controller SRCS16";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10001960_H
