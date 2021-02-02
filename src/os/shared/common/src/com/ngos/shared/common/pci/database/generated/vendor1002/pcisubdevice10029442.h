// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029442_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029442_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029442: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10020502 = 0x10020502,
    SUBDEVICE_174BE810 = 0x174BE810
};



inline const char8* enumToString(PciSubDevice10029442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029442::NONE:               return "NONE";
        case PciSubDevice10029442::SUBDEVICE_10020502: return "SUBDEVICE_10020502";
        case PciSubDevice10029442::SUBDEVICE_174BE810: return "SUBDEVICE_174BE810";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029442 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029442::SUBDEVICE_10020502: return "MSI Radeon HD 4850 512MB GDDR3";
        case PciSubDevice10029442::SUBDEVICE_174BE810: return "Radeon HD 4850 512MB GDDR3";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029442_H
