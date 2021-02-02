// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024380_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024380_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10024380: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C2813 = 0x103C2813,
    SUBDEVICE_1179FF50 = 0x1179FF50,
    SUBDEVICE_1458B003 = 0x1458B003,
    SUBDEVICE_1458B005 = 0x1458B005,
    SUBDEVICE_14627327 = 0x14627327,
    SUBDEVICE_17F25999 = 0x17F25999
};



inline const char8* enumToString(PciSubDevice10024380 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024380::NONE:               return "NONE";
        case PciSubDevice10024380::SUBDEVICE_103C2813: return "SUBDEVICE_103C2813";
        case PciSubDevice10024380::SUBDEVICE_1179FF50: return "SUBDEVICE_1179FF50";
        case PciSubDevice10024380::SUBDEVICE_1458B003: return "SUBDEVICE_1458B003";
        case PciSubDevice10024380::SUBDEVICE_1458B005: return "SUBDEVICE_1458B005";
        case PciSubDevice10024380::SUBDEVICE_14627327: return "SUBDEVICE_14627327";
        case PciSubDevice10024380::SUBDEVICE_17F25999: return "SUBDEVICE_17F25999";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10024380 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10024380 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10024380::SUBDEVICE_103C2813: return "DC5750 Microtower";
        case PciSubDevice10024380::SUBDEVICE_1179FF50: return "Satellite P305D-S8995E";
        case PciSubDevice10024380::SUBDEVICE_1458B003: return "GA-MA790FX-DS5 (rev. 1.0)";
        case PciSubDevice10024380::SUBDEVICE_1458B005: return "Gigabyte GA-MA69G-S3H Motherboard";
        case PciSubDevice10024380::SUBDEVICE_14627327: return "K9AG Neo2";
        case PciSubDevice10024380::SUBDEVICE_17F25999: return "KI690-AM2 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10024380_H
