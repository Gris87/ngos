// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D3A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D3A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80869D3A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1025115F = 0x1025115F,
    SUBDEVICE_102806D6 = 0x102806D6,
    SUBDEVICE_102806DC = 0x102806DC,
    SUBDEVICE_102806F3 = 0x102806F3,
    SUBDEVICE_103C8079 = 0x103C8079,
    SUBDEVICE_17AA2247 = 0x17AA2247,
    SUBDEVICE_17AA224F = 0x17AA224F,
    SUBDEVICE_17AA225D = 0x17AA225D,
    SUBDEVICE_17AA382A = 0x17AA382A
};



inline const char8* enumToString(PciSubDevice80869D3A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869D3A::NONE:               return "NONE";
        case PciSubDevice80869D3A::SUBDEVICE_1025115F: return "SUBDEVICE_1025115F";
        case PciSubDevice80869D3A::SUBDEVICE_102806D6: return "SUBDEVICE_102806D6";
        case PciSubDevice80869D3A::SUBDEVICE_102806DC: return "SUBDEVICE_102806DC";
        case PciSubDevice80869D3A::SUBDEVICE_102806F3: return "SUBDEVICE_102806F3";
        case PciSubDevice80869D3A::SUBDEVICE_103C8079: return "SUBDEVICE_103C8079";
        case PciSubDevice80869D3A::SUBDEVICE_17AA2247: return "SUBDEVICE_17AA2247";
        case PciSubDevice80869D3A::SUBDEVICE_17AA224F: return "SUBDEVICE_17AA224F";
        case PciSubDevice80869D3A::SUBDEVICE_17AA225D: return "SUBDEVICE_17AA225D";
        case PciSubDevice80869D3A::SUBDEVICE_17AA382A: return "SUBDEVICE_17AA382A";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80869D3A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80869D3A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80869D3A::SUBDEVICE_1025115F: return "Acer Aspire E5-575G";
        case PciSubDevice80869D3A::SUBDEVICE_102806D6: return "Latitude 7275 tablet";
        case PciSubDevice80869D3A::SUBDEVICE_102806DC: return "Latitude E7470";
        case PciSubDevice80869D3A::SUBDEVICE_102806F3: return "Latitude 3570";
        case PciSubDevice80869D3A::SUBDEVICE_103C8079: return "EliteBook 840 G3";
        case PciSubDevice80869D3A::SUBDEVICE_17AA2247: return "ThinkPad T570";
        case PciSubDevice80869D3A::SUBDEVICE_17AA224F: return "ThinkPad X1 Carbon 5th Gen";
        case PciSubDevice80869D3A::SUBDEVICE_17AA225D: return "ThinkPad T480";
        case PciSubDevice80869D3A::SUBDEVICE_17AA382A: return "B51-80 Laptop";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80869D3A_H
