// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0005_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0005_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice111A0005: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_111A0001 = 0x111A0001,
    SUBDEVICE_111A0009 = 0x111A0009,
    SUBDEVICE_111A0101 = 0x111A0101,
    SUBDEVICE_111A0109 = 0x111A0109,
    SUBDEVICE_111A0809 = 0x111A0809,
    SUBDEVICE_111A0909 = 0x111A0909,
    SUBDEVICE_111A0A09 = 0x111A0A09
};



inline const char8* enumToString(PciSubDevice111A0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice111A0005::NONE:               return "NONE";
        case PciSubDevice111A0005::SUBDEVICE_111A0001: return "SUBDEVICE_111A0001";
        case PciSubDevice111A0005::SUBDEVICE_111A0009: return "SUBDEVICE_111A0009";
        case PciSubDevice111A0005::SUBDEVICE_111A0101: return "SUBDEVICE_111A0101";
        case PciSubDevice111A0005::SUBDEVICE_111A0109: return "SUBDEVICE_111A0109";
        case PciSubDevice111A0005::SUBDEVICE_111A0809: return "SUBDEVICE_111A0809";
        case PciSubDevice111A0005::SUBDEVICE_111A0909: return "SUBDEVICE_111A0909";
        case PciSubDevice111A0005::SUBDEVICE_111A0A09: return "SUBDEVICE_111A0A09";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice111A0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice111A0005 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice111A0005::SUBDEVICE_111A0001: return "ENI-3010 ATM";
        case PciSubDevice111A0005::SUBDEVICE_111A0009: return "ENI-3060 ADSL (VPI=0)";
        case PciSubDevice111A0005::SUBDEVICE_111A0101: return "ENI-3010 ATM";
        case PciSubDevice111A0005::SUBDEVICE_111A0109: return "ENI-3060CO ADSL (VPI=0)";
        case PciSubDevice111A0005::SUBDEVICE_111A0809: return "ENI-3060 ADSL (VPI=0 or 8)";
        case PciSubDevice111A0005::SUBDEVICE_111A0909: return "ENI-3060CO ADSL (VPI=0 or 8)";
        case PciSubDevice111A0005::SUBDEVICE_111A0A09: return "ENI-3060 ADSL (VPI=<0..15>)";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR111A_PCISUBDEVICE111A0005_H
