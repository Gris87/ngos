// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000060_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000060_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000060: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10001006 = 0x10001006,
    SUBDEVICE_1000100A = 0x1000100A,
    SUBDEVICE_1000100E = 0x1000100E,
    SUBDEVICE_1000100F = 0x1000100F,
    SUBDEVICE_10001010 = 0x10001010,
    SUBDEVICE_10001011 = 0x10001011,
    SUBDEVICE_10001012 = 0x10001012,
    SUBDEVICE_10001016 = 0x10001016,
    SUBDEVICE_10140363 = 0x10140363,
    SUBDEVICE_10140364 = 0x10140364,
    SUBDEVICE_10140365 = 0x10140365,
    SUBDEVICE_10140379 = 0x10140379,
    SUBDEVICE_10281F0A = 0x10281F0A,
    SUBDEVICE_10281F0B = 0x10281F0B,
    SUBDEVICE_10281F0C = 0x10281F0C,
    SUBDEVICE_10281F0D = 0x10281F0D,
    SUBDEVICE_10281F11 = 0x10281F11,
    SUBDEVICE_1033835A = 0x1033835A,
    SUBDEVICE_1043824D = 0x1043824D,
    SUBDEVICE_1170002F = 0x1170002F,
    SUBDEVICE_11700036 = 0x11700036,
    SUBDEVICE_15D9C080 = 0x15D9C080,
    SUBDEVICE_17AA6B7C = 0x17AA6B7C,
    SUBDEVICE_18A10003 = 0x18A10003,
    SUBDEVICE_80861006 = 0x80861006,
    SUBDEVICE_8086100A = 0x8086100A,
    SUBDEVICE_80861010 = 0x80861010,
    SUBDEVICE_808634CC = 0x808634CC,
    SUBDEVICE_808634CD = 0x808634CD,
    SUBDEVICE_80863505 = 0x80863505
};



inline const char8* enumToString(PciSubDevice10000060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000060::NONE:               return "NONE";
        case PciSubDevice10000060::SUBDEVICE_10001006: return "SUBDEVICE_10001006";
        case PciSubDevice10000060::SUBDEVICE_1000100A: return "SUBDEVICE_1000100A";
        case PciSubDevice10000060::SUBDEVICE_1000100E: return "SUBDEVICE_1000100E";
        case PciSubDevice10000060::SUBDEVICE_1000100F: return "SUBDEVICE_1000100F";
        case PciSubDevice10000060::SUBDEVICE_10001010: return "SUBDEVICE_10001010";
        case PciSubDevice10000060::SUBDEVICE_10001011: return "SUBDEVICE_10001011";
        case PciSubDevice10000060::SUBDEVICE_10001012: return "SUBDEVICE_10001012";
        case PciSubDevice10000060::SUBDEVICE_10001016: return "SUBDEVICE_10001016";
        case PciSubDevice10000060::SUBDEVICE_10140363: return "SUBDEVICE_10140363";
        case PciSubDevice10000060::SUBDEVICE_10140364: return "SUBDEVICE_10140364";
        case PciSubDevice10000060::SUBDEVICE_10140365: return "SUBDEVICE_10140365";
        case PciSubDevice10000060::SUBDEVICE_10140379: return "SUBDEVICE_10140379";
        case PciSubDevice10000060::SUBDEVICE_10281F0A: return "SUBDEVICE_10281F0A";
        case PciSubDevice10000060::SUBDEVICE_10281F0B: return "SUBDEVICE_10281F0B";
        case PciSubDevice10000060::SUBDEVICE_10281F0C: return "SUBDEVICE_10281F0C";
        case PciSubDevice10000060::SUBDEVICE_10281F0D: return "SUBDEVICE_10281F0D";
        case PciSubDevice10000060::SUBDEVICE_10281F11: return "SUBDEVICE_10281F11";
        case PciSubDevice10000060::SUBDEVICE_1033835A: return "SUBDEVICE_1033835A";
        case PciSubDevice10000060::SUBDEVICE_1043824D: return "SUBDEVICE_1043824D";
        case PciSubDevice10000060::SUBDEVICE_1170002F: return "SUBDEVICE_1170002F";
        case PciSubDevice10000060::SUBDEVICE_11700036: return "SUBDEVICE_11700036";
        case PciSubDevice10000060::SUBDEVICE_15D9C080: return "SUBDEVICE_15D9C080";
        case PciSubDevice10000060::SUBDEVICE_17AA6B7C: return "SUBDEVICE_17AA6B7C";
        case PciSubDevice10000060::SUBDEVICE_18A10003: return "SUBDEVICE_18A10003";
        case PciSubDevice10000060::SUBDEVICE_80861006: return "SUBDEVICE_80861006";
        case PciSubDevice10000060::SUBDEVICE_8086100A: return "SUBDEVICE_8086100A";
        case PciSubDevice10000060::SUBDEVICE_80861010: return "SUBDEVICE_80861010";
        case PciSubDevice10000060::SUBDEVICE_808634CC: return "SUBDEVICE_808634CC";
        case PciSubDevice10000060::SUBDEVICE_808634CD: return "SUBDEVICE_808634CD";
        case PciSubDevice10000060::SUBDEVICE_80863505: return "SUBDEVICE_80863505";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000060 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000060::SUBDEVICE_10001006: return "MegaRAID SAS 8888ELP";
        case PciSubDevice10000060::SUBDEVICE_1000100A: return "MegaRAID SAS 8708ELP";
        case PciSubDevice10000060::SUBDEVICE_1000100E: return "MegaRAID SAS 8884E";
        case PciSubDevice10000060::SUBDEVICE_1000100F: return "MegaRAID SAS 8708E";
        case PciSubDevice10000060::SUBDEVICE_10001010: return "MegaRAID SATA 350-8ELP";
        case PciSubDevice10000060::SUBDEVICE_10001011: return "MegaRAID SATA 350-4ELP";
        case PciSubDevice10000060::SUBDEVICE_10001012: return "MegaRAID SAS 8704ELP";
        case PciSubDevice10000060::SUBDEVICE_10001016: return "MegaRAID SAS 8880EM2";
        case PciSubDevice10000060::SUBDEVICE_10140363: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000060::SUBDEVICE_10140364: return "SystemX MegaRAID SAS 8808E";
        case PciSubDevice10000060::SUBDEVICE_10140365: return "SystemX MegaRAID SAS 8884E";
        case PciSubDevice10000060::SUBDEVICE_10140379: return "SystemX MegaRAID SAS 8880EM2";
        case PciSubDevice10000060::SUBDEVICE_10281F0A: return "PERC 6/E Adapter RAID Controller";
        case PciSubDevice10000060::SUBDEVICE_10281F0B: return "PERC 6/i Adapter RAID Controller";
        case PciSubDevice10000060::SUBDEVICE_10281F0C: return "PERC 6/i Integrated RAID Controller";
        case PciSubDevice10000060::SUBDEVICE_10281F0D: return "PERC 6/i Integrated RAID Controller";
        case PciSubDevice10000060::SUBDEVICE_10281F11: return "CERC 6/i Integrated RAID Controller";
        case PciSubDevice10000060::SUBDEVICE_1033835A: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000060::SUBDEVICE_1043824D: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000060::SUBDEVICE_1170002F: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000060::SUBDEVICE_11700036: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000060::SUBDEVICE_15D9C080: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000060::SUBDEVICE_17AA6B7C: return "MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000060::SUBDEVICE_18A10003: return "LSI MegaRAID SAS PCI Express ROMB";
        case PciSubDevice10000060::SUBDEVICE_80861006: return "RAID Controller SRCSAS28EP";
        case PciSubDevice10000060::SUBDEVICE_8086100A: return "RAID Controller SRCSAS28EV";
        case PciSubDevice10000060::SUBDEVICE_80861010: return "RAID Controller SRCSATA28E";
        case PciSubDevice10000060::SUBDEVICE_808634CC: return "Integrated RAID Controller SROMBSAS28E";
        case PciSubDevice10000060::SUBDEVICE_808634CD: return "Integrated RAID Controller SROMBSAS28E";
        case PciSubDevice10000060::SUBDEVICE_80863505: return "Integrated RAID Controller SROMBSASMP2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000060_H
