// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086100F: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140269 = 0x10140269,
    SUBDEVICE_1014028E = 0x1014028E,
    SUBDEVICE_15AD0750 = 0x15AD0750,
    SUBDEVICE_80861000 = 0x80861000,
    SUBDEVICE_80861001 = 0x80861001
};



inline const char8* enumToString(PciSubDevice8086100F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086100F::NONE:               return "NONE";
        case PciSubDevice8086100F::SUBDEVICE_10140269: return "SUBDEVICE_10140269";
        case PciSubDevice8086100F::SUBDEVICE_1014028E: return "SUBDEVICE_1014028E";
        case PciSubDevice8086100F::SUBDEVICE_15AD0750: return "SUBDEVICE_15AD0750";
        case PciSubDevice8086100F::SUBDEVICE_80861000: return "SUBDEVICE_80861000";
        case PciSubDevice8086100F::SUBDEVICE_80861001: return "SUBDEVICE_80861001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086100F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086100F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086100F::SUBDEVICE_10140269: return "iSeries 1000/100/10 Ethernet Adapter";
        case PciSubDevice8086100F::SUBDEVICE_1014028E: return "PRO/1000 MT Network Connection";
        case PciSubDevice8086100F::SUBDEVICE_15AD0750: return "PRO/1000 MT Single Port Adapter";
        case PciSubDevice8086100F::SUBDEVICE_80861000: return "PRO/1000 MT Network Connection";
        case PciSubDevice8086100F::SUBDEVICE_80861001: return "PRO/1000 MT Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086100F_H
