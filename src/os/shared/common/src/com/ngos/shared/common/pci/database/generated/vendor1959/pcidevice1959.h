// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1959_PCIDEVICE1959_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1959_PCIDEVICE1959_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1959: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_A000 = 0xA000,
    DEVICE_A001 = 0xA001,
    DEVICE_A002 = 0xA002,
    DEVICE_A003 = 0xA003,
    DEVICE_A004 = 0xA004,
    DEVICE_A005 = 0xA005,
    DEVICE_A006 = 0xA006,
    DEVICE_A007 = 0xA007,
    DEVICE_A008 = 0xA008,
    DEVICE_A009 = 0xA009,
    DEVICE_A00A = 0xA00A,
    DEVICE_A00B = 0xA00B,
    DEVICE_A00C = 0xA00C,
    DEVICE_A00D = 0xA00D
};



inline const char8* enumToString(PciDevice1959 device1959) // TEST: NO
{
    // COMMON_LT((" | device1959 = %u", device1959)); // Commented to avoid bad looking logs



    switch (device1959)
    {
        case PciDevice1959::NONE:        return "NONE";
        case PciDevice1959::DEVICE_A000: return "DEVICE_A000";
        case PciDevice1959::DEVICE_A001: return "DEVICE_A001";
        case PciDevice1959::DEVICE_A002: return "DEVICE_A002";
        case PciDevice1959::DEVICE_A003: return "DEVICE_A003";
        case PciDevice1959::DEVICE_A004: return "DEVICE_A004";
        case PciDevice1959::DEVICE_A005: return "DEVICE_A005";
        case PciDevice1959::DEVICE_A006: return "DEVICE_A006";
        case PciDevice1959::DEVICE_A007: return "DEVICE_A007";
        case PciDevice1959::DEVICE_A008: return "DEVICE_A008";
        case PciDevice1959::DEVICE_A009: return "DEVICE_A009";
        case PciDevice1959::DEVICE_A00A: return "DEVICE_A00A";
        case PciDevice1959::DEVICE_A00B: return "DEVICE_A00B";
        case PciDevice1959::DEVICE_A00C: return "DEVICE_A00C";
        case PciDevice1959::DEVICE_A00D: return "DEVICE_A00D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1959 device1959) // TEST: NO
{
    // COMMON_LT((" | device1959 = %u", device1959)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1959, enumToString(device1959));

    return res;
}



inline const char8* enumToHumanString(PciDevice1959 device1959) // TEST: NO
{
    // COMMON_LT((" | device1959 = %u", device1959)); // Commented to avoid bad looking logs



    switch (device1959)
    {
        case PciDevice1959::DEVICE_A000: return "PA6T Core";
        case PciDevice1959::DEVICE_A001: return "PWRficient Host Bridge";
        case PciDevice1959::DEVICE_A002: return "PWRficient PCI-Express Port";
        case PciDevice1959::DEVICE_A003: return "PWRficient SMBus Controller";
        case PciDevice1959::DEVICE_A004: return "PWRficient 16550 UART";
        case PciDevice1959::DEVICE_A005: return "PWRficient Gigabit Ethernet";
        case PciDevice1959::DEVICE_A006: return "PWRficient 10-Gigabit Ethernet";
        case PciDevice1959::DEVICE_A007: return "PWRficient DMA Controller";
        case PciDevice1959::DEVICE_A008: return "PWRficient LPC/Localbus Interface";
        case PciDevice1959::DEVICE_A009: return "PWRficient L2 Cache";
        case PciDevice1959::DEVICE_A00A: return "PWRficient DDR2 Memory Controller";
        case PciDevice1959::DEVICE_A00B: return "PWRficient SERDES";
        case PciDevice1959::DEVICE_A00C: return "PWRficient System/Debug Controller";
        case PciDevice1959::DEVICE_A00D: return "PWRficient PCI-Express Internal Endpoint";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1959_PCIDEVICE1959_H
