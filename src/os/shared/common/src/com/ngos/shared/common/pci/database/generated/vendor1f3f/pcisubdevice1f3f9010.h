// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9010_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9010_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1F3F9010: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1F3F0041 = 0x1F3F0041,
    SUBDEVICE_1F3F0061 = 0x1F3F0061
};



inline const char8* enumToString(PciSubDevice1F3F9010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F9010::NONE:               return "NONE";
        case PciSubDevice1F3F9010::SUBDEVICE_1F3F0041: return "SUBDEVICE_1F3F0041";
        case PciSubDevice1F3F9010::SUBDEVICE_1F3F0061: return "SUBDEVICE_1F3F0061";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1F3F9010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1F3F9010 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1F3F9010::SUBDEVICE_1F3F0041: return "Dual Port 16GE FC to PCIe Gen4 x16 Adapter";
        case PciSubDevice1F3F9010::SUBDEVICE_1F3F0061: return "Dual Port 32GE FC to PCIe Gen4 x16 Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1F3F_PCISUBDEVICE1F3F9010_H
