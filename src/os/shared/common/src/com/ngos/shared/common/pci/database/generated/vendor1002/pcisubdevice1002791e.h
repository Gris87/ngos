// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002791E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002791E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002791E: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14627327 = 0x14627327,
    SUBDEVICE_17F25000 = 0x17F25000
};



inline const char8* enumToString(PciSubDevice1002791E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002791E::NONE:               return "NONE";
        case PciSubDevice1002791E::SUBDEVICE_14627327: return "SUBDEVICE_14627327";
        case PciSubDevice1002791E::SUBDEVICE_17F25000: return "SUBDEVICE_17F25000";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002791E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002791E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002791E::SUBDEVICE_14627327: return "K9AG Neo2";
        case PciSubDevice1002791E::SUBDEVICE_17F25000: return "KI690-AM2 Motherboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002791E_H
