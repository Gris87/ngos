// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1101_PCIDEVICE1101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1101_PCIDEVICE1101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1101: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0002 = 0x0002,
    DEVICE_1060 = 0x1060,
    DEVICE_1622 = 0x1622,
    DEVICE_9100 = 0x9100,
    DEVICE_9400 = 0x9400,
    DEVICE_9401 = 0x9401,
    DEVICE_9500 = 0x9500,
    DEVICE_9502 = 0x9502
};



inline const char8* enumToString(PciDevice1101 device1101) // TEST: NO
{
    // COMMON_LT((" | device1101 = %u", device1101)); // Commented to avoid bad looking logs



    switch (device1101)
    {
        case PciDevice1101::NONE:        return "NONE";
        case PciDevice1101::DEVICE_0002: return "DEVICE_0002";
        case PciDevice1101::DEVICE_1060: return "DEVICE_1060";
        case PciDevice1101::DEVICE_1622: return "DEVICE_1622";
        case PciDevice1101::DEVICE_9100: return "DEVICE_9100";
        case PciDevice1101::DEVICE_9400: return "DEVICE_9400";
        case PciDevice1101::DEVICE_9401: return "DEVICE_9401";
        case PciDevice1101::DEVICE_9500: return "DEVICE_9500";
        case PciDevice1101::DEVICE_9502: return "DEVICE_9502";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1101 device1101) // TEST: NO
{
    // COMMON_LT((" | device1101 = %u", device1101)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1101, enumToString(device1101));

    return res;
}



inline const char8* enumToHumanString(PciDevice1101 device1101) // TEST: NO
{
    // COMMON_LT((" | device1101 = %u", device1101)); // Commented to avoid bad looking logs



    switch (device1101)
    {
        case PciDevice1101::DEVICE_0002: return "INI-920 Ultra SCSI Adapter";
        case PciDevice1101::DEVICE_1060: return "INI-A100U2W";
        case PciDevice1101::DEVICE_1622: return "INI-1623 PCI SATA-II Controller";
        case PciDevice1101::DEVICE_9100: return "INI-9100/9100W";
        case PciDevice1101::DEVICE_9400: return "INI-940 Fast Wide SCSI Adapter";
        case PciDevice1101::DEVICE_9401: return "INI-935 Fast Wide SCSI Adapter";
        case PciDevice1101::DEVICE_9500: return "INI-950 SCSI Adapter";
        case PciDevice1101::DEVICE_9502: return "INI-950P Ultra Wide SCSI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1101_PCIDEVICE1101_H
