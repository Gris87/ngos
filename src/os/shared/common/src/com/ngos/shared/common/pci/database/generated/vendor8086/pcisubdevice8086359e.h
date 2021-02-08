// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086359E_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086359E_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice8086359E: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280168 = 0x10280168,
    SUBDEVICE_10280169 = 0x10280169
};



inline const char8* enumToString(PciSubDevice8086359E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086359E::NONE:               return "NONE";
        case PciSubDevice8086359E::SUBDEVICE_10280168: return "SUBDEVICE_10280168";
        case PciSubDevice8086359E::SUBDEVICE_10280169: return "SUBDEVICE_10280169";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice8086359E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice8086359E subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice8086359E::SUBDEVICE_10280168: return "Precision Workstation 670 Mainboard";
        case PciSubDevice8086359E::SUBDEVICE_10280169: return "Precision 470";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR8086_PCISUBDEVICE8086359E_H
