// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCIDEVICE10B5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCIDEVICE10B5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice10B5: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0001 = 0x0001,
    DEVICE_0557 = 0x0557,
    DEVICE_1000 = 0x1000,
    DEVICE_1024 = 0x1024,
    DEVICE_1042 = 0x1042,
    DEVICE_106A = 0x106A,
    DEVICE_1076 = 0x1076,
    DEVICE_1077 = 0x1077,
    DEVICE_1078 = 0x1078,
    DEVICE_1103 = 0x1103,
    DEVICE_1146 = 0x1146,
    DEVICE_1147 = 0x1147,
    DEVICE_2000 = 0x2000,
    DEVICE_2540 = 0x2540,
    DEVICE_2724 = 0x2724,
    DEVICE_3376 = 0x3376,
    DEVICE_4000 = 0x4000,
    DEVICE_4001 = 0x4001,
    DEVICE_4002 = 0x4002,
    DEVICE_6140 = 0x6140,
    DEVICE_6150 = 0x6150,
    DEVICE_6152 = 0x6152,
    DEVICE_6154 = 0x6154,
    DEVICE_6254 = 0x6254,
    DEVICE_6466 = 0x6466,
    DEVICE_6520 = 0x6520,
    DEVICE_6540 = 0x6540,
    DEVICE_6541 = 0x6541,
    DEVICE_6542 = 0x6542,
    DEVICE_8111 = 0x8111,
    DEVICE_8112 = 0x8112,
    DEVICE_8114 = 0x8114,
    DEVICE_8311 = 0x8311,
    DEVICE_8505 = 0x8505,
    DEVICE_8508 = 0x8508,
    DEVICE_8509 = 0x8509,
    DEVICE_8512 = 0x8512,
    DEVICE_8516 = 0x8516,
    DEVICE_8517 = 0x8517,
    DEVICE_8518 = 0x8518,
    DEVICE_8524 = 0x8524,
    DEVICE_8525 = 0x8525,
    DEVICE_8532 = 0x8532,
    DEVICE_8533 = 0x8533,
    DEVICE_8547 = 0x8547,
    DEVICE_8548 = 0x8548,
    DEVICE_8603 = 0x8603,
    DEVICE_8604 = 0x8604,
    DEVICE_8605 = 0x8605,
    DEVICE_8606 = 0x8606,
    DEVICE_8608 = 0x8608,
    DEVICE_8609 = 0x8609,
    DEVICE_8612 = 0x8612,
    DEVICE_8613 = 0x8613,
    DEVICE_8614 = 0x8614,
    DEVICE_8615 = 0x8615,
    DEVICE_8616 = 0x8616,
    DEVICE_8617 = 0x8617,
    DEVICE_8618 = 0x8618,
    DEVICE_8619 = 0x8619,
    DEVICE_8624 = 0x8624,
    DEVICE_8625 = 0x8625,
    DEVICE_8632 = 0x8632,
    DEVICE_8636 = 0x8636,
    DEVICE_8647 = 0x8647,
    DEVICE_8648 = 0x8648,
    DEVICE_8649 = 0x8649,
    DEVICE_8664 = 0x8664,
    DEVICE_8680 = 0x8680,
    DEVICE_8696 = 0x8696,
    DEVICE_8717 = 0x8717,
    DEVICE_8718 = 0x8718,
    DEVICE_8724 = 0x8724,
    DEVICE_8732 = 0x8732,
    DEVICE_8734 = 0x8734,
    DEVICE_8747 = 0x8747,
    DEVICE_8748 = 0x8748,
    DEVICE_87B0 = 0x87B0,
    DEVICE_9016 = 0x9016,
    DEVICE_9030 = 0x9030,
    DEVICE_9036 = 0x9036,
    DEVICE_9050 = 0x9050,
    DEVICE_9052 = 0x9052,
    DEVICE_9054 = 0x9054,
    DEVICE_9056 = 0x9056,
    DEVICE_9060 = 0x9060,
    DEVICE_906D = 0x906D,
    DEVICE_906E = 0x906E,
    DEVICE_9080 = 0x9080,
    DEVICE_9656 = 0x9656,
    DEVICE_9733 = 0x9733,
    DEVICE_9749 = 0x9749,
    DEVICE_A100 = 0xA100,
    DEVICE_BB04 = 0xBB04,
    DEVICE_C001 = 0xC001,
    DEVICE_D00D = 0xD00D,
    DEVICE_D33D = 0xD33D,
    DEVICE_D44D = 0xD44D
};



inline const char8* enumToString(PciDevice10B5 device10B5) // TEST: NO
{
    // COMMON_LT((" | device10B5 = %u", device10B5)); // Commented to avoid bad looking logs



    switch (device10B5)
    {
        case PciDevice10B5::NONE:        return "NONE";
        case PciDevice10B5::DEVICE_0001: return "DEVICE_0001";
        case PciDevice10B5::DEVICE_0557: return "DEVICE_0557";
        case PciDevice10B5::DEVICE_1000: return "DEVICE_1000";
        case PciDevice10B5::DEVICE_1024: return "DEVICE_1024";
        case PciDevice10B5::DEVICE_1042: return "DEVICE_1042";
        case PciDevice10B5::DEVICE_106A: return "DEVICE_106A";
        case PciDevice10B5::DEVICE_1076: return "DEVICE_1076";
        case PciDevice10B5::DEVICE_1077: return "DEVICE_1077";
        case PciDevice10B5::DEVICE_1078: return "DEVICE_1078";
        case PciDevice10B5::DEVICE_1103: return "DEVICE_1103";
        case PciDevice10B5::DEVICE_1146: return "DEVICE_1146";
        case PciDevice10B5::DEVICE_1147: return "DEVICE_1147";
        case PciDevice10B5::DEVICE_2000: return "DEVICE_2000";
        case PciDevice10B5::DEVICE_2540: return "DEVICE_2540";
        case PciDevice10B5::DEVICE_2724: return "DEVICE_2724";
        case PciDevice10B5::DEVICE_3376: return "DEVICE_3376";
        case PciDevice10B5::DEVICE_4000: return "DEVICE_4000";
        case PciDevice10B5::DEVICE_4001: return "DEVICE_4001";
        case PciDevice10B5::DEVICE_4002: return "DEVICE_4002";
        case PciDevice10B5::DEVICE_6140: return "DEVICE_6140";
        case PciDevice10B5::DEVICE_6150: return "DEVICE_6150";
        case PciDevice10B5::DEVICE_6152: return "DEVICE_6152";
        case PciDevice10B5::DEVICE_6154: return "DEVICE_6154";
        case PciDevice10B5::DEVICE_6254: return "DEVICE_6254";
        case PciDevice10B5::DEVICE_6466: return "DEVICE_6466";
        case PciDevice10B5::DEVICE_6520: return "DEVICE_6520";
        case PciDevice10B5::DEVICE_6540: return "DEVICE_6540";
        case PciDevice10B5::DEVICE_6541: return "DEVICE_6541";
        case PciDevice10B5::DEVICE_6542: return "DEVICE_6542";
        case PciDevice10B5::DEVICE_8111: return "DEVICE_8111";
        case PciDevice10B5::DEVICE_8112: return "DEVICE_8112";
        case PciDevice10B5::DEVICE_8114: return "DEVICE_8114";
        case PciDevice10B5::DEVICE_8311: return "DEVICE_8311";
        case PciDevice10B5::DEVICE_8505: return "DEVICE_8505";
        case PciDevice10B5::DEVICE_8508: return "DEVICE_8508";
        case PciDevice10B5::DEVICE_8509: return "DEVICE_8509";
        case PciDevice10B5::DEVICE_8512: return "DEVICE_8512";
        case PciDevice10B5::DEVICE_8516: return "DEVICE_8516";
        case PciDevice10B5::DEVICE_8517: return "DEVICE_8517";
        case PciDevice10B5::DEVICE_8518: return "DEVICE_8518";
        case PciDevice10B5::DEVICE_8524: return "DEVICE_8524";
        case PciDevice10B5::DEVICE_8525: return "DEVICE_8525";
        case PciDevice10B5::DEVICE_8532: return "DEVICE_8532";
        case PciDevice10B5::DEVICE_8533: return "DEVICE_8533";
        case PciDevice10B5::DEVICE_8547: return "DEVICE_8547";
        case PciDevice10B5::DEVICE_8548: return "DEVICE_8548";
        case PciDevice10B5::DEVICE_8603: return "DEVICE_8603";
        case PciDevice10B5::DEVICE_8604: return "DEVICE_8604";
        case PciDevice10B5::DEVICE_8605: return "DEVICE_8605";
        case PciDevice10B5::DEVICE_8606: return "DEVICE_8606";
        case PciDevice10B5::DEVICE_8608: return "DEVICE_8608";
        case PciDevice10B5::DEVICE_8609: return "DEVICE_8609";
        case PciDevice10B5::DEVICE_8612: return "DEVICE_8612";
        case PciDevice10B5::DEVICE_8613: return "DEVICE_8613";
        case PciDevice10B5::DEVICE_8614: return "DEVICE_8614";
        case PciDevice10B5::DEVICE_8615: return "DEVICE_8615";
        case PciDevice10B5::DEVICE_8616: return "DEVICE_8616";
        case PciDevice10B5::DEVICE_8617: return "DEVICE_8617";
        case PciDevice10B5::DEVICE_8618: return "DEVICE_8618";
        case PciDevice10B5::DEVICE_8619: return "DEVICE_8619";
        case PciDevice10B5::DEVICE_8624: return "DEVICE_8624";
        case PciDevice10B5::DEVICE_8625: return "DEVICE_8625";
        case PciDevice10B5::DEVICE_8632: return "DEVICE_8632";
        case PciDevice10B5::DEVICE_8636: return "DEVICE_8636";
        case PciDevice10B5::DEVICE_8647: return "DEVICE_8647";
        case PciDevice10B5::DEVICE_8648: return "DEVICE_8648";
        case PciDevice10B5::DEVICE_8649: return "DEVICE_8649";
        case PciDevice10B5::DEVICE_8664: return "DEVICE_8664";
        case PciDevice10B5::DEVICE_8680: return "DEVICE_8680";
        case PciDevice10B5::DEVICE_8696: return "DEVICE_8696";
        case PciDevice10B5::DEVICE_8717: return "DEVICE_8717";
        case PciDevice10B5::DEVICE_8718: return "DEVICE_8718";
        case PciDevice10B5::DEVICE_8724: return "DEVICE_8724";
        case PciDevice10B5::DEVICE_8732: return "DEVICE_8732";
        case PciDevice10B5::DEVICE_8734: return "DEVICE_8734";
        case PciDevice10B5::DEVICE_8747: return "DEVICE_8747";
        case PciDevice10B5::DEVICE_8748: return "DEVICE_8748";
        case PciDevice10B5::DEVICE_87B0: return "DEVICE_87B0";
        case PciDevice10B5::DEVICE_9016: return "DEVICE_9016";
        case PciDevice10B5::DEVICE_9030: return "DEVICE_9030";
        case PciDevice10B5::DEVICE_9036: return "DEVICE_9036";
        case PciDevice10B5::DEVICE_9050: return "DEVICE_9050";
        case PciDevice10B5::DEVICE_9052: return "DEVICE_9052";
        case PciDevice10B5::DEVICE_9054: return "DEVICE_9054";
        case PciDevice10B5::DEVICE_9056: return "DEVICE_9056";
        case PciDevice10B5::DEVICE_9060: return "DEVICE_9060";
        case PciDevice10B5::DEVICE_906D: return "DEVICE_906D";
        case PciDevice10B5::DEVICE_906E: return "DEVICE_906E";
        case PciDevice10B5::DEVICE_9080: return "DEVICE_9080";
        case PciDevice10B5::DEVICE_9656: return "DEVICE_9656";
        case PciDevice10B5::DEVICE_9733: return "DEVICE_9733";
        case PciDevice10B5::DEVICE_9749: return "DEVICE_9749";
        case PciDevice10B5::DEVICE_A100: return "DEVICE_A100";
        case PciDevice10B5::DEVICE_BB04: return "DEVICE_BB04";
        case PciDevice10B5::DEVICE_C001: return "DEVICE_C001";
        case PciDevice10B5::DEVICE_D00D: return "DEVICE_D00D";
        case PciDevice10B5::DEVICE_D33D: return "DEVICE_D33D";
        case PciDevice10B5::DEVICE_D44D: return "DEVICE_D44D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice10B5 device10B5) // TEST: NO
{
    // COMMON_LT((" | device10B5 = %u", device10B5)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device10B5, enumToString(device10B5));

    return res;
}



inline const char8* enumToHumanString(PciDevice10B5 device10B5) // TEST: NO
{
    // COMMON_LT((" | device10B5 = %u", device10B5)); // Commented to avoid bad looking logs



    switch (device10B5)
    {
        case PciDevice10B5::DEVICE_0001: return "i960 PCI bus interface";
        case PciDevice10B5::DEVICE_0557: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_1000: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_1024: return "Acromag, Inc. IndustryPack Carrier Card";
        case PciDevice10B5::DEVICE_1042: return "Brandywine / jxi2, Inc. - PMC-SyncClock32, IRIG A & B, Nasa 36";
        case PciDevice10B5::DEVICE_106A: return "Dual OX16C952 4 port serial adapter [Megawolf Romulus/4]";
        case PciDevice10B5::DEVICE_1076: return "VScom 800 8 port serial adaptor";
        case PciDevice10B5::DEVICE_1077: return "VScom 400 4 port serial adaptor";
        case PciDevice10B5::DEVICE_1078: return "VScom 210 2 port serial and 1 port parallel adaptor";
        case PciDevice10B5::DEVICE_1103: return "VScom 200 2 port serial adaptor";
        case PciDevice10B5::DEVICE_1146: return "VScom 010 1 port parallel adaptor";
        case PciDevice10B5::DEVICE_1147: return "VScom 020 2 port parallel adaptor";
        case PciDevice10B5::DEVICE_2000: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_2540: return "IXXAT CAN-Interface PC-I 04/PCI";
        case PciDevice10B5::DEVICE_2724: return "Thales PCSM Security Card";
        case PciDevice10B5::DEVICE_3376: return "Cosateq 4 Port CAN Card";
        case PciDevice10B5::DEVICE_4000: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_4001: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_4002: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_6140: return "PCI6140 32-bit 33MHz PCI-to-PCI Bridge";
        case PciDevice10B5::DEVICE_6150: return "PCI6150 32-bit 33MHz PCI-to-PCI Bridge";
        case PciDevice10B5::DEVICE_6152: return "PCI6152 32-bit 66MHz PCI-to-PCI Bridge";
        case PciDevice10B5::DEVICE_6154: return "PCI6154 64-bit 66MHz PCI-to-PCI Bridge";
        case PciDevice10B5::DEVICE_6254: return "PCI6254 64-bit 66MHz PCI-to-PCI Bridge";
        case PciDevice10B5::DEVICE_6466: return "PCI6466 64-bit 66MHz PCI-to-PCI Bridge";
        case PciDevice10B5::DEVICE_6520: return "PCI6520 64-bit 133MHz PCI-X-to-PCI-X Bridge";
        case PciDevice10B5::DEVICE_6540: return "PCI6540 64-bit 133MHz PCI-X-to-PCI-X Bridge";
        case PciDevice10B5::DEVICE_6541: return "PCI6540/6466 PCI-PCI bridge (non-transparent mode, primary side)";
        case PciDevice10B5::DEVICE_6542: return "PCI6540/6466 PCI-PCI bridge (non-transparent mode, secondary side)";
        case PciDevice10B5::DEVICE_8111: return "PEX 8111 PCI Express-to-PCI Bridge";
        case PciDevice10B5::DEVICE_8112: return "PEX8112 x1 Lane PCI Express-to-PCI Bridge";
        case PciDevice10B5::DEVICE_8114: return "PEX 8114 PCI Express-to-PCI/PCI-X Bridge";
        case PciDevice10B5::DEVICE_8311: return "PEX8311 x1 Lane PCI Express-to-Generic Local Bus Bridge";
        case PciDevice10B5::DEVICE_8505: return "PEX 8505 5-lane, 5-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8508: return "PEX 8508 8-lane, 5-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8509: return "PEX 8509 8-lane, 8-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8512: return "PEX 8512 12-lane, 5-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8516: return "PEX 8516 Versatile PCI Express Switch";
        case PciDevice10B5::DEVICE_8517: return "PEX 8517 16-lane, 5-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8518: return "PEX 8518 16-lane, 5-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8524: return "PEX 8524 24-lane, 6-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8525: return "PEX 8525 24-lane, 5-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8532: return "PEX 8532 Versatile PCI Express Switch";
        case PciDevice10B5::DEVICE_8533: return "PEX 8533 32-lane, 6-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8547: return "PEX 8547 48-lane, 3-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8548: return "PEX 8548 48-lane, 9-port PCI Express Switch";
        case PciDevice10B5::DEVICE_8603: return "PEX 8603 3-lane, 3-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8604: return "PEX 8604 4-lane, 4-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8605: return "PEX 8605 PCI Express 4-port Gen2 Switch";
        case PciDevice10B5::DEVICE_8606: return "PEX 8606 6 Lane, 6 Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8608: return "PEX 8608 8-lane, 8-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8609: return "PEX 8609 8-lane, 8-Port PCI Express Gen 2 (5.0 GT/s) Switch with DMA";
        case PciDevice10B5::DEVICE_8612: return "PEX 8612 12-lane, 4-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8613: return "PEX 8613 12-lane, 3-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8614: return "PEX 8614 12-lane, 12-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8615: return "PEX 8615 12-lane, 12-Port PCI Express Gen 2 (5.0 GT/s) Switch with DMA";
        case PciDevice10B5::DEVICE_8616: return "PEX 8616 16-lane, 4-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8617: return "PEX 8617 16-lane, 4-Port PCI Express Gen 2 (5.0 GT/s) Switch with P2P";
        case PciDevice10B5::DEVICE_8618: return "PEX 8618 16-lane, 16-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8619: return "PEX 8619 16-lane, 16-Port PCI Express Gen 2 (5.0 GT/s) Switch with DMA";
        case PciDevice10B5::DEVICE_8624: return "PEX 8624 24-lane, 6-Port PCI Express Gen 2 (5.0 GT/s) Switch [ExpressLane]";
        case PciDevice10B5::DEVICE_8625: return "PEX 8625 24-lane, 24-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8632: return "PEX 8632 32-lane, 12-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8636: return "PEX 8636 36-lane, 24-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8647: return "PEX 8647 48-Lane, 3-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8648: return "PEX 8648 48-lane, 12-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8649: return "PEX 8649 48-lane, 12-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8664: return "PEX 8664 64-lane, 16-Port PCI Express Gen 2 (5.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8680: return "PEX 8680 80-lane, 20-Port PCI Express Gen 2 (5.0 GT/s) Multi-Root Switch";
        case PciDevice10B5::DEVICE_8696: return "PEX 8696 96-lane, 24-Port PCI Express Gen 2 (5.0 GT/s) Multi-Root Switch";
        case PciDevice10B5::DEVICE_8717: return "PEX 8717 16-lane, 8-Port PCI Express Gen 3 (8.0 GT/s) Switch with DMA";
        case PciDevice10B5::DEVICE_8718: return "PEX 8718 16-Lane, 5-Port PCI Express Gen 3 (8.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8724: return "PEX 8724 24-Lane, 6-Port PCI Express Gen 3 (8 GT/s) Switch, 19 x 19mm FCBGA";
        case PciDevice10B5::DEVICE_8732: return "PEX 8732 32-lane, 8-Port PCI Express Gen 3 (8.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8734: return "PEX 8734 32-lane, 8-Port PCI Express Gen 3 (8.0GT/s) Switch";
        case PciDevice10B5::DEVICE_8747: return "PEX 8747 48-Lane, 5-Port PCI Express Gen 3 (8.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_8748: return "PEX 8748 48-Lane, 12-Port PCI Express Gen 3 (8 GT/s) Switch, 27 x 27mm FCBGA";
        case PciDevice10B5::DEVICE_87B0: return "PEX 8732 32-lane, 8-Port PCI Express Gen 3 (8.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_9016: return "PLX 9016 8-port serial controller";
        case PciDevice10B5::DEVICE_9030: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_9036: return "9036";
        case PciDevice10B5::DEVICE_9050: return "PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_9052: return "PCI9052 PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_9054: return "PCI9054 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_9056: return "PCI9056 32-bit 66MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_9060: return "PCI9060 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_906D: return "9060SD";
        case PciDevice10B5::DEVICE_906E: return "9060ES";
        case PciDevice10B5::DEVICE_9080: return "PCI9080 32-bit; 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_9656: return "PCI9656 PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_9733: return "PEX 9733 33-lane, 9-port PCI Express Gen 3 (8.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_9749: return "PEX 9749 49-lane, 13-port PCI Express Gen 3 (8.0 GT/s) Switch";
        case PciDevice10B5::DEVICE_A100: return "Blackmagic Design DeckLink";
        case PciDevice10B5::DEVICE_BB04: return "B&B 3PCIOSD1A Isolated PCI Serial";
        case PciDevice10B5::DEVICE_C001: return "CronyxOmega-PCI (8-port RS232)";
        case PciDevice10B5::DEVICE_D00D: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_D33D: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";
        case PciDevice10B5::DEVICE_D44D: return "PCI9030 32-bit 33MHz PCI <-> IOBus Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10B5_PCIDEVICE10B5_H
