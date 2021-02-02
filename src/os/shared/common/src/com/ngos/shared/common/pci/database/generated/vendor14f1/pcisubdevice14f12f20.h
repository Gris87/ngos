// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12F20_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12F20_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F12F20: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14F1200C = 0x14F1200C,
    SUBDEVICE_14F1200F = 0x14F1200F
};



inline const char8* enumToString(PciSubDevice14F12F20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F12F20::NONE:               return "NONE";
        case PciSubDevice14F12F20::SUBDEVICE_14F1200C: return "SUBDEVICE_14F1200C";
        case PciSubDevice14F12F20::SUBDEVICE_14F1200F: return "SUBDEVICE_14F1200F";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F12F20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F12F20 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F12F20::SUBDEVICE_14F1200C: return "Soft Data Fax Modem with SmartCP";
        case PciSubDevice14F12F20::SUBDEVICE_14F1200F: return "Dimension 3000";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12F20_H
