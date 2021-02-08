// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0020_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0020_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice100B0020: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_103C0024 = 0x103C0024,
    SUBDEVICE_12D9000C = 0x12D9000C,
    SUBDEVICE_1385F311 = 0x1385F311,
    SUBDEVICE_1385F312 = 0x1385F312
};



inline const char8* enumToString(PciSubDevice100B0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100B0020::NONE:               return "NONE";
        case PciSubDevice100B0020::SUBDEVICE_103C0024: return "SUBDEVICE_103C0024";
        case PciSubDevice100B0020::SUBDEVICE_12D9000C: return "SUBDEVICE_12D9000C";
        case PciSubDevice100B0020::SUBDEVICE_1385F311: return "SUBDEVICE_1385F311";
        case PciSubDevice100B0020::SUBDEVICE_1385F312: return "SUBDEVICE_1385F312";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice100B0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice100B0020 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice100B0020::SUBDEVICE_103C0024: return "Pavilion ze4400 builtin Network";
        case PciSubDevice100B0020::SUBDEVICE_12D9000C: return "Aculab E1/T1 PMXc cPCI carrier card";
        case PciSubDevice100B0020::SUBDEVICE_1385F311: return "FA311 / FA312 (FA311 with WoL HW)";
        case PciSubDevice100B0020::SUBDEVICE_1385F312: return "FA312 (rev. A1) Fast Ethernet PCI Adapter";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR100B_PCISUBDEVICE100B0020_H
