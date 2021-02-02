// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063164_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063164_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11063164: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_104380F4 = 0x104380F4,
    SUBDEVICE_14627028 = 0x14627028
};



inline const char8* enumToString(PciSubDevice11063164 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063164::NONE:               return "NONE";
        case PciSubDevice11063164::SUBDEVICE_104380F4: return "SUBDEVICE_104380F4";
        case PciSubDevice11063164::SUBDEVICE_14627028: return "SUBDEVICE_14627028";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11063164 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11063164 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11063164::SUBDEVICE_104380F4: return "P4P800 Mainboard Deluxe ATX";
        case PciSubDevice11063164::SUBDEVICE_14627028: return "915P/G Neo2";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1106_PCISUBDEVICE11063164_H
