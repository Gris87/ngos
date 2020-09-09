// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E01C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E01C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1133E01C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11331C01 = 0x11331C01,
    SUBDEVICE_11331C02 = 0x11331C02,
    SUBDEVICE_11331C03 = 0x11331C03,
    SUBDEVICE_11331C04 = 0x11331C04,
    SUBDEVICE_11331C05 = 0x11331C05,
    SUBDEVICE_11331C06 = 0x11331C06,
    SUBDEVICE_11331C07 = 0x11331C07,
    SUBDEVICE_11331C08 = 0x11331C08,
    SUBDEVICE_11331C09 = 0x11331C09,
    SUBDEVICE_11331C0A = 0x11331C0A,
    SUBDEVICE_11331C0B = 0x11331C0B,
    SUBDEVICE_11331C0C = 0x11331C0C
};



inline const char8* enumToString(PciSubDevice1133E01C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E01C::NONE:               return "NONE";
        case PciSubDevice1133E01C::SUBDEVICE_11331C01: return "SUBDEVICE_11331C01";
        case PciSubDevice1133E01C::SUBDEVICE_11331C02: return "SUBDEVICE_11331C02";
        case PciSubDevice1133E01C::SUBDEVICE_11331C03: return "SUBDEVICE_11331C03";
        case PciSubDevice1133E01C::SUBDEVICE_11331C04: return "SUBDEVICE_11331C04";
        case PciSubDevice1133E01C::SUBDEVICE_11331C05: return "SUBDEVICE_11331C05";
        case PciSubDevice1133E01C::SUBDEVICE_11331C06: return "SUBDEVICE_11331C06";
        case PciSubDevice1133E01C::SUBDEVICE_11331C07: return "SUBDEVICE_11331C07";
        case PciSubDevice1133E01C::SUBDEVICE_11331C08: return "SUBDEVICE_11331C08";
        case PciSubDevice1133E01C::SUBDEVICE_11331C09: return "SUBDEVICE_11331C09";
        case PciSubDevice1133E01C::SUBDEVICE_11331C0A: return "SUBDEVICE_11331C0A";
        case PciSubDevice1133E01C::SUBDEVICE_11331C0B: return "SUBDEVICE_11331C0B";
        case PciSubDevice1133E01C::SUBDEVICE_11331C0C: return "SUBDEVICE_11331C0C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1133E01C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1133E01C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1133E01C::SUBDEVICE_11331C01: return "Diva PRI/E1/T1-8 PCI v3";
        case PciSubDevice1133E01C::SUBDEVICE_11331C02: return "Diva PRI/T1-24 PCI(e) v3";
        case PciSubDevice1133E01C::SUBDEVICE_11331C03: return "Diva PRI/E1-30 PCI(e) v3";
        case PciSubDevice1133E01C::SUBDEVICE_11331C04: return "Diva PRI/E1/T1-CTI PCI(e) v3";
        case PciSubDevice1133E01C::SUBDEVICE_11331C05: return "Diva V-PRI/T1-24 PCI(e) v3";
        case PciSubDevice1133E01C::SUBDEVICE_11331C06: return "Diva V-PRI/E1-30 PCI(e) v3";
        case PciSubDevice1133E01C::SUBDEVICE_11331C07: return "Diva Server PRI/E1/T1-8 Cornet NQ";
        case PciSubDevice1133E01C::SUBDEVICE_11331C08: return "Diva Server PRI/T1-24 Cornet NQ";
        case PciSubDevice1133E01C::SUBDEVICE_11331C09: return "Diva Server PRI/E1-30 Cornet NQ";
        case PciSubDevice1133E01C::SUBDEVICE_11331C0A: return "Diva Server PRI/E1/T1 Cornet NQ";
        case PciSubDevice1133E01C::SUBDEVICE_11331C0B: return "Diva Server V-PRI/T1-24 Cornet NQ";
        case PciSubDevice1133E01C::SUBDEVICE_11331C0C: return "Diva Server V-PRI/E1-30 Cornet NQ";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1133_PCISUBDEVICE1133E01C_H
