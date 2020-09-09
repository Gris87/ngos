// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086423C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086423C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086423C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861201 = 0x80861201,
    SUBDEVICE_80861206 = 0x80861206,
    SUBDEVICE_80861221 = 0x80861221,
    SUBDEVICE_80861301 = 0x80861301,
    SUBDEVICE_80861306 = 0x80861306,
    SUBDEVICE_80861321 = 0x80861321
};



inline const char8* enumToString(PciSubDevice8086423C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086423C::NONE:               return "NONE";
        case PciSubDevice8086423C::SUBDEVICE_80861201: return "SUBDEVICE_80861201";
        case PciSubDevice8086423C::SUBDEVICE_80861206: return "SUBDEVICE_80861206";
        case PciSubDevice8086423C::SUBDEVICE_80861221: return "SUBDEVICE_80861221";
        case PciSubDevice8086423C::SUBDEVICE_80861301: return "SUBDEVICE_80861301";
        case PciSubDevice8086423C::SUBDEVICE_80861306: return "SUBDEVICE_80861306";
        case PciSubDevice8086423C::SUBDEVICE_80861321: return "SUBDEVICE_80861321";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086423C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086423C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086423C::SUBDEVICE_80861201: return "WiMAX/WiFi Link 5150 AGN";
        case PciSubDevice8086423C::SUBDEVICE_80861206: return "WiMAX/WiFi Link 5150 ABG";
        case PciSubDevice8086423C::SUBDEVICE_80861221: return "WiMAX/WiFi Link 5150 AGN";
        case PciSubDevice8086423C::SUBDEVICE_80861301: return "WiMAX/WiFi Link 5150 AGN";
        case PciSubDevice8086423C::SUBDEVICE_80861306: return "WiMAX/WiFi Link 5150 ABG";
        case PciSubDevice8086423C::SUBDEVICE_80861321: return "WiMAX/WiFi Link 5150 AGN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086423C_H
