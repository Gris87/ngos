// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086423D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086423D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086423D: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80861211 = 0x80861211,
    SUBDEVICE_80861216 = 0x80861216,
    SUBDEVICE_80861311 = 0x80861311,
    SUBDEVICE_80861316 = 0x80861316
};



inline const char8* enumToString(PciSubDevice8086423D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086423D::NONE:               return "NONE";
        case PciSubDevice8086423D::SUBDEVICE_80861211: return "SUBDEVICE_80861211";
        case PciSubDevice8086423D::SUBDEVICE_80861216: return "SUBDEVICE_80861216";
        case PciSubDevice8086423D::SUBDEVICE_80861311: return "SUBDEVICE_80861311";
        case PciSubDevice8086423D::SUBDEVICE_80861316: return "SUBDEVICE_80861316";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086423D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086423D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086423D::SUBDEVICE_80861211: return "WiMAX/WiFi Link 5150 AGN";
        case PciSubDevice8086423D::SUBDEVICE_80861216: return "WiMAX/WiFi Link 5150 ABG";
        case PciSubDevice8086423D::SUBDEVICE_80861311: return "WiMAX/WiFi Link 5150 AGN";
        case PciSubDevice8086423D::SUBDEVICE_80861316: return "WiMAX/WiFi Link 5150 ABG";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086423D_H
