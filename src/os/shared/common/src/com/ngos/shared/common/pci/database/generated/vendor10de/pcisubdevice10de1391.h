// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1391_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1391_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE1391: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_17AA3697 = 0x17AA3697,
    SUBDEVICE_17AAA125 = 0x17AAA125
};



inline const char8* enumToString(PciSubDevice10DE1391 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1391::NONE:               return "NONE";
        case PciSubDevice10DE1391::SUBDEVICE_17AA3697: return "SUBDEVICE_17AA3697";
        case PciSubDevice10DE1391::SUBDEVICE_17AAA125: return "SUBDEVICE_17AAA125";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE1391 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE1391 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE1391::SUBDEVICE_17AA3697: return "GeForce GTX 850A";
        case PciSubDevice10DE1391::SUBDEVICE_17AAA125: return "GeForce GTX 850A";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE1391_H
