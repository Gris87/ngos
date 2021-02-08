// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A0007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A0007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice101A0007: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_101A0019 = 0x101A0019,
    SUBDEVICE_101A001C = 0x101A001C,
    SUBDEVICE_101A001F = 0x101A001F
};



inline const char8* enumToString(PciSubDevice101A0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101A0007::NONE:               return "NONE";
        case PciSubDevice101A0007::SUBDEVICE_101A0019: return "SUBDEVICE_101A0019";
        case PciSubDevice101A0007::SUBDEVICE_101A001C: return "SUBDEVICE_101A001C";
        case PciSubDevice101A0007::SUBDEVICE_101A001F: return "SUBDEVICE_101A001F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice101A0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice101A0007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice101A0007::SUBDEVICE_101A0019: return "BYNET BIC2C";
        case PciSubDevice101A0007::SUBDEVICE_101A001C: return "BYNET BIC2G";
        case PciSubDevice101A0007::SUBDEVICE_101A001F: return "BYNET BIC4G";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR101A_PCISUBDEVICE101A0007_H
