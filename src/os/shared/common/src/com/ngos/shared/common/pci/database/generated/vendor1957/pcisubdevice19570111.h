// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE19570111_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE19570111_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice19570111: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1C7F5200 = 0x1C7F5200
};



inline const char8* enumToString(PciSubDevice19570111 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19570111::NONE:               return "NONE";
        case PciSubDevice19570111::SUBDEVICE_1C7F5200: return "SUBDEVICE_1C7F5200";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice19570111 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice19570111 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice19570111::SUBDEVICE_1C7F5200: return "EB5200";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1957_PCISUBDEVICE19570111_H
