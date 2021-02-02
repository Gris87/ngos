// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12176972_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12176972_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice12176972: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1014020C = 0x1014020C,
    SUBDEVICE_10280152 = 0x10280152,
    SUBDEVICE_11790001 = 0x11790001
};



inline const char8* enumToString(PciSubDevice12176972 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12176972::NONE:               return "NONE";
        case PciSubDevice12176972::SUBDEVICE_1014020C: return "SUBDEVICE_1014020C";
        case PciSubDevice12176972::SUBDEVICE_10280152: return "SUBDEVICE_10280152";
        case PciSubDevice12176972::SUBDEVICE_11790001: return "SUBDEVICE_11790001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice12176972 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice12176972 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice12176972::SUBDEVICE_1014020C: return "ThinkPad R30";
        case PciSubDevice12176972::SUBDEVICE_10280152: return "Latitude D500";
        case PciSubDevice12176972::SUBDEVICE_11790001: return "Magnia Z310";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1217_PCISUBDEVICE12176972_H
