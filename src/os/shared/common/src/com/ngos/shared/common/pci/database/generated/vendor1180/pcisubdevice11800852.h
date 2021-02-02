// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800852_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800852_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice11800852: bad_uint32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10250121 = 0x10250121,
    SUBDEVICE_102801F3 = 0x102801F3,
    SUBDEVICE_1028022F = 0x1028022F,
    SUBDEVICE_103C30B5 = 0x103C30B5,
    SUBDEVICE_103C30B7 = 0x103C30B7,
    SUBDEVICE_103C30CC = 0x103C30CC,
    SUBDEVICE_103C30CF = 0x103C30CF,
    SUBDEVICE_10431967 = 0x10431967,
    SUBDEVICE_11800852 = 0x11800852,
    SUBDEVICE_132410CF = 0x132410CF,
    SUBDEVICE_17AA20CB = 0x17AA20CB
};



inline const char8* enumToString(PciSubDevice11800852 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800852::NONE:               return "NONE";
        case PciSubDevice11800852::SUBDEVICE_10250121: return "SUBDEVICE_10250121";
        case PciSubDevice11800852::SUBDEVICE_102801F3: return "SUBDEVICE_102801F3";
        case PciSubDevice11800852::SUBDEVICE_1028022F: return "SUBDEVICE_1028022F";
        case PciSubDevice11800852::SUBDEVICE_103C30B5: return "SUBDEVICE_103C30B5";
        case PciSubDevice11800852::SUBDEVICE_103C30B7: return "SUBDEVICE_103C30B7";
        case PciSubDevice11800852::SUBDEVICE_103C30CC: return "SUBDEVICE_103C30CC";
        case PciSubDevice11800852::SUBDEVICE_103C30CF: return "SUBDEVICE_103C30CF";
        case PciSubDevice11800852::SUBDEVICE_10431967: return "SUBDEVICE_10431967";
        case PciSubDevice11800852::SUBDEVICE_11800852: return "SUBDEVICE_11800852";
        case PciSubDevice11800852::SUBDEVICE_132410CF: return "SUBDEVICE_132410CF";
        case PciSubDevice11800852::SUBDEVICE_17AA20CB: return "SUBDEVICE_17AA20CB";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice11800852 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (bad_uint32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice11800852 subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice11800852::SUBDEVICE_10250121: return "Aspire 5920G";
        case PciSubDevice11800852::SUBDEVICE_102801F3: return "Inspiron 1420";
        case PciSubDevice11800852::SUBDEVICE_1028022F: return "Inspiron 1525";
        case PciSubDevice11800852::SUBDEVICE_103C30B5: return "Presario V3242AU";
        case PciSubDevice11800852::SUBDEVICE_103C30B7: return "Presario V6133CL";
        case PciSubDevice11800852::SUBDEVICE_103C30CC: return "Pavilion dv6700";
        case PciSubDevice11800852::SUBDEVICE_103C30CF: return "Pavilion dv9668eg Laptop";
        case PciSubDevice11800852::SUBDEVICE_10431967: return "V6800V";
        case PciSubDevice11800852::SUBDEVICE_11800852: return "Pavilion 2410us";
        case PciSubDevice11800852::SUBDEVICE_132410CF: return "P7120";
        case PciSubDevice11800852::SUBDEVICE_17AA20CB: return "ThinkPad T400";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR1180_PCISUBDEVICE11800852_H
