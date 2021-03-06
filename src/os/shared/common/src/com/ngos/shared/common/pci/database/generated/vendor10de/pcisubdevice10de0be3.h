// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0BE3_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0BE3_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice10DE0BE3: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_1028040B = 0x1028040B,
    SUBDEVICE_10DE066D = 0x10DE066D,
    SUBDEVICE_14628094 = 0x14628094
};



inline const char8* enumToString(PciSubDevice10DE0BE3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0BE3::NONE:               return "NONE";
        case PciSubDevice10DE0BE3::SUBDEVICE_1028040B: return "SUBDEVICE_1028040B";
        case PciSubDevice10DE0BE3::SUBDEVICE_10DE066D: return "SUBDEVICE_10DE066D";
        case PciSubDevice10DE0BE3::SUBDEVICE_14628094: return "SUBDEVICE_14628094";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice10DE0BE3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice10DE0BE3 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice10DE0BE3::SUBDEVICE_1028040B: return "Latitude E6510";
        case PciSubDevice10DE0BE3::SUBDEVICE_10DE066D: return "G98 [GeForce 8400GS]";
        case PciSubDevice10DE0BE3::SUBDEVICE_14628094: return "N210 [Geforce 210] PCIe graphics adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR10DE_PCISUBDEVICE10DE0BE3_H
