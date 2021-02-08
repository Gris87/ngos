// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086105E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086105E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086105E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C7044 = 0x103C7044,
    SUBDEVICE_103C704E = 0x103C704E,
    SUBDEVICE_17751100 = 0x17751100,
    SUBDEVICE_17756003 = 0x17756003,
    SUBDEVICE_18DF1214 = 0x18DF1214,
    SUBDEVICE_8086005E = 0x8086005E,
    SUBDEVICE_8086105E = 0x8086105E,
    SUBDEVICE_808610D5 = 0x808610D5,
    SUBDEVICE_8086115E = 0x8086115E,
    SUBDEVICE_8086125E = 0x8086125E,
    SUBDEVICE_8086135E = 0x8086135E
};



inline const char8* enumToString(PciSubDevice8086105E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086105E::NONE:               return "NONE";
        case PciSubDevice8086105E::SUBDEVICE_103C7044: return "SUBDEVICE_103C7044";
        case PciSubDevice8086105E::SUBDEVICE_103C704E: return "SUBDEVICE_103C704E";
        case PciSubDevice8086105E::SUBDEVICE_17751100: return "SUBDEVICE_17751100";
        case PciSubDevice8086105E::SUBDEVICE_17756003: return "SUBDEVICE_17756003";
        case PciSubDevice8086105E::SUBDEVICE_18DF1214: return "SUBDEVICE_18DF1214";
        case PciSubDevice8086105E::SUBDEVICE_8086005E: return "SUBDEVICE_8086005E";
        case PciSubDevice8086105E::SUBDEVICE_8086105E: return "SUBDEVICE_8086105E";
        case PciSubDevice8086105E::SUBDEVICE_808610D5: return "SUBDEVICE_808610D5";
        case PciSubDevice8086105E::SUBDEVICE_8086115E: return "SUBDEVICE_8086115E";
        case PciSubDevice8086105E::SUBDEVICE_8086125E: return "SUBDEVICE_8086125E";
        case PciSubDevice8086105E::SUBDEVICE_8086135E: return "SUBDEVICE_8086135E";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086105E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086105E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086105E::SUBDEVICE_103C7044: return "NC360T PCI Express Dual Port Gigabit Server Adapter";
        case PciSubDevice8086105E::SUBDEVICE_103C704E: return "Dual Port 1000Base-T (PCIe) [AD337A]";
        case PciSubDevice8086105E::SUBDEVICE_17751100: return "CR11/VR11 Single Board Computer";
        case PciSubDevice8086105E::SUBDEVICE_17756003: return "Telum GE-QT";
        case PciSubDevice8086105E::SUBDEVICE_18DF1214: return "2x 1GbE, PCIe x1, dual Intel 82571EB chips";
        case PciSubDevice8086105E::SUBDEVICE_8086005E: return "PRO/1000 PT Dual Port Server Connection";
        case PciSubDevice8086105E::SUBDEVICE_8086105E: return "PRO/1000 PT Dual Port Network Connection";
        case PciSubDevice8086105E::SUBDEVICE_808610D5: return "82571PT Gigabit PT Quad Port Server ExpressModule";
        case PciSubDevice8086105E::SUBDEVICE_8086115E: return "PRO/1000 PT Dual Port Server Adapter";
        case PciSubDevice8086105E::SUBDEVICE_8086125E: return "PRO/1000 PT Dual Port Server Adapter";
        case PciSubDevice8086105E::SUBDEVICE_8086135E: return "PRO/1000 PT Dual Port Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086105E_H
