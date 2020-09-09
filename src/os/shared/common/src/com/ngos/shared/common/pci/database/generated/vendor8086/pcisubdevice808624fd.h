// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624FD_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624FD_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice808624FD: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_80860010 = 0x80860010,
    SUBDEVICE_80860150 = 0x80860150,
    SUBDEVICE_80861010 = 0x80861010,
    SUBDEVICE_80861130 = 0x80861130
};



inline const char8* enumToString(PciSubDevice808624FD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624FD::NONE:               return "NONE";
        case PciSubDevice808624FD::SUBDEVICE_80860010: return "SUBDEVICE_80860010";
        case PciSubDevice808624FD::SUBDEVICE_80860150: return "SUBDEVICE_80860150";
        case PciSubDevice808624FD::SUBDEVICE_80861010: return "SUBDEVICE_80861010";
        case PciSubDevice808624FD::SUBDEVICE_80861130: return "SUBDEVICE_80861130";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice808624FD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice808624FD subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice808624FD::SUBDEVICE_80860010: return "Dual Band Wireless-AC 8265";
        case PciSubDevice808624FD::SUBDEVICE_80860150: return "Dual Band Wireless-AC 8265";
        case PciSubDevice808624FD::SUBDEVICE_80861010: return "Dual Band Wireless-AC 8265";
        case PciSubDevice808624FD::SUBDEVICE_80861130: return "Dual Band Wireless-AC 8265";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE808624FD_H
