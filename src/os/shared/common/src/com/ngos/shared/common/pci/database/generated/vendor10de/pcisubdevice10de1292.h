// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1292_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1292_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1292: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA3675 = 0x17AA3675,
    SUBDEVICE_17AA367C = 0x17AA367C,
    SUBDEVICE_17AA3684 = 0x17AA3684
};



inline const char8* enumToString(PciSubDevice10DE1292 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1292::NONE:               return "NONE";
        case PciSubDevice10DE1292::SUBDEVICE_17AA3675: return "SUBDEVICE_17AA3675";
        case PciSubDevice10DE1292::SUBDEVICE_17AA367C: return "SUBDEVICE_17AA367C";
        case PciSubDevice10DE1292::SUBDEVICE_17AA3684: return "SUBDEVICE_17AA3684";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1292 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1292 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1292::SUBDEVICE_17AA3675: return "GeForce GT 740A";
        case PciSubDevice10DE1292::SUBDEVICE_17AA367C: return "GeForce GT 740A";
        case PciSubDevice10DE1292::SUBDEVICE_17AA3684: return "GeForce GT 740A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1292_H
