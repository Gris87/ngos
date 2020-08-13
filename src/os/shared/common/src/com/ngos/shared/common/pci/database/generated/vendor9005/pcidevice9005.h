// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCIDEVICE9005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCIDEVICE9005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice9005: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0010 = 0x0010,
    DEVICE_0011 = 0x0011,
    DEVICE_0013 = 0x0013,
    DEVICE_001F = 0x001F,
    DEVICE_0020 = 0x0020,
    DEVICE_002F = 0x002F,
    DEVICE_0030 = 0x0030,
    DEVICE_003F = 0x003F,
    DEVICE_0050 = 0x0050,
    DEVICE_0051 = 0x0051,
    DEVICE_0053 = 0x0053,
    DEVICE_005F = 0x005F,
    DEVICE_0080 = 0x0080,
    DEVICE_0081 = 0x0081,
    DEVICE_0083 = 0x0083,
    DEVICE_008F = 0x008F,
    DEVICE_0092 = 0x0092,
    DEVICE_0093 = 0x0093,
    DEVICE_00C0 = 0x00C0,
    DEVICE_00C1 = 0x00C1,
    DEVICE_00C3 = 0x00C3,
    DEVICE_00C5 = 0x00C5,
    DEVICE_00CF = 0x00CF,
    DEVICE_0241 = 0x0241,
    DEVICE_0242 = 0x0242,
    DEVICE_0243 = 0x0243,
    DEVICE_0244 = 0x0244,
    DEVICE_0250 = 0x0250,
    DEVICE_0279 = 0x0279,
    DEVICE_0283 = 0x0283,
    DEVICE_0284 = 0x0284,
    DEVICE_0285 = 0x0285,
    DEVICE_0286 = 0x0286,
    DEVICE_028B = 0x028B,
    DEVICE_028C = 0x028C,
    DEVICE_028D = 0x028D,
    DEVICE_028F = 0x028F,
    DEVICE_0410 = 0x0410,
    DEVICE_0412 = 0x0412,
    DEVICE_0415 = 0x0415,
    DEVICE_0416 = 0x0416,
    DEVICE_041E = 0x041E,
    DEVICE_041F = 0x041F,
    DEVICE_042F = 0x042F,
    DEVICE_0430 = 0x0430,
    DEVICE_0432 = 0x0432,
    DEVICE_043E = 0x043E,
    DEVICE_043F = 0x043F,
    DEVICE_0450 = 0x0450,
    DEVICE_0500 = 0x0500,
    DEVICE_0503 = 0x0503,
    DEVICE_0910 = 0x0910,
    DEVICE_091E = 0x091E,
    DEVICE_8000 = 0x8000,
    DEVICE_800F = 0x800F,
    DEVICE_8010 = 0x8010,
    DEVICE_8011 = 0x8011,
    DEVICE_8012 = 0x8012,
    DEVICE_8013 = 0x8013,
    DEVICE_8014 = 0x8014,
    DEVICE_8015 = 0x8015,
    DEVICE_8016 = 0x8016,
    DEVICE_8017 = 0x8017,
    DEVICE_801C = 0x801C,
    DEVICE_801D = 0x801D,
    DEVICE_801E = 0x801E,
    DEVICE_801F = 0x801F,
    DEVICE_8080 = 0x8080,
    DEVICE_8081 = 0x8081,
    DEVICE_8088 = 0x8088,
    DEVICE_8089 = 0x8089,
    DEVICE_808F = 0x808F,
    DEVICE_8090 = 0x8090,
    DEVICE_8091 = 0x8091,
    DEVICE_8092 = 0x8092,
    DEVICE_8093 = 0x8093,
    DEVICE_8094 = 0x8094,
    DEVICE_8095 = 0x8095,
    DEVICE_8096 = 0x8096,
    DEVICE_8097 = 0x8097,
    DEVICE_809C = 0x809C,
    DEVICE_809D = 0x809D,
    DEVICE_809E = 0x809E,
    DEVICE_809F = 0x809F
};



inline const char8* enumToString(PciDevice9005 device9005) // TEST: NO
{
    // COMMON_LT((" | device9005 = %u", device9005)); // Commented to avoid bad looking logs



    switch (device9005)
    {
        case PciDevice9005::NONE:        return "NONE";
        case PciDevice9005::DEVICE_0010: return "DEVICE_0010";
        case PciDevice9005::DEVICE_0011: return "DEVICE_0011";
        case PciDevice9005::DEVICE_0013: return "DEVICE_0013";
        case PciDevice9005::DEVICE_001F: return "DEVICE_001F";
        case PciDevice9005::DEVICE_0020: return "DEVICE_0020";
        case PciDevice9005::DEVICE_002F: return "DEVICE_002F";
        case PciDevice9005::DEVICE_0030: return "DEVICE_0030";
        case PciDevice9005::DEVICE_003F: return "DEVICE_003F";
        case PciDevice9005::DEVICE_0050: return "DEVICE_0050";
        case PciDevice9005::DEVICE_0051: return "DEVICE_0051";
        case PciDevice9005::DEVICE_0053: return "DEVICE_0053";
        case PciDevice9005::DEVICE_005F: return "DEVICE_005F";
        case PciDevice9005::DEVICE_0080: return "DEVICE_0080";
        case PciDevice9005::DEVICE_0081: return "DEVICE_0081";
        case PciDevice9005::DEVICE_0083: return "DEVICE_0083";
        case PciDevice9005::DEVICE_008F: return "DEVICE_008F";
        case PciDevice9005::DEVICE_0092: return "DEVICE_0092";
        case PciDevice9005::DEVICE_0093: return "DEVICE_0093";
        case PciDevice9005::DEVICE_00C0: return "DEVICE_00C0";
        case PciDevice9005::DEVICE_00C1: return "DEVICE_00C1";
        case PciDevice9005::DEVICE_00C3: return "DEVICE_00C3";
        case PciDevice9005::DEVICE_00C5: return "DEVICE_00C5";
        case PciDevice9005::DEVICE_00CF: return "DEVICE_00CF";
        case PciDevice9005::DEVICE_0241: return "DEVICE_0241";
        case PciDevice9005::DEVICE_0242: return "DEVICE_0242";
        case PciDevice9005::DEVICE_0243: return "DEVICE_0243";
        case PciDevice9005::DEVICE_0244: return "DEVICE_0244";
        case PciDevice9005::DEVICE_0250: return "DEVICE_0250";
        case PciDevice9005::DEVICE_0279: return "DEVICE_0279";
        case PciDevice9005::DEVICE_0283: return "DEVICE_0283";
        case PciDevice9005::DEVICE_0284: return "DEVICE_0284";
        case PciDevice9005::DEVICE_0285: return "DEVICE_0285";
        case PciDevice9005::DEVICE_0286: return "DEVICE_0286";
        case PciDevice9005::DEVICE_028B: return "DEVICE_028B";
        case PciDevice9005::DEVICE_028C: return "DEVICE_028C";
        case PciDevice9005::DEVICE_028D: return "DEVICE_028D";
        case PciDevice9005::DEVICE_028F: return "DEVICE_028F";
        case PciDevice9005::DEVICE_0410: return "DEVICE_0410";
        case PciDevice9005::DEVICE_0412: return "DEVICE_0412";
        case PciDevice9005::DEVICE_0415: return "DEVICE_0415";
        case PciDevice9005::DEVICE_0416: return "DEVICE_0416";
        case PciDevice9005::DEVICE_041E: return "DEVICE_041E";
        case PciDevice9005::DEVICE_041F: return "DEVICE_041F";
        case PciDevice9005::DEVICE_042F: return "DEVICE_042F";
        case PciDevice9005::DEVICE_0430: return "DEVICE_0430";
        case PciDevice9005::DEVICE_0432: return "DEVICE_0432";
        case PciDevice9005::DEVICE_043E: return "DEVICE_043E";
        case PciDevice9005::DEVICE_043F: return "DEVICE_043F";
        case PciDevice9005::DEVICE_0450: return "DEVICE_0450";
        case PciDevice9005::DEVICE_0500: return "DEVICE_0500";
        case PciDevice9005::DEVICE_0503: return "DEVICE_0503";
        case PciDevice9005::DEVICE_0910: return "DEVICE_0910";
        case PciDevice9005::DEVICE_091E: return "DEVICE_091E";
        case PciDevice9005::DEVICE_8000: return "DEVICE_8000";
        case PciDevice9005::DEVICE_800F: return "DEVICE_800F";
        case PciDevice9005::DEVICE_8010: return "DEVICE_8010";
        case PciDevice9005::DEVICE_8011: return "DEVICE_8011";
        case PciDevice9005::DEVICE_8012: return "DEVICE_8012";
        case PciDevice9005::DEVICE_8013: return "DEVICE_8013";
        case PciDevice9005::DEVICE_8014: return "DEVICE_8014";
        case PciDevice9005::DEVICE_8015: return "DEVICE_8015";
        case PciDevice9005::DEVICE_8016: return "DEVICE_8016";
        case PciDevice9005::DEVICE_8017: return "DEVICE_8017";
        case PciDevice9005::DEVICE_801C: return "DEVICE_801C";
        case PciDevice9005::DEVICE_801D: return "DEVICE_801D";
        case PciDevice9005::DEVICE_801E: return "DEVICE_801E";
        case PciDevice9005::DEVICE_801F: return "DEVICE_801F";
        case PciDevice9005::DEVICE_8080: return "DEVICE_8080";
        case PciDevice9005::DEVICE_8081: return "DEVICE_8081";
        case PciDevice9005::DEVICE_8088: return "DEVICE_8088";
        case PciDevice9005::DEVICE_8089: return "DEVICE_8089";
        case PciDevice9005::DEVICE_808F: return "DEVICE_808F";
        case PciDevice9005::DEVICE_8090: return "DEVICE_8090";
        case PciDevice9005::DEVICE_8091: return "DEVICE_8091";
        case PciDevice9005::DEVICE_8092: return "DEVICE_8092";
        case PciDevice9005::DEVICE_8093: return "DEVICE_8093";
        case PciDevice9005::DEVICE_8094: return "DEVICE_8094";
        case PciDevice9005::DEVICE_8095: return "DEVICE_8095";
        case PciDevice9005::DEVICE_8096: return "DEVICE_8096";
        case PciDevice9005::DEVICE_8097: return "DEVICE_8097";
        case PciDevice9005::DEVICE_809C: return "DEVICE_809C";
        case PciDevice9005::DEVICE_809D: return "DEVICE_809D";
        case PciDevice9005::DEVICE_809E: return "DEVICE_809E";
        case PciDevice9005::DEVICE_809F: return "DEVICE_809F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice9005 device9005) // TEST: NO
{
    // COMMON_LT((" | device9005 = %u", device9005)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device9005, enumToString(device9005));

    return res;
}



inline const char8* enumToHumanString(PciDevice9005 device9005) // TEST: NO
{
    // COMMON_LT((" | device9005 = %u", device9005)); // Commented to avoid bad looking logs



    switch (device9005)
    {
        case PciDevice9005::DEVICE_0010: return "AHA-2940U2/U2W";
        case PciDevice9005::DEVICE_0011: return "AHA-2930U2";
        case PciDevice9005::DEVICE_0013: return "78902";
        case PciDevice9005::DEVICE_001F: return "AHA-2940U2/U2W / 7890/7891";
        case PciDevice9005::DEVICE_0020: return "AIC-7890";
        case PciDevice9005::DEVICE_002F: return "AIC-7890";
        case PciDevice9005::DEVICE_0030: return "AIC-7890";
        case PciDevice9005::DEVICE_003F: return "AIC-7890";
        case PciDevice9005::DEVICE_0050: return "AHA-3940U2x/395U2x";
        case PciDevice9005::DEVICE_0051: return "AHA-3950U2D";
        case PciDevice9005::DEVICE_0053: return "AIC-7896 SCSI Controller";
        case PciDevice9005::DEVICE_005F: return "AIC-7896U2/7897U2";
        case PciDevice9005::DEVICE_0080: return "AIC-7892A U160/m";
        case PciDevice9005::DEVICE_0081: return "AIC-7892B U160/m";
        case PciDevice9005::DEVICE_0083: return "AIC-7892D U160/m";
        case PciDevice9005::DEVICE_008F: return "AIC-7892P U160/m";
        case PciDevice9005::DEVICE_0092: return "AVC-2010 [VideoH!]";
        case PciDevice9005::DEVICE_0093: return "AVC-2410 [VideoH!]";
        case PciDevice9005::DEVICE_00C0: return "AHA-3960D / AIC-7899A U160/m";
        case PciDevice9005::DEVICE_00C1: return "AIC-7899B U160/m";
        case PciDevice9005::DEVICE_00C3: return "AIC-7899D U160/m";
        case PciDevice9005::DEVICE_00C5: return "RAID subsystem HBA";
        case PciDevice9005::DEVICE_00CF: return "AIC-7899P U160/m";
        case PciDevice9005::DEVICE_0241: return "Serial ATA II RAID 1420SA";
        case PciDevice9005::DEVICE_0242: return "Serial ATA II RAID 1220SA";
        case PciDevice9005::DEVICE_0243: return "Serial ATA II RAID 1430SA";
        case PciDevice9005::DEVICE_0244: return "eSATA II RAID 1225SA";
        case PciDevice9005::DEVICE_0250: return "ServeRAID Controller";
        case PciDevice9005::DEVICE_0279: return "ServeRAID 6M";
        case PciDevice9005::DEVICE_0283: return "AAC-RAID";
        case PciDevice9005::DEVICE_0284: return "AAC-RAID";
        case PciDevice9005::DEVICE_0285: return "AAC-RAID";
        case PciDevice9005::DEVICE_0286: return "AAC-RAID (Rocket)";
        case PciDevice9005::DEVICE_028B: return "Series 6 - 6G SAS/PCIe 2";
        case PciDevice9005::DEVICE_028C: return "Series 7 6G SAS/PCIe 3";
        case PciDevice9005::DEVICE_028D: return "Series 8 12G SAS/PCIe 3";
        case PciDevice9005::DEVICE_028F: return "Smart Storage PQI 12G SAS/PCIe 3";
        case PciDevice9005::DEVICE_0410: return "AIC-9410W SAS (Razor HBA RAID)";
        case PciDevice9005::DEVICE_0412: return "AIC-9410W SAS (Razor HBA non-RAID)";
        case PciDevice9005::DEVICE_0415: return "ASC-58300 SAS (Razor-External HBA RAID)";
        case PciDevice9005::DEVICE_0416: return "ASC-58300 SAS (Razor-External HBA non-RAID)";
        case PciDevice9005::DEVICE_041E: return "AIC-9410W SAS (Razor ASIC non-RAID)";
        case PciDevice9005::DEVICE_041F: return "AIC-9410W SAS (Razor ASIC RAID)";
        case PciDevice9005::DEVICE_042F: return "VSC7250/7251 SAS (Aurora ASIC non-RAID)";
        case PciDevice9005::DEVICE_0430: return "AIC-9405W SAS (Razor-Lite HBA RAID)";
        case PciDevice9005::DEVICE_0432: return "AIC-9405W SAS (Razor-Lite HBA non-RAID)";
        case PciDevice9005::DEVICE_043E: return "AIC-9405W SAS (Razor-Lite ASIC non-RAID)";
        case PciDevice9005::DEVICE_043F: return "AIC-9405W SAS (Razor-Lite ASIC RAID)";
        case PciDevice9005::DEVICE_0450: return "ASC-1405 Unified Serial HBA";
        case PciDevice9005::DEVICE_0500: return "Obsidian chipset SCSI controller";
        case PciDevice9005::DEVICE_0503: return "Scamp chipset SCSI controller";
        case PciDevice9005::DEVICE_0910: return "AUA-3100B";
        case PciDevice9005::DEVICE_091E: return "AUA-3100B";
        case PciDevice9005::DEVICE_8000: return "ASC-29320A U320";
        case PciDevice9005::DEVICE_800F: return "AIC-7901 U320";
        case PciDevice9005::DEVICE_8010: return "ASC-39320 U320";
        case PciDevice9005::DEVICE_8011: return "ASC-39320D";
        case PciDevice9005::DEVICE_8012: return "ASC-29320 U320";
        case PciDevice9005::DEVICE_8013: return "ASC-29320B U320";
        case PciDevice9005::DEVICE_8014: return "ASC-29320LP U320";
        case PciDevice9005::DEVICE_8015: return "ASC-39320B U320";
        case PciDevice9005::DEVICE_8016: return "ASC-39320A U320";
        case PciDevice9005::DEVICE_8017: return "ASC-29320ALP U320";
        case PciDevice9005::DEVICE_801C: return "ASC-39320D U320";
        case PciDevice9005::DEVICE_801D: return "AIC-7902B U320";
        case PciDevice9005::DEVICE_801E: return "AIC-7901A U320";
        case PciDevice9005::DEVICE_801F: return "AIC-7902 U320";
        case PciDevice9005::DEVICE_8080: return "ASC-29320A U320 w/HostRAID";
        case PciDevice9005::DEVICE_8081: return "PMC-Sierra PM8001 SAS HBA [Series 6H]";
        case PciDevice9005::DEVICE_8088: return "PMC-Sierra PM8018 SAS HBA [Series 7H]";
        case PciDevice9005::DEVICE_8089: return "PMC-Sierra PM8019 SAS encryption HBA [Series 7He]";
        case PciDevice9005::DEVICE_808F: return "AIC-7901 U320 w/HostRAID";
        case PciDevice9005::DEVICE_8090: return "ASC-39320 U320 w/HostRAID";
        case PciDevice9005::DEVICE_8091: return "ASC-39320D U320 w/HostRAID";
        case PciDevice9005::DEVICE_8092: return "ASC-29320 U320 w/HostRAID";
        case PciDevice9005::DEVICE_8093: return "ASC-29320B U320 w/HostRAID";
        case PciDevice9005::DEVICE_8094: return "ASC-29320LP U320 w/HostRAID";
        case PciDevice9005::DEVICE_8095: return "ASC-39320(B) U320 w/HostRAID";
        case PciDevice9005::DEVICE_8096: return "ASC-39320A U320 w/HostRAID";
        case PciDevice9005::DEVICE_8097: return "ASC-29320ALP U320 w/HostRAID";
        case PciDevice9005::DEVICE_809C: return "ASC-39320D(B) U320 w/HostRAID";
        case PciDevice9005::DEVICE_809D: return "AIC-7902(B) U320 w/HostRAID";
        case PciDevice9005::DEVICE_809E: return "AIC-7901A U320 w/HostRAID";
        case PciDevice9005::DEVICE_809F: return "AIC-7902 U320 w/HostRAID";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR9005_PCIDEVICE9005_H
