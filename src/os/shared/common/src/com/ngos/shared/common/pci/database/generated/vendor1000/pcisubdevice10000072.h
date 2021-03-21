// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000072_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000072_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000072: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10003040 = 0x10003040,
    SUBDEVICE_10003080 = 0x10003080,
    SUBDEVICE_100030B0 = 0x100030B0,
    SUBDEVICE_101403CA = 0x101403CA,
    SUBDEVICE_10281F1C = 0x10281F1C,
    SUBDEVICE_10281F1D = 0x10281F1D,
    SUBDEVICE_10281F1E = 0x10281F1E,
    SUBDEVICE_10281F1F = 0x10281F1F,
    SUBDEVICE_10281F20 = 0x10281F20,
    SUBDEVICE_10281F22 = 0x10281F22,
    SUBDEVICE_17341177 = 0x17341177,
    SUBDEVICE_1BD4000D = 0x1BD4000D,
    SUBDEVICE_1BD4000E = 0x1BD4000E,
    SUBDEVICE_1BD4000F = 0x1BD4000F,
    SUBDEVICE_1BD40010 = 0x1BD40010,
    SUBDEVICE_8086350F = 0x8086350F,
    SUBDEVICE_80863700 = 0x80863700
};



inline const char8* enumToString(PciSubDevice10000072 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000072::NONE:               return "NONE";
        case PciSubDevice10000072::SUBDEVICE_10003040: return "SUBDEVICE_10003040";
        case PciSubDevice10000072::SUBDEVICE_10003080: return "SUBDEVICE_10003080";
        case PciSubDevice10000072::SUBDEVICE_100030B0: return "SUBDEVICE_100030B0";
        case PciSubDevice10000072::SUBDEVICE_101403CA: return "SUBDEVICE_101403CA";
        case PciSubDevice10000072::SUBDEVICE_10281F1C: return "SUBDEVICE_10281F1C";
        case PciSubDevice10000072::SUBDEVICE_10281F1D: return "SUBDEVICE_10281F1D";
        case PciSubDevice10000072::SUBDEVICE_10281F1E: return "SUBDEVICE_10281F1E";
        case PciSubDevice10000072::SUBDEVICE_10281F1F: return "SUBDEVICE_10281F1F";
        case PciSubDevice10000072::SUBDEVICE_10281F20: return "SUBDEVICE_10281F20";
        case PciSubDevice10000072::SUBDEVICE_10281F22: return "SUBDEVICE_10281F22";
        case PciSubDevice10000072::SUBDEVICE_17341177: return "SUBDEVICE_17341177";
        case PciSubDevice10000072::SUBDEVICE_1BD4000D: return "SUBDEVICE_1BD4000D";
        case PciSubDevice10000072::SUBDEVICE_1BD4000E: return "SUBDEVICE_1BD4000E";
        case PciSubDevice10000072::SUBDEVICE_1BD4000F: return "SUBDEVICE_1BD4000F";
        case PciSubDevice10000072::SUBDEVICE_1BD40010: return "SUBDEVICE_1BD40010";
        case PciSubDevice10000072::SUBDEVICE_8086350F: return "SUBDEVICE_8086350F";
        case PciSubDevice10000072::SUBDEVICE_80863700: return "SUBDEVICE_80863700";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000072 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000072 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000072::SUBDEVICE_10003040: return "9210-8i";
        case PciSubDevice10000072::SUBDEVICE_10003080: return "9200-8e [LSI SAS 6Gb/s SAS/SATA PCIe x8 External HBA]";
        case PciSubDevice10000072::SUBDEVICE_100030B0: return "9200-8e [LSI SAS 6Gb/s SAS/SATA PCIe x8 External HBA]";
        case PciSubDevice10000072::SUBDEVICE_101403CA: return "IBM 6Gb SAS HBA [9212-4i4e]";
        case PciSubDevice10000072::SUBDEVICE_10281F1C: return "6Gbps SAS HBA Adapter";
        case PciSubDevice10000072::SUBDEVICE_10281F1D: return "PERC H200 Adapter";
        case PciSubDevice10000072::SUBDEVICE_10281F1E: return "PERC H200 Integrated";
        case PciSubDevice10000072::SUBDEVICE_10281F1F: return "PERC H200 Modular";
        case PciSubDevice10000072::SUBDEVICE_10281F20: return "PERC H200 Embedded";
        case PciSubDevice10000072::SUBDEVICE_10281F22: return "PERC H200 Internal Tape Adapter";
        case PciSubDevice10000072::SUBDEVICE_17341177: return "HBA Ctrl SAS 6G 0/1 [D2607]";
        case PciSubDevice10000072::SUBDEVICE_1BD4000D: return "6G SAS2008IT";
        case PciSubDevice10000072::SUBDEVICE_1BD4000E: return "6G SAS2008IR";
        case PciSubDevice10000072::SUBDEVICE_1BD4000F: return "6G SAS2008IT SA5248";
        case PciSubDevice10000072::SUBDEVICE_1BD40010: return "6G SAS2008IR SA5248";
        case PciSubDevice10000072::SUBDEVICE_8086350F: return "RMS2LL040 RAID Controller";
        case PciSubDevice10000072::SUBDEVICE_80863700: return "SSD 910 Series";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000072_H
