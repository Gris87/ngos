// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338C12_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338C12_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice53338C12: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014017F = 0x1014017F,
    SUBDEVICE_11790001 = 0x11790001
};



inline const char8* enumToString(PciSubDevice53338C12 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338C12::NONE:               return "NONE";
        case PciSubDevice53338C12::SUBDEVICE_1014017F: return "SUBDEVICE_1014017F";
        case PciSubDevice53338C12::SUBDEVICE_11790001: return "SUBDEVICE_11790001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice53338C12 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice53338C12 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice53338C12::SUBDEVICE_1014017F: return "ThinkPad T20/T22";
        case PciSubDevice53338C12::SUBDEVICE_11790001: return "86C584 SuperSavage/IXC Toshiba";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR5333_PCISUBDEVICE53338C12_H
