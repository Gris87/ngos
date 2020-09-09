// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000073_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000073_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10000073: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10009240 = 0x10009240,
    SUBDEVICE_10009241 = 0x10009241,
    SUBDEVICE_100092A0 = 0x100092A0,
    SUBDEVICE_101403B1 = 0x101403B1,
    SUBDEVICE_1014040D = 0x1014040D,
    SUBDEVICE_10281F4E = 0x10281F4E,
    SUBDEVICE_10281F4F = 0x10281F4F,
    SUBDEVICE_10281F50 = 0x10281F50,
    SUBDEVICE_10281F51 = 0x10281F51,
    SUBDEVICE_10281F52 = 0x10281F52,
    SUBDEVICE_10281F53 = 0x10281F53,
    SUBDEVICE_10281F54 = 0x10281F54,
    SUBDEVICE_10281F78 = 0x10281F78,
    SUBDEVICE_10543035 = 0x10543035,
    SUBDEVICE_11370072 = 0x11370072,
    SUBDEVICE_11370073 = 0x11370073,
    SUBDEVICE_113700B0 = 0x113700B0,
    SUBDEVICE_113700B1 = 0x113700B1,
    SUBDEVICE_113700C2 = 0x113700C2,
    SUBDEVICE_113700C3 = 0x113700C3,
    SUBDEVICE_15D90400 = 0x15D90400,
    SUBDEVICE_17341177 = 0x17341177,
    SUBDEVICE_17AA1051 = 0x17AA1051,
    SUBDEVICE_8086350D = 0x8086350D,
    SUBDEVICE_80869240 = 0x80869240,
    SUBDEVICE_80869241 = 0x80869241
};



inline const char8* enumToString(PciSubDevice10000073 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000073::NONE:               return "NONE";
        case PciSubDevice10000073::SUBDEVICE_10009240: return "SUBDEVICE_10009240";
        case PciSubDevice10000073::SUBDEVICE_10009241: return "SUBDEVICE_10009241";
        case PciSubDevice10000073::SUBDEVICE_100092A0: return "SUBDEVICE_100092A0";
        case PciSubDevice10000073::SUBDEVICE_101403B1: return "SUBDEVICE_101403B1";
        case PciSubDevice10000073::SUBDEVICE_1014040D: return "SUBDEVICE_1014040D";
        case PciSubDevice10000073::SUBDEVICE_10281F4E: return "SUBDEVICE_10281F4E";
        case PciSubDevice10000073::SUBDEVICE_10281F4F: return "SUBDEVICE_10281F4F";
        case PciSubDevice10000073::SUBDEVICE_10281F50: return "SUBDEVICE_10281F50";
        case PciSubDevice10000073::SUBDEVICE_10281F51: return "SUBDEVICE_10281F51";
        case PciSubDevice10000073::SUBDEVICE_10281F52: return "SUBDEVICE_10281F52";
        case PciSubDevice10000073::SUBDEVICE_10281F53: return "SUBDEVICE_10281F53";
        case PciSubDevice10000073::SUBDEVICE_10281F54: return "SUBDEVICE_10281F54";
        case PciSubDevice10000073::SUBDEVICE_10281F78: return "SUBDEVICE_10281F78";
        case PciSubDevice10000073::SUBDEVICE_10543035: return "SUBDEVICE_10543035";
        case PciSubDevice10000073::SUBDEVICE_11370072: return "SUBDEVICE_11370072";
        case PciSubDevice10000073::SUBDEVICE_11370073: return "SUBDEVICE_11370073";
        case PciSubDevice10000073::SUBDEVICE_113700B0: return "SUBDEVICE_113700B0";
        case PciSubDevice10000073::SUBDEVICE_113700B1: return "SUBDEVICE_113700B1";
        case PciSubDevice10000073::SUBDEVICE_113700C2: return "SUBDEVICE_113700C2";
        case PciSubDevice10000073::SUBDEVICE_113700C3: return "SUBDEVICE_113700C3";
        case PciSubDevice10000073::SUBDEVICE_15D90400: return "SUBDEVICE_15D90400";
        case PciSubDevice10000073::SUBDEVICE_17341177: return "SUBDEVICE_17341177";
        case PciSubDevice10000073::SUBDEVICE_17AA1051: return "SUBDEVICE_17AA1051";
        case PciSubDevice10000073::SUBDEVICE_8086350D: return "SUBDEVICE_8086350D";
        case PciSubDevice10000073::SUBDEVICE_80869240: return "SUBDEVICE_80869240";
        case PciSubDevice10000073::SUBDEVICE_80869241: return "SUBDEVICE_80869241";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10000073 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10000073 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10000073::SUBDEVICE_10009240: return "MegaRAID SAS 9240-8i";
        case PciSubDevice10000073::SUBDEVICE_10009241: return "MegaRAID SAS 9240-4i";
        case PciSubDevice10000073::SUBDEVICE_100092A0: return "MegaRAID SAS 9220-8i";
        case PciSubDevice10000073::SUBDEVICE_101403B1: return "ServeRAID M1015 SAS/SATA Controller";
        case PciSubDevice10000073::SUBDEVICE_1014040D: return "ServeRAID M1115 SAS/SATA Controller";
        case PciSubDevice10000073::SUBDEVICE_10281F4E: return "PERC H310 Adapter";
        case PciSubDevice10000073::SUBDEVICE_10281F4F: return "PERC H310 Integrated";
        case PciSubDevice10000073::SUBDEVICE_10281F50: return "PERC H310 Mini Blades";
        case PciSubDevice10000073::SUBDEVICE_10281F51: return "PERC H310 Mini Monolithics";
        case PciSubDevice10000073::SUBDEVICE_10281F52: return "PERC H310 Embedded1";
        case PciSubDevice10000073::SUBDEVICE_10281F53: return "PERC H310 Embedded2";
        case PciSubDevice10000073::SUBDEVICE_10281F54: return "PERC H310 Reserved";
        case PciSubDevice10000073::SUBDEVICE_10281F78: return "PERC H310";
        case PciSubDevice10000073::SUBDEVICE_10543035: return "LSI MegaRAID SAS 9240-8i";
        case PciSubDevice10000073::SUBDEVICE_11370072: return "2004 iMR ROMB";
        case PciSubDevice10000073::SUBDEVICE_11370073: return "2008 ROMB";
        case PciSubDevice10000073::SUBDEVICE_113700B0: return "UCSC RAID SAS 2008M-8i";
        case PciSubDevice10000073::SUBDEVICE_113700B1: return "UCSC RAID SAS 2008M-8i";
        case PciSubDevice10000073::SUBDEVICE_113700C2: return "UCS E-Series Double Wide";
        case PciSubDevice10000073::SUBDEVICE_113700C3: return "UCS E-Series Single Wide";
        case PciSubDevice10000073::SUBDEVICE_15D90400: return "Supermicro SMC2008-iMR";
        case PciSubDevice10000073::SUBDEVICE_17341177: return "RAID Ctrl SAS 6G 0/1 (D2607)";
        case PciSubDevice10000073::SUBDEVICE_17AA1051: return "ThinkServer RAID 510i";
        case PciSubDevice10000073::SUBDEVICE_8086350D: return "RMS2AF040 RAID Controller";
        case PciSubDevice10000073::SUBDEVICE_80869240: return "RAID Controller RS2WC080";
        case PciSubDevice10000073::SUBDEVICE_80869241: return "RAID Controller RS2WC040";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1000_PCISUBDEVICE10000073_H
