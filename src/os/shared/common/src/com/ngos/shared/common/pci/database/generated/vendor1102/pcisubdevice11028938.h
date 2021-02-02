// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11028938_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11028938_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11028938: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103380E5 = 0x103380E5,
    SUBDEVICE_10717150 = 0x10717150,
    SUBDEVICE_110A5938 = 0x110A5938,
    SUBDEVICE_13BD100C = 0x13BD100C,
    SUBDEVICE_13BD100D = 0x13BD100D,
    SUBDEVICE_13BD100E = 0x13BD100E,
    SUBDEVICE_13BDF6F1 = 0x13BDF6F1,
    SUBDEVICE_14FF0E70 = 0x14FF0E70,
    SUBDEVICE_14FFC401 = 0x14FFC401,
    SUBDEVICE_156DB400 = 0x156DB400,
    SUBDEVICE_156DB550 = 0x156DB550,
    SUBDEVICE_156DB560 = 0x156DB560,
    SUBDEVICE_156DB700 = 0x156DB700,
    SUBDEVICE_156DB795 = 0x156DB795,
    SUBDEVICE_156DB797 = 0x156DB797
};



inline const char8* enumToString(PciSubDevice11028938 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11028938::NONE:               return "NONE";
        case PciSubDevice11028938::SUBDEVICE_103380E5: return "SUBDEVICE_103380E5";
        case PciSubDevice11028938::SUBDEVICE_10717150: return "SUBDEVICE_10717150";
        case PciSubDevice11028938::SUBDEVICE_110A5938: return "SUBDEVICE_110A5938";
        case PciSubDevice11028938::SUBDEVICE_13BD100C: return "SUBDEVICE_13BD100C";
        case PciSubDevice11028938::SUBDEVICE_13BD100D: return "SUBDEVICE_13BD100D";
        case PciSubDevice11028938::SUBDEVICE_13BD100E: return "SUBDEVICE_13BD100E";
        case PciSubDevice11028938::SUBDEVICE_13BDF6F1: return "SUBDEVICE_13BDF6F1";
        case PciSubDevice11028938::SUBDEVICE_14FF0E70: return "SUBDEVICE_14FF0E70";
        case PciSubDevice11028938::SUBDEVICE_14FFC401: return "SUBDEVICE_14FFC401";
        case PciSubDevice11028938::SUBDEVICE_156DB400: return "SUBDEVICE_156DB400";
        case PciSubDevice11028938::SUBDEVICE_156DB550: return "SUBDEVICE_156DB550";
        case PciSubDevice11028938::SUBDEVICE_156DB560: return "SUBDEVICE_156DB560";
        case PciSubDevice11028938::SUBDEVICE_156DB700: return "SUBDEVICE_156DB700";
        case PciSubDevice11028938::SUBDEVICE_156DB795: return "SUBDEVICE_156DB795";
        case PciSubDevice11028938::SUBDEVICE_156DB797: return "SUBDEVICE_156DB797";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11028938 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11028938 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11028938::SUBDEVICE_103380E5: return "SlimTower-Jim (NEC)";
        case PciSubDevice11028938::SUBDEVICE_10717150: return "Mitac 7150";
        case PciSubDevice11028938::SUBDEVICE_110A5938: return "Siemens Scenic Mobile 510PIII";
        case PciSubDevice11028938::SUBDEVICE_13BD100C: return "Ceres-C (Sharp, Intel BX)";
        case PciSubDevice11028938::SUBDEVICE_13BD100D: return "Sharp, Intel Banister";
        case PciSubDevice11028938::SUBDEVICE_13BD100E: return "TwinHead P09S/P09S3 (Sharp)";
        case PciSubDevice11028938::SUBDEVICE_13BDF6F1: return "Marlin (Sharp)";
        case PciSubDevice11028938::SUBDEVICE_14FF0E70: return "P88TE (TWINHEAD INTERNATIONAL Corp)";
        case PciSubDevice11028938::SUBDEVICE_14FFC401: return "Notebook 9100/9200/2000 (TWINHEAD INTERNATIONAL Corp)";
        case PciSubDevice11028938::SUBDEVICE_156DB400: return "G400 - Geo (AlphaTop (Taiwan))";
        case PciSubDevice11028938::SUBDEVICE_156DB550: return "G560 (AlphaTop (Taiwan))";
        case PciSubDevice11028938::SUBDEVICE_156DB560: return "G560 (AlphaTop (Taiwan))";
        case PciSubDevice11028938::SUBDEVICE_156DB700: return "G700/U700 (AlphaTop (Taiwan))";
        case PciSubDevice11028938::SUBDEVICE_156DB795: return "G795 (AlphaTop (Taiwan))";
        case PciSubDevice11028938::SUBDEVICE_156DB797: return "G797 (AlphaTop (Taiwan))";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1102_PCISUBDEVICE11028938_H
