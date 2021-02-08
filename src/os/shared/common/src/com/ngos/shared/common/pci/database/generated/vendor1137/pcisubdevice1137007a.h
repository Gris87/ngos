// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE1137007A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE1137007A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1137007A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1137012A = 0x1137012A,
    SUBDEVICE_1137012C = 0x1137012C,
    SUBDEVICE_11370137 = 0x11370137,
    SUBDEVICE_1137014D = 0x1137014D
};



inline const char8* enumToString(PciSubDevice1137007A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1137007A::NONE:               return "NONE";
        case PciSubDevice1137007A::SUBDEVICE_1137012A: return "SUBDEVICE_1137012A";
        case PciSubDevice1137007A::SUBDEVICE_1137012C: return "SUBDEVICE_1137012C";
        case PciSubDevice1137007A::SUBDEVICE_11370137: return "SUBDEVICE_11370137";
        case PciSubDevice1137007A::SUBDEVICE_1137014D: return "SUBDEVICE_1137014D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1137007A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1137007A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1137007A::SUBDEVICE_1137012A: return "VIC M4308 Dual 40Gb";
        case PciSubDevice1137007A::SUBDEVICE_1137012C: return "VIC 1340 Dual 40Gb MLOM";
        case PciSubDevice1137007A::SUBDEVICE_11370137: return "VIC 1380 Dual 40Gb Mezzanine";
        case PciSubDevice1137007A::SUBDEVICE_1137014D: return "VIC 1385 Dual 40Gb PCIe";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1137_PCISUBDEVICE1137007A_H
