// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AF4_PCIDEVICE1AF4_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AF4_PCIDEVICE1AF4_H



#include <com/ngos/shared/common/log/assert.h>
#include <com/ngos/shared/common/log/log.h>
#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AF4: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_1000 = 0x1000,
    DEVICE_1001 = 0x1001,
    DEVICE_1002 = 0x1002,
    DEVICE_1003 = 0x1003,
    DEVICE_1004 = 0x1004,
    DEVICE_1005 = 0x1005,
    DEVICE_1009 = 0x1009,
    DEVICE_1041 = 0x1041,
    DEVICE_1042 = 0x1042,
    DEVICE_1043 = 0x1043,
    DEVICE_1044 = 0x1044,
    DEVICE_1045 = 0x1045,
    DEVICE_1048 = 0x1048,
    DEVICE_1049 = 0x1049,
    DEVICE_1050 = 0x1050,
    DEVICE_1052 = 0x1052,
    DEVICE_1053 = 0x1053,
    DEVICE_1110 = 0x1110
};



inline const char8* enumToString(PciDevice1AF4 device1AF4) // TEST: NO
{
    // COMMON_LT((" | device1AF4 = %u", device1AF4)); // Commented to avoid bad looking logs



    switch (device1AF4)
    {
        case PciDevice1AF4::NONE:        return "NONE";
        case PciDevice1AF4::DEVICE_1000: return "DEVICE_1000";
        case PciDevice1AF4::DEVICE_1001: return "DEVICE_1001";
        case PciDevice1AF4::DEVICE_1002: return "DEVICE_1002";
        case PciDevice1AF4::DEVICE_1003: return "DEVICE_1003";
        case PciDevice1AF4::DEVICE_1004: return "DEVICE_1004";
        case PciDevice1AF4::DEVICE_1005: return "DEVICE_1005";
        case PciDevice1AF4::DEVICE_1009: return "DEVICE_1009";
        case PciDevice1AF4::DEVICE_1041: return "DEVICE_1041";
        case PciDevice1AF4::DEVICE_1042: return "DEVICE_1042";
        case PciDevice1AF4::DEVICE_1043: return "DEVICE_1043";
        case PciDevice1AF4::DEVICE_1044: return "DEVICE_1044";
        case PciDevice1AF4::DEVICE_1045: return "DEVICE_1045";
        case PciDevice1AF4::DEVICE_1048: return "DEVICE_1048";
        case PciDevice1AF4::DEVICE_1049: return "DEVICE_1049";
        case PciDevice1AF4::DEVICE_1050: return "DEVICE_1050";
        case PciDevice1AF4::DEVICE_1052: return "DEVICE_1052";
        case PciDevice1AF4::DEVICE_1053: return "DEVICE_1053";
        case PciDevice1AF4::DEVICE_1110: return "DEVICE_1110";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AF4 device1AF4) // TEST: NO
{
    // COMMON_LT((" | device1AF4 = %u", device1AF4)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1AF4, enumToString(device1AF4));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AF4 device1AF4) // TEST: NO
{
    // COMMON_LT((" | device1AF4 = %u", device1AF4)); // Commented to avoid bad looking logs



    switch (device1AF4)
    {
        case PciDevice1AF4::DEVICE_1000: return "Virtio network device";
        case PciDevice1AF4::DEVICE_1001: return "Virtio block device";
        case PciDevice1AF4::DEVICE_1002: return "Virtio memory balloon";
        case PciDevice1AF4::DEVICE_1003: return "Virtio console";
        case PciDevice1AF4::DEVICE_1004: return "Virtio SCSI";
        case PciDevice1AF4::DEVICE_1005: return "Virtio RNG";
        case PciDevice1AF4::DEVICE_1009: return "Virtio filesystem";
        case PciDevice1AF4::DEVICE_1041: return "Virtio network device";
        case PciDevice1AF4::DEVICE_1042: return "Virtio block device";
        case PciDevice1AF4::DEVICE_1043: return "Virtio console";
        case PciDevice1AF4::DEVICE_1044: return "Virtio RNG";
        case PciDevice1AF4::DEVICE_1045: return "Virtio memory balloon";
        case PciDevice1AF4::DEVICE_1048: return "Virtio SCSI";
        case PciDevice1AF4::DEVICE_1049: return "Virtio filesystem";
        case PciDevice1AF4::DEVICE_1050: return "Virtio GPU";
        case PciDevice1AF4::DEVICE_1052: return "Virtio input";
        case PciDevice1AF4::DEVICE_1053: return "Virtio socket";
        case PciDevice1AF4::DEVICE_1110: return "Inter-VM shared memory";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AF4_PCIDEVICE1AF4_H
