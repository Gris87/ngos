// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800843_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800843_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11800843: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250121 = 0x10250121,
    SUBDEVICE_102801D7 = 0x102801D7,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_102801F5 = 0x102801F5,
    SUBDEVICE_1028024F = 0x1028024F,
    SUBDEVICE_103C03B5 = 0x103C03B5,
    SUBDEVICE_103C1521 = 0x103C1521,
    SUBDEVICE_103C30B7 = 0x103C30B7,
    SUBDEVICE_103C30CF = 0x103C30CF,
    SUBDEVICE_10431017 = 0x10431017,
    SUBDEVICE_11830843 = 0x11830843
};



inline const char8* enumToString(PciSubDevice11800843 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800843::NONE:               return "NONE";
        case PciSubDevice11800843::SUBDEVICE_10250121: return "SUBDEVICE_10250121";
        case PciSubDevice11800843::SUBDEVICE_102801D7: return "SUBDEVICE_102801D7";
        case PciSubDevice11800843::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice11800843::SUBDEVICE_102801F5: return "SUBDEVICE_102801F5";
        case PciSubDevice11800843::SUBDEVICE_1028024F: return "SUBDEVICE_1028024F";
        case PciSubDevice11800843::SUBDEVICE_103C03B5: return "SUBDEVICE_103C03B5";
        case PciSubDevice11800843::SUBDEVICE_103C1521: return "SUBDEVICE_103C1521";
        case PciSubDevice11800843::SUBDEVICE_103C30B7: return "SUBDEVICE_103C30B7";
        case PciSubDevice11800843::SUBDEVICE_103C30CF: return "SUBDEVICE_103C30CF";
        case PciSubDevice11800843::SUBDEVICE_10431017: return "SUBDEVICE_10431017";
        case PciSubDevice11800843::SUBDEVICE_11830843: return "SUBDEVICE_11830843";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11800843 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11800843 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800843::SUBDEVICE_10250121: return "Aspire 5920G";
        case PciSubDevice11800843::SUBDEVICE_102801D7: return "XPS M1210";
        case PciSubDevice11800843::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice11800843::SUBDEVICE_102801F5: return "Inspiron 1501";
        case PciSubDevice11800843::SUBDEVICE_1028024F: return "Latitude e6500";
        case PciSubDevice11800843::SUBDEVICE_103C03B5: return "Presario V3242AU";
        case PciSubDevice11800843::SUBDEVICE_103C1521: return "HP EliteBook 8540w";
        case PciSubDevice11800843::SUBDEVICE_103C30B7: return "Presario V6133CL";
        case PciSubDevice11800843::SUBDEVICE_103C30CF: return "Pavilion dv9500/9600/9700 series";
        case PciSubDevice11800843::SUBDEVICE_10431017: return "X58LE";
        case PciSubDevice11800843::SUBDEVICE_11830843: return "Alienware Aurora m9700";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800843_H
