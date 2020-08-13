// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCIDEVICE1217_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCIDEVICE1217_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1217: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_00F7 = 0x00F7,
    DEVICE_10F7 = 0x10F7,
    DEVICE_11F7 = 0x11F7,
    DEVICE_13F7 = 0x13F7,
    DEVICE_6729 = 0x6729,
    DEVICE_673A = 0x673A,
    DEVICE_6832 = 0x6832,
    DEVICE_6836 = 0x6836,
    DEVICE_6872 = 0x6872,
    DEVICE_6925 = 0x6925,
    DEVICE_6933 = 0x6933,
    DEVICE_6972 = 0x6972,
    DEVICE_7110 = 0x7110,
    DEVICE_7112 = 0x7112,
    DEVICE_7113 = 0x7113,
    DEVICE_7114 = 0x7114,
    DEVICE_7120 = 0x7120,
    DEVICE_7130 = 0x7130,
    DEVICE_7134 = 0x7134,
    DEVICE_7135 = 0x7135,
    DEVICE_7136 = 0x7136,
    DEVICE_71E2 = 0x71E2,
    DEVICE_7212 = 0x7212,
    DEVICE_7213 = 0x7213,
    DEVICE_7223 = 0x7223,
    DEVICE_7233 = 0x7233,
    DEVICE_8120 = 0x8120,
    DEVICE_8130 = 0x8130,
    DEVICE_8220 = 0x8220,
    DEVICE_8221 = 0x8221,
    DEVICE_8320 = 0x8320,
    DEVICE_8321 = 0x8321,
    DEVICE_8330 = 0x8330,
    DEVICE_8331 = 0x8331,
    DEVICE_8520 = 0x8520,
    DEVICE_8621 = 0x8621
};



inline const char8* enumToString(PciDevice1217 device1217) // TEST: NO
{
    // COMMON_LT((" | device1217 = %u", device1217)); // Commented to avoid bad looking logs



    switch (device1217)
    {
        case PciDevice1217::NONE:        return "NONE";
        case PciDevice1217::DEVICE_00F7: return "DEVICE_00F7";
        case PciDevice1217::DEVICE_10F7: return "DEVICE_10F7";
        case PciDevice1217::DEVICE_11F7: return "DEVICE_11F7";
        case PciDevice1217::DEVICE_13F7: return "DEVICE_13F7";
        case PciDevice1217::DEVICE_6729: return "DEVICE_6729";
        case PciDevice1217::DEVICE_673A: return "DEVICE_673A";
        case PciDevice1217::DEVICE_6832: return "DEVICE_6832";
        case PciDevice1217::DEVICE_6836: return "DEVICE_6836";
        case PciDevice1217::DEVICE_6872: return "DEVICE_6872";
        case PciDevice1217::DEVICE_6925: return "DEVICE_6925";
        case PciDevice1217::DEVICE_6933: return "DEVICE_6933";
        case PciDevice1217::DEVICE_6972: return "DEVICE_6972";
        case PciDevice1217::DEVICE_7110: return "DEVICE_7110";
        case PciDevice1217::DEVICE_7112: return "DEVICE_7112";
        case PciDevice1217::DEVICE_7113: return "DEVICE_7113";
        case PciDevice1217::DEVICE_7114: return "DEVICE_7114";
        case PciDevice1217::DEVICE_7120: return "DEVICE_7120";
        case PciDevice1217::DEVICE_7130: return "DEVICE_7130";
        case PciDevice1217::DEVICE_7134: return "DEVICE_7134";
        case PciDevice1217::DEVICE_7135: return "DEVICE_7135";
        case PciDevice1217::DEVICE_7136: return "DEVICE_7136";
        case PciDevice1217::DEVICE_71E2: return "DEVICE_71E2";
        case PciDevice1217::DEVICE_7212: return "DEVICE_7212";
        case PciDevice1217::DEVICE_7213: return "DEVICE_7213";
        case PciDevice1217::DEVICE_7223: return "DEVICE_7223";
        case PciDevice1217::DEVICE_7233: return "DEVICE_7233";
        case PciDevice1217::DEVICE_8120: return "DEVICE_8120";
        case PciDevice1217::DEVICE_8130: return "DEVICE_8130";
        case PciDevice1217::DEVICE_8220: return "DEVICE_8220";
        case PciDevice1217::DEVICE_8221: return "DEVICE_8221";
        case PciDevice1217::DEVICE_8320: return "DEVICE_8320";
        case PciDevice1217::DEVICE_8321: return "DEVICE_8321";
        case PciDevice1217::DEVICE_8330: return "DEVICE_8330";
        case PciDevice1217::DEVICE_8331: return "DEVICE_8331";
        case PciDevice1217::DEVICE_8520: return "DEVICE_8520";
        case PciDevice1217::DEVICE_8621: return "DEVICE_8621";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1217 device1217) // TEST: NO
{
    // COMMON_LT((" | device1217 = %u", device1217)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device1217, enumToString(device1217));

    return res;
}



inline const char8* enumToHumanString(PciDevice1217 device1217) // TEST: NO
{
    // COMMON_LT((" | device1217 = %u", device1217)); // Commented to avoid bad looking logs



    switch (device1217)
    {
        case PciDevice1217::DEVICE_00F7: return "Firewire (IEEE 1394)";
        case PciDevice1217::DEVICE_10F7: return "1394 OHCI Compliant Host Controller";
        case PciDevice1217::DEVICE_11F7: return "OZ600 1394a-2000 Controller";
        case PciDevice1217::DEVICE_13F7: return "1394 OHCI Compliant Host Controller";
        case PciDevice1217::DEVICE_6729: return "OZ6729";
        case PciDevice1217::DEVICE_673A: return "OZ6730";
        case PciDevice1217::DEVICE_6832: return "OZ6832/6833 CardBus Controller";
        case PciDevice1217::DEVICE_6836: return "OZ6836/6860 CardBus Controller";
        case PciDevice1217::DEVICE_6872: return "OZ6812 CardBus Controller";
        case PciDevice1217::DEVICE_6925: return "OZ6922 CardBus Controller";
        case PciDevice1217::DEVICE_6933: return "OZ6933/711E1 CardBus/SmartCardBus Controller";
        case PciDevice1217::DEVICE_6972: return "OZ601/6912/711E0 CardBus/SmartCardBus Controller";
        case PciDevice1217::DEVICE_7110: return "OZ711Mx 4-in-1 MemoryCardBus Accelerator";
        case PciDevice1217::DEVICE_7112: return "OZ711EC1/M1 SmartCardBus/MemoryCardBus Controller";
        case PciDevice1217::DEVICE_7113: return "OZ711EC1 SmartCardBus Controller";
        case PciDevice1217::DEVICE_7114: return "OZ711M1/MC1 4-in-1 MemoryCardBus Controller";
        case PciDevice1217::DEVICE_7120: return "Integrated MMC/SD Controller";
        case PciDevice1217::DEVICE_7130: return "Integrated MS/xD Controller";
        case PciDevice1217::DEVICE_7134: return "OZ711MP1/MS1 MemoryCardBus Controller";
        case PciDevice1217::DEVICE_7135: return "Cardbus bridge";
        case PciDevice1217::DEVICE_7136: return "OZ711SP1 Memory CardBus Controller";
        case PciDevice1217::DEVICE_71E2: return "OZ711E2 SmartCardBus Controller";
        case PciDevice1217::DEVICE_7212: return "OZ711M2 4-in-1 MemoryCardBus Controller";
        case PciDevice1217::DEVICE_7213: return "OZ6933E CardBus Controller";
        case PciDevice1217::DEVICE_7223: return "OZ711M3/MC3 4-in-1 MemoryCardBus Controller";
        case PciDevice1217::DEVICE_7233: return "OZ711MP3/MS3 4-in-1 MemoryCardBus Controller";
        case PciDevice1217::DEVICE_8120: return "Integrated MMC/SD Controller";
        case PciDevice1217::DEVICE_8130: return "Integrated MS/MSPRO/xD Controller";
        case PciDevice1217::DEVICE_8220: return "OZ600FJ1/OZ900FJ1 SD/MMC Card Reader Controller";
        case PciDevice1217::DEVICE_8221: return "OZ600FJ0/OZ900FJ0/OZ600FJS SD/MMC Card Reader Controller";
        case PciDevice1217::DEVICE_8320: return "OZ600RJ1/OZ900RJ1 SD/MMC Card Reader Controller";
        case PciDevice1217::DEVICE_8321: return "OZ600RJ0/OZ900RJ0/OZ600RJS SD/MMC Card Reader Controller";
        case PciDevice1217::DEVICE_8330: return "OZ600 MS/xD Controller";
        case PciDevice1217::DEVICE_8331: return "O2 Flash Memory Card";
        case PciDevice1217::DEVICE_8520: return "SD/MMC Card Reader Controller";
        case PciDevice1217::DEVICE_8621: return "SD/MMC Card Reader Controller";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCIDEVICE1217_H
