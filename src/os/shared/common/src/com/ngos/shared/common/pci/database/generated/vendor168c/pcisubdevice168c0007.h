// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice168C0007: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17370007 = 0x17370007,
    SUBDEVICE_1B470100 = 0x1B470100,
    SUBDEVICE_1B470110 = 0x1B470110,
    SUBDEVICE_80862501 = 0x80862501
};



inline const char8* enumToString(PciSubDevice168C0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0007::NONE:               return "NONE";
        case PciSubDevice168C0007::SUBDEVICE_17370007: return "SUBDEVICE_17370007";
        case PciSubDevice168C0007::SUBDEVICE_1B470100: return "SUBDEVICE_1B470100";
        case PciSubDevice168C0007::SUBDEVICE_1B470110: return "SUBDEVICE_1B470110";
        case PciSubDevice168C0007::SUBDEVICE_80862501: return "SUBDEVICE_80862501";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice168C0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice168C0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice168C0007::SUBDEVICE_17370007: return "WPC54A Wireless PC Card";
        case PciSubDevice168C0007::SUBDEVICE_1B470100: return "Harmony 8450CN Wireless CardBus Module";
        case PciSubDevice168C0007::SUBDEVICE_1B470110: return "Skyline 4030 / Harmony 8450 802.11a Wireless CardBus Adapter";
        case PciSubDevice168C0007::SUBDEVICE_80862501: return "PRO/Wireless 5000 LAN PCI Adapter Module";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR168C_PCISUBDEVICE168C0007_H
