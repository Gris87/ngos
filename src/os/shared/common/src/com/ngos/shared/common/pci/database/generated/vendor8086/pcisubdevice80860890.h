// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860890_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860890_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice80860890: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80864022 = 0x80864022,
    SUBDEVICE_80864422 = 0x80864422,
    SUBDEVICE_80864822 = 0x80864822
};



inline const char8* enumToString(PciSubDevice80860890 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860890::NONE:               return "NONE";
        case PciSubDevice80860890::SUBDEVICE_80864022: return "SUBDEVICE_80864022";
        case PciSubDevice80860890::SUBDEVICE_80864422: return "SUBDEVICE_80864422";
        case PciSubDevice80860890::SUBDEVICE_80864822: return "SUBDEVICE_80864822";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice80860890 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice80860890 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice80860890::SUBDEVICE_80864022: return "Centrino Wireless-N 2200 BGN";
        case PciSubDevice80860890::SUBDEVICE_80864422: return "Centrino Wireless-N 2200 BGN";
        case PciSubDevice80860890::SUBDEVICE_80864822: return "Centrino Wireless-N 2200 BGN";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE80860890_H
