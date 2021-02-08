// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860885_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860885_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860885: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861305 = 0x80861305,
    SUBDEVICE_80861307 = 0x80861307,
    SUBDEVICE_80861325 = 0x80861325,
    SUBDEVICE_80861327 = 0x80861327
};



inline const char8* enumToString(PciSubDevice80860885 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860885::NONE:               return "NONE";
        case PciSubDevice80860885::SUBDEVICE_80861305: return "SUBDEVICE_80861305";
        case PciSubDevice80860885::SUBDEVICE_80861307: return "SUBDEVICE_80861307";
        case PciSubDevice80860885::SUBDEVICE_80861325: return "SUBDEVICE_80861325";
        case PciSubDevice80860885::SUBDEVICE_80861327: return "SUBDEVICE_80861327";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860885 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860885 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860885::SUBDEVICE_80861305: return "Centrino Wireless-N + WiMAX 6150 BGN";
        case PciSubDevice80860885::SUBDEVICE_80861307: return "Centrino Wireless-N + WiMAX 6150 BG";
        case PciSubDevice80860885::SUBDEVICE_80861325: return "Centrino Wireless-N + WiMAX 6150 BGN";
        case PciSubDevice80860885::SUBDEVICE_80861327: return "Centrino Wireless-N + WiMAX 6150 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860885_H
