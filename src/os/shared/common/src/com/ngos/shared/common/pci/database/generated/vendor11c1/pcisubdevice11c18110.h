// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C18110_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C18110_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11C18110: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12D9000C = 0x12D9000C
};



inline const char8* enumToString(PciSubDevice11C18110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C18110::NONE:               return "NONE";
        case PciSubDevice11C18110::SUBDEVICE_12D9000C: return "SUBDEVICE_12D9000C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11C18110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11C18110 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11C18110::SUBDEVICE_12D9000C: return "E1/T1 PMXc cPCI carrier card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR11C1_PCISUBDEVICE11C18110_H
