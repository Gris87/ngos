// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCISUBDEVICE11131216_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCISUBDEVICE11131216_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11131216: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_11131216 = 0x11131216,
    SUBDEVICE_11132220 = 0x11132220,
    SUBDEVICE_11132242 = 0x11132242,
    SUBDEVICE_111A1020 = 0x111A1020
};



inline const char8* enumToString(PciSubDevice11131216 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11131216::NONE:               return "NONE";
        case PciSubDevice11131216::SUBDEVICE_11131216: return "SUBDEVICE_11131216";
        case PciSubDevice11131216::SUBDEVICE_11132220: return "SUBDEVICE_11132220";
        case PciSubDevice11131216::SUBDEVICE_11132242: return "SUBDEVICE_11132242";
        case PciSubDevice11131216::SUBDEVICE_111A1020: return "SUBDEVICE_111A1020";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11131216 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11131216 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11131216::SUBDEVICE_11131216: return "EN1207F series PCI Fast Ethernet Adapter";
        case PciSubDevice11131216::SUBDEVICE_11132220: return "EN2220A Cardbus Fast Ethernet Adapter";
        case PciSubDevice11131216::SUBDEVICE_11132242: return "EN2242 10/100 Ethernet Mini-PCI Card";
        case PciSubDevice11131216::SUBDEVICE_111A1020: return "SpeedStream 1020 PCI 10/100 Ethernet Adaptor [EN-1207F-TX ?]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1113_PCISUBDEVICE11131216_H
