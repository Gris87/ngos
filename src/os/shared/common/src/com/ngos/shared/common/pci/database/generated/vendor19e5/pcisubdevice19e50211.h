// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50211_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50211_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19E50211: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_19E5D12F = 0x19E5D12F,
    SUBDEVICE_19E5D137 = 0x19E5D137,
    SUBDEVICE_19E5D142 = 0x19E5D142
};



inline const char8* enumToString(PciSubDevice19E50211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50211::NONE:               return "NONE";
        case PciSubDevice19E50211::SUBDEVICE_19E5D12F: return "SUBDEVICE_19E5D12F";
        case PciSubDevice19E50211::SUBDEVICE_19E5D137: return "SUBDEVICE_19E5D137";
        case PciSubDevice19E50211::SUBDEVICE_19E5D142: return "SUBDEVICE_19E5D142";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19E50211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19E50211 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19E50211::SUBDEVICE_19E5D12F: return "Hi1822 SP571 (4*25GE)";
        case PciSubDevice19E50211::SUBDEVICE_19E5D137: return "Hi1822 SP581 (4*25GE)";
        case PciSubDevice19E50211::SUBDEVICE_19E5D142: return "Hi1822 SP583 (4*25GE)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR19E5_PCISUBDEVICE19E50211_H
