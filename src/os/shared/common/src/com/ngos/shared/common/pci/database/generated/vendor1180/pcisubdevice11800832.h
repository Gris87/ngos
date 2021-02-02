// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800832_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800832_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11800832: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250121 = 0x10250121,
    SUBDEVICE_102801D7 = 0x102801D7,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_1028022F = 0x1028022F,
    SUBDEVICE_1028024D = 0x1028024D,
    SUBDEVICE_103C30B5 = 0x103C30B5,
    SUBDEVICE_103C30B7 = 0x103C30B7,
    SUBDEVICE_103C30C1 = 0x103C30C1,
    SUBDEVICE_103C30CC = 0x103C30CC,
    SUBDEVICE_103C30CF = 0x103C30CF,
    SUBDEVICE_17AA20C5 = 0x17AA20C5,
    SUBDEVICE_17AA20C7 = 0x17AA20C7
};



inline const char8* enumToString(PciSubDevice11800832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800832::NONE:               return "NONE";
        case PciSubDevice11800832::SUBDEVICE_10250121: return "SUBDEVICE_10250121";
        case PciSubDevice11800832::SUBDEVICE_102801D7: return "SUBDEVICE_102801D7";
        case PciSubDevice11800832::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice11800832::SUBDEVICE_1028022F: return "SUBDEVICE_1028022F";
        case PciSubDevice11800832::SUBDEVICE_1028024D: return "SUBDEVICE_1028024D";
        case PciSubDevice11800832::SUBDEVICE_103C30B5: return "SUBDEVICE_103C30B5";
        case PciSubDevice11800832::SUBDEVICE_103C30B7: return "SUBDEVICE_103C30B7";
        case PciSubDevice11800832::SUBDEVICE_103C30C1: return "SUBDEVICE_103C30C1";
        case PciSubDevice11800832::SUBDEVICE_103C30CC: return "SUBDEVICE_103C30CC";
        case PciSubDevice11800832::SUBDEVICE_103C30CF: return "SUBDEVICE_103C30CF";
        case PciSubDevice11800832::SUBDEVICE_17AA20C5: return "SUBDEVICE_17AA20C5";
        case PciSubDevice11800832::SUBDEVICE_17AA20C7: return "SUBDEVICE_17AA20C7";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11800832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11800832 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800832::SUBDEVICE_10250121: return "Aspire 5920G";
        case PciSubDevice11800832::SUBDEVICE_102801D7: return "XPS M1210";
        case PciSubDevice11800832::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice11800832::SUBDEVICE_1028022F: return "Inspiron 1525";
        case PciSubDevice11800832::SUBDEVICE_1028024D: return "Latitude E4300";
        case PciSubDevice11800832::SUBDEVICE_103C30B5: return "Presario V3242AU";
        case PciSubDevice11800832::SUBDEVICE_103C30B7: return "Presario V6133CL";
        case PciSubDevice11800832::SUBDEVICE_103C30C1: return "Compaq 6910p";
        case PciSubDevice11800832::SUBDEVICE_103C30CC: return "Pavilion dv6700";
        case PciSubDevice11800832::SUBDEVICE_103C30CF: return "Pavilion dv9668eg Laptop";
        case PciSubDevice11800832::SUBDEVICE_17AA20C5: return "ThinkPad R61";
        case PciSubDevice11800832::SUBDEVICE_17AA20C7: return "ThinkPad R61";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800832_H
