// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12F00_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12F00_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14F12F00: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_13E08D84 = 0x13E08D84,
    SUBDEVICE_13E08D85 = 0x13E08D85,
    SUBDEVICE_14F12004 = 0x14F12004
};



inline const char8* enumToString(PciSubDevice14F12F00 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F12F00::NONE:               return "NONE";
        case PciSubDevice14F12F00::SUBDEVICE_13E08D84: return "SUBDEVICE_13E08D84";
        case PciSubDevice14F12F00::SUBDEVICE_13E08D85: return "SUBDEVICE_13E08D85";
        case PciSubDevice14F12F00::SUBDEVICE_14F12004: return "SUBDEVICE_14F12004";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14F12F00 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14F12F00 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14F12F00::SUBDEVICE_13E08D84: return "IBM HSFi V.90";
        case PciSubDevice14F12F00::SUBDEVICE_13E08D85: return "Compaq Stinger";
        case PciSubDevice14F12F00::SUBDEVICE_14F12004: return "Dynalink 56PMi";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14F1_PCISUBDEVICE14F12F00_H
