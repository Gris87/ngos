// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B44_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B44_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863B44: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040A = 0x1028040A,
    SUBDEVICE_1028040B = 0x1028040B,
    SUBDEVICE_15D9060D = 0x15D9060D,
    SUBDEVICE_17C010D2 = 0x17C010D2
};



inline const char8* enumToString(PciSubDevice80863B44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B44::NONE:               return "NONE";
        case PciSubDevice80863B44::SUBDEVICE_1028040A: return "SUBDEVICE_1028040A";
        case PciSubDevice80863B44::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";
        case PciSubDevice80863B44::SUBDEVICE_15D9060D: return "SUBDEVICE_15D9060D";
        case PciSubDevice80863B44::SUBDEVICE_17C010D2: return "SUBDEVICE_17C010D2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863B44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863B44 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B44::SUBDEVICE_1028040A: return "Latitude E6410";
        case PciSubDevice80863B44::SUBDEVICE_1028040B: return "Latitude E6510";
        case PciSubDevice80863B44::SUBDEVICE_15D9060D: return "C7SIM-Q Motherboard";
        case PciSubDevice80863B44::SUBDEVICE_17C010D2: return "Medion Akoya E7214 Notebook PC [MD98410]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B44_H
