// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861010_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80861010: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_0E1100DB = 0x0E1100DB,
    SUBDEVICE_1014027C = 0x1014027C,
    SUBDEVICE_15AD0760 = 0x15AD0760,
    SUBDEVICE_18FB7872 = 0x18FB7872,
    SUBDEVICE_1FC10026 = 0x1FC10026,
    SUBDEVICE_4C531080 = 0x4C531080,
    SUBDEVICE_4C5310A0 = 0x4C5310A0,
    SUBDEVICE_80861011 = 0x80861011,
    SUBDEVICE_80861012 = 0x80861012,
    SUBDEVICE_8086101A = 0x8086101A,
    SUBDEVICE_80863424 = 0x80863424
};



inline const char8* enumToString(PciSubDevice80861010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861010::NONE:               return "NONE";
        case PciSubDevice80861010::SUBDEVICE_0E1100DB: return "SUBDEVICE_0E1100DB";
        case PciSubDevice80861010::SUBDEVICE_1014027C: return "SUBDEVICE_1014027C";
        case PciSubDevice80861010::SUBDEVICE_15AD0760: return "SUBDEVICE_15AD0760";
        case PciSubDevice80861010::SUBDEVICE_18FB7872: return "SUBDEVICE_18FB7872";
        case PciSubDevice80861010::SUBDEVICE_1FC10026: return "SUBDEVICE_1FC10026";
        case PciSubDevice80861010::SUBDEVICE_4C531080: return "SUBDEVICE_4C531080";
        case PciSubDevice80861010::SUBDEVICE_4C5310A0: return "SUBDEVICE_4C5310A0";
        case PciSubDevice80861010::SUBDEVICE_80861011: return "SUBDEVICE_80861011";
        case PciSubDevice80861010::SUBDEVICE_80861012: return "SUBDEVICE_80861012";
        case PciSubDevice80861010::SUBDEVICE_8086101A: return "SUBDEVICE_8086101A";
        case PciSubDevice80861010::SUBDEVICE_80863424: return "SUBDEVICE_80863424";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80861010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80861010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80861010::SUBDEVICE_0E1100DB: return "NC7170 Gigabit Server Adapter";
        case PciSubDevice80861010::SUBDEVICE_1014027C: return "PRO/1000 MT Dual Port Network Adapter";
        case PciSubDevice80861010::SUBDEVICE_15AD0760: return "PRO/1000 MT Dual Port Adapter";
        case PciSubDevice80861010::SUBDEVICE_18FB7872: return "RESlink-X";
        case PciSubDevice80861010::SUBDEVICE_1FC10026: return "Niagara 2260 Bypass Card";
        case PciSubDevice80861010::SUBDEVICE_4C531080: return "CT8 mainboard";
        case PciSubDevice80861010::SUBDEVICE_4C5310A0: return "CA3/CR3 mainboard";
        case PciSubDevice80861010::SUBDEVICE_80861011: return "PRO/1000 MT Dual Port Server Adapter";
        case PciSubDevice80861010::SUBDEVICE_80861012: return "PRO/1000 MT Dual Port Server Adapter";
        case PciSubDevice80861010::SUBDEVICE_8086101A: return "PRO/1000 MT Dual Port Network Connection";
        case PciSubDevice80861010::SUBDEVICE_80863424: return "SE7501HG2 Mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80861010_H
