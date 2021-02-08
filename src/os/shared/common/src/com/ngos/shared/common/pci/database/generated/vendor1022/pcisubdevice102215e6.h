// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE102215E6_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE102215E6_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice102215E6: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_102215E4 = 0x102215E4
};



inline const char8* enumToString(PciSubDevice102215E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102215E6::NONE:               return "NONE";
        case PciSubDevice102215E6::SUBDEVICE_102215E4: return "SUBDEVICE_102215E4";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice102215E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice102215E6 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice102215E6::SUBDEVICE_102215E4: return "Raven/Raven2/Renoir Sensor Fusion Hub";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1022_PCISUBDEVICE102215E6_H
