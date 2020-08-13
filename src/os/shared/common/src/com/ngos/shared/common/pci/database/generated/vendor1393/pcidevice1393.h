// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1393_PCIDEVICE1393_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1393_PCIDEVICE1393_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1393: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_1020 = 0x1020,
    DEVICE_1021 = 0x1021,
    DEVICE_1022 = 0x1022,
    DEVICE_1023 = 0x1023,
    DEVICE_1024 = 0x1024,
    DEVICE_1025 = 0x1025,
    DEVICE_1040 = 0x1040,
    DEVICE_1041 = 0x1041,
    DEVICE_1042 = 0x1042,
    DEVICE_1043 = 0x1043,
    DEVICE_1044 = 0x1044,
    DEVICE_1045 = 0x1045,
    DEVICE_1080 = 0x1080,
    DEVICE_1140 = 0x1140,
    DEVICE_1141 = 0x1141,
    DEVICE_1142 = 0x1142,
    DEVICE_1143 = 0x1143,
    DEVICE_1144 = 0x1144,
    DEVICE_1180 = 0x1180,
    DEVICE_1181 = 0x1181,
    DEVICE_1182 = 0x1182,
    DEVICE_1320 = 0x1320,
    DEVICE_1321 = 0x1321,
    DEVICE_1322 = 0x1322,
    DEVICE_1340 = 0x1340,
    DEVICE_1341 = 0x1341,
    DEVICE_1380 = 0x1380,
    DEVICE_1680 = 0x1680,
    DEVICE_1681 = 0x1681,
    DEVICE_1682 = 0x1682,
    DEVICE_1683 = 0x1683,
    DEVICE_2040 = 0x2040,
    DEVICE_2180 = 0x2180,
    DEVICE_3200 = 0x3200
};



inline const char8* enumToString(PciDevice1393 device1393) // TEST: NO
{
    // COMMON_LT((" | device1393 = %u", device1393)); // Commented to avoid bad looking logs



    switch (device1393)
    {
        case PciDevice1393::NONE:        return "NONE";
        case PciDevice1393::DEVICE_0001: return "DEVICE_0001";
        case PciDevice1393::DEVICE_1020: return "DEVICE_1020";
        case PciDevice1393::DEVICE_1021: return "DEVICE_1021";
        case PciDevice1393::DEVICE_1022: return "DEVICE_1022";
        case PciDevice1393::DEVICE_1023: return "DEVICE_1023";
        case PciDevice1393::DEVICE_1024: return "DEVICE_1024";
        case PciDevice1393::DEVICE_1025: return "DEVICE_1025";
        case PciDevice1393::DEVICE_1040: return "DEVICE_1040";
        case PciDevice1393::DEVICE_1041: return "DEVICE_1041";
        case PciDevice1393::DEVICE_1042: return "DEVICE_1042";
        case PciDevice1393::DEVICE_1043: return "DEVICE_1043";
        case PciDevice1393::DEVICE_1044: return "DEVICE_1044";
        case PciDevice1393::DEVICE_1045: return "DEVICE_1045";
        case PciDevice1393::DEVICE_1080: return "DEVICE_1080";
        case PciDevice1393::DEVICE_1140: return "DEVICE_1140";
        case PciDevice1393::DEVICE_1141: return "DEVICE_1141";
        case PciDevice1393::DEVICE_1142: return "DEVICE_1142";
        case PciDevice1393::DEVICE_1143: return "DEVICE_1143";
        case PciDevice1393::DEVICE_1144: return "DEVICE_1144";
        case PciDevice1393::DEVICE_1180: return "DEVICE_1180";
        case PciDevice1393::DEVICE_1181: return "DEVICE_1181";
        case PciDevice1393::DEVICE_1182: return "DEVICE_1182";
        case PciDevice1393::DEVICE_1320: return "DEVICE_1320";
        case PciDevice1393::DEVICE_1321: return "DEVICE_1321";
        case PciDevice1393::DEVICE_1322: return "DEVICE_1322";
        case PciDevice1393::DEVICE_1340: return "DEVICE_1340";
        case PciDevice1393::DEVICE_1341: return "DEVICE_1341";
        case PciDevice1393::DEVICE_1380: return "DEVICE_1380";
        case PciDevice1393::DEVICE_1680: return "DEVICE_1680";
        case PciDevice1393::DEVICE_1681: return "DEVICE_1681";
        case PciDevice1393::DEVICE_1682: return "DEVICE_1682";
        case PciDevice1393::DEVICE_1683: return "DEVICE_1683";
        case PciDevice1393::DEVICE_2040: return "DEVICE_2040";
        case PciDevice1393::DEVICE_2180: return "DEVICE_2180";
        case PciDevice1393::DEVICE_3200: return "DEVICE_3200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1393 device1393) // TEST: NO
{
    // COMMON_LT((" | device1393 = %u", device1393)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1393, enumToString(device1393));

    return res;
}



inline const char8* enumToHumanString(PciDevice1393 device1393) // TEST: NO
{
    // COMMON_LT((" | device1393 = %u", device1393)); // Commented to avoid bad looking logs



    switch (device1393)
    {
        case PciDevice1393::DEVICE_0001: return "UC7000 Serial";
        case PciDevice1393::DEVICE_1020: return "CP-102 (2-port RS-232 PCI)";
        case PciDevice1393::DEVICE_1021: return "CP-102UL (2-port RS-232 Universal PCI)";
        case PciDevice1393::DEVICE_1022: return "CP-102U (2-port RS-232 Universal PCI)";
        case PciDevice1393::DEVICE_1023: return "CP-102UF";
        case PciDevice1393::DEVICE_1024: return "CP-102E (2-port RS-232 Smart PCI Express Serial Board)";
        case PciDevice1393::DEVICE_1025: return "CP-102EL (2-port RS-232 Smart PCI Express Serial Board)";
        case PciDevice1393::DEVICE_1040: return "Smartio C104H/PCI";
        case PciDevice1393::DEVICE_1041: return "CP104U (4-port RS-232 Universal PCI)";
        case PciDevice1393::DEVICE_1042: return "CP104JU (4-port RS-232 Universal PCI)";
        case PciDevice1393::DEVICE_1043: return "CP104EL (4-port RS-232 Smart PCI Express)";
        case PciDevice1393::DEVICE_1044: return "POS104UL (4-port RS-232 Universal PCI)";
        case PciDevice1393::DEVICE_1045: return "CP-104EL-A (4-port RS-232 PCI Express Serial Board)";
        case PciDevice1393::DEVICE_1080: return "CB108 (8-port RS-232 PC/104-plus Module)";
        case PciDevice1393::DEVICE_1140: return "CT-114 series";
        case PciDevice1393::DEVICE_1141: return "Industrio CP-114";
        case PciDevice1393::DEVICE_1142: return "CB114 (4-port RS-232/422/485 PC/104-plus Module)";
        case PciDevice1393::DEVICE_1143: return "CP-114UL (4-port RS-232/422/485 Smart Universal PCI Serial Board)";
        case PciDevice1393::DEVICE_1144: return "CP-114EL (4-port RS-232/422/485 Smart PCI Express Serial Board)";
        case PciDevice1393::DEVICE_1180: return "CP118U (8-port RS-232/422/485 Smart Universal PCI)";
        case PciDevice1393::DEVICE_1181: return "CP118EL (8-port RS-232/422/485 Smart PCI Express)";
        case PciDevice1393::DEVICE_1182: return "CP-118EL-A (8-port RS-232/422/485 PCI Express Serial Board)";
        case PciDevice1393::DEVICE_1320: return "CP132 (2-port RS-422/485 PCI)";
        case PciDevice1393::DEVICE_1321: return "CP132U (2-Port RS-422/485 Universal PCI)";
        case PciDevice1393::DEVICE_1322: return "CP-132EL (2-port RS-422/485 Smart PCI Express Serial Board)";
        case PciDevice1393::DEVICE_1340: return "CP134U (4-Port RS-422/485 Universal PCI)";
        case PciDevice1393::DEVICE_1341: return "CB134I (4-port RS-422/485 PC/104-plus Module)";
        case PciDevice1393::DEVICE_1380: return "CP138U (8-port RS-232/422/485 Smart Universal PCI)";
        case PciDevice1393::DEVICE_1680: return "Smartio C168H/PCI";
        case PciDevice1393::DEVICE_1681: return "CP-168U V2 Smart Serial Board (8-port RS-232)";
        case PciDevice1393::DEVICE_1682: return "CP-168EL (8-port RS-232 Smart PCI Express)";
        case PciDevice1393::DEVICE_1683: return "CP-168EL-A (8-port RS-232 PCI Express Serial Board)";
        case PciDevice1393::DEVICE_2040: return "Intellio CP-204J";
        case PciDevice1393::DEVICE_2180: return "Intellio C218 Turbo PCI";
        case PciDevice1393::DEVICE_3200: return "Intellio C320 Turbo PCI";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1393_PCIDEVICE1393_H
