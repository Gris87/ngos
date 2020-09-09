// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19691063_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19691063_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19691063: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1458E000 = 0x1458E000,
    SUBDEVICE_17C010D2 = 0x17C010D2
};



inline const char8* enumToString(PciSubDevice19691063 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19691063::NONE:               return "NONE";
        case PciSubDevice19691063::SUBDEVICE_1458E000: return "SUBDEVICE_1458E000";
        case PciSubDevice19691063::SUBDEVICE_17C010D2: return "SUBDEVICE_17C010D2";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19691063 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19691063 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19691063::SUBDEVICE_1458E000: return "GA-G31M-ES2L Motherboard";
        case PciSubDevice19691063::SUBDEVICE_17C010D2: return "Medion Akoya E7214 Notebook PC [MD98410]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1969_PCISUBDEVICE19691063_H
