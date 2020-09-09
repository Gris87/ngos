// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR001C_PCISUBDEVICE001C0001_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR001C_PCISUBDEVICE001C0001_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice001C0001: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_001C0004 = 0x001C0004,
    SUBDEVICE_001C0005 = 0x001C0005
};



inline const char8* enumToString(PciSubDevice001C0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice001C0001::NONE:               return "NONE";
        case PciSubDevice001C0001::SUBDEVICE_001C0004: return "SUBDEVICE_001C0004";
        case PciSubDevice001C0001::SUBDEVICE_001C0005: return "SUBDEVICE_001C0005";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice001C0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice001C0001 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice001C0001::SUBDEVICE_001C0004: return "2 Channel CAN Bus SJC1000";
        case PciSubDevice001C0001::SUBDEVICE_001C0005: return "2 Channel CAN Bus SJC1000 (Optically Isolated)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR001C_PCISUBDEVICE001C0001_H
