// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCISUBDEVICE101E9063_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCISUBDEVICE101E9063_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101E9063: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101E0767 = 0x101E0767
};



inline const char8* enumToString(PciSubDevice101E9063 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101E9063::NONE:               return "NONE";
        case PciSubDevice101E9063::SUBDEVICE_101E0767: return "SUBDEVICE_101E0767";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101E9063 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101E9063 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101E9063::SUBDEVICE_101E0767: return "Dell Remote Assistant Card 2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101E_PCISUBDEVICE101E9063_H
