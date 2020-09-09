// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4165A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140378 = 0x10140378,
    SUBDEVICE_1028020F = 0x1028020F,
    SUBDEVICE_10280210 = 0x10280210,
    SUBDEVICE_10280225 = 0x10280225,
    SUBDEVICE_103C7051 = 0x103C7051,
    SUBDEVICE_103C7052 = 0x103C7052
};



inline const char8* enumToString(PciSubDevice14E4165A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4165A::NONE:               return "NONE";
        case PciSubDevice14E4165A::SUBDEVICE_10140378: return "SUBDEVICE_10140378";
        case PciSubDevice14E4165A::SUBDEVICE_1028020F: return "SUBDEVICE_1028020F";
        case PciSubDevice14E4165A::SUBDEVICE_10280210: return "SUBDEVICE_10280210";
        case PciSubDevice14E4165A::SUBDEVICE_10280225: return "SUBDEVICE_10280225";
        case PciSubDevice14E4165A::SUBDEVICE_103C7051: return "SUBDEVICE_103C7051";
        case PciSubDevice14E4165A::SUBDEVICE_103C7052: return "SUBDEVICE_103C7052";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4165A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4165A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4165A::SUBDEVICE_10140378: return "System x3350 (Machine type 4192)";
        case PciSubDevice14E4165A::SUBDEVICE_1028020F: return "PowerEdge R300 Broadcom NetXtreme 5722";
        case PciSubDevice14E4165A::SUBDEVICE_10280210: return "PowerEdge T300 Broadcom NetXtreme 5722";
        case PciSubDevice14E4165A::SUBDEVICE_10280225: return "PowerEdge T105 Broadcom NetXtreme 5722";
        case PciSubDevice14E4165A::SUBDEVICE_103C7051: return "NC105i PCIe Gigabit Server Adapter";
        case PciSubDevice14E4165A::SUBDEVICE_103C7052: return "NC105T PCIe Gigabit Server Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4165A_H
