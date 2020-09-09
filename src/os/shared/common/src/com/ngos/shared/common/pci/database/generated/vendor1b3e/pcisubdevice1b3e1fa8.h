// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCISUBDEVICE1B3E1FA8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCISUBDEVICE1B3E1FA8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1B3E1FA8: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1B3E00A3 = 0x1B3E00A3,
    SUBDEVICE_1B3E00C3 = 0x1B3E00C3
};



inline const char8* enumToString(PciSubDevice1B3E1FA8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B3E1FA8::NONE:               return "NONE";
        case PciSubDevice1B3E1FA8::SUBDEVICE_1B3E00A3: return "SUBDEVICE_1B3E00A3";
        case PciSubDevice1B3E1FA8::SUBDEVICE_1B3E00C3: return "SUBDEVICE_1B3E00C3";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1B3E1FA8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1B3E1FA8 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1B3E1FA8::SUBDEVICE_1B3E00A3: return "BYNET BIC2SX";
        case PciSubDevice1B3E1FA8::SUBDEVICE_1B3E00C3: return "BYNET BIC2SE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1B3E_PCISUBDEVICE1B3E1FA8_H
