// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC42_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC42_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104CAC42: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102800E6 = 0x102800E6
};



inline const char8* enumToString(PciSubDevice104CAC42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC42::NONE:               return "NONE";
        case PciSubDevice104CAC42::SUBDEVICE_102800E6: return "SUBDEVICE_102800E6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104CAC42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104CAC42 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104CAC42::SUBDEVICE_102800E6: return "PCI4451 PC card CardBus Controller (Inspiron 8100)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104CAC42_H
