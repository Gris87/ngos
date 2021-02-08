// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803D_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803D_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice104C803D: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C309F = 0x103C309F,
    SUBDEVICE_103C30A1 = 0x103C30A1,
    SUBDEVICE_103C30A3 = 0x103C30A3,
    SUBDEVICE_103C30AA = 0x103C30AA
};



inline const char8* enumToString(PciSubDevice104C803D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C803D::NONE:               return "NONE";
        case PciSubDevice104C803D::SUBDEVICE_103C309F: return "SUBDEVICE_103C309F";
        case PciSubDevice104C803D::SUBDEVICE_103C30A1: return "SUBDEVICE_103C30A1";
        case PciSubDevice104C803D::SUBDEVICE_103C30A3: return "SUBDEVICE_103C30A3";
        case PciSubDevice104C803D::SUBDEVICE_103C30AA: return "SUBDEVICE_103C30AA";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice104C803D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice104C803D subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice104C803D::SUBDEVICE_103C309F: return "Compaq nx9420 Notebook";
        case PciSubDevice104C803D::SUBDEVICE_103C30A1: return "NC2400";
        case PciSubDevice104C803D::SUBDEVICE_103C30A3: return "nc8430";
        case PciSubDevice104C803D::SUBDEVICE_103C30AA: return "nc6310";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR104C_PCISUBDEVICE104C803D_H
