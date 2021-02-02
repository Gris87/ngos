// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91007_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91007_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12B91007: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12B900A3 = 0x12B900A3,
    SUBDEVICE_12B900C4 = 0x12B900C4
};



inline const char8* enumToString(PciSubDevice12B91007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12B91007::NONE:               return "NONE";
        case PciSubDevice12B91007::SUBDEVICE_12B900A3: return "SUBDEVICE_12B900A3";
        case PciSubDevice12B91007::SUBDEVICE_12B900C4: return "SUBDEVICE_12B900C4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12B91007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12B91007 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12B91007::SUBDEVICE_12B900A3: return "USR 56k Internal WinModem (Model 3595)";
        case PciSubDevice12B91007::SUBDEVICE_12B900C4: return "U.S. Robotics V.92 Voice Faxmodem (2884A/B/C)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12B9_PCISUBDEVICE12B91007_H
