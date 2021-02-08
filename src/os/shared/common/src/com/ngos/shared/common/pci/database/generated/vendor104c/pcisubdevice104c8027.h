// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8027_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8027_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C8027: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102800E5 = 0x102800E5,
    SUBDEVICE_102800E6 = 0x102800E6
};



inline const char8* enumToString(PciSubDevice104C8027 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8027::NONE:               return "NONE";
        case PciSubDevice104C8027::SUBDEVICE_102800E5: return "SUBDEVICE_102800E5";
        case PciSubDevice104C8027::SUBDEVICE_102800E6: return "SUBDEVICE_102800E6";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C8027 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C8027 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C8027::SUBDEVICE_102800E5: return "Latitude C810";
        case PciSubDevice104C8027::SUBDEVICE_102800E6: return "PCI4451 IEEE-1394 Controller (Dell Inspiron 8100)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C8027_H
