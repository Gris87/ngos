// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808629C0_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808629C0_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808629C0: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028020D = 0x1028020D,
    SUBDEVICE_103C2A6F = 0x103C2A6F,
    SUBDEVICE_10438276 = 0x10438276,
    SUBDEVICE_104382B0 = 0x104382B0,
    SUBDEVICE_14627345 = 0x14627345,
    SUBDEVICE_14627360 = 0x14627360,
    SUBDEVICE_1AF41100 = 0x1AF41100,
    SUBDEVICE_80865044 = 0x80865044
};



inline const char8* enumToString(PciSubDevice808629C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808629C0::NONE:               return "NONE";
        case PciSubDevice808629C0::SUBDEVICE_1028020D: return "SUBDEVICE_1028020D";
        case PciSubDevice808629C0::SUBDEVICE_103C2A6F: return "SUBDEVICE_103C2A6F";
        case PciSubDevice808629C0::SUBDEVICE_10438276: return "SUBDEVICE_10438276";
        case PciSubDevice808629C0::SUBDEVICE_104382B0: return "SUBDEVICE_104382B0";
        case PciSubDevice808629C0::SUBDEVICE_14627345: return "SUBDEVICE_14627345";
        case PciSubDevice808629C0::SUBDEVICE_14627360: return "SUBDEVICE_14627360";
        case PciSubDevice808629C0::SUBDEVICE_1AF41100: return "SUBDEVICE_1AF41100";
        case PciSubDevice808629C0::SUBDEVICE_80865044: return "SUBDEVICE_80865044";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808629C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808629C0 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808629C0::SUBDEVICE_1028020D: return "Inspiron 530";
        case PciSubDevice808629C0::SUBDEVICE_103C2A6F: return "Asus IPIBL-LB Motherboard";
        case PciSubDevice808629C0::SUBDEVICE_10438276: return "P5K PRO Motherboard: Intel 82P35 Northbridge";
        case PciSubDevice808629C0::SUBDEVICE_104382B0: return "P5KPL-VM Motherboard";
        case PciSubDevice808629C0::SUBDEVICE_14627345: return "MS-7345 Motherboard: Intel 82G33/P35 Northbridge";
        case PciSubDevice808629C0::SUBDEVICE_14627360: return "G33/P35 Neo";
        case PciSubDevice808629C0::SUBDEVICE_1AF41100: return "QEMU Virtual Machine";
        case PciSubDevice808629C0::SUBDEVICE_80865044: return "Desktop Board DP35DP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808629C0_H
