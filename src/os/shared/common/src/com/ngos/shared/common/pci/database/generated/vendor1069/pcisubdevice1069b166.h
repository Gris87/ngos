// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069B166_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069B166_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1069B166: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140242 = 0x10140242,
    SUBDEVICE_10140266 = 0x10140266,
    SUBDEVICE_10140278 = 0x10140278,
    SUBDEVICE_101402D3 = 0x101402D3,
    SUBDEVICE_101402D4 = 0x101402D4,
    SUBDEVICE_10690200 = 0x10690200,
    SUBDEVICE_10690202 = 0x10690202,
    SUBDEVICE_10690204 = 0x10690204,
    SUBDEVICE_10690206 = 0x10690206
};



inline const char8* enumToString(PciSubDevice1069B166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1069B166::NONE:               return "NONE";
        case PciSubDevice1069B166::SUBDEVICE_10140242: return "SUBDEVICE_10140242";
        case PciSubDevice1069B166::SUBDEVICE_10140266: return "SUBDEVICE_10140266";
        case PciSubDevice1069B166::SUBDEVICE_10140278: return "SUBDEVICE_10140278";
        case PciSubDevice1069B166::SUBDEVICE_101402D3: return "SUBDEVICE_101402D3";
        case PciSubDevice1069B166::SUBDEVICE_101402D4: return "SUBDEVICE_101402D4";
        case PciSubDevice1069B166::SUBDEVICE_10690200: return "SUBDEVICE_10690200";
        case PciSubDevice1069B166::SUBDEVICE_10690202: return "SUBDEVICE_10690202";
        case PciSubDevice1069B166::SUBDEVICE_10690204: return "SUBDEVICE_10690204";
        case PciSubDevice1069B166::SUBDEVICE_10690206: return "SUBDEVICE_10690206";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1069B166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1069B166 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1069B166::SUBDEVICE_10140242: return "iSeries 2872 DASD IOA";
        case PciSubDevice1069B166::SUBDEVICE_10140266: return "Dual Channel PCI-X u320 SCSI Adapter";
        case PciSubDevice1069B166::SUBDEVICE_10140278: return "Dual Channel PCI-X u320 SCSI RAID Adapter";
        case PciSubDevice1069B166::SUBDEVICE_101402D3: return "Dual Channel PCI-X u320 SCSI Adapter";
        case PciSubDevice1069B166::SUBDEVICE_101402D4: return "Dual Channel PCI-X u320 SCSI RAID Adapter";
        case PciSubDevice1069B166::SUBDEVICE_10690200: return "AcceleRAID 400, Single Channel, PCI-X, u320, SCSI RAID";
        case PciSubDevice1069B166::SUBDEVICE_10690202: return "AcceleRAID Sapphire, Dual Channel, PCI-X, u320, SCSI RAID";
        case PciSubDevice1069B166::SUBDEVICE_10690204: return "AcceleRAID 500, Dual Channel, Low-Profile, PCI-X, u320, SCSI RAID";
        case PciSubDevice1069B166::SUBDEVICE_10690206: return "AcceleRAID 600, Dual Channel, PCI-X, u320, SCSI RAID";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1069_PCISUBDEVICE1069B166_H
