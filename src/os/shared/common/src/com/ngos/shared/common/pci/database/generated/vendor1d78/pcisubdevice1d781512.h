// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D78_PCISUBDEVICE1D781512_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D78_PCISUBDEVICE1D781512_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1D781512: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1D782003 = 0x1D782003,
    SUBDEVICE_1D782004 = 0x1D782004,
    SUBDEVICE_1D782005 = 0x1D782005,
    SUBDEVICE_1D782006 = 0x1D782006,
    SUBDEVICE_1D782007 = 0x1D782007,
    SUBDEVICE_1D782008 = 0x1D782008,
    SUBDEVICE_1D782103 = 0x1D782103,
    SUBDEVICE_1D782104 = 0x1D782104,
    SUBDEVICE_1D782105 = 0x1D782105,
    SUBDEVICE_1D782106 = 0x1D782106,
    SUBDEVICE_1D782107 = 0x1D782107,
    SUBDEVICE_1D782108 = 0x1D782108
};



inline const char8* enumToString(PciSubDevice1D781512 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1D781512::NONE:               return "NONE";
        case PciSubDevice1D781512::SUBDEVICE_1D782003: return "SUBDEVICE_1D782003";
        case PciSubDevice1D781512::SUBDEVICE_1D782004: return "SUBDEVICE_1D782004";
        case PciSubDevice1D781512::SUBDEVICE_1D782005: return "SUBDEVICE_1D782005";
        case PciSubDevice1D781512::SUBDEVICE_1D782006: return "SUBDEVICE_1D782006";
        case PciSubDevice1D781512::SUBDEVICE_1D782007: return "SUBDEVICE_1D782007";
        case PciSubDevice1D781512::SUBDEVICE_1D782008: return "SUBDEVICE_1D782008";
        case PciSubDevice1D781512::SUBDEVICE_1D782103: return "SUBDEVICE_1D782103";
        case PciSubDevice1D781512::SUBDEVICE_1D782104: return "SUBDEVICE_1D782104";
        case PciSubDevice1D781512::SUBDEVICE_1D782105: return "SUBDEVICE_1D782105";
        case PciSubDevice1D781512::SUBDEVICE_1D782106: return "SUBDEVICE_1D782106";
        case PciSubDevice1D781512::SUBDEVICE_1D782107: return "SUBDEVICE_1D782107";
        case PciSubDevice1D781512::SUBDEVICE_1D782108: return "SUBDEVICE_1D782108";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1D781512 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1D781512 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1D781512::SUBDEVICE_1D782003: return "D5457 HHHL 1.6TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782004: return "D5437 HHHL 2TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782005: return "D5457 HHHL 3.2TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782006: return "D5437 HHHL 4TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782007: return "D5457 HHHL 6.4TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782008: return "D5437 HHHL 8TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782103: return "D5457 U.2 1.6TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782104: return "D5437 U.2 2TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782105: return "D5457 U.2 3.2TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782106: return "D5437 U.2 4TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782107: return "D5457 U.2 6.4TB NVMe SSD";
        case PciSubDevice1D781512::SUBDEVICE_1D782108: return "D5437 U.2 8TB NVMe SSD";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1D78_PCISUBDEVICE1D781512_H
