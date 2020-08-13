// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCIDEVICE1B21_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCIDEVICE1B21_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1B21: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0611 = 0x0611,
    DEVICE_0612 = 0x0612,
    DEVICE_1042 = 0x1042,
    DEVICE_1080 = 0x1080,
    DEVICE_1142 = 0x1142,
    DEVICE_1184 = 0x1184,
    DEVICE_1242 = 0x1242,
    DEVICE_1343 = 0x1343,
    DEVICE_2142 = 0x2142,
    DEVICE_3242 = 0x3242
};



inline const char8* enumToString(PciDevice1B21 device1B21) // TEST: NO
{
    // COMMON_LT((" | device1B21 = %u", device1B21)); // Commented to avoid bad looking logs



    switch (device1B21)
    {
        case PciDevice1B21::NONE:        return "NONE";
        case PciDevice1B21::DEVICE_0611: return "DEVICE_0611";
        case PciDevice1B21::DEVICE_0612: return "DEVICE_0612";
        case PciDevice1B21::DEVICE_1042: return "DEVICE_1042";
        case PciDevice1B21::DEVICE_1080: return "DEVICE_1080";
        case PciDevice1B21::DEVICE_1142: return "DEVICE_1142";
        case PciDevice1B21::DEVICE_1184: return "DEVICE_1184";
        case PciDevice1B21::DEVICE_1242: return "DEVICE_1242";
        case PciDevice1B21::DEVICE_1343: return "DEVICE_1343";
        case PciDevice1B21::DEVICE_2142: return "DEVICE_2142";
        case PciDevice1B21::DEVICE_3242: return "DEVICE_3242";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1B21 device1B21) // TEST: NO
{
    // COMMON_LT((" | device1B21 = %u", device1B21)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1B21, enumToString(device1B21));

    return res;
}



inline const char8* enumToHumanString(PciDevice1B21 device1B21) // TEST: NO
{
    // COMMON_LT((" | device1B21 = %u", device1B21)); // Commented to avoid bad looking logs



    switch (device1B21)
    {
        case PciDevice1B21::DEVICE_0611: return "ASM1061 SATA IDE Controller";
        case PciDevice1B21::DEVICE_0612: return "ASM1062 Serial ATA Controller";
        case PciDevice1B21::DEVICE_1042: return "ASM1042 SuperSpeed USB Host Controller";
        case PciDevice1B21::DEVICE_1080: return "ASM1083/1085 PCIe to PCI Bridge";
        case PciDevice1B21::DEVICE_1142: return "ASM1042A USB 3.0 Host Controller";
        case PciDevice1B21::DEVICE_1184: return "ASM1184e PCIe Switch Port";
        case PciDevice1B21::DEVICE_1242: return "ASM1142 USB 3.1 Host Controller";
        case PciDevice1B21::DEVICE_1343: return "ASM1143 USB 3.1 Host Controller";
        case PciDevice1B21::DEVICE_2142: return "ASM2142 USB 3.1 Host Controller";
        case PciDevice1B21::DEVICE_3242: return "ASM3242 USB 3.2 Host Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B21_PCIDEVICE1B21_H
