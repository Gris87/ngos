// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862580_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862580_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80862580: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14582580 = 0x14582580,
    SUBDEVICE_14627028 = 0x14627028,
    SUBDEVICE_1734105B = 0x1734105B
};



inline const char8* enumToString(PciSubDevice80862580 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862580::NONE:               return "NONE";
        case PciSubDevice80862580::SUBDEVICE_14582580: return "SUBDEVICE_14582580";
        case PciSubDevice80862580::SUBDEVICE_14627028: return "SUBDEVICE_14627028";
        case PciSubDevice80862580::SUBDEVICE_1734105B: return "SUBDEVICE_1734105B";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80862580 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80862580 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80862580::SUBDEVICE_14582580: return "GA-8I915ME-G Mainboard";
        case PciSubDevice80862580::SUBDEVICE_14627028: return "915P/G Neo2";
        case PciSubDevice80862580::SUBDEVICE_1734105B: return "Scenic W620";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80862580_H
