// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CA_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CA_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624CA: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014052D = 0x1014052D,
    SUBDEVICE_1025005A = 0x1025005A,
    SUBDEVICE_10250064 = 0x10250064,
    SUBDEVICE_1028014F = 0x1028014F,
    SUBDEVICE_10280163 = 0x10280163,
    SUBDEVICE_1028018D = 0x1028018D,
    SUBDEVICE_10280196 = 0x10280196,
    SUBDEVICE_103C088C = 0x103C088C,
    SUBDEVICE_103C0890 = 0x103C0890,
    SUBDEVICE_103C08B0 = 0x103C08B0,
    SUBDEVICE_10718160 = 0x10718160,
    SUBDEVICE_144DC005 = 0x144DC005,
    SUBDEVICE_144DC00C = 0x144DC00C,
    SUBDEVICE_17341055 = 0x17341055,
    SUBDEVICE_80864541 = 0x80864541
};



inline const char8* enumToString(PciSubDevice808624CA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624CA::NONE:               return "NONE";
        case PciSubDevice808624CA::SUBDEVICE_1014052D: return "SUBDEVICE_1014052D";
        case PciSubDevice808624CA::SUBDEVICE_1025005A: return "SUBDEVICE_1025005A";
        case PciSubDevice808624CA::SUBDEVICE_10250064: return "SUBDEVICE_10250064";
        case PciSubDevice808624CA::SUBDEVICE_1028014F: return "SUBDEVICE_1028014F";
        case PciSubDevice808624CA::SUBDEVICE_10280163: return "SUBDEVICE_10280163";
        case PciSubDevice808624CA::SUBDEVICE_1028018D: return "SUBDEVICE_1028018D";
        case PciSubDevice808624CA::SUBDEVICE_10280196: return "SUBDEVICE_10280196";
        case PciSubDevice808624CA::SUBDEVICE_103C088C: return "SUBDEVICE_103C088C";
        case PciSubDevice808624CA::SUBDEVICE_103C0890: return "SUBDEVICE_103C0890";
        case PciSubDevice808624CA::SUBDEVICE_103C08B0: return "SUBDEVICE_103C08B0";
        case PciSubDevice808624CA::SUBDEVICE_10718160: return "SUBDEVICE_10718160";
        case PciSubDevice808624CA::SUBDEVICE_144DC005: return "SUBDEVICE_144DC005";
        case PciSubDevice808624CA::SUBDEVICE_144DC00C: return "SUBDEVICE_144DC00C";
        case PciSubDevice808624CA::SUBDEVICE_17341055: return "SUBDEVICE_17341055";
        case PciSubDevice808624CA::SUBDEVICE_80864541: return "SUBDEVICE_80864541";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624CA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624CA subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624CA::SUBDEVICE_1014052D: return "ThinkPad";
        case PciSubDevice808624CA::SUBDEVICE_1025005A: return "TravelMate 290";
        case PciSubDevice808624CA::SUBDEVICE_10250064: return "Extensa 3000 series laptop: Intel 82801DBM (ICH4-M)";
        case PciSubDevice808624CA::SUBDEVICE_1028014F: return "Latitude X300";
        case PciSubDevice808624CA::SUBDEVICE_10280163: return "Latitude D505";
        case PciSubDevice808624CA::SUBDEVICE_1028018D: return "Inspiron 700m/710m";
        case PciSubDevice808624CA::SUBDEVICE_10280196: return "Inspiron 5160";
        case PciSubDevice808624CA::SUBDEVICE_103C088C: return "NC8000 laptop";
        case PciSubDevice808624CA::SUBDEVICE_103C0890: return "NC6000 laptop";
        case PciSubDevice808624CA::SUBDEVICE_103C08B0: return "tc1100 tablet";
        case PciSubDevice808624CA::SUBDEVICE_10718160: return "MIM2000";
        case PciSubDevice808624CA::SUBDEVICE_144DC005: return "X10 Laptop";
        case PciSubDevice808624CA::SUBDEVICE_144DC00C: return "P30/P35 notebook";
        case PciSubDevice808624CA::SUBDEVICE_17341055: return "Amilo M1420";
        case PciSubDevice808624CA::SUBDEVICE_80864541: return "Latitude D400/D500";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624CA_H
