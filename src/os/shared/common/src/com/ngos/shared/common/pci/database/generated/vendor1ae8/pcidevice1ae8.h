// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE8_PCIDEVICE1AE8_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE8_PCIDEVICE1AE8_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciDevice1AE8: u16 // Ignore CppEnumVerifier
{
    NONE        = 0,
    DEVICE_0751 = 0x0751,
    DEVICE_0752 = 0x0752,
    DEVICE_0753 = 0x0753,
    DEVICE_0754 = 0x0754,
    DEVICE_0755 = 0x0755,
    DEVICE_0756 = 0x0756,
    DEVICE_0757 = 0x0757,
    DEVICE_0758 = 0x0758,
    DEVICE_0759 = 0x0759,
    DEVICE_0A40 = 0x0A40,
    DEVICE_0A41 = 0x0A41,
    DEVICE_0A42 = 0x0A42,
    DEVICE_0A44 = 0x0A44,
    DEVICE_0A45 = 0x0A45,
    DEVICE_0A53 = 0x0A53,
    DEVICE_0A54 = 0x0A54,
    DEVICE_0A56 = 0x0A56,
    DEVICE_0A57 = 0x0A57,
    DEVICE_0A58 = 0x0A58,
    DEVICE_0A5A = 0x0A5A,
    DEVICE_0B52 = 0x0B52,
    DEVICE_0B53 = 0x0B53,
    DEVICE_0B61 = 0x0B61,
    DEVICE_0B63 = 0x0B63,
    DEVICE_0E42 = 0x0E42,
    DEVICE_0E44 = 0x0E44
};



inline const char8* enumToString(PciDevice1AE8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AE8::NONE:        return "NONE";
        case PciDevice1AE8::DEVICE_0751: return "DEVICE_0751";
        case PciDevice1AE8::DEVICE_0752: return "DEVICE_0752";
        case PciDevice1AE8::DEVICE_0753: return "DEVICE_0753";
        case PciDevice1AE8::DEVICE_0754: return "DEVICE_0754";
        case PciDevice1AE8::DEVICE_0755: return "DEVICE_0755";
        case PciDevice1AE8::DEVICE_0756: return "DEVICE_0756";
        case PciDevice1AE8::DEVICE_0757: return "DEVICE_0757";
        case PciDevice1AE8::DEVICE_0758: return "DEVICE_0758";
        case PciDevice1AE8::DEVICE_0759: return "DEVICE_0759";
        case PciDevice1AE8::DEVICE_0A40: return "DEVICE_0A40";
        case PciDevice1AE8::DEVICE_0A41: return "DEVICE_0A41";
        case PciDevice1AE8::DEVICE_0A42: return "DEVICE_0A42";
        case PciDevice1AE8::DEVICE_0A44: return "DEVICE_0A44";
        case PciDevice1AE8::DEVICE_0A45: return "DEVICE_0A45";
        case PciDevice1AE8::DEVICE_0A53: return "DEVICE_0A53";
        case PciDevice1AE8::DEVICE_0A54: return "DEVICE_0A54";
        case PciDevice1AE8::DEVICE_0A56: return "DEVICE_0A56";
        case PciDevice1AE8::DEVICE_0A57: return "DEVICE_0A57";
        case PciDevice1AE8::DEVICE_0A58: return "DEVICE_0A58";
        case PciDevice1AE8::DEVICE_0A5A: return "DEVICE_0A5A";
        case PciDevice1AE8::DEVICE_0B52: return "DEVICE_0B52";
        case PciDevice1AE8::DEVICE_0B53: return "DEVICE_0B53";
        case PciDevice1AE8::DEVICE_0B61: return "DEVICE_0B61";
        case PciDevice1AE8::DEVICE_0B63: return "DEVICE_0B63";
        case PciDevice1AE8::DEVICE_0E42: return "DEVICE_0E42";
        case PciDevice1AE8::DEVICE_0E44: return "DEVICE_0E44";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciDevice1AE8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    static char8 res[23];

    sprintf(res, "0x%04X (%s)", (u16)device, enumToString(device));

    return res;
}



inline const char8* enumToHumanString(PciDevice1AE8 device) // TEST: NO
{
    // COMMON_LT((" | device = %u", device)); // Commented to avoid bad looking logs



    switch (device)
    {
        case PciDevice1AE8::DEVICE_0751: return "mE5 marathon VCL";
        case PciDevice1AE8::DEVICE_0752: return "mE5 marathon AF2";
        case PciDevice1AE8::DEVICE_0753: return "mE5 marathon ACX QP";
        case PciDevice1AE8::DEVICE_0754: return "mE5 marathon ACL";
        case PciDevice1AE8::DEVICE_0755: return "mE5 marathon ACX SP";
        case PciDevice1AE8::DEVICE_0756: return "mE5 marathon ACX DP";
        case PciDevice1AE8::DEVICE_0757: return "mE5 marathon VCX QP";
        case PciDevice1AE8::DEVICE_0758: return "mE5 marathon VF2";
        case PciDevice1AE8::DEVICE_0759: return "mE5 marathon VCLx";
        case PciDevice1AE8::DEVICE_0A40: return "microEnable IV AD1-CL";
        case PciDevice1AE8::DEVICE_0A41: return "microEnable IV VD1-CL";
        case PciDevice1AE8::DEVICE_0A42: return "microEnable IV AD4-CL";
        case PciDevice1AE8::DEVICE_0A44: return "microEnable IV VD4-CL";
        case PciDevice1AE8::DEVICE_0A45: return "microEnable IV AS1-CL";
        case PciDevice1AE8::DEVICE_0A53: return "microEnable 5 AQ8-CXP6B";
        case PciDevice1AE8::DEVICE_0A54: return "microEnable 5 VQ8-CXP6B";
        case PciDevice1AE8::DEVICE_0A56: return "microEnable 5 VQ8-CXP6D";
        case PciDevice1AE8::DEVICE_0A57: return "microEnable 5 AQ8-CXP6D";
        case PciDevice1AE8::DEVICE_0A58: return "microEnable 5 VD8-CL";
        case PciDevice1AE8::DEVICE_0A5A: return "microEnable 5 AD8-CL";
        case PciDevice1AE8::DEVICE_0B52: return "mE5 Abacus 4G Base";
        case PciDevice1AE8::DEVICE_0B53: return "mE5 Abacus 4G Base II";
        case PciDevice1AE8::DEVICE_0B61: return "mE6 Abacus 4TG";
        case PciDevice1AE8::DEVICE_0B63: return "CXP-12 Interface Card 1C";
        case PciDevice1AE8::DEVICE_0E42: return "microEnable IV AQ4-GE";
        case PciDevice1AE8::DEVICE_0E44: return "microEnable IV VQ4-GE";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1AE8_PCIDEVICE1AE8_H
