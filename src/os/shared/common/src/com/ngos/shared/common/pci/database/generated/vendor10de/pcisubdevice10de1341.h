// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1341_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1341_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1341: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA3697 = 0x17AA3697,
    SUBDEVICE_17AA3699 = 0x17AA3699,
    SUBDEVICE_17AA369C = 0x17AA369C
};



inline const char8* enumToString(PciSubDevice10DE1341 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1341::NONE:               return "NONE";
        case PciSubDevice10DE1341::SUBDEVICE_17AA3697: return "SUBDEVICE_17AA3697";
        case PciSubDevice10DE1341::SUBDEVICE_17AA3699: return "SUBDEVICE_17AA3699";
        case PciSubDevice10DE1341::SUBDEVICE_17AA369C: return "SUBDEVICE_17AA369C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1341 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1341 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1341::SUBDEVICE_17AA3697: return "GeForce 840A";
        case PciSubDevice10DE1341::SUBDEVICE_17AA3699: return "GeForce 840A";
        case PciSubDevice10DE1341::SUBDEVICE_17AA369C: return "GeForce 840A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1341_H
