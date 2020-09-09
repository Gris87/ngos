// This file generated with the code_generator
// Please do not modify it manually
#ifndef COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4170C_H
#define COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4170C_H



#include <com/ngos/shared/common/ngos/types.h>
#include <com/ngos/shared/common/printf/printf.h>



enum class PciSubDevice14E4170C: u32 // Ignore CppEnumVerifier
{
    NONE               = 0,
    SUBDEVICE_10280188 = 0x10280188,
    SUBDEVICE_1028018D = 0x1028018D,
    SUBDEVICE_10280196 = 0x10280196,
    SUBDEVICE_102801AF = 0x102801AF,
    SUBDEVICE_102801CD = 0x102801CD,
    SUBDEVICE_102801D7 = 0x102801D7,
    SUBDEVICE_102801D8 = 0x102801D8,
    SUBDEVICE_103C099C = 0x103C099C,
    SUBDEVICE_103C30A2 = 0x103C30A2,
    SUBDEVICE_14E4170C = 0x14E4170C
};



inline const char8* enumToString(PciSubDevice14E4170C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4170C::NONE:               return "NONE";
        case PciSubDevice14E4170C::SUBDEVICE_10280188: return "SUBDEVICE_10280188";
        case PciSubDevice14E4170C::SUBDEVICE_1028018D: return "SUBDEVICE_1028018D";
        case PciSubDevice14E4170C::SUBDEVICE_10280196: return "SUBDEVICE_10280196";
        case PciSubDevice14E4170C::SUBDEVICE_102801AF: return "SUBDEVICE_102801AF";
        case PciSubDevice14E4170C::SUBDEVICE_102801CD: return "SUBDEVICE_102801CD";
        case PciSubDevice14E4170C::SUBDEVICE_102801D7: return "SUBDEVICE_102801D7";
        case PciSubDevice14E4170C::SUBDEVICE_102801D8: return "SUBDEVICE_102801D8";
        case PciSubDevice14E4170C::SUBDEVICE_103C099C: return "SUBDEVICE_103C099C";
        case PciSubDevice14E4170C::SUBDEVICE_103C30A2: return "SUBDEVICE_103C30A2";
        case PciSubDevice14E4170C::SUBDEVICE_14E4170C: return "SUBDEVICE_14E4170C";

        default: return "UNKNOWN";
    }
}



inline const char8* enumToFullString(PciSubDevice14E4170C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    static char8 res[32];

    sprintf(res, "0x%08X (%s)", (u32)subDevice, enumToString(subDevice));

    return res;
}



inline const char8* enumToHumanString(PciSubDevice14E4170C subDevice) // TEST: NO
{
    // COMMON_LT((" | subDevice = %u", subDevice)); // Commented to avoid bad looking logs



    switch (subDevice)
    {
        case PciSubDevice14E4170C::SUBDEVICE_10280188: return "Inspiron 6000 laptop";
        case PciSubDevice14E4170C::SUBDEVICE_1028018D: return "Inspiron 700m/710m";
        case PciSubDevice14E4170C::SUBDEVICE_10280196: return "Inspiron 5160";
        case PciSubDevice14E4170C::SUBDEVICE_102801AF: return "Inspiron 6400";
        case PciSubDevice14E4170C::SUBDEVICE_102801CD: return "Inspiron 9400 Laptop";
        case PciSubDevice14E4170C::SUBDEVICE_102801D7: return "XPS M1210";
        case PciSubDevice14E4170C::SUBDEVICE_102801D8: return "Inspiron E1405";
        case PciSubDevice14E4170C::SUBDEVICE_103C099C: return "NX6110/NC6120";
        case PciSubDevice14E4170C::SUBDEVICE_103C30A2: return "NX7300 laptop";
        case PciSubDevice14E4170C::SUBDEVICE_14E4170C: return "HP Compaq 6720t Mobile Thin Client";

        default: return "Unknown device";
    }
}



#endif // COM_NGOS_SHARED_COMMON_PCI_DATABASE_GENERATED_VENDOR14E4_PCISUBDEVICE14E4170C_H
