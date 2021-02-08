// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660234_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660234_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11660234: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280205 = 0x10280205,
    SUBDEVICE_1028020B = 0x1028020B
};



inline const char8* enumToString(PciSubDevice11660234 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11660234::NONE:               return "NONE";
        case PciSubDevice11660234::SUBDEVICE_10280205: return "SUBDEVICE_10280205";
        case PciSubDevice11660234::SUBDEVICE_1028020B: return "SUBDEVICE_1028020B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11660234 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11660234 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11660234::SUBDEVICE_10280205: return "PowerEdge 2970 HT1000 LPC";
        case PciSubDevice11660234::SUBDEVICE_1028020B: return "PowerEdge T605 HT1000 LPC";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660234_H
