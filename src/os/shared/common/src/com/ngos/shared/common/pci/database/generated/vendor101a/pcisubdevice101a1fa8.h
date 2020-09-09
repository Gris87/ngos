// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A1FA8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A1FA8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101A1FA8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101A00C3 = 0x101A00C3
};



inline const char8* enumToString(PciSubDevice101A1FA8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101A1FA8::NONE:               return "NONE";
        case PciSubDevice101A1FA8::SUBDEVICE_101A00C3: return "SUBDEVICE_101A00C3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101A1FA8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101A1FA8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101A1FA8::SUBDEVICE_101A00C3: return "BYNET BIC2SE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A1FA8_H
