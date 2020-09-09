// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000408_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000408_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000408: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10000001 = 0x10000001,
    SUBDEVICE_10000002 = 0x10000002,
    SUBDEVICE_1025004D = 0x1025004D,
    SUBDEVICE_10280001 = 0x10280001,
    SUBDEVICE_10280002 = 0x10280002,
    SUBDEVICE_10280012 = 0x10280012,
    SUBDEVICE_10280015 = 0x10280015,
    SUBDEVICE_10281F03 = 0x10281F03,
    SUBDEVICE_17341065 = 0x17341065,
    SUBDEVICE_80860002 = 0x80860002,
    SUBDEVICE_80863449 = 0x80863449
};



inline const char8* enumToString(PciSubDevice10000408 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000408::NONE:               return "NONE";
        case PciSubDevice10000408::SUBDEVICE_10000001: return "SUBDEVICE_10000001";
        case PciSubDevice10000408::SUBDEVICE_10000002: return "SUBDEVICE_10000002";
        case PciSubDevice10000408::SUBDEVICE_1025004D: return "SUBDEVICE_1025004D";
        case PciSubDevice10000408::SUBDEVICE_10280001: return "SUBDEVICE_10280001";
        case PciSubDevice10000408::SUBDEVICE_10280002: return "SUBDEVICE_10280002";
        case PciSubDevice10000408::SUBDEVICE_10280012: return "SUBDEVICE_10280012";
        case PciSubDevice10000408::SUBDEVICE_10280015: return "SUBDEVICE_10280015";
        case PciSubDevice10000408::SUBDEVICE_10281F03: return "SUBDEVICE_10281F03";
        case PciSubDevice10000408::SUBDEVICE_17341065: return "SUBDEVICE_17341065";
        case PciSubDevice10000408::SUBDEVICE_80860002: return "SUBDEVICE_80860002";
        case PciSubDevice10000408::SUBDEVICE_80863449: return "SUBDEVICE_80863449";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000408 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000408 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000408::SUBDEVICE_10000001: return "MegaRAID SCSI 320-1E RAID Controller";
        case PciSubDevice10000408::SUBDEVICE_10000002: return "MegaRAID SCSI 320-2E RAID Controller";
        case PciSubDevice10000408::SUBDEVICE_1025004D: return "MegaRAID ACER ROMB-2E RAID Controller";
        case PciSubDevice10000408::SUBDEVICE_10280001: return "PowerEdge RAID Controller PERC4e/SC";
        case PciSubDevice10000408::SUBDEVICE_10280002: return "PowerEdge RAID Controller PERC4e/DC";
        case PciSubDevice10000408::SUBDEVICE_10280012: return "PowerEdge RAID Controller RAC4";
        case PciSubDevice10000408::SUBDEVICE_10280015: return "PowerEdge RAID Controller PERC5";
        case PciSubDevice10000408::SUBDEVICE_10281F03: return "PowerEdge RAID Controller PERC5";
        case PciSubDevice10000408::SUBDEVICE_17341065: return "FSC MegaRAID PCI Express ROMB";
        case PciSubDevice10000408::SUBDEVICE_80860002: return "MegaRAID Intel RAID Controller SRCU42E";
        case PciSubDevice10000408::SUBDEVICE_80863449: return "MegaRAID Intel RAID Controller SROMBU";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000408_H
