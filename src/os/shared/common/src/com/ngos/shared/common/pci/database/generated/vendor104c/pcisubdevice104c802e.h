// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C802E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C802E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C802E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028018D = 0x1028018D
};



inline const char8* enumToString(PciSubDevice104C802E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C802E::NONE:               return "NONE";
        case PciSubDevice104C802E::SUBDEVICE_1028018D: return "SUBDEVICE_1028018D";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C802E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C802E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C802E::SUBDEVICE_1028018D: return "Inspiron 700m/710m";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C802E_H
