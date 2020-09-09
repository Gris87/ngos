// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860083_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860083_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860083: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861205 = 0x80861205,
    SUBDEVICE_80861206 = 0x80861206,
    SUBDEVICE_80861225 = 0x80861225,
    SUBDEVICE_80861226 = 0x80861226,
    SUBDEVICE_80861305 = 0x80861305,
    SUBDEVICE_80861306 = 0x80861306,
    SUBDEVICE_80861325 = 0x80861325,
    SUBDEVICE_80861326 = 0x80861326
};



inline const char8* enumToString(PciSubDevice80860083 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860083::NONE:               return "NONE";
        case PciSubDevice80860083::SUBDEVICE_80861205: return "SUBDEVICE_80861205";
        case PciSubDevice80860083::SUBDEVICE_80861206: return "SUBDEVICE_80861206";
        case PciSubDevice80860083::SUBDEVICE_80861225: return "SUBDEVICE_80861225";
        case PciSubDevice80860083::SUBDEVICE_80861226: return "SUBDEVICE_80861226";
        case PciSubDevice80860083::SUBDEVICE_80861305: return "SUBDEVICE_80861305";
        case PciSubDevice80860083::SUBDEVICE_80861306: return "SUBDEVICE_80861306";
        case PciSubDevice80860083::SUBDEVICE_80861325: return "SUBDEVICE_80861325";
        case PciSubDevice80860083::SUBDEVICE_80861326: return "SUBDEVICE_80861326";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860083 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860083 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860083::SUBDEVICE_80861205: return "Centrino Wireless-N 1000 BGN";
        case PciSubDevice80860083::SUBDEVICE_80861206: return "Centrino Wireless-N 1000 BG";
        case PciSubDevice80860083::SUBDEVICE_80861225: return "Centrino Wireless-N 1000 BGN";
        case PciSubDevice80860083::SUBDEVICE_80861226: return "Centrino Wireless-N 1000 BG";
        case PciSubDevice80860083::SUBDEVICE_80861305: return "Centrino Wireless-N 1000 BGN";
        case PciSubDevice80860083::SUBDEVICE_80861306: return "Centrino Wireless-N 1000 BG";
        case PciSubDevice80860083::SUBDEVICE_80861325: return "Centrino Wireless-N 1000 BGN";
        case PciSubDevice80860083::SUBDEVICE_80861326: return "Centrino Wireless-N 1000 BG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860083_H
