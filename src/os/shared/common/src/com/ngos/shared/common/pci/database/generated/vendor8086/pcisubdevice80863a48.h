// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A48_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A48_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80863A48: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C330B = 0x103C330B,
    SUBDEVICE_104382EA = 0x104382EA,
    SUBDEVICE_14585001 = 0x14585001
};



inline const char8* enumToString(PciSubDevice80863A48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A48::NONE:               return "NONE";
        case PciSubDevice80863A48::SUBDEVICE_103C330B: return "SUBDEVICE_103C330B";
        case PciSubDevice80863A48::SUBDEVICE_104382EA: return "SUBDEVICE_104382EA";
        case PciSubDevice80863A48::SUBDEVICE_14585001: return "SUBDEVICE_14585001";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80863A48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80863A48 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80863A48::SUBDEVICE_103C330B: return "ProLiant ML150 G6 Server";
        case PciSubDevice80863A48::SUBDEVICE_104382EA: return "P6T Deluxe Motherboard";
        case PciSubDevice80863A48::SUBDEVICE_14585001: return "GA-EP45-DS5 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80863A48_H
