// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4321_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4321_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice127A4321: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_12354321 = 0x12354321,
    SUBDEVICE_12354324 = 0x12354324,
    SUBDEVICE_13E00210 = 0x13E00210,
    SUBDEVICE_144D2321 = 0x144D2321
};



inline const char8* enumToString(PciSubDevice127A4321 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A4321::NONE:               return "NONE";
        case PciSubDevice127A4321::SUBDEVICE_12354321: return "SUBDEVICE_12354321";
        case PciSubDevice127A4321::SUBDEVICE_12354324: return "SUBDEVICE_12354324";
        case PciSubDevice127A4321::SUBDEVICE_13E00210: return "SUBDEVICE_13E00210";
        case PciSubDevice127A4321::SUBDEVICE_144D2321: return "SUBDEVICE_144D2321";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice127A4321 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice127A4321 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice127A4321::SUBDEVICE_12354321: return "Hewlett Packard DF";
        case PciSubDevice127A4321::SUBDEVICE_12354324: return "Hewlett Packard DF";
        case PciSubDevice127A4321::SUBDEVICE_13E00210: return "Hewlett Packard DF";
        case PciSubDevice127A4321::SUBDEVICE_144D2321: return "Riptide";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR127A_PCISUBDEVICE127A4321_H
