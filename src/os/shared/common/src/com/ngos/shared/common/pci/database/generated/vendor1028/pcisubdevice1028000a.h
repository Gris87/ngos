// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE1028000A_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE1028000A_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice1028000A: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280106 = 0x10280106,
    SUBDEVICE_1028011B = 0x1028011B,
    SUBDEVICE_10280121 = 0x10280121
};



inline const char8* enumToString(PciSubDevice1028000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1028000A::NONE:               return "NONE";
        case PciSubDevice1028000A::SUBDEVICE_10280106: return "SUBDEVICE_10280106";
        case PciSubDevice1028000A::SUBDEVICE_1028011B: return "SUBDEVICE_1028011B";
        case PciSubDevice1028000A::SUBDEVICE_10280121: return "SUBDEVICE_10280121";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice1028000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice1028000A subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice1028000A::SUBDEVICE_10280106: return "PERC 3/DiJ [Jaguar]";
        case PciSubDevice1028000A::SUBDEVICE_1028011B: return "PERC 3/DiD [Dagger]";
        case PciSubDevice1028000A::SUBDEVICE_10280121: return "PERC 3/DiB [Boxster]";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1028_PCISUBDEVICE1028000A_H
