// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C57_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C57_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024C57: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10140517 = 0x10140517,
    SUBDEVICE_10140530 = 0x10140530,
    SUBDEVICE_102800E6 = 0x102800E6,
    SUBDEVICE_1028012A = 0x1028012A,
    SUBDEVICE_10431622 = 0x10431622,
    SUBDEVICE_144DC006 = 0x144DC006
};



inline const char8* enumToString(PciSubDevice10024C57 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C57::NONE:               return "NONE";
        case PciSubDevice10024C57::SUBDEVICE_10140517: return "SUBDEVICE_10140517";
        case PciSubDevice10024C57::SUBDEVICE_10140530: return "SUBDEVICE_10140530";
        case PciSubDevice10024C57::SUBDEVICE_102800E6: return "SUBDEVICE_102800E6";
        case PciSubDevice10024C57::SUBDEVICE_1028012A: return "SUBDEVICE_1028012A";
        case PciSubDevice10024C57::SUBDEVICE_10431622: return "SUBDEVICE_10431622";
        case PciSubDevice10024C57::SUBDEVICE_144DC006: return "SUBDEVICE_144DC006";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024C57 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024C57 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024C57::SUBDEVICE_10140517: return "ThinkPad T30";
        case PciSubDevice10024C57::SUBDEVICE_10140530: return "ThinkPad T4x Series";
        case PciSubDevice10024C57::SUBDEVICE_102800E6: return "Radeon Mobility M7 LW (Dell Inspiron 8100)";
        case PciSubDevice10024C57::SUBDEVICE_1028012A: return "Latitude C640";
        case PciSubDevice10024C57::SUBDEVICE_10431622: return "Mobility Radeon M7 (L3C/S)";
        case PciSubDevice10024C57::SUBDEVICE_144DC006: return "Radeon Mobility M7 LW in vpr Matrix 170B4";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024C57_H
