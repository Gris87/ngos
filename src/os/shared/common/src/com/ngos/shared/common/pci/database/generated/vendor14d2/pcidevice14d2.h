// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D2_PCIDEVICE14D2_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D2_PCIDEVICE14D2_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice14D2: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_8001 = 0x8001,
    DEVICE_8002 = 0x8002,
    DEVICE_8010 = 0x8010,
    DEVICE_8011 = 0x8011,
    DEVICE_8020 = 0x8020,
    DEVICE_8021 = 0x8021,
    DEVICE_8028 = 0x8028,
    DEVICE_8040 = 0x8040,
    DEVICE_8043 = 0x8043,
    DEVICE_8048 = 0x8048,
    DEVICE_8080 = 0x8080,
    DEVICE_8088 = 0x8088,
    DEVICE_A000 = 0xA000,
    DEVICE_A001 = 0xA001,
    DEVICE_A003 = 0xA003,
    DEVICE_A004 = 0xA004,
    DEVICE_A005 = 0xA005,
    DEVICE_A007 = 0xA007,
    DEVICE_A008 = 0xA008,
    DEVICE_A009 = 0xA009,
    DEVICE_E001 = 0xE001,
    DEVICE_E010 = 0xE010,
    DEVICE_E020 = 0xE020
};



inline const char8* enumToString(PciDevice14D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14D2::NONE:        return "NONE";
        case PciDevice14D2::DEVICE_8001: return "DEVICE_8001";
        case PciDevice14D2::DEVICE_8002: return "DEVICE_8002";
        case PciDevice14D2::DEVICE_8010: return "DEVICE_8010";
        case PciDevice14D2::DEVICE_8011: return "DEVICE_8011";
        case PciDevice14D2::DEVICE_8020: return "DEVICE_8020";
        case PciDevice14D2::DEVICE_8021: return "DEVICE_8021";
        case PciDevice14D2::DEVICE_8028: return "DEVICE_8028";
        case PciDevice14D2::DEVICE_8040: return "DEVICE_8040";
        case PciDevice14D2::DEVICE_8043: return "DEVICE_8043";
        case PciDevice14D2::DEVICE_8048: return "DEVICE_8048";
        case PciDevice14D2::DEVICE_8080: return "DEVICE_8080";
        case PciDevice14D2::DEVICE_8088: return "DEVICE_8088";
        case PciDevice14D2::DEVICE_A000: return "DEVICE_A000";
        case PciDevice14D2::DEVICE_A001: return "DEVICE_A001";
        case PciDevice14D2::DEVICE_A003: return "DEVICE_A003";
        case PciDevice14D2::DEVICE_A004: return "DEVICE_A004";
        case PciDevice14D2::DEVICE_A005: return "DEVICE_A005";
        case PciDevice14D2::DEVICE_A007: return "DEVICE_A007";
        case PciDevice14D2::DEVICE_A008: return "DEVICE_A008";
        case PciDevice14D2::DEVICE_A009: return "DEVICE_A009";
        case PciDevice14D2::DEVICE_E001: return "DEVICE_E001";
        case PciDevice14D2::DEVICE_E010: return "DEVICE_E010";
        case PciDevice14D2::DEVICE_E020: return "DEVICE_E020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice14D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice14D2 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice14D2::DEVICE_8001: return "VScom 010L 1 port parallel adaptor";
        case PciDevice14D2::DEVICE_8002: return "VScom 020L 2 port parallel adaptor";
        case PciDevice14D2::DEVICE_8010: return "VScom 100L 1 port serial adaptor";
        case PciDevice14D2::DEVICE_8011: return "VScom 110L 1 port serial and 1 port parallel adaptor";
        case PciDevice14D2::DEVICE_8020: return "VScom 200L 1 or 2 port serial adaptor";
        case PciDevice14D2::DEVICE_8021: return "VScom 210L 2 port serial and 1 port parallel adaptor";
        case PciDevice14D2::DEVICE_8028: return "VScom 200I/200I-SI 2-port serial adapter";
        case PciDevice14D2::DEVICE_8040: return "VScom 400L 4 port serial adaptor";
        case PciDevice14D2::DEVICE_8043: return "VScom 430L 4-port serial and 3-port parallel adapter";
        case PciDevice14D2::DEVICE_8048: return "VScom 400I 4-port serial adapter";
        case PciDevice14D2::DEVICE_8080: return "VScom 800L 8 port serial adaptor";
        case PciDevice14D2::DEVICE_8088: return "VScom 800I 8-port serial adapter";
        case PciDevice14D2::DEVICE_A000: return "VScom 010H 1 port parallel adaptor";
        case PciDevice14D2::DEVICE_A001: return "VScom 100H 1 port serial adaptor";
        case PciDevice14D2::DEVICE_A003: return "VScom 400H 4 port serial adaptor";
        case PciDevice14D2::DEVICE_A004: return "VScom 400HF1 4 port serial adaptor";
        case PciDevice14D2::DEVICE_A005: return "VScom 200H 2 port serial adaptor";
        case PciDevice14D2::DEVICE_A007: return "VScom PCI800EH (PCIe) 8-port serial adapter Port 1-4";
        case PciDevice14D2::DEVICE_A008: return "VScom PCI800EH (PCIe) 8-port serial adapter Port 5-8";
        case PciDevice14D2::DEVICE_A009: return "VScom PCI400EH (PCIe) 4-port serial adapter";
        case PciDevice14D2::DEVICE_E001: return "VScom 010HV2 1 port parallel adaptor";
        case PciDevice14D2::DEVICE_E010: return "VScom 100HV2 1 port serial adaptor";
        case PciDevice14D2::DEVICE_E020: return "VScom 200HV2 2 port serial adaptor";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14D2_PCIDEVICE14D2_H
