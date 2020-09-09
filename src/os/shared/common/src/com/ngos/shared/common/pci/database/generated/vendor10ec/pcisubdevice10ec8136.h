// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8136_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8136_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10EC8136: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C1985 = 0x103C1985,
    SUBDEVICE_103C2A8C = 0x103C2A8C,
    SUBDEVICE_103C2AB1 = 0x103C2AB1,
    SUBDEVICE_103C30CC = 0x103C30CC,
    SUBDEVICE_1179FF64 = 0x1179FF64,
    SUBDEVICE_17C01053 = 0x17C01053
};



inline const char8* enumToString(PciSubDevice10EC8136 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8136::NONE:               return "NONE";
        case PciSubDevice10EC8136::SUBDEVICE_103C1985: return "SUBDEVICE_103C1985";
        case PciSubDevice10EC8136::SUBDEVICE_103C2A8C: return "SUBDEVICE_103C2A8C";
        case PciSubDevice10EC8136::SUBDEVICE_103C2AB1: return "SUBDEVICE_103C2AB1";
        case PciSubDevice10EC8136::SUBDEVICE_103C30CC: return "SUBDEVICE_103C30CC";
        case PciSubDevice10EC8136::SUBDEVICE_1179FF64: return "SUBDEVICE_1179FF64";
        case PciSubDevice10EC8136::SUBDEVICE_17C01053: return "SUBDEVICE_17C01053";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10EC8136 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10EC8136 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10EC8136::SUBDEVICE_103C1985: return "RTL8106E on Pavilion 17-e163sg Notebook PC";
        case PciSubDevice10EC8136::SUBDEVICE_103C2A8C: return "Compaq 500B Microtower";
        case PciSubDevice10EC8136::SUBDEVICE_103C2AB1: return "Pavilion p6774";
        case PciSubDevice10EC8136::SUBDEVICE_103C30CC: return "Pavilion dv6700";
        case PciSubDevice10EC8136::SUBDEVICE_1179FF64: return "RTL8102E PCI-E Fast Ethernet NIC";
        case PciSubDevice10EC8136::SUBDEVICE_17C01053: return "RTL8101e Medion WIM 2210 Notebook PC [MD96850]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10EC_PCISUBDEVICE10EC8136_H
