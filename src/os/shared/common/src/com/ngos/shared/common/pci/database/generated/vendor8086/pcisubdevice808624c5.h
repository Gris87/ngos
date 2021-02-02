// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C5_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C5_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624C5: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100B8 = 0x0E1100B8,
    SUBDEVICE_10140267 = 0x10140267,
    SUBDEVICE_10140537 = 0x10140537,
    SUBDEVICE_1014055F = 0x1014055F,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_10250064 = 0x10250064,
    SUBDEVICE_10280139 = 0x10280139,
    SUBDEVICE_1028014F = 0x1028014F,
    SUBDEVICE_10280152 = 0x10280152,
    SUBDEVICE_10280160 = 0x10280160,
    SUBDEVICE_10280163 = 0x10280163,
    SUBDEVICE_1028018D = 0x1028018D,
    SUBDEVICE_10280196 = 0x10280196,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_103C0890 = 0x103C0890,
    SUBDEVICE_103C08B0 = 0x103C08B0,
    SUBDEVICE_10431713 = 0x10431713,
    SUBDEVICE_104380B0 = 0x104380B0,
    SUBDEVICE_10718160 = 0x10718160,
    SUBDEVICE_11790201 = 0x11790201,
    SUBDEVICE_144DC005 = 0x144DC005,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_1458A002 = 0x1458A002,
    SUBDEVICE_14625800 = 0x14625800,
    SUBDEVICE_17341005 = 0x17341005,
    SUBDEVICE_17341055 = 0x17341055
};



inline const char8* enumToString(PciSubDevice808624C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624C5::NONE:               return "NONE";
        case PciSubDevice808624C5::SUBDEVICE_0E1100B8: return "SUBDEVICE_0E1100B8";
        case PciSubDevice808624C5::SUBDEVICE_10140267: return "SUBDEVICE_10140267";
        case PciSubDevice808624C5::SUBDEVICE_10140537: return "SUBDEVICE_10140537";
        case PciSubDevice808624C5::SUBDEVICE_1014055F: return "SUBDEVICE_1014055F";
        case PciSubDevice808624C5::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice808624C5::SUBDEVICE_10250064: return "SUBDEVICE_10250064";
        case PciSubDevice808624C5::SUBDEVICE_10280139: return "SUBDEVICE_10280139";
        case PciSubDevice808624C5::SUBDEVICE_1028014F: return "SUBDEVICE_1028014F";
        case PciSubDevice808624C5::SUBDEVICE_10280152: return "SUBDEVICE_10280152";
        case PciSubDevice808624C5::SUBDEVICE_10280160: return "SUBDEVICE_10280160";
        case PciSubDevice808624C5::SUBDEVICE_10280163: return "SUBDEVICE_10280163";
        case PciSubDevice808624C5::SUBDEVICE_1028018D: return "SUBDEVICE_1028018D";
        case PciSubDevice808624C5::SUBDEVICE_10280196: return "SUBDEVICE_10280196";
        case PciSubDevice808624C5::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice808624C5::SUBDEVICE_103C0890: return "SUBDEVICE_103C0890";
        case PciSubDevice808624C5::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";
        case PciSubDevice808624C5::SUBDEVICE_10431713: return "SUBDEVICE_10431713";
        case PciSubDevice808624C5::SUBDEVICE_104380B0: return "SUBDEVICE_104380B0";
        case PciSubDevice808624C5::SUBDEVICE_10718160: return "SUBDEVICE_10718160";
        case PciSubDevice808624C5::SUBDEVICE_11790201: return "SUBDEVICE_11790201";
        case PciSubDevice808624C5::SUBDEVICE_144DC005: return "SUBDEVICE_144DC005";
        case PciSubDevice808624C5::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice808624C5::SUBDEVICE_1458A002: return "SUBDEVICE_1458A002";
        case PciSubDevice808624C5::SUBDEVICE_14625800: return "SUBDEVICE_14625800";
        case PciSubDevice808624C5::SUBDEVICE_17341005: return "SUBDEVICE_17341005";
        case PciSubDevice808624C5::SUBDEVICE_17341055: return "SUBDEVICE_17341055";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624C5 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624C5::SUBDEVICE_0E1100B8: return "Analog Devices Inc. codec [SoundMAX]";
        case PciSubDevice808624C5::SUBDEVICE_10140267: return "NetVista A30p";
        case PciSubDevice808624C5::SUBDEVICE_10140537: return "ThinkPad T4x Series";
        case PciSubDevice808624C5::SUBDEVICE_1014055F: return "Thinkpad R50e model 1634";
        case PciSubDevice808624C5::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice808624C5::SUBDEVICE_10250064: return "Extensa 3000 series laptop: Intel 82801DBM (ICH4-M)";
        case PciSubDevice808624C5::SUBDEVICE_10280139: return "Latitude D400";
        case PciSubDevice808624C5::SUBDEVICE_1028014F: return "Latitude X300";
        case PciSubDevice808624C5::SUBDEVICE_10280152: return "Latitude D500";
        case PciSubDevice808624C5::SUBDEVICE_10280160: return "Dimension 2400";
        case PciSubDevice808624C5::SUBDEVICE_10280163: return "Latitude D505";
        case PciSubDevice808624C5::SUBDEVICE_1028018D: return "Inspiron 700m/710m [SigmaTel STAC9750, 51]";
        case PciSubDevice808624C5::SUBDEVICE_10280196: return "Inspiron 5160";
        case PciSubDevice808624C5::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice808624C5::SUBDEVICE_103C0890: return "NC6000 laptop";
        case PciSubDevice808624C5::SUBDEVICE_103C08B0: return "tc1100 tablet";
        case PciSubDevice808624C5::SUBDEVICE_10431713: return "M2400N/M6800N laptop";
        case PciSubDevice808624C5::SUBDEVICE_104380B0: return "P4B533";
        case PciSubDevice808624C5::SUBDEVICE_10718160: return "MIM2000";
        case PciSubDevice808624C5::SUBDEVICE_11790201: return "Toshiba Tecra M1";
        case PciSubDevice808624C5::SUBDEVICE_144DC005: return "X10 Laptop";
        case PciSubDevice808624C5::SUBDEVICE_144DC00C: return "P30/P35 notebook";
        case PciSubDevice808624C5::SUBDEVICE_1458A002: return "GA-8PE667 Ultra";
        case PciSubDevice808624C5::SUBDEVICE_14625800: return "845PE Max (MS-6580)";
        case PciSubDevice808624C5::SUBDEVICE_17341005: return "D1451 (SCENIC N300, bad_int845GV) Sigmatel STAC9750T";
        case PciSubDevice808624C5::SUBDEVICE_17341055: return "Amilo M1420";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624C5_H
