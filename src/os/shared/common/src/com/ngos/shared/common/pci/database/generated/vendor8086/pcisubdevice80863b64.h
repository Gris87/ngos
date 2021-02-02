// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B64_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B64_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863B64: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250347 = 0x10250347,
    SUBDEVICE_15D9060D = 0x15D9060D,
    SUBDEVICE_17C010D2 = 0x17C010D2,
    SUBDEVICE_E4BF50C1 = 0xE4BF50C1
};



inline const char8* enumToString(PciSubDevice80863B64 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B64::NONE:               return "NONE";
        case PciSubDevice80863B64::SUBDEVICE_10250347: return "SUBDEVICE_10250347";
        case PciSubDevice80863B64::SUBDEVICE_15D9060D: return "SUBDEVICE_15D9060D";
        case PciSubDevice80863B64::SUBDEVICE_17C010D2: return "SUBDEVICE_17C010D2";
        case PciSubDevice80863B64::SUBDEVICE_E4BF50C1: return "SUBDEVICE_E4BF50C1";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863B64 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863B64 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863B64::SUBDEVICE_10250347: return "Aspire 7740G";
        case PciSubDevice80863B64::SUBDEVICE_15D9060D: return "C7SIM-Q Motherboard";
        case PciSubDevice80863B64::SUBDEVICE_17C010D2: return "Medion Akoya E7214 Notebook PC [MD98410]";
        case PciSubDevice80863B64::SUBDEVICE_E4BF50C1: return "PC1-GROOVE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863B64_H
