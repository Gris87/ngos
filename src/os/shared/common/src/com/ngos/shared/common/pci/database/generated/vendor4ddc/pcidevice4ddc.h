// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4DDC_PCIDEVICE4DDC_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4DDC_PCIDEVICE4DDC_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice4DDC: bad_uint16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0100 = 0x0100,
    DEVICE_0300 = 0x0300,
    DEVICE_0340 = 0x0340,
    DEVICE_0400 = 0x0400,
    DEVICE_0500 = 0x0500,
    DEVICE_0510 = 0x0510,
    DEVICE_0801 = 0x0801,
    DEVICE_0802 = 0x0802,
    DEVICE_0811 = 0x0811,
    DEVICE_0812 = 0x0812,
    DEVICE_0881 = 0x0881,
    DEVICE_0882 = 0x0882,
    DEVICE_0891 = 0x0891,
    DEVICE_0892 = 0x0892,
    DEVICE_0901 = 0x0901,
    DEVICE_0902 = 0x0902,
    DEVICE_0903 = 0x0903,
    DEVICE_0904 = 0x0904,
    DEVICE_0B01 = 0x0B01,
    DEVICE_0B02 = 0x0B02,
    DEVICE_0B03 = 0x0B03,
    DEVICE_0B04 = 0x0B04,
    DEVICE_0D01 = 0x0D01,
    DEVICE_0D10 = 0x0D10,
    DEVICE_2F00 = 0x2F00,
    DEVICE_3000 = 0x3000
};



inline const char8* enumToString(PciDevice4DDC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4DDC::NONE:        return "NONE";
        case PciDevice4DDC::DEVICE_0100: return "DEVICE_0100";
        case PciDevice4DDC::DEVICE_0300: return "DEVICE_0300";
        case PciDevice4DDC::DEVICE_0340: return "DEVICE_0340";
        case PciDevice4DDC::DEVICE_0400: return "DEVICE_0400";
        case PciDevice4DDC::DEVICE_0500: return "DEVICE_0500";
        case PciDevice4DDC::DEVICE_0510: return "DEVICE_0510";
        case PciDevice4DDC::DEVICE_0801: return "DEVICE_0801";
        case PciDevice4DDC::DEVICE_0802: return "DEVICE_0802";
        case PciDevice4DDC::DEVICE_0811: return "DEVICE_0811";
        case PciDevice4DDC::DEVICE_0812: return "DEVICE_0812";
        case PciDevice4DDC::DEVICE_0881: return "DEVICE_0881";
        case PciDevice4DDC::DEVICE_0882: return "DEVICE_0882";
        case PciDevice4DDC::DEVICE_0891: return "DEVICE_0891";
        case PciDevice4DDC::DEVICE_0892: return "DEVICE_0892";
        case PciDevice4DDC::DEVICE_0901: return "DEVICE_0901";
        case PciDevice4DDC::DEVICE_0902: return "DEVICE_0902";
        case PciDevice4DDC::DEVICE_0903: return "DEVICE_0903";
        case PciDevice4DDC::DEVICE_0904: return "DEVICE_0904";
        case PciDevice4DDC::DEVICE_0B01: return "DEVICE_0B01";
        case PciDevice4DDC::DEVICE_0B02: return "DEVICE_0B02";
        case PciDevice4DDC::DEVICE_0B03: return "DEVICE_0B03";
        case PciDevice4DDC::DEVICE_0B04: return "DEVICE_0B04";
        case PciDevice4DDC::DEVICE_0D01: return "DEVICE_0D01";
        case PciDevice4DDC::DEVICE_0D10: return "DEVICE_0D10";
        case PciDevice4DDC::DEVICE_2F00: return "DEVICE_2F00";
        case PciDevice4DDC::DEVICE_3000: return "DEVICE_3000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice4DDC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (bad_uint16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice4DDC device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice4DDC::DEVICE_0100: return "DD-42924I5-300 (ARINC 429 Data Bus)";
        case PciDevice4DDC::DEVICE_0300: return "SB-3620 Motion Feedback Device";
        case PciDevice4DDC::DEVICE_0340: return "SB-3623 Motion Feedback Device";
        case PciDevice4DDC::DEVICE_0400: return "SB-3622 Motion Feedback Device";
        case PciDevice4DDC::DEVICE_0500: return "SB-3621 Motion Feedback Device";
        case PciDevice4DDC::DEVICE_0510: return "SB-3624 Motion Feedback Device";
        case PciDevice4DDC::DEVICE_0801: return "BU-65570I1 MIL-STD-1553 Test and Simulation";
        case PciDevice4DDC::DEVICE_0802: return "BU-65570I2 MIL-STD-1553 Test and Simulation";
        case PciDevice4DDC::DEVICE_0811: return "BU-65572I1 MIL-STD-1553 Test and Simulation";
        case PciDevice4DDC::DEVICE_0812: return "BU-65572I2 MIL-STD-1553 Test and Simulation";
        case PciDevice4DDC::DEVICE_0881: return "BU-65570T1 MIL-STD-1553 Test and Simulation";
        case PciDevice4DDC::DEVICE_0882: return "BU-65570T2 MIL-STD-1553 Test and Simulation";
        case PciDevice4DDC::DEVICE_0891: return "BU-65572T1 MIL-STD-1553 Test and Simulation";
        case PciDevice4DDC::DEVICE_0892: return "BU-65572T2 MIL-STD-1553 Test and Simulation";
        case PciDevice4DDC::DEVICE_0901: return "BU-65565C1 MIL-STD-1553 Data Bus";
        case PciDevice4DDC::DEVICE_0902: return "BU-65565C2 MIL-STD-1553 Data Bus";
        case PciDevice4DDC::DEVICE_0903: return "BU-65565C3 MIL-STD-1553 Data Bus";
        case PciDevice4DDC::DEVICE_0904: return "BU-65565C4 MIL-STD-1553 Data Bus";
        case PciDevice4DDC::DEVICE_0B01: return "BU-65569I1 MIL-STD-1553 Data Bus";
        case PciDevice4DDC::DEVICE_0B02: return "BU-65569I2 MIL-STD-1553 Data Bus";
        case PciDevice4DDC::DEVICE_0B03: return "BU-65569I3 MIL-STD-1553 Data Bus";
        case PciDevice4DDC::DEVICE_0B04: return "BU-65569I4 MIL-STD-1553 Data Bus";
        case PciDevice4DDC::DEVICE_0D01: return "SB-3641 Motion Feedback Device";
        case PciDevice4DDC::DEVICE_0D10: return "SB-365x Motion Feedback Device";
        case PciDevice4DDC::DEVICE_2F00: return "SB-3642 Motion Feedback Device";
        case PciDevice4DDC::DEVICE_3000: return "SB-3644 Motion Feedback Device";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR4DDC_PCIDEVICE4DDC_H
