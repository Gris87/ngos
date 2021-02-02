// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002665F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002665F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002665F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280B04 = 0x10280B04,
    SUBDEVICE_14622938 = 0x14622938,
    SUBDEVICE_14623271 = 0x14623271,
    SUBDEVICE_16827360 = 0x16827360
};



inline const char8* enumToString(PciSubDevice1002665F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002665F::NONE:               return "NONE";
        case PciSubDevice1002665F::SUBDEVICE_10280B04: return "SUBDEVICE_10280B04";
        case PciSubDevice1002665F::SUBDEVICE_14622938: return "SUBDEVICE_14622938";
        case PciSubDevice1002665F::SUBDEVICE_14623271: return "SUBDEVICE_14623271";
        case PciSubDevice1002665F::SUBDEVICE_16827360: return "SUBDEVICE_16827360";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002665F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002665F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002665F::SUBDEVICE_10280B04: return "Radeon R9 360 OEM";
        case PciSubDevice1002665F::SUBDEVICE_14622938: return "Radeon R9 360 OEM";
        case PciSubDevice1002665F::SUBDEVICE_14623271: return "Radeon R9 360 OEM";
        case PciSubDevice1002665F::SUBDEVICE_16827360: return "Radeon R7 360";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002665F_H
