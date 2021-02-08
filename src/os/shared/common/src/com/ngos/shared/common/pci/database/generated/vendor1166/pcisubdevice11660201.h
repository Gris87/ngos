// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660201_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660201_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11660201: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_4C531080 = 0x4C531080
};



inline const char8* enumToString(PciSubDevice11660201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11660201::NONE:               return "NONE";
        case PciSubDevice11660201::SUBDEVICE_4C531080: return "SUBDEVICE_4C531080";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11660201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11660201 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11660201::SUBDEVICE_4C531080: return "CT8 mainboard";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1166_PCISUBDEVICE11660201_H
