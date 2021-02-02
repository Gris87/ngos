// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140101_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140101_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice18140101: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10430127 = 0x10430127,
    SUBDEVICE_13710010 = 0x13710010,
    SUBDEVICE_14626828 = 0x14626828
};



inline const char8* enumToString(PciSubDevice18140101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140101::NONE:               return "NONE";
        case PciSubDevice18140101::SUBDEVICE_10430127: return "SUBDEVICE_10430127";
        case PciSubDevice18140101::SUBDEVICE_13710010: return "SUBDEVICE_13710010";
        case PciSubDevice18140101::SUBDEVICE_14626828: return "SUBDEVICE_14626828";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice18140101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice18140101 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice18140101::SUBDEVICE_10430127: return "WiFi-b add-on Card";
        case PciSubDevice18140101::SUBDEVICE_13710010: return "Minitar MNW2BPCI Wireless PCI Card";
        case PciSubDevice18140101::SUBDEVICE_14626828: return "PC11B2 (MS-6828) Wireless 11b PCI Card";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1814_PCISUBDEVICE18140101_H
