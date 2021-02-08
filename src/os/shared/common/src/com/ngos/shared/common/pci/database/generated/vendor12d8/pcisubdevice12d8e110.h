// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCISUBDEVICE12D8E110_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCISUBDEVICE12D8E110_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12D8E110: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_177511CC = 0x177511CC
};



inline const char8* enumToString(PciSubDevice12D8E110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12D8E110::NONE:               return "NONE";
        case PciSubDevice12D8E110::SUBDEVICE_177511CC: return "SUBDEVICE_177511CC";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12D8E110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12D8E110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12D8E110::SUBDEVICE_177511CC: return "CC11/CL11 CompactPCI Bridge";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR12D8_PCISUBDEVICE12D8E110_H
