// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B42_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B42_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863B42: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102802DA = 0x102802DA,
    SUBDEVICE_1028040A = 0x1028040A,
    SUBDEVICE_1028040B = 0x1028040B,
    SUBDEVICE_103C1521 = 0x103C1521,
    SUBDEVICE_144DC06A = 0x144DC06A,
    SUBDEVICE_15D9060D = 0x15D9060D,
    SUBDEVICE_17C010D2 = 0x17C010D2
};



inline const char8* enumToString(PciSubDevice80863B42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B42::NONE:               return "NONE";
        case PciSubDevice80863B42::SUBDEVICE_102802DA: return "SUBDEVICE_102802DA";
        case PciSubDevice80863B42::SUBDEVICE_1028040A: return "SUBDEVICE_1028040A";
        case PciSubDevice80863B42::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";
        case PciSubDevice80863B42::SUBDEVICE_103C1521: return "SUBDEVICE_103C1521";
        case PciSubDevice80863B42::SUBDEVICE_144DC06A: return "SUBDEVICE_144DC06A";
        case PciSubDevice80863B42::SUBDEVICE_15D9060D: return "SUBDEVICE_15D9060D";
        case PciSubDevice80863B42::SUBDEVICE_17C010D2: return "SUBDEVICE_17C010D2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863B42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863B42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B42::SUBDEVICE_102802DA: return "OptiPlex 980";
        case PciSubDevice80863B42::SUBDEVICE_1028040A: return "Latitude E6410";
        case PciSubDevice80863B42::SUBDEVICE_1028040B: return "Latitude E6510";
        case PciSubDevice80863B42::SUBDEVICE_103C1521: return "EliteBook 8540p";
        case PciSubDevice80863B42::SUBDEVICE_144DC06A: return "R730 Laptop";
        case PciSubDevice80863B42::SUBDEVICE_15D9060D: return "C7SIM-Q Motherboard";
        case PciSubDevice80863B42::SUBDEVICE_17C010D2: return "Medion Akoya E7214 Notebook PC [MD98410]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B42_H
