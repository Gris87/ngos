// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01D3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01D3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE01D3: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10438203 = 0x10438203,
    SUBDEVICE_10438250 = 0x10438250
};



inline const char8* enumToString(PciSubDevice10DE01D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE01D3::NONE:               return "NONE";
        case PciSubDevice10DE01D3::SUBDEVICE_10438203: return "SUBDEVICE_10438203";
        case PciSubDevice10DE01D3::SUBDEVICE_10438250: return "SUBDEVICE_10438250";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE01D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE01D3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE01D3::SUBDEVICE_10438203: return "EN7300SE";
        case PciSubDevice10DE01D3::SUBDEVICE_10438250: return "EN7200GS";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE01D3_H
