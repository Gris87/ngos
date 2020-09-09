// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864232_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864232_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80864232: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861201 = 0x80861201,
    SUBDEVICE_80861204 = 0x80861204,
    SUBDEVICE_80861205 = 0x80861205,
    SUBDEVICE_80861206 = 0x80861206,
    SUBDEVICE_80861221 = 0x80861221,
    SUBDEVICE_80861224 = 0x80861224,
    SUBDEVICE_80861225 = 0x80861225,
    SUBDEVICE_80861226 = 0x80861226,
    SUBDEVICE_80861301 = 0x80861301,
    SUBDEVICE_80861304 = 0x80861304,
    SUBDEVICE_80861305 = 0x80861305,
    SUBDEVICE_80861306 = 0x80861306,
    SUBDEVICE_80861321 = 0x80861321,
    SUBDEVICE_80861324 = 0x80861324,
    SUBDEVICE_80861325 = 0x80861325,
    SUBDEVICE_80861326 = 0x80861326
};



inline const char8* enumToString(PciSubDevice80864232 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864232::NONE:               return "NONE";
        case PciSubDevice80864232::SUBDEVICE_80861201: return "SUBDEVICE_80861201";
        case PciSubDevice80864232::SUBDEVICE_80861204: return "SUBDEVICE_80861204";
        case PciSubDevice80864232::SUBDEVICE_80861205: return "SUBDEVICE_80861205";
        case PciSubDevice80864232::SUBDEVICE_80861206: return "SUBDEVICE_80861206";
        case PciSubDevice80864232::SUBDEVICE_80861221: return "SUBDEVICE_80861221";
        case PciSubDevice80864232::SUBDEVICE_80861224: return "SUBDEVICE_80861224";
        case PciSubDevice80864232::SUBDEVICE_80861225: return "SUBDEVICE_80861225";
        case PciSubDevice80864232::SUBDEVICE_80861226: return "SUBDEVICE_80861226";
        case PciSubDevice80864232::SUBDEVICE_80861301: return "SUBDEVICE_80861301";
        case PciSubDevice80864232::SUBDEVICE_80861304: return "SUBDEVICE_80861304";
        case PciSubDevice80864232::SUBDEVICE_80861305: return "SUBDEVICE_80861305";
        case PciSubDevice80864232::SUBDEVICE_80861306: return "SUBDEVICE_80861306";
        case PciSubDevice80864232::SUBDEVICE_80861321: return "SUBDEVICE_80861321";
        case PciSubDevice80864232::SUBDEVICE_80861324: return "SUBDEVICE_80861324";
        case PciSubDevice80864232::SUBDEVICE_80861325: return "SUBDEVICE_80861325";
        case PciSubDevice80864232::SUBDEVICE_80861326: return "SUBDEVICE_80861326";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80864232 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80864232 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80864232::SUBDEVICE_80861201: return "WiFi Link 5100 AGN";
        case PciSubDevice80864232::SUBDEVICE_80861204: return "WiFi Link 5100 AGN";
        case PciSubDevice80864232::SUBDEVICE_80861205: return "WiFi Link 5100 BGN";
        case PciSubDevice80864232::SUBDEVICE_80861206: return "WiFi Link 5100 ABG";
        case PciSubDevice80864232::SUBDEVICE_80861221: return "WiFi Link 5100 AGN";
        case PciSubDevice80864232::SUBDEVICE_80861224: return "WiFi Link 5100 AGN";
        case PciSubDevice80864232::SUBDEVICE_80861225: return "WiFi Link 5100 BGN";
        case PciSubDevice80864232::SUBDEVICE_80861226: return "WiFi Link 5100 ABG";
        case PciSubDevice80864232::SUBDEVICE_80861301: return "WiFi Link 5100 AGN";
        case PciSubDevice80864232::SUBDEVICE_80861304: return "WiFi Link 5100 AGN";
        case PciSubDevice80864232::SUBDEVICE_80861305: return "WiFi Link 5100 BGN";
        case PciSubDevice80864232::SUBDEVICE_80861306: return "WiFi Link 5100 ABG";
        case PciSubDevice80864232::SUBDEVICE_80861321: return "WiFi Link 5100 AGN";
        case PciSubDevice80864232::SUBDEVICE_80861324: return "WiFi Link 5100 AGN";
        case PciSubDevice80864232::SUBDEVICE_80861325: return "WiFi Link 5100 BGN";
        case PciSubDevice80864232::SUBDEVICE_80861326: return "WiFi Link 5100 ABG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80864232_H
