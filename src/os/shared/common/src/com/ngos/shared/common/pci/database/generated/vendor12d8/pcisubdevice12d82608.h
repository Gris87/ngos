// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCISUBDEVICE12D82608_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCISUBDEVICE12D82608_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12D82608: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_EA50CC10 = 0xEA50CC10
};



inline const char8* enumToString(PciSubDevice12D82608 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12D82608::NONE:               return "NONE";
        case PciSubDevice12D82608::SUBDEVICE_EA50CC10: return "SUBDEVICE_EA50CC10";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12D82608 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12D82608 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12D82608::SUBDEVICE_EA50CC10: return "RXi2-BP";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCISUBDEVICE12D82608_H
