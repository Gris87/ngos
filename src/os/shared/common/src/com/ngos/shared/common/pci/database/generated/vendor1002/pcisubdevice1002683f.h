// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002683F_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002683F_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1002683F: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_14622790 = 0x14622790,
    SUBDEVICE_14622791 = 0x14622791,
    SUBDEVICE_16423B97 = 0x16423B97
};



inline const char8* enumToString(PciSubDevice1002683F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002683F::NONE:               return "NONE";
        case PciSubDevice1002683F::SUBDEVICE_14622790: return "SUBDEVICE_14622790";
        case PciSubDevice1002683F::SUBDEVICE_14622791: return "SUBDEVICE_14622791";
        case PciSubDevice1002683F::SUBDEVICE_16423B97: return "SUBDEVICE_16423B97";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1002683F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1002683F subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1002683F::SUBDEVICE_14622790: return "Radeon HD 8740";
        case PciSubDevice1002683F::SUBDEVICE_14622791: return "Radeon HD 8740";
        case PciSubDevice1002683F::SUBDEVICE_16423B97: return "Radeon HD 8740";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE1002683F_H
