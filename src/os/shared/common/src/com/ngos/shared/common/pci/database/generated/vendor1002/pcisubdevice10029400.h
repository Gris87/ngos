// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029400_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029400_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10029400: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10022552 = 0x10022552,
    SUBDEVICE_10023000 = 0x10023000,
    SUBDEVICE_10023142 = 0x10023142
};



inline const char8* enumToString(PciSubDevice10029400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029400::NONE:               return "NONE";
        case PciSubDevice10029400::SUBDEVICE_10022552: return "SUBDEVICE_10022552";
        case PciSubDevice10029400::SUBDEVICE_10023000: return "SUBDEVICE_10023000";
        case PciSubDevice10029400::SUBDEVICE_10023142: return "SUBDEVICE_10023142";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10029400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10029400 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10029400::SUBDEVICE_10022552: return "Radeon HD 2900 XT";
        case PciSubDevice10029400::SUBDEVICE_10023000: return "Radeon HD 2900 PRO";
        case PciSubDevice10029400::SUBDEVICE_10023142: return "HIS Radeon HD 2900XT 512MB GDDR3 VIVO PCIe";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1002_PCISUBDEVICE10029400_H
